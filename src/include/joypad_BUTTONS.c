#include <genesis.h>


#include "custom_tools.h"
#include "structures.h"
#include "variables.h"


#include "maps_WAITERS.h"


#include "tables_CRACKERS.h"
#include "tables_QUESTIONS.h"
#include "tables_ROULETTE.h"
#include "tables_SLAP.h"
#include "tables_WAITERS.h"




void intro_Callback(u16 joy, u16 changed, u16 state)
{
    if(joy == JOY_1)
    {
        if(G_SCENE != SCENE_INTRO_EXIT && G_SCENE != SCENE_FADE_IN && G_SCENE != SCENE_FADE_OUT)
        {
            // BOUTON B //
            if( changed & state & BUTTON_START )
            {
                G_SCENE = SCENE_INTRO_EXIT;
            }
        }
    }
}




void roulette_Callback(u16 joy, u16 changed, u16 state)
{
    if(joy == JOY_1)
    {
        // BOUTON B //
        if( changed & state & BUTTON_B )
        {
            if(G_PHASE_SEQUENCE == ROULETTE_PHASE_CHOICE)
            {
                // REINIT COUNTER //
                G_COUNTER_ROULETTE = 0;

                // GET SELECTED ICON ID //
                G_SELECTED_ICON_ID = TABLE_GENERATED_ICONS[TABLE_GENERATED_HAND_POSITION[G_CURRENT_TURN]];
                
                // ICON SELECTED //
                G_PHASE_SEQUENCE = ROULETTE_PHASE_VALIDATED;

                return ;
            }
        }
    }
}




void trivia_Callback(u16 joy, u16 changed, u16 state)
{
    u16 value=JOY_readJoypad(JOY_1);
    
    if(joy == JOY_1)
    {
        // BOUTON B //
        if( changed & state & BUTTON_B )
        {
            if(G_PHASE_SEQUENCE == TRIVIA_PHASE_CHOICE)
            {
                if(value & BUTTON_LEFT)
                {
                    G_SELECTED_ANSWER = 0;

                    if(G_SELECTED_ANSWER == TABLE_QUESTIONS[G_SELECTED_QUESTION].answer)
                    {
                        G_STATUS_MISSION = SUCCESS;
                    }

                    else
                    {
                        G_STATUS_MISSION = FAILED;
                    }

                    SPR_setFrame(sprite_STOOGES,25);
                    
                    SPR_setPosition(sprite_ANSWER_A,-48,-48);
                    SPR_setPosition(sprite_ANSWER_B,-48,-48);
                    SPR_setPosition(sprite_ANSWER_C,-48,-48);

                    G_PHASE_SEQUENCE = TRIVIA_PHASE_RESULT;
                }
            
                else if(value & BUTTON_UP)
                {
                    G_SELECTED_ANSWER = 1;

                    if(G_SELECTED_ANSWER == TABLE_QUESTIONS[G_SELECTED_QUESTION].answer)
                    {
                        G_STATUS_MISSION = SUCCESS;
                    }

                    else
                    {
                        G_STATUS_MISSION = FAILED;
                    }

                    SPR_setFrame(sprite_STOOGES,25);
                    
                    SPR_setPosition(sprite_ANSWER_A,-48,-48);
                    SPR_setPosition(sprite_ANSWER_B,-48,-48);
                    SPR_setPosition(sprite_ANSWER_C,-48,-48);

                    G_PHASE_SEQUENCE = TRIVIA_PHASE_RESULT;
                }

                else if(value & BUTTON_RIGHT)
                {
                    G_SELECTED_ANSWER = 2;

                    if(G_SELECTED_ANSWER == TABLE_QUESTIONS[G_SELECTED_QUESTION].answer)
                    {
                        G_STATUS_MISSION = SUCCESS;
                    }

                    else
                    {
                        G_STATUS_MISSION = FAILED;
                    }

                    SPR_setFrame(sprite_STOOGES,25);
                    
                    SPR_setPosition(sprite_ANSWER_A,-48,-48);
                    SPR_setPosition(sprite_ANSWER_B,-48,-48);
                    SPR_setPosition(sprite_ANSWER_C,-48,-48);

                    G_PHASE_SEQUENCE = TRIVIA_PHASE_RESULT;
                }
            }
        }
    }
}




