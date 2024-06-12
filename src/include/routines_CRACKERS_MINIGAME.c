#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"








inline static void collision_CRACKERS()
{
    u8 i;

    for(i=0 ; i<14 ; i++)
    {
        if(list_CRACKER[i].state_CRACKER < 3)
        {
            u16 distance_X = abs( (list_CRACKER[i].pos_X + 28) - (G_POS_X_PLAYER + 24) );
            u16 distance_Y = abs( (list_CRACKER[i].pos_Y + 20) - (G_POS_Y_PLAYER + 16) );
            
            if(distance_X < 16)
            {
                if(distance_Y < 16)
                {
                    VDP_drawIntEx_BG_A_QUEUE(i,1,0,0,PAL0);
                    VDP_drawIntEx_BG_A_QUEUE(distance_X,3,0,2,PAL0);
                    VDP_drawIntEx_BG_A_QUEUE(distance_Y,3,0,3,PAL0);

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

        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON LEFT                          //
        //                                                              //
        //--------------------------------------------------------------//

        if(value & BUTTON_LEFT)
        {
            if(G_POS_X_PLAYER - 2 < 39)
            {
                G_POS_X_PLAYER = 39;
            }

            else
            {
                G_POS_X_PLAYER -= 2;
            }

            if(value & BUTTON_UP)
            {
                if(G_POS_Y_PLAYER - 2 < 100)
                {
                    G_POS_Y_PLAYER = 100;
                }

                else
                {
                    G_POS_Y_PLAYER -= 2;
                }
            }

            else if(value & BUTTON_DOWN)
            {
                if(G_POS_Y_PLAYER + 2 < 201)
                {
                    G_POS_Y_PLAYER += 2;
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
            if(G_POS_X_PLAYER + 2 > 255)
            {
                G_POS_X_PLAYER = 255;
            }

            else
            {
                G_POS_X_PLAYER += 2;
            }

            if(value & BUTTON_UP)
            {
                if(G_POS_Y_PLAYER - 2 < 100)
                {
                    G_POS_Y_PLAYER = 100;
                }

                else
                {
                    G_POS_Y_PLAYER -= 2;
                }
            }

            else if(value & BUTTON_DOWN)
            {
                if(G_POS_Y_PLAYER + 2 < 201)
                {
                    G_POS_Y_PLAYER += 2;
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
            if(G_POS_Y_PLAYER - 2 < 100)
            {
                G_POS_Y_PLAYER = 100;
            }

            else
            {
                G_POS_Y_PLAYER -= 2;
            }

            if(value & BUTTON_LEFT)
            {
                if(G_POS_X_PLAYER - 2 < 39)
                {
                    G_POS_X_PLAYER = 39;
                }

                else
                {
                    G_POS_X_PLAYER -= 2;
                }
            }

            else if(value & BUTTON_RIGHT)
            {
                if(G_POS_X_PLAYER + 2 > 255)
                {
                    G_POS_X_PLAYER = 255;
                }

                else
                {
                    G_POS_X_PLAYER += 2;
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
            if(G_POS_Y_PLAYER + 2 < 201)
            {
                G_POS_Y_PLAYER += 2;
            }

            if(value & BUTTON_LEFT)
            {
                if(G_POS_X_PLAYER - 2 < 39)
                {
                    G_POS_X_PLAYER = 39;
                }

                else
                {
                    G_POS_X_PLAYER -= 2;
                }
            }

            else if(value & BUTTON_RIGHT)
            {
                if(G_POS_X_PLAYER + 2 > 255)
                {
                    G_POS_X_PLAYER = 255;
                }

                else
                {
                    G_POS_X_PLAYER += 2;
                }
            }
        }

        SPR_setPosition(sprite_HAND[2] , G_POS_X_PLAYER      , G_POS_Y_PLAYER);
        SPR_setPosition(sprite_HAND[1] , G_POS_X_PLAYER -  7 , G_POS_Y_PLAYER + 100);
        SPR_setPosition(sprite_HAND[0] , G_POS_X_PLAYER + 10 , G_POS_Y_PLAYER +  44);

        //collision_CRACKERS();
    }
}




void sequence_CRACKERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == CRACKER_SPOON_GRAB)
    {
        //------------------------------------------------------------------//
        //                       UPDATE SPRITE FRAME                        //
        //------------------------------------------------------------------//
        if(G_COUNTER_1 == 6)
        {
            SPR_setPosition(sprite_HAND[1] , G_POS_X_PLAYER -  7 , G_POS_Y_PLAYER + 100);            
            SPR_setPosition(sprite_HAND[0] , G_POS_X_PLAYER + 10 , G_POS_Y_PLAYER +  44);


            SPR_setFrame(sprite_HAND[0],0);
            SPR_setFrame(sprite_HAND[1],0);
            SPR_setFrame(sprite_HAND[2],0);

            SPR_setPosition(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER , G_POS_X_PLAYER - 7 , G_POS_Y_PLAYER  - 8);



        }

        //------------------------------------------------------------------//
        //                          MOVE HAND DOWN                          //
        //------------------------------------------------------------------//
        else if(G_COUNTER_1 > 6 && G_COUNTER_1 < 32)
        {
            //------------------------------------------------------------------//
            //                      REMOVE CRACKER SPRITE                       //
            //------------------------------------------------------------------//
            if(G_COUNTER_1 == 31)
            {
                SPR_releaseSprite(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER);
                list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER = NULL;


                //------------------------------------------------------------------//
                //                   IF CRACKERS NUMBER REACHES 0                   //
                //                GO TO NEXT ROUND AND SPREAD SCREEN                //
                //------------------------------------------------------------------//
                if(G_NUMBER_CRACKERS == 0)
                {
                    PAL_fadeOutAll(2,FALSE);

                    SPR_reset();

                    G_REWARD += 50;

                    
                    G_ROUND_CRACKERS    += 1;

                    //------------------------------------------------------------------//
                    //                  IF WE HAVE PLAYED ALL 4 ROUNDS                  //
                    //                  GO TO CRACKERS GAME OVER SCREEN                 //
                    //------------------------------------------------------------------//
                    if(G_ROUND_CRACKERS > CRACKERS_ROUND_4)
                    {
                        G_CRACKERS_SCREEN_TYPE  = CRACKERS_SCREEN_OVER;
                    }

                    //------------------------------------------------------------------//
                    //                     ELSE GO TO SPREAD SCREEN                     //
                    //------------------------------------------------------------------//
                    else
                    {
                        G_CRACKERS_SCREEN_TYPE  = CRACKERS_SCREEN_SPREAD;
                    }


                    G_SCENE_TYPE            = SCENE_CRACKERS_SCREEN;
                    G_SCENE_NEXT            = SCENE_CRACKERS_SCREEN;

                    G_CRACKERS_INIT         = FALSE;

                    G_SCENE_LOADED          = FALSE;

                    return;
                }
            }

            G_POS_Y_PLAYER += 4;

            SPR_setPosition(sprite_HAND[2] , G_POS_X_PLAYER, G_POS_Y_PLAYER);
            SPR_setPosition(sprite_HAND[1] , G_POS_X_PLAYER -  7 , G_POS_Y_PLAYER + 100);            
            SPR_setPosition(sprite_HAND[0] , G_POS_X_PLAYER + 10 , G_POS_Y_PLAYER +  44);

            if(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER != NULL)
            {
                SPR_setPosition(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER , G_POS_X_PLAYER - 7 , G_POS_Y_PLAYER  - 8);
            }
        }

        //------------------------------------------------------------------//
        //                           MOVE HAND UP                           //
        //------------------------------------------------------------------//
        else if(G_COUNTER_1 > 35 && G_COUNTER_1 < 57)
        {
            G_POS_Y_PLAYER -= 4;

            SPR_setPosition(sprite_HAND[2] , G_POS_X_PLAYER, G_POS_Y_PLAYER);
            SPR_setPosition(sprite_HAND[1] , G_POS_X_PLAYER -  7 , G_POS_Y_PLAYER + 100);            
            SPR_setPosition(sprite_HAND[0] , G_POS_X_PLAYER + 10 , G_POS_Y_PLAYER +  44);
        }

        //------------------------------------------------------------------//
        //                    GO BACK TO HAND MOVE PHASE                    //
        //------------------------------------------------------------------//
        else if(G_COUNTER_1 == 62)
        {
            G_COUNTER_1 = 0;

            G_PHASE_SEQUENCE = CRACKER_SPOON_MOVE;
            
            return;            
        }
        

        G_COUNTER_1 += 1;
    }


    else if(G_PHASE_SEQUENCE == CRACKER_SPOON_MISS)
    {
        if(G_COUNTER_1 == 6)
        {
            SPR_setPosition(sprite_HAND[1] , G_POS_X_PLAYER -  7 , G_POS_Y_PLAYER + 100);            
            SPR_setPosition(sprite_HAND[0] , G_POS_X_PLAYER + 10 , G_POS_Y_PLAYER +  44);


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









