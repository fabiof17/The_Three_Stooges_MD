#include <genesis.h>




#include "outils.h"
#include "variables.h"
#include "palettes.h"




#include "maps_BACKGROUNDS.h"
#include "maps_BANK.h"
#include "maps_CONTRACT.h"
#include "maps_DOLLAR.h"
#include "maps_GLOBAL.h"
#include "maps_INTRO.h"
#include "maps_QUESTION_MARK.h"
#include "maps_REWARD.h"
#include "maps_ROULETTE.h"
#include "maps_TRIVIA.h"




#include "routines_QUESTION_MARK.h"
#include "routines_ROULETTE.h"




#include "music.h"
#include "sound.h"




#include "sprites_BANK.h"
#include "sprites_DOLLAR.h"
#include "sprites_GLOBAL.h"
#include "sprites_INTRO.h"
#include "sprites_QUESTION_MARK.h"
#include "sprites_ROULETTE.h"
#include "sprites_SLAP.h"




#include "tables_BACKGROUNDS.h"
#include "tables_DOLLAR.h"
#include "tables_INTRO.h"
#include "tables_QUESTIONS.h"
#include "tables_ROULETTE.h"
#include "tables_TRIVIA.h"




void init_SYSTEM()
{  
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   4 BLACK PALETTES                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    PAL_setColors(0, (u16*) palette_black, 64, CPU);


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                  H40 MODE : 320*224                                  //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

	VDP_setScreenWidth320();
    VDP_setScreenHeight224();


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                SCROLLING MODE : PLANE                                //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

	VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);

}


