#include <genesis.h>


#include "outils.h"
#include "structures.h"
#include "variables.h"




#include "tables_ROULETTE.h"
#include "tables_QUESTIONS.h"




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
                //
            }

            // BOUTON C //
            if( changed & state & BUTTON_C )
            {
                if((value & BUTTON_DIR) == SLAP_MOE_STATE_IDLE)
                {
                    if(G_AXIS == LEFT)
                    {
                        G_AXIS = RIGHT;
                        SPR_setHFlip(sprite_MOE,G_AXIS);
                    }

                    else
                    {
                        G_AXIS = LEFT;
                        SPR_setHFlip(sprite_MOE,G_AXIS);
                    }
                }
            }
        }
    }
}










