#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"





void joypad_DOCTORS_MINIGAME()
{
    u16 value=JOY_readJoypad(JOY_1);


    //--------------------------------------------------------------//
    //                                                              //
    //                       NO JOYPAD INPUT                        //
    //                                                              //
    //--------------------------------------------------------------//

    if((value & BUTTON_DIR) == 0)
    {
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





void sequence_DOCTORS_MINIGAME()
{
    //
}









