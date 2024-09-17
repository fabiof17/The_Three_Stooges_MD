#include <genesis.h>



#include "custom_tools.h"
#include "palettes.h"
#include "structures.h"
#include "variables.h"



#include "maps_GLOBAL.h"
#include "maps_TRIVIA.h"



#include "routines_ROULETTE.h"



#include "tables_GLOBAL.h"
#include "tables_QUESTIONS.h"
#include "tables_TRIVIA.h"






void fadeOut_TRIVIA()
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

    G_SCENE             = SCENE_FADE_IN;
    G_SCENE_NEXT        = SCENE_ROULETTE;

    G_SCENE_LOADED      = FALSE;
}


inline static void anim_ANSWER()
{
    // B //
    if(G_COUNTER_1 == 0)
    {
        SPR_setPosition(sprite_ANSWER_B,138,90);
        
        SPR_setPosition(sprite_ANSWER_A,-48,-48);
        SPR_setPosition(sprite_ANSWER_C,-48,-48);
    }

    // C //
    if(G_COUNTER_1 == 1)
    {
        SPR_setPosition(sprite_ANSWER_C,186,100);
        
        SPR_setPosition(sprite_ANSWER_A,-48,-48);
        SPR_setPosition(sprite_ANSWER_B,-48,-48);
    }

    // A //
    if(G_COUNTER_1 == 3)
    {
        SPR_setPosition(sprite_ANSWER_A,90,100);
        
        SPR_setPosition(sprite_ANSWER_B,-48,-48);
        SPR_setPosition(sprite_ANSWER_C,-48,-48);
    }

    // B //
    if(G_COUNTER_1 == 5)
    {
        SPR_setPosition(sprite_ANSWER_B,138,90);
        
        SPR_setPosition(sprite_ANSWER_A,-48,-48);
        SPR_setPosition(sprite_ANSWER_C,-48,-48);
    }

    // A //
    if(G_COUNTER_1 == 6)
    {
        SPR_setPosition(sprite_ANSWER_A,90,100);
        
        SPR_setPosition(sprite_ANSWER_B,-48,-48);
        SPR_setPosition(sprite_ANSWER_C,-48,-48);
    }

    // B //
    if(G_COUNTER_1 == 7)
    {
        SPR_setPosition(sprite_ANSWER_B,138,90);
        
        SPR_setPosition(sprite_ANSWER_A,-48,-48);
        SPR_setPosition(sprite_ANSWER_C,-48,-48);
    }

    // C //
    if(G_COUNTER_1 == 9)
    {
        SPR_setPosition(sprite_ANSWER_C,186,100);
        
        SPR_setPosition(sprite_ANSWER_A,-48,-48);
        SPR_setPosition(sprite_ANSWER_B,-48,-48);
    }

    // A //
    if(G_COUNTER_1 == 11)
    {
        SPR_setPosition(sprite_ANSWER_A,90,100);
        
        SPR_setPosition(sprite_ANSWER_B,-48,-48);
        SPR_setPosition(sprite_ANSWER_C,-48,-48);
    }

    // C //
    if(G_COUNTER_1 == 12)
    {
        SPR_setPosition(sprite_ANSWER_C,186,100);
        
        SPR_setPosition(sprite_ANSWER_A,-48,-48);
        SPR_setPosition(sprite_ANSWER_B,-48,-48);
    }

    // A //
    if(G_COUNTER_1 == 13)
    {
        SPR_setPosition(sprite_ANSWER_A,90,100);
        
        SPR_setPosition(sprite_ANSWER_B,-48,-48);
        SPR_setPosition(sprite_ANSWER_C,-48,-48);
    }



    G_COUNTER_1 += 1;

    if(G_COUNTER_1 == 15)
    {
        G_COUNTER_1 = 0;
    }
}


