#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"




#include "maps_DOCTORS.h"
#include "maps_GLOBAL.h"




#include "tables_DOCTORS.h"




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
            //G_CAR_SPEED = 2;
            
            list_CARS[0].axis_CAR = AXIS_CENTER;

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON LEFT                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_LEFT)
        {
            if(list_CARS[0].pos_X > 40)
            {
                list_CARS[0].axis_CAR = AXIS_LEFT;

                list_CARS[0].pos_X -= 2;

                SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                SPR_setFrame(list_CARS[0].spr_CAR , AXIS_LEFT);
            }

            else
            {
                list_CARS[0].axis_CAR = AXIS_CENTER;

                SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON RIGHT                         //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_RIGHT)
        {
            if(list_CARS[0].pos_X < 224)
            {
                list_CARS[0].axis_CAR = AXIS_RIGHT;

                list_CARS[0].pos_X += 2;

                SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                SPR_setFrame(list_CARS[0].spr_CAR , AXIS_RIGHT);
            }

            else
            {
                list_CARS[0].axis_CAR = AXIS_CENTER;

                SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON DOWN                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_DOWN)
        {
            G_CAR_SPEED = 2;
            
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
            G_CAR_SPEED = 4;
            
            list_CARS[0].axis_CAR = AXIS_CENTER;

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
        }








        //--------------------------------------------------------------//
        //                                                              //
        //                      UPDATE CURLY'S CAR                      //
        //                                                              //
        //--------------------------------------------------------------//

        list_CARS[1].pos_X = list_CARS[1].TABLE_POSITION[list_CARS[1].index_READ_POSITION];

        SPR_setPosition(list_CARS[1].spr_CAR , list_CARS[1].pos_X , list_CARS[1].pos_Y);
        SPR_setFrame(list_CARS[1].spr_CAR , list_CARS[1].TABLE_AXIS[list_CARS[1].index_READ_POSITION]);


        list_CARS[1].index_READ_POSITION += 1;

        if(list_CARS[1].index_READ_POSITION > 16)
        {
            list_CARS[1].index_READ_POSITION = 0;
        }




        list_CARS[1].TABLE_POSITION[list_CARS[1].index_WRITE_POSITION] = list_CARS[0].pos_X;
        list_CARS[1].TABLE_AXIS[list_CARS[1].index_WRITE_POSITION] = list_CARS[0].axis_CAR;


        list_CARS[1].index_WRITE_POSITION += 1;

        if(list_CARS[1].index_WRITE_POSITION > 16)
        {
            list_CARS[1].index_WRITE_POSITION = 0;
        }




        //--------------------------------------------------------------//
        //                                                              //
        //                      UPDATE LARRY'S CAR                      //
        //                                                              //
        //--------------------------------------------------------------//

        list_CARS[2].pos_X = list_CARS[2].TABLE_POSITION[list_CARS[2].index_READ_POSITION];

        SPR_setPosition(list_CARS[2].spr_CAR , list_CARS[2].pos_X , list_CARS[2].pos_Y);
        SPR_setFrame(list_CARS[2].spr_CAR , list_CARS[1].TABLE_AXIS[list_CARS[2].index_READ_POSITION]);


        list_CARS[2].index_READ_POSITION += 1;

        if(list_CARS[2].index_READ_POSITION > 16)
        {
            list_CARS[2].index_READ_POSITION = 0;
        }




        list_CARS[2].TABLE_POSITION[list_CARS[2].index_WRITE_POSITION] = list_CARS[0].pos_X;
        list_CARS[2].TABLE_AXIS[list_CARS[2].index_WRITE_POSITION] = list_CARS[0].axis_CAR;


        list_CARS[2].index_WRITE_POSITION += 1;

        if(list_CARS[2].index_WRITE_POSITION > 16)
        {
            list_CARS[2].index_WRITE_POSITION = 0;
        }
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
                VDP_drawIntEx_BG_A_QUEUE(G_COUNTER_DOCTORS , 2 , 8 , 26 , PAL0);
            }

            else
            {
                VDP_drawIntEx_BG_A_QUEUE(G_COUNTER_DOCTORS , 1 , 9 , 26 , PAL0);
                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, 8), 8, 26,  0,  0, 1, 1, CPU);
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
        VDP_drawIntEx_BG_A_QUEUE(G_REWARD , 2 , 3 , 26 , PAL0);
    }

    else if(G_REWARD < 1000)
    {
        VDP_drawIntEx_BG_A_QUEUE(G_REWARD , 3 , 3 , 26 , PAL0);
    }    

    else
    {
        VDP_drawIntEx_BG_A_QUEUE(G_REWARD , 4 , 3 , 26 , PAL0);
    }  
}







