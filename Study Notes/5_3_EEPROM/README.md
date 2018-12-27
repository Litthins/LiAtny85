# Register EEAR(EEARH+EEARL）

片内EEPROM共计512Bytes，使用时应注意EEAR寄存器的使用方法。

EEAR address:

+ EEAR(0x1E)(2Bytes)
+ EEARL(0x1E)(1Byte)
+ EEARH(0X1F)(1Byte)

# Using EEAR directly.（直接使用整个EEAR）
Declare a variable of unsigned int,and then assign this integer to EEAR.

# EEARL can be used alone.（单独使用EEARL或配合EEARH使用）
The size of EEARL is **only** one Byte,because 8 bits could **only** present 0 to 255,so EEARL can **only** reach the first 256 Bytes in EEPROM.Considering we have 512 Bytes in EEPROM,we should set the EEARH[0] first,then (EEARH[0]+EEARL) have 9 bits,which could present 0 to 512,then we can reach the rest 256 Bytes.



