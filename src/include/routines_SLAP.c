#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"




#include "maps_SLAP.h"
#include "maps_GLOBAL.h"




#include "sprites_SLAP.h"




#include "tables_SLAP.h"




void sequence_SLAP()
{
    if(G_PHASE_SEQUENCE == SLAP_PHASE_WALKIN)
    {
        // STOOGES ANIMATION //
        // SETUP POINTER TO STOOGES ANIMATION TABLE //
        const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_WALKIN_SLAP[G_INDEX_3];

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



        if(G_COUNTER_1 == 616)
        {
            VDP_loadTileSet(image_SLAP_DIALOG_1.tileset, G_ADR_VRAM_DIALOG, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_SLAP_DIALOG_1.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 12, 34, 0, 0, 16, 7, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG,160,104);
        }

        else if(G_COUNTER_1 == 707)
        {
            VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, 0), 12, 34, 0, 0, 16, 7, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG,-24,-32);
        }

        else if(G_COUNTER_1 == 724)
        {
            VDP_loadTileSet(image_SLAP_DIALOG_2.tileset, G_ADR_VRAM_DIALOG, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_SLAP_DIALOG_2.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 12, 32, 0, 0, 16, 9, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG,160,104);
        }

        else if(G_COUNTER_1 == 1774)
        {
            // DISPLAY SLAP HUB //
            VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, 0), 12, 32, 0, 0, 16, 9, DMA_QUEUE);
            VDP_setTileMapEx(BG_B, image_SLAP_HUB.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 9, 34, 0, 0, 22, 8, DMA_QUEUE);

            // DIALOG ARROW SPRITE OFF SCREEN //
            SPR_setPosition(sprite_ARROW_DIALOG,-24,-32);

            // DISPLAY SLAP HUB SPRITES //
            SPR_setPosition(sprite_HAND_SLAP,152,71);
            SPR_setPosition(sprite_METER_SLAP,-6,55);

            // RELEASE STOOGES SPRITE //
            SPR_releaseSprite(sprite_STOOGES);
            sprite_STOOGES = NULL;

            // CREATE SPRITES FOR MOE, LARRY, CURLY //
            sprite_MOE   = SPR_addSprite(&tiles_SPR_MOE_SLAP,    131, 133, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
            sprite_LARRY = SPR_addSprite(&tiles_SPR_LARRY_SLAP,   99, 129, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
            sprite_CURLY = SPR_addSprite(&tiles_SPR_CURLY_SLAP,  164, 127, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));

            //SPR_setAnimAndFrame(sprite_MOE,1,3);
            //SPR_setAnimAndFrame(sprite_LARRY,1,0);


            memcpy( &palette_64[16] , image_SLAP_HUB.palette->data     , 16 * 2 );
            PAL_setPalette(PAL1,image_SLAP_HUB.palette->data,DMA_QUEUE);




            G_PHASE_SEQUENCE = SLAP_PHASE_MINIGAME;

            G_COUNTER_1 = 0;
            G_INDEX_3 = 0;

            return;
        }




        G_COUNTER_1 += 1;
    }

    else if(G_PHASE_SEQUENCE == SLAP_PHASE_MINIGAME)
    {
        //
    }

}









