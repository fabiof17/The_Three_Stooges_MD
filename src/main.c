#include "genesis.h"


#include "include/custom_tools.h"

#include "include/joypad_BUTTONS.h"
#include "include/init.h"


#include "include/variables.h"


#include "include/routines_BANK.h"
#include "include/routines_BOXING.h"
#include "include/routines_BOXING_MINIGAME.h"
#include "include/routines_CRACKERs.h"
#include "include/routines_CRACKERS_MINIGAME.h"
#include "include/routines_DISCLAIMER.h"
#include "include/routines_DOCTORS.h"
#include "include/routines_DOCTORS_MINIGAME.h"
#include "include/routines_DOLLAR.h"
#include "include/routines_GAMEOVER.h"
#include "include/routines_INTRO.h"
#include "include/routines_LOGO.h"
#include "include/routines_QUESTION_MARK.h"
#include "include/routines_REWARD.h"
#include "include/routines_ROULETTE.h"
#include "include/routines_SAFE.h"
#include "include/routines_SLAP.h"
#include "include/routines_THE_END.h"
#include "include/routines_TRIVIA.h"
#include "include/routines_WAITERS.h"
#include "include/routines_WAITERS_MINIGAME.h"


#include "include/tables_CRACKERS.h"
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
        //                                   DISCLAIMER                                         //
        //                                                                                      //
        //**************************************************************************************//

        if(G_REEL == REEL_DISCLAIMER)
        {
            // LOADING DISCLAIMER SCREEN //
            if(G_SCENE_LOADED == FALSE)
            {
                JOY_setEventHandler(disable_Callback);

                init_DISCLAIMER();
            }

            // PLAYING DISCLAIMER SCREEN //
            else
            {
                if(G_SCENE == SCENE_LOGO_SCREEN)
                {
                    sequence_DISCLAIMER();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                else if(G_SCENE == SCENE_FADE_IN)
                {
                    PAL_fadeInAll(palette_64, 30, FALSE);

                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }
            }
        }




        //**************************************************************************************//
        //                                                                                      //
        //                                   SGDK LOGO                                          //
        //                                                                                      //
        //**************************************************************************************//

        else if(G_REEL == REEL_LOGO)
        {
            // LOADING SGDK LOGO SCREEN //
            if(G_SCENE_LOADED == FALSE)
            {
                JOY_setEventHandler(disable_Callback);

                init_LOGO();
            }

            // PLAYING SGDK LOGO SCREEN //
            else
            {
                if(G_SCENE == SCENE_LOGO_SCREEN)
                {
                    sequence_LOGO();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                else if(G_SCENE == SCENE_FADE_IN)
                {
                    PAL_fadeInAll(palette_64, 30, FALSE);

                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }
            }
        }




        //**************************************************************************************//
        //                                                                                      //
        //                                     INTRO                                            //
        //                                                                                      //
        //**************************************************************************************//

        else if(G_REEL == REEL_INTRO)
        {
            // LOADING INTRO SCREEN //
            if(G_SCENE_LOADED == FALSE)
            {
                JOY_setEventHandler(disable_Callback);

                init_INTRO();
            }

            // PLAYING INTRO SCREEN //
            else
            {
                // INTRO SCREEN 1 //
                if(G_SCENE == SCENE_INTRO_SCREEN_1)
                {
                    JOY_setEventHandler(intro_Callback);

                    anim_INTRO_SCREEN_1();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 2 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_2)
                {
                    JOY_setEventHandler(intro_Callback);

                    anim_INTRO_SCREEN_2();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 3 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_3)
                {
                    JOY_setEventHandler(intro_Callback);

                    anim_INTRO_SCREEN_3();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 4 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_4)
                {
                    JOY_setEventHandler(intro_Callback);

                    anim_INTRO_SCREEN_4_5_6();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 5 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_5)
                {
                    JOY_setEventHandler(intro_Callback);

                    anim_INTRO_SCREEN_4_5_6();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 6 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_6)
                {
                    JOY_setEventHandler(intro_Callback);

                    anim_INTRO_SCREEN_4_5_6();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // INTRO SCREEN 7 //
                else if(G_SCENE == SCENE_INTRO_SCREEN_7)
                {
                    JOY_setEventHandler(intro_Callback);

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
                        PAL_fadeInAll(palette_64, 16, FALSE);
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_5)
                    {
                        PAL_fadeInAll(palette_64, 4, FALSE);
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_6)
                    {
                        PAL_fadeInAll(palette_64, 4, FALSE);
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
                        fadeOut_INTRO_SCREEN_4();
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_5)
                    {
                        fadeOut_INTRO_SCREEN_5();
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_6)
                    {
                        fadeOut_INTRO_SCREEN_6();
                    }

                    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_7)
                    {
                        fadeOut_INTRO_SCREEN_7();
                    }
                }

                // EXIT //
                else if(G_SCENE == SCENE_INTRO_EXIT)
                {
                    // FADE OUT : 30 FRAMES //
                    PAL_fadeOutAll(30,FALSE);

                    // STOP SOUND EFFECTS //
                    if(XGM_isPlayingPCM(SOUND_PCM_CH4_MSK) != 0)
                    {
                        XGM_stopPlayPCM(SOUND_PCM_CH4);
                    }

                    // STOP MUSIC //
                    if(XGM_isPlaying() != FALSE)
                    {
                        XGM_stopPlay();
                    }

                    // CLEAR PLANES //
                    VDP_clearPlane(BG_B,TRUE);
                    VDP_clearPlane(BG_A,TRUE);

                    // RELEASE ALL SPRITES //
                    SPR_reset();


                    G_REEL              = REEL_GAME;

                    G_SCENE             = SCENE_FADE_IN;
                    G_SCENE_TYPE        = SCENE_ROULETTE;
                    G_SCENE_NEXT        = SCENE_ROULETTE;

                    G_SCENE_LOADED      = FALSE;

                    waitMs(4000);
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
                JOY_setEventHandler(disable_Callback);

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
                    JOY_setEventHandler(disable_Callback);

                    sequence_BOXING();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // DOCTORS //
                else if(G_SCENE == SCENE_DOCTORS)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_DOCTORS();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // DOLLAR //
                else if(G_SCENE == SCENE_DOLLAR)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_DOLLAR();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // QUESTION MARK //
                else if(G_SCENE == SCENE_QUESTION_MARK)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_QUESTION_MARK();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // SLAP //
                else if(G_SCENE == SCENE_SLAP)
                {
                    joypad_SLAP();
                    JOY_setEventHandler(slap_Callback);

                    sequence_SLAP();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // WAITERS //
                else if(G_SCENE == SCENE_WAITERS)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_WAITERS();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // CRACKERS //
                else if(G_SCENE == SCENE_CRACKERS)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_CRACKERS();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // SAFE //
                else if(G_SCENE == SCENE_SAFE)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_SAFE();

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


                //-------------------------------------------------//
                //                    MINIGAMES                    //
                //-------------------------------------------------//

                // CRACKERS MINIGAME //
                else if(G_SCENE == SCENE_BOXING_MINIGAME)
                {
                    JOY_setEventHandler(boxing_Callback);

                    sequence_BOXING_MINIGAME();

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
                    JOY_setEventHandler(disable_Callback);

                    sequence_BOXING_SCREEN_TYPE_1();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // BOXING SCREEN TYPE 2 //
                else if(G_SCENE == SCENE_BOXING_SCREEN_TYPE2)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_BOXING_SCREEN_TYPE_2();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // BOXING SCREEN TYPE 3 //
                else if(G_SCENE == SCENE_BOXING_SCREEN_TYPE3)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_BOXING_SCREEN_TYPE_3();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // DOCTORS MINIGAME //
                else if(G_SCENE == SCENE_DOCTORS_MINIGAME)
                {
                    joypad_DOCTORS_MINIGAME();

                    sequence_DOCTORS_MINIGAME();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // WAITERS MINIGAME //
                else if(G_SCENE == SCENE_WAITERS_MINIGAME)
                {
                    joypad_WAITERS_MINIGAME();
                    JOY_setEventHandler(waiters_Callback);

                    sequence_WAITERS_MINIGAME();

                    /*VDP_drawIntEx_BG_A_QUEUE(list_GUESTS[0].pie_DEVIATION,1,1,0,PAL1);
                    VDP_drawIntEx_BG_A_QUEUE(list_GUESTS[1].pie_DEVIATION,1,1,1,PAL1);
                    VDP_drawIntEx_BG_A_QUEUE(list_GUESTS[2].pie_DEVIATION,1,1,2,PAL1);

                    VDP_drawIntEx_BG_A_QUEUE(list_WAITERS[0].pie_DEVIATION,1,3,0,PAL1);
                    VDP_drawIntEx_BG_A_QUEUE(list_WAITERS[1].pie_DEVIATION,1,3,1,PAL1);
                    VDP_drawIntEx_BG_A_QUEUE(list_WAITERS[2].pie_DEVIATION,1,3,2,PAL1);*/

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // CRACKERS SCREEN //
                else if(G_SCENE == SCENE_CRACKERS_SCREEN)
                {
                    sequence_CRACKERS_SCREEN();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // CRACKERS MINIGAME //
                else if(G_SCENE == SCENE_CRACKERS_MINIGAME)
                {
                    JOY_setEventHandler(crackers_Callback);
                    joypad_CRACKERS_MINIGAME();

                    sequence_CRACKERS_MINIGAME();

                    SPR_update();
                    SYS_doVBlankProcess();
                }


                //-------------------------------------------------//
                //                    CONTRACTS                    //
                //-------------------------------------------------//

                // CONTRACT QUESTION MARK //
                else if(G_SCENE == SCENE_CONTRACT_QUESTION_MARK)
                {
                    JOY_setEventHandler(pause_Callback);

                    if(G_PAUSE == FALSE)
                    {
                        sequence_CONTRACT_QUESTION_MARK();
                    }

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // CONTRACT DOCTORS //
                else if(G_SCENE == SCENE_CONTRACT_DOCTORS)
                {
                    JOY_setEventHandler(pause_Callback);

                    if(G_PAUSE == FALSE)
                    {
                        sequence_CONTRACT_DOCTORS();
                    }

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // CONTRACT WAITERS //
                else if(G_SCENE == SCENE_CONTRACT_WAITERS)
                {
                    JOY_setEventHandler(pause_Callback);

                    if(G_PAUSE == FALSE)
                    {
                        sequence_CONTRACT_WAITERS();
                    }

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // CONTRACT CRACKERS //
                else if(G_SCENE == SCENE_CONTRACT_CRACKERS)
                {
                    JOY_setEventHandler(pause_Callback);

                    if(G_PAUSE == FALSE)
                    {
                        sequence_CONTRACT_CRACKERS();
                    }

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // CONTRACT BOXING //
                else if(G_SCENE == SCENE_CONTRACT_BOXING)
                {
                    JOY_setEventHandler(pause_Callback);

                    if(G_PAUSE == FALSE)
                    {
                        sequence_CONTRACT_BOXING();
                    }

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // FADE IN CRACKERS //
                else if(G_SCENE == SCENE_FADE_IN_CRACKERS)
                {
                    JOY_setEventHandler(disable_Callback);

                    PAL_fadeInAll(palette_64, 1, FALSE);

                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }

                // FADE OUT CRACKERS //
                else if(G_SCENE == SCENE_FADE_OUT_CRACKERS)
                {
                    JOY_setEventHandler(disable_Callback);

                    PAL_fadeOutAll(1,FALSE);

                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }

                // CONTRACT QUESTION MARK //
                else if(G_SCENE == SCENE_CONTRACT_SAFE)
                {
                    JOY_setEventHandler(pause_Callback);

                    if(G_PAUSE == FALSE)
                    {
                        sequence_CONTRACT_SAFE();
                    }

                    SPR_update();
                    SYS_doVBlankProcess();
                }




                // REWARD //
                else if(G_SCENE == SCENE_REWARD)
                {
                    JOY_setEventHandler(pause_Callback);

                    if(G_PAUSE == FALSE)
                    {
                        sequence_REWARD();
                    }

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // GAME OVER //
                else if(G_SCENE == SCENE_GAMEOVER)
                {
                    JOY_setEventHandler(disable_Callback);

                    sequence_GAMEOVER();

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                // FADE IN //
                else if(G_SCENE == SCENE_FADE_IN)
                {
                    JOY_setEventHandler(disable_Callback);

                    PAL_fadeInAll(palette_64, 40, FALSE);

                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }

                // FADE OUT //
                else if(G_SCENE == SCENE_FADE_OUT)
                {
                    JOY_setEventHandler(disable_Callback);

                    fadeOut_ROULETTE();
                }

                // FADE IN BOXING //
                else if(G_SCENE == SCENE_FADE_IN_BOXING)
                {
                    JOY_setEventHandler(disable_Callback);

                    PAL_fadeInAll(palette_64, 2, FALSE);

                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }

            }
        }




        //**************************************************************************************//
        //                                                                                      //
        //                                     THE END                                          //
        //                                                                                      //
        //**************************************************************************************//

        else if(G_REEL == REEL_THE_END)
        {
            // LOADING THE END SCREEN //
            if(G_SCENE_LOADED == FALSE)
            {
                JOY_setEventHandler(disable_Callback);

                init_THE_END();
            }

            // PLAYING THE END SCREEN //
            else
            {
                if(G_SCENE == SCENE_THE_END)
                {
                    sequence_THE_END();

                    //VDP_drawIntEx_BG_A_QUEUE(G_COUNTER_1,1,40,0,PAL0);

                    SPR_update();
                    SYS_doVBlankProcess();
                }

                else if(G_SCENE == SCENE_FADE_IN)
                {
                    PAL_fadeInAll(palette_64, 30, FALSE);

                    G_SCENE         = G_SCENE_NEXT;
                    G_SCENE_NEXT    = NULL;
                }
            }
        }
    }

	return 0;
}