void joypad_TRIVIA()
{
    u16 value=JOY_readJoypad(JOY_1);

    // FUEL DEPOT //
    if(G_PHASE_SEQUENCE != TRIVIA_PHASE_WALKIN && G_PHASE_SEQUENCE != TRIVIA_PHASE_TURN_BACK && G_PHASE_SEQUENCE != TRIVIA_PHASE_RESULT)
    {
        //******************************************//
        //                                          //
        //                NO BUTTONS                //
        //                                          //
        //******************************************//        
        if((value & BUTTON_DIR) == 0)
        {
            G_PHASE_SEQUENCE = TRIVIA_PHASE_ANIM_ANSWERS;
        }

        //******************************************//
        //                                          //
        //                   LEFT                   //
        //                                          //
        //******************************************//
        else if(value & BUTTON_LEFT)
        {
            // A //
            if(G_COUNTER_1 == 13)
            {
                SPR_setPosition(sprite_ANSWER_A,90,100);
                
                SPR_setPosition(sprite_ANSWER_B,-48,-48);
                SPR_setPosition(sprite_ANSWER_C,-48,-48);

                G_COUNTER_1 = 0;

                G_SELECTED_ANSWER = 0;

                G_PHASE_SEQUENCE = TRIVIA_PHASE_CHOICE;
            }
        }

        //******************************************//
        //                                          //
        //                   RIGHT                  //
        //                                          //
        //******************************************//
        else if(value & BUTTON_RIGHT)
        {
            // C //
            if(G_COUNTER_1 == 13)
            {
                SPR_setPosition(sprite_ANSWER_C,186,100);
                
                SPR_setPosition(sprite_ANSWER_A,-48,-48);
                SPR_setPosition(sprite_ANSWER_B,-48,-48);

                G_COUNTER_1 = 0;

                G_SELECTED_ANSWER = 1;

                G_PHASE_SEQUENCE = TRIVIA_PHASE_CHOICE;
            }
        }

        //******************************************//
        //                                          //
        //                     UP                   //
        //                                          //
        //******************************************//
        else if(value & BUTTON_UP)
        {
            // C //
            if(G_COUNTER_1 == 13)
            {
                SPR_setPosition(sprite_ANSWER_B,138,90);
                
                SPR_setPosition(sprite_ANSWER_A,-48,-48);
                SPR_setPosition(sprite_ANSWER_C,-48,-48);

                G_COUNTER_1 = 0;

                G_SELECTED_ANSWER = 2;

                G_PHASE_SEQUENCE = TRIVIA_PHASE_CHOICE;
            }
        }
    }
}





