#include <genesis.h>



#include "custom_tools.h"
#include "structures.h"
#include "variables.h"




#include "maps_DOLLAR.h"
#include "maps_SLAP.h"
#include "maps_GLOBAL.h"




#include "routines_ROULETTE.h"




#include "sprites_SLAP.h"




#include "tables_SLAP.h"




void joypad_SLAP()
{
    u16 value=JOY_readJoypad(JOY_1);

    
    if(G_PHASE_SEQUENCE == SLAP_PHASE_ATTACK)
    {
        //--------------------------------------------------------------//
        //                                                              //
        //                       NO JOYPAD INPUT                        //
        //                                                              //
        //--------------------------------------------------------------//

        if((value & BUTTON_DIR) == 0)
        {
            SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_IDLE);

            if(G_AXIS == LEFT)
            {
                SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_IDLE);
            }

            else if(G_AXIS == RIGHT)
            {
                SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_IDLE);
            }

            G_PREVIOUS_STATE = G_CURRENT_STATE;
            G_CURRENT_STATE = SLAP_STATE_IDLE;
        }  

 


        //--------------------------------------------------------------//
        //                                                              //
        //                          BUTTON UP                           //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_UP)
        {
            if(value & BUTTON_LEFT)
            {
                if(G_AXIS == LEFT)
                {
                    SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_FRONT_UP);
                    SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_FRONT_UP);

                    G_PREVIOUS_STATE = G_CURRENT_STATE;
                    G_CURRENT_STATE = SLAP_STATE_FRONT_UP;
                }

                else
                {
                    SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_BACK_UP);
                    SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_BACK_UP);

                    G_PREVIOUS_STATE = G_CURRENT_STATE;
                    G_CURRENT_STATE = SLAP_STATE_BACK_UP;
                }
            }


            else if(value & BUTTON_RIGHT)
            {
                if(G_AXIS == RIGHT)
                {
                    SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_FRONT_UP);
                    SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_FRONT_UP);

                    G_PREVIOUS_STATE = G_CURRENT_STATE;
                    G_CURRENT_STATE = SLAP_STATE_FRONT_UP;
                }

                else
                {
                    SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_BACK_UP);
                    SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_BACK_UP);

                    G_PREVIOUS_STATE = G_CURRENT_STATE;
                    G_CURRENT_STATE = SLAP_STATE_BACK_UP;
                }
            }


            else
            {
                SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_UP);

                if(G_AXIS == LEFT)
                {
                    SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_UP);
                }

                else
                {
                    SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_UP);
                }

                G_PREVIOUS_STATE = G_CURRENT_STATE;
                G_CURRENT_STATE = SLAP_STATE_UP;
            }

            G_COUNTER_WAIT = 0;
        }




        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON DOWN                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_DOWN)
        {
            if(value & BUTTON_LEFT)
            {
                if(G_AXIS == LEFT)
                {
                    SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_FRONT_DOWN);
                    SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_FRONT_DOWN);

                    G_PREVIOUS_STATE = G_CURRENT_STATE;
                    G_CURRENT_STATE = SLAP_STATE_FRONT_DOWN;
                }
            }


            else if(value & BUTTON_RIGHT)
            {
                if(G_AXIS == RIGHT)
                {
                    SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_FRONT_DOWN);
                    SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_FRONT_DOWN);

                    G_PREVIOUS_STATE = G_CURRENT_STATE;
                    G_CURRENT_STATE = SLAP_STATE_FRONT_DOWN;
                }
            }


            else
            {
                SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_DOWN);

                G_PREVIOUS_STATE = G_CURRENT_STATE;
                G_CURRENT_STATE = SLAP_STATE_DOWN;

                if(G_AXIS == LEFT)
                {
                    SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_DOWN);
                }

                else if(G_AXIS == RIGHT)
                {
                    SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_DOWN);
                }
            }

            G_COUNTER_WAIT = 0;
        }




        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON LEFT                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_LEFT)
        {
            if(G_AXIS == LEFT)
            {
                SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_FRONT);
                SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_FRONT);

                G_PREVIOUS_STATE = G_CURRENT_STATE;
                G_CURRENT_STATE = SLAP_STATE_FRONT;
            }

            else if(G_AXIS == RIGHT)
            {
                SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_BACK);
                SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_BACK);

                G_PREVIOUS_STATE = G_CURRENT_STATE;
                G_CURRENT_STATE = SLAP_STATE_BACK;
            }

            G_COUNTER_WAIT = 0;
        }




        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON RIGHT                         //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_RIGHT)
        {
            if(G_AXIS == LEFT)
            {
                SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_BACK);
                SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_BACK);

                G_PREVIOUS_STATE = G_CURRENT_STATE;
                G_CURRENT_STATE = SLAP_STATE_BACK;
            }

            else if(G_AXIS == RIGHT)
            {
                SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_FRONT);
                SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_FRONT);

                G_PREVIOUS_STATE = G_CURRENT_STATE;
                G_CURRENT_STATE = SLAP_STATE_FRONT;
            }

            G_COUNTER_WAIT = 0;
        }
    }
}


