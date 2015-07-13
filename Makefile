	
	# check if user is root
	user = $(shell whoami)
	ifeq ($(user),root)
	INSTALL_DIR = /usr/lib/lv2
	else 
	INSTALL_DIR = ~/.lv2
	endif

	ifneq (cat /proc/cpuinfo | grep sse2 >/dev/null,)
	SSE_CFLAGS = -msse2 -mfpmath=sse
	else ifneq (cat /proc/cpuinfo | grep sse >/dev/null,)
	SSE_CFLAGS = -msse -mfpmath=sse
	else
	SSE_CFLAGS = ""
	endif

	# set bundle name
	NAME = gx_voxtb
	BUNDLE = $(NAME).lv2
	VER = 0.1
	# create debian package
	DEBNAME = gxvoxtonebender_$(VER)
	CREATEDEB = yes '' | dh_make -s -n -e $(USER)@org -p $(DEBNAME) -c gpl >/dev/null
	BUILDDEB = dpkg-buildpackage -rfakeroot -b 2>/dev/null | grep dpkg-deb 
	# set compile flags
	CXXFLAGS += -I. -I../DSP -fPIC -DPIC -O2 -Wall -funroll-loops -ffast-math -fomit-frame-pointer -fstrength-reduce $(SSE_CFLAGS)
	LDFLAGS += -shared -lm
	# invoke build files
	OBJECTS = $(NAME).cpp 
	## output style (bash colours)
	BLUE = "\033[1;34m"
	RED =  "\033[1;31m"
	NONE = "\033[0m"

.PHONY : all clean install uninstall 

all : $(NAME)
	@mkdir -p ./$(BUNDLE)
	@cp ./*.ttl ./$(BUNDLE)
	@cp -r ./modgui ./$(BUNDLE)
	@mv ./*.so ./$(BUNDLE)
	@if [ -f ./$(BUNDLE)/$(NAME).so ]; then echo $(BLUE)"build finish, now run make install"; \
	else echo $(RED)"sorry, build failed"; fi
	@echo $(NONE)

clean :
	@rm -f $(NAME).so
	@rm -rf ./$(BUNDLE)
	@echo ". ." $(BLUE)", done"$(NONE)

dist-clean :
	@rm -rf ./debian
	@rm -f $(NAME).so
	@rm -rf ./$(BUNDLE)
	@echo ". ." $(BLUE)", done"$(NONE)

install : all
	@mkdir -p $(DESTDIR)$(INSTALL_DIR)/$(BUNDLE)
	@cp -r ./$(BUNDLE)/* $(DESTDIR)$(INSTALL_DIR)/$(BUNDLE)
	@echo ". ." $(BLUE)", done"$(NONE)

    #@create tar ball
tar : clean
	@cd ../ && \
	tar -cf $(BUNDLE).tar.bz2 --bzip2 $(BUNDLE)
	@echo $(BLUE)"build "$(BUNDLE)".tar.bz2"$(NONE)

    #@build a debian packet for all arch
deb :
	@rm -rf ./debian
	@echo $(BLUE)"create ./debian"$(NONE)
	-@ $(CREATEDEB)
	@echo $(BLUE)"try to build debian package, that may take some time"$(NONE)
	-@ if $(BUILDDEB); then echo ". ." $(BLUE)", done"$(NONE); else \
     echo $(RED)"sorry, build fail"$(NONE); fi

uninstall :
	@rm -rf $(INSTALL_DIR)/$(BUNDLE)
	@echo ". ." $(BLUE)", done"$(NONE)

$(NAME) :
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME).so