void slap_Callback(u16 joy, u16 changed, u16 state)
{
    u16 value=JOY_readJoypad(JOY_1);
    
    if(joy == JOY_1)
    {
        if(G_PHASE_SEQUENCE == SLAP_PHASE_ATTACK)
        {
            // BOUTON B //
            if( changed & state & BUTTON_B )
            {
                // IF MOE ATTACKS (NOT IN IDLE STATE) //
                if(G_CURRENT_STATE != SLAP_STATE_IDLE)
                {
                    SPR_setAnimAndFrame(sprite_MOE, 1, G_CURRENT_STATE);
                    
                    // COMPUTE THE PROBABILITY OF SUCCESS //
                    u8 hit_probability = abs(G_CURRENT_STATE - G_PREVIOUS_STATE);

                    //KLog_U1("probability :" , hit_probability);

                    // GENERATE RANDOM NUMBER //
                    u8 hit_number = random_NUMBER(0,19);

                    // GET HIT RESULT //
                    bool result = TABLE_PROBABILITY_SLAP_ATTACK[hit_probability][hit_number];


                    // MISS //
                    if(result == 0)
                    {
                        if(G_POS_X_METER_SLAP < 80)
                        {
                            G_POS_X_METER_SLAP += 4;

                            G_HAND_SPEED -= 1;
                        }
                        
                        u8 random_miss_pcm = random_NUMBER(70,73);

                        XGM_startPlayPCM(random_miss_pcm,15,SOUND_PCM_CH4);
                    }

                    // HIT //
                    else
                    {
                        if(G_POS_X_METER_SLAP > -80)
                        {
                            G_POS_X_METER_SLAP -= 4;

                            G_HAND_SPEED += 1;
                        }
                        
                        u8 attack_pcm = G_CURRENT_STATE;

                        XGM_startPlayPCM(TABLE_ID_PCM_SLAP_HIT[attack_pcm],15,SOUND_PCM_CH4);

                    }

                    // MOVE METER SPRITE //
                    SPR_setPosition(sprite_METER_SLAP , G_POS_X_METER_SLAP , 55);


                    if(G_AXIS == LEFT)
                    {
                        SPR_setAnimAndFrame(sprite_LARRY, 1 + result, G_CURRENT_STATE);
                    }

                    else if(G_AXIS == RIGHT)
                    {
                        SPR_setAnimAndFrame(sprite_CURLY, 1 + result, G_CURRENT_STATE);
                    }

                    G_PHASE_SEQUENCE = SLAP_PHASE_RESULT_ATTACK;
                }

                G_COUNTER_WAIT = 0;
            }

            // BOUTON C //
            else if( changed & state & BUTTON_C )
            {
                if((value & BUTTON_DIR) == 0)
                {
                    if(G_AXIS == LEFT)
                    {
                        G_AXIS = RIGHT;
                        SPR_setHFlip(sprite_MOE,G_AXIS);
                        SPR_setPosition(sprite_MOE,132,133);
                    }

                    else
                    {
                        G_AXIS = LEFT;
                        SPR_setHFlip(sprite_MOE,G_AXIS);
                        SPR_setPosition(sprite_MOE,131,133);
                    }
                }

                G_COUNTER_WAIT = 0;
            }  
        }
    }
}