inline static void counter_SLAP()
{
    if(G_COUNTER_SLAP == 20)
    {
        G_COUNTER_SLAP = 0;

        if(G_INDEX_2 > 0)
        {
            G_INDEX_2 -= 1;

            SPR_setAnim(sprite_COUNTER_SLAP,G_INDEX_2);

            return;
        }

        else
        {
            SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_IDLE);
            SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_IDLE);
            SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_IDLE);
            
            G_PHASE_SEQUENCE = SLAP_PHASE_OVER;

            return;
        }
    }

    G_COUNTER_SLAP += 1;
}


inline static void counter_WAIT()
{
    if(G_COUNTER_WAIT == 159)
    {
        if(G_POS_X_METER_SLAP < 80)
        {
            G_POS_X_METER_SLAP += 4;

            G_HAND_SPEED -= 1;
        }

        // MOVE METER SPRITE //
        SPR_setPosition(sprite_METER_SLAP , G_POS_X_METER_SLAP , 55);


        SPR_setAnimAndFrame(sprite_MOE, 2 , 0);


        if(G_AXIS == LEFT)
        {
            SPR_setAnimAndFrame(sprite_LARRY, 3, 0);
        }

        else if(G_AXIS == RIGHT)
        {
            SPR_setAnimAndFrame(sprite_CURLY, 3, 0);
        }

        G_COUNTER_WAIT = 0;

        G_PHASE_SEQUENCE = SLAP_PHASE_HIT;

        XGM_startPlayPCM(SOUND_SLAP_HIT,14,SOUND_PCM_CH3);

        return;
    }
    
    G_COUNTER_WAIT += 1;
}




