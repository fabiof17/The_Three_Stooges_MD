#include <genesis.h>


#include "outils.h"
#include "structures.h"
#include "variables.h"




#include "tables_QUESTIONS.h"
#include "tables_ROULETTE.h"
#include "tables_SLAP.h"




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

                //VDP_drawInt(TABLE_MINIGAMES[G_SELECTED_ICON_ID],1,0,0);

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

                    // GENERATE RANDOM NUMBER //
                    u8 hit_number = random_NUMBER(0,19);

                    // GET HIT RESULT //
                    bool result = TABLE_PROBABILITY_SLAP_ATTACK[hit_probability][hit_number];

                    // MISS //
                    if(result == 0)
                    {
                        G_POS_X_METER_SLAP += 4;
                    }

                    else
                    {
                        G_POS_X_METER_SLAP -= 4;
                    }

                    SPR_setPosition(sprite_METER_SLAP , G_POS_X_METER_SLAP , 55);

                    //VDP_drawIntEx_BG_B(G_CURRENT_STATE,1,0,28,PAL1);
                    //VDP_drawIntEx_BG_B(1+result,1,0,30,PAL1);

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
            }
        }
    }
}










