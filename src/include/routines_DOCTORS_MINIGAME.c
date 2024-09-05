#include <genesis.h>



#include "custom_tools.h"
#include "structures.h"
#include "variables.h"




#include "maps_DOCTORS.h"
#include "maps_GLOBAL.h"




#include "tables_DOCTORS.h"




inline static void collisions_CAR(u8 car_NUMBER)
{
    //-----------------------------------------------------------------------------//
    //                     GET DISTANCE BETWEEN MOE AND PATIENT                    //
    //                     MOE WIDTH  : 56                                         //
    //                     MOE HEIGHT : 48                                         //
    //-----------------------------------------------------------------------------//
    u16 distance_X = abs((list_CARS[car_NUMBER].pos_X + 28) - ( patient.pos_X + (patient.width_PATIENT>>1) ));
    u16 distance_Y = abs((list_CARS[car_NUMBER].pos_Y + 24) - ( patient.pos_Y + (patient.height_PATIENT>>1) ));

    //-----------------------------------------------------------------------------//
    //         IF DISTANCE X IS INFERIOR THAN MOE WIDTH/2 + PATIENT WIDTH/2        //
    //-----------------------------------------------------------------------------//
    if( distance_X < (28 + (patient.width_PATIENT >>1 ) - PATIENT_BOX_MARGIN) )
    {
        //-----------------------------------------------------------------------------//
        //        IF DISTANCE Y IS INFERIOR THAN MOE HEIGHT/2 + PATIENT HEIGHT/2       //
        //-----------------------------------------------------------------------------//
        if( distance_Y < (24 + (patient.height_PATIENT >>1 )) - PATIENT_BOX_MARGIN )
        {
            if(patient.patient_STATE == PATIENT_NOT_HIT)
            {
                patient.counter_SPRITE_FRAME    = 0;
                patient.index_SPRITE_FRAME      = 0;

                patient.patient_STATE           = PATIENT_HIT;

                VDP_loadTileSet(image_DOCTORS_RED_DOT.tileset, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + G_HIT_NUMBER, DMA_QUEUE);
                G_HIT_NUMBER                    += 1;




                //-------------------------------------------------------//
                //                  UPDATE SPRITE FRAME                  //
                //-------------------------------------------------------//
                SPR_setAnimAndFrame(patient.spr_PATIENT , patient.patient_STATE , patient.index_SPRITE_FRAME);
            }

            list_CARS[car_NUMBER].hit       = TRUE;

            if(G_CAR_SPEED != 1)
            {
                XGM_startPlayPCM(SOUND_ENGINE_1 , 13 , SOUND_PCM_CH2 );
            }

            G_CAR_SPEED                     = 1;

            G_CAR_COUNTER_SPEED             = 0;


            //-----------------------------------------------------------------------------//
            //                                                                             //
            //                     PATIENT WILL BE OFFSETED TO THE RIGHT                   //
            //                                                                             //
            //-----------------------------------------------------------------------------//
            if( (list_CARS[car_NUMBER].pos_X + 28) <= (patient.pos_X + (patient.width_PATIENT>>1)))
            {
                //-----------------------------------------------------------------------------//
                //              IF THERE IS ENOUGH SPACE BETWEEN PATIENT AND WALL              //
                //-----------------------------------------------------------------------------//
                if(list_CARS[car_NUMBER].pos_X + 56 + patient.width_PATIENT <= 272)
                {
                    patient.pos_X = list_CARS[car_NUMBER].pos_X + 56;
                }

                //-----------------------------------------------------------------------------//
                //        ELSE PATIENT GOES AGAINST WALL AND MOE IS OFFSETED TO THE LEFT       //
                //-----------------------------------------------------------------------------//
                else
                {
                    patient.pos_X = 272 - patient.width_PATIENT;

                    list_CARS[car_NUMBER].pos_X = patient.pos_X - 56 - 8;
                }
            }

            //-----------------------------------------------------------------------------//
            //                                                                             //
            //                    PATIENT WILL BE OFFSETED TO THE LEFT                     //
            //                                                                             //
            //-----------------------------------------------------------------------------//
            else
            {
                //-----------------------------------------------------------------------------//
                //              IF THERE IS ENOUGH SPACE BETWEEN PATIENT AND WALL              //
                //-----------------------------------------------------------------------------//
                if(list_CARS[car_NUMBER].pos_X - patient.width_PATIENT >= 40)
                {
                    patient.pos_X = list_CARS[car_NUMBER].pos_X - patient.width_PATIENT;
                }

                //-----------------------------------------------------------------------------//
                //         ELSE PATIENT GOES AGAINST WALL AND MOE IS OFFSETED TO THE LEFT      //
                //-----------------------------------------------------------------------------//
                else
                {
                    patient.pos_X = 40;

                    list_CARS[car_NUMBER].pos_X = patient.pos_X + patient.width_PATIENT + 8;
                }
            }

            SPR_setPosition(list_CARS[car_NUMBER].spr_CAR , list_CARS[car_NUMBER].pos_X , 99);
            SPR_setPosition(patient.spr_PATIENT , patient.pos_X , patient.pos_Y );

            u8 random_pcm = random_NUMBER(0,1);
            XGM_startPlayPCM(TABLE_ID_PCM_DOCTORS_MINIGAME_CRASH[random_pcm],14,SOUND_PCM_CH3);
        }
    }
}




inline static void update_ACCELERATION()
{
    if(G_CAR_COUNTER_SPEED < MAX_COUNTER_SPEED_3)
    {
        G_CAR_COUNTER_SPEED += 1;

        if(G_CAR_COUNTER_SPEED == MAX_COUNTER_SPEED_2)
        {
            G_CAR_SPEED = KART_SPEED_2;

            XGM_startPlayPCM(SOUND_ENGINE_2 , 13 , SOUND_PCM_CH2 );
        }

        else if(G_CAR_COUNTER_SPEED == MAX_COUNTER_SPEED_3)
        {
            G_CAR_SPEED = KART_SPEED_3;

            XGM_startPlayPCM(SOUND_ENGINE_3 , 13 , SOUND_PCM_CH2 );
        }
    }
}


inline static void update_DECELERATION()
{
    if(G_CAR_COUNTER_SPEED > 0)
    {
        G_CAR_COUNTER_SPEED -= 1;

        if(G_CAR_COUNTER_SPEED == 0)
        {
            G_CAR_SPEED = KART_SPEED_1;

            XGM_startPlayPCM(SOUND_ENGINE_1 , 13 , SOUND_PCM_CH2 );
        }

        else if(G_CAR_COUNTER_SPEED == MAX_COUNTER_SPEED_2)
        {
            G_CAR_SPEED = KART_SPEED_2;

            XGM_startPlayPCM(SOUND_ENGINE_2 , 13 , SOUND_PCM_CH2 );
        }
    }
}