void init_VARIABLES()
{
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                  REEL INITIALISATION                                 //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_REEL = REEL_GAME; // REEL_INTRO | REEL_GAME


    if(G_REEL == REEL_INTRO)
    {
        G_SCENE = SCENE_FADE_IN;
        G_SCENE_TYPE = SCENE_INTRO_SCREEN_1;
    }

    else if(G_REEL == REEL_GAME)
    {
        G_SCENE = SCENE_FADE_IN;
        G_SCENE_TYPE = SCENE_ROULETTE;
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                      GENERAL                                         //
    //                                                                                      //
    //**************************************************************************************// 

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                               INITIALISATION GENERALE                                //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_SCENE_LOADED              = FALSE;

    G_ADR_VRAM_BG_B             = 0;
    G_ADR_VRAM_BG_A             = 0;


    G_INDEX_1                   = 0;


    G_COUNTER_1                 = 0;


    G_DAY                       = 1;
    G_MONEY                     = 0;


    G_HIGHSTREET_POSITION       = 0;


    G_STREET_TYPE               = STREET_TYPE_0;

    G_TRIVIA_TYPE               = 0;


    G_HAND_SPEED                = 25;
    G_FINGER_NUMBER             = 4;


    G_REWARD                    = 250;


    G_SELECTED_QUESTION         = 0;


    G_POS_Y_CAMERA              = 0;


    G_QUESTION_LOCKED           = FALSE;

    


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                               GENERATE HAND MOVE ORDER                               //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    TABLE_GENERATED_HAND_POSITION[9] = 1;
    TABLE_GENERATED_HAND_POSITION[8] = 4;
    TABLE_GENERATED_HAND_POSITION[7] = 2;
    TABLE_GENERATED_HAND_POSITION[6] = 3;
    TABLE_GENERATED_HAND_POSITION[5] = 1;
    TABLE_GENERATED_HAND_POSITION[4] = 5;
    TABLE_GENERATED_HAND_POSITION[3] = 0;
    TABLE_GENERATED_HAND_POSITION[2] = 2;
    TABLE_GENERATED_HAND_POSITION[1] = 4;
    TABLE_GENERATED_HAND_POSITION[0] = 1;

    
    //**************************************************************************************//
    //                                                                                      //
    //                                    INTRODUCTION                                      //
    //                                                                                      //
    //**************************************************************************************// 

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                GENERAL INITIALISATION                                //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    /*G_BOOL_NEUTRE           = 0;
    G_COMPTEUR_NEUTRE_1     = 0;

    G_INDEX_NEUTRE_1        = 0;
    G_INDEX_NEUTRE_2        = 0;
    G_INDEX_NEUTRE_3        = 0;

    G_ADR_VRAM_DANEMARK     = 0;
    G_ADR_VRAM_HOLLANDE     = 0;
    G_ADR_VRAM_BELGIQUE     = 0;
    G_ADR_VRAM_NEUTRE_1     = 0;

    G_NB_PARTIE_ROCKET      = 5;


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                INITIALISATION SPRITES                                //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    for(i=0; i<38 ; i++)
    {
        sprite_NEUTRE[i] = NULL;
    }*/
    
}


void init_INTRO()
{
    // INTRO SCREEN 1 //
    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_1)
    {
        VDP_setPlaneSize(64,32,FALSE);
        
        SPR_initEx(460);
        
        VDP_setHilightShadow(TRUE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  LOADING BG_B TILES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B = TILE_USER_INDEX;

        VDP_loadTileSet(image_INTRO_SCREEN_1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_1_BG_B.tileset->numTile;
        SYS_doVBlankProcess();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    STOOGES SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -95, 154, TILE_ATTR(PAL2, TRUE, FALSE, FALSE)); // -95 , 142
        SPR_setFrame(sprite_STOOGES,14);



        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       SH SPRITES                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_SH_INTRO_SCREEN_1[0]  = SPR_addSprite(&tiles_SPR_0_SH_INTRO_SCREEN_1,    0,  24, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[1]  = SPR_addSprite(&tiles_SPR_1_SH_INTRO_SCREEN_1,   88,  32, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[2]  = SPR_addSprite(&tiles_SPR_2_SH_INTRO_SCREEN_1,  152,  38, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[3]  = SPR_addSprite(&tiles_SPR_3_SH_INTRO_SCREEN_1,  213,  35, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[4]  = SPR_addSprite(&tiles_SPR_4_SH_INTRO_SCREEN_1,  264,  40, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[5]  = SPR_addSprite(&tiles_SPR_5_SH_INTRO_SCREEN_1,    0, 103, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[6]  = SPR_addSprite(&tiles_SPR_6_SH_INTRO_SCREEN_1,   96, 104, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[7]  = SPR_addSprite(&tiles_SPR_7_SH_INTRO_SCREEN_1,  238, 106, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[8]  = SPR_addSprite(&tiles_SPR_8_SH_INTRO_SCREEN_1,    0, 158, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[9]  = SPR_addSprite(&tiles_SPR_9_SH_INTRO_SCREEN_1,   46, 148, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[10] = SPR_addSprite(&tiles_SPR_10_SH_INTRO_SCREEN_1, 136, 144, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[11] = SPR_addSprite(&tiles_SPR_11_SH_INTRO_SCREEN_1,   0, 176, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[12] = SPR_addSprite(&tiles_SPR_12_SH_INTRO_SCREEN_1, 278, 174, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_SH_INTRO_SCREEN_1[13] = SPR_addSprite(&tiles_SPR_13_SH_INTRO_SCREEN_1, 296, 173, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));

        SPR_update();
        SYS_doVBlankProcess();

        sprite_DEFENDER = SPR_addSprite(&tiles_SPR_DEFENDER_SH_INTRO_SCREEN_1,  56,  32, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));

        SPR_update();
        SYS_doVBlankProcess();

        sprite_OF       = SPR_addSprite(&tiles_SPR_OF_SH_INTRO_SCREEN_1,       118,  97, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_THE      = SPR_addSprite(&tiles_SPR_THE_SH_INTRO_SCREEN_1,      174,  99, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));

        SPR_update();
        SYS_doVBlankProcess();

        sprite_CROWN    = SPR_addSprite(&tiles_SPR_CROWN_SH_INTRO_SCREEN_1,     87, 136, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));

        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , palette_INTRO_SCREEN_1_0.data             , 16 * 2 );
		//memcpy( &palette_64[16] , image_INTRO_SCREEN_1_BG_A.palette->data  , 16 * 2 );
		memcpy( &palette_64[32] , palette_SPR_STOOGES.data                  , 16 * 2 );
		memcpy( &palette_64[48] , palette_SPR_SH_INTRO_SCREEN_1.data        , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;

        G_INDEX_PALETTE_CYCLE   = 0;
        

        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_INTRO_SCREEN_1;
        G_SCENE_NEXT            = SCENE_INTRO_SCREEN_1;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        XGM_setPCM(SOUND_INTRO_SCREEN1, PCM_INTRO_SCREEN1, sizeof(PCM_INTRO_SCREEN1));

    }

    // INTRO SCREEN 2 //
    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_2)
    {
        // CLEAN VRAM //
        u16 i = 0;

        for(i=16 ; i<1440 ; i++)
        {
            VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
        }




        VDP_setPlaneSize(64,32,TRUE);
        
        SPR_init();
        
        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  LOADING BG_B TILES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B = TILE_USER_INDEX;

        VDP_loadTileSet(image_INTRO_SCREEN_2_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_2_BG_B.tileset->numTile;
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  LOADING BG_A TILES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_INTRO_SCREEN_2_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_2_BG_A.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                 LOADING NUMBERS TILES                                //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_INTRO_SCREEN_2_BG_A1.tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_2_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_2_BG_A1.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_2_BG_A.tileset->numTile), 12, 5, 0, 0, 17, 18, CPU);
        SYS_doVBlankProcess();
        



        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_INTRO_SCREEN_2_BG_B.palette->data   , 16 * 2 );
		memcpy( &palette_64[16] , palette_BLACK.data                        , 16 * 2 );
		memcpy( &palette_64[32] , palette_BLACK.data                        , 16 * 2 );
		memcpy( &palette_64[48] , palette_BLACK.data                        , 16 * 2 );




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
        G_SCENE_TYPE            = SCENE_INTRO_SCREEN_2;
        G_SCENE_NEXT            = SCENE_INTRO_SCREEN_2;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//



        waitMs(2000);
    }

    // INTRO SCREEN 3 //
    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_3)
    {
        // CLEAN VRAM //
        u16 i = 0;

        for(i=16 ; i<1440 ; i++)
        {
            VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
        }




        VDP_setPlaneSize(64,32,FALSE);
        
        SPR_init();
        
        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  LOADING BG_B TILES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B = TILE_USER_INDEX;

        VDP_loadTileSet(image_INTRO_SCREEN_3_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_3_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_3_BG_B.tileset->numTile;
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  LOADING BG_A TILES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_INTRO_SCREEN_3_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_3_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 40, 11, 0, 0, 13, 8, CPU);
        SYS_doVBlankProcess();

        VDP_setVerticalScrollVSync(BG_A , -4);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    STOOGES SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  112, 154, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));
        SPR_setFrame(sprite_STOOGES,16);

        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_INTRO_SCREEN_3_BG_B.palette->data   , 16 * 2 );
		memcpy( &palette_64[16] , image_INTRO_SCREEN_3_BG_A.palette->data   , 16 * 2 );
		memcpy( &palette_64[32] , palette_SPR_STOOGES.data                  , 16 * 2 );
		memcpy( &palette_64[48] , palette_BLACK.data                        , 16 * 2 );




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
        G_SCENE_TYPE            = SCENE_INTRO_SCREEN_3;
        G_SCENE_NEXT            = SCENE_INTRO_SCREEN_3;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
    }

    // INTRO SCREEN 4 //
    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_4)
    {
        //
    }

    // INTRO SCREEN 5 //
    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_5)
    {
        //
    }

    // INTRO SCREEN 6 //
    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_6)
    {
        //
    }

    // INTRO SCREEN 5 //
    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_7)
    {
        VDP_setPlaneSize(64,32,FALSE);
        
        SPR_initEx(228);
        
        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  LOADING BG_B TILES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B = 0;

        VDP_loadTileSet(image_INTRO_SCREEN_7_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_7_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   GRANDMA TILES BG_B                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_GRANDMA_INTRO_BG_B_STEP0.tileset, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_B, image_GRANDMA_INTRO_BG_B_STEP0.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile), 6, 14, 0, 0, 5, 6, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile + image_GRANDMA_INTRO_BG_B_STEP0.tileset->numTile;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  LOADING BG_A TILES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_INTRO_SCREEN_7_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   GRANDMA TILES BG_A                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_GRANDMA_INTRO_BG_A_STEP0.tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_A, image_GRANDMA_INTRO_BG_A_STEP0.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile), 6, 14, 0, 0, 5, 6, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                     BANKER SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_BANKER[0] = SPR_addSprite(&tiles_SPR_BANKER_PART2,   105, 132, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
        sprite_BANKER[1] = SPR_addSprite(&tiles_SPR_BANKER_PART1,   105, 132, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));

        SPR_setZ(sprite_BANKER[0] , 0);
        SPR_setZ(sprite_BANKER[1] , 1);


        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_INTRO_SCREEN_7_BG_B.palette->data  , 16 * 2 );
		memcpy( &palette_64[16] , image_INTRO_SCREEN_7_BG_A.palette->data  , 16 * 2 );
		memcpy( &palette_64[32] , palette_SPR_BANKER_PART2_INTRO.data      , 16 * 2 );
		memcpy( &palette_64[48] , palette_SPR_STOOGES.data                 , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1   = 0;
        G_INDEX_1     = 0;
        G_INDEX_2     = 0;
        G_INDEX_3     = 0;
        

        G_SCENE             = SCENE_FADE_IN;
        G_SCENE_TYPE        = SCENE_INTRO_SCREEN_7;
        G_SCENE_NEXT        = SCENE_INTRO_SCREEN_7;

        G_SCENE_LOADED      = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        XGM_setPCM(SOUND_RIRE_INTRO, PCM_RIRE_INTRO, sizeof(PCM_RIRE_INTRO));
    }
}


void init_SCENE()
{
    // BANK //
    if(G_SCENE_TYPE == SCENE_BANK)
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

        VDP_loadTileSet(image_BANK_NUMBERS.tileset, TILE_FONT_INDEX + 16, CPU);




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
        VDP_loadTileSet(image_BANK_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_BANK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
        VDP_setTileMapEx(BG_B, image_BANK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_BANK_BG_B.tileset->numTile;
        

        VDP_loadTileSet(image_BANK_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_BANK_BG_A.tileset->numTile;


        VDP_loadTileSet(image_BANK_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);
        G_ADR_VRAM_HUB = G_ADR_VRAM_DIALOG + image_BANK_DIALOG.tileset->numTile;
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

        // 1 DAY SPENT //
        //G_DAY += 1;

        init_HUB();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        // ARROW SPRITE OFF SCREEN //
        SPR_setPosition(sprite_ARROW , -48 , -48);

        // STOOGES SPRITES OFF SCREEN //
        SPR_setPosition(sprite_STOOGES , -96 , -64);

        // BANKER SPRITES OFF SCREEN //
        sprite_BANKER[0] = SPR_addSprite(&tiles_SPR_BANKER_PART3,   -48, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE)); // 105 132
        sprite_BANKER[1] = SPR_addSprite(&tiles_SPR_BANKER_PART2,   -48, -64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE)); // 105 132
        SPR_setFrame(sprite_BANKER[1],3);

        // DIALOG ARROW //
        sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_BANK_ARROW,   -24, -32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));

        SPR_update();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_BANK_BG_B.palette->data             , 16 * 2 );
        memcpy( &palette_64[16] , palette_SPR_BANKER_PART2_INTRO.data       , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_PHASE_SEQUENCE        = BANKER_PHASE_WALKIN;
       

        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_BANK;
        G_SCENE_NEXT            = SCENE_BANK;

        G_SCENE_LOADED          = TRUE;
    }
    
    // BOXING //
    else if(G_SCENE_TYPE == SCENE_BOXING)
    {

        // CLEAN VRAM //
        u16 i = 0;

        for(i=16 ; i<1440 ; i++)
        {
            VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
        }




        VDP_setPlaneSize(64,32,TRUE);
        
        SPR_initEx(250);
        
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
        VDP_loadTileSet(image_STREET_BOXING_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_STREET_BOXING_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_BOXING_BG_B.tileset->numTile;
        SYS_doVBlankProcess();


        VDP_loadTileSet(image_STREET_BOXING_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_STREET_BOXING_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();




        VDP_setVerticalScroll(BG_B,0);
        VDP_setVerticalScroll(BG_A,0);





        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    STOOGES SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//





        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_STREET_BOXING_BG_B.palette->data    , 16 * 2 );
        memcpy( &palette_64[16] , image_STREET_BOXING_BG_A.palette->data    , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_STREET_TYPE           = STREET_TYPE_BOXING;
       

        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_BOXING;
        G_SCENE_NEXT            = SCENE_BOXING;

        G_SCENE_LOADED          = TRUE;
    }
    
    // DOCTORS //
    else if(G_SCENE_TYPE == SCENE_DOCTORS)
    {

        // CLEAN VRAM //
        u16 i = 0;

        for(i=16 ; i<1440 ; i++)
        {
            VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
        }




        VDP_setPlaneSize(64,32,TRUE);
        
        SPR_initEx(250);
        
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
        VDP_loadTileSet(image_STREET_DOCTORS_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_STREET_DOCTORS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_DOCTORS_BG_B.tileset->numTile;
        SYS_doVBlankProcess();


        VDP_loadTileSet(image_STREET_DOCTORS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_STREET_DOCTORS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();


        VDP_setVerticalScroll(BG_B,0);
        VDP_setVerticalScroll(BG_A,0);





        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    STOOGES SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//





        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_STREET_DOCTORS_BG_B.palette->data   , 16 * 2 );
        memcpy( &palette_64[16] , image_STREET_DOCTORS_BG_A.palette->data   , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_STREET_TYPE           = STREET_TYPE_DOCTORS;
       

        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_BOXING;
        G_SCENE_NEXT            = SCENE_BOXING;

        G_SCENE_LOADED          = TRUE;
    }

    // DOLLAR //
    else if(G_SCENE_TYPE == SCENE_DOLLAR)
    {
        // RANDOMLY SELECT BETWEEN : //
        // DOLLAR TYPE 1  (0) //
        // DOLLAR TYPE 2  (1) //
        // DOLLAR TYPE 3  (2) //
        u8 dollar_TYPE  = random_NUMBER(0 , 2);

        // LOAD TRIVIA TYPE SCENE //
        //G_SCENE_TYPE    = dollar_TYPE;

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      INIT STREET                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // POINTER DECLARATION //
        void (*ptr_INIT_DOLLAR)(void);

        // SETTING POINTER ON TRIVIA INIT FUNCTION //
        ptr_INIT_DOLLAR = TABLE_INIT_STREET_DOLLAR[dollar_TYPE];

        // RUNNING STREET INIT FUNCTION //
        (*ptr_INIT_DOLLAR)();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       INIT HUB                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //G_REWARD = TABLE_DOLLAR_REWARD[random_NUMBER(0,2)];

        G_MONEY += G_REWARD;

        // SPENT 1 DAY //
        G_DAY += 1;

        init_HUB();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        // ARROW SPRITE OFF SCREEN //
        SPR_setPosition(sprite_ARROW , -48 , -48);

        // STOOGES SPRITES OFF SCREEN //
        SPR_setPosition(sprite_STOOGES , -96 , -64);

        SPR_update();
        SYS_doVBlankProcess();

        // DOLLAR BAG SPRITE //
        sprite_DOLLAR_BAG = SPR_addSprite(&tiles_SPR_DOLLAR_BAG,  144, 168, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));

        // DIALOG ARROW //
        sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_DOLLAR_ARROW,  -16, -24, TILE_ATTR(PAL1, FALSE, FALSE, FALSE)); //166 104
        

        SPR_update();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        //G_STREET_TYPE           = STREET_TYPE_DOLLAR;
       

        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_DOLLAR;
        G_SCENE_NEXT            = SCENE_DOLLAR;

        G_SCENE_LOADED          = TRUE;
    }

    // QUESTION MARK //
    else if(G_SCENE_TYPE == SCENE_QUESTION_MARK)
    {
        // CLEAN VRAM //
        u16 i = 0;

        for(i=16 ; i<1440 ; i++)
        {
            VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
        }




        VDP_setPlaneSize(64,32,TRUE);
        
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
        VDP_setTileMapEx(BG_B, image_QUESTION_MARK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();


        G_POS_Y_CAMERA = 0;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);
        SYS_doVBlankProcess();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    STOOGES SPRITE                                    //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES  = SPR_addSprite(&tiles_SPR_STOOGES_WALK,   -96,  133, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));

        sprite_ICE_CUBE = SPR_addSprite(&tiles_SPR_ICE_CUBE,       149, 23, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));
        sprite_SCISSOR  = SPR_addSprite(&tiles_SPR_SCISSOR,        128,  0, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));
        sprite_ICE_CUBE_SHADOW = SPR_addSprite(&tiles_SPR_ICE_CUBE_SHADOW,       143, 31, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));


        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_QUESTION_MARK_BG_B.palette->data    , 16 * 2 );
        memcpy( &palette_64[16] , palette_BLACK.data                        , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_REWARD                = 250;


        G_PHASE_SEQUENCE        = 0;


        G_STREET_TYPE           = STREET_TYPE_QUESTION_MARK;       


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_QUESTION_MARK;
        G_SCENE_NEXT            = SCENE_QUESTION_MARK;

        G_SCENE_LOADED          = TRUE;
    }

    // SLAP //
    else if(G_SCENE_TYPE == SCENE_SLAP)
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
        VDP_loadTileSet(image_DOLLAR_1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_DOLLAR_1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
        VDP_setTileMapEx(BG_B, image_DOLLAR_1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_DOLLAR_1_BG_B.tileset->numTile;
        SYS_doVBlankProcess();

        // SLAP HUB //
        VDP_loadTileSet(image_SLAP_HUB.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_B, image_SLAP_HUB.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 9, 34, 0, 0, 22, 8, CPU);
        G_ADR_VRAM_HUB = G_ADR_VRAM_BG_A + image_SLAP_HUB.tileset->numTile;
        SYS_doVBlankProcess();


        VDP_setVerticalScroll(BG_B,224);
        VDP_setVerticalScroll(BG_A,224);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       INIT HUB                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // GENERATE NEXT POSITION IN HIGHSTREET //
        G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);

        // 1 DAY SPENT //
        G_DAY += 1;

        init_HUB();       




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  SLAP HAND SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_HAND_SLAP = SPR_addSprite(&tiles_SPR_HAND_SLAP,  153, 71, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  SLAP HAND SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_METER_SLAP = SPR_addSprite(&tiles_SPR_METER_SLAP,  -6, 55, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    STOOGES SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // ARROW SPRITE OFF SCREEN //
        SPR_setPosition(sprite_ARROW , -48 , -48);

        // STOOGES SPRITES OFF SCREEN //
        SPR_setPosition(sprite_STOOGES , -96 , -64);


        SPR_update();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_DOLLAR_1_BG_B.palette->data     , 16 * 2 );
		memcpy( &palette_64[16] , image_SLAP_HUB.palette->data          , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        //G_STREET_TYPE           = STREET_TYPE_SLAP;
       

        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_SLAP;
        G_SCENE_NEXT            = SCENE_SLAP;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        
    }

    // TRIVIA //
    else if(G_SCENE_TYPE == SCENE_TRIVIA_SELECT)
    {
        if(G_QUESTION_LOCKED == FALSE)
        {
            // RANDOMLY SELECT BETWEEN : //
            // TRIVIA TYPE 1  (14) //
            // TRIVIA TYPE 2  (15) //
            // TRIVIA TYPE 3  (16) //
            u8 trivia_TYPE  = random_NUMBER(14 , 15);

            // LOAD TRIVIA TYPE SCENE //
            G_TRIVIA_TYPE    = trivia_TYPE;
        }

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      INIT STREET                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // POINTER DECLARATION //
        void (*ptr_INIT_TRIVIA)(void);

        // SETTING POINTER ON TRIVIA INIT FUNCTION //
        ptr_INIT_TRIVIA = TABLE_INIT_MINIGAME_TRIVIA[G_TRIVIA_TYPE - 14];

        // RUNNING STREET INIT FUNCTION //
        (*ptr_INIT_TRIVIA)();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************// 

        // ARROW SPRITE OFF SCREEN //
        SPR_setPosition(sprite_ARROW , -48 , -48);

        // STOOGES SPRITES OFF SCREEN //
        //SPR_setPosition(sprite_STOOGES , -96 , -64);

        SPR_update();
        SYS_doVBlankProcess();
    }

    // WAITERS //
    else if(G_SCENE_TYPE == SCENE_WAITERS)
    {
        //
    }

    // ROULETTE //
    else if(G_SCENE_TYPE == SCENE_ROULETTE)
    {
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      INIT STREET                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // POINTER DECLARATION //
        void (*ptr_INIT_STREET)(void);

        // SETTING POINTER ON STREET INIT FUNCTION //
        ptr_INIT_STREET = TABLE_INIT_STREET_BEGINNING[G_STREET_TYPE];

        // RUNNING STREET INIT FUNCTION //
        (*ptr_INIT_STREET)();


        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       INIT HUB                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        init_HUB();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_COUNTER_ROULETTE      = 0;
        G_CURRENT_TURN          = 9;

        G_QUESTION_LOCKED       = FALSE;

        G_PHASE_SEQUENCE        = ROULETTE_PHASE_READY;
        

        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_ROULETTE;
        G_SCENE_NEXT            = SCENE_ROULETTE;

        G_SCENE_LOADED          = TRUE;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //XGM_setPCM(MUSIC_ROULETTE, PCM_MUSIC_ROULETTE, sizeof(PCM_MUSIC_ROULETTE));
        
        XGM_setPCM(SOUND_WALKOUT, PCM_WALKOUT, sizeof(PCM_WALKOUT));
        XGM_setPCM(SOUND_SWATTER, PCM_SWATTER, sizeof(PCM_SWATTER));

    }  

    // TRIVIA CONTRACT
    else if(G_SCENE_TYPE == SCENE_TRIVIA_QUESTION)
    {
        // CLEAN VRAM //
        u16 i = 0;

        for(i=16 ; i<1440 ; i++)
        {
            VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
        }




        VDP_setPlaneSize(64,32,TRUE);
        
        SPR_init();
        
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
        VDP_loadTileSet(image_TRIVIA_QUESTION_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_TRIVIA_QUESTION_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_QUESTION_BG_B.tileset->numTile;
        SYS_doVBlankProcess();

        // BG_B //
        VDP_loadTileSet(image_TRIVIA_QUESTION_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_TRIVIA_QUESTION_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_QUESTION = G_ADR_VRAM_BG_A + image_TRIVIA_QUESTION_BG_A.tileset->numTile; 
        SYS_doVBlankProcess();

        // LOAD QUESTION TILESET //
        VDP_loadTileSet(TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tileset, G_ADR_VRAM_QUESTION, CPU);

        // DISPLAY QUESTION //
        VDP_setTileMapEx(BG_B, TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_QUESTION), 6, 13, 0, 0, 29, 3, CPU);

        // DISPLAY ANSWERS //
        VDP_setTileMapEx(BG_B, TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_QUESTION), 6, 18, 0, 4, 29, 3, CPU);


        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B , G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A , G_POS_Y_CAMERA);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_TRIVIA_QUESTION_BG_B.palette->data      , 16 * 2 );
        memcpy( &palette_64[16] , image_TRIVIA_QUESTION_BG_A.palette->data      , 16 * 2 );
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
        G_SCENE_TYPE            = SCENE_TRIVIA_QUESTION;
        G_SCENE_NEXT            = SCENE_TRIVIA_QUESTION;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
    }

    // REWARD //
    else if(G_SCENE_TYPE == SCENE_REWARD)
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

        VDP_loadTileSet(image_FONT.tileset, TILE_FONT_INDEX, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   LOADING BG TILES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B = TILE_USER_INDEX;

        // BG_B //
        VDP_loadTileSet(image_REWARD_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_REWARD_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_REWARD_BG_B.tileset->numTile;
        SYS_doVBlankProcess();

        // SLAP HUB //
        VDP_loadTileSet(image_REWARD_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_REWARD_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      PRINT TEXT                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // REWARD AMOUNT //
        if(G_REWARD < 10)
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
        }




        VDP_setVerticalScroll(BG_A , -4);
 



        //**************************************************************************************//
        //                                                                                      //
        //                                       SPRITES                                        //
        //                                                                                      //
        //**************************************************************************************// 

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       SLAP DAY                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_DAY = SPR_addSprite(&tiles_SPR_DAY,  224, 63, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));
        SPR_setFrame(sprite_DAY , G_DAY - 1);

        SPR_update();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_REWARD_BG_B.palette->data       , 16 * 2 );
		memcpy( &palette_64[16] , image_REWARD_BG_A.palette->data       , 16 * 2 );
		memcpy( &palette_64[32] , palette_BLACK.data                    , 16 * 2 );
		memcpy( &palette_64[48] , palette_BLACK.data                    , 16 * 2 );




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
        G_SCENE_TYPE            = SCENE_REWARD;
        G_SCENE_NEXT            = SCENE_REWARD;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
    
    }    

    // REWARD QUESTION MARK //
    else if(G_SCENE_TYPE == SCENE_REWARD_QUESTION_MARK)
    {
        // CLEAN VRAM //
        u16 i = 0;

        for(i=16 ; i<1440 ; i++)
        {
            VDP_loadTileSet(image_EMPTY_TILE.tileset , i , CPU);
        }




        VDP_setPlaneSize(64,32,TRUE);
        
        SPR_init();
        
        VDP_setHilightShadow(FALSE);




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
        VDP_loadTileSet(image_CONTRACT_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CONTRACT_BG_B.tileset->numTile;

        // BG_A //
        VDP_loadTileSet(image_CONTRACT_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_CONTRACT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
        //SYS_doVBlankProcess();

        // TEXT //
        VDP_loadTileSet(image_TEXT_REWARD_QUESTION_MARK.tileset, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_B, image_TEXT_REWARD_QUESTION_MARK.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile), 6, 6, 0, 0, 27, 11, CPU);




        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        // GENERATE NEXT POSITION IN HIGHSTREET //
        G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);



        SPR_setPosition(sprite_STOOGES,-96,0);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_CONTRACT_BG_B.palette->data         , 16 * 2 );
        memcpy( &palette_64[16] , image_CONTRACT_BG_A.palette->data         , 16 * 2 );
        memcpy( &palette_64[32] , palette_BLACK.data                        , 16 * 2 );
        memcpy( &palette_64[48] , palette_BLACK.data                        , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_PHASE_SEQUENCE        = 0;
       

        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_REWARD_QUESTION_MARK;
        G_SCENE_NEXT            = SCENE_REWARD_QUESTION_MARK;

        G_SCENE_LOADED          = TRUE;
    }








}