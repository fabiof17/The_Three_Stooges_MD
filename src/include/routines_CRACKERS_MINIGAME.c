#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"




#include "maps_CRACKERS.h"






inline static void spawn_OYSTER()
{
    if(G_NUMBER_CRACKERS > 0)
    {
        if(G_COUNTER_OYSTER == 0 || G_COUNTER_OYSTER == 60)
        {
            G_RANDOM_OK = FALSE;

            while(G_RANDOM_OK == FALSE)
            {
                u8 new_oyster = random_NUMBER(0,13);

                // IF MORE THAN 1 CRACKER REMAINING //
                if(G_NUMBER_CRACKERS != 1)
                {
                    if(list_CRACKER[new_oyster].state_CRACKER == CRACKER_PHASE_FREE)
                    {
                        list_CRACKER[new_oyster].animated = TRUE;

                        SPR_setFrame(list_CRACKER[new_oyster].spr_CRACKER,list_CRACKER[new_oyster].state_CRACKER);

                        G_RANDOM_OK = TRUE;
                    }
                }

                // IF ONLY 1 CRACKER REMAINING //
                else if(G_NUMBER_CRACKERS == 1)
                {
                    // IF PLAYER IS NOT GRABBING THE LAST CRACKER //
                    if(G_PHASE_SEQUENCE != CRACKER_SPOON_GRAB)
                    {
                        // IF LAST CRACKER IS NOT ANIMATED //
                        // IT GETS ANIMATED //
                        if(list_CRACKER[new_oyster].state_CRACKER == CRACKER_PHASE_FREE)
                        {
                            list_CRACKER[new_oyster].animated = TRUE;

                            SPR_setFrame(list_CRACKER[new_oyster].spr_CRACKER,list_CRACKER[new_oyster].state_CRACKER);

                            G_RANDOM_OK = TRUE;
                        }

                        // ELSE IF LAST CRACKER IS ALREADY ANIMTED //
                        else
                        {
                            G_RANDOM_OK = TRUE;
                        }
                    }

                    // IF PLAYER IS GRABBING THE LAST CRACKER //
                    else
                    {
                        G_RANDOM_OK = TRUE;
                    }
                }
            }
        }  
    }

    /*else
    {
        G_RANDOM_OK = TRUE;
    }*/

    /*else if(G_NUMBER_CRACKERS == 1)
    {
        if(list_CRACKER[G_SELECTED_CRACKER].state_CRACKER != CRACKER_PHASE_EATEN)
        {
            list_CRACKER[G_SELECTED_CRACKER].animated = TRUE;
            list_CRACKER[G_SELECTED_CRACKER].counter_CRACKER += 1;

            SPR_setFrame(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER,list_CRACKER[G_SELECTED_CRACKER].state_CRACKER);

            G_RANDOM_OK = TRUE;
        }
    }*/

    G_COUNTER_OYSTER += 1;

    if(G_COUNTER_OYSTER == 240)
    {
        G_COUNTER_OYSTER = 0;
    }
}