void joypad_DOCTORS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == DOCTORS_PHASE_RACING)
    {
        u16 value=JOY_readJoypad(JOY_1);

        //--------------------------------------------------------------//
        //                                                              //
        //                       NO JOYPAD INPUT                        //
        //                                                              //
        //--------------------------------------------------------------//

        if((value & BUTTON_DIR) == 0)
        {            
            u8 i;

            for(i=0 ; i<3 ; i++)
            {
                collisions_CAR(i);
            }




            if(G_CAR_COUNTER_SPEED < MAX_COUNTER_SPEED_2)
            {
                G_CAR_COUNTER_SPEED = 0;
            }

            else if(G_CAR_COUNTER_SPEED < MAX_COUNTER_SPEED_3)
            {
                G_CAR_COUNTER_SPEED = MAX_COUNTER_SPEED_2;
            }
            



            list_CARS[0].axis_CAR = AXIS_CENTER;

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);

            SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON LEFT                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_LEFT)
        {
            u8 i;

            for(i=0 ; i<3 ; i++)
            {
                collisions_CAR(i);
            }

            if(list_CARS[0].hit == FALSE)
            {
                if(list_CARS[0].pos_X > 40)
                {
                    if(list_CARS[0].pos_X - G_CAR_SPEED > 40)
                    {
                        list_CARS[0].axis_CAR = AXIS_LEFT;

                        list_CARS[0].pos_X -= G_CAR_SPEED;

                        SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                        SPR_setFrame(list_CARS[0].spr_CAR , AXIS_LEFT);
                    }

                    else
                    {
                        //G_CAR_COUNTER_SPEED = 0;

                        /*if(XGM_isPlayingPCM(SOUND_PCM_CH4) == 0)
                        {
                            //XGM_startPlayPCM(SOUND_TIRE , 15 , SOUND_PCM_CH4 );
                        }*/

                        //G_CAR_SPEED = 1;
                        
                        list_CARS[0].axis_CAR = AXIS_CENTER;

                        list_CARS[0].pos_X = 40;

                        SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                        SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
                    }
                }

                else
                {
                    //G_CAR_COUNTER_SPEED = 0;

                    /*if(XGM_isPlayingPCM(SOUND_PCM_CH4) == 0)
                    {
                        //XGM_startPlayPCM(SOUND_TIRE , 15 , SOUND_PCM_CH4 );
                    }*/

                    //G_CAR_SPEED = 1;
                    
                    list_CARS[0].axis_CAR = AXIS_CENTER;

                    SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                    SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
                }
            }


            if(value & BUTTON_UP)
            {
                /*G_CAR_COUNTER_SPEED += 1;

                if(G_CAR_COUNTER_SPEED > MAX_COUNTER_SPEED_2)
                {
                    G_CAR_COUNTER_SPEED = MAX_COUNTER_SPEED_2;

                    if(G_CAR_SPEED == 1)
                    {
                        XGM_startPlayPCM(SOUND_ENGINE_2 , 13 , SOUND_PCM_CH2 );
                        G_CAR_SPEED = 2;
                    }

                    else if(G_CAR_SPEED == 2)
                    {
                        XGM_startPlayPCM(SOUND_ENGINE_3 , 13 , SOUND_PCM_CH2 );
                        G_CAR_SPEED = 4;
                    }
                }*/
               update_ACCELERATION();
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON RIGHT                         //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_RIGHT)
        {
            u8 i;

            for(i=0 ; i<3 ; i++)
            {
                collisions_CAR(i);
            }

            if(list_CARS[0].hit == FALSE)
            {
                if(list_CARS[0].pos_X < 224)
                {
                    if(list_CARS[0].pos_X + G_CAR_SPEED < 224)
                    {
                        list_CARS[0].axis_CAR = AXIS_RIGHT;

                        list_CARS[0].pos_X += G_CAR_SPEED;

                        SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                        SPR_setFrame(list_CARS[0].spr_CAR , AXIS_RIGHT);
                    }

                    else
                    {
                        //G_CAR_COUNTER_SPEED = 0;

                        /*if(XGM_isPlayingPCM(SOUND_PCM_CH4) == 0)
                        {
                            //XGM_startPlayPCM(SOUND_TIRE , 15 , SOUND_PCM_CH4 );
                        }*/

                        //G_CAR_SPEED = 1;
                        
                        list_CARS[0].axis_CAR = AXIS_CENTER;

                        list_CARS[0].pos_X = 224;

                        SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                        SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
                    }
                }

                else
                {
                    //G_CAR_COUNTER_SPEED = 0;

                    /*if(XGM_isPlayingPCM(SOUND_PCM_CH4) == 0)
                    {
                        //XGM_startPlayPCM(SOUND_TIRE , 15 , SOUND_PCM_CH4 );
                    }*/

                    //G_CAR_SPEED = 1;
                    
                    list_CARS[0].axis_CAR = AXIS_CENTER;

                    SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                    SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
                }
            }


            if(value & BUTTON_UP)
            {
                /*G_CAR_COUNTER_SPEED += 1;

                if(G_CAR_COUNTER_SPEED > MAX_COUNTER_SPEED_2)
                {
                    G_CAR_COUNTER_SPEED = MAX_COUNTER_SPEED_2;

                    if(G_CAR_SPEED == 1)
                    {
                        XGM_startPlayPCM(SOUND_ENGINE_2 , 13 , SOUND_PCM_CH2 );
                        G_CAR_SPEED = 2;
                    }

                    else if(G_CAR_SPEED == 2)
                    {
                        XGM_startPlayPCM(SOUND_ENGINE_3 , 13 , SOUND_PCM_CH2 );
                        G_CAR_SPEED = 4;
                    }
                }*/
               update_ACCELERATION();
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON DOWN                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_DOWN)
        {
            /*if(G_CAR_SPEED != 1)
            {
                XGM_startPlayPCM(SOUND_ENGINE_1 , 13 , SOUND_PCM_CH2 );
            }*/
            
            u8 i;

            for(i=0 ; i<3 ; i++)
            {
                collisions_CAR(i);
            }




            update_DECELERATION();




            list_CARS[0].axis_CAR = AXIS_CENTER;

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
            
            
            list_CARS[0].axis_CAR = AXIS_CENTER;

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);

        }


        //--------------------------------------------------------------//
        //                                                              //
        //                          BUTTON UP                           //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_UP)
        {
            u8 i;

            for(i=0 ; i<3 ; i++)
            {
                collisions_CAR(i);
            }

            if(list_CARS[0].hit == FALSE && list_CARS[1].hit == FALSE && list_CARS[2].hit == FALSE)
            {
                /*G_CAR_COUNTER_SPEED += 1;

                if(G_CAR_COUNTER_SPEED > MAX_COUNTER_SPEED_2)
                {
                    G_CAR_COUNTER_SPEED = MAX_COUNTER_SPEED_2;

                    if(G_CAR_SPEED == 1)
                    {
                        XGM_startPlayPCM(SOUND_ENGINE_2 , 13 , SOUND_PCM_CH2 );
                        G_CAR_SPEED = 2;
                    }

                    else if(G_CAR_SPEED == 2)
                    {
                        XGM_startPlayPCM(SOUND_ENGINE_3 , 13 , SOUND_PCM_CH2 );
                        G_CAR_SPEED = 4;
                    }
                }*/

                update_ACCELERATION();
                
                list_CARS[0].axis_CAR = AXIS_CENTER;

                SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
            }
        }








        //-----------------------------------------------------------------------------//
        //                                                                             //
        //                        UPDATE CURLY AND LARRY'S CAR                         //
        //                                                                             //
        //-----------------------------------------------------------------------------//

        u8 i;

        for(i=1 ; i<3 ; i++)
        {
            //-----------------------------------------------------------------------------//
            //                READ MOE'S AXIS WITH A TIME OFFSET OF 8 FRAMES               //
            //-----------------------------------------------------------------------------//
            
            if(list_CARS[i].TABLE_AXIS[list_CARS[i].index_READ_AXIS] == AXIS_LEFT)
            {
                list_CARS[i].pos_X -= list_CARS[i].TABLE_SPEED[list_CARS[i].index_READ_AXIS];

                if(list_CARS[i].pos_X < 40)
                {
                    list_CARS[i].pos_X = 40;
                }
            }

            else if(list_CARS[i].TABLE_AXIS[list_CARS[i].index_READ_AXIS] == AXIS_RIGHT)
            {
                list_CARS[i].pos_X += list_CARS[i].TABLE_SPEED[list_CARS[i].index_READ_AXIS];

                if(list_CARS[i].pos_X > 224)
                {
                    list_CARS[i].pos_X = 224;
                }
            }

            else if(list_CARS[i].TABLE_AXIS[list_CARS[i].index_READ_AXIS] == AXIS_CENTER)
            {
                //-----------------------------------------------------------------------------//
                //                          IF CAR IS LEFT SIDE OF MOE                         //
                //-----------------------------------------------------------------------------//
                if(list_CARS[i].pos_X < list_CARS[0].pos_X)
                {
                    if((list_CARS[0].pos_X - list_CARS[i].pos_X) >= (list_CARS[i].TABLE_SPEED[list_CARS[i].index_READ_AXIS] >> 1))
                    {
                        list_CARS[i].pos_X += (list_CARS[i].TABLE_SPEED[list_CARS[i].index_READ_AXIS] >> 1);
                    }

                    else
                    {
                        list_CARS[i].pos_X = list_CARS[0].pos_X;
                    }


                    /////////////////////////////
                    /*if((list_CARS[0].pos_X - list_CARS[i].pos_X) == 1)
                    {
                        list_CARS[i].pos_X = list_CARS[0].pos_X;
                    }*/


                    if(list_CARS[i].pos_X > 224)
                    {
                        list_CARS[i].pos_X = 224;
                    }

                    else if(list_CARS[i].pos_X < 40)
                    {
                        list_CARS[i].pos_X = 40;
                    }
                }

                //-----------------------------------------------------------------------------//
                //                         IF CAR IS RIGHT SIDE OF MOE                         //
                //-----------------------------------------------------------------------------//
                else if(list_CARS[i].pos_X > list_CARS[0].pos_X)
                {
                    if((list_CARS[i].pos_X - list_CARS[0].pos_X) >= (list_CARS[i].TABLE_SPEED[list_CARS[i].index_READ_AXIS] >> 1))
                    {
                        list_CARS[i].pos_X -= (list_CARS[i].TABLE_SPEED[list_CARS[i].index_READ_AXIS] >> 1);
                    }

                    else
                    {
                        list_CARS[i].pos_X = list_CARS[0].pos_X;
                    }


                    /////////////////////////////
                    /*if((list_CARS[i].pos_X - list_CARS[0].pos_X) == 1)
                    {
                        list_CARS[i].pos_X = list_CARS[0].pos_X;
                    }*/


                    if(list_CARS[i].pos_X > 224)
                    {
                        list_CARS[i].pos_X = 224;
                    }

                    else if(list_CARS[i].pos_X < 40)
                    {
                        list_CARS[i].pos_X = 40;
                    }
                }
            }




            SPR_setPosition(list_CARS[i].spr_CAR , list_CARS[i].pos_X , list_CARS[i].pos_Y);

            SPR_setFrame(list_CARS[i].spr_CAR , list_CARS[i].TABLE_AXIS[list_CARS[i].index_READ_AXIS]);




            //-----------------------------------------------------------------------------//
            //                             INCREASE READ INDEX                             //
            //-----------------------------------------------------------------------------//        
            list_CARS[i].index_READ_AXIS += 1;

            if(list_CARS[i].index_READ_AXIS > 16)
            {
                list_CARS[i].index_READ_AXIS = 0;
            }


            //-----------------------------------------------------------------------------//
            //                             READ NEXT AXIS VALUE                            //
            //-----------------------------------------------------------------------------// 
            list_CARS[i].TABLE_AXIS[list_CARS[i].index_WRITE_AXIS]  = list_CARS[0].axis_CAR;
            list_CARS[i].TABLE_SPEED[list_CARS[i].index_WRITE_AXIS] = G_CAR_SPEED;



            //-----------------------------------------------------------------------------//
            //                            INCREASE WRITE INDEX                             //
            //-----------------------------------------------------------------------------//
            list_CARS[i].index_WRITE_AXIS += 1;

            if(list_CARS[i].index_WRITE_AXIS > 16)
            {
                list_CARS[i].index_WRITE_AXIS = 0;
            }
        }


        list_CARS[0].hit = FALSE;
        list_CARS[1].hit = FALSE;
        list_CARS[2].hit = FALSE;
    }
}







