#include <genesis.h>



#include "custom_tools.h"
#include "palettes.h"
#include "structures.h"
#include "variables.h"



#include "maps_BACKGROUNDS.h"
#include "maps_BOXING.h"
#include "maps_CRACKERS.h"
#include "maps_DOCTORS.h"
#include "maps_GLOBAL.h"
#include "maps_QUESTION_MARK.h"
#include "maps_TRIVIA.h"
#include "maps_WAITERS.h"




#include "routines_ROULETTE.h"




#include "sprites_QUESTION_MARK.h"
#include "sprites_TRIVIA.h"




#include "tables_QUESTIONS.h"




void init_STREET_BEGINNIG()
{
    //**************************************************************************************//
    //                                                                                      //
    //                                      CLEAN VRAM                                      //
    //                                                                                      //
    //**************************************************************************************//

    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(200);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                  TILES BASE SGDK                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_TILES_BASE_SGDK.tileset, 0, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                   ROULETTE FONT                                      //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_B                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_loadTileSet(image_STREET_0_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_0_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_0_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 28, 0, 0, 40, 28, CPU);
    

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_A                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_0_BG_B.tileset->numTile;
    VDP_loadTileSet(image_STREET_0_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_0_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_0_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 28, 0, 0, 40, 28, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//
    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_STREET_0_BG_A.tileset->numTile;
   



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
    //**************************************************************************************//
    //                                                                                      //
    //                                      CLEAN VRAM                                      //
    //                                                                                      //
    //**************************************************************************************//

    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(220);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                   ROULETTE FONT                                      //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_B                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_loadTileSet(image_TRIVIA_TYPE1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    
    
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_A                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_TYPE1_BG_B.tileset->numTile;
    VDP_loadTileSet(image_TRIVIA_TYPE1_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  28, 0, 0, 40, 28, CPU);
    
    
    
    
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_TRIVIA_TYPE1_BG_A.tileset->numTile;
  



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
    //**************************************************************************************//
    //                                                                                      //
    //                                      CLEAN VRAM                                      //
    //                                                                                      //
    //**************************************************************************************//

    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(350);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                   ROULETTE FONT                                      //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_B                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_loadTileSet(image_TRIVIA_TYPE2_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_A                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_TYPE2_BG_B.tileset->numTile;
    VDP_loadTileSet(image_TRIVIA_TYPE2_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE2_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE2_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  28, 0, 0, 40, 28, CPU);   
 
    
    
    
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_TRIVIA_TYPE2_BG_A.tileset->numTile;
    



    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                SETUP PLANES POSITION                                 //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    //G_POS_Y_CAMERA = 224;


    //VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
    //VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




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






void init_STREET_QUESTION_MARK()
{
    //**************************************************************************************//
    //                                                                                      //
    //                                      CLEAN VRAM                                      //
    //                                                                                      //
    //**************************************************************************************//

    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_init();
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                   ROULETTE FONT                                      //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_B                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_loadTileSet(image_QUESTION_MARK_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_QUESTION_MARK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B),  0,  0,  0,  0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_QUESTION_MARK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B),  0, 28,  0,  0, 40, 28, CPU);
    
    
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_A                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//
    // AS THERE'S NO BG_A ON THIS SCREEN //
    // WE CLEAR IT FOR SAFETY //
    VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, 0),  0,  0,  0,  0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_EMPTY_TILEMAP.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, 0),  0, 28,  0,  0, 40, 28, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_B + image_QUESTION_MARK_BG_B.tileset->numTile;




    //**************************************************************************************//
    //                                                                                      //
    //                                      SPRITES                                         //
    //                                                                                      //
    //**************************************************************************************// 

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                    SCISSOR SPRITE                                    //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    sprite_SCISSOR = SPR_addSprite(&tiles_SPR_SCISSOR, 128, 0, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));
    SPR_setFrame(sprite_SCISSOR,1);
    SPR_setDepth(sprite_SCISSOR,10);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_QUESTION_MARK_BG_B.palette->data    , 16 * 2 );
    memcpy( &palette_64[16] , palette_BLACK.data                        , 16 * 2 );
}