void crackers_Callback(u16 joy, u16 changed, u16 state)
{    
    if(joy == JOY_1)
    {
        if(G_PHASE_SEQUENCE == CRACKER_SPOON_MOVE)
        {
            // BOUTON B //
            if( changed & state & BUTTON_B )
            {
                SPR_setPosition(sprite_HAND[0] ,G_POS_X_PLAYER + 9 , G_POS_Y_PLAYER + 16);
                SPR_setPosition(sprite_HAND[1] ,G_POS_X_PLAYER - 7 , G_POS_Y_PLAYER + 68);

                G_SPOON_FRAME = 1;

                SPR_setFrame(sprite_HAND[0],G_SPOON_FRAME);
                SPR_setFrame(sprite_HAND[1],G_SPOON_FRAME);
                SPR_setFrame(sprite_HAND[2],G_SPOON_FRAME);




                u8 i;

                for(i=0 ; i<14 ; i++)
                {
                    if(list_CRACKER[i].state_CRACKER < 6)
                    {
                        u16 distance_X = abs( (list_CRACKER[i].pos_X + 28) - (G_POS_X_PLAYER + 24) );
                        u16 distance_Y = abs( (list_CRACKER[i].pos_Y + 20) - (G_POS_Y_PLAYER + 16) );
                        
                        if(distance_X < 16)
                        {
                            if(distance_Y < 16)
                            {
                                list_CRACKER[i].animated = FALSE;

                                //------------------------------------------------------------------//
                                //          PROBABILITY TO HAVE SPOON TRAPPED BY THE OYSTER         //
                                //------------------------------------------------------------------//
                                u8 random_trapped = random_NUMBER(0,9);


                                //------------------------------------------------------------------//
                                //                                                                  //
                                //              IF SPOON IS NOT TRAPPED BY THE OYSTER               //
                                //                                                                  //
                                //------------------------------------------------------------------//
                                if(TABLE_PROBABILITY_SPOON_TRAPPED[random_trapped] == FALSE)
                                {
                                    //------------------------------------------------------------------//
                                    //                    CRACKER GOES GRABBED STATE                    //
                                    //------------------------------------------------------------------//
                                    list_CRACKER[i].state_CRACKER = CRACKER_PHASE_GRABBED;
                                    
                                    //------------------------------------------------------------------//
                                    //                       SET CRACKER POSITION                       //
                                    //------------------------------------------------------------------//
                                    list_CRACKER[i].pos_X = G_POS_X_PLAYER - 11;
                                    list_CRACKER[i].pos_Y = G_POS_Y_PLAYER - 8;
                                    SPR_setPosition(list_CRACKER[i].spr_CRACKER , list_CRACKER[i].pos_X , list_CRACKER[i].pos_Y);

                                    //------------------------------------------------------------------//
                                    //                     SET CRACKER SPRITE FRAME                     //
                                    //------------------------------------------------------------------//
                                    SPR_setFrame(list_CRACKER[i].spr_CRACKER,0);


                                    //------------------------------------------------------------------//
                                    //                ONE MORE CRACKER HAS BEEN GRABBED                 //
                                    //------------------------------------------------------------------//
                                    G_NUMBER_GRABBED_CRACKERS += 1;

                                    //------------------------------------------------------------------//
                                    //                10 DOLLARS REWARD FOR THE CRACKER                 //
                                    //------------------------------------------------------------------//                                    
                                    G_REWARD += 10;

                                    //------------------------------------------------------------------//
                                    //               GO TO CRACKER SPOON GRABBED SEQUENCE               //
                                    //------------------------------------------------------------------//   
                                    G_PHASE_SEQUENCE = CRACKER_SPOON_GRAB;

                                    //------------------------------------------------------------------//
                                    //                     START CASH REGISTER SOUND                    //
                                    //------------------------------------------------------------------//
                                    XGM_startPlayPCM(SOUND_MONEY,14,SOUND_PCM_CH2);
                                }


                                //------------------------------------------------------------------//
                                //                                                                  //
                                //                IF SPOON IS TRAPPED BY THE OYSTER                 //
                                //                                                                  //
                                //------------------------------------------------------------------//
                                else
                                {
                                    //------------------------------------------------------------------//
                                    //                    CRACKER GOES TRAPPED STATE                    //
                                    //------------------------------------------------------------------//
                                    list_CRACKER[i].state_CRACKER = CRACKER_PHASE_TRAPPED;

                                    //------------------------------------------------------------------//
                                    //                       SET CRACKER POSITION                       //
                                    //------------------------------------------------------------------//
                                    list_CRACKER[i].pos_X = G_POS_X_PLAYER - 11;
                                    list_CRACKER[i].pos_Y = G_POS_Y_PLAYER + 4;

                                    SPR_setPosition(list_CRACKER[i].spr_CRACKER , list_CRACKER[i].pos_X , list_CRACKER[i].pos_Y);

                                    //------------------------------------------------------------------//
                                    //                     SET CRACKER SPRITE FRAME                     //
                                    //------------------------------------------------------------------//
                                    SPR_setFrame(list_CRACKER[i].spr_CRACKER,7);

                                    //------------------------------------------------------------------//
                                    //                GO TO CRACKER SPOON TRAPPED SEQUENCE              //
                                    //------------------------------------------------------------------// 
                                    G_PHASE_SEQUENCE = CRACKER_SPOON_TRAPPED;
                                }

                                
                                
                                //------------------------------------------------------------------//
                                //                   CRACKER GOES ON TOP OF SPOON                   //
                                //------------------------------------------------------------------// 
                                SPR_setDepth(list_CRACKER[i].spr_CRACKER,0);

                                //------------------------------------------------------------------//
                                //                  CRACKERS NUMBER DECREASED BY 1                  //
                                //------------------------------------------------------------------// 
                                G_NUMBER_CRACKERS -= 1;

                                //------------------------------------------------------------------//
                                //                      CRACKER GETS SELECTED                       //
                                //------------------------------------------------------------------// 
                                G_SELECTED_CRACKER = i;

                                return;
                            }
                        }
                    }
                }


                G_PHASE_SEQUENCE = CRACKER_SPOON_MISS;  
            }
        }
    }
}




