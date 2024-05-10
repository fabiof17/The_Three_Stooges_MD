#include <genesis.h>




#include "outils.h"
#include "palettes.h"
#include "structures.h"
#include "variables.h"




#include "maps_DOLLAR.h"
#include "maps_GLOBAL.h"
#include "maps_ROULETTE.h"




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                      ANIMATIONS                                      //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const struct_WALK_STOOGES_      TABLE_ANIM_STOOGES_WALKIN_DOLLAR[31]        =   {
                                                                                    {    5 ,  0 , -87 },
                                                                                    {    8 ,  1 , -79 },
                                                                                    {   12 ,  2 , -73 },
                                                                                    {   16 ,  3 , -65 },
                                                                                    {   19 ,  4 , -57 },
                                                                                    {   23 ,  5 , -49 },
                                                                                    {   26 ,  6 , -40 },
                                                                                    {   30 ,  7 , -31 },
                                                                                    {   34 ,  0 , -23 },
                                                                                    {   37 ,  1 , -17 },
                                                                                    {   41 ,  2 ,  -9 },
                                                                                    {   44 ,  3 ,  -1 },
                                                                                    {   48 ,  4 ,   7 },
                                                                                    {   52 ,  5 ,  17 },
                                                                                    {   56 ,  6 ,  23 },
                                                                                    {   60 ,  7 ,  32 },
                                                                                    {   64 ,  0 ,  41 },
                                                                                    {   67 ,  1 ,  49 },
                                                                                    {   71 ,  2 ,  55 },
                                                                                    {   74 ,  3 ,  63 },
                                                                                    {   79 ,  4 ,  71 },
                                                                                    {   82 ,  5 ,  81 },
                                                                                    {   86 , 10 ,  88 },
                                                                                    {   92 , 11 ,  95 },
                                                                                    {  100 , 12 ,  95 },
                                                                                    {  110 , 13 , 116 },
                                                                                    {  124 , 30 , 116 },
                                                                                    {  140 , 31 , 110 },
                                                                                    {  158 , 15 , 114 },
                                                                                    {  181 , 32 , 114 },
                                                                                    {  203 , 33 , 114 }
                                                                                };


const u16                       TABLE_DOLLAR_REWARD[4]          =   {
                                                                        100,
                                                                        200,
                                                                        300,
                                                                        400
                                                                    };


const Image                     *TABLE_DOLLAR_REWARD_IMAGE[4]   =   {
                                                                        &image_DOLLAR_100,
                                                                        &image_DOLLAR_200,
                                                                        &image_DOLLAR_300,
                                                                        &image_DOLLAR_400
                                                                    };







void init_DOLLAR_TYPE1()
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

    VDP_loadTileSet(image_DOLLAR_1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_DOLLAR_1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_DOLLAR_1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    
    
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                        DIALOG                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//    
    
    G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_B + image_DOLLAR_1_BG_B.tileset->numTile;
    VDP_loadTileSet(image_DOLLAR_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                          RANDOM REWARD BETWEEN 100 AND 300                           //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    u8 generated_number = random_NUMBER(0,3);
    G_REWARD = TABLE_DOLLAR_REWARD[generated_number];
    VDP_loadTileSet(TABLE_DOLLAR_REWARD_IMAGE[generated_number]->tileset, G_ADR_VRAM_DIALOG + image_DOLLAR_DIALOG.tileset->numTile, CPU);
    
    


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_DIALOG + image_DOLLAR_DIALOG.tileset->numTile + TABLE_DOLLAR_REWARD_IMAGE[generated_number]->tileset->numTile;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                         GENERATE NEXT POSITION IN HIGHSTREET                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_DOLLAR_1_BG_B.palette->data         , 16 * 2 );
    memcpy( &palette_64[16] , palette_SPR_BANKER_PART2_INTRO.data       , 16 * 2 );
}


void init_DOLLAR_TYPE2()
{
    //**************************************************************************************//
    //                                                                                      //
    //                                      CLEAN VRAM                                      //
    //                                                                                      //
    //**************************************************************************************//^

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

    VDP_loadTileSet(image_DOLLAR_2_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_DOLLAR_2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_DOLLAR_2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                        DIALOG                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//    

    G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_B + image_DOLLAR_2_BG_B.tileset->numTile;
    VDP_loadTileSet(image_DOLLAR_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                          RANDOM REWARD BETWEEN 100 AND 300                           //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    u8 generated_number = random_NUMBER(0,3);
    G_REWARD = TABLE_DOLLAR_REWARD[generated_number];
    VDP_loadTileSet(TABLE_DOLLAR_REWARD_IMAGE[generated_number]->tileset, G_ADR_VRAM_DIALOG + image_DOLLAR_DIALOG.tileset->numTile, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_DIALOG + image_DOLLAR_DIALOG.tileset->numTile + TABLE_DOLLAR_REWARD_IMAGE[generated_number]->tileset->numTile;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                         GENERATE NEXT POSITION IN HIGHSTREET                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_DOLLAR_2_BG_B.palette->data         , 16 * 2 );
    memcpy( &palette_64[16] , palette_SPR_BANKER_PART2_INTRO.data       , 16 * 2 );
}


void init_DOLLAR_TYPE3()
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

    VDP_loadTileSet(image_DOLLAR_3_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_DOLLAR_3_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_DOLLAR_3_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                        DIALOG                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//    

    G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_B + image_DOLLAR_3_BG_B.tileset->numTile;
    VDP_loadTileSet(image_DOLLAR_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                          RANDOM REWARD BETWEEN 100 AND 300                           //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    u8 generated_number = random_NUMBER(0,3);
    G_REWARD = TABLE_DOLLAR_REWARD[generated_number];
    VDP_loadTileSet(TABLE_DOLLAR_REWARD_IMAGE[generated_number]->tileset, G_ADR_VRAM_DIALOG + image_DOLLAR_DIALOG.tileset->numTile, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_HUB = G_ADR_VRAM_DIALOG + image_DOLLAR_DIALOG.tileset->numTile + TABLE_DOLLAR_REWARD_IMAGE[generated_number]->tileset->numTile;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                         GENERATE NEXT POSITION IN HIGHSTREET                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_DOLLAR_3_BG_B.palette->data         , 16 * 2 );
    memcpy( &palette_64[16] , palette_SPR_BANKER_PART2_INTRO.data       , 16 * 2 );
}










void (*TABLE_INIT_STREET_DOLLAR[3])(void)       =   {
                                                        init_DOLLAR_TYPE1,
                                                        init_DOLLAR_TYPE2,
                                                        init_DOLLAR_TYPE3
                                                    };





































