#pragma once

#include <lammy/custom.hpp>
//#include <psyq/LIBETC.H>
#include <psyq/LIBAPI.H>
#include <recomp/settings.hpp>

//Custom
enum EThreadID : u32 {
	THREAD_MAIN = 1,
};

using threadfunc_t = long();


//Stores the address of the tables
int* THREAD_ADDRESS_TABLE_DAT_801c0334 = nullptr;
//Stores PSYQ thread ids
int* THREAD_ID_TABLE_ADDRESS_DAT_801c0300 = nullptr;

#if LAM_RECOMP_BETTERNAME
namespace ujl {
	namespace thread {
#endif


		LAM_RECOMP_DEFINE_USEBETTERFUNC(void, (EThreadID p_ID), G_Thread_Create, Close) {
			if (((&DAT_801c0330)[p_ID * 4] & 0xf) != 0) {
				(&DAT_801c0330)[p_ID * 4] = 0;
				(&THREAD_ADDRESS_TABLE_DAT_801c0334)[p_ID * 2] = 0;
				EnterCriticalSection();
				CloseTh((&THREAD_ID_TABLE_ADDRESS_DAT_801c0300)[p_ID]);
				ExitCriticalSection();
			}
			return;
		}


		LAM_RECOMP_DEFINE_USEBETTERFUNC(void, (threadfunc_t* p_FuncData, EThreadID p_ID), G_Thread_Create, Create) {
			int iVar1;
			u_long globalPointer_and_threadID;
			u32 uVar2;

			if (((&DAT_801c0330)[p_ID * 4] & 0xffff7fffU) != 0) {
				LAM_RECOMP_CALL_USEBETTERFUNC(G_Thread_Close, Close)(p_ID);
			}
			iVar1 = _DAT_00000110;
			globalPointer_and_threadID = GetGp();
			(&DAT_801b52f8)[p_ID * 0x400] = 0x6c28382a;
			EnterCriticalSection();
			uVar2 = OpenTh(p_FuncData, &DAT_801b62f8 + p_ID * 0x1000, globalPointer_and_threadID);
			THREAD_ID_TABLE_ADDRESS_DAT_801c0300[p_ID] = uVar2;
			*((uVar2 & 0xffff) * 0xc0 + iVar1 + 0x94) = 0x40000404;
			ExitCriticalSection();
			(&DAT_801c0330)[p_ID * 4] = 2;
			(&THREAD_ADDRESS_TABLE_DAT_801c0334)[p_ID * 2] = 0;
			return;
		}
#if LAM_RECOMP_BETTERNAME
	}
}
#endif