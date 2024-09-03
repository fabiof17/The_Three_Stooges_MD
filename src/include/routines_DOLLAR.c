#include <genesis.h>



#include "custom_tools.h"
#include "structures.h"
#include "variables.h"




#include "maps_DOLLAR.h"
#include "maps_GLOBAL.h"




#include "routines_ROULETTE.h"




#include "tables_DOLLAR.h"




void sequence_DOLLAR()
{
    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_WALKIN_DOLLAR[G_INDEX_3];

    if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
    {
        // CHANGING SPRITE ANIMATION FRAME //
        SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

        // RETRIEVE X POSITION FROM TABLE //
        SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 133 );


        // UPDATE INDEX IN STOOGES ANIMATION TABLE //
        // UP TO 30 (LAST INDEX IN ARRAY OF 31 ENTRIES) //
        if(G_INDEX_3 < 30)
        {
            G_INDEX_3 += 1;
        }        
    }


    if(G_COUNTER_1 == 146)
    {
        // PLAY HEAD SHOCK SOUND //
        XGM_startPlayPCM(SOUND_HEAD_SHOCK,15,SOUND_PCM_CH4);
    }


    else if(G_COUNTER_1 == 382)
    {
        // DISPLAY DIALOG //
        VDP_setTileMapEx(BG_A, image_DOLLAR_DIALOG.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 12, 34, 0, 0, 16, 7, DMA_QUEUE);

        // DISPLAY REWARD IN DIALOG //
        VDP_setTileMapEx(BG_A, image_DOLLAR_100.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_DOLLAR_DIALOG.tileset->numTile), 14, 38, 0, 0,  3, 1, DMA_QUEUE);

        // DISPLAY DIALOG ARROW //
        SPR_setPosition(sprite_ARROW_DIALOG,166,104);
    }


    else if(G_COUNTER_1 == 641)
    {
        // CLEAR DIALOG //
        VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 0), 12, 34, 0, 0, 16, 7, DMA_QUEUE);

        // REMOVE DIALOG ARROW //
        SPR_releaseSprite(sprite_ARROW_DIALOG);
        sprite_ARROW_DIALOG = NULL;

        // REMOVE DOLLAR BAG SPRITE //
        SPR_releaseSprite(sprite_DOLLAR_BAG);
        sprite_DOLLAR_BAG = NULL;

        // CHANGE STOOGES FRAME //
        SPR_setFrame(sprite_STOOGES , 17);
    }


    else if(G_COUNTER_1 == 560)
    {
        // PLAY SWATTER SOUND //
        XGM_startPlayPCM(SOUND_JOY_CRY,15,SOUND_PCM_CH4);
    }


    else if(G_COUNTER_1 == 760)
    {
            G_POS_Y_CAMERA = 0;
            
            // DISPLAY HUB //
            display_HUB();

            // GENERATE NEW HAND MOVE SEQUENCE //
            //generate_RANDOM_HAND_MOVE();


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









