#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"

#include "maps_WAITERS.h"




void joypad_WAITERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == WAITER_PHASE_ACTION)
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
}




void sequence_WAITERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == WAITER_PHASE_DIALOG)
    {
        if(G_COUNTER_1 == 60)
        {
            // DIALOG LEFT//
            VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 9, 0, 28, 13, 7, DMA_QUEUE);

            // WE WANT OUR PIE... //
            VDP_setTileMapEx(BG_A, image_WAITERS_TEXT.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 33), 1, 10, 0, 5, 11, 4, DMA_QUEUE);
        }

        else if(G_COUNTER_1 == 240)
        {
            // ERASE DIALOG LEFT //
            VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 9, 0, 9, 13, 7, DMA_QUEUE);

            // DIALOG RIGHT //
            VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 25, 9, 13, 28, 15, 7, DMA_QUEUE);

            // YOU HEARD'EM //
            VDP_setTileMapEx(BG_A, image_WAITERS_TEXT.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 33), 26, 10, 0, 10, 13, 4, DMA_QUEUE);
        }

        else if(G_COUNTER_1 == 420)
        {
            // ERASE DIALOG RIGHT //
            VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 25, 9, 25, 9, 15, 7, DMA_QUEUE);

            // DISPLAY HAND //
            SPR_setPosition(sprite_HAND_WAITERS,270,108);

            SPR_setFrame(list_WAITERS[1].spr_CHAR_1,1);
            SPR_setFrame(list_WAITERS[1].spr_CHAR_2,1);

            G_PHASE_SEQUENCE = WAITER_PHASE_ACTION;
        }


        G_COUNTER_1 += 1;
    }

    else if(G_PHASE_SEQUENCE == WAITER_PHASE_ACTION)
    {
        //
    }
}











