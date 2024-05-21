#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"




#include "maps_DOCTORS.h"
#include "maps_GLOBAL.h"




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

        SPR_setPosition(list_CARS[1].spr_CAR , list_CARS[1].TABLE_POSITION[list_CARS[1].index_READ_POSITION] , 139);
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

        SPR_setPosition(list_CARS[2].spr_CAR , list_CARS[2].TABLE_POSITION[list_CARS[2].index_READ_POSITION] , 179);
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
                VDP_drawIntEx_BG_A_QUEUE(G_COUNTER_DOCTORS , 2 , 8 , 26 , PAL1);
            }

            else
            {
                VDP_drawIntEx_BG_A_QUEUE(G_COUNTER_DOCTORS , 1 , 9 , 26 , PAL1);
                VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, 6), 8, 26,  0,  0, 1, 1, CPU);
            }
        }

        return;    
    }
    
    G_COUNTER_1 += 1;
}




void sequence_DOCTORS_MINIGAME()
{
    counter_DOCTORS();
    
    if(G_PHASE_SEQUENCE == DOCTORS_PHASE_RACING)
    {
        G_POS_Y_CAMERA += G_CAR_SPEED;

        if(G_POS_Y_CAMERA == 16766 || G_POS_Y_CAMERA == 16768)
        {
            VDP_setTileMapEx(BG_B, image_DOCTORS_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_DOCTORS_BG_B1.tileset->numTile), 0, 11, 0, 0, 40, 5, DMA_QUEUE);
        }
        
        else if(G_POS_Y_CAMERA > 16808)
        {
            G_POS_Y_CAMERA = 0;

            G_PHASE_SEQUENCE = DOCTORS_PHASE_RACING_OVER;
        }
        
        VDP_setVerticalScrollVSync(BG_B , -G_POS_Y_CAMERA);
    }


    else if(G_PHASE_SEQUENCE == DOCTORS_PHASE_RACING_OVER)
    {
        //
    }
}









