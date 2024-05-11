#include <genesis.h>



#include "outils.h"
#include "palettes.h"
#include "structures.h"
#include "variables.h"




#include "sprites_QUESTION_MARK.h"




#include "tables_QUESTION_MARK.h"



void sequence_CONTRACT_QUESTION_MARK()
{
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

        G_PHASE_SEQUENCE = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN;
        G_SCENE_TYPE    = SCENE_REWARD;
        G_SCENE_NEXT    = SCENE_REWARD;

        G_SCENE_LOADED  = FALSE;

        return;
    }

    G_COUNTER_1 += 1;

}


void sequence_QUESTION_MARK()
{
    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_QUESTION_MARK[G_INDEX_3];

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
    
    

    // GO TO REWARD SCREEN //
    if(G_COUNTER_1 == 160)
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

        // GENERATE NEW HAND MOVE SEQUENCE //
        generate_RANDOM_HAND_MOVE();

        G_COUNTER_1 = 0;
        G_INDEX_3 = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN;
        G_SCENE_TYPE    = SCENE_CONTRACT_QUESTION_MARK;
        G_SCENE_NEXT    = SCENE_CONTRACT_QUESTION_MARK;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    
    G_COUNTER_1 += 1; 
}









