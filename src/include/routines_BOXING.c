#include <genesis.h>




#include "structures.h"
#include "variables.h"




#include "maps_BOXING.h"
#include "maps_GLOBAL.h"




#include "tables_BOXING.h"



void sequence_CONTRACT_BOXING()
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
        G_SCENE_TYPE    = SCENE_BOXING_SCREEN_TYPE1;
        G_SCENE_NEXT    = SCENE_BOXING_SCREEN_TYPE1;

        G_SCENE_LOADED  = FALSE;

        return;
    }

    G_COUNTER_1 += 1;

}


void sequence_BOXING()
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


    if(G_COUNTER_1 == 200)
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
        G_COUNTER_1 = 0;
        G_INDEX_3 = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN;
        G_SCENE_TYPE    = SCENE_CONTRACT_BOXING; //SCENE_BOXING_SCREEN_TYPE1
        G_SCENE_NEXT    = SCENE_CONTRACT_BOXING;

        G_SCENE_LOADED  = FALSE;

        return;
    }

    G_COUNTER_1 += 1;
}




void sequence_BOXING_SCREEN_TYPE_1()
{
    if(G_COUNTER_1 == 450)
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

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN_BOXING;
        G_SCENE_TYPE    = SCENE_BOXING_SCREEN_TYPE2; //SCENE_BOXING_SCREEN_TYPE1
        G_SCENE_NEXT    = SCENE_BOXING_SCREEN_TYPE2;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    
    G_COUNTER_1 += 1;
}


void sequence_BOXING_SCREEN_TYPE_2()
{
    if(G_COUNTER_1 == 10)
    {
        G_COUNTER_1 = 0;

        G_INDEX_1 += 1;
        G_INDEX_2 += 1;

        if(G_INDEX_1 == 4)
        {
            G_INDEX_1 = 0;
        }

        // (30*10 =300 FRAMES = 5SEC)
        /*if(G_INDEX_2 == 30)
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

            G_PHASE_SEQUENCE = 0;

            // DEFINE NEXT MINIGAME //
            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_ROULETTE;
            G_SCENE_NEXT    = SCENE_ROULETTE;

            G_SCENE_LOADED  = FALSE;

            return;
        
        }*/
    }
    
    PAL_setPalette( PAL1 , TABLE_BOXING_CYCLE[G_INDEX_1]->data , DMA);

    G_COUNTER_1 += 1;
}







