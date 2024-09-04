#include <genesis.h>




#include "custom_tools.h"
#include "structures.h"
#include "variables.h"




#include "maps_GAMEOVER.h"
#include "maps_INTRO.h"





void sequence_GAMEOVER()
{
    //--------------------------------------------------------------------//
    //                                                                    //
    //                     FAIL TO SAVE THE ORPHANAGE                     //
    //                                                                    //
    //--------------------------------------------------------------------//
    if(G_MONEY < 5000)
    {
        // EVIL LAUGH //
        if(G_COUNTER_1 == 72)
        {
            XGM_startPlayPCM(SOUND_BANKER_LAUGH,15,SOUND_PCM_CH4);
        }

        // ...IS NOT ENOUGH ! //
        else if(G_COUNTER_1 == 250)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 15, 9, 0, 0, 12, 5, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_FAIL_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 16, 10, 0, 0, 10, 3, DMA_QUEUE);

            u8 leading;

            if(G_MONEY < 10)
            {
                leading = 1;
            }

            else if(G_MONEY < 100)
            {
                leading = 2;
            }

            else if(G_MONEY < 1000)
            {
                leading = 3;
            }

            else if(G_MONEY < 10000)
            {
                leading = 4;
            }

            else if(G_MONEY < 10000)
            {
                leading = 5;
            }

            VDP_drawIntEx_BG_A_QUEUE(G_MONEY,leading,19,10,PAL2);

            SPR_setPosition(sprite_ARROW_DIALOG , 150 , 112);
        }

        // EVIL LAUGH //
        else if(G_COUNTER_1 == 258)
        {
            XGM_startPlayPCM(SOUND_BANKER_LAUGH,15,SOUND_PCM_CH4);
        }

        // EVIL LAUGH //
        else if(G_COUNTER_1 == 356)
        {
            XGM_startPlayPCM(SOUND_BANKER_LAUGH,15,SOUND_PCM_CH4);
        }

        // CLEAR DIALOG //
        else if(G_COUNTER_1 == 433)
        {
            VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 15, 9, 15, 9, 12, 5, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , -24 , -24);
        }

        // THE ORPHANAGE IS MINE! //
        else if(G_COUNTER_1 == 466)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 15, 9, 0, 0, 12, 5, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_FAIL_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 16, 10, 0, 3, 10, 3, DMA_QUEUE);
        
            SPR_setPosition(sprite_ARROW_DIALOG , 150 , 112);
        }

        // EVIL LAUGH //
        else if(G_COUNTER_1 == 718)
        {
            XGM_startPlayPCM(SOUND_BANKER_LAUGH,15,SOUND_PCM_CH4);
        }

        // EVIL LAUGH //
        else if(G_COUNTER_1 == 862)
        {
            XGM_startPlayPCM(SOUND_BANKER_LAUGH,15,SOUND_PCM_CH4);
        }

        // EVIL LAUGH //
        else if(G_COUNTER_1 == 972)
        {
            XGM_startPlayPCM(SOUND_BANKER_LAUGH,15,SOUND_PCM_CH4);
        }

        // EVIL LAUGH //
        else if(G_COUNTER_1 == 1046)
        {
            XGM_startPlayPCM(SOUND_BANKER_LAUGH,15,SOUND_PCM_CH4);
        }


    }


    //--------------------------------------------------------------------//
    //                                                                    //
    //                         SAVE THE ORPHANAGE                         //
    //                                                                    //
    //--------------------------------------------------------------------//
    else if(G_MONEY < 10000)
    {
        // THANK YOU BOYS! //
        if(G_COUNTER_1 == 60)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 5, 8, 0, 5, 11, 4, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 6, 9, 0, 0, 9, 2, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , 76 , 96);
        }

        // ERASE DIALOG //
        else if(G_COUNTER_1 == 180)
        {
            VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 5, 8, 5, 8, 11, 4, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , -24 , -24);
        }

        // YOUR GIFT OF... //
        else if(G_COUNTER_1 == 200)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 5, 8, 0, 9, 11, 5, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 6, 9, 0, 3, 9, 3, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , 76 , 104);
        }

        // ERASE DIALOG //
        else if(G_COUNTER_1 == 380)
        {
            VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 5, 8, 5, 8, 11, 5, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , -24 , -24);
        }

        // ...HAS SAVED THE CHILDREN'S HOME! //
        else if(G_COUNTER_1 == 400)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 5, 8, 0, 14, 12, 6, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 6, 9, 0, 7, 10, 4, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , 76 , 112);
        }

        // ERASE DIALOG //
        else if(G_COUNTER_1 == 520)
        {
            VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 5, 8, 5, 8, 12, 6, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , -24 , -24);
        }

        // IT IS A SHAME WE CAN'T FIX IT UP. //
        else if(G_COUNTER_1 == 540)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 5, 8, 0, 14, 12, 6, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 6, 9, 0, 12, 10, 4, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , 76 , 112);
        }




    }


    //--------------------------------------------------------------------//
    //                                                                    //
    //                    SAVE AND REPAIR THE ORPHANAGE                   //
    //                                                                    //
    //--------------------------------------------------------------------//
    else//else if(G_MONEY < 20000)
    {
        // THANK YOU BOYS! //
        if(G_COUNTER_1 == 60)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 5, 8, 0, 5, 11, 4, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 6, 9, 0, 0, 9, 2, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , 76 , 96);
        }

        // ERASE DIALOG //
        else if(G_COUNTER_1 == 180)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 5, 8, 5, 8, 11, 4, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , -24 , -24);
        }

        // YOUR GIFT OF... //
        else if(G_COUNTER_1 == 200)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 5, 8, 0, 9, 11, 5, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 6, 9, 0, 3, 9, 3, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , 76 , 104);
        }

        // ERASE DIALOG //
        else if(G_COUNTER_1 == 380)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 5, 8, 5, 8, 11, 5, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , -24 , -24);
        }

        // ...HAS SAVED THE CHILDREN'S HOME! //
        else if(G_COUNTER_1 == 400)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 5, 8, 0, 14, 12, 6, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 6, 9, 0, 7, 10, 4, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , 76 , 112);
        }

        // ERASE DIALOG //
        else if(G_COUNTER_1 == 520)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 5, 8, 5, 8, 12, 6, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , -24 , -24);
        }

        // ... AND IT IS AS GOOD AS NEW! //
        else if(G_COUNTER_1 == 540)
        {
            VDP_setTileMapEx(BG_A, image_GAMEOVER_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 5, 8, 0, 14, 12, 6, DMA_QUEUE);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile), 6, 9, 0, 17, 10, 4, DMA_QUEUE);

            SPR_setPosition(sprite_ARROW_DIALOG , 76 , 112);
        }
    }


    //--------------------------------------------------------------------//
    //                                                                    //
    //       SAVE AND REPAIR THE ORPHANAGE, AND MARRY THE DAUGHTERS       //
    //                                                                    //
    //--------------------------------------------------------------------//

    /*else
    {

    }*/


    G_COUNTER_1 += 1;
    

}









