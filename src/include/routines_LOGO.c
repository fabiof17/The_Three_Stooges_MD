#include <genesis.h>




#include "variables.h"




void sequence_LOGO()
{
    if(G_COUNTER_1 == 120)
    {
        //SPR_setPosition(sprite_STOOGES,115,146);
        SPR_setFrame(sprite_STOOGES,1);
    }

    else if(G_COUNTER_1 == 180)
    {
        //SPR_setPosition(sprite_STOOGES,115,146);
        SPR_setFrame(sprite_STOOGES,2);
    }


    else if(G_COUNTER_1 == 300)
    {           
        // FADE OUT : 30 FRAMES //
        PAL_fadeOutAll(30,FALSE);

        // CLEAR PLANES //
        VDP_clearPlane(BG_B,TRUE);
        VDP_clearPlane(BG_A,TRUE);

        // RELEASE ALL SPRITES //
        SPR_reset();

        G_REEL              = REEL_INTRO;

        G_SCENE             = SCENE_FADE_IN;
        G_SCENE_TYPE        = SCENE_INTRO_SCREEN_1;
        G_SCENE_NEXT        = SCENE_INTRO_SCREEN_1;

        G_SCENE_LOADED      = FALSE;

        waitMs(4000);

        return;
    }


    G_COUNTER_1 += 1;

}