void sequence_SLAP()
{
    if(G_PHASE_SEQUENCE == SLAP_PHASE_WALKIN)
    {
        // STOOGES ANIMATION //
        // SETUP POINTER TO STOOGES ANIMATION TABLE //
        const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_WALKIN_SLAP[G_INDEX_3];

        if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
        {
            // CHANGING SPRITE ANIMATION FRAME //
            SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

            // RETRIEVE X POSITION FROM TABLE //
            SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 133 );


            // UPDATE INDEX IN STOOGES ANIMATION TABLE //
            // UP TO 25 (LAST INDEX IN ARRAY OF 26 ENTRIES) //
            if(G_INDEX_3 < 25)
            {
                G_INDEX_3 += 1;
            }
        }



        if(G_COUNTER_1 == 616)
        {
            VDP_loadTileSet(image_SLAP_DIALOG_1.tileset, G_ADR_VRAM_DIALOG, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_SLAP_DIALOG_1.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 12, 34, 0, 0, 16, 7, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG,160,104);
        }

        else if(G_COUNTER_1 == 707)
        {
            VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, 0), 12, 34, 0, 0, 16, 7, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG,-24,-32);
        }

        else if(G_COUNTER_1 == 724)
        {
            VDP_loadTileSet(image_SLAP_DIALOG_2.tileset, G_ADR_VRAM_DIALOG, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_SLAP_DIALOG_2.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 11, 32, 0, 0, 18, 9, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG,160,104);
        }

        else if(G_COUNTER_1 == 1774)
        {
            // DISPLAY SLAP HUB //
            VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, 0), 11, 32, 0, 0, 18, 9, DMA_QUEUE);
            VDP_setTileMapEx(BG_B, image_SLAP_HUB.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 9, 34, 0, 0, 22, 8, DMA_QUEUE);

            // DIALOG ARROW SPRITE OFF SCREEN //
            SPR_setPosition(sprite_ARROW_DIALOG,-24,-32);

            // DISPLAY SLAP HUB SPRITES //
            SPR_setPosition(sprite_COUNTER_SLAP,88,91);

            SPR_setPosition(sprite_HAND_SLAP,152,71);

            //G_POS_X_METER_SLAP = -4;
            SPR_setPosition(sprite_METER_SLAP,G_POS_X_METER_SLAP,55);

            // RELEASE STOOGES SPRITE //
            SPR_setPosition(sprite_STOOGES,-96,0);

            // CREATE SPRITES FOR MOE, LARRY, CURLY //
            sprite_MOE   = SPR_addSprite(&tiles_SPR_MOE_SLAP,    131, 133, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
            SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_IDLE);

            sprite_LARRY = SPR_addSprite(&tiles_SPR_LARRY_SLAP,   99, 129, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
            SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_IDLE);

            sprite_CURLY = SPR_addSprite(&tiles_SPR_CURLY_SLAP,  164, 127, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
            SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_IDLE);

            //SPR_setAnimAndFrame(sprite_MOE,1,3);
            //SPR_setAnimAndFrame(sprite_LARRY,1,0);


            memcpy( &palette_64[16] , image_SLAP_HUB.palette->data     , 16 * 2 );
            PAL_setPalette(PAL1,image_SLAP_HUB.palette->data,DMA_QUEUE);




            G_PHASE_SEQUENCE = SLAP_PHASE_ATTACK;

            G_COUNTER_1 = 0;
            G_INDEX_3 = 0;

            return;
        }




        G_COUNTER_1 += 1;
    }


    else if(G_PHASE_SEQUENCE == SLAP_PHASE_ATTACK)
    {
        counter_SLAP();
        counter_WAIT();
    }


    else if(G_PHASE_SEQUENCE == SLAP_PHASE_RESULT_ATTACK)
    {
        counter_SLAP();
        
        if(G_COUNTER_1 == 30)
        {
            SPR_setAnimAndFrame(sprite_MOE,0,SLAP_STATE_IDLE);
            SPR_setAnimAndFrame(sprite_LARRY,0,SLAP_STATE_IDLE);
            SPR_setAnimAndFrame(sprite_CURLY,0,SLAP_STATE_IDLE);

            G_COUNTER_1 = 0;

            G_PHASE_SEQUENCE = SLAP_PHASE_PAUSE;

            return;
        }
        
        G_COUNTER_1 += 1;
    }


    else if(G_PHASE_SEQUENCE == SLAP_PHASE_PAUSE)
    {        
        counter_SLAP();
        
        if(G_COUNTER_1 == 10)
        {
            G_COUNTER_1 = 0;

            G_PHASE_SEQUENCE = SLAP_PHASE_ATTACK;

            return;
        }
        
        G_COUNTER_1 += 1;
    }


    else if(G_PHASE_SEQUENCE == SLAP_PHASE_OVER)
    {        
        if(G_COUNTER_1 == 240)
        {
            if(G_DAY < 31)
            {
                // CLEAR SLAP HUB //
                VDP_setTileMapEx(BG_B, image_SLAP_BG_B.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 9, 34, 9, 6, 22, 8, DMA_QUEUE);

                // DISPLAY HUB //
                display_HUB();

                SPR_setFrame(sprite_STOOGES,17);
                SPR_setPosition(sprite_STOOGES,117,133);


                SPR_releaseSprite(sprite_MOE);
                SPR_releaseSprite(sprite_LARRY);
                SPR_releaseSprite(sprite_CURLY);


                SPR_releaseSprite(sprite_COUNTER_SLAP);
                SPR_releaseSprite(sprite_HAND_SLAP);
                SPR_releaseSprite(sprite_METER_SLAP);
                SPR_releaseSprite(sprite_ARROW_DIALOG);

                
                G_COUNTER_1             = 0;
                G_INDEX_1               = 0;
                G_INDEX_2               = 0;
                G_INDEX_3               = 0;


                G_COUNTER_ROULETTE      = 0;
                G_CURRENT_TURN          = 9;


                G_SCENE = SCENE_ROULETTE;

                G_PHASE_SEQUENCE = ROULETTE_PHASE_READY;

                return;
            }

            else
            {
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


                G_COUNTER_1             = 0;
                G_INDEX_1               = 0;
                G_INDEX_2               = 0;
                G_INDEX_3               = 0;


                G_SCENE             = SCENE_FADE_IN;
                G_SCENE_TYPE        = SCENE_GAMEOVER;
                G_SCENE_NEXT        = SCENE_GAMEOVER;

                G_SCENE_LOADED      = FALSE;

                return;
            }
        }
        
        G_COUNTER_1 += 1;
    }


    else if(G_PHASE_SEQUENCE == SLAP_PHASE_HIT)
    {        
        counter_SLAP();
        
        if(G_COUNTER_WAIT == 10)
        {
            G_COUNTER_WAIT = 0;

            G_PHASE_SEQUENCE = SLAP_PHASE_ATTACK;

            return;
        }
        
        G_COUNTER_WAIT += 1;
    }
}









