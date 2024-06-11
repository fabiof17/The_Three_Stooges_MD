#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"








inline static void collision_CRACKERS()
{
    s16 pos_X_HAND = SPR_getPositionX(sprite_HAND[2]);
    s16 pos_Y_HAND = SPR_getPositionY(sprite_HAND[2]);

    u8 i;

    for(i=0 ; i<G_NB_CRACKERS ; i++)
    {
        if(list_CRACKER[i].state_CRACKER < 3)
        {
            u16 distance_X = abs( (list_CRACKER[i].pos_X + 28) - (pos_X_HAND + 24) );
            u16 distance_Y = abs( (list_CRACKER[i].pos_Y + 20) - (pos_Y_HAND + 16) );
            
            if(distance_X < 16)
            {
                if(distance_Y < 16)
                {
                    //VDP_drawIntEx_BG_A_QUEUE(i,1,0,0,PAL0);
                    //VDP_drawIntEx_BG_A_QUEUE(distance_X,3,0,2,PAL0);
                    //VDP_drawIntEx_BG_A_QUEUE(distance_Y,3,0,3,PAL0);

                    return;
                }
            }
        }
    }
}


void joypad_CRACKERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == CRACKER_SPOON_MOVE)
    {
        u16 value=JOY_readJoypad(JOY_1);

        s16 pos_X_HAND = SPR_getPositionX(sprite_HAND[2]);
        s16 pos_Y_HAND = SPR_getPositionY(sprite_HAND[2]);

        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON LEFT                          //
        //                                                              //
        //--------------------------------------------------------------//

        if(value & BUTTON_LEFT)
        {
            if(pos_X_HAND - 2 < 39)
            {
                pos_X_HAND = 39;
            }

            else
            {
                pos_X_HAND -= 2;
            }

            if(value & BUTTON_UP)
            {
                if(pos_Y_HAND - 2 < 100)
                {
                    pos_Y_HAND = 100;
                }

                else
                {
                    pos_Y_HAND -= 2;
                }
            }

            else if(value & BUTTON_DOWN)
            {
                if(pos_Y_HAND + 2 > 200)
                {
                    pos_Y_HAND = 200;
                }

                else
                {
                    pos_Y_HAND += 2;
                }
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON RIGHT                         //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_RIGHT)
        {
            if(pos_X_HAND + 2 > 255)
            {
                pos_X_HAND = 255;
            }

            else
            {
                pos_X_HAND += 2;
            }

            if(value & BUTTON_UP)
            {
                if(pos_Y_HAND - 2 < 100)
                {
                    pos_Y_HAND = 100;
                }

                else
                {
                    pos_Y_HAND -= 2;
                }
            }

            else if(value & BUTTON_DOWN)
            {
                if(pos_Y_HAND + 2 > 200)
                {
                    pos_Y_HAND = 200;
                }

                else
                {
                    pos_Y_HAND += 2;
                }
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                          BUTTON UP                           //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_UP)
        {
            if(pos_Y_HAND - 2 < 100)
            {
                pos_Y_HAND = 100;
            }

            else
            {
                pos_Y_HAND -= 2;
            }

            if(value & BUTTON_LEFT)
            {
                if(pos_X_HAND - 2 < 39)
                {
                    pos_X_HAND = 39;
                }

                else
                {
                    pos_X_HAND -= 2;
                }
            }

            else if(value & BUTTON_RIGHT)
            {
                if(pos_X_HAND + 2 > 255)
                {
                    pos_X_HAND = 255;
                }

                else
                {
                    pos_X_HAND += 2;
                }
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON DOWN                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_DOWN)
        {
            if(pos_Y_HAND + 2 > 200)
            {
                pos_Y_HAND = 200;
            }

            else
            {
                pos_Y_HAND += 2;
            }

            if(value & BUTTON_LEFT)
            {
                if(pos_X_HAND - 2 < 39)
                {
                    pos_X_HAND = 39;
                }

                else
                {
                    pos_X_HAND -= 2;
                }
            }

            else if(value & BUTTON_RIGHT)
            {
                if(pos_X_HAND + 2 > 255)
                {
                    pos_X_HAND = 255;
                }

                else
                {
                    pos_X_HAND += 2;
                }
            }
        }

        SPR_setPosition(sprite_HAND[2] , pos_X_HAND      , pos_Y_HAND);
        SPR_setPosition(sprite_HAND[1] , pos_X_HAND -  7 , pos_Y_HAND + 100);
        SPR_setPosition(sprite_HAND[0] , pos_X_HAND + 10 , pos_Y_HAND +  44);

        //collision_CRACKERS();
    }
}




void sequence_CRACKERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == CRACKER_SPOON_GRAB)
    {
        s16 pos_X_HAND = SPR_getPositionX(sprite_HAND[2]);
        s16 pos_Y_HAND = SPR_getPositionY(sprite_HAND[2]);

        if(G_COUNTER_1 == 6)
        {
            SPR_setPosition(sprite_HAND[1] , pos_X_HAND -  7 , pos_Y_HAND + 100);            
            SPR_setPosition(sprite_HAND[0] , pos_X_HAND + 10 , pos_Y_HAND +  44);


            SPR_setFrame(sprite_HAND[0],0);
            SPR_setFrame(sprite_HAND[1],0);
            SPR_setFrame(sprite_HAND[2],0);

            SPR_setPosition(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER , pos_X_HAND - 7 , pos_Y_HAND  - 8);



        }

        if(G_COUNTER_1 > 10 && G_COUNTER_1 < 37)
        {
            if(pos_Y_HAND < 212)
            {
                if(pos_Y_HAND + 4 >211)
                {
                    pos_Y_HAND = 212;
                }

                else
                {
                    pos_Y_HAND += 4;
                }

                SPR_setPosition(sprite_HAND[2] , pos_X_HAND, pos_Y_HAND);
                SPR_setPosition(sprite_HAND[1] , pos_X_HAND -  7 , pos_Y_HAND + 100);            
                SPR_setPosition(sprite_HAND[0] , pos_X_HAND + 10 , pos_Y_HAND +  44);

                SPR_setPosition(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER , pos_X_HAND - 7 , pos_Y_HAND  - 8);
            }
        }


        if(G_COUNTER_1 == 36)
        {
            SPR_releaseSprite(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER);
            list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER = NULL;
        }


        else if(G_COUNTER_1 > 44)
        {
            if(pos_Y_HAND > 116)
            {
                if(pos_Y_HAND - 4 < 117)
                {
                    pos_Y_HAND = 116;

                    SPR_setPosition(sprite_HAND[2] , pos_X_HAND, pos_Y_HAND);
                    SPR_setPosition(sprite_HAND[1] , pos_X_HAND -  7 , pos_Y_HAND + 100);            
                    SPR_setPosition(sprite_HAND[0] , pos_X_HAND + 10 , pos_Y_HAND +  44);

                    G_COUNTER_1 = 0;

                    G_PHASE_SEQUENCE = CRACKER_SPOON_MOVE;

                    return;
                }

                else
                {
                    pos_Y_HAND -= 4;

                    SPR_setPosition(sprite_HAND[2] , pos_X_HAND, pos_Y_HAND);
                    SPR_setPosition(sprite_HAND[1] , pos_X_HAND -  7 , pos_Y_HAND + 100);            
                    SPR_setPosition(sprite_HAND[0] , pos_X_HAND + 10 , pos_Y_HAND +  44);
                }
            }
        }
        
        G_COUNTER_1 += 1;
    }


    else if(G_PHASE_SEQUENCE == CRACKER_SPOON_MISS)
    {
        s16 pos_X_HAND = SPR_getPositionX(sprite_HAND[2]);
        s16 pos_Y_HAND = SPR_getPositionY(sprite_HAND[2]);


        if(G_COUNTER_1 == 6)
        {
            SPR_setPosition(sprite_HAND[1] , pos_X_HAND -  7 , pos_Y_HAND + 100);            
            SPR_setPosition(sprite_HAND[0] , pos_X_HAND + 10 , pos_Y_HAND +  44);


            SPR_setFrame(sprite_HAND[0],0);
            SPR_setFrame(sprite_HAND[1],0);
            SPR_setFrame(sprite_HAND[2],0);

            G_COUNTER_1 = 0;

            G_PHASE_SEQUENCE = CRACKER_SPOON_MOVE;

            return;
        }

        G_COUNTER_1 += 1;
    }
}









