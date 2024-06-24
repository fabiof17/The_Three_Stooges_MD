#include <genesis.h>




#include "outils.h"
#include "structures.h"
#include "variables.h"




#include "maps_GAMEOVER.h"
#include "maps_INTRO.h"





void sequence_GAMEOVER()
{
    if(G_MONEY < 5000)
    {
        // ...IS NOT ENOUGH ! //
        if(G_COUNTER_1 == 250)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 15, 9, 0, 0, 12, 5, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_FAIL_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 16, 10, 0, 0, 10, 3, DMA_QUEUE);

            u8 leading;

            if(G_MONEY < 10)
            {
                leading = 1;
            }

            else if(G_MONEY < 100)
            {
                leading = 2;
            }

            else if(G_MONEY < 1000)
            {
                leading = 3;
            }

            else if(G_MONEY < 10000)
            {
                leading = 4;
            }

            else if(G_MONEY < 10000)
            {
                leading = 5;
            }

            VDP_drawIntEx_BG_A_QUEUE(G_MONEY,leading,19,10,PAL2);

            SPR_setPosition(sprite_ARROW_DIALOG , 150 , 112);
        }

        // CLEAR DIALOG //
        else if(G_COUNTER_1 == 433)
        {
            VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 15, 9, 15, 9, 12, 5, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , -24 , -24);
        }


        // THE ORPHANAGE IS MINE! //
        else if(G_COUNTER_1 == 466)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 15, 9, 0, 0, 12, 5, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_FAIL_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 16, 10, 0, 3, 10, 3, DMA_QUEUE);
        
            SPR_setPosition(sprite_ARROW_DIALOG , 150 , 112);
        }










        G_COUNTER_1 += 1;
    }

}