inline static void counter_TIME_DOCTORS()
{
    if(G_COUNTER_1 == 72)
    {
        G_COUNTER_1 = 0;

        if(G_COUNTER_DOCTORS > 0)
        {
            G_COUNTER_DOCTORS -= 1;

            if(G_COUNTER_DOCTORS > 9)
            {
                VDP_drawIntEx_BG_A_QUEUE(G_COUNTER_DOCTORS , 2 , 8 , 26 , PAL1);
            }

            else
            {
                VDP_drawIntEx_BG_A_QUEUE(G_COUNTER_DOCTORS , 1 , 9 , 26 , PAL1);
                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, 8), 8, 26,  0,  0, 1, 1, DMA_QUEUE);
            }
        }

        return;    
    }
    
    G_COUNTER_1 += 1;
}


inline static void counter_REWARD_DOCTORS()
{
    if(G_REWARD < 100)
    {
        VDP_drawIntEx_BG_A_QUEUE(G_REWARD , 2 , 3 , 26 , PAL1);
    }

    else if(G_REWARD < 1000)
    {
        VDP_drawIntEx_BG_A_QUEUE(G_REWARD , 3 , 3 , 26 , PAL1);
    }    

    else
    {
        VDP_drawIntEx_BG_A_QUEUE(G_REWARD , 4 , 3 , 26 , PAL1);
    }  
}








