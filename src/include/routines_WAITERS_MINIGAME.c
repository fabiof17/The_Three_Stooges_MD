#include <genesis.h>



#include "custom_tools.h"
#include "structures.h"
#include "variables.h"


#include "maps_WAITERS.h"


#include "tables_SLAP.h"
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
                // IF CURLY IS IDLE //
                if(list_WAITERS[1].state_CHARACTER == CHAR_PHASE_IDLE)
                {
                    SPR_setFrame(list_WAITERS[1].spr_CHAR_1,1);
                    SPR_setFrame(list_WAITERS[1].spr_CHAR_2,1);

                    SPR_setPosition(sprite_HAND_WAITERS,270,108);

                    // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                    VDP_loadTileSet(image_CURLY1_2_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);

                    
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
            }


            //--------------------------------------------------------------//
            //                                                              //
            //                          BUTTON UP                           //
            //                                                              //
            //--------------------------------------------------------------//

            // MOE CROUCHES //
            else if(value & BUTTON_UP)
            {
                if(list_WAITERS[2].state_CHARACTER == CHAR_PHASE_IDLE)
                {
                    SPR_setFrame(list_WAITERS[2].spr_CHAR_1,1);
                    SPR_setFrame(list_WAITERS[2].spr_CHAR_2,1);

                    SPR_setPosition(sprite_HAND_WAITERS,254,104);
                    
                    list_WAITERS[2].state_CHARACTER = CHAR_PHASE_CROUCH;

                    G_SELECTED_WAITER = WAITER_MOE;




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


                        // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                        VDP_loadTileSet(image_CURLY1_1_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);

                        
                        list_WAITERS[1].state_CHARACTER = CHAR_PHASE_IDLE; 
                    }

                }
            }


            //--------------------------------------------------------------//
            //                                                              //
            //                         BUTTON DOWN                          //
            //                                                              //
            //--------------------------------------------------------------//

            // LARRY CROUCHES //
            else if(value & BUTTON_DOWN)
            {
                // IF LARRY IS IDLE //
                if(list_WAITERS[0].state_CHARACTER == CHAR_PHASE_IDLE)
                {
                    SPR_setFrame(list_WAITERS[0].spr_CHAR_1,1);
                    SPR_setFrame(list_WAITERS[0].spr_CHAR_2,1);

                    SPR_setPosition(sprite_HAND_WAITERS,286,112);
                    
                    list_WAITERS[0].state_CHARACTER = CHAR_PHASE_CROUCH;

                    G_SELECTED_WAITER = WAITER_LARRY;




                    // IF MOE IS CROUCHING //
                    // NO NEED TO CHECK FOR CURLY //
                    if(list_WAITERS[2].state_CHARACTER < CHAR_PHASE_GRAB)
                    {
                        SPR_setFrame(list_WAITERS[2].spr_CHAR_1,0);
                        SPR_setFrame(list_WAITERS[2].spr_CHAR_2,0);
                        
                        list_WAITERS[2].state_CHARACTER = CHAR_PHASE_IDLE;
                    }

                    // IF CURLY IS CROUCHING //
                    if(list_WAITERS[1].state_CHARACTER < CHAR_PHASE_GRAB)
                    {
                        SPR_setFrame(list_WAITERS[1].spr_CHAR_1,0);
                        SPR_setFrame(list_WAITERS[1].spr_CHAR_2,0);


                        // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                        VDP_loadTileSet(image_CURLY1_1_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);


                        list_WAITERS[1].state_CHARACTER = CHAR_PHASE_IDLE; 
                    }
                }
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
            G_COUNTER_ACTION_WAITERS = 0;

            G_ACTION_WAITER_AUTHORIZED = TRUE;

            return;
        }
        
        G_COUNTER_ACTION_WAITERS += 1;
    }

}


