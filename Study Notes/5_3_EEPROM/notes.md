# Register EEAR(EEARH+EEARL）

EEAR address:
+ EEAR(0x1E)(2Bytes)
+ EEARL(0x1E)(1Byte)
+ EEARH(0X1F)(1Byte)

# Using EEAR directly
Declare a variable of unsigned int,and then assign this integer to EEAR.

# Both EEARH and EEARL can be used alone.
The size of EEARL is**only** one Byte,because 8 bits could **only** present (0~255),so EEARL can **only** reach the first 256 Bytes in EEPROM.Considering we have 512 Bytes in EEPROM,we should set the EEARH[0] first,then (EEARH[0]+EEARL) have 9 bits,which could present (0~512),the we can reach the rest 256 Bytes.



