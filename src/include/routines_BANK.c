#include <genesis.h>



//#include "palettes.h"
#include "structures.h"
#include "variables.h"




#include "maps_BANK.h"
#include "maps_GLOBAL.h"




#include "routines_ROULETTE.h"




#include "tables_BANK.h"




void sequence_BANK()
{
    if(G_PHASE_SEQUENCE == BANKER_PHASE_WALKIN)
    {
        // STOOGES ANIMATION //
        // SETUP POINTER TO STOOGES ANIMATION TABLE //
        const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_BANKER[G_INDEX_3];

        if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
        {
            // CHANGING SPRITE ANIMATION FRAME //
            SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

            // RETRIEVE X POSITION FROM TABLE //
            SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 133 );


            // UPDATE INDEX IN STOOGES ANIMATION TABLE //
            // UP TO 25 (LAST INDEX IN ARRAY OF 26 ENTRIES) //
            if(G_INDEX_3 < 25)
            {
                G_INDEX_3 += 1;
            }
        }


        if(G_COUNTER_1 == 675)
        {
            // REINIT COUNTER //
            G_COUNTER_1 = 0;
            
            G_PHASE_SEQUENCE = BANKER_PHASE_APPEAR;

            return;
        }

        G_COUNTER_1 += 1;
    }

    else if(G_PHASE_SEQUENCE == BANKER_PHASE_APPEAR)
    {
        // DORRS OPEN //
        if(G_COUNTER_1 == 230)
        {
            // DOORS OPEN //
            VDP_setTileMapEx(BG_A, image_BANK_BG_A.tilemap, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 16, 40, 16, 12, 8, 10, DMA_QUEUE);
            
            // BANKER SHOW UP //
            SPR_setPosition(sprite_BANKER[0] , 135 , 107);
            SPR_setPosition(sprite_BANKER[1] , 135 , 107);
        }

        // DISPLAY DIALOG //
        else if(G_COUNTER_1 == 549)
        {
            // DISPLAY DIALOG //
            VDP_setTileMapEx(BG_A, image_BANK_DIALOG.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 13, 32, 0, 0, 16, 6, DMA_QUEUE);

            // DISPLAY REMAINING DAYS //
            u8 remaining_days = 30 - G_DAY;

            if(remaining_days > 9)
            {
                u8 number1 = remaining_days/10;
                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 14 , 36 , 0, 0, 1, 1, DMA_QUEUE);

                u8 number2 = remaining_days - (number1*10);
                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 15 , 36 , 0, 0, 1, 1, DMA_QUEUE);
            }

            // DISPLAY DIALOG ARROW //
            SPR_setPosition(sprite_ARROW_DIALOG,168,80);
        }

        // DOORS GET CLOSED //
        else if(G_COUNTER_1 == 900)
        {
            // CLEAR DOORS //
            VDP_setTileMapEx(BG_A, image_BANK_BG_A.tilemap, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 16, 40, 0, 0, 8, 10, DMA_QUEUE);

            // CLEAR DIALOG //
            VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 0), 13, 32, 0, 0, 16, 6, DMA_QUEUE);

            // LOAD HUB FONT //
            VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, DMA_QUEUE);

            G_DAY += 1;

            // PRINT DAY NUMBER //
            if(G_DAY < 10)
            {
                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + G_DAY), 8 , 11 , 0, 0, 1, 1, CPU);
            }
            else
            {
                u8 number1 = G_DAY / 10;
                u8 number2 = G_DAY - (number1*10);

                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 8 , 11 , 0, 0, 1, 1, CPU);
                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 9 , 11 , 0, 0, 1, 1, CPU);

            }

            SPR_setFrame(sprite_STOOGES,17);
            SPR_setPosition(sprite_STOOGES,117,133);

            // REMOVE BANKER SPRITES //
            SPR_releaseSprite(sprite_BANKER[0]);
            sprite_BANKER[0] = NULL;
            SPR_releaseSprite(sprite_BANKER[1]);
            sprite_BANKER[1] = NULL;

            // HIDE DIALOG ARROW //
            SPR_setPosition(sprite_ARROW_DIALOG,-32,-48);

            
        }

        // DISPLAY HUB //
        else if(G_COUNTER_1 == 960)
        {           
            // DISPLAY HUB //
            display_HUB();


            G_COUNTER_1             = 0;
            G_INDEX_1               = 0;
            G_INDEX_2               = 0;
            G_INDEX_3               = 0;


            G_COUNTER_ROULETTE      = 0;
            G_CURRENT_TURN          = 9;

            G_SCENE = SCENE_ROULETTE;

            G_PHASE_SEQUENCE = ROULETTE_PHASE_READY;

            return;
        }


        G_COUNTER_1 += 1;
    }

}