inline static void AI_GUESTS()
{
    u8 i;

    for(i=0 ; i<3 ; i++)
    {
        //********************************************************************//
        //                                                                    //
        //                          IF GUEST IS IDLE                          //
        //                                                                    //
        //********************************************************************//
        //--------------------------------------------------------------------//
        //              GUEST CAN :                                           //
        //              - IDLE                                                //
        //              - CROUCH                                              //
        //--------------------------------------------------------------------//
        if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_IDLE)
        {      
            //--------------------------------------------------------------------//
            //                   INCREASE GUEST COUNTER ACTION                    //
            //--------------------------------------------------------------------//            
            list_GUESTS[i].counter_ACTION += 1;
            

            if(list_GUESTS[i].counter_ACTION == GUEST_ACTION_DELAY)
            {
                //--------------------------------------------------------------------//
                //                       RANDOM NEW GUEST STATE                       //
                //--------------------------------------------------------------------//                
                u8 random_STATE = random_NUMBER(0,19);
                u8 guest_STATE  = TABLE_PROBABILITY_IDLE_CROUCH[random_STATE];

                //--------------------------------------------------------------------//
                //                        SET NEW GUEST STATE                         //
                //--------------------------------------------------------------------// 
                list_GUESTS[i].state_CHARACTER = guest_STATE;


                //--------------------------------------------------------------------//
                //                     UPDATE GUEST SPRITE FRAME                      //
                //--------------------------------------------------------------------//  
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1,guest_STATE);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2,guest_STATE);


                //--------------------------------------------------------------------//
                //              !!!  TRICK TO AVOID SPRITE LIMIT  !!! //              //
                //--------------------------------------------------------------------//
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(TABLE_TILES_MAN_1[guest_STATE]->tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }


                //--------------------------------------------------------------------//
                //                     RESET GUEST COUNTER ACTION                     //
                //--------------------------------------------------------------------// 
                list_GUESTS[i].counter_ACTION = 0;
            }
        }


        //--------------------------------------------------------------------//
        //                                                                    //
        //                        IF GUEST IS CROUCHING                       //
        //                                                                    //
        //--------------------------------------------------------------------//
        //--------------------------------------------------------------------//
        //              GUEST CAN :                                           //
        //              - IDLE                                                //
        //              - CROUCH                                              //
        //              - GRAB A PIE                                          //
        //--------------------------------------------------------------------//
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_CROUCH)
        {      
            //--------------------------------------------------------------------//
            //                   INCREASE GUEST COUNTER ACTION                    //
            //--------------------------------------------------------------------//             
            list_GUESTS[i].counter_ACTION += 1;


            if(list_GUESTS[i].counter_ACTION == GUEST_ACTION_DELAY)
            {
                //--------------------------------------------------------------------//
                //                    IF SHOOTING A PIE IS ALLOWED                    //
                //--------------------------------------------------------------------//
                if(G_GUEST_SHOT_AUTHORIZED == TRUE)
                {
                    //--------------------------------------------------------------------//
                    //                    IF PIE IS SERVED ON THE TABLE                   //
                    //--------------------------------------------------------------------//
                    //--------------------------------------------------------------------//
                    //              GUEST CAN :                                           //
                    //              - IDLE                                                //
                    //              - CROUCH                                              //
                    //              - GRAB A PIE                                          //
                    //--------------------------------------------------------------------//
                    if(list_GUESTS[i].state_PIE == PIE_PHASE_SERVED)
                    {
                        //--------------------------------------------------------------------//
                        //                       RANDOM NEW GUEST STATE                       //
                        //--------------------------------------------------------------------//                  
                        u8 random_STATE = random_NUMBER(0,19);
                        u8 guest_STATE  = TABLE_PROBABILITY_IDLE_CROUCH_GRAB[random_STATE];


                        //--------------------------------------------------------------------//
                        //                        SET NEW GUEST STATE                         //
                        //--------------------------------------------------------------------// 
                        list_GUESTS[i].state_CHARACTER = guest_STATE;


                        //--------------------------------------------------------------------//
                        //                     UPDATE GUEST SPRITE FRAME                      //
                        //--------------------------------------------------------------------//   
                        SPR_setFrame(list_GUESTS[i].spr_CHAR_1,guest_STATE);
                        SPR_setFrame(list_GUESTS[i].spr_CHAR_2,guest_STATE);


                        //--------------------------------------------------------------------//
                        //              !!!  TRICK TO AVOID SPRITE LIMIT  !!! //              //
                        //--------------------------------------------------------------------//
                        if(i == GUEST_MAN_1)
                        {
                            VDP_loadTileSet(TABLE_TILES_MAN_1[guest_STATE]->tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                        }


                        //\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///
                        //                                                                    //
                        //                           MANAGE GUEST PIE                         //
                        //                                                                    //
                        //\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///
                        //--------------------------------------------------------------------//
                        //                        IF GUEST GRABS A PIE                        //
                        //--------------------------------------------------------------------// 
                        if(guest_STATE == CHAR_PHASE_GRAB)
                        {
                            list_GUESTS[i].index_ANIM_PIE = 1;

                            //------------------------------------------------------//
                            //            SET POINTER TO PIE ANIM TABLE             //
                            //------------------------------------------------------//
                            const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                            if(i == GUEST_WOMAN)
                            {
                                ptr_PIE_ANIM = &TABLE_PIE_ANIM_WOMAN[list_GUESTS[GUEST_WOMAN].index_ANIM_PIE];
                            }

                            else if(i == GUEST_MAN_1)
                            {
                                ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_1[list_GUESTS[GUEST_MAN_1].index_ANIM_PIE];
                            }

                            else if(i == GUEST_MAN_2)
                            {
                                ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_2[list_GUESTS[GUEST_MAN_2].index_ANIM_PIE];
                            }


                            //--------------------------------------------------------------------//
                            //               SET GUEST PIE POSITION AND SPRITE FRAME              //
                            //--------------------------------------------------------------------//
                            SPR_setPosition(list_GUESTS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);
                        }
                    }


                    //--------------------------------------------------------------------//
                    //                  IF PIE IS NOT SERVED ON THE TABLE                 //
                    //--------------------------------------------------------------------//
                    //--------------------------------------------------------------------//
                    //              GUEST CAN :                                           //
                    //              - IDLE                                                //
                    //              - CROUCH                                              //
                    //--------------------------------------------------------------------//
                    else
                    {
                        //--------------------------------------------------------------------//
                        //                       RANDOM NEW GUEST STATE                       //
                        //--------------------------------------------------------------------//                 
                        u8 random_STATE = random_NUMBER(0,19);
                        u8 guest_STATE  = TABLE_PROBABILITY_IDLE_CROUCH[random_STATE];


                        //--------------------------------------------------------------------//
                        //                        SET NEW GUEST STATE                         //
                        //--------------------------------------------------------------------// 
                        list_GUESTS[i].state_CHARACTER = guest_STATE;


                        //--------------------------------------------------------------------//
                        //                     UPDATE GUEST SPRITE FRAME                      //
                        //--------------------------------------------------------------------//   
                        SPR_setFrame(list_GUESTS[i].spr_CHAR_1,guest_STATE);
                        SPR_setFrame(list_GUESTS[i].spr_CHAR_2,guest_STATE);


                        //--------------------------------------------------------------------//
                        //              !!!  TRICK TO AVOID SPRITE LIMIT  !!! //              //
                        //--------------------------------------------------------------------//
                        if(i == GUEST_MAN_1)
                        {
                            VDP_loadTileSet(TABLE_TILES_MAN_1[guest_STATE]->tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                        }
                    }
                }


                //--------------------------------------------------------------------//
                //                  IF SHOOTING A PIE IS NOT ALLOWED                  //
                //--------------------------------------------------------------------//
                //--------------------------------------------------------------------//
                //              GUEST CAN :                                           //
                //              - IDLE                                                //
                //              - CROUCH                                              //
                //--------------------------------------------------------------------//
                else
                {
                    //--------------------------------------------------------------------//
                    //                       RANDOM NEW GUEST STATE                       //
                    //--------------------------------------------------------------------//                
                    u8 random_STATE = random_NUMBER(0,19);
                    u8 guest_STATE  = TABLE_PROBABILITY_IDLE_CROUCH[random_STATE];


                    //--------------------------------------------------------------------//
                    //                        SET NEW GUEST STATE                         //
                    //--------------------------------------------------------------------// 
                    list_GUESTS[i].state_CHARACTER = guest_STATE;


                    //--------------------------------------------------------------------//
                    //                     UPDATE GUEST SPRITE FRAME                      //
                    //--------------------------------------------------------------------//  
                    SPR_setFrame(list_GUESTS[i].spr_CHAR_1,guest_STATE);
                    SPR_setFrame(list_GUESTS[i].spr_CHAR_2,guest_STATE);


                    //--------------------------------------------------------------------//
                    //              !!!  TRICK TO AVOID SPRITE LIMIT  !!! //              //
                    //--------------------------------------------------------------------//
                    if(i == GUEST_MAN_1)
                    {
                        VDP_loadTileSet(TABLE_TILES_MAN_1[guest_STATE]->tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                    }
                }


                //--------------------------------------------------------------------//
                //                     RESET GUEST COUNTER ACTION                     //
                //--------------------------------------------------------------------// 
                list_GUESTS[i].counter_ACTION = 0;
            }
        }
    }
}








inline static void anim_PIE_WAITERS()
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


            //********************************************************************//
            //********************************************************************//
            //                               CASE 1                               //
            //********************************************************************//
            //********************************************************************//

            //********************************************************************//
            //                                                                    //
            //               IF PIE REACHED THE END OF ITS TRAJECTORY             //
            //                                                                    //
            //********************************************************************//
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
                if(list_GUESTS[i].state_CHARACTER != CHAR_PHASE_CROUCH && list_GUESTS[i].state_CHARACTER != CHAR_PHASE_CROUCH_2)
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




            //********************************************************************//
            //********************************************************************//
            //                               CASE 2                               //
            //********************************************************************//
            //********************************************************************//

            //********************************************************************//
            //                                                                    //
            //                   IF PIE IS FOLLOWING ITS TRAJECTORY               //
            //                                                                    //
            //********************************************************************//
            else
            {
                //------------------------------------------------------//
                //            SET POINTER TO PIE ANIM TABLE             //
                //------------------------------------------------------//
                const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                if(i == WAITER_LARRY)
                {
                    if(list_GUESTS[i].pie_DEVIATION == NO_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_LARRY[list_WAITERS[WAITER_LARRY].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == UP_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_LARRY_UP[list_GUESTS[WAITER_LARRY].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == DOWN_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_LARRY_DOWN[list_GUESTS[WAITER_LARRY].index_ANIM_PIE];
                    }
                }

                else if(i == WAITER_CURLY)
                {
                    if(list_GUESTS[i].pie_DEVIATION == NO_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_CURLY[list_WAITERS[WAITER_CURLY].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == UP_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_CURLY_UP[list_GUESTS[WAITER_CURLY].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == DOWN_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_CURLY_DOWN[list_GUESTS[WAITER_CURLY].index_ANIM_PIE];
                    }
                }

                else if(i == WAITER_MOE)
                {
                    if(list_GUESTS[i].pie_DEVIATION == NO_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MOE[list_WAITERS[WAITER_MOE].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == UP_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MOE_UP[list_GUESTS[WAITER_MOE].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == DOWN_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MOE_DOWN[list_GUESTS[WAITER_MOE].index_ANIM_PIE];
                    }
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


inline static void anim_PIE_GUESTS()
{
    u8 i;

    for(i=0 ; i<3 ; i++)
    {
        if(list_GUESTS[i].state_PIE == PIE_PHASE_THROW)
        {
            //--------------------------------------------------------------------//
            //                      INCREASE PIE ANIM INDEX                       //
            //--------------------------------------------------------------------//
            list_GUESTS[i].index_ANIM_PIE += 1;


            //********************************************************************//
            //********************************************************************//
            //                               CASE 1                               //
            //********************************************************************//
            //********************************************************************//

            //********************************************************************//
            //                                                                    //
            //                  IF GUEST PIE REACHED COLLISON STEP                //
            //                                                                    //
            //********************************************************************//
            if(list_GUESTS[i].index_ANIM_PIE == 18)
            {
                //********************************************************************//
                //                                                                    //
                //                  IF WAITER PIE REACHED COLLISON STEP               //
                //                                                                    //
                //********************************************************************//
                if(list_WAITERS[i].index_ANIM_PIE == 23)
                {
                    u8 random_COLLISION = random_NUMBER(0,19);

                    // 0 = NO_DEVIATION
                    // 1 = UP_DEVIATION
                    // 2 = DOWN_DEVIATION
                    u8 deviation_ID = TABLE_PROBABILITY_PIE_COLLISION[random_COLLISION];

                    list_GUESTS[i].pie_DEVIATION = deviation_ID;

                    // IF GUEST PIE IS DEVIATED UPWARD   //
                    // WAITER PIE IS DEVIATED DOWNWARD   //
                    if(deviation_ID == UP_DEVIATION)
                    {
                        list_WAITERS[i].pie_DEVIATION = DOWN_DEVIATION;
                    }

                    // IF GUEST PIE IS DEVIATED DOWNWARD //
                    // WAITER PIE IS DEVIATED UPWARD     //
                    else if(deviation_ID == DOWN_DEVIATION)
                    {
                        list_WAITERS[i].pie_DEVIATION = UP_DEVIATION;
                    }
                }
            }





            //********************************************************************//
            //********************************************************************//
            //                               CASE 2                               //
            //********************************************************************//
            //********************************************************************//

            //********************************************************************//
            //                                                                    //
            //               IF PIE REACHED THE END OF ITS TRAJECTORY             //
            //                                                                    //
            //********************************************************************//
            else if(list_GUESTS[i].index_ANIM_PIE == 58)
            {
                //********************************************************************//
                //********************************************************************//
                //                           COLLISION CHECK                          //
                //********************************************************************//
                //********************************************************************//

                //********************************************************************//
                //                                                                    //
                //                      IF WAITER IS NOT CROUCHING                    //
                //                                                                    //
                //********************************************************************//
                if(list_WAITERS[i].state_CHARACTER != CHAR_PHASE_CROUCH && list_WAITERS[i].state_CHARACTER != CHAR_PHASE_CROUCH_2)
                {
                    //--------------------------------------------------------------------//
                    //                    IF GUEST PIE IS NOT DEVIATED                    //
                    //--------------------------------------------------------------------//
                    if(list_GUESTS[i].pie_DEVIATION == NO_DEVIATION)
                    {
                        list_WAITERS[i].counter_CHARACTER = 0;

                        //--------------------------------------------------------------------//
                        //                        WAITER GOES TO PHASE                        //
                        //--------------------------------------------------------------------//
                        list_WAITERS[i].state_CHARACTER = CHAR_PHASE_HIT_1;

                        SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , CHAR_PHASE_HIT_1);
                        SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , CHAR_PHASE_HIT_1);




                        //--------------------------------------------------------------------//
                        //                         UPDATE BULB SPRITE                         //
                        //--------------------------------------------------------------------//

                        G_HIT_NUMBER += 1;

                        SPR_setFrame(sprite_BULB[G_HIT_NUMBER -1],1);
                        SPR_setPalette(sprite_BULB[G_HIT_NUMBER -1],PAL3);




                        //********************************************************************//
                        //                                                                    //
                        //                           CHECK HIT NUMBER                         //
                        //                                                                    //
                        //********************************************************************//

                        //--------------------------------------------------------------------//
                        //                                                                    //
                        //                  IF WAITERS HAVE BEEN HIT 5 TIMES                  //
                        //                          SEQUENCE IS OVER                          //
                        //                                                                    //
                        //--------------------------------------------------------------------//
                        if(G_HIT_NUMBER == 5)
                        {
                            G_PHASE_SEQUENCE = WAITER_PHASE_GAME_OVER;
                        }


                        //--------------------------------------------------------------------//
                        //                                                                    //
                        //                IF WAITERS HAVE NOT BEEN HIT 5 TIMES                //
                        //                                                                    //
                        //--------------------------------------------------------------------//
                        else
                        {
                            //--------------------------------------------------------------------//
                            //                      RESET WAITER PIE COUNTER                      //
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
                            //                A NEW PIE IS SERVED ON WAITERS TABLE                //
                            //--------------------------------------------------------------------//
                            list_WAITERS[i].state_PIE     = PIE_PHASE_SERVED;

                            list_WAITERS[i].pie_DEVIATION = NO_DEVIATION;

                            SPR_setPosition(list_WAITERS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);
                            SPR_setFrame(list_WAITERS[i].spr_PIE , 0);
                        }

                        //--------------------------------------------------------------------//
                        //                           PLAY HIT PCM                             //
                        //--------------------------------------------------------------------//
                        XGM_startPlayPCM(SOUND_PIE_HIT,13,SOUND_PCM_CH3);
                    }
                }


                //********************************************************************//
                //                                                                    //
                //                         WAITER IS CROUCHING                        //
                //                          PIE HITS THE WALL                         //
                //                                                                    //
                //********************************************************************//
                else
                {
                    //--------------------------------------------------------------------//
                    //                                                                    //
                    //                      IF PIE IS NOT DEVIATED                        //
                    //                                                                    //
                    //--------------------------------------------------------------------//
                    if(list_GUESTS[i].pie_DEVIATION == NO_DEVIATION)
                    {
                        //--------------------------------------------------------------------//
                        //                  WE LOAD WALL PIE TILES FOR BG_B                   //
                        //--------------------------------------------------------------------//
                        VDP_loadTileSet(list_WALL_PIES_RIGHT_BG_B[i].ptr_IMAGE->tileset, list_WALL_PIES_RIGHT_BG_B[i].vram_ADRESS, DMA_QUEUE);

                        //--------------------------------------------------------------------//
                        //                  WE LOAD WALL PIE TILES FOR BG_A                   //
                        //--------------------------------------------------------------------//
                        VDP_loadTileSet(list_WALL_PIES_RIGHT_BG_A[i].ptr_IMAGE->tileset, list_WALL_PIES_RIGHT_BG_A[i].vram_ADRESS, DMA_QUEUE);
                    }


                    //--------------------------------------------------------------------//
                    //                                                                    //
                    //                     IF PIE IS DEVIATED UPWARD                      //
                    //                                                                    //
                    //--------------------------------------------------------------------//
                    else if(list_GUESTS[i].pie_DEVIATION == UP_DEVIATION)
                    {
                        //--------------------------------------------------------------------//
                        //                  WE LOAD WALL PIE TILES FOR BG_B                   //
                        //--------------------------------------------------------------------//
                        VDP_loadTileSet(list_WALL_PIES_UP_RIGHT_BG_B[i].ptr_IMAGE->tileset, list_WALL_PIES_UP_RIGHT_BG_B[i].vram_ADRESS, DMA_QUEUE);

                        //--------------------------------------------------------------------//
                        //                  WE LOAD WALL PIE TILES FOR BG_A                   //
                        //--------------------------------------------------------------------//
                        VDP_loadTileSet(list_WALL_PIES_UP_RIGHT_BG_A[i].ptr_IMAGE->tileset, list_WALL_PIES_UP_RIGHT_BG_A[i].vram_ADRESS, DMA_QUEUE);
                    }


                    //--------------------------------------------------------------------//
                    //                                                                    //
                    //                    IF PIE IS DEVIATED DOWNWARD                     //
                    //                                                                    //
                    //--------------------------------------------------------------------//
                    else if(list_GUESTS[i].pie_DEVIATION == DOWN_DEVIATION)
                    {
                        //--------------------------------------------------------------------//
                        //                  WE LOAD WALL PIE TILES FOR BG_B                   //
                        //--------------------------------------------------------------------//
                        VDP_loadTileSet(list_WALL_PIES_DOWN_BG_B[i].ptr_IMAGE->tileset, list_WALL_PIES_DOWN_BG_B[i].vram_ADRESS, DMA_QUEUE);

                        //--------------------------------------------------------------------//
                        //                  WE LOAD WALL PIE TILES FOR BG_A                   //
                        //--------------------------------------------------------------------//
                        VDP_loadTileSet(list_WALL_PIES_DOWN_BG_B[i].ptr_IMAGE->tileset, list_WALL_PIES_DOWN_BG_B[i].vram_ADRESS, DMA_QUEUE);
                    }


                    //--------------------------------------------------------------------//
                    //                           PLAY WALL PCM                            //
                    //--------------------------------------------------------------------//
                    XGM_startPlayPCM(SOUND_PIE_WALL,13,SOUND_PCM_CH3);
                }




                //********************************************************************//
                //                                                                    //
                //                           RESET GUEST PIE                          //
                //                                                                    //
                //********************************************************************//

                //--------------------------------------------------------------------//
                //                      RESET GUEST PIE COUNTER                       //
                //--------------------------------------------------------------------//
                list_GUESTS[i].index_ANIM_PIE = 0;

                //--------------------------------------------------------------------//
                //                   SET POINTER TO PIE ANIM TABLE                    //
                //--------------------------------------------------------------------//
                const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                if(i == GUEST_WOMAN)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_WOMAN[list_GUESTS[GUEST_WOMAN].index_ANIM_PIE];
                }

                else if(i == GUEST_MAN_1)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_1[list_GUESTS[GUEST_MAN_1].index_ANIM_PIE];
                }

                else if(i == GUEST_MAN_2)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_2[list_GUESTS[GUEST_MAN_2].index_ANIM_PIE];
                }


                //--------------------------------------------------------------------//
                //                 A NEW PIE IS SERVED ON GUESTS TABLE                //
                //--------------------------------------------------------------------//
                list_GUESTS[i].state_PIE     = PIE_PHASE_SERVED;

                list_GUESTS[i].pie_DEVIATION = NO_DEVIATION;

                SPR_setPosition(list_GUESTS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);
                SPR_setFrame(list_GUESTS[i].spr_PIE , 0);

            }




            //********************************************************************//
            //********************************************************************//
            //                               CASE 3                               //
            //********************************************************************//
            //********************************************************************//

            //********************************************************************//
            //                                                                    //
            //                   IF PIE IS FOLLOWING ITS TRAJECTORY               //
            //                                                                    //
            //********************************************************************//
            else
            {
                //------------------------------------------------------//
                //            SET POINTER TO PIE ANIM TABLE             //
                //------------------------------------------------------//
                const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                if(i == GUEST_WOMAN)
                {
                    if(list_GUESTS[i].pie_DEVIATION == NO_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_WOMAN[list_GUESTS[GUEST_WOMAN].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == UP_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_WOMAN_UP[list_GUESTS[GUEST_WOMAN].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == DOWN_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_WOMAN_DOWN[list_GUESTS[GUEST_WOMAN].index_ANIM_PIE];
                    }
                }

                else if(i == GUEST_MAN_1)
                {
                    if(list_GUESTS[i].pie_DEVIATION == NO_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_1[list_GUESTS[GUEST_MAN_1].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == UP_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_1_UP[list_GUESTS[GUEST_MAN_1].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == DOWN_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_1_DOWN[list_GUESTS[GUEST_MAN_1].index_ANIM_PIE];
                    }
                }

                else if(i == GUEST_MAN_2)
                {
                    if(list_GUESTS[i].pie_DEVIATION == NO_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_2[list_GUESTS[GUEST_MAN_2].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == UP_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_2_UP[list_GUESTS[GUEST_MAN_2].index_ANIM_PIE];
                    }

                    else if(list_GUESTS[i].pie_DEVIATION == DOWN_DEVIATION)
                    {
                        ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_2_DOWN[list_GUESTS[GUEST_MAN_2].index_ANIM_PIE];
                    }
                }


                //--------------------------------------------------------------------//
                //               SET GUEST PIE POSITION AND SPRITE FRAME              //
                //--------------------------------------------------------------------//
                SPR_setPosition(list_GUESTS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);

                if(ptr_PIE_ANIM->index_ANIM_PIE != 99)
                {
                    SPR_setFrame(list_GUESTS[i].spr_PIE , ptr_PIE_ANIM->index_ANIM_PIE);
                }
            }
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

                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == WAITER_CURLY)
                {
                    VDP_loadTileSet(image_CURLY1_4_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);
                }




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


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == WAITER_CURLY)
                {
                    VDP_loadTileSet(image_CURLY1_5_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);
                }




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

                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == WAITER_CURLY)
                {
                    VDP_loadTileSet(image_CURLY1_1_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);
                }
            }

            else if(list_WAITERS[i].counter_CHARACTER == 14)
            {
                //------------------------------------------------------//
                //                    STOOGE CROUCHES                   //
                //------------------------------------------------------//
                SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , 1);
                SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , 1);

                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == WAITER_CURLY)
                {
                    VDP_loadTileSet(image_CURLY1_2_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);
                }

                list_WAITERS[i].counter_CHARACTER = 0;

                list_WAITERS[i].state_CHARACTER = CHAR_PHASE_CROUCH_2;

                return;
            }


            list_WAITERS[i].counter_CHARACTER += 1;
        }


        //--------------------------------------------------------//
        //                                                        //
        //                   STOOGE HIT PHASE 1                   //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_WAITERS[i].state_CHARACTER == CHAR_PHASE_HIT_1)
        {
            if(list_WAITERS[i].counter_CHARACTER == 63)
            {
                // RESET COUNTER //
                list_WAITERS[i].counter_CHARACTER = 0;

                list_WAITERS[i].state_CHARACTER = CHAR_PHASE_HIT_2;
                
                SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , CHAR_PHASE_HIT_2);
                SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , CHAR_PHASE_HIT_2);

                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == WAITER_CURLY)
                {
                    VDP_loadTileSet(image_CURLY1_7_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);
                }

                return;
            }

            list_WAITERS[i].counter_CHARACTER += 1;
        }


        //--------------------------------------------------------//
        //                                                        //
        //                   STOOGE HIT PHASE 2                   //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_WAITERS[i].state_CHARACTER == CHAR_PHASE_HIT_2)
        {
            if(list_WAITERS[i].counter_CHARACTER == 21)
            {
                // RESET COUNTER //
                list_WAITERS[i].counter_CHARACTER = 0;

                list_WAITERS[i].state_CHARACTER = CHAR_PHASE_HIT_3;

                SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , CHAR_PHASE_HIT_3);
                SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , CHAR_PHASE_HIT_3);

                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == WAITER_CURLY)
                {
                    VDP_loadTileSet(image_CURLY1_8_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);
                }

                return;
            }

            list_WAITERS[i].counter_CHARACTER += 1;
        }


        //--------------------------------------------------------//
        //                                                        //
        //                   STOOGE HIT PHASE 3                   //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_WAITERS[i].state_CHARACTER == CHAR_PHASE_HIT_3)
        {
            if(list_WAITERS[i].counter_CHARACTER == 20)
            {
                // RESET COUNTER //
                list_WAITERS[i].counter_CHARACTER = 0;

                // RANDOMLY CHOOSE NEXT STATE (TO BE DONE) //
                list_WAITERS[i].state_CHARACTER = CHAR_PHASE_IDLE;

                SPR_setFrame(list_WAITERS[i].spr_CHAR_1 , CHAR_PHASE_IDLE);
                SPR_setFrame(list_WAITERS[i].spr_CHAR_2 , CHAR_PHASE_IDLE);

                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == WAITER_CURLY)
                {
                    VDP_loadTileSet(image_CURLY1_1_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);
                }

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


inline static void anim_GUESTS()
{
    u8 i;

    for(i=0 ; i<3 ; i++)
    {
        if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_GRAB)
        {
            //------------------------------------------------------//
            //                 INCREASE GUEST COUNTER               //
            //------------------------------------------------------//            
            list_GUESTS[i].counter_CHARACTER += 1;
            
            
            if(list_GUESTS[i].counter_CHARACTER == 9)
            {
                //------------------------------------------------------//
                //                  RESET GUEST COUNTER                 //
                //------------------------------------------------------//
                list_GUESTS[i].counter_CHARACTER = 0;

                //------------------------------------------------------//
                //                  GUEST GOES AIM PHASE                //
                //------------------------------------------------------//
                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_AIM;

                //------------------------------------------------------//
                //               UPDATE GUEST SPRITE FRAME              //
                //------------------------------------------------------//
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , list_GUESTS[i].state_CHARACTER);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , list_GUESTS[i].state_CHARACTER);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(image_MAN1_4_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }




                //------------------------------------------------------//
                //                  SET GUEST PIE INDEX                 //
                //------------------------------------------------------//
                list_GUESTS[i].index_ANIM_PIE = 2;

                //------------------------------------------------------//
                //            SET POINTER TO PIE ANIM TABLE             //
                //------------------------------------------------------//
                const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                if(i == GUEST_WOMAN)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_WOMAN[list_GUESTS[GUEST_WOMAN].index_ANIM_PIE];
                }

                else if(i == GUEST_MAN_1)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_1[list_GUESTS[GUEST_MAN_1].index_ANIM_PIE];
                }

                else if(i == GUEST_MAN_2)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_2[list_GUESTS[GUEST_MAN_2].index_ANIM_PIE];
                }




                //--------------------------------------------------------------------//
                //               SET GUEST PIE POSITION AND SPRITE FRAME              //
                //--------------------------------------------------------------------//
                SPR_setPosition(list_GUESTS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);
                SPR_setFrame(list_GUESTS[i].spr_PIE , 1);


                //--------------------------------------------------------------------//
                //                 SHHOTING A PIE IS AUTHORIZED AGAIN                 //
                //--------------------------------------------------------------------//
                G_GUEST_SHOT_AUTHORIZED = TRUE;
            }
        }


        //--------------------------------------------------------//
        //                                                        //
        //                    GUEST AIM PHASE                     //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_AIM)
        {
            list_GUESTS[i].counter_CHARACTER += 1;


            if(list_GUESTS[i].counter_CHARACTER == 9)
            {
                //------------------------------------------------------//
                //                 RESET GUEST COUNTER                  //
                //------------------------------------------------------//
                list_GUESTS[i].counter_CHARACTER = 0;

                //------------------------------------------------------//
                //                GUEST GOES THROW PHASE                //
                //------------------------------------------------------//
                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_THROW;

                //------------------------------------------------------//
                //              UPDATE GUEST SPRITE FRAME               //
                //------------------------------------------------------//
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , list_GUESTS[i].state_CHARACTER);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , list_GUESTS[i].state_CHARACTER);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(image_MAN1_5_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }




                //------------------------------------------------------//
                //                 PIE GOES THROW PHASE                 //
                //------------------------------------------------------//
                list_GUESTS[i].state_PIE = PIE_PHASE_THROW;

                //------------------------------------------------------//
                //                  INCREASE PIE INDEX                  //
                //------------------------------------------------------//
                list_GUESTS[i].index_ANIM_PIE = 3;

                //------------------------------------------------------//
                //            SET POINTER TO PIE ANIM TABLE             //
                //------------------------------------------------------//
                const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                if(i == GUEST_WOMAN)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_WOMAN[list_GUESTS[GUEST_WOMAN].index_ANIM_PIE];
                }

                else if(i == GUEST_MAN_1)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_1[list_GUESTS[GUEST_MAN_1].index_ANIM_PIE];
                }

                else if(i == GUEST_MAN_2)
                {
                    ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_2[list_GUESTS[GUEST_MAN_2].index_ANIM_PIE];
                }




                //--------------------------------------------------------------------//
                //               SET GUEST PIE POSITION AND SPRITE FRAME              //
                //--------------------------------------------------------------------//
                SPR_setPosition(list_GUESTS[i].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);
                SPR_setFrame(list_GUESTS[i].spr_PIE , 2);


                //return;
            }

            //list_GUESTS[i].counter_CHARACTER += 1;
        }


        //--------------------------------------------------------//
        //                                                        //
        //                   GUEST THROW PHASE                    //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_THROW)
        {
            list_GUESTS[i].counter_CHARACTER += 1;

                
            if(list_GUESTS[i].counter_CHARACTER == 9)
            {
                //------------------------------------------------------//
                //              UPDATE GUEST SPRITE FRAME               //
                //------------------------------------------------------//
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , 0);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , 0);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(image_MAN1_1_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }
            }


            else if(list_GUESTS[i].counter_CHARACTER == 16)
            {
                //------------------------------------------------------//
                //                 RESET GUEST COUNTER                  //
                //------------------------------------------------------//
                list_GUESTS[i].counter_CHARACTER = 0;

                //------------------------------------------------------//
                //               GUEST GOES CROUCH 2 PHASE              //
                //------------------------------------------------------//
                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_CROUCH_2;

                //------------------------------------------------------//
                //              UPDATE GUEST SPRITE FRAME               //
                //------------------------------------------------------//
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , 1);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , 1);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(image_MAN1_2_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }
            }
        }


        //--------------------------------------------------------//
        //                                                        //
        //                   GUEST HIT PHASE 1                    //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_HIT_1)
        {
            list_GUESTS[i].counter_CHARACTER += 1;
            
            if(list_GUESTS[i].counter_CHARACTER == 64)
            {
                //------------------------------------------------------//
                //                 RESET GUEST COUNTER                  //
                //------------------------------------------------------//
                list_GUESTS[i].counter_CHARACTER = 0;

                //------------------------------------------------------//
                //                GUEST GOES HIT PHASE 2                //
                //------------------------------------------------------//
                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_HIT_2;


                //------------------------------------------------------//
                //              UPDATE GUEST SPRITE FRAME               //
                //------------------------------------------------------//
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , CHAR_PHASE_HIT_2);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , CHAR_PHASE_HIT_2);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(image_MAN1_7_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }

                //return;
            }

            //list_GUESTS[i].counter_CHARACTER += 1;
        }


        //--------------------------------------------------------//
        //                                                        //
        //                   GUEST HIT PHASE 2                    //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_HIT_2)
        {
            list_GUESTS[i].counter_CHARACTER += 1;
            
            if(list_GUESTS[i].counter_CHARACTER == 22)
            {
                //------------------------------------------------------//
                //                 RESET GUEST COUNTER                  //
                //------------------------------------------------------//
                list_GUESTS[i].counter_CHARACTER = 0;

                //------------------------------------------------------//
                //                GUEST GOES HIT PHASE 3                //
                //------------------------------------------------------//
                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_HIT_3;


                //------------------------------------------------------//
                //              UPDATE GUEST SPRITE FRAME               //
                //------------------------------------------------------//
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , CHAR_PHASE_HIT_3);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , CHAR_PHASE_HIT_3);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(image_MAN1_8_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }

                //return;
            }

            //list_GUESTS[i].counter_CHARACTER += 1;
        }


        //--------------------------------------------------------//
        //                                                        //
        //                   GUEST HIT PHASE 3                    //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_HIT_3)
        {
            
            list_GUESTS[i].counter_CHARACTER += 1;
            

            if(list_GUESTS[i].counter_CHARACTER == 21)
            {
                //------------------------------------------------------//
                //                 RESET GUEST COUNTER                  //
                //------------------------------------------------------//
                list_GUESTS[i].counter_CHARACTER = 0;

                // RANDOMLY CHOOSE NEXT STATE (TO BE DONE) //
                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_IDLE;

                //------------------------------------------------------//
                //              UPDATE GUEST SPRITE FRAME               //
                //------------------------------------------------------//
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , CHAR_PHASE_IDLE);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , CHAR_PHASE_IDLE);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(image_MAN1_1_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }


                //--------------------------------------------------------------------//
                //                     RESET GUEST COUNTER ACTION                     //
                //--------------------------------------------------------------------// 
                list_GUESTS[i].counter_ACTION = 0;
            }
        }


        //--------------------------------------------------------//
        //                                                        //
        //                  GUEST CROUCH 2 PHASE                  //
        //                                                        //
        //--------------------------------------------------------//
        else if(list_GUESTS[i].state_CHARACTER == CHAR_PHASE_CROUCH_2)
        {
            list_GUESTS[i].counter_CHARACTER += 1;
            
            
            if(list_GUESTS[i].counter_CHARACTER == 15)
            {
                //------------------------------------------------------//
                //                 RESET GUEST COUNTER                  //
                //------------------------------------------------------//
                list_GUESTS[i].counter_CHARACTER = 0;


                list_GUESTS[i].state_CHARACTER = CHAR_PHASE_IDLE;

                //------------------------------------------------------//
                //              UPDATE GUEST SPRITE FRAME               //
                //------------------------------------------------------//
                SPR_setFrame(list_GUESTS[i].spr_CHAR_1 , CHAR_PHASE_IDLE);
                SPR_setFrame(list_GUESTS[i].spr_CHAR_2 , CHAR_PHASE_IDLE);


                // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                if(i == GUEST_MAN_1)
                {
                    VDP_loadTileSet(image_MAN1_1_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);
                }


                //--------------------------------------------------------------------//
                //                     RESET GUEST COUNTER ACTION                     //
                //--------------------------------------------------------------------// 
                list_GUESTS[i].counter_ACTION = 0;
            }
        }
    }
}








