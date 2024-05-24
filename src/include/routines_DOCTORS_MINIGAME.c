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
            
            list_CARS[0].car_AXIS = AXIS_CENTER;

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
                list_CARS[0].car_AXIS = AXIS_LEFT;

                list_CARS[0].pos_X -= 2;

                SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                SPR_setFrame(list_CARS[0].spr_CAR , AXIS_LEFT);
            }

            else
            {
                list_CARS[0].car_AXIS = AXIS_CENTER;

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
                list_CARS[0].car_AXIS = AXIS_RIGHT;

                list_CARS[0].pos_X += 2;

                SPR_setPosition(list_CARS[0].spr_CAR , list_CARS[0].pos_X , 99);

                SPR_setFrame(list_CARS[0].spr_CAR , AXIS_RIGHT);
            }

            else
            {
                list_CARS[0].car_AXIS = AXIS_CENTER;

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
            
            list_CARS[0].car_AXIS = AXIS_CENTER;

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
            
            list_CARS[0].car_AXIS = AXIS_CENTER;

            SPR_setFrame(list_CARS[0].spr_CAR , AXIS_CENTER);
        }








        //--------------------------------------------------------------//
        //                                                              //
        //                      UPDATE CURLY'S CAR                      //
        //                                                              //
        //--------------------------------------------------------------//

        SPR_setPosition(list_CARS[1].spr_CAR , list_CARS[1].TABLE_POSITION[list_CARS[1].index_READ_POSITION] , 141);
        SPR_setFrame(list_CARS[1].spr_CAR , list_CARS[1].TABLE_AXIS[list_CARS[1].index_READ_POSITION]);


        list_CARS[1].index_READ_POSITION += 1;

        if(list_CARS[1].index_READ_POSITION > 16)
        {
            list_CARS[1].index_READ_POSITION = 0;
        }




        list_CARS[1].TABLE_POSITION[list_CARS[1].index_WRITE_POSITION] = list_CARS[0].pos_X;
        list_CARS[1].TABLE_AXIS[list_CARS[1].index_WRITE_POSITION] = list_CARS[0].car_AXIS;


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

        SPR_setPosition(list_CARS[2].spr_CAR , list_CARS[2].TABLE_POSITION[list_CARS[2].index_READ_POSITION] , 183);
        SPR_setFrame(list_CARS[2].spr_CAR , list_CARS[1].TABLE_AXIS[list_CARS[2].index_READ_POSITION]);


        list_CARS[2].index_READ_POSITION += 1;

        if(list_CARS[2].index_READ_POSITION > 16)
        {
            list_CARS[2].index_READ_POSITION = 0;
        }




        list_CARS[2].TABLE_POSITION[list_CARS[2].index_WRITE_POSITION] = list_CARS[0].pos_X;
        list_CARS[2].TABLE_AXIS[list_CARS[2].index_WRITE_POSITION] = list_CARS[0].car_AXIS;


        list_CARS[2].index_WRITE_POSITION += 1;

        if(list_CARS[2].index_WRITE_POSITION > 16)
        {
            list_CARS[2].index_WRITE_POSITION = 0;
        }
    }
}




inline static void counter_DOCTORS()
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




inline static void anim_NURSE()
{
    if(nurse.nurse_AXIS == AXIS_RIGHT)
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

                nurse.nurse_AXIS = AXIS_LEFT;
            }

            else
            {
                nurse.pos_X += nurse_VELOCITY;
            }
            

            SPR_setPosition(nurse.spr_NURSE , nurse.pos_X , 10);
        }
    }


    else if(nurse.nurse_AXIS == AXIS_LEFT)
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

                nurse.nurse_AXIS = AXIS_RIGHT;
            }

            else
            {
                nurse.pos_X -= nurse_VELOCITY;
            }
            

            SPR_setPosition(nurse.spr_NURSE , nurse.pos_X , 10);
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
            u8 new_patient_type = random_NUMBER(0,2);

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

        patient.pos_Y                = TABLE_PATIENT_TYPE[random_patient_type].height_PATIENT * -1;

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

                    //VDP_drawIntEx_BG_A_QUEUE(new_pos_X,3,0,20,PAL2);
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

                    //VDP_drawIntEx_BG_A_QUEUE(new_pos_X,3,0,20,PAL2);
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


        if(G_POS_Y_CAMERA > 16765 && G_POS_Y_CAMERA < 16769)
        {
            VDP_setTileMapEx(BG_B, image_DOCTORS_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_DOCTORS_BG_B1.tileset->numTile), 0, 11, 0, 0, 40, 5, DMA_QUEUE);
        }
        
        else if(G_POS_Y_CAMERA > 16808)
        {
            G_POS_Y_CAMERA = 16808;

            G_PHASE_SEQUENCE = DOCTORS_PHASE_RACING_OVER;
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


        if(G_POS_Y_CAMERA < 16000)
        {
            spawn_PATIENT();
        }
        



        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        COUNTER                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        counter_DOCTORS();

        //VDP_drawIntEx_BG_A_QUEUE(G_POS_Y_CAMERA,3,0,20,PAL2);
    }


    else if(G_PHASE_SEQUENCE == DOCTORS_PHASE_RACING_OVER)
    {
        //
    }
}