inline static void anim_NURSE()
{
    if(nurse.axis_NURSE == AXIS_RIGHT)
    {
        //-------------------------------------------------------//
        //             INCREASE SPRITE FRAME COUNTER             //
        //-------------------------------------------------------//
        nurse.counter_SPRITE_FRAME += 1;
        
        //-------------------------------------------------------//
        //               UPDATE NURSE SPRITE FRAME               //
        //-------------------------------------------------------//
        if(nurse.counter_SPRITE_FRAME == 7)
        {
            //-------------------------------------------------------//
            //           INCREASE NURSE SPRITE FRAME INDEX           //
            //-------------------------------------------------------//            
            nurse.index_SPRITE_FRAME += 1;

            //-------------------------------------------------------//
            //            IF NURSE SPRITE FRAME INDEX == 4           //
            //            REINIT NURSE SPRITE FRAME INDEX            //
            //-------------------------------------------------------//   
            if(nurse.index_SPRITE_FRAME == 4)
            {
                nurse.index_SPRITE_FRAME = 0;
            }


            //-------------------------------------------------------//
            //                SET NURSE SPRITE FRAME                 //
            //-------------------------------------------------------//
            SPR_setFrame(nurse.spr_NURSE , nurse.index_SPRITE_FRAME);

            //-------------------------------------------------------//
            //              REINIT SPRITE FRAME COUNTER              //
            //-------------------------------------------------------//
            nurse.counter_SPRITE_FRAME = 0;




            //-------------------------------------------------------//
            //                 UPDATE NURSE POSITION                 //
            //-------------------------------------------------------//
            //-------------------------------------------------------//
            //                  READ NURSE VELOCITY                  //
            //-------------------------------------------------------//
            u8 nurse_VELOCITY = TABLE_NURSE_VELOCITY[nurse.index_SPRITE_FRAME];


            //-------------------------------------------------------//
            //                 CHANGE NURSE POSITION                 //
            //-------------------------------------------------------//
            //-------------------------------------------------------//
            //           NURSE SPRITE IS 64 PIXELS IN HEIGHT         //
            //           ITS Y POSITION = 10 : 64+10 = 74            //
            //-------------------------------------------------------//
            //-------------------------------------------------------//
            //               IF PATIENT IS ABOVE NURSE               //
            //-------------------------------------------------------//
            if(patient.pos_Y < 74)
            {
                //-------------------------------------------------------//
                //            IF NURSE IS LEFT SIDE OF PATIENT           //
                //-------------------------------------------------------//
                if(nurse.pos_X < (patient.pos_X + (patient.width_PATIENT >> 1)))
                {
                    //-----------------------------------------------------------------------------------//
                    //  IF DISTANCE BETWEEN THE 2 SPRITES IS LESS THAN NURSE SPRITE WIDTH/2 (24 PIXELS)  //
                    //-----------------------------------------------------------------------------------//
                    if(patient.pos_X - nurse.pos_X < 48 + 24)
                    {
                        //-------------------------------------------------------//
                        //                 NURSE GOES TO THE LEFT                //
                        //-------------------------------------------------------//
                        if( (nurse.pos_X - nurse_VELOCITY) < 44)
                        {
                            nurse.pos_X = 44;

                            nurse.axis_NURSE = AXIS_RIGHT;
                        }

                        else
                        {
                            nurse.pos_X -= nurse_VELOCITY;

                            nurse.axis_NURSE = AXIS_LEFT;
                        }
                    }

                    //-------------------------------------------------------//
                    //                 NURSE GOES TO THE RIGHT               //
                    //-------------------------------------------------------//
                    else
                    {
                        if( (nurse.pos_X + nurse_VELOCITY) > 227)
                        {
                            nurse.pos_X = 227;

                            nurse.axis_NURSE = AXIS_LEFT;
                        }

                        else
                        {
                            nurse.pos_X += nurse_VELOCITY;

                            nurse.axis_NURSE = AXIS_RIGHT;
                        }
                    }
                }

                //-------------------------------------------------------//
                //            IF NURSE IS RIGHT SIDE OF PATIENT          //
                //-------------------------------------------------------//
                else
                {
                    //-------------------------------------------------------//
                    //                 NURSE GOES TO THE RIGHT               //
                    //-------------------------------------------------------//
                    if( (nurse.pos_X + nurse_VELOCITY) > 227)
                    {
                        nurse.pos_X = 227;

                        nurse.axis_NURSE = AXIS_LEFT;
                    }

                    else
                    {
                        nurse.pos_X += nurse_VELOCITY;

                        nurse.axis_NURSE = AXIS_RIGHT;
                    }
                }
            }


            //-------------------------------------------------------//
            //               IF PATIENT IS UNDER NURSE               //
            //-------------------------------------------------------//
            else
            {
                if( (nurse.pos_X + nurse_VELOCITY) > 227)
                {
                    nurse.pos_X = 227;

                    nurse.axis_NURSE = AXIS_LEFT;
                }

                else
                {
                    nurse.pos_X += nurse_VELOCITY;

                    nurse.axis_NURSE = AXIS_RIGHT;
                }
            }
            

            SPR_setPosition(nurse.spr_NURSE , nurse.pos_X , nurse.pos_Y);
        }
    }


    else if(nurse.axis_NURSE == AXIS_LEFT)
    {
        //-------------------------------------------------------//
        //             INCREASE SPRITE FRAME COUNTER             //
        //-------------------------------------------------------//
        nurse.counter_SPRITE_FRAME += 1;

        //-------------------------------------------------------//
        //               UPDATE NURSE SPRITE FRAME               //
        //-------------------------------------------------------//        
        if(nurse.counter_SPRITE_FRAME == 7)
        {
            //-------------------------------------------------------//
            //           INCREASE NURSE SPRITE FRAME INDEX           //
            //-------------------------------------------------------//               
            nurse.index_SPRITE_FRAME += 1;

            //-------------------------------------------------------//
            //            IF NURSE SPRITE FRAME INDEX == 4           //
            //            REINIT NURSE SPRITE FRAME INDEX            //
            //-------------------------------------------------------//  
            if(nurse.index_SPRITE_FRAME == 4)
            {
                nurse.index_SPRITE_FRAME = 0;
            }


            //-------------------------------------------------------//
            //                SET NURSE SPRITE FRAME                 //
            //-------------------------------------------------------//
            SPR_setFrame(nurse.spr_NURSE , nurse.index_SPRITE_FRAME);

            //-------------------------------------------------------//
            //              REINIT SPRITE FRAME COUNTER              //
            //-------------------------------------------------------//
            nurse.counter_SPRITE_FRAME = 0;




            //-------------------------------------------------------//
            //                 UPDATE NURSE POSITION                 //
            //-------------------------------------------------------//
            //-------------------------------------------------------//
            //                  READ NURSE VELOCITY                  //
            //-------------------------------------------------------//
            u8 nurse_VELOCITY = TABLE_NURSE_VELOCITY[nurse.index_SPRITE_FRAME];


            //-------------------------------------------------------//
            //                 CHANGE NURSE POSITION                 //
            //-------------------------------------------------------//
            //-------------------------------------------------------//
            //           NURSE SPRITE IS 64 PIXELS IN HEIGHT         //
            //           ITS Y POSITION = 10 : 64+10 = 74            //
            //-------------------------------------------------------//
            //-------------------------------------------------------//
            //               IF PATIENT IS ABOVE NURSE               //
            //-------------------------------------------------------//
            if(patient.pos_Y < 74)
            {
                //-------------------------------------------------------//
                //            IF NURSE IS RIGHT SIDE OF PATIENT          //
                //-------------------------------------------------------//
                if(nurse.pos_X > (patient.pos_X + (patient.width_PATIENT >> 1)))
                {
                    //-----------------------------------------------------------------------------------//
                    //        IF DISTANCE BETWEEN THE 2 SPRITES IS LESS THAN PATIENT SPRITE WIDTH/2      //
                    //-----------------------------------------------------------------------------------//
                    if(nurse.pos_X - patient.pos_X < (patient.width_PATIENT))
                    {
                        //-------------------------------------------------------//
                        //                 NURSE GOES TO THE RIGHT               //
                        //-------------------------------------------------------//
                        if( (nurse.pos_X + nurse_VELOCITY) > 227)
                        {
                            nurse.pos_X = 227;

                            nurse.axis_NURSE = AXIS_LEFT;
                        }

                        else
                        {
                            nurse.pos_X += nurse_VELOCITY;

                            nurse.axis_NURSE = AXIS_RIGHT;
                        }
                    }

                    //-------------------------------------------------------//
                    //                 NURSE GOES TO THE LEFT                //
                    //-------------------------------------------------------//
                    else
                    {
                        if( (nurse.pos_X - nurse_VELOCITY) < 44)
                        {
                            nurse.pos_X = 44;

                            nurse.axis_NURSE = AXIS_RIGHT;
                        }

                        else
                        {
                            nurse.pos_X -= nurse_VELOCITY;

                            nurse.axis_NURSE = AXIS_LEFT;
                        }
                    }
                }

                //-------------------------------------------------------//
                //            IF NURSE IS LEFT SIDE OF PATIENT           //
                //-------------------------------------------------------//
                else
                {
                    //-------------------------------------------------------//
                    //                 NURSE GOES TO THE LEFT                //
                    //-------------------------------------------------------//
                    if( (nurse.pos_X - nurse_VELOCITY) < 44)
                    {
                        nurse.pos_X = 44;

                        nurse.axis_NURSE = AXIS_RIGHT;
                    }

                    else
                    {
                        nurse.pos_X -= nurse_VELOCITY;

                        nurse.axis_NURSE = AXIS_LEFT;
                    }
                }
            }


            //-------------------------------------------------------//
            //               IF PATIENT IS UNDER NURSE               //
            //-------------------------------------------------------//
            else
            {
                if( (nurse.pos_X - nurse_VELOCITY) < 44)
                {
                    nurse.pos_X = 44;

                    nurse.axis_NURSE = AXIS_RIGHT;
                }

                else
                {
                    nurse.pos_X -= nurse_VELOCITY;

                    nurse.axis_NURSE = AXIS_LEFT;
                }
            }


            SPR_setPosition(nurse.spr_NURSE , nurse.pos_X , nurse.pos_Y);
        }
    }
}








