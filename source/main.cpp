#include <psyq/ABS.H>
#include <psyq/ASM.H>
#include <psyq/ASSERT.H>
#include <psyq/LIBAPI.H>
#include <psyq/LIBGPU.H>
#include <psyq/LIBETC.H>
#include <psyq/LIBHMD.H>
#include <psyq/SYS/TYPES.H>
#include <psyq/LIBSPU.H>
#include <psyq/LIBDS.H>
#include <psyq/MEMORY.H>
#include <psyq/KERNEL.H>
#include <psyq/LIBGS.H>

#include <recomp/settings.hpp>
#include <lammy/kernel.hpp>
#include <lammy/globals.hpp>
#include <lammy/thread.hpp>


using undefined = void;
using undefined4 = void;

#if !LAM_RECOMP_BETTERCODE
void __main() { //Automatically inserted when compiling, so should we still put this here for matching?
    return;
}
#endif


/* DISPLAY WARNING: Type casts are NOT being printed */

void main(void)

{
    GsOT* otp;
    undefined* puVar1;
    undefined4* puVar2;
    uint uVar3;
    SpuReverbAttr reverbAttr;

#if !LAM_RECOMP_BETTERCODE
    __main();
#endif
    STACKPOINTER_DAT_801ae2b8 = SetSp(0x801b62f8);
    G_Kernel_Init();
    ResetCallback();
    VSync(0);
    SetDispMask(0);
    reverbAttr.mask = 1;
    reverbAttr.mode = 0x100;
    reverbAttr.depth.left = 0;
    reverbAttr.depth.right = 0;
    reverbAttr.delay = 0;
    reverbAttr.feedback = 0;
    SpuInit();
    SpuSetReverbModeParam(&reverbAttr);
    SpuQuit();
    InitHeap3(&GLOBALHEAP_DAT_801ae2c0, 0x7000);
    SetVideoMode(MODE_NTSC);

    do {
        uVar3 = 0;
        G_Game_Init();
        LAM_RECOMP_CALL_USEBETTERFUNC(G_Thread_Create, ujl::thread::Create)(G_Game_MainLoopThread, THREAD_MAIN);
        ExitCriticalSection();
        otp = &DAT_80078a40;
        puVar1 = &DAT_800781f8;
        puVar2 = &DAT_80078a44;
        do {
            otp->length = 5;
            *puVar2 = puVar1;
            GsClearOt(0, 0, otp);
            puVar2 = puVar2 + 5;
            otp = otp + 1;
            uVar3 = uVar3 + 1;
            puVar1 = puVar1 + 0x80;
        } while (uVar3 < 2);
        G_Game_Tick();
        G_Game_Unload();
    } while (true);
}

