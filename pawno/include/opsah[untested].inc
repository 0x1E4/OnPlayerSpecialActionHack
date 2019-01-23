#include <a_samp>
#include <YSI\y_bit> // man seriously i love this, because it much simpler to use <3

//lets declarate my loved macros <3
#define         PUB->%0(%1)                   public %0(%1)
#define         STR->%0(%1)                   stock %0(%1)
#define         FUNC->%0(%1)                  forward %0(%1); public %0(%1)

static
      BitArray:ac_SafetyToUse<MAX_PLAYERS>

PUB->OnPlayerSpawn(playerid)
{
    Bit_Set(ac_SafetyToUse, playerid, false);
    
#if defined pre_OnPlayerSpawn
		pre_OnPlayerSpawn(playerid);
	#endif
	return true;
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn pre_OnPlayerSpawn

#if defined pre_OnPlayerSpawn
    forward pre_OnPlayerSpawn(playerid);
#endif

PUB->OnPlayerUpdate(playerid)
{
	//begin the anticheat
	if(IsPlayerUseSpecialAction(playerid) && !Bit_Get(ac_SafetyToUse, playerid))
	{
		CallLocalFunction("OnPlayerSpecialActionHack", "i", playerid);
	}
 }
 
 str->Pre_SetPlayerSpecialAction(playerid, actionid)
 {
       Bit_Set(ac_SafetyToUse, playerid, true);
       return SetPlayerSpecialAction(playerid, actionid);
 }
 
 #if defined _ALS_SetPlayerSpecialAction
	#undef SetPlayerSpecialAction
#else
	#define _ALS_SetPlayerSpecialAction
#endif

#define SetPlayerSpecialAction pre_SetPlayerSpecialAction
 
 STR->IsPlayerUseSpecialAction(playerid)
 {
       if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DANCE1 || 
       GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DANCE2 || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DANCE3 || 
       GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DANCE4 ||GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_HANDSUP || 
       GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_STOPUSECELLPHONE || 
       GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DRINKBEER || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_SMOKE_CIGGY || 
       GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DRINK_WHINE || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DRINK_SPRUNK ||
       GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CUFFED || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_PISSING) return 1;
       //if(GetPlayerSpecialction(playerid) == SPECIAL_ACTION_NONE) return 0;
       return 0;
}
       
       
