#include <genesis.h>




#include "variables.h"




void sequence_DISCLAIMER()
{
    if(G_COUNTER_1 == 300)
    {           
        // FADE OUT : 30 FRAMES //
        PAL_fadeOutAll(30,FALSE);

        // CLEAR PLANES //
        VDP_clearPlane(BG_B,TRUE);

        G_COUNTER_1         = 0;

        G_REEL              = REEL_LOGO;

        G_SCENE             = SCENE_FADE_IN;
        G_SCENE_TYPE        = SCENE_LOGO_SCREEN;
        G_SCENE_NEXT        = SCENE_LOGO_SCREEN;

        G_SCENE_LOADED      = FALSE;

        waitMs(1000);

        return;
    }


    G_COUNTER_1 += 1;
}









