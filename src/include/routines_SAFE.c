#include <genesis.h>



#include "custom_tools.h"
#include "palettes.h"
#include "structures.h"
#include "variables.h"




#include "sprites_SAFE.h"




#include "tables_SAFE.h"



void sequence_CONTRACT_SAFE()
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

        if(G_LUCK == TRUE)
        {
            G_SCENE_TYPE    = SCENE_REWARD;
            G_SCENE_NEXT    = SCENE_REWARD;
        }

        else
        {
            // IF THE 30 DAYS AVAILABLE HAVE BEEN SPENT //
            if(G_DAY == 31)
            {
                G_SCENE             = SCENE_FADE_IN;
                G_SCENE_TYPE        = SCENE_GAMEOVER;
                G_SCENE_NEXT        = SCENE_GAMEOVER;
            }

            // ELSE WE GO TO THE ROULETTE SEQUENCE //
            else
            {
                G_SCENE         = SCENE_FADE_IN;
                G_SCENE_TYPE    = SCENE_ROULETTE;
                G_SCENE_NEXT    = SCENE_ROULETTE;
            }
        }

        G_SCENE_LOADED  = FALSE;

        return;
    }
}


void sequence_SAFE()
{
    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_SAFE[G_INDEX_3];

    if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
    {
        // CHANGING SPRITE ANIMATION FRAME //
        SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

        // RETRIEVE X POSITION FROM TABLE //
        SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 133 );


        // UPDATE INDEX IN STOOGES ANIMATION TABLE //
        // UP TO 27 (LAST INDEX IN ARRAY OF 28 ENTRIES) //
        if(G_INDEX_3 < 27)
        {
            G_INDEX_3 += 1;
        }
    }


    // ICE CUBE ANIMATION //
    // SETUP POINTER TO ICE CUBE ANIMATION TABLE //
    const struct_FALLING_OBJECT_ *ptr_ANIM_CHEST = &TABLE_ANIM_CHEST[G_INDEX_1];

    if(G_COUNTER_1 == ptr_ANIM_CHEST->num_FRAME)
    {
        // RETRIEVE X AND Y POSITION FROM TABLE //
        SPR_setPosition( sprite_CHEST , ptr_ANIM_CHEST->pos_X , ptr_ANIM_CHEST->pos_Y );

        // UPDATE INDEX IN ICE CUBE ANIMATION TABLE //
        // UP TO 30 (LAST INDEX IN ARRAY OF 31 ENTRIES) //
        if(G_INDEX_1 < 30)
        {
            G_INDEX_1 += 1;
        }
    }


    if(G_COUNTER_1 == 1162)
    {
        XGM_startPlayPCM(SOUND_CHEST_FALL,15,SOUND_PCM_CH4);
    }

    else if(G_COUNTER_1 == 1164)
    {
        SPR_setPosition(sprite_ROPE,153,0);

        SPR_setPosition(sprite_CHEST,129,6);

        SPR_setFrame(sprite_CHEST,1);
    }

    else if(G_COUNTER_1 == 1195)
    {
        SPR_setFrame(sprite_STOOGES,36);
        
        if(G_LUCK == TRUE)
        {
            SPR_setFrame(sprite_CHEST,2);
        }

        else
        {
            SPR_setFrame(sprite_CHEST,3);
        }
    }    
    

    // GO TO REWARD SCREEN //
    else if(G_COUNTER_1 == 1577)
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
        G_SCENE_TYPE    = SCENE_CONTRACT_SAFE;
        G_SCENE_NEXT    = SCENE_CONTRACT_SAFE;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    
    G_COUNTER_1 += 1; 
}









