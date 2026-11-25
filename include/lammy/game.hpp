#include <recomp/settings.hpp>
#include <psyq/LIBGPU.H>
#include <lammy/types.hpp>

#if LAM_RECOMP_BETTERNAME
namespace ujl {
	namespace game {
#endif
		LAM_RECOMP_DEFINE_USEBETTERFUNC(void, (void), G_Game_Init, Init) {
			undefined1* puVar1;
			uint uVar2;
			uint* puVar3;
			RECT screenRect;

			SetDispMask(0);
			FUN_80024d48();
			DAT_80071ca0 = GsGetActiveBuff();
			G_MemCard_Init("BISCPS-18011");
			G_Pad_Init();
			G_Loop_SetEndTick(NULL);
			G_Render_SetRenderFuncData_EduGuess(0x0, 0x0);
			FUN_8002d544(0, 0, 0);
			G_Aud_Init();
			G_Spu_Init_EduGuess();
			FUN_8002d994();
			puVar1 = &screenRect.y + 1;
			uVar2 = puVar1 & 3;
			puVar3 = puVar1 + -uVar2;
			*puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
			screenRect.x = 0;
			screenRect.y = 0;
			puVar1 = &screenRect.h + 1;
			uVar2 = puVar1 & 3;
			puVar3 = puVar1 + -uVar2;
			*puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0x2000400U >> (3 - uVar2) * 8;
			screenRect.w = 0x400;
			screenRect.h = 0x200;
			ClearImage(&screenRect, '\0', '\0', '\0');
			DrawSync(0);
			GsInitVcount();
			FUN_8004cff8();
			SeVibOn_Possible(0x340, 0x1e4);
			SetVib_OrSeVibOn_Possible(0xffffff70, 0xffffff98);
			VSync(0);
			SetDispMask(1);
			return;
		}

#if LAM_RECOMP_BETTERNAME
	}
}
#endif