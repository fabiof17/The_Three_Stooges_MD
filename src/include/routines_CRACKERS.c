#include <genesis.h>




#include "structures.h"
#include "variables.h"









#include "tables_BOXING.h"




void sequence_CONTRACT_CRACKERS()
{
    if(G_PHASE_SEQUENCE == CONTRACT_PHASE)
    {
        if(G_COUNTER_1 == 600)
        {
            G_PHASE_SEQUENCE = CONTRACT_PHASE_FADE_OUT;
        }

        G_COUNTER_1 += 1;
    }

    else if(G_PHASE_SEQUENCE == CONTRACT_PHASE_FADE_OUT)
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

        // STOP MUSIC //
        XGM_stopPlay();

        G_COUNTER_1 = 0;

        G_PHASE_SEQUENCE = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN;
        G_SCENE_TYPE    = SCENE_CRACKERS_SCREEN;
        G_SCENE_NEXT    = SCENE_CRACKERS_SCREEN;

        G_SCENE_LOADED  = FALSE;

        return;
    }
}




void sequence_CRACKERS()
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


    if(G_COUNTER_1 == 360)
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
        G_SCENE_TYPE    = SCENE_CONTRACT_CRACKERS;
        G_SCENE_NEXT    = SCENE_CONTRACT_CRACKERS;

        G_SCENE_LOADED  = FALSE;

        return;
    }

    G_COUNTER_1 += 1;
}