void sequence_TRIVIA_TYPE1()
{
    if(G_PHASE_SEQUENCE == TRIVIA_PHASE_WALKIN)
    {
        // STOOGES ANIMATION //
        // SETUP POINTER TO STOOGES ANIMATION TABLE //
        const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_WALKIN_TRIVIA_TYPE1[G_INDEX_3];

        // STOOGES WALKIN //
        if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
        {
            // CHANGING SPRITE ANIMATION FRAME //
            SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

            // RETRIEVE X POSITION FROM TABLE //
            SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 133 );


            // UPDATE INDEX IN STOOGES ANIMATION TABLE //
            // UP TO 29 (LAST INDEX IN ARRAY OF 30 ENTRIES) //
            if(G_INDEX_3 < 28)
            {
                G_INDEX_3 += 1;
            }
        }


        // RADIO MESSAGE //
        if(G_COUNTER_1 == 345)
        {
            // DISPLAY DIALOG //
            VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_DIALOG.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 4, 31, 0, 0, 31, 10, DMA_QUEUE);

            // DISPLAY DIALOG ARROW //
            SPR_setPosition(sprite_ARROW_DIALOG,148,104);
        }


        // HIDE RADIO MESSAGE //
        else if(G_COUNTER_1 == 525)
        {
            // HIDE DIALOG //
            VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 4, 31, 4, 3, 31, 10, DMA_QUEUE);

            // HIDE DIALOG ARROW //
            SPR_setPosition(sprite_ARROW_DIALOG,-40,-40);
        }


        // DISPLAY QUESTION //
        else if(G_COUNTER_1 == 585)
        {
            // DISPLAY DIALOG //
            VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_DIALOG.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 4, 31, 0, 0, 31, 10, DMA_QUEUE);

            // DISPLAY QUESTION //
            VDP_setTileMapEx(BG_A, TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_QUESTION), 5, 32, 0, 0, 29, 3, DMA_QUEUE);

            // DISPLAY ANSWERS //
            VDP_setTileMapEx(BG_A, TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_QUESTION), 5, 36, 0, 4, 29, 3, DMA_QUEUE);

            // DISPLAY DIALOG ARROW //
            SPR_setPosition(sprite_ARROW_DIALOG,148,104);
        }


        // PCM //
        else if(G_COUNTER_1 == 900)
        {
            XGM_startPlayPCM(SOUND_TRIVIA_1 , 15 , SOUND_PCM_CH4 );
        }




        // ANIM ANSWERS //
        else if(G_COUNTER_1 == 1185)
        {
            // HIDE DIALOG //
            VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 4, 31, 4, 3, 31, 10, DMA_QUEUE);

            // HIDE DIALOG ARROW //
            SPR_setPosition(sprite_ARROW_DIALOG,-40,-40);

            SPR_setFrame(sprite_STOOGES,20);
            SPR_setPosition(sprite_STOOGES,114,133);
        }

        // ANIM ANSWERS //
        else if(G_COUNTER_1 == 1198)
        {
            SPR_setFrame(sprite_STOOGES,21);
            //SPR_setPosition(sprite_STOOGES,114,133);
        }

        // ANIM ANSWERS //
        else if(G_COUNTER_1 == 1212)
        {
            SPR_setFrame(sprite_STOOGES,22);
            
            SPR_setPosition(sprite_ANSWER_A,90,100);
        }

        // ANIM ANSWERS //
        else if(G_COUNTER_1 == 1225)
        {
            SPR_setFrame(sprite_STOOGES,23);

            SPR_setPosition(sprite_ANSWER_C,186,100);
        }

        // ANIM ANSWERS //
        else if(G_COUNTER_1 == 1240)
        {
            SPR_setFrame(sprite_STOOGES,24);

            SPR_setPosition(sprite_ANSWER_B,138,90);
        }

        // GO TO CHOICE PHASE //
        else if(G_COUNTER_1 == 1285)
        {
            G_COUNTER_1 = 0;
            G_INDEX_3   = 0;

            G_PHASE_SEQUENCE = TRIVIA_PHASE_ANIM_ANSWERS;

            return;
        }

        G_COUNTER_1 += 1;
    }

    // ANIM ANSWERS //
    else if(G_PHASE_SEQUENCE == TRIVIA_PHASE_ANIM_ANSWERS)
    {
        anim_ANSWER();
    }

    // PLAYER CHOICE //
    else if(G_PHASE_SEQUENCE == TRIVIA_PHASE_CHOICE)
    {
        // WAIT JOYPAD INPUT //
    }

    // GETTING RESULT //
    else if(G_PHASE_SEQUENCE == TRIVIA_PHASE_RESULT)
    {
        if(G_COUNTER_1 == 72)
        {
            // WRONG ANSWER //
            if(G_STATUS_MISSION == FAILED)
            {
                XGM_startPlayPCM(SOUND_WRONG_ANSWER , 15 , SOUND_PCM_CH4 );
            }
        }
        
        else if(G_COUNTER_1 == 120)
        {
            // GOOD ANSWER //
            if(G_STATUS_MISSION == SUCCESS)
            {
                SPR_setFrame(sprite_STOOGES,26);
            }

            // WRONG ANSWER //
            else
            {
                // A //
                if(G_SELECTED_ANSWER == 0)
                {
                    SPR_setFrame(sprite_STOOGES,27);
                }

                // B //
                else if(G_SELECTED_ANSWER == 1)
                {
                    SPR_setFrame(sprite_STOOGES,28);
                }

                // C //
                else if(G_SELECTED_ANSWER == 2)
                {
                    SPR_setFrame(sprite_STOOGES,29);
                }
            }
        }

        else if(G_COUNTER_1 == 140)
        {
            
            if(G_STATUS_MISSION == FAILED)
            {
                SPR_setFrame(sprite_STOOGES,25);
            }
        }


        else if(G_COUNTER_1 == 300)
        {
            // GO TO REWARD SCENE //
            if(G_STATUS_MISSION == SUCCESS)
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

                G_PHASE_SEQUENCE = 0;

                // DEFINE NEXT MINIGAME //
                G_SCENE         = SCENE_FADE_IN;
                G_SCENE_TYPE    = SCENE_REWARD;
                G_SCENE_NEXT    = SCENE_REWARD;

                G_SCENE_LOADED  = FALSE;
            }

            // GO TO ROULETTE SEQUENCE //
            else
            {
                // 1 DAY SPENT //
                G_DAY += 1;

                // PRINT DAY NUMBER //
                print_DAY();
                
                // DISPLAY HUB //
                display_HUB();

                G_PHASE_SEQUENCE = ROULETTE_PHASE_READY;
                
                G_SCENE = SCENE_ROULETTE;
            }
        }
        
        
        
        G_COUNTER_1 += 1;
    }
}


