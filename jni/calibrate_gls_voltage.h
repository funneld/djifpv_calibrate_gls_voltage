
static void *guiLib = 0;
static bool started = false;
static void (* racingChnlupdateParam)(void *this) = 0;
static float calib;


typedef struct GlassRacingChnlUI GlassRacingChnlUI, *PGlassRacingChnlUI;
typedef struct GlassRacingChnlUI GlassRacingChnlUI_t;

struct GlassRacingChnlUI {
	char dummy[0x4a0];
	float gs_voltage;
	char dummy2[0x208]; //end at 0x6ac

}__attribute__((packed, aligned(1)));