void waiters_Callback(u16 joy, u16 changed, u16 state)
{    
    if(joy == JOY_1)
    {
        if(G_PHASE_SEQUENCE == WAITER_PHASE_ACTION)
        {
            // BOUTON B //
            if( changed & state & BUTTON_B )
            {
                // IF STOOGE IS CROUCHING //
                if(list_WAITERS[G_SELECTED_WAITER].state_CHARACTER == CHAR_PHASE_CROUCH)
                {
                    // IF PIE IS SERVED ON THE TABLE //
                    if(list_WAITERS[G_SELECTED_WAITER].state_PIE == PIE_PHASE_SERVED)
                    {
                        // STOOGE GOES TO GRAB PHASE //
                        list_WAITERS[G_SELECTED_WAITER].state_CHARACTER = CHAR_PHASE_GRAB;
                        
                        // UPDATE STOOGES SPRITE FRAME //
                        SPR_setFrame(list_WAITERS[G_SELECTED_WAITER].spr_CHAR_1,2);
                        SPR_setFrame(list_WAITERS[G_SELECTED_WAITER].spr_CHAR_2,2);


                        // !!!  TRICK TO AVOID SPRITE LIMIT  !!! //
                        if(G_SELECTED_WAITER == WAITER_CURLY)
                        {
                            VDP_loadTileSet(image_CURLY1_3_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, DMA_QUEUE);
                        }



                        // INCREASE PIE ANIM INDEX //
                        list_WAITERS[G_SELECTED_WAITER].index_ANIM_PIE += 1;

                        // SETUP POINTER TO PIE ANIMATION TABLE
                        const struct_PIE_ANIM_ *ptr_PIE_ANIM;

                        // DEPENDING ON WHICH STOOGE IS SELECTED //
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



                        // MOVE PIE SPRITE TO ITS NEW POSITION //
                        SPR_setPosition(list_WAITERS[G_SELECTED_WAITER].spr_PIE , ptr_PIE_ANIM->pos_X_PIE , ptr_PIE_ANIM->pos_Y_PIE);

                        // WAITER GOES TO GRAB PHASE //
                        list_WAITERS[G_SELECTED_WAITER].state_PIE = PIE_PHASE_GRAB;

                        // ANOTHER PIE CAN NOT BE THROWN IMMEDIATLY //
                        G_ACTION_WAITER_AUTHORIZED = FALSE;

                        // PLAY SOUND //
                        XGM_startPlayPCM(SOUND_PIE_THROW,14,SOUND_PCM_CH4);
                    }
                }
            }
        }
    }
}






