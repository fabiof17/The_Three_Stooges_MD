#include <genesis.h>


#include "variables.h"
#include "tables_ROULETTE.h"


void VDP_drawInt(u16 valeur,u8 zeros,s16 x, s16 y)
{
	intToStr(valeur,text_output,zeros); //MIN -500.000.000 - MAX 500.000.000
	VDP_drawTextBG(BG_B,text_output,x,y);
}


void VDP_drawIntEx_BG_A_QUEUE(u16 valeur , u8 zeros , s16 x, s16 y , u8 pal)
{
	intToStr(valeur,text_output,zeros); //MIN -500.000.000 - MAX 500.000.000
	VDP_drawTextEx(BG_A,text_output,TILE_ATTR(pal, TRUE, FALSE, FALSE),x,y,DMA_QUEUE);
}


void VDP_drawIntEx_BG_A_DMA(u16 valeur , u8 zeros , s16 x, s16 y , u8 pal)
{
	intToStr(valeur,text_output,zeros); //MIN -500.000.000 - MAX 500.000.000
	VDP_drawTextEx(BG_A,text_output,TILE_ATTR(pal, FALSE, FALSE, FALSE),x,y,DMA);
}


void VDP_drawIntEx_BG_B(u16 valeur , u8 zeros , s16 x, s16 y , u8 pal)
{
	intToStr(valeur,text_output,zeros); //MIN -500.000.000 - MAX 500.000.000
	VDP_drawTextEx(BG_B,text_output,TILE_ATTR(pal, FALSE, FALSE, FALSE),x,y,DMA_QUEUE);
}








u8 random_NUMBER(u8 minimum , u8 maximum)
{
	//setRandomSeed(2);
	
	u8 resultat = random() % (maximum - minimum + 1) + minimum;

	return resultat;
}



void generate_RANDOM_HAND_MOVE()
{
	// SELECT A RANDOM HAND MOVE SEQUENCE //
	u8 random_hand_move_sequence = random_NUMBER(0,29);

	u8 j=0;

	for(j=0 ; j<10 ; j++)
	{
		TABLE_GENERATED_HAND_POSITION[9-j] = TABLE_HAND_MOVE[random_hand_move_sequence][j];
	}
}


void generate_RANDOM_HAND_MOVE_SWATTER()
{
	G_RANDOM_HAND_MOVE_VALIDATED = FALSE;
	
	while(G_RANDOM_HAND_MOVE_VALIDATED == FALSE)
	{
		// SELECT A RANDOM HAND MOVE SEQUENCE //
		u8 random_hand_move_sequence = random_NUMBER(0,29);

		// IF CURRENT HAND POSITION IS DIFFERENT FROM 1RST HAND POSITION IN NEW MOVE SEQUENCE //
		if(TABLE_GENERATED_HAND_POSITION[G_CURRENT_TURN] != TABLE_HAND_MOVE[random_hand_move_sequence][0])
		{
			u8 j=0;

			for(j=0 ; j<10 ; j++)
			{
				TABLE_GENERATED_HAND_POSITION[9-j] = TABLE_HAND_MOVE[random_hand_move_sequence][j];
			}

			G_RANDOM_HAND_MOVE_VALIDATED = TRUE;
		}
	}
}