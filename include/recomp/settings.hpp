#pragma once


//Use recompiling utilities (like removing bad code)
#define LAM_RECOMP_BETTERCODE 1


#if LAM_RECOMP_BETTERCODE
constexpr bool c_BetterCode = true;
#endif

//Do we use better naming scemes (C style function naming -> C++ namespaces)
#define LAM_RECOMP_BETTERNAME 1


#if LAM_RECOMP_BETTERNAME

#define LAM_RECOMP_DEFINE_USEBETTERFUNC(retType, params, origFuncDef, modernFuncDef) retType modernFuncDef params
#define LAM_RECOMP_CALL_USEBETTERFUNC(origFunc, modernFunc) modernFunc 

#else

#define LAM_RECOMP_DEFINE_USEBETTERFUNC(retType, params, origFuncDef, modernFuncDef) retType origFuncDef params
#define LAM_RECOMP_CALL_USEBETTERFUNC(origFunc, modernFunc) origFunc

#endif