inline static void anim_NURSE()
{
    if(nurse.axis_NURSE == AXIS_RIGHT)
    {
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




            // READ NURSE VELOCITY //
            u8 nurse_VELOCITY = TABLE_NURSE_VELOCITY[nurse.index_SPRITE_FRAME];

            // CHANGE NURSE POSITION //
            if( (nurse.pos_X + nurse_VELOCITY) > 227)
            {
                nurse.pos_X = 227;

                nurse.axis_NURSE = AXIS_LEFT;
            }

            else
            {
                nurse.pos_X += nurse_VELOCITY;
            }
            

            SPR_setPosition(nurse.spr_NURSE , nurse.pos_X , 10);
        }
    }


    else if(nurse.axis_NURSE == AXIS_LEFT)
    {
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




            // READ NURSE VELOCITY //
            u8 nurse_VELOCITY = TABLE_NURSE_VELOCITY[nurse.index_SPRITE_FRAME];

            // CHANGE NURSE POSITION //
            if( (nurse.pos_X - nurse_VELOCITY) < 44)
            {
                nurse.pos_X = 44;

                nurse.axis_NURSE = AXIS_RIGHT;
            }

            else
            {
                nurse.pos_X -= nurse_VELOCITY;
            }
            

            SPR_setPosition(nurse.spr_NURSE , nurse.pos_X , 10);
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

        patient.pos_Y                = (TABLE_PATIENT_TYPE[random_patient_type].height_PATIENT * -1) -64;

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
            u16 random_patient_pos = random_NUMBER(0,10);
            s16 new_pos_X = TABLE_PATIENT_SPAWN_POSITION[random_patient_pos];

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
                //              IF PATIENT HAS NOT BEEN HIT              //
                //-------------------------------------------------------//
                if(patient.patient_STATE == PATIENT_NOT_HIT)
                {
                    patient.pos_Y -= patient.ptr_VELOCITY[patient.index_SPRITE_FRAME];
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

        //VDP_drawIntEx_BG_A_QUEUE(list_CARS[0].pos_X,3,0,0,PAL2);
        //VDP_drawIntEx_BG_A_QUEUE(list_CARS[1].pos_X,3,0,1,PAL2);
        //VDP_drawIntEx_BG_A_QUEUE(list_CARS[2].pos_X,3,0,2,PAL2);
    }


    else if(G_PHASE_SEQUENCE == DOCTORS_PHASE_EXIT)
    {
        //--------------------------------------------------------------//
        //                                                              //
        //                        RECENTER NURSE                        //
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
        //                       UPDATE MOE'S CAR                       //
        //                                                              //
        //--------------------------------------------------------------//

        if(list_CARS[0].pos_X < 136)
        {
            list_CARS[0].axis_CAR = AXIS_RIGHT;

            list_CARS[0].pos_X += 2;

            SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , list_CARS[0].pos_Y);

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_RIGHT);
        }

        else if(list_CARS[0].pos_X > 136)
        {
            list_CARS[0].axis_CAR = AXIS_LEFT;
            
            list_CARS[0].pos_X -= 2;

            SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , list_CARS[0].pos_Y);

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_LEFT);
        }

        else if(list_CARS[0].pos_X == 136)
        {
            list_CARS[0].axis_CAR = AXIS_CENTER;

            SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , list_CARS[0].pos_Y);

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                      UPDATE CURLY'S CAR                      //
        //                                                              //
        //--------------------------------------------------------------//

        SPR_setPosition(list_CARS[1].spr_CAR , list_CARS[1].TABLE_POSITION[list_CARS[1].index_READ_POSITION] , list_CARS[1].pos_Y);
        SPR_setFrame(list_CARS[1].spr_CAR , list_CARS[1].TABLE_AXIS[list_CARS[1].index_READ_POSITION]);


        list_CARS[1].index_READ_POSITION += 1;

        if(list_CARS[1].index_READ_POSITION > 16)
        {
            list_CARS[1].index_READ_POSITION = 0;
        }




        list_CARS[1].TABLE_POSITION[list_CARS[1].index_WRITE_POSITION] = list_CARS[0].pos_X;
        list_CARS[1].TABLE_AXIS[list_CARS[1].index_WRITE_POSITION] = list_CARS[0].axis_CAR;


        list_CARS[1].index_WRITE_POSITION += 1;

        if(list_CARS[1].index_WRITE_POSITION > 16)
        {
            list_CARS[1].index_WRITE_POSITION = 0;
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                      UPDATE LARRY'S CAR                      //
        //                                                              //
        //--------------------------------------------------------------//

        SPR_setPosition(list_CARS[2].spr_CAR , list_CARS[2].TABLE_POSITION[list_CARS[2].index_READ_POSITION] , list_CARS[2].pos_Y);
        SPR_setFrame(list_CARS[2].spr_CAR , list_CARS[1].TABLE_AXIS[list_CARS[2].index_READ_POSITION]);


        list_CARS[2].index_READ_POSITION += 1;

        if(list_CARS[2].index_READ_POSITION > 16)
        {
            list_CARS[2].index_READ_POSITION = 0;
        }




        list_CARS[2].TABLE_POSITION[list_CARS[2].index_WRITE_POSITION] = list_CARS[0].pos_X;
        list_CARS[2].TABLE_AXIS[list_CARS[2].index_WRITE_POSITION] = list_CARS[0].axis_CAR;


        list_CARS[2].index_WRITE_POSITION += 1;

        if(list_CARS[2].index_WRITE_POSITION > 16)
        {
            list_CARS[2].index_WRITE_POSITION = 0;
        }




        //--------------------------------------------------------------//
        //                                                              //
        //                           SCROLLING                          //
        //                                                              //
        //--------------------------------------------------------------//
        
        G_POS_Y_CAMERA += G_CAR_SPEED;
        

        if(G_POS_Y_CAMERA > 16765 && G_POS_Y_CAMERA < 16769)
        {
            VDP_setTileMapEx(BG_B, image_DOCTORS_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_DOCTORS_BG_B1.tileset->numTile), 0, 11, 0, 0, 40, 5, DMA_QUEUE);
        }
        
        if(G_POS_Y_CAMERA < 16813)
        {
            VDP_setVerticalScrollVSync(BG_B , -G_POS_Y_CAMERA);
        }

        if(G_POS_Y_CAMERA >= 17240)
        {
            G_COUNTER_1 = 0;

            // 15 DOLLARS REWARD PER REMAINING SECOND //
            G_REWARD += (G_COUNTER_DOCTORS * 15);
            
            G_PHASE_SEQUENCE = DOCTORS_PHASE_GAME_OVER;
        }



        VDP_drawIntEx_BG_A_QUEUE(G_POS_Y_CAMERA,5,0,0,PAL2);
    }


    else if(G_PHASE_SEQUENCE == DOCTORS_PHASE_GAME_OVER)
    {
        G_COUNTER_1 += 1;

        //VDP_drawIntEx_BG_A_QUEUE(G_COUNTER_1,3,0,2,PAL2);

        if(G_COUNTER_1 == 120)
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

            G_PHASE_SEQUENCE = 0;

            // DEFINE NEXT MINIGAME //
            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_REWARD;
            G_SCENE_NEXT    = SCENE_REWARD;

            G_SCENE_LOADED  = FALSE;

            return;
        }
    }

}









