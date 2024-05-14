#include "genesis.h"


#include "include/outils.h"

#include "include/joypad_BUTTONS.h"
#include "include/init.h"


#include "include/variables.h"


#include "include/routines_BANK.h"
#include "include/routines_BOXING.h"
#include "include/routines_DOLLAR.h"
#include "include/routines_INTRO.h"
#include "include/routines_QUESTION_MARK.h"
#include "include/routines_REWARD.h"
#include "include/routines_ROULETTE.h"
#include "include/routines_SLAP.h"
#include "include/routines_TRIVIA.h"


#include "include/tables_INTRO.h"








int main(bool hardReset)
{
    init_SYSTEM();

    init_VARIABLES();

    JOY_init();
    
    while(TRUE)
    {
        //**************************************************************************************//
        //                                                                                      //
        //                                     INTRO                                            //
        //                                                                                      //
        //**************************************************************************************//

        if(G_REEL == REEL_INTRO)
        {
            // LOADING INTRO SCREEN //
            if(G_SCENE_LOADED == FALSE)
            {
                init_INTRO();

                // INTRO SCREEN LOADED //
                G_SCENE_LOADED = TRUE;
            }

            // PLAYING INTRO SCREEN //
            else
            {
                // INTRO SCREEN 1 //
                if(G_SCENE == SCENE_INTRO_SCREEN_1)
                {
                    anim_INTRO_SCREEN_1();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 2 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_2)
                {
                    anim_INTRO_SCREEN_2();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 3 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_3)
                {
                    anim_INTRO_SCREEN_3();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 4 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_4)
                {
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 5 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_5)
                {
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 6 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_6)
                {
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 7 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_7)
                {
                    anim_INTRO_SCREEN_7();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // FADE IN //
                else if(G_SCENE == SCENE_FADE_IN)
                {
                    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_1)
                    {
                        PAL_fadeInAll(palette_64, 25, FALSE);
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_2)
                    {
                        PAL_fadeInAll(palette_64, 1, FALSE);
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_3)
                    {
                        PAL_fadeInAll(palette_64, 35, FALSE);
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_4)
                    {
                        //
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_5)
                    {
                        //
                    }
                    
                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_6)
                    {
                        //
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_7)
                    {
                        PAL_fadeInAll(palette_64, 40, FALSE);
                    }


                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }

                // FADE OUT //
                else if(G_SCENE == SCENE_FADE_OUT)
                {
                    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_1)
                    {
                        fadeOut_INTRO_SCREEN_1();
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_2)
                    {
                        fadeOut_INTRO_SCREEN_2();
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_3)
                    {
                        fadeOut_INTRO_SCREEN_3();
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_4)
                    {
                        //
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_5)
                    {
                        //
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_6)
                    {
                        //
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_7)
                    {
                        fadeOut_INTRO_SCREEN_7();
                    }
                }
            }
        }




        //**************************************************************************************//
        //                                                                                      //
        //                                      GAME                                            //
        //                                                                                      //
        //**************************************************************************************//

        else if(G_REEL == REEL_GAME)
        {
            // LOADING GAME SEQUENCE //
            if(G_SCENE_LOADED == FALSE)
            {
                init_SCENE();

                // INTRO SCREEN LOADED //
                G_SCENE_LOADED = TRUE;
            }

            // PLAYING GAME SEQUENCE //
            else
            {
                // BANK //
                if(G_SCENE == SCENE_BANK)
                {                    
                    sequence_BANK();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // BOXING //
                else if(G_SCENE == SCENE_BOXING)
                {                    
                    sequence_BOXING();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // DOCTORS //
                else if(G_SCENE == SCENE_DOCTORS)
                {                    
                    //sequence_BOXING();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // DOLLAR //
                else if(G_SCENE == SCENE_DOLLAR)
                {                    
                    sequence_DOLLAR();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // QUESTION MARK //
                else if(G_SCENE == SCENE_QUESTION_MARK)
                {                    
                    sequence_QUESTION_MARK();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // SLAP //
                else if(G_SCENE == SCENE_SLAP)
                {                    
                    sequence_SLAP();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // ROULETTE //
                else if(G_SCENE == SCENE_ROULETTE)
                {
                    JOY_setEventHandler(roulette_Callback);
                    
                    sequence_ROULETTE();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // TRIVIA MINIGAME TYPE 1 //
                else if(G_SCENE == SCENE_TRIVIA_MINIGAME_TYPE1)
                {
                    JOY_setEventHandler(trivia_Callback);
                    joypad_TRIVIA();
                    
                    
                    sequence_TRIVIA_TYPE1();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // TRIVIA MINIGAME TYPE 2 //
                else if(G_SCENE == SCENE_TRIVIA_MINIGAME_TYPE2)
                {
                    JOY_setEventHandler(trivia_Callback);
                    joypad_TRIVIA();

                    sequence_TRIVIA_TYPE2();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // TRIVIA QUESTION //
                else if(G_SCENE == SCENE_TRIVIA_QUESTION)
                {
                    sequence_TRIVIA_QUESTION();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // BOXING SCREEN TYPE 1 //
                else if(G_SCENE == SCENE_BOXING_SCREEN_TYPE1)
                {
                    sequence_BOXING_SCREEN_TYPE_1();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // BOXING SCREEN TYPE 2 //
                else if(G_SCENE == SCENE_BOXING_SCREEN_TYPE2)
                {
                    sequence_BOXING_SCREEN_TYPE_2();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // BOXING SCREEN TYPE 3 //
                else if(G_SCENE == SCENE_BOXING_SCREEN_TYPE3)
                {
                    //sequence_BOXING_SCREEN_TYPE_3();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // REWARD //
                else if(G_SCENE == SCENE_REWARD)
                {                    
                    sequence_REWARD();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // CONTRACT QUESTION MARK //
                else if(G_SCENE == SCENE_CONTRACT_QUESTION_MARK)
                {                    
                    sequence_CONTRACT_QUESTION_MARK();
                    
                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // FADE IN //
                else if(G_SCENE == SCENE_FADE_IN)
                {
                    /*if(G_SCENE_TYPE == SCENE_ROULETTE)
                    {
                        PAL_fadeInAll(palette_64, 40, FALSE);
                    }

                    else if(G_SCENE_TYPE == SCENE_SLAP)
                    {
                        PAL_fadeInAll(palette_64, 40, FALSE);
                    }

                    else if(G_SCENE_TYPE == SCENE_REWARD)
                    {
                        PAL_fadeInAll(palette_64, 40, FALSE);
                    }*/

                    PAL_fadeInAll(palette_64, 40, FALSE);

                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }

                // FADE OUT //
                else if(G_SCENE == SCENE_FADE_OUT)
                {                    
                    fadeOut_ROULETTE();
                }
            }
        }
    }

	return 0;
}
