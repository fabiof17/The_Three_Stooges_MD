#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"




#include "maps_SLAP.h"
#include "maps_GLOBAL.h"




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

        else if(G_COUNTER_1 == 1024)
        {
            VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, 0), 12, 32, 0, 0, 16, 9, DMA_QUEUE);
            VDP_setTileMapEx(BG_B, image_SLAP_HUB.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 9, 34, 0, 0, 22, 8, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG,-24,-32);
            SPR_setPosition(sprite_HAND_SLAP,152,71);

            memcpy( &palette_64[16] , image_SLAP_HUB.palette->data     , 16 * 2 );
            PAL_setPalette(PAL1,image_SLAP_HUB.palette->data,DMA_QUEUE);
        }




        G_COUNTER_1 += 1;
    }

    else if(G_PHASE_SEQUENCE == SLAP_PHASE_MINIGAME)
    {
        //
    }

}









