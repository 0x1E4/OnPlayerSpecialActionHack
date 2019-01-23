# OnPlayerSpecialActionHack
Useful when player using special actions s0b3it!

## Example

```
public OnPlayerSpecialActionHack(playerid)
{
     SendAdminMessage(playerid, -1, "%s trying to use special hack!", GetName(playerid));
     SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
     return 1;
 }
 ```

 ## Credits
Y_Less - YSI\y_bit  
