#include <genesis.h>



#include "palettes.h"
#include "structures.h"
#include "variables.h"



#include "maps_BACKGROUNDS.h"
#include "maps_GLOBAL.h"
#include "maps_QUESTION_MARK.h"
#include "maps_TRIVIA.h"




#include "routines_ROULETTE.h"




#include "sprites_TRIVIA.h"




#include "tables_QUESTIONS.h"




void init_STREET_BEGINNIG()
{
    // CLEAN VRAM //
    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(200);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                        FONT                                          //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   LOADING BG TILES                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    // BG_B //
    VDP_loadTileSet(image_STREET_0_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_0_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_0_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_0_BG_B.tileset->numTile;
    SYS_doVBlankProcess();

    // BG_A //
    VDP_loadTileSet(image_STREET_0_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_0_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_0_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_STREET_0_BG_A.tileset->numTile;
    SYS_doVBlankProcess();
   



    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_STREET_0_BG_B.palette->data         , 16 * 2 );
    memcpy( &palette_64[16] , image_STREET_0_BG_A.palette->data         , 16 * 2 );




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       VARIABLES                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_STREET_TYPE   = STREET_TYPE_0;
}






void init_STREET_TRIVIA_TYPE1()
{
    // CLEAN VRAM //
    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(220);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   LOADING BG TILES                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_TYPE1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_TYPE1_BG_B.tileset->numTile;
    

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_TYPE1_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_TRIVIA_TYPE1_BG_A.tileset->numTile;


    G_POS_Y_CAMERA = 0;
    



    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_TRIVIA_TYPE1_BG_B.palette->data , 16 * 2 );
    memcpy( &palette_64[16] , image_TRIVIA_TYPE1_BG_A.palette->data , 16 * 2 );




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       VARIABLES                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_SCENE_TYPE            = SCENE_TRIVIA_MINIGAME_TYPE1;
}


void init_STREET_TRIVIA_TYPE2()
{
    // CLEAN VRAM //
    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(350);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   LOADING BG TILES                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_TYPE2_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_TYPE2_BG_B.tileset->numTile;

    // BG_A //
    VDP_loadTileSet(image_TRIVIA_TYPE2_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE2_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE2_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  28, 0, 0, 40, 28, CPU);   
    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_TRIVIA_TYPE2_BG_A.tileset->numTile;
    

    VDP_setVerticalScroll(BG_B,224);
    VDP_setVerticalScroll(BG_A,224);


    SYS_doVBlankProcess();




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       INIT HUB                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    //init_HUB();




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_TRIVIA_TYPE2_BG_B.palette->data , 16 * 2 );
    memcpy( &palette_64[16] , image_TRIVIA_TYPE2_BG_A.palette->data , 16 * 2 );




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       VARIABLES                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_COUNTER_1             = 0;
    G_INDEX_1               = 0;
    G_INDEX_2               = 0;
    G_INDEX_3               = 0;
    

    G_SCENE                 = SCENE_FADE_IN;
    G_SCENE_TYPE            = SCENE_TRIVIA_MINIGAME_TYPE2;
    G_SCENE_NEXT            = SCENE_TRIVIA_MINIGAME_TYPE2;

    G_SCENE_LOADED          = TRUE;
}


void init_STREET_TRIVIA_TYPE3()
{
    // CLEAN VRAM //
    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(230);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   LOADING BG TILES                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_TYPE1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_TYPE1_BG_B.tileset->numTile;
    

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_TYPE1_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_TRIVIA_TYPE1_BG_A.tileset->numTile;

    SYS_doVBlankProcess();


    VDP_setVerticalScroll(BG_B,224);
    VDP_setVerticalScroll(BG_A,224);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       INIT HUB                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    //init_HUB();




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_TRIVIA_TYPE1_BG_B.palette->data , 16 * 2 );
    memcpy( &palette_64[16] , image_TRIVIA_TYPE1_BG_A.palette->data , 16 * 2 );




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       VARIABLES                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_COUNTER_1             = 0;
    G_INDEX_1               = 0;
    G_INDEX_2               = 0;
    G_INDEX_3               = 0;


    //G_STREET_TYPE           = STREET_TYPE_BANK;
    

    G_SCENE                 = SCENE_FADE_IN;
    G_SCENE_TYPE            = SCENE_TRIVIA_MINIGAME_TYPE3;
    G_SCENE_NEXT            = SCENE_TRIVIA_MINIGAME_TYPE3;

    G_SCENE_LOADED          = TRUE;
}


