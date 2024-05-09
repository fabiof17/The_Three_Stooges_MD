#ifndef _OUTILS_H
#define _OUTILS_H


extern void VDP_drawInt(u16 valeur,u8 zeros,s16 x, s16 y);

extern void VDP_drawIntEx_BG_A_QUEUE(u16 valeur,u8 zeros,s16 x, s16 y, u8 pal);

extern void VDP_drawIntEx_BG_A_DMA(u16 valeur,u8 zeros,s16 x, s16 y, u8 pal);

extern void VDP_drawIntEx_BG_B(u16 valeur,u8 zeros,s16 x, s16 y, u8 pal);




extern u8 random_NUMBER(u8 minimum , u8 maximum);

extern void generate_RANDOM_HAND_MOVE();

extern void generate_RANDOM_HAND_MOVE_SWATTER();








#endif // _MAIN