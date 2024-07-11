#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"




void joypad_WAITERS_MINIGAME()
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
            if(G_SELECTED_WAITER != WAITER_CURLY)
            {

                // IF CURLY IS IDLE //
                if(list_WAITERS[1].state_CHARACTER == WAITER_PHASE_IDLE)
                {
                    SPR_setFrame(list_WAITERS[1].spr_CHAR_1,1);
                    SPR_setFrame(list_WAITERS[1].spr_CHAR_2,1);

                    SPR_setPosition(sprite_HAND_WAITERS,270,108);
                    
                    list_WAITERS[1].state_CHARACTER = WAITER_PHASE_CROUCH;

                    G_SELECTED_WAITER = WAITER_CURLY;
                }




                // IF LARRY IS CROUCHING //
                // NO NEED TO CHECK FOR MOE //
                if(list_WAITERS[0].state_CHARACTER == WAITER_PHASE_CROUCH)
                {
                    SPR_setFrame(list_WAITERS[0].spr_CHAR_1,0);
                    SPR_setFrame(list_WAITERS[0].spr_CHAR_2,0);
                    
                    list_WAITERS[0].state_CHARACTER = WAITER_PHASE_IDLE;

                    //return;
                }

                // IF MOE IS CROUCHING //
                if(list_WAITERS[2].state_CHARACTER == WAITER_PHASE_CROUCH)
                {
                    SPR_setFrame(list_WAITERS[2].spr_CHAR_1,0);
                    SPR_setFrame(list_WAITERS[2].spr_CHAR_2,0);
                    
                    list_WAITERS[2].state_CHARACTER = WAITER_PHASE_IDLE;
                }
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
           if(G_SELECTED_WAITER != WAITER_MOE)
            {
                // IF MOE IS IDLE //
                if(list_WAITERS[2].state_CHARACTER == WAITER_PHASE_IDLE)
                {
                    SPR_setFrame(list_WAITERS[2].spr_CHAR_1,1);
                    SPR_setFrame(list_WAITERS[2].spr_CHAR_2,1);

                    SPR_setPosition(sprite_HAND_WAITERS,254,104);
                    
                    list_WAITERS[2].state_CHARACTER = WAITER_PHASE_CROUCH;

                    G_SELECTED_WAITER = WAITER_MOE;
                }




                // IF LARRY IS CROUCHING //
                // NO NEED TO CHECK FOR CURLY //
                if(list_WAITERS[0].state_CHARACTER == WAITER_PHASE_CROUCH)
                {
                    SPR_setFrame(list_WAITERS[0].spr_CHAR_1,0);
                    SPR_setFrame(list_WAITERS[0].spr_CHAR_2,0);
                    
                    list_WAITERS[0].state_CHARACTER = WAITER_PHASE_IDLE;

                    //return;
                }

                // IF CURLY IS CROUCHING //
                if(list_WAITERS[1].state_CHARACTER == WAITER_PHASE_CROUCH)
                {
                    SPR_setFrame(list_WAITERS[1].spr_CHAR_1,0);
                    SPR_setFrame(list_WAITERS[1].spr_CHAR_2,0);
                    
                    list_WAITERS[1].state_CHARACTER = WAITER_PHASE_IDLE; 
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
           if(G_SELECTED_WAITER != WAITER_LARRY)
            {
                // IF LARRY IS IDLE //
                if(list_WAITERS[0].state_CHARACTER == WAITER_PHASE_IDLE)
                {
                    SPR_setFrame(list_WAITERS[0].spr_CHAR_1,1);
                    SPR_setFrame(list_WAITERS[0].spr_CHAR_2,1);

                    SPR_setPosition(sprite_HAND_WAITERS,286,112);
                    
                    list_WAITERS[0].state_CHARACTER = WAITER_PHASE_CROUCH;

                    G_SELECTED_WAITER = WAITER_LARRY;
                }




                // IF MOE IS CROUCHING //
                // NO NEED TO CHECK FOR CURLY //
                if(list_WAITERS[2].state_CHARACTER == WAITER_PHASE_CROUCH)
                {
                    SPR_setFrame(list_WAITERS[2].spr_CHAR_1,0);
                    SPR_setFrame(list_WAITERS[2].spr_CHAR_2,0);
                    
                    list_WAITERS[2].state_CHARACTER = WAITER_PHASE_IDLE;

                    //return;
                }

                // IF CURLY IS CROUCHING //
                if(list_WAITERS[1].state_CHARACTER == WAITER_PHASE_CROUCH)
                {
                    SPR_setFrame(list_WAITERS[1].spr_CHAR_1,0);
                    SPR_setFrame(list_WAITERS[1].spr_CHAR_2,0);
                    
                    list_WAITERS[1].state_CHARACTER = WAITER_PHASE_IDLE; 
                }
            }
        }
  
}
