void sequence_TRIVIA_TYPE2()
{
    if(G_PHASE_SEQUENCE == TRIVIA_PHASE_WALKIN)
    {
        // STOOGES ANIMATION //
        // SETUP POINTER TO STOOGES ANIMATION TABLE //
        const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_WALKIN_TRIVIA_TYPE2[G_INDEX_3];

        // STOOGES WALKIN //
        if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
        {
            // CHANGING SPRITE ANIMATION FRAME //
            SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

            // RETRIEVE X POSITION FROM TABLE //
            SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 133 );


            // UPDATE INDEX IN STOOGES ANIMATION TABLE //
            // UP TO 28 (LAST INDEX IN ARRAY OF 29 ENTRIES) //
            if(G_INDEX_3 < 28)
            {
                G_INDEX_3 += 1;
            }
        }


        if(G_COUNTER_1 == 634)
        {
            // PLAY HEAD SHOCK SOUND //
            XGM_startPlayPCM(SOUND_HEAD_TRIVIA,15,SOUND_PCM_CH4);
        }

        else if(G_COUNTER_1 == 950)
        {
            XGM_startPlayPCM(SOUND_TRIVIA_2 , 15 , SOUND_PCM_CH4 );
        }

        else if(G_COUNTER_1 == 1018)
        {
            G_COUNTER_1 = 0;
            G_INDEX_3   = 0;

            //G_PHASE_SEQUENCE = TRIVIA_PHASE_TURN_BACK;

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

            // DEFINE NEXT MINIGAME //
            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_TRIVIA_QUESTION;
            G_SCENE_NEXT    = SCENE_TRIVIA_QUESTION;

            G_SCENE_LOADED  = FALSE;

            return;
        }

        G_COUNTER_1 += 1;
    }

    // STOOGES TURN BACK //
    else if(G_PHASE_SEQUENCE == TRIVIA_PHASE_TURN_BACK)
    {
        //
        
        if(G_COUNTER_1 == 0)
        {
            SPR_setFrame(sprite_STOOGES,20);
        }

        else if(G_COUNTER_1 == 12)
        {
            SPR_setFrame(sprite_STOOGES,21);
        }

        else if(G_COUNTER_1 == 33)
        {
            SPR_setFrame(sprite_STOOGES,22);
            SPR_setPosition(sprite_ANSWER_A,90,100);
        }

        else if(G_COUNTER_1 == 49)
        {
            SPR_setFrame(sprite_STOOGES,23);
            SPR_setPosition(sprite_ANSWER_C,186,100);
        }

        else if(G_COUNTER_1 == 62)
        {
            SPR_setPosition(sprite_ANSWER_B,138,90);
        }

        else if(G_COUNTER_1 == 107)
        {
            G_COUNTER_1 = 0;
            
            G_QUESTION_LOCKED = FALSE;

            G_PHASE_SEQUENCE = TRIVIA_PHASE_ANIM_ANSWERS;

            return;
        }

        G_COUNTER_1 += 1;
    }

    // ANIM ANSWERS //
    else if(G_PHASE_SEQUENCE == TRIVIA_PHASE_ANIM_ANSWERS)
    {
        anim_ANSWER();
    }

    // PLAYER CHOICE //
    else if(G_PHASE_SEQUENCE == TRIVIA_PHASE_CHOICE)
    {
        // WAIT JOYPAD INPUT //
    }

    // GETTING RESULT //
    else if(G_PHASE_SEQUENCE == TRIVIA_PHASE_RESULT)
    {
        if(G_COUNTER_1 == 72)
        {
            // WRONG ANSWER //
            if(G_STATUS_MISSION == FAILED)
            {
                XGM_startPlayPCM(SOUND_WRONG_ANSWER , 15 , SOUND_PCM_CH4 );
            }
        }

        else if(G_COUNTER_1 == 120)
        {
            // GOOD ANSWER //
            if(G_STATUS_MISSION == SUCCESS)
            {
                SPR_setFrame(sprite_STOOGES,26);
            }

            // WRONG ANSWER //
            else
            {
                // A //
                if(G_SELECTED_ANSWER == 0)
                {
                    SPR_setFrame(sprite_STOOGES,27);
                }

                // B //
                else if(G_SELECTED_ANSWER == 1)
                {
                    SPR_setFrame(sprite_STOOGES,28);
                }

                // C //
                else if(G_SELECTED_ANSWER == 2)
                {
                    SPR_setFrame(sprite_STOOGES,29);
                }
            }
        }

        else if(G_COUNTER_1 == 140)
        {
            
            if(G_STATUS_MISSION == FAILED)
            {
                SPR_setFrame(sprite_STOOGES,25);
            }
        }


        else if(G_COUNTER_1 == 300)
        {
            // GO TO REWARD SCENE //
            if(G_STATUS_MISSION == SUCCESS)
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

                G_PHASE_SEQUENCE = 0;

                // DEFINE NEXT MINIGAME //
                G_SCENE         = SCENE_FADE_IN;
                G_SCENE_TYPE    = SCENE_REWARD;
                G_SCENE_NEXT    = SCENE_REWARD;

                G_SCENE_LOADED  = FALSE;
            }

            // GO TO ROULETTE SEQUENCE //
            else
            {
                // 1 DAY SPENT //
                G_DAY += 1;

                // PRINT DAY NUMBER //
                print_DAY();
                
                // DISPLAY HUB //
                display_HUB();

                G_PHASE_SEQUENCE = ROULETTE_PHASE_READY;
                
                G_SCENE = SCENE_ROULETTE;
            }
        }
        
        
        
        G_COUNTER_1 += 1;
    }
}




void sequence_TRIVIA_QUESTION()
{
    if(G_COUNTER_1 == 360)
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

        G_COUNTER_1 = 0;
        G_INDEX_3   = 0;

        G_PHASE_SEQUENCE = TRIVIA_PHASE_TURN_BACK;

        G_QUESTION_LOCKED = TRUE;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_IN;
        G_SCENE_TYPE    = SCENE_TRIVIA_SELECT;
        G_SCENE_NEXT    = SCENE_TRIVIA_SELECT;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    
    G_COUNTER_1 += 1;
}









