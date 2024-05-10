#include <genesis.h>



#include "outils.h"
#include "palettes.h"
#include "structures.h"
#include "variables.h"



#include "maps_BACKGROUNDS.h"
#include "maps_GLOBAL.h"
#include "maps_TRIVIA.h"

#include "routines_ROULETTE.h"


#include "sprites_TRIVIA.h"




#include "tables_QUESTIONS.h"




const struct_WALK_STOOGES_      TABLE_ANIM_STOOGES_WALKIN_TRIVIA_TYPE1[29]  =   {
                                                                                    {    5 ,  0 , -87 },
                                                                                    {   11 ,  1 , -79 },
                                                                                    {   17 ,  2 , -73 },
                                                                                    {   23 ,  3 , -65 },
                                                                                    {   29 ,  4 , -57 },
                                                                                    {   35 ,  5 , -49 },
                                                                                    {   41 ,  6 , -40 },
                                                                                    {   47 ,  7 , -31 },
                                                                                    {   53 ,  0 , -23 },
                                                                                    {   59 ,  1 , -17 },
                                                                                    {   65 ,  2 ,  -9 },
                                                                                    {   71 ,  3 ,  -1 },
                                                                                    {   77 ,  4 ,  7  },
                                                                                    {   83 ,  5 ,  17 },
                                                                                    {   89 ,  6 ,  23 },
                                                                                    {   95 ,  7 ,  32 },
                                                                                    {  101 ,  0 ,  41 },
                                                                                    {  107 ,  1 ,  49 },
                                                                                    {  113 ,  2 ,  55 },
                                                                                    {  119 ,  3 ,  63 },
                                                                                    {  125 ,  4 ,  71 },
                                                                                    {  131 ,  5 ,  81 },
                                                                                    {  138 , 10 ,  88 },
                                                                                    {  146 , 11 ,  95 },
                                                                                    {  156 , 12 ,  95 },
                                                                                    {  170 , 13 , 116 },
                                                                                    {  185 , 14 , 116 },
                                                                                    {  203 , 15 , 110 },
                                                                                    {  224 , 16 , 114 }
                                                                                };


const struct_WALK_STOOGES_      TABLE_ANIM_STOOGES_WALKIN_TRIVIA_TYPE2[29]  =   {
                                                                                    {    5 ,  0 , -87 },
                                                                                    {   14 ,  1 , -79 },
                                                                                    {   23 ,  2 , -73 },
                                                                                    {   30 ,  3 , -65 },
                                                                                    {   40 ,  4 , -57 },
                                                                                    {   48 ,  5 , -49 },
                                                                                    {   56 ,  6 , -40 },
                                                                                    {   65 ,  7 , -31 },
                                                                                    {   72 ,  0 , -23 },
                                                                                    {   82 ,  1 , -17 },
                                                                                    {   90 ,  2 ,  -9 },
                                                                                    {   98 ,  3 ,  -1 },
                                                                                    {  107 ,  4 ,  7  },
                                                                                    {  115 ,  5 ,  17 },
                                                                                    {  124 ,  6 ,  23 },
                                                                                    {  132 ,  7 ,  32 },
                                                                                    {  140 ,  0 ,  41 },
                                                                                    {  149 ,  1 ,  49 },
                                                                                    {  157 ,  2 ,  55 },
                                                                                    {  166 ,  3 ,  63 },
                                                                                    {  174 ,  4 ,  71 },
                                                                                    {  182 ,  5 ,  81 },
                                                                                    {  192 , 10 ,  88 },
                                                                                    {  204 , 11 ,  95 },
                                                                                    {  216 , 12 ,  95 },
                                                                                    {  223 , 16 , 114 },
                                                                                    {  510 , 34 , 114 },
                                                                                    {  634 , 15 , 114 },
                                                                                    {  651 , 35 , 114 }
                                                                                };




