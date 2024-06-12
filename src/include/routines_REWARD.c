#include <genesis.h>



//#include "outils.h"
#include "palettes.h"
#include "variables.h"



#include "tables_REWARD.h"




void fadeOut_REWARD()
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

    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_NEXT        = SCENE_ROULETTE;

    G_SCENE_LOADED      = FALSE;
}



void sequence_REWARD()
{
    if(G_COUNTER_1 == 10)
    {
        G_COUNTER_1 = 0;

        G_INDEX_1 += 1;
        G_INDEX_2 += 1;

        if(G_INDEX_1 == 3)
        {
            G_INDEX_1 = 0;
        }

        // (30*10 =300 FRAMES = 5SEC)
        if(G_INDEX_2 == 30)
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

            // 1 DAY SPENT //
            G_DAY += 1;

            // GET REWARD //
            G_MONEY += G_REWARD;

            // REINIT REWARD //
            G_REWARD = 0;

            G_PHASE_SEQUENCE = 0;

            // DEFINE NEXT MINIGAME //
            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_ROULETTE;
            G_SCENE_NEXT    = SCENE_ROULETTE;

            G_SCENE_LOADED  = FALSE;

            return;
        
        }
    }
    
    PAL_setPalette( PAL0 , TABLE_REWARD_CYCLE[G_INDEX_1]->data , DMA);

    G_COUNTER_1 += 1;
}