void init_STREET_TRIVIA_TYPE4()
{
    // CLEAN VRAM //
    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    VDP_setPlaneSize(64,32,TRUE);
    
    SPR_initEx(200);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   LOADING BG TILES                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_MINIGAME_TYPE1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_MINIGAME_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_MINIGAME_TYPE1_BG_B.tileset->numTile;
    SYS_doVBlankProcess();

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_MINIGAME_TYPE1_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_MINIGAME_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);
    SYS_doVBlankProcess();




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                      PRINT TEXT                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    // REWARD AMOUNT //
    /*if(G_REWARD < 10)
    {
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + G_REWARD), 26 , 9 , 0, 0, 1, 1, CPU);
    }

    else if(G_REWARD < 100)
    {
        u8 number1 = G_REWARD / 10;
        u8 number2 = G_REWARD - (number1*10);

        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 26 , 9 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 27 , 9 , 0, 0, 1, 1, CPU);
    }

    else if(G_REWARD < 1000)
    {
        u8 number1 = G_REWARD / 100;
        u8 number2 = (G_REWARD - (number1*100)) / 10;
        u8 number3 = G_REWARD - (number1*100) - (number2*10);

        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 26 , 9 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 27 , 9 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number3), 28 , 9 , 0, 0, 1, 1, CPU);
    }

    else
    {
        u8 number1 = G_REWARD / 1000;
        u8 number2 = (G_REWARD - (number1*1000)) / 100;
        u8 number3 = (G_REWARD - (number1*1000) - (number2*100)) / 10;
        u8 number4 = G_REWARD - (number1*1000) - (number2*100) - (number3*10);

        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 26 , 9 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 27 , 9 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number3), 28 , 9 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number4), 29 , 9 , 0, 0, 1, 1, CPU);
    }*/



    VDP_setVerticalScroll(BG_B , 0);
    VDP_setVerticalScroll(BG_A , 0);








    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_TRIVIA_MINIGAME_TYPE1_BG_B.palette->data      , 16 * 2 );
    memcpy( &palette_64[16] , image_TRIVIA_MINIGAME_TYPE1_BG_A.palette->data      , 16 * 2 );
    memcpy( &palette_64[32] , palette_BLACK.data                            , 16 * 2 );
    memcpy( &palette_64[48] , palette_BLACK.data                            , 16 * 2 );




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       VARIABLES                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_COUNTER_1             = 0;
    G_INDEX_1               = 0;
    G_INDEX_2               = 0;
    G_INDEX_3               = 0;
    

    G_SCENE                 = SCENE_FADE_IN;
    G_SCENE_TYPE            = SCENE_TRIVIA_MINIGAME_TYPE2;
    G_SCENE_NEXT            = SCENE_TRIVIA_MINIGAME_TYPE2;

    G_SCENE_LOADED          = TRUE;


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         AUDIO                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//
    
}






void init_STREET_QUESTION_MARK()
{
        // CLEAN VRAM //
        u16 i = 0;

        for(i=16 ; i<1440 ; i++)
        {
            VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
        }




        VDP_setPlaneSize(64,64,TRUE);
        
        SPR_init();
        
        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   LOADING BG TILES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B = TILE_USER_INDEX;

        // BG_B //
        VDP_loadTileSet(image_QUESTION_MARK_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_QUESTION_MARK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B),  0,  0,  0,  0, 40, 28, CPU);
        VDP_setTileMapEx(BG_B, image_QUESTION_MARK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B),  0, 28,  0,  0, 40, 28, CPU);
        G_ADR_VRAM_HUB = G_ADR_VRAM_BG_B + image_QUESTION_MARK_BG_B.tileset->numTile;
        SYS_doVBlankProcess();

        // AS THERE'S NO BG_A ON THIS SCREEN //
        // WE CLEAR IT FOR SAFETY //
        VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, 0),  0,  0,  0,  0, 40, 28, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, 0),  0, 28,  0,  0, 40, 28, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        //


        SPR_update();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_QUESTION_MARK_BG_B.palette->data    , 16 * 2 );
        memcpy( &palette_64[16] , palette_BLACK.data                        , 16 * 2 );

}








void (*TABLE_INIT_STREET_BEGINNING[17])(void)   =   {
                                                        init_STREET_BEGINNIG,
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        init_STREET_QUESTION_MARK, // init_STREET_QUESTION_MARK
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        init_STREET_TRIVIA_TYPE1,
                                                        init_STREET_TRIVIA_TYPE2,
                                                        init_STREET_TRIVIA_TYPE3,
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        NULL
                                                    };