inline static void spawn_ITEM()
{
    if(nurse.counter_ITEM == 36)
    {
        nurse.counter_ITEM = 0;

        u8 i;

        for(i=0 ; i<2 ; i++)
        {
            if(list_ITEM[i].spr_ITEM == NULL)
            {
                list_ITEM[i].reward_ITEM = TABLE_ITEM_TYPE[nurse.index_ITEM].reward_ITEM;

                if(nurse.pos_X > 160)
                {
                    list_ITEM[i].axis_ITEM = AXIS_LEFT;

                    list_ITEM[i].pos_X = nurse.pos_X - 24;
                }

                else
                {
                    list_ITEM[i].axis_ITEM = AXIS_RIGHT;

                    list_ITEM[i].pos_X = nurse.pos_X  + 40;
                }


                list_ITEM[i].pos_Y = 32;

                list_ITEM[i].counter_FRAME = 0;
                list_ITEM[i].index_FRAME = 0;

                list_ITEM[i].spr_ITEM = SPR_addSprite(TABLE_ITEM_TYPE[nurse.index_ITEM].tiles_ITEM , list_ITEM[i].pos_X , list_ITEM[i].pos_Y , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));

                SPR_setAnimAndFrame(list_ITEM[i].spr_ITEM , list_ITEM[i].axis_ITEM - 1 , 0);


                nurse.index_ITEM += 1;

                if(nurse.index_ITEM == 3)
                {
                    nurse.index_ITEM = 0;
                }


                return;
            }
        }

        return;
    }

    nurse.counter_ITEM += 1;
}


inline static void collisions_ITEMS()
{
    u8 i;
    u8 j;


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                               COLLISION CHECK WITH CARS                              //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    for(i=0 ; i<2 ; i++)
    {
        if(list_ITEM[i].spr_ITEM != NULL)
        {
            for(j=0 ; j<3 ; j++)
            {
                if(list_ITEM[i].pos_X >= (list_CARS[j].pos_X + 8))
                {
                    if(list_ITEM[i].pos_X <= (list_CARS[j].pos_X + 40 ))
                    {
                        if(list_ITEM[i].pos_Y >= list_CARS[j].pos_Y)
                        {
                            if(list_ITEM[i].pos_Y <= (list_CARS[j].pos_Y + 40))
                            {
                                G_REWARD += list_ITEM[i].reward_ITEM;

                                counter_REWARD_DOCTORS();
                                
                                SPR_releaseSprite(list_ITEM[i].spr_ITEM);
                                list_ITEM[i].spr_ITEM = NULL;

                                u8 random_pcm = random_NUMBER(0,3);
                                XGM_startPlayPCM(TABLE_ID_PCM_DOCTORS_MINIGAME_CRY[random_pcm],14,SOUND_PCM_CH4);

                                return;
                            }
                        }
                    }
                }
            }
        }
    } 
}


