#include <Engine/Application.h>
#include <Engine/Diagnostics/Log.h>
#include <Engine/Includes/Standard.h>

int main(int argc, char* args[]) {
#ifdef PS3
	mkdir("/dev_hdd0/HGE", 0777);	
	mkdir("/dev_hdd0/HGE/saves", 0777);	
	chdir("/dev_hdd0/HGE");	
#endif
#if SWITCH
	Log::Init();
	socketInitializeDefault();
	nxlinkStdio();
#if defined(SWITCH_ROMFS)
	romfsInit();
#endif
	// pcvInitialize();
	// pcvSetClockRate(PcvModule_CpuBus, 1581000000); // normal:
	// 1020000000, overclock: 1581000000, strong overclock:
	// 1785000000
#endif

	Application::Run(argc, args);

#if SWITCH
// pcvSetClockRate(PcvModule_CpuBus, 1020000000);
// pcvExit();
#if defined(SWITCH_ROMFS)
	romfsExit();
#endif
	socketExit();
#endif
	return 0;
}
