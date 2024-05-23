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
                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, 6), 8, 26,  0,  0, 1, 1, CPU);
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
        //                          IF CAMERA FALLS WITHIN SPAWN RANGE                          //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        if(G_POS_Y_CAMERA >= TABLE_PATIENTS[G_INDEX_SPAWN_PATIENT].spawn_FRAME && G_POS_Y_CAMERA <= TABLE_PATIENTS[G_INDEX_SPAWN_PATIENT].spawn_FRAME + 4)
        {
            patient.pos_X                = TABLE_PATIENTS[G_INDEX_SPAWN_PATIENT].pos_X;
            patient.pos_Y                = TABLE_PATIENTS[G_INDEX_SPAWN_PATIENT].pos_Y;

            patient.counter_SPRITE_FRAME = 0;
            patient.index_SPRITE_FRAME   = 0;

            patient.patient_STATE        = 0;

            patient.ptr_VELOCITY         = &TABLE_PATIENTS[G_INDEX_SPAWN_PATIENT].ptr_VELOCITY[0];
            
            patient.spr_PATIENT          = SPR_addSprite(TABLE_PATIENTS[G_INDEX_SPAWN_PATIENT].tiles_PATIENT , patient.pos_X , patient.pos_Y , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        }
    }
}


inline static void anim_PATIENT()
{
    if(patient.spr_PATIENT != NULL)
    {
        patient.pos_Y += G_CAR_SPEED;
        

        patient.counter_SPRITE_FRAME += 1;


        if(patient.counter_SPRITE_FRAME == 16)
        {
            patient.counter_SPRITE_FRAME = 0;

            patient.index_SPRITE_FRAME += 1;


            if(patient.index_SPRITE_FRAME == 3)
            {
                patient.index_SPRITE_FRAME = 0;
            }

            SPR_setFrame(patient.spr_PATIENT , patient.index_SPRITE_FRAME);
            
            patient.pos_Y -= patient.ptr_VELOCITY[patient.index_SPRITE_FRAME];

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

        spawn_PATIENT();






        counter_DOCTORS();
    }


    else if(G_PHASE_SEQUENCE == DOCTORS_PHASE_RACING_OVER)
    {
        //
    }
}









