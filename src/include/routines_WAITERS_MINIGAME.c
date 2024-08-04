#include <genesis.h>



#include "custom_tools.h"
#include "structures.h"
#include "variables.h"


#include "maps_WAITERS.h"


#include "tables_WAITERS.h"




inline static void update_SCORE()
{
    if(G_REWARD < 100)
    {
        u8 tens = G_REWARD / 10;
        
        VDP_drawIntEx_BG_A_QUEUE(tens,1,6,4,PAL1);
        VDP_drawIntEx_BG_A_QUEUE(   0,1,8,4,PAL1);
    }

    else if(G_REWARD < 1000)
    {
        u8 hundreds  =  G_REWARD / 100;
        u8 tens      =  (G_REWARD - (hundreds * 100) ) / 10;
        
        VDP_drawIntEx_BG_A_QUEUE(hundreds,1,6 ,4,PAL1);
        VDP_drawIntEx_BG_A_QUEUE(tens    ,1,8 ,4,PAL1);
        VDP_drawIntEx_BG_A_QUEUE(0       ,1,10,4,PAL1);
    }
}




void joypad_WAITERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == WAITER_PHASE_ACTION)
    {
        if(G_ACTION_WAITER_AUTHORIZED == TRUE)
        {
            u16 value=JOY_readJoypad(JOY_1);

            //--------------------------------------------------------------//
            //                                                              //
            //                       NO JOYPAD INPUT                        //
            //                                                              //
            //--------------------------------------------------------------//

            // CURLY CROUCHES //
            if((value & BUTTON_DIR) == 0)
            {            
                // CURLY CROUCHES //
                //if(G_SELECTED_WAITER != WAITER_CURLY)
                //{
                    // IF CURLY IS IDLE //
                    if(list_WAITERS[1].state_CHARACTER == CHAR_PHASE_IDLE)
                    {
                        SPR_setFrame(list_WAITERS[1].spr_CHAR_1,1);
                        SPR_setFrame(list_WAITERS[1].spr_CHAR_2,1);

                        SPR_setPosition(sprite_HAND_WAITERS,270,108);
                        
                        list_WAITERS[1].state_CHARACTER = CHAR_PHASE_CROUCH;

                        G_SELECTED_WAITER = WAITER_CURLY;
                    }




                    // IF LARRY IS CROUCHING //
                    // NO NEED TO CHECK FOR MOE //
                    if(list_WAITERS[0].state_CHARACTER < CHAR_PHASE_GRAB)
                    {
                        SPR_setFrame(list_WAITERS[0].spr_CHAR_1,0);
                        SPR_setFrame(list_WAITERS[0].spr_CHAR_2,0);
                        
                        list_WAITERS[0].state_CHARACTER = CHAR_PHASE_IDLE;

                        //return;
                    }

                    // IF MOE IS CROUCHING //
                    if(list_WAITERS[2].state_CHARACTER < CHAR_PHASE_GRAB)
                    {
                        SPR_setFrame(list_WAITERS[2].spr_CHAR_1,0);
                        SPR_setFrame(list_WAITERS[2].spr_CHAR_2,0);
                        
                        list_WAITERS[2].state_CHARACTER = CHAR_PHASE_IDLE;
                    }
                //}
            }


            //--------------------------------------------------------------//
            //                                                              //
            //                          BUTTON UP                           //
            //                                                              //
            //--------------------------------------------------------------//

            // MOE CROUCHES //
            else if(value & BUTTON_UP)
            {
                //if(G_SELECTED_WAITER != WAITER_MOE)
                //{
                    // IF MOE IS IDLE //
                    if(list_WAITERS[2].state_CHARACTER == CHAR_PHASE_IDLE)
                    {
                        SPR_setFrame(list_WAITERS[2].spr_CHAR_1,1);
                        SPR_setFrame(list_WAITERS[2].spr_CHAR_2,1);

                        SPR_setPosition(sprite_HAND_WAITERS,254,104);
                        
                        list_WAITERS[2].state_CHARACTER = CHAR_PHASE_CROUCH;

                        G_SELECTED_WAITER = WAITER_MOE;
                    }




                    // IF LARRY IS CROUCHING //
                    // NO NEED TO CHECK FOR CURLY //
                    if(list_WAITERS[0].state_CHARACTER < CHAR_PHASE_GRAB)
                    {
                        SPR_setFrame(list_WAITERS[0].spr_CHAR_1,0);
                        SPR_setFrame(list_WAITERS[0].spr_CHAR_2,0);
                        
                        list_WAITERS[0].state_CHARACTER = CHAR_PHASE_IDLE;

                        //return;
                    }

                    // IF CURLY IS CROUCHING //
                    if(list_WAITERS[1].state_CHARACTER < CHAR_PHASE_GRAB)
                    {
                        SPR_setFrame(list_WAITERS[1].spr_CHAR_1,0);
                        SPR_setFrame(list_WAITERS[1].spr_CHAR_2,0);
                        
                        list_WAITERS[1].state_CHARACTER = CHAR_PHASE_IDLE; 
                    }
                //}
            }


            //--------------------------------------------------------------//
            //                                                              //
            //                         BUTTON DOWN                          //
            //                                                              //
            //--------------------------------------------------------------//

            // LARRY CROUCHES //
            else if(value & BUTTON_DOWN)
            {
                //if(G_SELECTED_WAITER != WAITER_LARRY)
                //{
                    // IF LARRY IS IDLE //
                    if(list_WAITERS[0].state_CHARACTER == CHAR_PHASE_IDLE)
                    {
                        SPR_setFrame(list_WAITERS[0].spr_CHAR_1,1);
                        SPR_setFrame(list_WAITERS[0].spr_CHAR_2,1);

                        SPR_setPosition(sprite_HAND_WAITERS,286,112);
                        
                        list_WAITERS[0].state_CHARACTER = CHAR_PHASE_CROUCH;

                        G_SELECTED_WAITER = WAITER_LARRY;
                    }




                    // IF MOE IS CROUCHING //
                    // NO NEED TO CHECK FOR CURLY //
                    if(list_WAITERS[2].state_CHARACTER < CHAR_PHASE_GRAB)
                    {
                        SPR_setFrame(list_WAITERS[2].spr_CHAR_1,0);
                        SPR_setFrame(list_WAITERS[2].spr_CHAR_2,0);
                        
                        list_WAITERS[2].state_CHARACTER = CHAR_PHASE_IDLE;

                        //return;
                    }

                    // IF CURLY IS CROUCHING //
                    if(list_WAITERS[1].state_CHARACTER < CHAR_PHASE_GRAB)
                    {
                        SPR_setFrame(list_WAITERS[1].spr_CHAR_1,0);
                        SPR_setFrame(list_WAITERS[1].spr_CHAR_2,0);
                        
                        list_WAITERS[1].state_CHARACTER = CHAR_PHASE_IDLE; 
                    }
                //}
            }
        }
    }
}