void init_STREET_DOCTORS()
{
    //**************************************************************************************//
    //                                                                                      //
    //                                      CLEAN VRAM                                      //
    //                                                                                      //
    //**************************************************************************************//

    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(250);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                   ROULETTE FONT                                      //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_B                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_loadTileSet(image_STREET_DOCTORS_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_DOCTORS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_DOCTORS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 28, 0, 0, 40, 28, CPU);


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_A                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_DOCTORS_BG_B.tileset->numTile;
    VDP_loadTileSet(image_STREET_DOCTORS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_DOCTORS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_DOCTORS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 28, 0, 0, 40, 28, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_STREET_DOCTORS_BG_A.tileset->numTile;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                SETUP PLANES POSITION                                 //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_POS_Y_CAMERA = 0;


    VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
    VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_STREET_DOCTORS_BG_B.palette->data   , 16 * 2 );
    memcpy( &palette_64[16] , image_STREET_DOCTORS_BG_A.palette->data   , 16 * 2 );
}


void init_STREET_CRACKERS()
{
    //**************************************************************************************//
    //                                                                                      //
    //                                      CLEAN VRAM                                      //
    //                                                                                      //
    //**************************************************************************************//

    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(250);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                   ROULETTE FONT                                      //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_B                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_loadTileSet(image_STREET_CRACKERS_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_CRACKERS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_CRACKERS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 28, 0, 0, 40, 28, CPU);


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_A                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_CRACKERS_BG_B.tileset->numTile;
    VDP_loadTileSet(image_STREET_CRACKERS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_CRACKERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_CRACKERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 28, 0, 0, 40, 28, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_STREET_CRACKERS_BG_A.tileset->numTile;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                SETUP PLANES POSITION                                 //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_POS_Y_CAMERA = 0;


    VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
    VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_STREET_CRACKERS_BG_B.palette->data  , 16 * 2 );
    memcpy( &palette_64[16] , image_STREET_CRACKERS_BG_A.palette->data  , 16 * 2 );
}


void init_STREET_WAITERS()
{
    //**************************************************************************************//
    //                                                                                      //
    //                                      CLEAN VRAM                                      //
    //                                                                                      //
    //**************************************************************************************//

    u16 i = 0;

    for(i=16 ; i<1440 ; i++)
    {
        VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,64,TRUE);
    
    SPR_initEx(320);
    
    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                   ROULETTE FONT                                      //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_FONT_ROULETTE.tileset, TILE_FONT_INDEX, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    G_ADR_VRAM_BG_B = TILE_USER_INDEX;

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_B                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_loadTileSet(image_STREET_WAITERS_BG_B1.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_WAITERS_BG_B1.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_STREET_WAITERS_BG_B1.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 28, 0, 0, 40, 28, CPU);
    VDP_loadTileSet(image_STREET_WAITERS_BG_B2.tileset, G_ADR_VRAM_BG_B + image_STREET_WAITERS_BG_B1.tileset->numTile, CPU);
    

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_A                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_WAITERS_BG_B1.tileset->numTile + image_STREET_WAITERS_BG_B2.tileset->numTile;
    VDP_loadTileSet(image_STREET_WAITERS_BG_A1.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_WAITERS_BG_A1.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_STREET_WAITERS_BG_A1.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 28, 0, 0, 40, 28, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_STREET_WAITERS_BG_A1.tileset->numTile;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                SETUP PLANES POSITION                                 //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_POS_Y_CAMERA = 0;


    VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
    VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_STREET_WAITERS_BG_B1.palette->data  , 16 * 2 );
    memcpy( &palette_64[16] , image_STREET_WAITERS_BG_A1.palette->data  , 16 * 2 );
}







void (*TABLE_INIT_STREET_ROULETTE[17])(void)   =   {
                                                        init_STREET_BEGINNIG,
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        init_STREET_QUESTION_MARK,
                                                        NULL,
                                                        init_STREET_DOCTORS,
                                                        NULL,
                                                        init_STREET_CRACKERS,
                                                        init_STREET_TRIVIA_TYPE1,
                                                        init_STREET_TRIVIA_TYPE2,
                                                        NULL,
                                                        init_STREET_WAITERS,
                                                        NULL,
                                                        NULL,
                                                        NULL
                                                    };






