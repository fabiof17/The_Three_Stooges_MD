#include <genesis.h>



#include "outils.h"
#include "structures.h"
#include "variables.h"




//#include "maps_DOCTORS.h"
//#include "maps_GLOBAL.h"




//#include "tables_DOCTORS.h"




void joypad_CRACKERS_MINIGAME()
{
    if(G_PHASE_SEQUENCE == CRACKER_SPOON_MOVE)
    {
        u16 value=JOY_readJoypad(JOY_1);

        s16 pos_X_HAND = SPR_getPositionX(sprite_HAND[2]);
        s16 pos_Y_HAND = SPR_getPositionY(sprite_HAND[2]);

        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON LEFT                          //
        //                                                              //
        //--------------------------------------------------------------//

        if(value & BUTTON_LEFT)
        {
            if(pos_X_HAND - 2 < 39)
            {
                pos_X_HAND = 39;
            }

            else
            {
                pos_X_HAND -= 2;
            }

            if(value & BUTTON_UP)
            {
                if(pos_Y_HAND - 2 < 100)
                {
                    pos_Y_HAND = 100;
                }

                else
                {
                    pos_Y_HAND -= 2;
                }
            }

            else if(value & BUTTON_DOWN)
            {
                if(pos_Y_HAND + 2 > 200)
                {
                    pos_Y_HAND = 200;
                }

                else
                {
                    pos_Y_HAND += 2;
                }
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON RIGHT                         //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_RIGHT)
        {
            if(pos_X_HAND + 2 > 255)
            {
                pos_X_HAND = 255;
            }

            else
            {
                pos_X_HAND += 2;
            }

            if(value & BUTTON_UP)
            {
                if(pos_Y_HAND - 2 < 100)
                {
                    pos_Y_HAND = 100;
                }

                else
                {
                    pos_Y_HAND -= 2;
                }
            }

            else if(value & BUTTON_DOWN)
            {
                if(pos_Y_HAND + 2 > 200)
                {
                    pos_Y_HAND = 200;
                }

                else
                {
                    pos_Y_HAND += 2;
                }
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                          BUTTON UP                           //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_UP)
        {
            if(pos_Y_HAND - 2 < 100)
            {
                pos_Y_HAND = 100;
            }

            else
            {
                pos_Y_HAND -= 2;
            }

            if(value & BUTTON_LEFT)
            {
                if(pos_X_HAND - 2 < 39)
                {
                    pos_X_HAND = 39;
                }

                else
                {
                    pos_X_HAND -= 2;
                }
            }

            else if(value & BUTTON_RIGHT)
            {
                if(pos_X_HAND + 2 > 255)
                {
                    pos_X_HAND = 255;
                }

                else
                {
                    pos_X_HAND += 2;
                }
            }
        }


        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON DOWN                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_DOWN)
        {
            if(pos_Y_HAND + 2 > 200)
            {
                pos_Y_HAND = 200;
            }

            else
            {
                pos_Y_HAND += 2;
            }

            if(value & BUTTON_LEFT)
            {
                if(pos_X_HAND - 2 < 39)
                {
                    pos_X_HAND = 39;
                }

                else
                {
                    pos_X_HAND -= 2;
                }
            }

            else if(value & BUTTON_RIGHT)
            {
                if(pos_X_HAND + 2 > 255)
                {
                    pos_X_HAND = 255;
                }

                else
                {
                    pos_X_HAND += 2;
                }
            }
        }

        SPR_setPosition(sprite_HAND[2] , pos_X_HAND      , pos_Y_HAND);
        SPR_setPosition(sprite_HAND[1] , pos_X_HAND -  7 , pos_Y_HAND + 100);
        SPR_setPosition(sprite_HAND[0] , pos_X_HAND + 10 , pos_Y_HAND +  44);
    }
}



/*
void sequence_CRACKERS_MINIGAME()
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

        //VDP_drawIntEx_BG_A_QUEUE(G_CAR_COUNTER_SPEED,2,0,0,PAL2);
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
            VDP_setTileMapEx(BG_B, image_DOCTORS_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_DOCTORS_BG_B1.tileset->numTile), 0, 11, 0, 0, 40, 5, DMA_QUEUE);
        }
        
        if(G_POS_Y_CAMERA < 16809)
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
*/








