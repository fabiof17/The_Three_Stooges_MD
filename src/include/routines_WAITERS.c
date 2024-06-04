#include <genesis.h>




#include "structures.h"
#include "variables.h"




#include "maps_WAITERS.h"




#include "tables_BOXING.h"




void sequence_CONTRACT_WAITERS()
{
    if(G_COUNTER_1 == 600)
    {
        // FADE OUT : 40 FRAMES //
        PAL_fadeOutAll(40,FALSE);

        // RESET SCROLLING //
        VDP_setVerticalScroll(BG_B , 0);
        VDP_setVerticalScroll(BG_A , 0);

        // CLEAR PLANES //
        VDP_clearPlane(BG_B,TRUE);
        VDP_clearPlane(BG_A,TRUE);

        // RELEASE ALL SPRITES //
        SPR_reset();

        G_COUNTER_1 = 0;

        G_PHASE_SEQUENCE = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN;
        G_SCENE_TYPE    = SCENE_WAITERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_WAITERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }

    G_COUNTER_1 += 1;

}




void sequence_WAITERS()
{
    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_BOXING[G_INDEX_3];

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




    if(G_COUNTER_1 == 600)
    {
        VDP_setTileMapEx(BG_B, image_STREET_WAITERS_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_STREET_WAITERS_BG_B1.tileset->numTile), 16, 11, 0, 0, 5, 11, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_STREET_WAITERS_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_STREET_WAITERS_BG_A1.tileset->numTile), 16, 11, 0, 0, 5, 11, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 720)
    {
        VDP_setTileMapEx(BG_A, image_WAITERS_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 9, 4, 0, 0, 15, 8, DMA_QUEUE);

        SPR_setPosition(sprite_ARROW_DIALOG , 136 , 96);
    }

    else if(G_COUNTER_1 == 960)
    {
        // FADE OUT : 40 FRAMES //
        PAL_fadeOutAll(40,FALSE);

        // RESET SCROLLING //
        VDP_setVerticalScroll(BG_B , 0);
        VDP_setVerticalScroll(BG_A , 0);

        // CLEAR PLANES //
        VDP_clearPlane(BG_B,TRUE);
        VDP_clearPlane(BG_A,TRUE);

        // RELEASE ALL SPRITES //
        SPR_reset();

        G_COUNTER_1 = 0;
        G_INDEX_3   = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN;
        G_SCENE_TYPE    = SCENE_CONTRACT_WAITERS;
        G_SCENE_NEXT    = SCENE_CONTRACT_WAITERS;

        G_SCENE_LOADED  = FALSE;

        return;
    }

    G_COUNTER_1 += 1;
}