inline static void check_WAITER_ACTION_AUTHORISATION()
{
    if(G_ACTION_WAITER_AUTHORIZED == FALSE)
    {
        if(G_COUNTER_ACTION_WAITERS == 24)
        {
            //
            
            G_COUNTER_ACTION_WAITERS = 0;

            G_ACTION_WAITER_AUTHORIZED = TRUE;

            return;
        }
        
        G_COUNTER_ACTION_WAITERS += 1;
    }

}




inline static void anim_PIE()
{
    u8 i;

    for(i=0 ; i<3 ; i++)
    {
        if(list_WAITERS[i].state_PIE == PIE_PHASE_THROW)
        {
            //--------------------------------------------------------------------//
            //                      INCREASE PIE ANIM INDEX                       //
            //--------------------------------------------------------------------//
            list_WAITERS[i].index_ANIM_PIE += 1;


            //--------------------------------------------------------------------//
            //                                                                    //
            //            IF PIE HAS REACHED THE END OF ITS TRAJECTORY            //
            //                                                                    //
            //--------------------------------------------------------------------//
            if(list_WAITERS[i].index_ANIM_PIE == 58)
            {
                //--------------------------------------------------------------------//
                //                                                                    //
                //                IF THERE ARE STILL PIES TO BE SERVED                //
                //                                                                    //
                //--------------------------------------------------------------------//
                if(G_SERVED_PIES < G_MAX_PIES)
                {
                    //--------------------------------------------------------------------//
                    //                         RESET PIE COUNTER                          //
                    //--------------------------------------------------------------------//
                    list_WAITERS[i].index_ANIM_PIE = 0;

                    //--------------------------------------------------------------------//
                    //                   SET POINTER TO PIE ANIM TABLE                    //
                    //--------------------------------------------------------------------//
                    const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                    if(i == WAITER_LARRY)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_LARRY[list_WAITERS[WAITER_LARRY].index_ANIM_PIE];
                    }

                    else if(i == WAITER_CURLY)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_CURLY[list_WAITERS[WAITER_CURLY].index_ANIM_PIE];
                    }

                    else if(i == WAITER_MOE)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MOE[list_WAITERS[WAITER_MOE].index_ANIM_PIE];
                    }


                    //--------------------------------------------------------------------//
                    //                  A NEW PIE IS SERVED ON THE TABLE                  //
                    //--------------------------------------------------------------------//
                    list_WAITERS[i].state_PIE = PIE_PHASE_SERVED;

                    SPR_setPosition(list_WAITERS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);
                    SPR_setFrame(list_WAITERS[i].spr_PIE , 0);


                    G_SERVED_PIES += 1;
                }


                //--------------------------------------------------------------------//
                //                                                                    //
                //                    IF ALL PIES HAVE BEEN SERVED                    //
                //                                                                    //
                //--------------------------------------------------------------------//
                else
                {
                    SPR_setPosition(list_WAITERS[i].spr_PIE , -32 , -32);
                    
                    list_WAITERS[i].state_PIE = PIE_PHASE_OUT;
                }




                //--------------------------------------------------------------------//
                //                                                                    //
                //                     IF GUEST IS NOT CROUCHING                      //
                //                  CHECK COLLISION WITH FACING GUEST                 //
                //                                                                    //
                //--------------------------------------------------------------------//
                if(list_GUESTS[i].state_CHARACTER != CHAR_PHASE_CROUCH)
                {
                    list_GUESTS[i].counter_CHARACTER = 0;

                    SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , CHAR_PHASE_HIT_1);
                    SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , CHAR_PHASE_HIT_1);

                    //--------------------------------------------------------------------//
                    //                !!!  TRICK TO AVOID SPRITE LIMIT  !!!               //
                    //                          IF GUEST IS MAN 1                         //
                    //--------------------------------------------------------------------//
                    if(i == GUEST_MAN_1)
                    {
                        VDP_loadTileSet(image_MAN1_6_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                    }


                    //--------------------------------------------------------------------//
                    //                        GUEST GOES TO PHASE                         //
                    //--------------------------------------------------------------------//
                    list_GUESTS[i].state_CHARACTER = CHAR_PHASE_HIT_1;

                    //--------------------------------------------------------------------//
                    //                         REWARD INCREASED                           //
                    //--------------------------------------------------------------------//
                    G_REWARD += 10;

                    //--------------------------------------------------------------------//
                    //                          WE UPDATE SCORE                           //
                    //--------------------------------------------------------------------//
                    update_SCORE();


                    //--------------------------------------------------------------------//
                    //                           PLAY HIT PCM                             //
                    //--------------------------------------------------------------------//
                    XGM_startPlayPCM(SOUND_PIE_HIT,13,SOUND_PCM_CH3);
                }


                //--------------------------------------------------------------------//
                //                                                                    //
                //                        IF GUEST IS CROUCHING                       //
                //                          PIE HITS THE WALL                         //
                //                                                                    //
                //--------------------------------------------------------------------//
                else
                {
                    //--------------------------------------------------------------------//
                    //                  WE LOAD WALL PIE TILES FOR BG_B                   //
                    //--------------------------------------------------------------------//
                    VDP_loadTileSet(list_WALL_PIES_LEFT_BG_B[i].ptr_IMAGE->tileset, list_WALL_PIES_LEFT_BG_B[i].vram_ADRESS, DMA_QUEUE);

                    //--------------------------------------------------------------------//
                    //                  WE LOAD WALL PIE TILES FOR BG_A                   //
                    //--------------------------------------------------------------------//
                    VDP_loadTileSet(list_WALL_PIES_LEFT_BG_A[i].ptr_IMAGE->tileset, list_WALL_PIES_LEFT_BG_A[i].vram_ADRESS, DMA_QUEUE);


                    //--------------------------------------------------------------------//
                    //                           PLAY WALL PCM                            //
                    //--------------------------------------------------------------------//
                    XGM_startPlayPCM(SOUND_PIE_WALL,13,SOUND_PCM_CH3);
                }


                G_USED_PIES += 1;


                //--------------------------------------------------------------------//
                //                                                                    //
                //                    IF ALL PIES HAVE BEEN SERVED                    //
                //                          SEQUENCE IS OVER                          //
                //                                                                    //
                //--------------------------------------------------------------------//
                if(G_USED_PIES == G_MAX_PIES)
                {
                    G_PHASE_SEQUENCE = WAITER_PHASE_GAME_OVER;
                }
            }



            //--------------------------------------------------------------------//
            //                                                                    //
            //                 IF PIE IS FOLLOWING ITS TRAJECTORY                 //
            //                                                                    //
            //--------------------------------------------------------------------//
            else
            {
                //------------------------------------------------------//
                //            SET POINTER TO PIE ANIM TABLE             //
                //------------------------------------------------------//
                const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                if(i == WAITER_LARRY)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_LARRY[list_WAITERS[WAITER_LARRY].index_ANIM_PIE];
                }

                else if(i == WAITER_CURLY)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_CURLY[list_WAITERS[WAITER_CURLY].index_ANIM_PIE];
                }

                else if(i == WAITER_MOE)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MOE[list_WAITERS[WAITER_MOE].index_ANIM_PIE];
                }

                //------------------------------------------------------//
                //          SET PIE POSITION AND SPRITE FRAME           //
                //------------------------------------------------------//
                SPR_setPosition(list_WAITERS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);

                if(ptr_PIE_ANIM->index_ANIM_PIE != 99)
                {
                    SPR_setFrame(list_WAITERS[i].spr_PIE , ptr_PIE_ANIM->index_ANIM_PIE);
                }
            }
        }
    }
}




