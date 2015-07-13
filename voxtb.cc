// generated from file './/voxtb.dsp' by dsp2cc:
// Code generated with Faust 0.9.65 (http://faust.grame.fr)


namespace voxtb {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec1[2];
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
	double 	fConst53;
	double 	fConst54;
	double 	fConst55;
	double 	fConst56;
	double 	fConst57;
	double 	fConst58;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec2[4];
	double 	fConst59;
	double 	fConst60;
	double 	fConst61;
	double 	fConst62;
	double 	fConst63;
	double 	fConst64;
	double 	fConst65;
	double 	fConst66;
	double 	fConst67;
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "voxtb";
	name = N_("Vox Tone Blender");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<4; i++) fRec2[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (3.20483870920171e-15 * fConst0);
	fConst2 = (4.18402072691443e-09 + (fConst0 * (1.12405087357832e-11 + fConst1)));
	fConst3 = (8.44855649476917e-15 * fConst0);
	fConst4 = (4.25748196373968e-07 + (fConst0 * (1.55261932216262e-10 + fConst3)));
	fConst5 = (9.77477880745123e-30 * fConst0);
	fConst6 = (4.52222748649205e-22 + (fConst0 * (1.7694794760881e-25 + fConst5)));
	fConst7 = (3.22236576702547e-30 * fConst0);
	fConst8 = ((fConst0 * (0 - (5.38277517084396e-26 + fConst7))) - 8.14000947568558e-23);
	fConst9 = (9.56185709606311e-16 * fConst0);
	fConst10 = ((fConst0 * (0 - (1.70069397437873e-11 + fConst9))) - 4.62891553897216e-08);
	fConst11 = (1.10628411090513e-30 * fConst0);
	fConst12 = ((fConst0 * (0 - (1.93725832924165e-26 + fConst11))) - 4.91675813574156e-23);
	fConst13 = (3.64698999108547e-31 * fConst0);
	fConst14 = (8.8501646443347e-24 + (fConst0 * (5.87651111144262e-27 + fConst13)));
	fConst15 = (1.22235822791309e-30 * fConst0);
	fConst16 = ((fConst0 * ((fConst0 * (0 - (2.24234667119061e-27 + fConst15))) - 1.28306478825726e-24)) - 1.62885869397805e-21);
	fConst17 = (3.7079221184589e-30 * fConst0);
	fConst18 = (9.04921496654485e-21 + (fConst0 * (4.68495021840625e-24 + (fConst0 * (1.19859488457426e-26 + fConst17)))));
	fConst19 = (3.27703251599175e-12 * fConst0);
	fConst20 = (8.52313273082747e-12 - fConst19);
	fConst21 = (3.26614536477583e-12 * fConst0);
	fConst22 = (fConst21 - 8.49481667524333e-12);
	fConst23 = ((fConst0 * (1.12405087357832e-11 - fConst1)) - 4.18402072691443e-09);
	fConst24 = ((fConst0 * (1.55261932216262e-10 - fConst3)) - 4.25748196373968e-07);
	fConst25 = ((fConst0 * (1.7694794760881e-25 - fConst5)) - 4.52222748649205e-22);
	fConst26 = (8.14000947568558e-23 + (fConst0 * (fConst7 - 5.38277517084396e-26)));
	fConst27 = (4.62891553897216e-08 + (fConst0 * (fConst9 - 1.70069397437873e-11)));
	fConst28 = (4.91675813574156e-23 + (fConst0 * (fConst11 - 1.93725832924165e-26)));
	fConst29 = ((fConst0 * (5.87651111144262e-27 - fConst13)) - 8.8501646443347e-24);
	fConst30 = ((fConst0 * (1.28306478825726e-24 + (fConst0 * (fConst15 - 2.24234667119061e-27)))) - 1.62885869397805e-21);
	fConst31 = (9.04921496654485e-21 + (fConst0 * ((fConst0 * (1.19859488457426e-26 - fConst17)) - 4.68495021840625e-24)));
	fConst32 = (2.93243364223537e-29 * fConst0);
	fConst33 = ((fConst0 * (fConst32 - 1.7694794760881e-25)) - 4.52222748649205e-22);
	fConst34 = (9.66709730107641e-30 * fConst0);
	fConst35 = (8.14000947568558e-23 + (fConst0 * (5.38277517084396e-26 - fConst34)));
	fConst36 = (2.86855712881893e-15 * fConst0);
	fConst37 = (4.62891553897216e-08 + (fConst0 * (1.70069397437873e-11 - fConst36)));
	fConst38 = (3.31885233271539e-30 * fConst0);
	fConst39 = (4.91675813574156e-23 + (fConst0 * (1.93725832924165e-26 - fConst38)));
	fConst40 = (1.09409699732564e-30 * fConst0);
	fConst41 = ((fConst0 * (fConst40 - 5.87651111144262e-27)) - 8.8501646443347e-24);
	fConst42 = (2.53456694843075e-14 * fConst0);
	fConst43 = ((fConst0 * (fConst42 - 1.55261932216262e-10)) - 4.25748196373968e-07);
	fConst44 = (9.61451612760513e-15 * fConst0);
	fConst45 = ((fConst0 * (fConst44 - 1.12405087357832e-11)) - 4.18402072691443e-09);
	fConst46 = (3.66707468373928e-30 * fConst0);
	fConst47 = ((fConst0 * (1.28306478825726e-24 + (fConst0 * (2.24234667119061e-27 - fConst46)))) - 4.88657608193416e-21);
	fConst48 = (1.11237663553767e-29 * fConst0);
	fConst49 = (2.71476448996345e-20 + (fConst0 * ((fConst0 * (fConst48 - 1.19859488457426e-26)) - 4.68495021840625e-24)));
	fConst50 = (4.18402072691443e-09 + (fConst0 * (0 - (1.12405087357832e-11 + fConst44))));
	fConst51 = (4.25748196373968e-07 + (fConst0 * (0 - (1.55261932216262e-10 + fConst42))));
	fConst52 = (4.52222748649205e-22 + (fConst0 * (0 - (1.7694794760881e-25 + fConst32))));
	fConst53 = ((fConst0 * (5.38277517084396e-26 + fConst34)) - 8.14000947568558e-23);
	fConst54 = ((fConst0 * (1.70069397437873e-11 + fConst36)) - 4.62891553897216e-08);
	fConst55 = ((fConst0 * (1.93725832924165e-26 + fConst38)) - 4.91675813574156e-23);
	fConst56 = (8.8501646443347e-24 + (fConst0 * (0 - (5.87651111144262e-27 + fConst40))));
	fConst57 = ((fConst0 * ((fConst0 * (2.24234667119061e-27 + fConst46)) - 1.28306478825726e-24)) - 4.88657608193416e-21);
	fConst58 = (2.71476448996345e-20 + (fConst0 * (4.68495021840625e-24 + (fConst0 * (0 - (1.19859488457426e-26 + fConst48))))));
	fConst59 = (9.79843609432748e-12 * fConst0);
	fConst60 = (8.49481667524333e-12 - fConst59);
	fConst61 = (9.83109754797523e-12 * fConst0);
	fConst62 = (fConst61 - 8.52313273082747e-12);
	fConst63 = (0 - (8.52313273082747e-12 + fConst61));
	fConst64 = (8.49481667524333e-12 + fConst59);
	fConst65 = (8.52313273082747e-12 + fConst19);
	fConst66 = (0 - (8.49481667524333e-12 + fConst21));
	fConst67 = faustpower<2>(fConst0);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
	double 	fSlow0 = (0.007000000000000006 * (1 - double(fslider0)));
	double 	fSlow1 = (0.007000000000000006 * (1 - double(fslider1)));
	double 	fSlow2 = (0.01 * double(fslider2));
	double 	fSlow3 = (1 - fSlow2);
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		fRec1[0] = ((0.993 * fRec1[1]) + fSlow1);
		double fTemp0 = (8.51944525593818e-06 + ((fRec0[0] * ((fConst18 * fRec0[0]) + fConst16)) + (fConst0 * ((fRec1[0] * (((fRec1[0] * ((fRec0[0] * (fConst14 + (fConst12 * fRec0[0]))) + fConst10)) + (fRec0[0] * (fConst8 + (fConst6 * fRec0[0])))) + fConst4)) + fConst2))));
		double  fTemp1 = (2.85290767276056e-13 * fRec0[0]);
		double  fTemp2 = (7.57880796120163e-15 * fRec0[0]);
		double  fTemp3 = (double)input0[i];
		fRec2[0] = ((fSlow2 * fTemp3) - ((((fRec2[1] * (2.55583357678145e-05 + ((fRec0[0] * ((fConst58 * fRec0[0]) + fConst57)) + (fConst0 * ((fRec1[0] * (((fRec1[0] * ((fRec0[0] * (fConst56 + (fConst55 * fRec0[0]))) + fConst54)) + (fRec0[0] * (fConst53 + (fConst52 * fRec0[0])))) + fConst51)) + fConst50))))) + (fRec2[2] * (2.55583357678145e-05 + ((fRec0[0] * ((fConst49 * fRec0[0]) + fConst47)) + (fConst0 * (fConst45 + (fRec1[0] * (fConst43 + ((fRec1[0] * ((fRec0[0] * (fConst41 + (fConst39 * fRec0[0]))) + fConst37)) + (fRec0[0] * (fConst35 + (fConst33 * fRec0[0])))))))))))) + (fRec2[3] * (8.51944525593818e-06 + ((fRec0[0] * ((fConst31 * fRec0[0]) + fConst30)) + (fConst0 * ((fRec1[0] * (((fRec1[0] * ((fRec0[0] * (fConst29 + (fConst28 * fRec0[0]))) + fConst27)) + (fRec0[0] * (fConst26 + (fConst25 * fRec0[0])))) + fConst24)) + fConst23)))))) / fTemp0));
		double  fTemp4 = (2.27364238836049e-14 * fRec0[0]);
		double  fTemp5 = (8.5587230182817e-13 * fRec0[0]);
		double  fTemp6 = ((fSlow3 * fTemp3) + ( 0.3 * (min(0.7514,max(-0.4514,(fConst67 * (((((fRec2[0] * (((fConst0 * (fRec1[0] * ((fTemp1 + (fRec1[0] * (fTemp2 - 7.60407065440563e-15))) - 2.8624173650031e-13))) + (fConst66 * fRec0[0])) + fConst65)) + (fRec2[1] * (((fConst0 * (fRec1[0] * (8.5872520950093e-13 + ((fRec1[0] * (2.28122119632169e-14 + (0 - fTemp4))) - fTemp5)))) + (fConst64 * fRec0[0])) + fConst63))) + (fRec2[2] * (fConst62 + ((fConst0 * (fRec1[0] * ((fTemp5 + (fRec1[0] * (fTemp4 - 2.28122119632169e-14))) - 8.5872520950093e-13))) + (fConst60 * fRec0[0]))))) + (fRec2[3] * (((fConst0 * (fRec1[0] * (2.8624173650031e-13 + ((fRec1[0] * (7.60407065440563e-15 + (0 - fTemp2))) - fTemp1)))) + (fConst22 * fRec0[0])) + fConst20))) / fTemp0)))))));
		output0[i] = (FAUSTFLOAT) fTemp6;
		// post processing
		for (int i=3; i>0; i--) fRec2[i] = fRec2[i-1];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case ATTACK: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case WET_DRY: 
		fslider2_ = (float*)data; // , 1e+02, 0.0, 1e+02, 1.0 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   ATTACK, 
   VOLUME, 
   WET_DRY, 
} PortIndex;
*/

} // end namespace voxtb