inline static void anim_ITEM()
{
    collisions_ITEMS();
    
    u8 i;


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                             POSITION AND FRAME ANIMATIONS                            //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    for(i=0 ; i<2 ; i++)
    {
        if(list_ITEM[i].spr_ITEM != NULL)
        {
            if(list_ITEM[i].pos_Y < 224)
            {
                if(list_ITEM[i].axis_ITEM == AXIS_LEFT)
                {
                    if(list_ITEM[i].pos_X - 3 > 44)
                    {
                        list_ITEM[i].pos_X -= 3;
                    }

                    else
                    {
                        list_ITEM[i].pos_X = 44;

                        list_ITEM[i].axis_ITEM = AXIS_RIGHT;
                    }
                }

            
                else if(list_ITEM[i].axis_ITEM == AXIS_RIGHT)
                {
                    if(list_ITEM[i].pos_X + 3 < 256)
                    {
                        list_ITEM[i].pos_X += 3;
                    }

                    else
                    {
                        list_ITEM[i].pos_X = 256;

                        list_ITEM[i].axis_ITEM = AXIS_LEFT;
                    }
                }

                list_ITEM[i].pos_Y += 3;
                list_ITEM[i].pos_Y += G_CAR_SPEED;

                SPR_setPosition(list_ITEM[i].spr_ITEM , list_ITEM[i].pos_X , list_ITEM[i].pos_Y );



                list_ITEM[i].counter_FRAME += 1;

                if(list_ITEM[i].counter_FRAME == 4)
                {
                    list_ITEM[i].counter_FRAME = 0;

                    list_ITEM[i].index_FRAME += 1;

                    if(list_ITEM[i].index_FRAME == 16)
                    {
                        list_ITEM[i].index_FRAME = 0;
                    }
                }

                SPR_setAnimAndFrame(list_ITEM[i].spr_ITEM , list_ITEM[i].axis_ITEM - 1 , list_ITEM[i].index_FRAME);
            }




            else
            {
                SPR_releaseSprite(list_ITEM[i].spr_ITEM);
                list_ITEM[i].spr_ITEM = NULL;
            }            
        }
    }
}