void sequence_WAITERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == WAITER_PHASE_DIALOG)
    {
        if(G_COUNTER_1 == 60)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                ERASE DIALOG BOX LEFT                                 //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_setTileMapEx(BG_A, image_WAITERS_MINIGAME_DIALOG.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 55), 0, 9, 0, 0, 13, 7, DMA_QUEUE);

            // WE WANT OUR PIE... //
            VDP_setTileMapEx(BG_A, image_WAITERS_TEXT.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 27), 1, 10, 0, 5, 11, 4, DMA_QUEUE);
        }

        else if(G_COUNTER_1 == 240)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                ERASE DIALOG BOX LEFT                                 //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 9, 0, 9, 13, 7, DMA_QUEUE);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         LEFT                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_setTileMapEx(BG_A, image_PIE_WALL2_0_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_LEFT_2), 5, 14, 0, 0, 2, 2, DMA_QUEUE);
            
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       TOP LEFT                                       //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_setTileMapEx(BG_A, image_PIE_WALL0_0_UP_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_LEFT_0), 0,  7, 0, 0, 2, 5, DMA_QUEUE);

            VDP_setTileMapEx(BG_A, image_PIE_WALL1_0_UP_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_LEFT_1), 3, 10, 0, 0, 2, 5, DMA_QUEUE);

            VDP_setTileMapEx(BG_A, image_PIE_WALL2_0_UP_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_LEFT_2), 5,  9, 0, 0, 2, 5, DMA_QUEUE);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                ERASE DIALOG BOX RIGHT                                //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_setTileMapEx(BG_A, image_WAITERS_MINIGAME_DIALOG.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 55), 25, 9, 13, 0, 15, 7, DMA_QUEUE);

            // YOU HEARD'EM //
            VDP_setTileMapEx(BG_A, image_WAITERS_TEXT.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 27), 26, 10, 0, 10, 13, 4, DMA_QUEUE);
        }

        else if(G_COUNTER_1 == 420)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                ERASE DIALOG BOX RIGHT                                //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 25, 9, 25, 9, 15, 7, DMA_QUEUE);

            
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                        RIGHT                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_setTileMapEx(BG_A, image_PIE_WALL2_0_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_RIGHT_2), 33, 14, 0, 0, 2, 2, DMA_QUEUE);

            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                      TOP RIGHT                                       //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_setTileMapEx(BG_A, image_PIE_WALL0_0_UP_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_0), 38,  8, 0, 0, 2, 5, DMA_QUEUE);

            VDP_setTileMapEx(BG_A, image_PIE_WALL1_0_UP_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_1), 36, 10, 0, 0, 2, 5, DMA_QUEUE);

            VDP_setTileMapEx(BG_A, image_PIE_WALL2_0_UP_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_2), 33,  9, 0, 0, 2, 5, DMA_QUEUE);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                     DISPLAY HAND                                     //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            SPR_setPosition(sprite_HAND_WAITERS,270,108);




            //--------------------------------------------------------------------------------------//
            //                                         MAN 1                                        //
            //--------------------------------------------------------------------------------------//
            list_GUESTS[1].state_CHARACTER   =   CHAR_PHASE_CROUCH;
            SPR_setFrame(list_GUESTS[1].spr_CHAR_1,1);
            SPR_setFrame(list_GUESTS[1].spr_CHAR_2,1);

            // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
            VDP_loadTileSet(image_MAN1_2_WAITERS.tileset, G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile, DMA_QUEUE);

            //--------------------------------------------------------------------------------------//
            //                                         MAN 2                                        //
            //--------------------------------------------------------------------------------------//
            list_GUESTS[2].state_CHARACTER   =   CHAR_PHASE_GRAB;
            SPR_setFrame(list_GUESTS[2].spr_CHAR_1,2);
            SPR_setFrame(list_GUESTS[2].spr_CHAR_2,2);


            // INCREASE PIE ANIM INDEX //
            list_GUESTS[2].index_ANIM_PIE    =   1;


            // SETUP POINTER TO PIE ANIMATION TABLE //
            const struct_PIE_ANIM_ *ptr_PIE_ANIM = &TABLE_PIE_ANIM_MAN_2[list_GUESTS[2].index_ANIM_PIE];
            SPR_setPosition(list_GUESTS[2].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);




            G_GUEST_SHOT_AUTHORIZED   = FALSE;

            G_PHASE_SEQUENCE          = WAITER_PHASE_ACTION;

            G_COUNTER_1               = 0;

            return;
        }


        G_COUNTER_1 += 1;
    }


    else if(G_PHASE_SEQUENCE == WAITER_PHASE_ACTION)
    {
        AI_GUESTS();
        
        check_WAITER_ACTION_AUTHORISATION();
        
        anim_PIE_WAITERS();
        anim_PIE_GUESTS();
        
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