inline static void anim_OYSTER()
{
    u8 i;

    for(i=0 ; i<14 ; i++)
    {
        if(list_CRACKER[i].animated == TRUE)
        {
            if(list_CRACKER[i].state_CRACKER != CRACKER_PHASE_EATEN)
            {
                list_CRACKER[i].counter_CRACKER += 1;
                
                if(list_CRACKER[i].counter_CRACKER == 5)
                {
                    list_CRACKER[i].state_CRACKER += 1;
                    SPR_setFrame(list_CRACKER[i].spr_CRACKER,list_CRACKER[i].state_CRACKER);
                }

                else if(list_CRACKER[i].counter_CRACKER == 10)
                {
                    list_CRACKER[i].state_CRACKER += 1;
                    SPR_setFrame(list_CRACKER[i].spr_CRACKER,list_CRACKER[i].state_CRACKER);
                }

                else if(list_CRACKER[i].counter_CRACKER == 20)
                {
                    list_CRACKER[i].state_CRACKER += 1;
                    SPR_setFrame(list_CRACKER[i].spr_CRACKER,list_CRACKER[i].state_CRACKER);
                }

                else if(list_CRACKER[i].counter_CRACKER == 76)
                {
                    list_CRACKER[i].state_CRACKER += 1;
                    SPR_setFrame(list_CRACKER[i].spr_CRACKER,list_CRACKER[i].state_CRACKER);
                }

                else if(list_CRACKER[i].counter_CRACKER == 81)
                {
                    list_CRACKER[i].state_CRACKER += 1;
                    SPR_setFrame(list_CRACKER[i].spr_CRACKER,list_CRACKER[i].state_CRACKER);
                }

                else if(list_CRACKER[i].counter_CRACKER == 86)
                {
                    list_CRACKER[i].state_CRACKER += 1;
                    SPR_setFrame(list_CRACKER[i].spr_CRACKER,list_CRACKER[i].state_CRACKER);
                }

                else if(list_CRACKER[i].counter_CRACKER == 91)
                {
                    SPR_releaseSprite(list_CRACKER[i].spr_CRACKER);
                    list_CRACKER[i].spr_CRACKER = NULL;

                    list_CRACKER[i].state_CRACKER = CRACKER_PHASE_EATEN;
                    list_CRACKER[i].animated = FALSE;

                    G_NUMBER_CRACKERS -= 1;

                    if(G_NUMBER_CRACKERS == 0)
                    {
                        PAL_fadeOutAll(2,FALSE);

                        SPR_reset();

                        //------------------------------------------------------------------//
                        //                  IF WE HAVE PLAYED ALL 4 ROUNDS                  //
                        //                  GO TO CRACKERS GAME OVER SCREEN                 //
                        //------------------------------------------------------------------//
                        if(G_GRABBED_CRACKERS == 0)
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

                        G_SCENE                 = SCENE_FADE_OUT_CRACKERS;
                        G_SCENE_TYPE            = SCENE_CRACKERS_SCREEN;
                        G_SCENE_NEXT            = SCENE_CRACKERS_SCREEN;

                        G_CRACKERS_INIT         = FALSE;

                        G_SCENE_LOADED          = FALSE;

                        return;
                    }
                }
            }   
        }
    }
}





inline static void anim_SPREAD_CRACKERS_SCREEN()
{
    if(G_COUNTER_CRACKERS == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 85)
    {
        G_INDEX_1 += 1;

        if(G_INDEX_1 < G_GRABBED_CRACKERS)
        {
            G_COUNTER_CRACKERS = 73;

            return;
        }
    }

    else if(G_COUNTER_CRACKERS == 145)
    {
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_CRACKERS = 0;
        G_INDEX_1       = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }

    G_COUNTER_CRACKERS += 1;
}


void sequence_CRACKERS_SCREEN()
{
    //------------------------------------------------------------------//
    //                     SPREAD SCREEN ANIMATIONS                     //
    //------------------------------------------------------------------//
    if(G_CRACKERS_SCREEN_TYPE  == CRACKERS_SCREEN_SPREAD)
    {
        anim_SPREAD_CRACKERS_SCREEN();
    }


    //------------------------------------------------------------------//
    //                     OTHER SCREENS ANIMATIONS                     //
    //------------------------------------------------------------------//
    /*else
    {
        // POINTER DECLARATION //
        void (*ptr_INIT_CRACKERS_SCREEN)(void);

        // SETTING POINTER ON STREET INIT FUNCTION //
        ptr_INIT_CRACKERS_SCREEN = TABLE_ANIM_INTERMEDIATE_SCREEN[G_CRACKERS_SCREEN_TYPE];

        // RUNNING STREET INIT FUNCTION //
        (*ptr_INIT_CRACKERS_SCREEN)();
    }*/
}







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
    spawn_OYSTER();
    anim_OYSTER();

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
                //------------------------------------------------------------------//
                if(G_NUMBER_CRACKERS == 0)
                {
                    PAL_fadeOutAll(2,FALSE);

                    SPR_reset();


                    //------------------------------------------------------------------//
                    //                  IF WE HAVE PLAYED ALL 4 ROUNDS                  //
                    //                  GO TO CRACKERS GAME OVER SCREEN                 //
                    //------------------------------------------------------------------//
                    if(G_GRABBED_CRACKERS == 0)
                    {
                        G_CRACKERS_SCREEN_TYPE  = CRACKERS_SCREEN_OVER;
                    }

                    //------------------------------------------------------------------//
                    //                     ELSE GO TO SPREAD SCREEN                     //
                    //------------------------------------------------------------------//
                    else
                    {
                        G_REWARD += 50;
                        
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









