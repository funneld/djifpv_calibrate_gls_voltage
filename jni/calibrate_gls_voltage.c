#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "calibrate_gls_voltage.h"


void _ZN17GlassRacingChnlUI11updateParamEv(void* this) {
	
	if (!racingChnlupdateParam){
	racingChnlupdateParam = dlsym (RTLD_NEXT, "_ZN17GlassRacingChnlUI11updateParamEv");
		if (racingChnlupdateParam == 0){
			guiLib = dlopen("/system/lib/libtp1801_gui.so", 1);
			racingChnlupdateParam = dlsym (guiLib, "_ZN17GlassRacingChnlUI11updateParamEv");
			if (racingChnlupdateParam == 0)
			{
				printf("dlsym: %s\n", dlerror());
				return;
			}
		}
	}
	
	racingChnlupdateParam(this);
	
	if(!started){
		started = true;	
		FILE * fp;
		fp = fopen ("/storage/sdcard0/glscalib.txt", "rb");
		if(fp){
			fscanf(fp, "%f", &calib);
		}
		else{
			printf("File not found.");
			calib = 1.0;
		}
		fclose(fp);
	}

	GlassRacingChnlUI *chnl_ui = (GlassRacingChnlUI_t *)this;
	chnl_ui->gs_voltage *= calib;
	
	return;	
}
