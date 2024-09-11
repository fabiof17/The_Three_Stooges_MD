#include <genesis.h>




#include "variables.h"




void sequence_THE_END()
{
    if(G_COUNTER_1 > 120)
    {           
        if(G_COUNTER_1%5 == TRUE)
        {
            if(G_POS_X_CAMERA_CURTAIN_1 != 0)
            {
                G_POS_X_CAMERA_CURTAIN_1 += 1;
            }

            if(G_POS_X_CAMERA_CURTAIN_2 != 160)
            {
                G_POS_X_CAMERA_CURTAIN_2 -= 1;
            }


            VDP_setHorizontalScrollVSync(BG_B, G_POS_X_CAMERA_CURTAIN_1);
            VDP_setHorizontalScrollVSync(BG_A, G_POS_X_CAMERA_CURTAIN_2);
        }
    }
    
    if(G_COUNTER_1 == 1000)
    {
        // FADE OUT : 60 FRAMES //
        PAL_fadeOutAll(60,FALSE);

    }


    G_COUNTER_1 += 1;

    if(G_COUNTER_1 == 1002)
    {
        G_COUNTER_1 = 1001;
    }
}









