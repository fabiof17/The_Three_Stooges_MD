#include <genesis.h>



#include "custom_tools.h"
#include "palettes.h"
#include "structures.h"
#include "variables.h"




#include "sprites_QUESTION_MARK.h"




#include "tables_QUESTION_MARK.h"



void sequence_CONTRACT_QUESTION_MARK()
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

        // STOP MUSIC //
        XGM_stopPlay();

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


    // ICE CUBE ANIMATION //
    // SETUP POINTER TO ICE CUBE ANIMATION TABLE //
    const struct_ICE_CUBE_ *ptr_ANIM_ICE_CUBE = &TABLE_ANIM_ICE_CUBE[G_INDEX_1];

    if(G_COUNTER_1 == ptr_ANIM_ICE_CUBE->num_FRAME)
    {
        // RETRIEVE X AND Y POSITION FROM TABLE //
        SPR_setPosition( sprite_ICE_CUBE , ptr_ANIM_ICE_CUBE->pos_X , ptr_ANIM_ICE_CUBE->pos_Y );
        SPR_setPosition( sprite_ICE_CUBE_SHADOW , ptr_ANIM_ICE_CUBE->pos_X - 6 , ptr_ANIM_ICE_CUBE->pos_Y + 8 );

        // UPDATE INDEX IN ICE CUBE ANIMATION TABLE //
        // UP TO 30 (LAST INDEX IN ARRAY OF 31 ENTRIES) //
        if(G_INDEX_1 < 30)
        {
            G_INDEX_1 += 1;
        }
    }


    if(G_COUNTER_1 == 622)
    {
        SPR_setFrame(sprite_SCISSOR,1);

        SPR_setPosition(sprite_ICE_CUBE,150,23);
        SPR_setPosition(sprite_ICE_CUBE_SHADOW,144,31);
    }

    else if(G_COUNTER_1 == 679)
    {
        SPR_setFrame(sprite_STOOGES,36);
        
        SPR_setFrame(sprite_ICE_CUBE,1);

        SPR_releaseSprite(sprite_ICE_CUBE_SHADOW);
        sprite_ICE_CUBE_SHADOW = NULL;
    }    
    

    // GO TO REWARD SCREEN //
    else if(G_COUNTER_1 == 810)
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
        G_INDEX_3   = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN;
        G_SCENE_TYPE    = SCENE_CONTRACT_QUESTION_MARK;
        G_SCENE_NEXT    = SCENE_CONTRACT_QUESTION_MARK;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    
    G_COUNTER_1 += 1; 
}