inline static void spawn_PATIENT()
{
    if(patient.spr_PATIENT == NULL)
    {
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                               GENERATE RANDOM PATIENT                                //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        u8 random_patient_type;
        
        G_RANDOM_OK = FALSE;

        while(G_RANDOM_OK == FALSE)
        {
            u8 new_patient_type = random_NUMBER(0,3);

            // WE MAKE SURE NEW PATIENT IS DIFFERENT FROM THE PREVIOUS ONE //
            if(new_patient_type != G_PREVIOUS_PATIENT_TYPE)
            {
                random_patient_type = new_patient_type;

                G_PREVIOUS_PATIENT_TYPE = random_patient_type;
                
                G_RANDOM_OK = TRUE;
            }
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              ASSIGN PATIENT PROPERTIES                               //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        patient.pos_Y                = (TABLE_PATIENT_TYPE[random_patient_type].height_PATIENT * -1);// -128;

        patient.counter_SPRITE_FRAME = 0;
        patient.index_SPRITE_FRAME   = 0;

        patient.number_STEPS         = TABLE_PATIENT_TYPE[random_patient_type].number_STEPS;
        patient.number_STEPS_HIT     = TABLE_PATIENT_TYPE[random_patient_type].number_STEPS_HIT;
        patient.speed_STEPS          = TABLE_PATIENT_TYPE[random_patient_type].speed_STEPS;

        patient.width_PATIENT        = TABLE_PATIENT_TYPE[random_patient_type].width_PATIENT;
        patient.height_PATIENT       = TABLE_PATIENT_TYPE[random_patient_type].height_PATIENT;

        patient.patient_STATE        = PATIENT_NOT_HIT;

        patient.ptr_VELOCITY         = &TABLE_PATIENT_TYPE[random_patient_type].ptr_VELOCITY[0];


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                             GENERATE RANDOM X POSITION                               //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
        
        G_RANDOM_OK = FALSE;

        while(G_RANDOM_OK == FALSE)
        {
            u16 random_patient_pos_x;
            
            if(nurse.pos_X < 136)
            {
                random_patient_pos_x = random_NUMBER(6,10);
            }

            else
            {
                random_patient_pos_x = random_NUMBER(0,5);
            }
            
            s16 new_pos_X = TABLE_PATIENT_SPAWN_POSITION[random_patient_pos_x];

            // IF SELECTED X POSITION IS ON THE NURSE LEFT SIDE //
            if(new_pos_X < nurse.pos_X)
            {
                // CHECK IF SPACE BETWEEN NURSE AND PATIENT NEW POSITION IS BIGGER THAN PATIENT WIDTH //
                // SO PATIENT SPRITE HAS ENOUGH SPACE TO FIT BETWEEN LEFT WALL AND NURSE //
                if( (nurse.pos_X - new_pos_X) > patient.width_PATIENT )
                {
                    patient.pos_X = new_pos_X;

                    G_RANDOM_OK = TRUE;
                }
                
            }

            // IF SELECTED X POSITION IS ON THE NURSE RIGHT SIDE //
            else if(new_pos_X > nurse.pos_X)
            {
                // CHECK IF SPACE BETWEEN NURSE AND PATIENT NEW POSITION IS BIGGER THAN NURSE WIDTH //
                // SO PATIENT SPRITE HAS ENOUGH SPACE TO FIT BETWEEN RIGHT WALL AND NURSE //
                // NURSE IS 48 PIXELS WIDTH //
                if( (new_pos_X - nurse.pos_X) > 48 )
                {
                    patient.pos_X = new_pos_X;

                    G_RANDOM_OK = TRUE;
                }
            }
        }

        
        patient.spr_PATIENT          = SPR_addSprite(TABLE_PATIENT_TYPE[random_patient_type].tiles_PATIENT_TYPE , patient.pos_X , patient.pos_Y , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
    }
}


inline static void anim_PATIENT()
{
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                               IF PATIENT SPRITE EXISTS                               //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    if(patient.spr_PATIENT != NULL)
    {
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //              IF PATIENT SPRITE REACHES BOTTOM OF SCREEN : REMOVE SPRITE              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
        
        if(patient.pos_Y >= 224)
        {
            SPR_releaseSprite(patient.spr_PATIENT);
            patient.spr_PATIENT = NULL;
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                       ELSE IF PATIENT SPRITE IS STILL ON SCREEN                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        else
        {
            //-------------------------------------------------------//
            //          MOVE PATIENT ACCORDING TO SCROLLING          //
            //-------------------------------------------------------//
            patient.pos_Y += G_CAR_SPEED;
            
            //-------------------------------------------------------//
            //              INCREASE FRAME COUNTER BY 1              //
            //-------------------------------------------------------//
            patient.counter_SPRITE_FRAME += 1;


            //-------------------------------------------------------//
            //              IF PATIENT HAS NOT BEEN HIT              //
            //-------------------------------------------------------//
            if(patient.patient_STATE == PATIENT_NOT_HIT)
            {

                //-------------------------------------------------------//
                //         IF FRAME COUNTER REACHES TRIGGER VALUE        //
                //-------------------------------------------------------//
                if(patient.counter_SPRITE_FRAME == patient.speed_STEPS)
                {
                    //-------------------------------------------------------//
                    //              REINIT SPRITE FRAME COUNTER              //
                    //-------------------------------------------------------//
                    patient.counter_SPRITE_FRAME = 0;

                    //-------------------------------------------------------//
                    //               INCREASE FRAME INDEX BY 1               //
                    //-------------------------------------------------------//
                    patient.index_SPRITE_FRAME += 1;

                    //-------------------------------------------------------//
                    //              REINIT FRAME INDEX IF NEEDED             //
                    //-------------------------------------------------------//
                    if(patient.index_SPRITE_FRAME == patient.number_STEPS)
                    {
                        patient.index_SPRITE_FRAME = 0;
                    }


                    //-------------------------------------------------------//
                    //                  UPDATE SPRITE FRAME                  //
                    //-------------------------------------------------------//
                    SPR_setAnimAndFrame(patient.spr_PATIENT , patient.patient_STATE , patient.index_SPRITE_FRAME);
                    

                    //-------------------------------------------------------//
                    //                   PATIENT OWN SPEED                   //
                    //-------------------------------------------------------//
                    patient.pos_Y -= patient.ptr_VELOCITY[patient.index_SPRITE_FRAME];
                }
            }


            //-------------------------------------------------------//
            //                IF PATIENT HAS BEEN HIT                //
            //-------------------------------------------------------//
            else
            {
                //-------------------------------------------------------//
                //         IF FRAME COUNTER REACHES TRIGGER VALUE        //
                //-------------------------------------------------------//
                if(patient.counter_SPRITE_FRAME == patient.speed_STEPS)
                {
                    //-------------------------------------------------------//
                    //              REINIT SPRITE FRAME COUNTER              //
                    //-------------------------------------------------------//
                    patient.counter_SPRITE_FRAME = 0;

                    //-------------------------------------------------------//
                    //               INCREASE FRAME INDEX BY 1               //
                    //-------------------------------------------------------//
                    patient.index_SPRITE_FRAME += 1;

                    //-------------------------------------------------------//
                    //              REINIT FRAME INDEX IF NEEDED             //
                    //-------------------------------------------------------//
                    if(patient.index_SPRITE_FRAME == patient.number_STEPS_HIT)
                    {
                        patient.index_SPRITE_FRAME = 0;
                    }


                    //-------------------------------------------------------//
                    //                  UPDATE SPRITE FRAME                  //
                    //-------------------------------------------------------//
                    SPR_setAnimAndFrame(patient.spr_PATIENT , patient.patient_STATE , patient.index_SPRITE_FRAME);
                    
                }
            }


            //-------------------------------------------------------//
            //                 UPDATE SPRITE POSITION                //
            //-------------------------------------------------------//
            SPR_setPosition(patient.spr_PATIENT , patient.pos_X , patient.pos_Y);
        }
    }
}








void sequence_DOCTORS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == DOCTORS_PHASE_RACING)
    {
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       SCROLLING                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
        
        G_POS_Y_CAMERA += G_CAR_SPEED;

        if(G_POS_Y_CAMERA >= 16556)
        {
            G_POS_Y_CAMERA = 16556;
            
            G_PHASE_SEQUENCE = DOCTORS_PHASE_EXIT;
        }



        
        VDP_setVerticalScrollVSync(BG_B , -G_POS_Y_CAMERA);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         NURSE                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        anim_NURSE();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        PATIENT                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        anim_PATIENT();

        anim_ITEM();


        if(G_POS_Y_CAMERA < 16000)
        {
            spawn_PATIENT();
        }
        
        if(G_POS_Y_CAMERA < 16380)
        {
            spawn_ITEM();
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        COUNTER                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        counter_TIME_DOCTORS();


        if(G_HIT_NUMBER == 5)
        {
            G_PHASE_SEQUENCE = DOCTORS_PHASE_GAME_OVER;

            XGM_stopPlayPCM(SOUND_PCM_CH2);
        }

        else
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         AUDIO                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            //--------------------------------------------------------------------------------------//
            //                                     ENGINE SOUND                                     //
            //--------------------------------------------------------------------------------------//
            if(XGM_isPlayingPCM(SOUND_PCM_CH2_MSK) == 0)
            {
                if(G_CAR_SPEED == 1)
                {
                    XGM_startPlayPCM(SOUND_ENGINE_1 , 13 , SOUND_PCM_CH2 );
                }

                else if(G_CAR_SPEED == 2)
                {
                    XGM_startPlayPCM(SOUND_ENGINE_2 , 13 , SOUND_PCM_CH2 );
                }

                else if(G_CAR_SPEED == 4)
                {
                    XGM_startPlayPCM(SOUND_ENGINE_3 , 13 , SOUND_PCM_CH2 );
                }
            }
        }
    }

    
    else if(G_PHASE_SEQUENCE == DOCTORS_PHASE_EXIT)
    {
        //--------------------------------------------------------------//
        //                                                              //
        //                 MOVE NURSE AND CARS VERTICALY                //
        //                                                              //
        //--------------------------------------------------------------//

        if(G_POS_Y_CAMERA >= 16808)
        {
            if(list_CARS[0].pos_Y > -48)
            {
                list_CARS[0].pos_Y -= G_CAR_SPEED;
            }

            if(list_CARS[1].pos_Y > -48)
            {
                list_CARS[1].pos_Y -= G_CAR_SPEED;
            }

            if(list_CARS[2].pos_Y > -48)
            {
                list_CARS[2].pos_Y -= G_CAR_SPEED;
            }

            if(nurse.pos_Y > -64)
            {
                nurse.pos_Y -= G_CAR_SPEED;
            }
        }


        if(nurse.pos_X < 136)
        {
            if((136 - nurse.pos_X) > 4)
            {
                nurse.pos_X += 2;
            }

            else
            {
                nurse.pos_X = 136;
            }
        }

        else if(nurse.pos_X > 136)
        {
            if((nurse.pos_X - 136) > 4)
            {
                nurse.pos_X -= 2;
            }

            else
            {
                nurse.pos_X = 136;
            }
        }

        SPR_setPosition(nurse.spr_NURSE , nurse.pos_X , nurse.pos_Y);
        

        //--------------------------------------------------------------//
        //                                                              //
        //                      UPDATE NURSE FRAME                      //
        //                                                              //
        //--------------------------------------------------------------//

        nurse.counter_SPRITE_FRAME += 1;
        
        if(nurse.counter_SPRITE_FRAME == 7)
        {
            
            nurse.index_SPRITE_FRAME += 1;

            // REINIT FRAME INDEX //
            if(nurse.index_SPRITE_FRAME == 4)
            {
                nurse.index_SPRITE_FRAME = 0;
            }

            // SET NURSE FRAME //
            SPR_setFrame(nurse.spr_NURSE , nurse.index_SPRITE_FRAME);

            // REINIT FRAME COUNTER //
            nurse.counter_SPRITE_FRAME = 0;       
        }



        
        //--------------------------------------------------------------//
        //                                                              //
        //                        RECENTER CARS                         //
        //                                                              //
        //--------------------------------------------------------------//

        u8 i;

        for(i=0 ; i<3 ; i++)
        {
            if(list_CARS[i].pos_X < 136)
            {
                if(136 - list_CARS[i].pos_X >= G_CAR_SPEED)
                {
                    list_CARS[i].pos_X += G_CAR_SPEED;

                    

                    SPR_setFrame(list_CARS[i].spr_CAR , AXIS_RIGHT);
                }

                else
                {
                    list_CARS[i].pos_X = 136;

                    list_CARS[i].axis_CAR = AXIS_CENTER;

                    SPR_setFrame(list_CARS[i].spr_CAR , AXIS_CENTER);
                }
                
                SPR_setPosition(list_CARS[i].spr_CAR , list_CARS[i].pos_X , list_CARS[i].pos_Y);
            }

            else if(list_CARS[i].pos_X > 136)
            {
                if(list_CARS[i].pos_X - 136 >= G_CAR_SPEED)
                {
                    list_CARS[i].pos_X -= G_CAR_SPEED;

                    list_CARS[i].axis_CAR = AXIS_LEFT;

                    SPR_setFrame(list_CARS[i].spr_CAR , AXIS_LEFT);
                }
                
                else
                {
                    list_CARS[i].pos_X = 136;

                    list_CARS[i].axis_CAR = AXIS_CENTER;

                    SPR_setFrame(list_CARS[i].spr_CAR , AXIS_CENTER);
                }            

                SPR_setPosition(list_CARS[i].spr_CAR , list_CARS[0].pos_X , list_CARS[i].pos_Y);
            }

            else if(list_CARS[i].pos_X == 136)
            {
                list_CARS[i].axis_CAR = AXIS_CENTER;

                SPR_setPosition(list_CARS[i].spr_CAR , list_CARS[i].pos_X , list_CARS[i].pos_Y);

                SPR_setFrame(list_CARS[i].spr_CAR , AXIS_CENTER);
            }
        }



        
        //--------------------------------------------------------------//
        //                                                              //
        //                           SCROLLING                          //
        //                                                              //
        //--------------------------------------------------------------//
        
        G_POS_Y_CAMERA += G_CAR_SPEED;
        

        if(G_POS_Y_CAMERA > 16765 && G_POS_Y_CAMERA < 16769)
        {
            if(patient.spr_PATIENT != NULL)
            {
                SPR_releaseSprite(patient.spr_PATIENT);
                patient.spr_PATIENT = NULL;
            }
            
            VDP_setTileMapEx(BG_B, image_DOCTORS_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_DOCTORS_BG_B1.tileset->numTile), 0, 11, 0, 0, 40, 5, DMA_QUEUE);
        }
        
        if(G_POS_Y_CAMERA < 16809)
        {
            VDP_setVerticalScrollVSync(BG_B , -G_POS_Y_CAMERA);
        }

        if(G_POS_Y_CAMERA < 17060)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         AUDIO                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            //--------------------------------------------------------------------------------------//
            //                                     ENGINE SOUND                                     //
            //--------------------------------------------------------------------------------------//
            if(XGM_isPlayingPCM(SOUND_PCM_CH2_MSK) == 0)
            {
                if(G_CAR_SPEED == 1)
                {
                    XGM_startPlayPCM(SOUND_ENGINE_1 , 13 , SOUND_PCM_CH2 );
                }

                else if(G_CAR_SPEED == 2)
                {
                    XGM_startPlayPCM(SOUND_ENGINE_2 , 13 , SOUND_PCM_CH2 );
                }

                else if(G_CAR_SPEED == 4)
                {
                    XGM_startPlayPCM(SOUND_ENGINE_3 , 13 , SOUND_PCM_CH2 );
                }
            }
        }

        if(G_POS_Y_CAMERA == 17060)
        {
            XGM_stopPlayPCM(SOUND_PCM_CH2);
            
            XGM_startPlayPCM(SOUND_DOCTORS_CRASH_3,15,SOUND_PCM_CH4);
        }

        if(G_POS_Y_CAMERA >= 17240)
        {
            G_COUNTER_1 = 0;

            // 15 DOLLARS REWARD PER REMAINING SECOND //
            G_REWARD += (G_COUNTER_DOCTORS * 15);
            
            G_PHASE_SEQUENCE = DOCTORS_PHASE_GAME_OVER;
        }




    }


    else if(G_PHASE_SEQUENCE == DOCTORS_PHASE_GAME_OVER)
    {
        G_COUNTER_1 += 1;

        // REACHED THE OPERATION THEATRE //
        if(G_HIT_NUMBER != 5)
        {
            if(G_COUNTER_1 == 240)
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

                G_CRACKERS_INIT             = FALSE;
                G_CRACKERS_SCREEN_TYPE      = CRACKERS_SCREEN_SPREAD;

                G_NUMBER_CRACKERS_MAX       = 14;
                G_NUMBER_CRACKERS           = 14;
                G_NUMBER_GRABBED_CRACKERS   = 14;



                G_SCENE         = SCENE_FADE_IN;
                G_SCENE_TYPE    = SCENE_REWARD;
                G_SCENE_NEXT    = SCENE_REWARD;

                G_SCENE_LOADED  = FALSE;

                return;
            }
        }

        // HIT 5 PATIENTS //
        else
        {
            if(G_COUNTER_1 == 240)
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

                G_CRACKERS_INIT             = FALSE;
                G_CRACKERS_SCREEN_TYPE      = CRACKERS_SCREEN_SPREAD;

                G_NUMBER_CRACKERS_MAX       = 14;
                G_NUMBER_CRACKERS           = 14;
                G_NUMBER_GRABBED_CRACKERS   = 14;



                G_SCENE         = SCENE_FADE_IN;
                G_SCENE_TYPE    = SCENE_REWARD;
                G_SCENE_NEXT    = SCENE_REWARD;

                G_SCENE_LOADED  = FALSE;

                return;
            }
        }
    }
    
}