inline static void anim_GUESTS()
{
    u8 i;

    for(i=0 ; i<3 ; i++)
    {
        // IF GUEST HAS BEEN HIT BY A PIE (STEP 1) //
        if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_HIT_1)
        {
            if(list_GUESTS[i].counter_CHARACTER == 63)
            {
                // RESET COUNTER //
                list_GUESTS[i].counter_CHARACTER = 0;

                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_HIT_2;
                
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , CHAR_PHASE_HIT_2);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , CHAR_PHASE_HIT_2);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == 1)
                {
                    VDP_loadTileSet(image_MAN1_7_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }

                return;
            }

            list_GUESTS[i].counter_CHARACTER += 1;
        }


        // IF GUEST HAS BEEN HIT BY A PIE (STEP 2) //
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_HIT_2)
        {
            if(list_GUESTS[i].counter_CHARACTER == 21)
            {
                // RESET COUNTER //
                list_GUESTS[i].counter_CHARACTER = 0;

                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_HIT_3;

                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , CHAR_PHASE_HIT_3);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , CHAR_PHASE_HIT_3);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == 1)
                {
                    VDP_loadTileSet(image_MAN1_8_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }

                return;
            }

            list_GUESTS[i].counter_CHARACTER += 1;
        }


        // IF GUEST HAS BEEN HIT BY A PIE (STEP 3) //
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_HIT_3)
        {
            if(list_GUESTS[i].counter_CHARACTER == 20)
            {
                // RESET COUNTER //
                list_GUESTS[i].counter_CHARACTER = 0;

                // RANDOMLY CHOOSE NEXT STATE (TO BE DONE) //
                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_IDLE;

                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , CHAR_PHASE_IDLE);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , CHAR_PHASE_IDLE);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == 1)
                {
                    VDP_loadTileSet(image_MAN1_1_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }

                return;
            }

            list_GUESTS[i].counter_CHARACTER += 1;
        }
    }
}