void init_TRIVIA_MINIGAME_TYPE1()
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
    VDP_loadTileSet(image_TRIVIA_TYPE1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_TYPE1_BG_B.tileset->numTile;
    

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_TYPE1_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_TRIVIA_TYPE1_BG_A.tileset->numTile;
    



    // DIALOG //
    VDP_loadTileSet(image_TRIVIA_TYPE1_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);
    G_ADR_VRAM_QUESTION = G_ADR_VRAM_DIALOG + image_TRIVIA_TYPE1_DIALOG.tileset->numTile;

    // RANDOM QUESTION //
    //G_SELECTED_QUESTION = random_NUMBER(0,6);

    // LOAD QUESTION TILESET //
    VDP_loadTileSet(TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tileset, G_ADR_VRAM_QUESTION, CPU);
    G_ADR_VRAM_HUB = G_ADR_VRAM_QUESTION + TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tileset->numTile;


    SYS_doVBlankProcess();


    G_POS_Y_CAMERA = 224;

    VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
    VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       INIT HUB                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    // GENERATE NEXT POSITION IN HIGHSTREET //
    G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);

    init_HUB();




    //**************************************************************************************//
    //                                                                                      //
    //                                      SPRITES                                         //
    //                                                                                      //
    //**************************************************************************************// 

    // DIALOG ARROW //
    sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_DIALOG1,  -40, -40, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));

    // ANSWER SPRITES //
    sprite_ANSWER_A = SPR_addSprite(&tiles_SPR_ANSWER_A,  -48, -48, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
    sprite_ANSWER_B = SPR_addSprite(&tiles_SPR_ANSWER_B,  -48, -48, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
    sprite_ANSWER_C = SPR_addSprite(&tiles_SPR_ANSWER_C,  -48, -48, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));

    // STOOGES SPRITES //
    SPR_setPosition(sprite_STOOGES , -96 , -64);

    SPR_update();




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

    //G_COUNTER_ROULETTE      = 0;
    //G_CURRENT_TURN          = 9;
    
    G_PHASE_SEQUENCE        = TRIVIA_PHASE_WALKIN;

    G_STREET_TYPE           = STREET_TYPE_TRIVIA_1;
  

    G_SCENE                 = SCENE_FADE_IN;
    G_SCENE_TYPE            = SCENE_TRIVIA_MINIGAME_TYPE1;
    G_SCENE_NEXT            = SCENE_TRIVIA_MINIGAME_TYPE1;

    G_SCENE_LOADED          = TRUE;
}


void init_TRIVIA_MINIGAME_TYPE2()
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
    VDP_loadTileSet(image_TRIVIA_TYPE2_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_B, image_TRIVIA_TYPE2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_TYPE2_BG_B.tileset->numTile;
    

    // BG_B //
    VDP_loadTileSet(image_TRIVIA_TYPE2_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE2_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
    VDP_setTileMapEx(BG_A, image_TRIVIA_TYPE2_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  28, 0, 0, 40, 28, CPU);
    G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_TRIVIA_TYPE2_BG_A.tileset->numTile;
    



    // DIALOG //
    VDP_loadTileSet(image_TRIVIA_TYPE1_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);
    G_ADR_VRAM_QUESTION = G_ADR_VRAM_DIALOG + image_TRIVIA_TYPE1_DIALOG.tileset->numTile;

    // LOAD QUESTION TILESET //
    VDP_loadTileSet(TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tileset, G_ADR_VRAM_QUESTION, CPU);
    G_ADR_VRAM_HUB = G_ADR_VRAM_QUESTION + TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tileset->numTile;


    SYS_doVBlankProcess();


    G_POS_Y_CAMERA = 224;

    VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
    VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       INIT HUB                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    // IF WE ALREADY SAW THE QUESTION SCREEN //
    if(G_PHASE_SEQUENCE == TRIVIA_PHASE_TURN_BACK)
    {
        // GENERATE NEXT POSITION IN HIGHSTREET //
        G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);
    }

    init_HUB();

    // IF WE ALREADY SAW THE QUESTION SCREEN //
    if(G_PHASE_SEQUENCE == TRIVIA_PHASE_TURN_BACK)
    {      
        // SET THE STOOGES TO LOOK THROUGH THE FENCE //
        SPR_setPosition(sprite_STOOGES,114,133);
        SPR_setFrame(sprite_STOOGES,35);
    }

    else
    {
        SPR_setPosition(sprite_STOOGES , -96 , -64);
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                      SPRITES                                         //
    //                                                                                      //
    //**************************************************************************************// 

    // DIALOG ARROW //
    sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_DIALOG1,  -40, -40, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));

    // ANSWER SPRITES //
    sprite_ANSWER_A = SPR_addSprite(&tiles_SPR_ANSWER_A,  -48, -48, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));
    sprite_ANSWER_B = SPR_addSprite(&tiles_SPR_ANSWER_B,  -48, -48, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));
    sprite_ANSWER_C = SPR_addSprite(&tiles_SPR_ANSWER_C,  -48, -48, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));

    SPR_update();




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

    //G_COUNTER_ROULETTE      = 0;
    //G_CURRENT_TURN          = 9;

    G_STREET_TYPE           = STREET_TYPE_TRIVIA_2;
  

    G_SCENE                 = SCENE_FADE_IN;
    G_SCENE_TYPE            = SCENE_TRIVIA_MINIGAME_TYPE2;
    G_SCENE_NEXT            = SCENE_TRIVIA_MINIGAME_TYPE2;

    G_SCENE_LOADED          = TRUE;
}







void (*TABLE_INIT_MINIGAME_TRIVIA[2])(void)     =   {
                                                        init_TRIVIA_MINIGAME_TYPE1,
                                                        init_TRIVIA_MINIGAME_TYPE2
                                                    };


