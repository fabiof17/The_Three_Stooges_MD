#include <genesis.h>




#include "variables.h"


#include "tables_INTRO.h"




void fadeOut_INTRO_SCREEN_1()
{
    // FADE OUT : 40 FRAMES //
    PAL_fadeOutAll(40,FALSE);

    // CLEAR PLANES //
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    // RELEASE ALL SPRITES //
    SPR_reset();


    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_TYPE        = SCENE_INTRO_SCREEN_2;
    G_SCENE_NEXT        = SCENE_INTRO_SCREEN_2;

    G_SCENE_LOADED      = FALSE;
}


void fadeOut_INTRO_SCREEN_2()
{
    // FADE OUT : 1 FRAME //
    PAL_fadeOutAll(1,FALSE);

    // CLEAR PLANES //
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    // RELEASE ALL SPRITES //
    SPR_reset();


    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_TYPE        = SCENE_INTRO_SCREEN_3;
    G_SCENE_NEXT        = SCENE_INTRO_SCREEN_3;

    G_SCENE_LOADED      = FALSE;
}


void fadeOut_INTRO_SCREEN_3()
{
    // FADE OUT : 40 FRAMES //
    PAL_fadeOutAll(40,FALSE);

    // RESET BG_A POSITION //
    VDP_setVerticalScrollVSync(BG_A , 0);

    // CLEAR PLANES //
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    // RELEASE ALL SPRITES //
    SPR_reset();


    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_TYPE        = SCENE_INTRO_SCREEN_4;
    G_SCENE_NEXT        = SCENE_INTRO_SCREEN_4;

    G_SCENE_LOADED      = FALSE;
}


void fadeOut_INTRO_SCREEN_4()
{
    // FADE OUT : 30 FRAMES //
    PAL_fadeOutAll(4,FALSE);

    // CLEAR PLANES //
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    // RELEASE ALL SPRITES //
    SPR_reset();


    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_TYPE        = SCENE_INTRO_SCREEN_5;
    G_SCENE_NEXT        = SCENE_INTRO_SCREEN_5;

    G_SCENE_LOADED      = FALSE;
}


void fadeOut_INTRO_SCREEN_5()
{
    // FADE OUT : 30 FRAMES //
    PAL_fadeOutAll(4,FALSE);

    // CLEAR PLANES //
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    // RELEASE ALL SPRITES //
    SPR_reset();


    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_TYPE        = SCENE_INTRO_SCREEN_6;
    G_SCENE_NEXT        = SCENE_INTRO_SCREEN_6;

    G_SCENE_LOADED      = FALSE;
}


void fadeOut_INTRO_SCREEN_6()
{
    // FADE OUT : 30 FRAMES //
    PAL_fadeOutAll(30,FALSE);

    // CLEAR PLANES //
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    // RELEASE ALL SPRITES //
    SPR_reset();


    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_TYPE        = SCENE_INTRO_SCREEN_7;
    G_SCENE_NEXT        = SCENE_INTRO_SCREEN_7;

    G_SCENE_LOADED      = FALSE;
}


void fadeOut_INTRO_SCREEN_7()
{
    // FADE OUT : 40 FRAMES //
    PAL_fadeOutAll(40,FALSE);

    // CLEAR PLANES //
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    // RELEASE ALL SPRITES //
    SPR_reset();


    G_REEL              = REEL_GAME;

    G_SCENE_TYPE        = SCENE_ROULETTE;

    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_NEXT        = SCENE_ROULETTE;

    G_SCENE_LOADED      = FALSE;
}








void anim_INTRO_SCREEN_3()
{
    // POINTER DECLARATION ON ANIMATION FUNCTION //
    void (*ptr_ANIM_INTRO)(void);

    // SETTING POINTER ON ANIMATION FUNCTION //
    ptr_ANIM_INTRO = TABLE_ANIM_INTRO_3[G_INDEX_1];

    // RUNNING ANIMATION //
    (*ptr_ANIM_INTRO)();
}


void anim_INTRO_SCREEN_7()
{
    // POINTER DECLARATION ON ANIMATION FUNCTION //
    void (*ptr_ANIM_INTRO)(void);

    // SETTING POINTER ON ANIMATION FUNCTION //
    ptr_ANIM_INTRO = TABLE_ANIM_INTRO_7[G_INDEX_1];

    // RUNNING ANIMATION //
    (*ptr_ANIM_INTRO)();


    
}