inline static void anim_WAITERS()
{
    u8 i;

    for(i=0 ; i<3 ; i++)
    {
        //--------------------------------------------------------//
        //                                                        //
        //                    STOOGE GRAB PHASE                   //
        //                                                        //
        //--------------------------------------------------------//
        if(list_WAITERS[i].state_CHARACTER == CHAR_PHASE_GRAB)
        {
            if(list_WAITERS[i].counter_CHARACTER == 6)
            {
                //------------------------------------------------------//
                //                 STOOGE GOES AIM PHASE                //
                //------------------------------------------------------//
                list_WAITERS[i].state_CHARACTER = CHAR_PHASE_AIM;

                //------------------------------------------------------//
                //              UPDATE STOOGE SPRITE FRAME              //
                //------------------------------------------------------//
                SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , list_WAITERS[i].state_CHARACTER);
                SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , list_WAITERS[i].state_CHARACTER);

                //------------------------------------------------------//
                //                 RESET STOOGE COUNTER                 //
                //------------------------------------------------------//
                list_WAITERS[i].counter_CHARACTER = 0;




                //------------------------------------------------------//
                //                  INCREASE PIE INDEX                  //
                //------------------------------------------------------//
                list_WAITERS[i].index_ANIM_PIE += 1;


                //------------------------------------------------------//
                //            SET POINTER TO PIE ANIM TABLE             //
                //------------------------------------------------------//
                const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                if(G_SELECTED_WAITER == WAITER_LARRY)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_LARRY[list_WAITERS[WAITER_LARRY].index_ANIM_PIE];
                }

                else if(G_SELECTED_WAITER == WAITER_CURLY)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_CURLY[list_WAITERS[WAITER_CURLY].index_ANIM_PIE];
                }

                else if(G_SELECTED_WAITER == WAITER_MOE)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MOE[list_WAITERS[WAITER_MOE].index_ANIM_PIE];
                }




                //------------------------------------------------------//
                //          SET PIE POSITION AND SPRITE FRAME           //
                //------------------------------------------------------//
                SPR_setPosition(list_WAITERS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);
                SPR_setFrame(list_WAITERS[i].spr_PIE , ptr_PIE_ANIM->index_ANIM_PIE);

                return;
            }

            list_WAITERS[i].counter_CHARACTER += 1;
        }




        //--------------------------------------------------------//
        //                                                        //
        //                    STOOGE AIM PHASE                    //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_WAITERS[i].state_CHARACTER == CHAR_PHASE_AIM)
        {
            if(list_WAITERS[i].counter_CHARACTER == 7)
            {
                //------------------------------------------------------//
                //                STOOGE GOES THROW PHASE               //
                //------------------------------------------------------//
                list_WAITERS[i].state_CHARACTER = CHAR_PHASE_THROW;

                //------------------------------------------------------//
                //              UPDATE STOOGE SPRITE FRAME              //
                //------------------------------------------------------//
                SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , list_WAITERS[i].state_CHARACTER);
                SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , list_WAITERS[i].state_CHARACTER);

                //------------------------------------------------------//
                //                 RESET STOOGE COUNTER                 //
                //------------------------------------------------------//
                list_WAITERS[i].counter_CHARACTER = 0;




                //------------------------------------------------------//
                //                  INCREASE PIE INDEX                  //
                //------------------------------------------------------//
                list_WAITERS[i].index_ANIM_PIE += 1;


                //------------------------------------------------------//
                //            SET POINTER TO PIE ANIM TABLE             //
                //------------------------------------------------------//
                const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                if(G_SELECTED_WAITER == WAITER_LARRY)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_LARRY[list_WAITERS[WAITER_LARRY].index_ANIM_PIE];
                }

                else if(G_SELECTED_WAITER == WAITER_CURLY)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_CURLY[list_WAITERS[WAITER_CURLY].index_ANIM_PIE];
                }

                else if(G_SELECTED_WAITER == WAITER_MOE)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MOE[list_WAITERS[WAITER_MOE].index_ANIM_PIE];
                }




                //------------------------------------------------------//
                //          SET PIE POSITION AND SPRITE FRAME           //
                //------------------------------------------------------//
                SPR_setPosition(list_WAITERS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);
                SPR_setFrame(list_WAITERS[i].spr_PIE , ptr_PIE_ANIM->index_ANIM_PIE);

                return;
            }

            list_WAITERS[i].counter_CHARACTER += 1;
        }




        //--------------------------------------------------------//
        //                                                        //
        //                   STOOGE THROW PHASE                   //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_WAITERS[i].state_CHARACTER == CHAR_PHASE_THROW)
        {
            //------------------------------------------------------//
            //                 PIE GOES THROW PHASE                 //
            //------------------------------------------------------//
            list_WAITERS[i].state_PIE = PIE_PHASE_THROW;
            

            //------------------------------------------------------//
            //              UPDATE STOOGE SPRITE FRAME              //
            //------------------------------------------------------//
            if(list_WAITERS[i].counter_CHARACTER == 7)
            {
                //------------------------------------------------------//
                //                     STOOGE STANDS                    //
                //------------------------------------------------------//
                SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , 0);
                SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , 0);
            }

            else if(list_WAITERS[i].counter_CHARACTER == 14)
            {
                //------------------------------------------------------//
                //                    STOOGE CROUCHES                   //
                //------------------------------------------------------//
                SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , 1);
                SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , 1);

                list_WAITERS[i].counter_CHARACTER = 0;

                list_WAITERS[i].state_CHARACTER = CHAR_PHASE_CROUCH_2;

                return;
            }


            list_WAITERS[i].counter_CHARACTER += 1;
        }




        //--------------------------------------------------------//
        //                                                        //
        //                  STOOGE CROUCH 2 PHASE                 //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_WAITERS[i].state_CHARACTER == CHAR_PHASE_CROUCH_2)
        {
            if(list_WAITERS[i].counter_CHARACTER == 14)
            {
                //------------------------------------------------------//
                //                      STOOGE IDLE                     //
                //------------------------------------------------------//
                list_WAITERS[i].counter_CHARACTER = 0;

                list_WAITERS[i].state_CHARACTER = CHAR_PHASE_IDLE;

                return;
            }


            list_WAITERS[i].counter_CHARACTER += 1;
        }
    }
}











