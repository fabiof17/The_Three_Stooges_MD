#include <genesis.h>




#include "outils.h"
#include "palettes.h"
#include "variables.h"






void sequence_REWARD_QUESTION_MARK()
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