void sequence_WAITERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == WAITER_PHASE_DIALOG)
    {
        if(G_COUNTER_1 == 60)
        {
            // DISPLAY DIALOG LEFT//
            VDP_setTileMapEx(BG_A, image_WAITERS_MINIGAME_DIALOG.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 55), 0, 9, 0, 0, 13, 7, DMA_QUEUE);

            // WE WANT OUR PIE... //
            VDP_setTileMapEx(BG_A, image_WAITERS_TEXT.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 27), 1, 10, 0, 5, 11, 4, DMA_QUEUE);
        }

        else if(G_COUNTER_1 == 240)
        {
            // ERASE DIALOG LEFT //
            VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 9, 0, 9, 13, 7, DMA_QUEUE);

            // DISPLAY DIALOG RIGHT //
            VDP_setTileMapEx(BG_A, image_WAITERS_MINIGAME_DIALOG.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 55), 25, 9, 13, 0, 15, 7, DMA_QUEUE);

            // YOU HEARD'EM //
            VDP_setTileMapEx(BG_A, image_WAITERS_TEXT.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 27), 26, 10, 0, 10, 13, 4, DMA_QUEUE);
        }

        else if(G_COUNTER_1 == 420)
        {
            // ERASE DIALOG RIGHT //
            VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 25, 9, 25, 9, 15, 7, DMA_QUEUE);

            // DISPLAY HAND //
            SPR_setPosition(sprite_HAND_WAITERS,270,108);

            //SPR_setFrame(list_WAITERS[1].spr_CHAR_1,1);
            //SPR_setFrame(list_WAITERS[1].spr_CHAR_2,1);

            G_PHASE_SEQUENCE = WAITER_PHASE_ACTION;

            G_COUNTER_1 = 0;

            return;
        }


        G_COUNTER_1 += 1;
    }


    else if(G_PHASE_SEQUENCE == WAITER_PHASE_ACTION)
    {
        check_WAITER_ACTION_AUTHORISATION();
        
        anim_PIE();
        
        anim_WAITERS();

        anim_GUESTS();
    }


    else if(G_PHASE_SEQUENCE == WAITER_PHASE_GAME_OVER)
    {
        if(G_COUNTER_1 == 180)
        {
            // IF ALL PIES HAVE BEEN USED //
            // REWARD IS DOUBLED //
            if(G_USED_PIES == G_MAX_PIES)
            {
                G_REWARD =  G_REWARD << 1;
            }
            
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

            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_REWARD;
            G_SCENE_NEXT    = SCENE_REWARD;

            G_SCENE_LOADED  = FALSE;

            return;
        }


        G_COUNTER_1 += 1;
    }
}











