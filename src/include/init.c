#include <genesis.h>




#include "custom_tools.h"
#include "variables.h"
#include "palettes.h"
#include "structures.h"




#include "maps_BACKGROUNDS.h"
#include "maps_BANK.h"
#include "maps_BOXING.h"
#include "maps_CONTRACT.h"
#include "maps_CRACKERS.h"
#include "maps_DISCLAIMER.h"
#include "maps_DOCTORS.h"
#include "maps_DOLLAR.h"
#include "maps_GAMEOVER.h"
#include "maps_GLOBAL.h"
#include "maps_INTRO.h"
#include "maps_LOGO.h"
#include "maps_QUESTION_MARK.h"
#include "maps_REWARD.h"
#include "maps_ROULETTE.h"
#include "maps_SAFE.h"
#include "maps_SLAP.h"
#include "maps_THE_END.h"
#include "maps_TRIVIA.h"
#include "maps_WAITERS.h"




#include "routines_QUESTION_MARK.h"
#include "routines_ROULETTE.h"




#include "music.h"
#include "sound.h"




#include "sprites_BANK.h"
#include "sprites_BOXING.h"
#include "sprites_CRACKERS.h"
#include "sprites_DOCTORS.h"
#include "sprites_DOLLAR.h"
#include "sprites_GAMEOVER.h"
#include "sprites_GLOBAL.h"
#include "sprites_INTRO.h"
#include "sprites_LOGO.h"
#include "sprites_QUESTION_MARK.h"
#include "sprites_ROULETTE.h"
#include "sprites_SAFE.h"
#include "sprites_SLAP.h"
#include "sprites_THE_END.h"
#include "sprites_WAITERS.h"




#include "tables_BACKGROUNDS.h"
#include "tables_BOXING.h"
#include "tables_CRACKERS.h"
#include "tables_DOCTORS.h"
#include "tables_DOLLAR.h"
#include "tables_GLOBAL.h"
#include "tables_INTRO.h"
#include "tables_QUESTIONS.h"
#include "tables_ROULETTE.h"
#include "tables_SAFE.h"
#include "tables_TRIVIA.h"
#include "tables_WAITERS.h"




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
    //**************************************************************************************//
    //                                                                                      //
    //                                  REEL INITIALISATION                                 //
    //                                                                                      //
    //**************************************************************************************//

    G_REEL = REEL_DISCLAIMER; // REEL_DISCLAIMER | REEL_INTRO | REEL_GAME | REEL_THE_END




    //**************************************************************************************//
    //                                                                                      //
    //                                        DEBUG                                         //
    //                                                                                      //
    //**************************************************************************************//

    if(G_REEL == REEL_INTRO)
    {
        G_SCENE_TYPE = SCENE_INTRO_SCREEN_1;
    }

    else if(G_REEL == REEL_GAME)
    {
        G_SCENE_TYPE = SCENE_BOXING_SCREEN_TYPE3; //SCENE_ROULETTE | SCENE_DOCTORS_MINIGAME | SCENE_CRACKERS_MINIGAME | SCENE_GAMEOVER | SCENE_BOXING_MINIGAME
    }

    else if(G_REEL == REEL_THE_END)
    {
        G_SCENE_TYPE = SCENE_THE_END;
    }




    //**************************************************************************************//
    //                                                                                      //
    //                                      GENERAL                                         //
    //                                                                                      //
    //**************************************************************************************//

    setRandomSeed(1024);

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                  GENERAL VARIABLES                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_SCENE_LOADED              = FALSE;

    G_ADR_VRAM_BG_B             = 0;
    G_ADR_VRAM_BG_A             = 0;


    G_COUNTER_1                 = 0;
    G_INDEX_1                   = 0;
    G_INDEX_2                   = 0;
    G_INDEX_3                   = 0;


    G_MONEY                     = 0;

    G_PAUSE                     = FALSE;

    G_LUCK                      = TRUE;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                      ROULETTE                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_STREET_TYPE               = STREET_TYPE_0;
    G_HIGHSTREET_POSITION       = 0;

    G_DAY                       = 1;//1

    G_HAND_SPEED                = 30;
    G_FINGER_NUMBER             = 4;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                        SLAP                                          //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_POS_X_METER_SLAP          = -4;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       REWARD                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_REWARD                    = 0;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       TRIVIA                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_TRIVIA_TYPE               = 0;
    G_SELECTED_QUESTION         = 0;

    G_QUESTION_LOCKED           = FALSE;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   DOCTORS MINIGAME                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_POS_Y_CAMERA              = 0;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                  CRACKERS MINIGAME                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                IMPORTANT : THESE VARIABLES MUST BE INITIALIZED HERE                  //
    //                AND BE REINITIALIZED AFTER MINIGAME COMPLETION                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_CRACKERS_INIT             = FALSE;
    G_CRACKERS_SCREEN_TYPE      = CRACKERS_SCREEN_SPREAD;

    G_NUMBER_CRACKERS_MAX       = 14;
    G_NUMBER_CRACKERS           = 14;
    G_NUMBER_GRABBED_CRACKERS   = 14;//14




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   BOXING MINIGAME                                    //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_RUN_DIRECTION = DIRECTION_FW;

    G_INDEX_WATCH = 0;

    G_INDEX_BOXERS = 0;

    G_INDEX_ROUND = 0;




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




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         AUDIO                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    //--------------------------------------------------------------------------------------//
    //                                        INTRO                                         //
    //--------------------------------------------------------------------------------------//

    XGM_setPCM(SOUND_INTRO_SCREEN1, PCM_INTRO_SCREEN1, sizeof(PCM_INTRO_SCREEN1));
    XGM_setPCM(SOUND_BIP, PCM_BIP, sizeof(PCM_BIP));
    XGM_setPCM(SOUND_BANKER_LAUGH, PCM_BANKER_LAUGH, sizeof(PCM_BANKER_LAUGH));
    XGM_setPCM(SOUND_MONEY_QUICK, PCM_MONEY_QUICK, sizeof(PCM_MONEY_QUICK));

    //--------------------------------------------------------------------------------------//
    //                                       ROULETTE                                       //
    //--------------------------------------------------------------------------------------//

    XGM_setPCM(SOUND_HAND, PCM_HAND, sizeof(PCM_HAND));
    XGM_setPCM(SOUND_WALKOUT, PCM_LETS_RIDE, sizeof(PCM_LETS_RIDE));
    XGM_setPCM(SOUND_SWATTER, PCM_SWATTER, sizeof(PCM_SWATTER));


    //--------------------------------------------------------------------------------------//
    //                                        DOLLAR                                        //
    //--------------------------------------------------------------------------------------//

    XGM_setPCM(SOUND_HEAD_SHOCK, PCM_HEAD_SHOCK, sizeof(PCM_HEAD_SHOCK));
    XGM_setPCM(SOUND_JOY_CRY, PCM_JOY_CRY, sizeof(PCM_JOY_CRY));


    //--------------------------------------------------------------------------------------//
    //                                       CRACKERS                                       //
    //--------------------------------------------------------------------------------------//

    XGM_setPCM(SOUND_MONEY,  PCM_MONEY,  sizeof(PCM_MONEY));
    XGM_setPCM(SOUND_OYSTER, PCM_OYSTER, sizeof(PCM_OYSTER));

    XGM_setPCM(SOUND_CRACKERS_CRY_1, PCM_CRACKERS_CRY_1, sizeof(PCM_CRACKERS_CRY_1));
    XGM_setPCM(SOUND_CRACKERS_CRY_2, PCM_CRACKERS_CRY_2, sizeof(PCM_CRACKERS_CRY_2));
    XGM_setPCM(SOUND_CRACKERS_CRY_3, PCM_CRACKERS_CRY_3, sizeof(PCM_CRACKERS_CRY_3));
    XGM_setPCM(SOUND_CRACKERS_CRY_4, PCM_CRACKERS_CRY_4, sizeof(PCM_CRACKERS_CRY_4));
    XGM_setPCM(SOUND_CRACKERS_CRY_5, PCM_CRACKERS_CRY_5, sizeof(PCM_CRACKERS_CRY_5));


    //--------------------------------------------------------------------------------------//
    //                                         SLAP                                         //
    //--------------------------------------------------------------------------------------//

    XGM_setPCM(SOUND_SLAP_MISS_1, PCM_SLAP_MISS_1, sizeof(PCM_SLAP_MISS_1));
    XGM_setPCM(SOUND_SLAP_MISS_2, PCM_SLAP_MISS_2, sizeof(PCM_SLAP_MISS_2));
    XGM_setPCM(SOUND_SLAP_MISS_3, PCM_SLAP_MISS_3, sizeof(PCM_SLAP_MISS_3));
    XGM_setPCM(SOUND_SLAP_MISS_4, PCM_SLAP_MISS_4, sizeof(PCM_SLAP_MISS_4));

    XGM_setPCM(SOUND_SLAP_EAR      , PCM_SLAP_EAR      , sizeof(PCM_SLAP_EAR));
    XGM_setPCM(SOUND_SLAP_EYES     , PCM_SLAP_EYES     , sizeof(PCM_SLAP_EYES));
    XGM_setPCM(SOUND_SLAP_KNEE     , PCM_SLAP_KNEE     , sizeof(PCM_SLAP_KNEE));
    XGM_setPCM(SOUND_SLAP_CHEEK    , PCM_SLAP_CHEEK    , sizeof(PCM_SLAP_CHEEK));
    XGM_setPCM(SOUND_SLAP_BELLY    , PCM_SLAP_BELLY    , sizeof(PCM_SLAP_BELLY));
    XGM_setPCM(SOUND_SLAP_FOREHEAD , PCM_SLAP_FOREHEAD , sizeof(PCM_SLAP_FOREHEAD));
    XGM_setPCM(SOUND_SLAP_HIT      , PCM_SLAP_HIT      , sizeof(PCM_SLAP_HIT));


    //--------------------------------------------------------------------------------------//
    //                                       DOCTORS                                        //
    //--------------------------------------------------------------------------------------//

    XGM_setPCM(SOUND_VOICE_DOCTORS , PCM_VOICE_DOCTORS , sizeof(PCM_VOICE_DOCTORS));
    XGM_setPCM(SOUND_DOCTORS_CRY_1 , PCM_DOCTORS_CRY_1 , sizeof(PCM_DOCTORS_CRY_1));
    XGM_setPCM(SOUND_DOCTORS_CRY_2 , PCM_DOCTORS_CRY_2 , sizeof(PCM_DOCTORS_CRY_2));
    XGM_setPCM(SOUND_DOCTORS_CRASH_1 , PCM_DOCTORS_CRASH_1 , sizeof(PCM_DOCTORS_CRASH_1));
    XGM_setPCM(SOUND_DOCTORS_CRASH_2 , PCM_DOCTORS_CRASH_2 , sizeof(PCM_DOCTORS_CRASH_2));
    XGM_setPCM(SOUND_DOCTORS_CRASH_3 , PCM_DOCTORS_CRASH_3 , sizeof(PCM_DOCTORS_CRASH_3));
    XGM_setPCM(SOUND_ENGINE_1 , PCM_ENGINE_1 , sizeof(PCM_ENGINE_1));
    XGM_setPCM(SOUND_ENGINE_2 , PCM_ENGINE_2 , sizeof(PCM_ENGINE_2));
    XGM_setPCM(SOUND_ENGINE_3 , PCM_ENGINE_3 , sizeof(PCM_ENGINE_3));
    XGM_setPCM(SOUND_TIRE , PCM_TIRE , sizeof(PCM_TIRE));


    //--------------------------------------------------------------------------------------//
    //                                       WAITERS                                        //
    //--------------------------------------------------------------------------------------//

    XGM_setPCM(SOUND_PIE_THROW , PCM_PIE_THROW , sizeof(PCM_PIE_THROW));
    XGM_setPCM(SOUND_PIE_HIT , PCM_PIE_HIT , sizeof(PCM_PIE_HIT));
    XGM_setPCM(SOUND_PIE_WALL , PCM_PIE_WALL , sizeof(PCM_PIE_WALL));


    //--------------------------------------------------------------------------------------//
    //                                       BOXING                                         //
    //--------------------------------------------------------------------------------------//
    XGM_setPCM(SOUND_BOXING_1_2 , PCM_BOXING_1_2 , sizeof(PCM_BOXING_1_2));
    XGM_setPCM(SOUND_BOXING_3 , PCM_BOXING_3 , sizeof(PCM_BOXING_3));


    //--------------------------------------------------------------------------------------//
    //                                    QUESTION MARK                                     //
    //--------------------------------------------------------------------------------------//
    XGM_setPCM(SOUND_ICE_FALL , PCM_ICE_FALL , sizeof(PCM_ICE_FALL));


    //--------------------------------------------------------------------------------------//
    //                                       TRIVIA                                         //
    //--------------------------------------------------------------------------------------//
    XGM_setPCM(SOUND_TRIVIA_1 , PCM_TRIVIA_1 , sizeof(PCM_TRIVIA_1));
    XGM_setPCM(SOUND_TRIVIA_2 , PCM_TRIVIA_2 , sizeof(PCM_TRIVIA_2));
    XGM_setPCM(SOUND_HEAD_TRIVIA , PCM_HEAD_TRIVIA , sizeof(PCM_HEAD_TRIVIA));
    XGM_setPCM(SOUND_WRONG_ANSWER , PCM_WRONG_ANSWER , sizeof(PCM_WRONG_ANSWER));


    //--------------------------------------------------------------------------------------//
    //                                        SAFE                                          //
    //--------------------------------------------------------------------------------------//
    XGM_setPCM(SOUND_CHEST_FALL , PCM_CHEST_FALL , sizeof(PCM_CHEST_FALL));


    //--------------------------------------------------------------------------------------//
    //                                       BOXING                                         //
    //--------------------------------------------------------------------------------------//
    XGM_setPCM(SOUND_BARGING , PCM_BARGING , sizeof(PCM_BARGING));
    XGM_setPCM(SOUND_KO , PCM_KO , sizeof(PCM_KO));
    XGM_setPCM(SOUND_HIT_OBSTACLE , PCM_HIT_OBSTACLE , sizeof(PCM_HIT_OBSTACLE));
    XGM_setPCM(SOUND_HIT_LAMP , PCM_HIT_LAMP , sizeof(PCM_HIT_LAMP));
    XGM_setPCM(SOUND_GONG , PCM_GONG , sizeof(PCM_GONG));
    XGM_setPCM(SOUND_SLIDE , PCM_SLIDE , sizeof(PCM_SLIDE));
    XGM_setPCM(SOUND_CROWD , PCM_CROWD , sizeof(PCM_CROWD));
    XGM_setPCM(SOUND_FOOT_STEP , PCM_FOOT_STEP , sizeof(PCM_FOOT_STEP));
}


void init_DISCLAIMER()
{
    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,32,TRUE);

    SPR_init();

    VDP_setHilightShadow(FALSE);




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

    VDP_loadTileSet(image_DISCLAIMER_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_DISCLAIMER_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_DISCLAIMER_BG_B.palette->data             , 16 * 2 );




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       VARIABLES                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_COUNTER_1             = 0;

    G_SCENE                 = SCENE_FADE_IN;
    G_SCENE_NEXT            = SCENE_DISCLAIMER_SCREEN;

    G_SCENE_LOADED          = TRUE;
}


void init_LOGO()
{
    //**************************************************************************************//
    //                                                                                      //
    //                                    SETUP DISPLAY                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_setPlaneSize(64,32,TRUE);

    SPR_init();

    VDP_setHilightShadow(FALSE);




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

    VDP_loadTileSet(image_LOGO_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_LOGO_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                      SPRITES                                         //
    //                                                                                      //
    //**************************************************************************************//

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                   STOOGES SPRITES                                    //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_LOGO,  116, 146, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
    //SPR_setFrame(sprite_STOOGES,14);

    SPR_update();




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_LOGO_BG_B.palette->data             , 16 * 2 );
    memcpy( &palette_64[16] , palette_SPR_STOOGES.data                  , 16 * 2 );




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
    G_SCENE_NEXT            = SCENE_LOGO_SCREEN;

    G_SCENE_LOADED          = TRUE;
}


void init_INTRO()
{
    // INTRO SCREEN 1 //
    if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_1)
    {
        //**************************************************************************************//
        //                                                                                      //
        //                                    SETUP DISPLAY                                     //
        //                                                                                      //
        //**************************************************************************************//

        VDP_setPlaneSize(64,32,FALSE);

        SPR_initEx(324);

        VDP_setHilightShadow(TRUE);




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

        VDP_loadTileSet(image_INTRO_SCREEN_1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_1_BG_B.tileset->numTile;




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

        //sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -95, 154, TILE_ATTR(PAL2, TRUE, FALSE, FALSE)); // -95 , 142
        sprite_STOOGES = SPR_addSpriteEx(&tiles_SPR_STOOGES_WALK, -95, 154, TILE_ATTR_FULL(PAL2, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 1), SPR_FLAG_AUTO_TILE_UPLOAD);

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

        sprite_DEFENDER_1 = SPR_addSprite(&tiles_SPR_DEFENDER_1_SH_INTRO_SCREEN_1,  57,  32, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_DEFENDER_2 = SPR_addSprite(&tiles_SPR_DEFENDER_2_SH_INTRO_SCREEN_1, 209,  40, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_DEFENDER_3 = SPR_addSprite(&tiles_SPR_DEFENDER_3_SH_INTRO_SCREEN_1, 225,  48, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_DEFENDER_4 = SPR_addSprite(&tiles_SPR_DEFENDER_4_SH_INTRO_SCREEN_1, 203,  31, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));

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

        XGM_startPlay(MUSIC_DEFENDER);
    }

    // INTRO SCREEN 2 //
    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_2)
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
        //                                         BG_B                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B = TILE_USER_INDEX;

        VDP_loadTileSet(image_INTRO_SCREEN_2_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_2_BG_B.tileset->numTile;
        VDP_loadTileSet(image_INTRO_SCREEN_2_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_2_BG_A.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                 LOADING NUMBERS TILES                                //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_INTRO_SCREEN_2_BG_A1.tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_2_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_2_BG_A1.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_2_BG_A.tileset->numTile), 12, 5, 0, 0, 17, 18, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                     RADAR SPRITE                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_RADAR = SPR_addSprite(&tiles_SPR_RADAR,  160, 0, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));




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
    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_3)
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

        VDP_setPlaneSize(64,32,FALSE);

        SPR_initEx(150);

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_INTRO_SCREEN_3_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_3_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  LOADING BG_A TILES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_3_BG_B.tileset->numTile;
        VDP_loadTileSet(image_INTRO_SCREEN_3_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_3_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 40, 11, 0, 0, 13, 8, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = -4;

        VDP_setVerticalScroll(BG_A ,G_POS_Y_CAMERA);




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

        XGM_startPlay(MUSIC_INTRO);
    }

    // INTRO SCREEN 4 //
    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_4)
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

        VDP_setPlaneSize(64,32,FALSE);

        SPR_initEx(1);

        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        G_ADR_VRAM_BG_B = 0;

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_B                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_INTRO_SCREEN_4_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_4_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_4_BG_B.tileset->numTile;
        VDP_loadTileSet(image_INTRO_SCREEN_4_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_4_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B , 0);
        VDP_setVerticalScroll(BG_A , 0);




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

        //sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK, -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        sprite_STOOGES = SPR_addSpriteEx(&tiles_SPR_STOOGES_WALK, -96, -64, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 10), SPR_FLAG_AUTO_TILE_UPLOAD);

        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_INTRO_SCREEN_4_BG_B.palette->data   , 16 * 2 );
		memcpy( &palette_64[16] , image_INTRO_SCREEN_4_BG_A.palette->data   , 16 * 2 );
		memcpy( &palette_64[32] , palette_BLACK.data                        , 16 * 2 );
		memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




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
        G_SCENE_TYPE            = SCENE_INTRO_SCREEN_4;
        G_SCENE_NEXT            = SCENE_INTRO_SCREEN_4;

        G_SCENE_LOADED          = TRUE;


        waitMs(2500);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        XGM_startPlay(MUSIC_BILLBOARDS);
    }

    // INTRO SCREEN 5 //
    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_5)
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

        VDP_setPlaneSize(64,32,FALSE);

        SPR_initEx(10);

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_INTRO_SCREEN_5_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_5_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_5_BG_B.tileset->numTile;
        VDP_loadTileSet(image_INTRO_SCREEN_5_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_5_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B , 0);
        VDP_setVerticalScroll(BG_A , 0);




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

        //sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK, -96, -64, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_STOOGES = SPR_addSpriteEx(&tiles_SPR_STOOGES_WALK, -96, -64, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 1), SPR_FLAG_AUTO_TILE_UPLOAD);

        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_INTRO_SCREEN_5_BG_B.palette->data   , 16 * 2 );
		memcpy( &palette_64[16] , image_INTRO_SCREEN_5_BG_A.palette->data   , 16 * 2 );
		memcpy( &palette_64[32] , palette_BLACK.data                        , 16 * 2 );
		memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




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
        G_SCENE_TYPE            = SCENE_INTRO_SCREEN_5;
        G_SCENE_NEXT            = SCENE_INTRO_SCREEN_5;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
    }

    // INTRO SCREEN 6 //
    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_6)
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

        VDP_setPlaneSize(64,32,FALSE);

        SPR_initEx(1);

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_INTRO_SCREEN_6_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_6_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_6_BG_B.tileset->numTile;
        VDP_loadTileSet(image_INTRO_SCREEN_6_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_6_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B , 0);
        VDP_setVerticalScroll(BG_A , 0);




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

        //sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK, -96, -64, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        sprite_STOOGES = SPR_addSpriteEx(&tiles_SPR_STOOGES_WALK, -96, -64, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 1), SPR_FLAG_AUTO_TILE_UPLOAD);

        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_INTRO_SCREEN_6_BG_B.palette->data   , 16 * 2 );
		memcpy( &palette_64[16] , image_INTRO_SCREEN_6_BG_A.palette->data   , 16 * 2 );
		memcpy( &palette_64[32] , palette_BLACK.data                        , 16 * 2 );
		memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




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
        G_SCENE_TYPE            = SCENE_INTRO_SCREEN_6;
        G_SCENE_NEXT            = SCENE_INTRO_SCREEN_6;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
    }

    // INTRO SCREEN 5 //
    else if(G_SCENE_TYPE == SCENE_INTRO_SCREEN_7)
    {
        //**************************************************************************************//
        //                                                                                      //
        //                                    SETUP DISPLAY                                     //
        //                                                                                      //
        //**************************************************************************************//

        VDP_setPlaneSize(64,32,FALSE);

        SPR_initEx(15);

        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                     FONT TILESET                                     //
        //                                                                                      //
        //**************************************************************************************//

        //VDP_loadTileSet(image_FONT_INTRO.tileset, TILE_FONT_INDEX, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        G_ADR_VRAM_BG_B = 0;

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_B                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_INTRO_SCREEN_7_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_7_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   GRANDMA TILES BG_B                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_GRANDMA_INTRO_BG_B_STEP0.tileset, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_B, image_GRANDMA_INTRO_BG_B_STEP0.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile), 6, 14, 0, 0, 5, 6, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile + image_GRANDMA_INTRO_BG_B_STEP0.tileset->numTile;
        VDP_loadTileSet(image_INTRO_SCREEN_7_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);

        VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 2, 0, 2,  4,  4, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   GRANDMA TILES BG_A                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_GRANDMA_INTRO_BG_A_STEP0.tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_A, image_GRANDMA_INTRO_BG_A_STEP0.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile), 6, 14, 0, 0, 5, 6, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                     DIALOG TILES                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile + image_GRANDMA_INTRO_BG_A_STEP0.tileset->numTile;
        VDP_loadTileSet(image_INTRO_SCREEN_7_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      TEXT TILES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_INTRO_SCREEN_7_TEXT.tileset, G_ADR_VRAM_DIALOG + image_INTRO_SCREEN_7_DIALOG.tileset->numTile, CPU);




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

        //sprite_BANKER[0] = SPR_addSprite(&tiles_SPR_BANKER_PART2,   105, 132, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
        //sprite_BANKER[1] = SPR_addSprite(&tiles_SPR_BANKER_PART1,   105, 132, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));

        sprite_BANKER[0] = SPR_addSpriteEx(&tiles_SPR_BANKER_PART2, 105, 132, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 1), SPR_FLAG_AUTO_TILE_UPLOAD);
        sprite_BANKER[1] = SPR_addSpriteEx(&tiles_SPR_BANKER_PART1, 105, 132, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 46), SPR_FLAG_AUTO_TILE_UPLOAD);

        SPR_setZ(sprite_BANKER[0] , 0);
        SPR_setZ(sprite_BANKER[1] , 1);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            DIALOG ARROW SPRITE OFF SCREEN                            //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_INTRO_ARROW,   -16, -32, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));


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

        waitMs(2000);

        XGM_startPlay(MUSIC_BANKER);

        waitMs(2500);
    }
}


void init_SCENE()
{
    // BANK //
    if(G_SCENE_TYPE == SCENE_BANK)
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
        //                                   NUMBERS TILESET                                    //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_BANK_NUMBERS.tileset, TILE_FONT_INDEX + 16, CPU);




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

        VDP_loadTileSet(image_BANK_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_BANK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
        VDP_setTileMapEx(BG_B, image_BANK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_BANK_BG_B.tileset->numTile;
        VDP_loadTileSet(image_BANK_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        DIALOG                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_BANK_BG_A.tileset->numTile;
        VDP_loadTileSet(image_BANK_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_HUB = G_ADR_VRAM_DIALOG + image_BANK_DIALOG.tileset->numTile;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         LUCK                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        bool random_luck = random_NUMBER(0,19);

        G_LUCK = TABLE_LUCK[random_luck];


        if(G_LUCK == FALSE)
        {
            G_MONEY -= (G_MONEY/10);
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 224;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                        GENERATE NEXT POSITION IN HIGHSTREET                          //
        //                                                                                      //
        //**************************************************************************************//

        //G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




        //**************************************************************************************//
        //                                                                                      //
        //                                  INCREASE HAND SPEED                                 //
        //                                                                                      //
        //**************************************************************************************//

        increase_HAND_SPEED();




        //**************************************************************************************//
        //                                                                                      //
        //                                       INIT HUB                                       //
        //                                                                                      //
        //**************************************************************************************//

        init_HUB();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                             HUB ARROW SPRITE OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        SPR_setPosition(sprite_ARROW_HUB , -48 , -48);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              BANKER SPRITES OFF SCREEN                               //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_BANKER[0] = SPR_addSprite(&tiles_SPR_BANKER_PART3,   -48, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        sprite_BANKER[1] = SPR_addSprite(&tiles_SPR_BANKER_PART2,   -48, -64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
        SPR_setFrame(sprite_BANKER[1],3);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            DIALOG ARROW SPRITE OFF SCREEN                            //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

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


        G_COUNTER_ROULETTE      = 0;
        G_CURRENT_TURN          = 9;


        G_PHASE_SEQUENCE        = BANKER_PHASE_WALKIN;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_BANK;
        G_SCENE_NEXT            = SCENE_BANK;

        G_SCENE_LOADED          = TRUE;
    }

    // BOXING //
    else if(G_SCENE_TYPE == SCENE_BOXING)
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

        VDP_setPlaneSize(64,32,TRUE);

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

        VDP_loadTileSet(image_STREET_BOXING_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_STREET_BOXING_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_BOXING_BG_B.tileset->numTile;
        VDP_loadTileSet(image_STREET_BOXING_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_STREET_BOXING_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        DIALOG                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_STREET_BOXING_BG_A.tileset->numTile;
        VDP_loadTileSet(image_BOXING_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                        GENERATE NEXT POSITION IN HIGHSTREET                          //
        //                                                                                      //
        //**************************************************************************************//

        //G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




        //**************************************************************************************//
        //                                                                                      //
        //                                  INCREASE HAND SPEED                                 //
        //                                                                                      //
        //**************************************************************************************//

        increase_HAND_SPEED();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            DIALOG ARROW SPRITE OFF SCREEN                            //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_BANK_ARROW,   -24, -32, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_STREET_BOXING_BG_B.palette->data    , 16 * 2 );
        memcpy( &palette_64[16] , image_STREET_BOXING_BG_A.palette->data    , 16 * 2 );
        memcpy( &palette_64[32] , image_BOXING_DIALOG.palette->data         , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




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


        G_STREET_TYPE           = STREET_TYPE_BOXING;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_BOXING;
        G_SCENE_NEXT            = SCENE_BOXING;

        G_SCENE_LOADED          = TRUE;
    }

    // DOCTORS //
    else if(G_SCENE_TYPE == SCENE_DOCTORS)
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

        VDP_setPlaneSize(64,32,TRUE);

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


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_DOCTORS_BG_B.tileset->numTile;
        VDP_loadTileSet(image_STREET_DOCTORS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_STREET_DOCTORS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                        GENERATE NEXT POSITION IN HIGHSTREET                          //
        //                                                                                      //
        //**************************************************************************************//

        //G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




        //**************************************************************************************//
        //                                                                                      //
        //                                  INCREASE HAND SPEED                                 //
        //                                                                                      //
        //**************************************************************************************//

        increase_HAND_SPEED();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_STREET_DOCTORS_BG_B.palette->data   , 16 * 2 );
        memcpy( &palette_64[16] , image_STREET_DOCTORS_BG_A.palette->data   , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




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
        G_SCENE_TYPE            = SCENE_DOCTORS;
        G_SCENE_NEXT            = SCENE_DOCTORS;

        G_SCENE_LOADED          = TRUE;
    }

    // DOLLAR //
    else if(G_SCENE_TYPE == SCENE_DOLLAR)
    {
        // RANDOMLY SELECT BETWEEN : //
        // DOLLAR TYPE 1  (0) //
        // DOLLAR TYPE 2  (1) //
        // DOLLAR TYPE 3  (2) //
        G_DOLLAR_TYPE  = random_NUMBER(0 , 2); // DOLLAR_TYPE_2;//




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      INIT STREET                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // POINTER DECLARATION //
        void (*ptr_INIT_DOLLAR)(void);

        // SETTING POINTER ON TRIVIA INIT FUNCTION //
        ptr_INIT_DOLLAR = TABLE_INIT_STREET_DOLLAR[G_DOLLAR_TYPE];

        // RUNNING STREET INIT FUNCTION //
        (*ptr_INIT_DOLLAR)();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 224;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                       INIT HUB                                       //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                           ADD REWARD TO TOTAL EARNED MONEY                           //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_MONEY += G_REWARD;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                     1 DAY SPENT                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_DAY += 1;


        init_HUB();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE)); // -95 , 142


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                               ARROW SPRITE OFF SCREEN                                //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        SPR_setPosition(sprite_ARROW_HUB , -48 , -48);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                             DOLLAR BAG SPRITE OFF SCREEN                             //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
        sprite_DOLLAR_BAG = SPR_addSprite(&tiles_SPR_DOLLAR_BAG,  144, 168, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            DIALOG ARROW SPRITE OFF SCREEN                            //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
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


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_DOLLAR;
        G_SCENE_NEXT            = SCENE_DOLLAR;

        G_SCENE_LOADED          = TRUE;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //XGM_setPCM(SOUND_HEAD_SHOCK, PCM_HEAD_SHOCK, sizeof(PCM_HEAD_SHOCK));
        //XGM_setPCM(SOUND_JOY_CRY, PCM_JOY_CRY, sizeof(PCM_JOY_CRY));
    }

    // QUESTION MARK //
    else if(G_SCENE_TYPE == SCENE_QUESTION_MARK)
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

        VDP_setPlaneSize(64,32,TRUE);

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
        VDP_setTileMapEx(BG_B, image_QUESTION_MARK_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_HUB = G_ADR_VRAM_BG_B + image_QUESTION_MARK_BG_B.tileset->numTile;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                        GENERATE NEXT POSITION IN HIGHSTREET                          //
        //                                                                                      //
        //**************************************************************************************//

        //G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




        //**************************************************************************************//
        //                                                                                      //
        //                                  INCREASE HAND SPEED                                 //
        //                                                                                      //
        //**************************************************************************************//

        increase_HAND_SPEED();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK, -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   ICE CUBE SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_ICE_CUBE         = SPR_addSprite(&tiles_SPR_ICE_CUBE,        149,  23, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));
        sprite_SCISSOR          = SPR_addSprite(&tiles_SPR_SCISSOR,         128,   0, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));
        sprite_ICE_CUBE_SHADOW  = SPR_addSprite(&tiles_SPR_ICE_CUBE_SHADOW, 143,  31, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));


        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_QUESTION_MARK_BG_B.palette->data    , 16 * 2 );
        memcpy( &palette_64[16] , palette_BLACK.data                        , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        REWARD                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        u8 random_reward        = random_NUMBER(0,6);

        G_REWARD                = TABLE_REWARD[random_reward];




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


        G_STREET_TYPE           = STREET_TYPE_QUESTION_MARK;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_QUESTION_MARK;
        G_SCENE_NEXT            = SCENE_QUESTION_MARK;

        G_SCENE_LOADED          = TRUE;
    }

    // SLAP //
    else if(G_SCENE_TYPE == SCENE_SLAP)
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

        VDP_loadTileSet(image_SLAP_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_SLAP_BG_B.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);
        VDP_setTileMapEx(BG_B, image_SLAP_BG_B.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  28, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_SLAP_BG_B.tileset->numTile;
        VDP_loadTileSet(image_SLAP_HUB.tileset, G_ADR_VRAM_BG_A, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        DIALOG                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_SLAP_HUB.tileset->numTile;
        VDP_loadTileSet(image_SLAP_DIALOG_2.tileset, G_ADR_VRAM_DIALOG, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                       SETUP HUB VRAM ADRESS FOR LATER HUB INIT                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_HUB = G_ADR_VRAM_DIALOG + image_SLAP_DIALOG_2.tileset->numTile;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 224;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       INIT HUB                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // GENERATE NEXT POSITION IN HIGHSTREET //
        //G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);

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
        //                                        COUNTER                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_SLAP = 96;
        sprite_COUNTER_SLAP = SPR_addSprite(&tiles_SPR_SLAP_COUNTER,  -24, -8, TILE_ATTR(PAL0, TRUE, FALSE, FALSE)); // 88 90
        SPR_setAnim(sprite_COUNTER_SLAP,G_COUNTER_SLAP);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  SLAP HAND SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_HAND_SLAP = SPR_addSprite(&tiles_SPR_HAND_SLAP,  -32, -32, TILE_ATTR(PAL3, TRUE, FALSE, FALSE)); // 152 71


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                     METER SPRITE                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_METER_SLAP = SPR_addSprite(&tiles_SPR_METER_SLAP,  0, -16, TILE_ATTR(PAL1, FALSE, FALSE, FALSE)); // -6 55


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                             HUB ARROW SPRITE OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        SPR_setPosition(sprite_ARROW_HUB , -48 , -48);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            DIALOG ARROW SPRITE OFF SCREEN                            //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_BANK_ARROW,   -24, -32, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -96, -64, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));


        SPR_update();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

		memcpy( &palette_64[0]  , image_DOLLAR_1_BG_B.palette->data     , 16 * 2 );
		memcpy( &palette_64[16] , image_SLAP_DIALOG_2.palette->data     , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 96;
        G_INDEX_3               = 0;


        G_COUNTER_ROULETTE      = 0;
        G_CURRENT_TURN          = 9;
        G_COUNTER_SLAP          = 0;
        G_COUNTER_WAIT          = 0;


        G_AXIS                  = LEFT;
        G_CURRENT_STATE         = SLAP_STATE_IDLE;
        G_PREVIOUS_STATE        = SLAP_STATE_IDLE;


        G_STREET_TYPE           = STREET_DOLLAR_TYPE_1;


        G_PHASE_SEQUENCE        = SLAP_PHASE_WALKIN;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_SLAP;
        G_SCENE_NEXT            = SCENE_SLAP;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //XGM_setPCM(SOUND_WALKOUT, PCM_LETS_RIDE, sizeof(PCM_LETS_RIDE));
        //XGM_setPCM(SOUND_SWATTER, PCM_SWATTER, sizeof(PCM_SWATTER));
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
            G_TRIVIA_TYPE    = trivia_TYPE; // trivia_TYPE
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

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            DIALOG ARROW SPRITE OFF SCREEN                            //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        SPR_setPosition(sprite_ARROW_HUB , -48 , -48);

        SPR_update();
        SYS_doVBlankProcess();


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_REWARD                = 500;

        G_SCENE_LOADED          = TRUE;
    }

    // WAITERS //
    else if(G_SCENE_TYPE == SCENE_WAITERS)
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

        VDP_setPlaneSize(64,32,TRUE);

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
        VDP_loadTileSet(image_STREET_WAITERS_BG_B2.tileset, G_ADR_VRAM_BG_B + image_STREET_WAITERS_BG_B1.tileset->numTile, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_WAITERS_BG_B1.tileset->numTile + image_STREET_WAITERS_BG_B2.tileset->numTile;
        VDP_loadTileSet(image_STREET_WAITERS_BG_A1.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_STREET_WAITERS_BG_A1.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);
        VDP_loadTileSet(image_STREET_WAITERS_BG_A2.tileset, G_ADR_VRAM_BG_A + image_STREET_WAITERS_BG_A1.tileset->numTile, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        DIALOG                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_STREET_WAITERS_BG_A1.tileset->numTile + image_STREET_WAITERS_BG_A2.tileset->numTile;
        VDP_loadTileSet(image_WAITERS_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                        GENERATE NEXT POSITION IN HIGHSTREET                          //
        //                                                                                      //
        //**************************************************************************************//

        //G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




        //**************************************************************************************//
        //                                                                                      //
        //                                  INCREASE HAND SPEED                                 //
        //                                                                                      //
        //**************************************************************************************//

        increase_HAND_SPEED();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            DIALOG ARROW SPRITE OFF SCREEN                            //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_BANK_ARROW,   -24, -32, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_STREET_WAITERS_BG_B1.palette->data  , 16 * 2 );
        memcpy( &palette_64[16] , image_STREET_WAITERS_BG_A1.palette->data  , 16 * 2 );
        memcpy( &palette_64[32] , image_WAITERS_DIALOG.palette->data        , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_STREET_TYPE           = STREET_TYPE_WAITERS;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_WAITERS;
        G_SCENE_NEXT            = SCENE_WAITERS;

        G_SCENE_LOADED          = TRUE;
    }

    // CRACKERS //
    else if(G_SCENE_TYPE == SCENE_CRACKERS)
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

        VDP_setPlaneSize(64,32,TRUE);

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

        VDP_loadTileSet(image_STREET_CRACKERS_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_STREET_CRACKERS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_STREET_CRACKERS_BG_B.tileset->numTile;
        VDP_loadTileSet(image_STREET_CRACKERS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_STREET_CRACKERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                        GENERATE NEXT POSITION IN HIGHSTREET                          //
        //                                                                                      //
        //**************************************************************************************//

        //G_HIGHSTREET_POSITION += random_NUMBER(1 , 6);




        //**************************************************************************************//
        //                                                                                      //
        //                                  INCREASE HAND SPEED                                 //
        //                                                                                      //
        //**************************************************************************************//

        increase_HAND_SPEED();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_STREET_CRACKERS_BG_B.palette->data  , 16 * 2 );
        memcpy( &palette_64[16] , image_STREET_CRACKERS_BG_A.palette->data  , 16 * 2 );
        memcpy( &palette_64[32] , palette_BLACK.data                        , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_STREET_TYPE           = STREET_TYPE_CRACKERS;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_CRACKERS;
        G_SCENE_NEXT            = SCENE_CRACKERS;

        G_SCENE_LOADED          = TRUE;
    }

    // QUESTION MARK //
    else if(G_SCENE_TYPE == SCENE_SAFE)
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

        VDP_setPlaneSize(64,32,TRUE);

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

        VDP_loadTileSet(image_SAFE_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_SAFE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_SAFE_BG_B.tileset->numTile;
        VDP_loadTileSet(image_SAFE_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_SAFE_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                  INCREASE HAND SPEED                                 //
        //                                                                                      //
        //**************************************************************************************//

        increase_HAND_SPEED();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    CHEST SPRITES                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_CHEST        = SPR_addSprite(&tiles_SPR_CHEST,   128,   0, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
        sprite_ROPE         = SPR_addSprite(&tiles_SPR_ROPE ,   -24, -32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              STOOGES SPRITES OFF SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK, -96, -64, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));


        SPR_update();
        SYS_doVBlankProcess();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_SAFE_BG_B.palette->data             , 16 * 2 );
        memcpy( &palette_64[16] , image_SAFE_BG_A.palette->data             , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         LUCK                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        bool random_luck = random_NUMBER(0,19);

        G_LUCK = TABLE_LUCK[random_luck];
        //G_LUCK = TRUE;

        // STOOGES GET A REWARD //
        if(G_LUCK == TRUE)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                        REWARD                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            u8 random_reward        = random_NUMBER(7,19);

            G_REWARD                = TABLE_REWARD[random_reward];

        }

        // STOOGES HAVE TO PAY THE HOSPITAL BILL //
        else
        {
            G_DAY += 1;

            // USELESS CHECK BUT... //
            if(G_MONEY > 299)
            {
                G_MONEY -= 300;
            }

            else
            {
                G_MONEY = 0;
            }

        }





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


        G_STREET_TYPE           = STREET_TYPE_SAFE;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_SAFE;
        G_SCENE_NEXT            = SCENE_SAFE;

        G_SCENE_LOADED          = TRUE;
    }

    // ROULETTE //
    else if(G_SCENE_TYPE == SCENE_ROULETTE)
    {
        //**************************************************************************************//
        //                                                                                      //
        //                                      INIT STREET                                     //
        //                                                                                      //
        //**************************************************************************************//

        // POINTER DECLARATION //
        void (*ptr_INIT_STREET)(void);

        // SETTING POINTER ON STREET INIT FUNCTION //
        ptr_INIT_STREET = TABLE_INIT_STREET_ROULETTE[G_STREET_TYPE];

        // RUNNING STREET INIT FUNCTION //
        (*ptr_INIT_STREET)();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                       INIT HUB                                       //
        //                                                                                      //
        //**************************************************************************************//

        init_HUB();




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   STOOGES SPRITES                                    //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  117, 133, TILE_ATTR(PAL3, FALSE, FALSE, FALSE)); // -95 , 142
        SPR_setFrame(sprite_STOOGES,17);


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

        //XGM_setPCM(SOUND_WALKOUT, PCM_LETS_RIDE, sizeof(PCM_LETS_RIDE));
        //XGM_setPCM(SOUND_SWATTER, PCM_SWATTER, sizeof(PCM_SWATTER));
    }


    //-------------------------------------------------//
    //                    MINIGAMES                    //
    //-------------------------------------------------//

    // TRIVIA CONTRACT
    else if(G_SCENE_TYPE == SCENE_TRIVIA_QUESTION)
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

        VDP_setPlaneSize(64,32,TRUE);

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

        VDP_loadTileSet(image_TRIVIA_QUESTION_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_TRIVIA_QUESTION_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_TRIVIA_QUESTION_BG_B.tileset->numTile;
        VDP_loadTileSet(image_TRIVIA_QUESTION_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_TRIVIA_QUESTION_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       QUESTION                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_QUESTION = G_ADR_VRAM_BG_A + image_TRIVIA_QUESTION_BG_A.tileset->numTile;

        // LOAD QUESTION TILESET //
        VDP_loadTileSet(TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tileset, G_ADR_VRAM_QUESTION, CPU);

        // DISPLAY QUESTION //
        VDP_setTileMapEx(BG_B, TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_QUESTION), 6, 13, 0, 0, 29, 3, CPU);

        // DISPLAY ANSWERS //
        VDP_setTileMapEx(BG_B, TABLE_QUESTIONS[G_SELECTED_QUESTION].ptr_IMAGE_QUESTION->tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_QUESTION), 6, 18, 0, 4, 29, 3, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

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
    }

    // BOXING SCREEN 1 //
    else if(G_SCENE_TYPE == SCENE_BOXING_SCREEN_TYPE1)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_initEx(20);

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_BOXING_SCREEN_1_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_BOXING_SCREEN_1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_BOXING_SCREEN_1_BG_B.tileset->numTile;
        VDP_loadTileSet(image_BOXING_SCREEN_1_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_BOXING_SCREEN_1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();



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

        memcpy( &palette_64[0]  , image_BOXING_SCREEN_1_BG_B.palette->data  , 16 * 2 );
        memcpy( &palette_64[16] , image_BOXING_SCREEN_1_BG_A.palette->data  , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        SPR_update();

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_PHASE_SEQUENCE        = 0;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_BOXING_SCREEN_TYPE1;
        G_SCENE_NEXT            = SCENE_BOXING_SCREEN_TYPE1;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        XGM_startPlayPCM(SOUND_BOXING_1_2 , 15 , SOUND_PCM_CH4);
    }

    // BOXING SCREEN 2 //
    else if(G_SCENE_TYPE == SCENE_BOXING_SCREEN_TYPE2)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_initEx(20);

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_BOXING_SCREEN_2_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_BOXING_SCREEN_2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_BOXING_SCREEN_2_BG_B.tileset->numTile;
        VDP_loadTileSet(image_BOXING_SCREEN_2_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_BOXING_SCREEN_2_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();



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

        memcpy( &palette_64[0]  , image_BOXING_SCREEN_2_BG_B.palette->data  , 16 * 2 );
        memcpy( &palette_64[16] , palette_BOXING_SCREEN_2_0.data            , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        SPR_update();

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_PHASE_SEQUENCE        = 0;


        G_SCENE                 = SCENE_FADE_IN_BOXING;
        G_SCENE_TYPE            = SCENE_BOXING_SCREEN_TYPE2;
        G_SCENE_NEXT            = SCENE_BOXING_SCREEN_TYPE2;

        G_SCENE_LOADED          = TRUE;
    }

    // BOXING SCREEN 3 //
    else if(G_SCENE_TYPE == SCENE_BOXING_SCREEN_TYPE3)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_initEx(20);

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_BOXING_SCREEN_3_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_BOXING_SCREEN_3_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_BOXING_SCREEN_3_BG_B.tileset->numTile;
        VDP_loadTileSet(image_BOXING_SCREEN_3_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_BOXING_SCREEN_3_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);
        SYS_doVBlankProcess();



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

        memcpy( &palette_64[0]  , image_BOXING_SCREEN_3_BG_B.palette->data  , 16 * 2 );
        memcpy( &palette_64[16] , image_BOXING_SCREEN_3_BG_A.palette->data  , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        SPR_update();

        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;


        G_PHASE_SEQUENCE        = 0;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_BOXING_SCREEN_TYPE3;
        G_SCENE_NEXT            = SCENE_BOXING_SCREEN_TYPE3;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        XGM_startPlayPCM(SOUND_BOXING_3 , 15 , SOUND_PCM_CH4);
    }

    // DOCTORS MINIGAME //
    else if(G_SCENE_TYPE == SCENE_DOCTORS_MINIGAME)
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

        SPR_initEx(520);

        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                   NUMBERS TILESET                                    //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_DOCTORS_NUMBERS.tileset, TILE_FONT_INDEX + 16, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        G_ADR_VRAM_BG_B = TILE_USER_INDEX;

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_B1                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_DOCTORS_BG_B1.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_DOCTORS_BG_B1.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0,  0,  0, 40, 64, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_B1                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_DOCTORS_BG_B2.tileset, G_ADR_VRAM_BG_B + image_DOCTORS_BG_B1.tileset->numTile, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_DOCTORS_BG_B1.tileset->numTile + image_DOCTORS_BG_B2.tileset->numTile;
        VDP_loadTileSet(image_DOCTORS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_DOCTORS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 25,  0,  0, 40, 3, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         DOTS                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_DOCTORS_BLUE_DOT.tileset, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile    , CPU);
        VDP_loadTileSet(image_DOCTORS_BLUE_DOT.tileset, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + 1, CPU);
        VDP_loadTileSet(image_DOCTORS_BLUE_DOT.tileset, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + 2, CPU);
        VDP_loadTileSet(image_DOCTORS_BLUE_DOT.tileset, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + 3, CPU);
        VDP_loadTileSet(image_DOCTORS_BLUE_DOT.tileset, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + 4, CPU);

        VDP_setTileMapEx(BG_A, image_DOCTORS_BLUE_DOT.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile    ), 29, 26,  0,  0,  1,  1, CPU);
        VDP_setTileMapEx(BG_A, image_DOCTORS_BLUE_DOT.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + 1), 31, 26,  0,  0,  1,  1, CPU);
        VDP_setTileMapEx(BG_A, image_DOCTORS_BLUE_DOT.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + 2), 33, 26,  0,  0,  1,  1, CPU);
        VDP_setTileMapEx(BG_A, image_DOCTORS_BLUE_DOT.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + 3), 35, 26,  0,  0,  1,  1, CPU);
        VDP_setTileMapEx(BG_A, image_DOCTORS_BLUE_DOT.tilemap, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_DOCTORS_BG_A.tileset->numTile + 4), 37, 26,  0,  0,  1,  1, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    PRINT COUNTER                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_drawIntEx_BG_A_CPU_PRIO(99 , 2 , 8 , 26 , PAL1);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    PRINT REWARD                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_drawIntEx_BG_A_CPU_PRIO(0 , 1 , 3 , 26 , PAL1);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         NURSE                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        nurse.pos_X                 = random_NUMBER(44,227);
        nurse.pos_Y                 = 10;

        nurse.spr_NURSE             = SPR_addSprite(&tiles_SPR_NURSE, nurse.pos_X, nurse.pos_Y, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        nurse.axis_NURSE            = AXIS_RIGHT;

        nurse.counter_SPRITE_FRAME  = 0;
        nurse.index_SPRITE_FRAME    = 0;

        nurse.counter_ITEM          = 0;
        nurse.index_ITEM            = 0;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        PATIENT                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        patient.spr_PATIENT             = NULL;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      LARRY'S CAR                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        list_CARS[2].hit                    = FALSE;

        list_CARS[2].pos_X                  = 140;
        list_CARS[2].pos_Y                  = 183;

        list_CARS[2].spr_CAR                = SPR_addSprite(&tiles_SPR_CAR_LARRY,  list_CARS[2].pos_X, list_CARS[2].pos_Y, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
        list_CARS[2].axis_CAR               = AXIS_CENTER;

        list_CARS[2].index_READ_AXIS        = 0;
        list_CARS[2].index_WRITE_AXIS       = 16;

        for(i=0 ; i<17 ; i++)
        {
            list_CARS[2].TABLE_SPEED[i]     = 2;
            list_CARS[2].TABLE_AXIS[i]      = AXIS_CENTER;
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      CURLY'S CAR                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        list_CARS[1].hit                    = FALSE;

        list_CARS[1].pos_X                  = 140;
        list_CARS[1].pos_Y                  = 141;

        list_CARS[1].spr_CAR                = SPR_addSprite(&tiles_SPR_CAR_CURLY,  list_CARS[1].pos_X, list_CARS[1].pos_Y, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
        list_CARS[1].axis_CAR               = AXIS_CENTER;

        list_CARS[1].index_READ_AXIS        = 0;
        list_CARS[1].index_WRITE_AXIS       = 8;

        for(i=0 ; i<17 ; i++)
        {
            list_CARS[1].TABLE_SPEED[i]     = 2;
            list_CARS[1].TABLE_AXIS[i]      = AXIS_CENTER;
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       MOE'S CAR                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        list_CARS[0].hit                    = FALSE;

        list_CARS[0].pos_X                  = 140;
        list_CARS[0].pos_Y                  = 99;

        list_CARS[0].spr_CAR                = SPR_addSprite(&tiles_SPR_CAR_MOE,  list_CARS[0].pos_X, list_CARS[0].pos_Y, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
        list_CARS[0].axis_CAR               = AXIS_CENTER;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      NURSE ITEMS                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        list_ITEM[0].spr_ITEM  = NULL;
        list_ITEM[1].spr_ITEM  = NULL;








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

        memcpy( &palette_64[0]  , image_DOCTORS_BG_B1.palette->data     , 16 * 2 );
        memcpy( &palette_64[16] , image_DOCTORS_BG_A.palette->data      , 16 * 2 );
        memcpy( &palette_64[32] , palette_SPR_CAR.data                  , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_NURSE.data                , 16 * 2 );

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


        G_REWARD                = 0;


        G_CAR_SPEED             = 1;

        G_CAR_COUNTER_SPEED     = 0;

        G_HIT_NUMBER            = 0;

        G_COUNTER_DOCTORS       = 99;

        G_PREVIOUS_PATIENT_TYPE = 100;

        G_RANDOM_OK             = FALSE;


        G_PHASE_SEQUENCE        = DOCTORS_PHASE_RACING;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_DOCTORS_MINIGAME;
        G_SCENE_NEXT            = SCENE_DOCTORS_MINIGAME;

        G_SCENE_LOADED          = TRUE;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        XGM_startPlayPCM(SOUND_VOICE_DOCTORS , 13 , SOUND_PCM_CH3 );


        waitMs(3000);


        XGM_startPlayPCM(SOUND_ENGINE_1 , 13 , SOUND_PCM_CH2 );
    }

    // DOCTORS MINIGAME //
    else if(G_SCENE_TYPE == SCENE_WAITERS_MINIGAME)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_initEx(300);

        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                   NUMBERS TILESET                                    //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_WAITERS_NUMBERS.tileset, TILE_FONT_INDEX + 16, CPU);

        //**************************************************************************************//
        //                                                                                      //
        //                                     FONT TILESET                                     //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_WAITERS_TEXT.tileset, TILE_FONT_INDEX + 27, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        G_ADR_VRAM_BG_B = 1; //TILE_USER_INDEX

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_B                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_WAITERS_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_WAITERS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0,  0,  0, 40, 28, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_WAITERS_BG_B.tileset->numTile;
        VDP_loadTileSet(image_WAITERS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_WAITERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0,  0,  0, 40, 28, CPU);


        VDP_setTileMapEx(BG_A, image_WAITERS_NUMBERS.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16), 4, 4, 10, 0, 1, 1, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    MAN 1 TILESET                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                  HERE WE USE A TRICK TO AVOID SPRITE LIMIT ON MAN 1                  //
        //                  PART OF MAN 1 SPRITE IS DISPLAYED ON BG_A                           //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_TILES_MAN_1 = G_ADR_VRAM_BG_A + image_WAITERS_BG_A.tileset->numTile;
        VDP_loadTileSet(image_MAN1_1_WAITERS.tileset, G_ADR_VRAM_TILES_MAN_1, CPU);
        VDP_setTileMapEx(BG_A, image_MAN1_1_WAITERS.tilemap, TILE_ATTR_FULL(PAL2, TRUE, FALSE, FALSE, G_ADR_VRAM_TILES_MAN_1), 5, 19, 0, 0, 3, 2, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    CURLY TILESET                                     //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                  HERE WE USE A TRICK TO AVOID SPRITE LIMIT ON MAN 1                  //
        //                  PART OF CURLY SPRITE IS DISPLAYED ON BG_A                           //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_TILES_CURLY = G_ADR_VRAM_TILES_MAN_1 + image_MAN1_1_WAITERS.tileset->numTile;
        VDP_loadTileSet(image_CURLY1_1_WAITERS.tileset, G_ADR_VRAM_TILES_CURLY, CPU);
        VDP_setTileMapEx(BG_A, image_CURLY1_1_WAITERS.tilemap, TILE_ATTR_FULL(PAL2, TRUE, FALSE, FALSE, G_ADR_VRAM_TILES_CURLY), 33, 19, 0, 0, 2, 2, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    BG_B WALL PIES                                    //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         LEFT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B_PIE_LEFT_0 = G_ADR_VRAM_TILES_CURLY + image_CURLY1_1_WAITERS.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL0_0_LEFT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_LEFT_0, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL0_0_LEFT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_LEFT_0), 0, 17, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_B_PIE_LEFT_1 = G_ADR_VRAM_BG_B_PIE_LEFT_0 + image_PIE_WALL0_0_LEFT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL1_0_LEFT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_LEFT_1, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL1_0_LEFT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_LEFT_1), 3, 16, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_B_PIE_LEFT_2 = G_ADR_VRAM_BG_B_PIE_LEFT_1 + image_PIE_WALL1_0_LEFT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL2_0_LEFT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_LEFT_2, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL2_0_LEFT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_LEFT_2), 5, 14, 0, 0, 2, 5, CPU);

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        RIGHT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B_PIE_RIGHT_0 = G_ADR_VRAM_BG_B_PIE_LEFT_2 + image_PIE_WALL2_0_LEFT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL0_0_RIGHT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_RIGHT_0, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL0_0_RIGHT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_RIGHT_0), 38, 17, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_B_PIE_RIGHT_1 = G_ADR_VRAM_BG_B_PIE_RIGHT_0 + image_PIE_WALL0_0_RIGHT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL1_0_RIGHT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_RIGHT_1, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL1_0_RIGHT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_RIGHT_1), 35, 16, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_B_PIE_RIGHT_2 = G_ADR_VRAM_BG_B_PIE_RIGHT_1 + image_PIE_WALL1_0_RIGHT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL2_0_RIGHT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_RIGHT_2, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL2_0_RIGHT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_RIGHT_2), 33, 14, 0, 0, 2, 5, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                    BG_A WALL PIES                                    //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         LEFT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A_PIE_LEFT_0 = G_ADR_VRAM_BG_B_PIE_RIGHT_2 + image_PIE_WALL2_0_RIGHT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL0_0_LEFT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_LEFT_0, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL0_0_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_LEFT_0), 0, 17, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_A_PIE_LEFT_1 = G_ADR_VRAM_BG_A_PIE_LEFT_0 + image_PIE_WALL0_0_LEFT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL1_0_LEFT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_LEFT_1, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL1_0_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_LEFT_1), 3, 16, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_A_PIE_LEFT_2 = G_ADR_VRAM_BG_A_PIE_LEFT_1 + image_PIE_WALL1_0_LEFT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL2_0_LEFT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_LEFT_2, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL2_0_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_LEFT_2), 5, 14, 0, 0, 2, 5, CPU);

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        RIGHT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A_PIE_RIGHT_0 = G_ADR_VRAM_BG_A_PIE_LEFT_2 + image_PIE_WALL2_0_LEFT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL0_0_RIGHT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_RIGHT_0, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL0_0_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_RIGHT_0), 38, 17, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_A_PIE_RIGHT_1 = G_ADR_VRAM_BG_A_PIE_RIGHT_0 + image_PIE_WALL0_0_RIGHT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL1_0_RIGHT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_RIGHT_1, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL1_0_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_RIGHT_1), 35, 16, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_A_PIE_RIGHT_2 = G_ADR_VRAM_BG_A_PIE_RIGHT_1 + image_PIE_WALL1_0_RIGHT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL2_0_RIGHT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_RIGHT_2, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL2_0_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_RIGHT_2), 33, 14, 0, 0, 2, 5, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  BG_B TOP WALL PIES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       TOP LEFT                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B_PIE_UP_LEFT_0 = G_ADR_VRAM_BG_A_PIE_RIGHT_2 + image_PIE_WALL2_0_RIGHT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL0_0_UP_LEFT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_UP_LEFT_0, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL0_0_UP_LEFT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_UP_LEFT_0), 0,  7, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_B_PIE_UP_LEFT_1 = G_ADR_VRAM_BG_B_PIE_UP_LEFT_0 + image_PIE_WALL0_0_UP_LEFT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL1_0_UP_LEFT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_UP_LEFT_1, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL1_0_UP_LEFT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_UP_LEFT_1), 3, 10, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_B_PIE_UP_LEFT_2 = G_ADR_VRAM_BG_B_PIE_UP_LEFT_1 + image_PIE_WALL1_0_UP_LEFT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL2_0_UP_LEFT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_UP_LEFT_2, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL2_0_UP_LEFT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_UP_LEFT_2), 5,  9, 0, 0, 2, 5, CPU);

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      TOP RIGHT                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B_PIE_UP_RIGHT_0 = G_ADR_VRAM_BG_B_PIE_UP_LEFT_2 + image_PIE_WALL2_0_UP_LEFT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL0_0_UP_RIGHT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_UP_RIGHT_0, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL0_0_UP_RIGHT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_UP_RIGHT_0), 38,  8, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_B_PIE_UP_RIGHT_1 = G_ADR_VRAM_BG_B_PIE_UP_RIGHT_0 + image_PIE_WALL0_0_UP_RIGHT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL1_0_UP_RIGHT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_UP_RIGHT_1, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL1_0_UP_RIGHT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_UP_RIGHT_1), 36, 10, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_B_PIE_UP_RIGHT_2 = G_ADR_VRAM_BG_B_PIE_UP_RIGHT_1 + image_PIE_WALL1_0_UP_RIGHT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL2_0_UP_RIGHT_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_UP_RIGHT_2, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_WALL2_0_UP_RIGHT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_UP_RIGHT_2), 33,  9, 0, 0, 2, 5, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  BG_A TOP WALL PIES                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       TOP LEFT                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A_PIE_UP_LEFT_0 = G_ADR_VRAM_BG_B_PIE_UP_RIGHT_2 + image_PIE_WALL2_0_UP_RIGHT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL0_0_UP_LEFT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_UP_LEFT_0, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL0_0_UP_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_LEFT_0), 0,  7, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_A_PIE_UP_LEFT_1 = G_ADR_VRAM_BG_A_PIE_UP_LEFT_0 + image_PIE_WALL0_0_UP_LEFT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL1_0_UP_LEFT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_UP_LEFT_1, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL1_0_UP_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_LEFT_1), 3, 10, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_A_PIE_UP_LEFT_2 = G_ADR_VRAM_BG_A_PIE_UP_LEFT_1 + image_PIE_WALL1_0_UP_LEFT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL2_0_UP_LEFT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_UP_LEFT_2, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL2_0_UP_LEFT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_LEFT_2), 5,  9, 0, 0, 2, 5, CPU);

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      TOP RIGHT                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A_PIE_UP_RIGHT_0 = G_ADR_VRAM_BG_A_PIE_UP_LEFT_2 + image_PIE_WALL2_0_UP_LEFT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL0_0_UP_RIGHT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_0, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL0_0_UP_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_0), 38,  8, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_A_PIE_UP_RIGHT_1 = G_ADR_VRAM_BG_A_PIE_UP_RIGHT_0 + image_PIE_WALL0_0_UP_RIGHT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL1_0_UP_RIGHT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_1, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL1_0_UP_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_1), 36, 10, 0, 0, 2, 5, CPU);

        G_ADR_VRAM_BG_A_PIE_UP_RIGHT_2 = G_ADR_VRAM_BG_A_PIE_UP_RIGHT_1 + image_PIE_WALL1_0_UP_RIGHT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_WALL2_0_UP_RIGHT_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_2, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_WALL2_0_UP_RIGHT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_UP_RIGHT_2), 33,  9, 0, 0, 2, 5, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   BG_B GROUND PIES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_B_PIE_DOWN_0 = G_ADR_VRAM_BG_A_PIE_UP_RIGHT_2 + image_PIE_WALL2_0_UP_RIGHT_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_DOWN0_0_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_DOWN_0, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_DOWN0_0_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_DOWN_0), 17, 24, 0, 0, 5, 2, CPU);

        G_ADR_VRAM_BG_B_PIE_DOWN_1 = G_ADR_VRAM_BG_B_PIE_DOWN_0 + image_PIE_DOWN0_0_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_DOWN1_0_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_DOWN_1, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_DOWN1_0_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_DOWN_1), 17, 22, 0, 0, 5, 2, CPU);

        G_ADR_VRAM_BG_B_PIE_DOWN_2 = G_ADR_VRAM_BG_B_PIE_DOWN_1 + image_PIE_DOWN1_0_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_DOWN2_0_BG_B.tileset, G_ADR_VRAM_BG_B_PIE_DOWN_2, CPU);
        VDP_setTileMapEx(BG_B, image_PIE_DOWN2_0_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B_PIE_DOWN_2), 17, 20, 0, 0, 5, 2, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   BG_A GROUND PIES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A_PIE_DOWN_0 = G_ADR_VRAM_BG_B_PIE_DOWN_2 + image_PIE_DOWN2_0_BG_B.tileset->numTile;
        VDP_loadTileSet(image_PIE_DOWN0_0_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_DOWN_0, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_DOWN0_0_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_DOWN_0), 17, 24, 0, 0, 5, 2, CPU);

        G_ADR_VRAM_BG_A_PIE_DOWN_1 = G_ADR_VRAM_BG_A_PIE_DOWN_0 + image_PIE_DOWN0_0_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_DOWN1_0_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_DOWN_1, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_DOWN1_0_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_DOWN_1), 17, 22, 0, 0, 5, 2, CPU);

        G_ADR_VRAM_BG_A_PIE_DOWN_2 = G_ADR_VRAM_BG_A_PIE_DOWN_1 + image_PIE_DOWN1_0_BG_A.tileset->numTile;
        VDP_loadTileSet(image_PIE_DOWN2_0_BG_A.tileset, G_ADR_VRAM_BG_A_PIE_DOWN_2, CPU);
        VDP_setTileMapEx(BG_A, image_PIE_DOWN2_0_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A_PIE_DOWN_2), 17, 20, 0, 0, 5, 2, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   WALL PIES ARRAYS                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        list_WALL_PIES_LEFT_BG_B[0].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_LEFT_0;
        list_WALL_PIES_LEFT_BG_B[1].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_LEFT_1;
        list_WALL_PIES_LEFT_BG_B[2].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_LEFT_2;

        list_WALL_PIES_LEFT_BG_A[0].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_LEFT_0;
        list_WALL_PIES_LEFT_BG_A[1].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_LEFT_1;
        list_WALL_PIES_LEFT_BG_A[2].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_LEFT_2;


        list_WALL_PIES_RIGHT_BG_B[0].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_RIGHT_0;
        list_WALL_PIES_RIGHT_BG_B[1].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_RIGHT_1;
        list_WALL_PIES_RIGHT_BG_B[2].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_RIGHT_2;

        list_WALL_PIES_RIGHT_BG_A[0].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_RIGHT_0;
        list_WALL_PIES_RIGHT_BG_A[1].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_RIGHT_1;
        list_WALL_PIES_RIGHT_BG_A[2].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_RIGHT_2;




        list_WALL_PIES_LEFT_BG_B[0].ptr_IMAGE    = &image_PIE_WALL0_1_LEFT_BG_B;
        list_WALL_PIES_LEFT_BG_B[1].ptr_IMAGE    = &image_PIE_WALL1_1_LEFT_BG_B;
        list_WALL_PIES_LEFT_BG_B[2].ptr_IMAGE    = &image_PIE_WALL2_1_LEFT_BG_B;

        list_WALL_PIES_LEFT_BG_A[0].ptr_IMAGE    = &image_PIE_WALL0_1_LEFT_BG_A;
        list_WALL_PIES_LEFT_BG_A[1].ptr_IMAGE    = &image_PIE_WALL1_1_LEFT_BG_A;
        list_WALL_PIES_LEFT_BG_A[2].ptr_IMAGE    = &image_PIE_WALL2_1_LEFT_BG_A;

        list_WALL_PIES_RIGHT_BG_B[0].ptr_IMAGE   = &image_PIE_WALL0_1_RIGHT_BG_B;
        list_WALL_PIES_RIGHT_BG_B[1].ptr_IMAGE   = &image_PIE_WALL1_1_RIGHT_BG_B;
        list_WALL_PIES_RIGHT_BG_B[2].ptr_IMAGE   = &image_PIE_WALL2_1_RIGHT_BG_B;

        list_WALL_PIES_RIGHT_BG_A[0].ptr_IMAGE   = &image_PIE_WALL0_1_RIGHT_BG_A;
        list_WALL_PIES_RIGHT_BG_A[1].ptr_IMAGE   = &image_PIE_WALL1_1_RIGHT_BG_A;
        list_WALL_PIES_RIGHT_BG_A[2].ptr_IMAGE   = &image_PIE_WALL2_1_RIGHT_BG_A;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                 UP WALL PIES ARRAYS                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        list_WALL_PIES_UP_LEFT_BG_B[0].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_UP_LEFT_0;
        list_WALL_PIES_UP_LEFT_BG_B[1].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_UP_LEFT_1;
        list_WALL_PIES_UP_LEFT_BG_B[2].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_UP_LEFT_2;

        list_WALL_PIES_UP_LEFT_BG_A[0].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_UP_LEFT_0;
        list_WALL_PIES_UP_LEFT_BG_A[1].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_UP_LEFT_1;
        list_WALL_PIES_UP_LEFT_BG_A[2].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_UP_LEFT_2;


        list_WALL_PIES_UP_RIGHT_BG_B[0].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_UP_RIGHT_0;
        list_WALL_PIES_UP_RIGHT_BG_B[1].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_UP_RIGHT_1;
        list_WALL_PIES_UP_RIGHT_BG_B[2].vram_ADRESS = G_ADR_VRAM_BG_B_PIE_UP_RIGHT_2;

        list_WALL_PIES_UP_RIGHT_BG_A[0].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_UP_RIGHT_0;
        list_WALL_PIES_UP_RIGHT_BG_A[1].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_UP_RIGHT_1;
        list_WALL_PIES_UP_RIGHT_BG_A[2].vram_ADRESS = G_ADR_VRAM_BG_A_PIE_UP_RIGHT_2;




        list_WALL_PIES_UP_LEFT_BG_B[0].ptr_IMAGE    = &image_PIE_WALL0_1_UP_LEFT_BG_B;
        list_WALL_PIES_UP_LEFT_BG_B[1].ptr_IMAGE    = &image_PIE_WALL1_1_UP_LEFT_BG_B;
        list_WALL_PIES_UP_LEFT_BG_B[2].ptr_IMAGE    = &image_PIE_WALL2_1_UP_LEFT_BG_B;

        list_WALL_PIES_UP_LEFT_BG_A[0].ptr_IMAGE    = &image_PIE_WALL0_1_UP_LEFT_BG_A;
        list_WALL_PIES_UP_LEFT_BG_A[1].ptr_IMAGE    = &image_PIE_WALL1_1_UP_LEFT_BG_A;
        list_WALL_PIES_UP_LEFT_BG_A[2].ptr_IMAGE    = &image_PIE_WALL2_1_UP_LEFT_BG_A;

        list_WALL_PIES_UP_RIGHT_BG_B[0].ptr_IMAGE   = &image_PIE_WALL0_1_UP_RIGHT_BG_B;
        list_WALL_PIES_UP_RIGHT_BG_B[1].ptr_IMAGE   = &image_PIE_WALL1_1_UP_RIGHT_BG_B;
        list_WALL_PIES_UP_RIGHT_BG_B[2].ptr_IMAGE   = &image_PIE_WALL2_1_UP_RIGHT_BG_B;

        list_WALL_PIES_UP_RIGHT_BG_A[0].ptr_IMAGE   = &image_PIE_WALL0_1_UP_RIGHT_BG_A;
        list_WALL_PIES_UP_RIGHT_BG_A[1].ptr_IMAGE   = &image_PIE_WALL1_1_UP_RIGHT_BG_A;
        list_WALL_PIES_UP_RIGHT_BG_A[2].ptr_IMAGE   = &image_PIE_WALL2_1_UP_RIGHT_BG_A;



        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                DOWN WALL PIES ARRAYS                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        list_WALL_PIES_DOWN_BG_B[0].vram_ADRESS     = G_ADR_VRAM_BG_B_PIE_DOWN_0;
        list_WALL_PIES_DOWN_BG_B[1].vram_ADRESS     = G_ADR_VRAM_BG_B_PIE_DOWN_1;
        list_WALL_PIES_DOWN_BG_B[2].vram_ADRESS     = G_ADR_VRAM_BG_B_PIE_DOWN_2;

        list_WALL_PIES_DOWN_BG_A[0].vram_ADRESS     = G_ADR_VRAM_BG_A_PIE_DOWN_0;
        list_WALL_PIES_DOWN_BG_A[1].vram_ADRESS     = G_ADR_VRAM_BG_A_PIE_DOWN_1;
        list_WALL_PIES_DOWN_BG_A[2].vram_ADRESS     = G_ADR_VRAM_BG_A_PIE_DOWN_2;

        list_WALL_PIES_DOWN_BG_B[0].ptr_IMAGE       = &image_PIE_DOWN0_1_BG_B;
        list_WALL_PIES_DOWN_BG_B[1].ptr_IMAGE       = &image_PIE_DOWN1_1_BG_B;
        list_WALL_PIES_DOWN_BG_B[2].ptr_IMAGE       = &image_PIE_DOWN2_1_BG_B;

        list_WALL_PIES_DOWN_BG_A[0].ptr_IMAGE       = &image_PIE_DOWN0_1_BG_A;
        list_WALL_PIES_DOWN_BG_A[1].ptr_IMAGE       = &image_PIE_DOWN1_1_BG_A;
        list_WALL_PIES_DOWN_BG_A[2].ptr_IMAGE       = &image_PIE_DOWN2_1_BG_A;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       DIALOG                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_WAITERS_MINIGAME_DIALOG.tileset, TILE_FONT_INDEX + 55, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        SCORE                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_drawIntEx_BG_A_CPU_PRIO(0,1,6,4,PAL1);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BULBS                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_BULB[0]                 =   SPR_addSprite(&tiles_SPR_BULB, 224,  36, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
        sprite_BULB[1]                 =   SPR_addSprite(&tiles_SPR_BULB, 240,  36, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
        sprite_BULB[2]                 =   SPR_addSprite(&tiles_SPR_BULB, 256,  36, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
        sprite_BULB[3]                 =   SPR_addSprite(&tiles_SPR_BULB, 272,  36, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
        sprite_BULB[4]                 =   SPR_addSprite(&tiles_SPR_BULB, 288,  36, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                          HAND                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_HAND_WAITERS             =   SPR_addSprite(&tiles_SPR_HAND_WAITERS, -24, -24, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));




        //--------------------------------------------------------------------------------------//
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        1RST ROW                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                                      LARRY'S PIE                                     //
        //--------------------------------------------------------------------------------------//

        list_WAITERS[0].spr_PIE          =   SPR_addSprite(&tiles_SPR_PIE_LARRY,      250, 173, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        list_WAITERS[0].state_PIE        =   PIE_PHASE_SERVED;
        list_WAITERS[0].index_ANIM_PIE   =   0;
        list_WAITERS[0].pie_DEVIATION    =   NO_DEVIATION;

        //--------------------------------------------------------------------------------------//
        //                                      WOMAN'S PIE                                     //
        //--------------------------------------------------------------------------------------//

        list_GUESTS[0].spr_PIE           =   SPR_addSprite(&tiles_SPR_PIE_WOMAN,       44, 173, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        list_GUESTS[0].state_PIE         =   PIE_PHASE_SERVED;
        list_GUESTS[0].index_ANIM_PIE    =   0;
        list_GUESTS[0].pie_DEVIATION     =   NO_DEVIATION;




        //--------------------------------------------------------------------------------------//
        //                                         LARRY                                        //
        //--------------------------------------------------------------------------------------//
        list_WAITERS[0].spr_CHAR_1       =   SPR_addSprite(&tiles_SPR_LARRY1_WAITERS, 256, 139, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));
        list_WAITERS[0].spr_CHAR_2       =   SPR_addSprite(&tiles_SPR_LARRY2_WAITERS, 256, 139, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        list_WAITERS[0].counter_ANIM     =   0;
        list_WAITERS[0].state_CHARACTER  =   CHAR_PHASE_IDLE;

        //--------------------------------------------------------------------------------------//
        //                                         WOMAN                                        //
        //--------------------------------------------------------------------------------------//
        list_GUESTS[0].spr_CHAR_1        =   SPR_addSprite(&tiles_SPR_WOMAN1_WAITERS, 0, 139, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));
        list_GUESTS[0].spr_CHAR_2        =   SPR_addSprite(&tiles_SPR_WOMAN2_WAITERS, 0, 139, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        list_GUESTS[0].counter_ANIM      =   0;
        list_GUESTS[0].counter_ACTION    =   0;
        list_GUESTS[0].state_CHARACTER   =   CHAR_PHASE_IDLE;








        //--------------------------------------------------------------------------------------//
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        2ND ROW                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                                      CURLY'S PIE                                     //
        //--------------------------------------------------------------------------------------//

        list_WAITERS[1].spr_PIE          =   SPR_addSprite(&tiles_SPR_PIE_CURLY,      240, 163, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        list_WAITERS[1].state_PIE        =   PIE_PHASE_SERVED;
        list_WAITERS[1].index_ANIM_PIE   =   0;
        list_WAITERS[1].pie_DEVIATION    =   NO_DEVIATION;

        //--------------------------------------------------------------------------------------//
        //                                      MAN 1'S PIE                                     //
        //--------------------------------------------------------------------------------------//

        list_GUESTS[1].spr_PIE           =   SPR_addSprite(&tiles_SPR_PIE_MAN_1,       58, 163, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        list_GUESTS[1].state_PIE         =   PIE_PHASE_SERVED;
        list_GUESTS[1].index_ANIM_PIE    =   0;
        list_GUESTS[1].pie_DEVIATION     =   NO_DEVIATION;




        //--------------------------------------------------------------------------------------//
        //                                         CURLY                                        //
        //--------------------------------------------------------------------------------------//

        list_WAITERS[1].spr_CHAR_1       =   SPR_addSprite(&tiles_SPR_CURLY1_WAITERS, 240, 138, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));
        list_WAITERS[1].spr_CHAR_2       =   SPR_addSprite(&tiles_SPR_CURLY2_WAITERS, 240, 138, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
        list_WAITERS[1].counter_ANIM     =   0;
        list_WAITERS[1].state_CHARACTER  =   CHAR_PHASE_IDLE;

        //--------------------------------------------------------------------------------------//
        //                                         MAN 1                                        //
        //--------------------------------------------------------------------------------------//

        list_GUESTS[1].spr_CHAR_1        =   SPR_addSprite(&tiles_SPR_MAN1_1_WAITERS, 31, 138, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
        list_GUESTS[1].spr_CHAR_2        =   SPR_addSprite(&tiles_SPR_MAN1_2_WAITERS, 31, 138, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        list_GUESTS[1].counter_ANIM      =   0;
        list_GUESTS[1].counter_ACTION    =   0;
        list_GUESTS[1].state_CHARACTER   =   CHAR_PHASE_IDLE;




        //--------------------------------------------------------------------------------------//
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        3RD ROW                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                                       MOE'S PIE                                      //
        //--------------------------------------------------------------------------------------//

        list_WAITERS[2].spr_PIE          =   SPR_addSprite(&tiles_SPR_PIE_MOE,        231, 156, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        list_WAITERS[2].state_PIE        =   PIE_PHASE_SERVED;
        list_WAITERS[2].index_ANIM_PIE   =   0;
        list_WAITERS[2].pie_DEVIATION    =   NO_DEVIATION;

        //--------------------------------------------------------------------------------------//
        //                                      MAN 2'S PIE                                     //
        //--------------------------------------------------------------------------------------//

        list_GUESTS[2].spr_PIE           =   SPR_addSprite(&tiles_SPR_PIE_MAN_2,       70, 156, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        list_GUESTS[2].state_PIE         =   PIE_PHASE_SERVED;
        list_GUESTS[2].index_ANIM_PIE    =   0;
        list_GUESTS[2].pie_DEVIATION     =   NO_DEVIATION;




        //--------------------------------------------------------------------------------------//
        //                                          MOE                                         //
        //--------------------------------------------------------------------------------------//

        list_WAITERS[2].spr_CHAR_1       =   SPR_addSprite(&tiles_SPR_MOE1_WAITERS, 232, 126, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
        list_WAITERS[2].spr_CHAR_2       =   SPR_addSprite(&tiles_SPR_MOE2_WAITERS, 232, 126, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        list_WAITERS[2].counter_ANIM     =   0;
        list_WAITERS[2].state_CHARACTER  =   CHAR_PHASE_IDLE;

        //--------------------------------------------------------------------------------------//
        //                                         MAN 2                                        //
        //--------------------------------------------------------------------------------------//

        list_GUESTS[2].spr_CHAR_1        =   SPR_addSprite(&tiles_SPR_MAN2_1_WAITERS, 48, 128, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
        list_GUESTS[2].spr_CHAR_2        =   SPR_addSprite(&tiles_SPR_MAN2_2_WAITERS, 48, 128, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        list_GUESTS[2].counter_ANIM      =   0;
        list_GUESTS[2].counter_ACTION    =   0;
        list_GUESTS[2].state_CHARACTER   =   CHAR_PHASE_IDLE;




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

        memcpy( &palette_64[0]  , image_WAITERS_BG_B.palette->data        , 16 * 2 );
        memcpy( &palette_64[16] , image_WAITERS_BG_A.palette->data        , 16 * 2 );
        memcpy( &palette_64[32] , palette_SPR_STOOGES_WAITERS_1.data     , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_STOOGES_WAITERS_2.data     , 16 * 2 );

        SPR_update();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_1                 = 0;
        G_INDEX_1                   = 0;
        G_INDEX_2                   = 0;
        G_INDEX_3                   = 0;

        G_COUNTER_ACTION_WAITERS    = 0;
        //G_COUNTER_ACTION_GUESTS     = 0;


        G_REWARD                    = 0;

        G_HIT_NUMBER                = 0;

        G_SERVED_PIES               = 3; // 3 STOOGES PIES
        G_USED_PIES                 = 0; // 0 USED PIES

        G_RANDOM_OK                 = FALSE;

        G_ACTION_WAITER_AUTHORIZED  = TRUE;

        G_GUEST_SHOT_AUTHORIZED     = NULL;

        G_DELAY_ACTION_WAITERS      = 40;


        G_SELECTED_WAITER           = 99; // 99 = NONE

        G_PHASE_SEQUENCE            = WAITER_PHASE_DIALOG;


        G_SCENE                     = SCENE_FADE_IN;
        G_SCENE_TYPE                = SCENE_WAITERS_MINIGAME;
        G_SCENE_NEXT                = SCENE_WAITERS_MINIGAME;

        G_SCENE_LOADED              = TRUE;

    }

    // CRACKERS SCREEN //
    else if(G_SCENE_TYPE == SCENE_CRACKERS_SCREEN)
    {
        //**************************************************************************************//
        //                                                                                      //
        //                                    SETUP DISPLAY                                     //
        //                                                                                      //
        //**************************************************************************************//

        VDP_setPlaneSize(64,32,TRUE);

        SPR_initEx(95);

        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        G_ADR_VRAM_BG_B = 1;

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            CRACKERS 4 ROUNDS SPREAD SCREEN                           //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        if(G_CRACKERS_SCREEN_TYPE == CRACKERS_SCREEN_SPREAD)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B1.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);

            VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile + image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset->numTile + 1;
            VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A1.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);

            VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, CPU);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       PALETTES                                       //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            memcpy( &palette_64[0]  , image_CRACKERS_SCREEN_SPREAD_BG_B1.palette->data     , 16 * 2 );
            memcpy( &palette_64[16] , image_CRACKERS_SCREEN_SPREAD_BG_A1.palette->data     , 16 * 2 );




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       VARIABLES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_COUNTER_1                 = 0;
            G_INDEX_1                   = 0;

            G_COUNTER_CRACKERS          = 0;
            G_COUNTER_OYSTER            = 0;



            G_NUMBER_CRACKERS_MAX       = G_NUMBER_GRABBED_CRACKERS;
            G_NUMBER_CRACKERS           = G_NUMBER_GRABBED_CRACKERS;
            G_NUMBER_GRABBED_CRACKERS   = 0;


            G_SELECTED_CRACKER          = 99;


            if(G_NUMBER_CRACKERS == 14)
            {
                G_SCENE = SCENE_FADE_IN;
            }

            else
            {
                G_SCENE = SCENE_FADE_IN_CRACKERS;
            }




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         AUDIO                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            //XGM_setPCM(SOUND_HAND, PCM_HAND, sizeof(PCM_HAND));
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              CRACKERS SURPRISE 1 SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        else if(G_CRACKERS_SCREEN_TYPE == CRACKERS_SCREEN_SURPRISE_1)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       BG_B BASE                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       BG_A BASE                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tileset->numTile;
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_1_BG_B.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SURPRISE_1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile), 15, 6, 0, 0, 10, 9, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_1_BG_A.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile + image_CRACKERS_SCREEN_SURPRISE_1_BG_B.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SURPRISE_1_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE,  G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile + image_CRACKERS_SCREEN_SURPRISE_1_BG_B.tileset->numTile), 16, 5, 0, 0, 9, 10, CPU);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       PALETTES                                       //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            memcpy( &palette_64[0]  , image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.palette->data     , 16 * 2 );
            memcpy( &palette_64[16] , image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.palette->data     , 16 * 2 );




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       VARIABLES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_SCENE = SCENE_FADE_IN_CRACKERS;




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         AUDIO                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            u8 random_PCM = random_NUMBER(0,2);

            //XGM_setPCM( TABLE_ID_PCM_CRACKERS_MINIGAME[random_PCM] , TABLE_SAMPLE_PCM_CRACKERS_MINIGAME[random_PCM] , TABLE_LENGH_PCM_CRACKERS_MINIGAME[random_PCM] );
            XGM_startPlayPCM( TABLE_ID_PCM_CRACKERS_MINIGAME[random_PCM] , 13 , SOUND_PCM_CH3 );
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              CRACKERS SURPRISE 2 SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        else if(G_CRACKERS_SCREEN_TYPE == CRACKERS_SCREEN_SURPRISE_2)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       BG_B BASE                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       BG_A BASE                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tileset->numTile;
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_2_BG_B.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SURPRISE_2_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile), 15, 6, 0, 0, 10, 9, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_2_BG_A.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile + image_CRACKERS_SCREEN_SURPRISE_2_BG_B.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SURPRISE_2_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE,  G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile + image_CRACKERS_SCREEN_SURPRISE_2_BG_B.tileset->numTile), 16, 5, 0, 0, 9, 10, CPU);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       PALETTES                                       //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            memcpy( &palette_64[0]  , image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.palette->data     , 16 * 2 );
            memcpy( &palette_64[16] , image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.palette->data     , 16 * 2 );




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       VARIABLES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_SCENE = SCENE_FADE_IN_CRACKERS;




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         AUDIO                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            u8 random_PCM = random_NUMBER(0,2);

            //XGM_setPCM( TABLE_ID_PCM_CRACKERS_MINIGAME[random_PCM] , TABLE_SAMPLE_PCM_CRACKERS_MINIGAME[random_PCM] , TABLE_LENGH_PCM_CRACKERS_MINIGAME[random_PCM] );
            XGM_startPlayPCM( TABLE_ID_PCM_CRACKERS_MINIGAME[random_PCM] , 13 , SOUND_PCM_CH3 );
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              CRACKERS SURPRISE 3 SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        else if(G_CRACKERS_SCREEN_TYPE == CRACKERS_SCREEN_SURPRISE_3)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       BG_B BASE                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       BG_A BASE                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tileset->numTile;
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_3_BG_B.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SURPRISE_3_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile), 15, 6, 0, 0, 10, 9, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_3_BG_A.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile + image_CRACKERS_SCREEN_SURPRISE_3_BG_B.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SURPRISE_3_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE,  G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile + image_CRACKERS_SCREEN_SURPRISE_3_BG_B.tileset->numTile), 16, 5, 0, 0, 9, 10, CPU);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       PALETTES                                       //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            memcpy( &palette_64[0]  , image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.palette->data     , 16 * 2 );
            memcpy( &palette_64[16] , image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.palette->data     , 16 * 2 );




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       VARIABLES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_SCENE = SCENE_FADE_IN_CRACKERS;




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         AUDIO                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            //XGM_setPCM(SOUND_CRACKERS_CRY_4, PCM_CRACKERS_CRY_4, sizeof(PCM_CRACKERS_CRY_4));
            XGM_startPlayPCM(SOUND_CRACKERS_CRY_4,13,SOUND_PCM_CH3);
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                              CRACKERS SURPRISE 4 SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        else if(G_CRACKERS_SCREEN_TYPE == CRACKERS_SCREEN_SURPRISE_4)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       BG_B BASE                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       BG_A BASE                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.tileset->numTile;
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_4_BG_B.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SURPRISE_4_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile), 15, 6, 0, 0, 10, 9, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            VDP_loadTileSet(image_CRACKERS_SCREEN_SURPRISE_4_BG_A.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile + image_CRACKERS_SCREEN_SURPRISE_4_BG_B.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SURPRISE_4_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE,  G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.tileset->numTile + image_CRACKERS_SCREEN_SURPRISE_4_BG_B.tileset->numTile), 16, 5, 0, 0, 9, 10, CPU);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       SPRITES                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            sprite_SPLASH = SPR_addSprite(&tiles_SPR_SPLASH, 112,  59, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
            SPR_update();
            SYS_doVBlankProcess();
            SYS_doVBlankProcess();




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       PALETTES                                       //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            memcpy( &palette_64[0]  , image_CRACKERS_SCREEN_SURPRISE_BASE_BG_B.palette->data     , 16 * 2 );
            memcpy( &palette_64[16] , image_CRACKERS_SCREEN_SURPRISE_BASE_BG_A.palette->data     , 16 * 2 );




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       VARIABLES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_SCENE = SCENE_FADE_IN_CRACKERS;




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         AUDIO                                        //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            XGM_startPlayPCM(SOUND_CRACKERS_CRY_5,13,SOUND_PCM_CH3);
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                               CRACKERS GAME OVER SCREEN                              //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        else if(G_CRACKERS_SCREEN_TYPE == CRACKERS_SCREEN_OVER)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_CRACKERS_SCREEN_OVER_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_OVER_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_OVER_BG_B.tileset->numTile;
            VDP_loadTileSet(image_CRACKERS_SCREEN_OVER_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_OVER_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       PALETTES                                       //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            memcpy( &palette_64[0]  , image_CRACKERS_SCREEN_OVER_BG_B.palette->data     , 16 * 2 );
            memcpy( &palette_64[16] , image_CRACKERS_SCREEN_OVER_BG_A.palette->data     , 16 * 2 );




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                       VARIABLES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_SCENE = SCENE_FADE_IN;
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_SCENE_TYPE            = SCENE_CRACKERS_SCREEN;
        G_SCENE_NEXT            = SCENE_CRACKERS_SCREEN;

        G_SCENE_LOADED          = TRUE;
    }

    // CRACKERS MINIGAME //
    else if(G_SCENE_TYPE == SCENE_CRACKERS_MINIGAME)
    {
        u16 i = 0;




        //**************************************************************************************//
        //                                                                                      //
        //                                    SETUP DISPLAY                                     //
        //                                                                                      //
        //**************************************************************************************//

        VDP_setPlaneSize(64,32,TRUE);

        SPR_initEx(640);

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_CRACKERS_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_CRACKERS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CRACKERS_BG_B.tileset->numTile;
        VDP_loadTileSet(image_CRACKERS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_CRACKERS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;


        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                   CRACKERS SPRITES                                   //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//


        //--------------------------------------------------------------------------------------//
        //                                   IF WE INIT ROUND                                   //
        //--------------------------------------------------------------------------------------//
        if(G_CRACKERS_INIT == FALSE)
        {
            //--------------------------------------------------------------------------------------//
            //                                     HAND SPRITES                                     //
            //--------------------------------------------------------------------------------------//

            G_POS_X_PLAYER = 174;
            G_POS_Y_PLAYER = 150;

            sprite_HAND[0] = SPR_addSprite(&tiles_SPR_HAND_PART_1,  G_POS_X_PLAYER + 10 , G_POS_Y_PLAYER + 44  , TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
            sprite_HAND[1] = SPR_addSprite(&tiles_SPR_HAND_PART_2,  G_POS_X_PLAYER - 7  , G_POS_Y_PLAYER + 100 , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
            sprite_HAND[2] = SPR_addSprite(&tiles_SPR_HAND_PART_3,  G_POS_X_PLAYER      , G_POS_Y_PLAYER       , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));




            //--------------------------------------------------------------------------------------//
            //                                   CRACKERS SPRITES                                   //
            //--------------------------------------------------------------------------------------//

            //--------------------------------------------------------------------------------------//
            //                            IF MORE THAN 1 REMAINING CRACKER                          //
            //--------------------------------------------------------------------------------------//
            if(G_NUMBER_CRACKERS_MAX != 1)
            {
                const s16 (*(*ptr_position_crackers)[14])[14][2] = &TABLE_POSITION_CRACKERS;

                for(i=0 ; i<G_NUMBER_CRACKERS_MAX ; i++)
                {
                    list_CRACKER[i].spr_CRACKER     = SPR_addSprite(&tiles_SPR_CRACKER,  0, 0, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
                    list_CRACKER[i].state_CRACKER   = CRACKER_PHASE_FREE;
                    list_CRACKER[i].animated        = FALSE;
                    list_CRACKER[i].counter_CRACKER = 0;

                    list_CRACKER[i].pos_X = (*(*ptr_position_crackers)[G_NUMBER_CRACKERS-1])[i][0];
                    list_CRACKER[i].pos_Y = (*(*ptr_position_crackers)[G_NUMBER_CRACKERS-1])[i][1];

                    SPR_setPosition(list_CRACKER[i].spr_CRACKER  ,  list_CRACKER[i].pos_X , list_CRACKER[i].pos_Y);
                }
            }

            //--------------------------------------------------------------------------------------//
            //                              IF ONLY 1 REMAINING CRACKER                             //
            //--------------------------------------------------------------------------------------//
            else
            {
                u8 pos_cracker = random_NUMBER(0,13);

                list_CRACKER[0].spr_CRACKER     = SPR_addSprite(&tiles_SPR_CRACKER,  0, 0, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
                list_CRACKER[0].state_CRACKER   = CRACKER_PHASE_FREE;
                list_CRACKER[0].animated        = FALSE;
                list_CRACKER[0].counter_CRACKER = 0;

                list_CRACKER[0].pos_X = TABLE_POSITION_CRACKERS_14[pos_cracker][0];
                list_CRACKER[0].pos_Y = TABLE_POSITION_CRACKERS_14[pos_cracker][1];

                SPR_setPosition(list_CRACKER[0].spr_CRACKER  ,  list_CRACKER[0].pos_X , list_CRACKER[0].pos_Y);
            }


            G_SPOON_FRAME       = 0;

            G_COUNTER_1         = 0;

            G_INDEX_1           = 0;

            G_RANDOM_OK         = FALSE;

            G_CRACKERS_INIT     = TRUE;

            G_PHASE_SEQUENCE    = CRACKER_SPOON_MOVE;
        }


        //--------------------------------------------------------------------------------------//
        //           ELSE WE JUST RECREATE CRACKERS SPRITES BUT KEEP THEIR PROPERTIES           //
        //--------------------------------------------------------------------------------------//

        else
        {
            //--------------------------------------------------------------------------------------//
            //                                     HAND SPRITES                                     //
            //--------------------------------------------------------------------------------------//

            if(G_SPOON_FRAME == 0)
            {
                sprite_HAND[0] = SPR_addSprite(&tiles_SPR_HAND_PART_1,  G_POS_X_PLAYER + 10 , G_POS_Y_PLAYER + 44  , TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
                sprite_HAND[1] = SPR_addSprite(&tiles_SPR_HAND_PART_2,  G_POS_X_PLAYER - 7  , G_POS_Y_PLAYER + 100 , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
                sprite_HAND[2] = SPR_addSprite(&tiles_SPR_HAND_PART_3,  G_POS_X_PLAYER      , G_POS_Y_PLAYER       , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
            }

            else
            {
                sprite_HAND[0] = SPR_addSprite(&tiles_SPR_HAND_PART_1,  G_POS_X_PLAYER +  9 , G_POS_Y_PLAYER + 16  , TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
                sprite_HAND[1] = SPR_addSprite(&tiles_SPR_HAND_PART_2,  G_POS_X_PLAYER - 7  , G_POS_Y_PLAYER + 68 , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
                sprite_HAND[2] = SPR_addSprite(&tiles_SPR_HAND_PART_3,  G_POS_X_PLAYER      , G_POS_Y_PLAYER       , TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
            }

            SPR_setFrame(sprite_HAND[0],G_SPOON_FRAME);
            SPR_setFrame(sprite_HAND[1],G_SPOON_FRAME);
            SPR_setFrame(sprite_HAND[2],G_SPOON_FRAME);


            //--------------------------------------------------------------------------------------//
            //                                   CRACKERS SPRITES                                   //
            //--------------------------------------------------------------------------------------//

            for(i=0 ; i<G_NUMBER_CRACKERS_MAX ; i++)
            {
                if(list_CRACKER[i].state_CRACKER != CRACKER_PHASE_EATEN)
                {
                    list_CRACKER[i].spr_CRACKER = SPR_addSprite(&tiles_SPR_CRACKER,  list_CRACKER[i].pos_X , list_CRACKER[i].pos_Y, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
                    SPR_setFrame(list_CRACKER[i].spr_CRACKER , list_CRACKER[i].state_CRACKER);
                }
            }


            //--------------------------------------------------------------------------------------//
            //                           IF PLAYER WAS GRABBING A CRACKER                           //
            //--------------------------------------------------------------------------------------//

            if(G_PHASE_SEQUENCE == CRACKER_SPOON_GRAB)
            {
                if(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER != NULL)
                {
                    SPR_setDepth(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER,0);
                }
            }

            //--------------------------------------------------------------------------------------//
            //                       IF PLAYER SPOON IS TRAPPED BY AN OYSTER                        //
            //--------------------------------------------------------------------------------------//

            else if(G_PHASE_SEQUENCE == CRACKER_SPOON_TRAPPED)
            {
                SPR_setDepth(list_CRACKER[G_SELECTED_CRACKER].spr_CRACKER,0);
            }
        }


        SPR_update();
        SYS_doVBlankProcess();


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , image_CRACKERS_BG_B.palette->data     , 16 * 2 );
        memcpy( &palette_64[16] , image_CRACKERS_BG_A.palette->data     , 16 * 2 );
        memcpy( &palette_64[32] , palette_SPR_HAND_PART_1.data          , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_HAND_PART_2.data          , 16 * 2 );




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//


        G_SCENE                 = SCENE_FADE_IN_CRACKERS;
        G_SCENE_TYPE            = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT            = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED          = TRUE;

    }

    // DOCTORS MINIGAME //
    else if(G_SCENE_TYPE == SCENE_BOXING_MINIGAME)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_initEx(5);

        VDP_setHilightShadow(FALSE);

        VDP_setScrollingMode(HSCROLL_TILE, VSCROLL_PLANE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        G_ADR_VRAM_BG_B = 1; //TILE_USER_INDEX

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_B                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_BOXING_BG_B_DEF.tileset, G_ADR_VRAM_BG_B, CPU);

        if(G_RUN_DIRECTION == DIRECTION_FW)
        {
            VDP_setTileMapEx(BG_B, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0,  0,  32, 64, 32, CPU);
        }

        else
        {
            VDP_setTileMapEx(BG_B, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B),  0,  0,    0, 32,  40, 13, CPU);

            VDP_setTileMapEx(BG_B, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B),  0, 13,  768, 45,  32, 19, CPU);

            VDP_setTileMapEx(BG_B, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 32, 13,  736, 45,  32, 19, CPU);
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        BG_A_1                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_BOXING_BG_B_DEF.tileset->numTile;
        VDP_loadTileSet(image_BOXING_BG_A1.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_BOXING_BG_A1.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0,  0,  0, 40, 12, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        BG_A_2                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//


        if(G_RUN_DIRECTION == DIRECTION_FW)
        {
            VDP_setTileMapEx(BG_A, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  13,  0,  13, 64, 19, CPU);
        }

        else
        {
            VDP_setTileMapEx(BG_A, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  13,  768, 13, 32, 19, CPU);

            VDP_setTileMapEx(BG_A, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 32, 13,  736, 13, 32, 19, CPU);
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         GONG                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_GONG = 1699;
        VDP_loadTileSet(image_GONG1_BG_B.tileset, G_ADR_VRAM_GONG, CPU);
        VDP_setTileMapEx(BG_B, image_GONG1_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_GONG), 32,  7,  0,  0, 5, 3, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         THUMB                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_THUMB = 1714;
        VDP_loadTileSet(image_THUMB1_BG_A.tileset, G_ADR_VRAM_THUMB, CPU);
        VDP_setTileMapEx(BG_A, image_THUMB1_BG_A.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_THUMB), 20,  1,  0,  0, 7, 3, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         DESK                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_DESK = 1735;
        VDP_loadTileSet(image_DESK1_BG_A.tileset, G_ADR_VRAM_DESK, CPU);
        VDP_setTileMapEx(BG_A, image_DESK1_BG_A.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DESK), 34,  10,  0,  0, 5, 2, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                     OBSTACLES                                        //
        //                                                                                      //
        //**************************************************************************************//

        for(i=0 ; i<MAX_OBSTACLES ; i++)
        {
            LIST_OBSTACLES[i].row         = TABLES_OBSTACLES[i].row;

            LIST_OBSTACLES[i].type        = TABLES_OBSTACLES[i].type;
            LIST_OBSTACLES[i].hit         = FALSE;

            LIST_OBSTACLES[i].pos_X       = 0;
            LIST_OBSTACLES[i].pos_Y       = TABLES_OBSTACLES[i].height * -1;

            LIST_OBSTACLES[i].width       = TABLES_OBSTACLES[i].width;
            LIST_OBSTACLES[i].height      = TABLES_OBSTACLES[i].height;

            LIST_OBSTACLES[i].index_trash = TABLES_OBSTACLES[i].index_trash;
        }




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        CHRONO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_CHRONO = SPR_addSpriteEx(&tiles_SPR_CHRONO, 192, 16, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 1), SPR_FLAG_AUTO_TILE_UPLOAD); // 6 TILES


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                      WATCH HAND                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_WATCH_HAND = SPR_addSpriteEx(&tiles_SPR_WATCH_HAND, 184, 32, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 7), SPR_FLAG_AUTO_TILE_UPLOAD); // 8 TILES

        if(G_RUN_DIRECTION == DIRECTION_FW)
        {
            G_COUNTER_WATCH_HAND = 0;

            G_INDEX_WATCH = 0;
        }

        else
        {
            SPR_setFrame(sprite_WATCH_HAND,G_INDEX_WATCH);
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        ROUND                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_ROUND = SPR_addSpriteEx(&tiles_SPR_ROUND, 48, 8, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 15), SPR_FLAG_AUTO_TILE_UPLOAD); // 4 TILES

        if(G_RUN_DIRECTION == DIRECTION_FW)
        {
            G_INDEX_ROUND = 0;
        }

        else
        {
            SPR_setFrame(sprite_ROUND,G_INDEX_ROUND);
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        HAMMER                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_HAMMER = SPR_addSpriteEx(&tiles_SPR_HAMMER, 280, 24, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 19), SPR_FLAG_AUTO_TILE_UPLOAD); // 31 TILES


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        BOXERS                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_BOXERS = SPR_addSpriteEx(&tiles_SPR_BOXERS, 80, 0, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, 1664), SPR_FLAG_AUTO_TILE_UPLOAD);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         LARRY                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        if(G_RUN_DIRECTION == DIRECTION_FW)
        {
            larry_BOXING.pos_X                  = 180;
            larry_BOXING.pos_Y                  = TOP_BOUND;

            larry_BOXING.spr_LARRY_BOXING       = SPR_addSpriteEx(&tiles_SPR_LARRY_BOXING_FW, larry_BOXING.pos_X, larry_BOXING.pos_Y, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 50), SPR_FLAG_AUTO_TILE_UPLOAD); // 37 TILES

            G_PHASE_SEQUENCE                    = BOXING_PHASE_RUN;
        }

        else
        {
            larry_BOXING.pos_X                  = 144;
            larry_BOXING.pos_Y                  = TOP_BOUND;

            larry_BOXING.spr_LARRY_BOXING       = SPR_addSpriteEx(&tiles_SPR_LARRY_BOXING_BW, larry_BOXING.pos_X, larry_BOXING.pos_Y, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 50), SPR_FLAG_AUTO_TILE_UPLOAD); // 37 TILES

            G_PHASE_SEQUENCE                    = BOXING_PHASE_EXIT_STORE;
        }



        larry_BOXING.state                  = LARRY_PHASE_RUN;

        larry_BOXING.counter_SPRITE_FRAME   = 5;
        larry_BOXING.index_SPRITE_FRAME     = 0;

        larry_BOXING.velocity               = 2;
        larry_BOXING.counter_HIT            = 0;

        larry_BOXING.row                    = ROW_BG;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        TRASHS                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        LIST_TRASH[0] = SPR_addSpriteEx(&tiles_SPR_TRASH, 0, -40, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 1746), SPR_FLAG_AUTO_TILE_UPLOAD);
        LIST_TRASH[1] = SPR_addSpriteEx(&tiles_SPR_TRASH, 0, -40, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 1746 + 20), SPR_FLAG_AUTO_TILE_UPLOAD);




        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH);
        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH + 1);
        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        if(G_RUN_DIRECTION == DIRECTION_FW)
        {
            for (i=0; i<14; i++)
            {
                scrollTable_BG[i] = 0;
            }


            G_POS_X_CAMERA = 0;
        }

        else
        {
            for (i=0; i<14; i++)
            {
                scrollTable_BG[i] = -6080;// -6144
            }


            G_POS_X_CAMERA = 6080;// -6144
        }

        VDP_setHorizontalScrollTile(BG_B, 13, scrollTable_BG, 14, CPU);
        VDP_setHorizontalScrollTile(BG_A, 13, scrollTable_BG, 14, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       PALETTES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        memcpy( &palette_64[0]  , palette_BOXING.data              , 32 * 2 );
        memcpy( &palette_64[32] , image_BOXING_BG_A1.palette->data , 16 * 2 );
        //memcpy( &palette_64[32] , image_BOXING_BG_A2.palette->data , 16 * 2 );
        memcpy( &palette_64[48] , palette_SPR_STOOGES.data         , 16 * 2 );

        SPR_update();




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       VARIABLES                                      //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_COUNTER_BOXERS        = 0;

        G_OBSTACLE_TYPE         = 0;

        G_REWARD                = 0;


        // BOXING_PHASE_RUN | BOXING_PHASE_EXIT_STORE


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_BOXING_MINIGAME;
        G_SCENE_NEXT            = SCENE_BOXING_MINIGAME;

        G_SCENE_LOADED          = TRUE;




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        if(G_RUN_DIRECTION == DIRECTION_BW)
        {
            XGM_startPlay(MUSIC_BOXING);
        }

        else
        {
            XGM_startPlayPCM(SOUND_CROWD , 15 , SOUND_PCM_CH2);
        }
    }



    //-------------------------------------------------//
    //                    CONTRACTS                    //
    //-------------------------------------------------//

    // CONTRACT QUESTION MARK //
    else if(G_SCENE_TYPE == SCENE_CONTRACT_QUESTION_MARK)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_init();

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_CONTRACT_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CONTRACT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_CONTRACT_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_CONTRACT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         TEXT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_CONTRACT_QUESTION_MARK.tileset, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_QUESTION_MARK.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile), 6, 6, 0, 0, 27, 11, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        sprite_PAUSE = SPR_addSprite(&tiles_SPR_PAUSE,  0, -8, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));




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


        G_PHASE_SEQUENCE        = CONTRACT_PHASE;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_CONTRACT_QUESTION_MARK;
        G_SCENE_NEXT            = SCENE_CONTRACT_QUESTION_MARK;

        G_SCENE_LOADED          = TRUE;
    }

    // CONTRACT DOCTORS //
    else if(G_SCENE_TYPE == SCENE_CONTRACT_DOCTORS)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_init();

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_CONTRACT_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CONTRACT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_CONTRACT_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_CONTRACT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         TEXT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_CONTRACT_DOCTORS.tileset, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_DOCTORS.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile), 6, 6, 0, 0, 27, 11, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        sprite_PAUSE = SPR_addSprite(&tiles_SPR_PAUSE,  0, -8, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));




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


        G_REWARD                = 0;


        G_PHASE_SEQUENCE        = CONTRACT_PHASE;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_CONTRACT_DOCTORS;
        G_SCENE_NEXT            = SCENE_CONTRACT_DOCTORS;

        G_SCENE_LOADED          = TRUE;
    }

    // CONTRACT DOCTORS //
    else if(G_SCENE_TYPE == SCENE_CONTRACT_CRACKERS)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_init();

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_CONTRACT_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CONTRACT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_CONTRACT_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_CONTRACT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         TEXT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_CONTRACT_CRACKERS.tileset, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_CRACKERS.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile), 6, 6, 0, 0, 27, 11, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        sprite_PAUSE = SPR_addSprite(&tiles_SPR_PAUSE,  0, -8, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));




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


        G_NUMBER_CRACKERS_MAX       = 14;
        G_NUMBER_CRACKERS           = 14;
        G_NUMBER_GRABBED_CRACKERS   = 14;


        G_REWARD                = 0;


        G_PHASE_SEQUENCE        = CONTRACT_PHASE;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_CONTRACT_CRACKERS;
        G_SCENE_NEXT            = SCENE_CONTRACT_CRACKERS;

        G_SCENE_LOADED          = TRUE;
    }

    // CONTRACT DOCTORS //
    else if(G_SCENE_TYPE == SCENE_CONTRACT_WAITERS)
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
        //                                   NUMBERS TILESET                                    //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_WAITERS_CONTRACT_NUMBERS.tileset, TILE_FONT_INDEX + 16, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                    SETUP DISPLAY                                     //
        //                                                                                      //
        //**************************************************************************************//

        VDP_setPlaneSize(64,32,TRUE);

        SPR_init();

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_CONTRACT_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CONTRACT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_CONTRACT_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_CONTRACT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         TEXT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_CONTRACT_WAITERS.tileset, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_WAITERS.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile), 6, 6, 0, 0, 27, 11, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                       MAX PIES                                       //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//
        //G_MAX_PIES = 10;
        G_MAX_PIES = random_NUMBER(51,129);

        //u8 random_entry = random_NUMBER(0,3);
        //G_MAX_PIES  = TABLE_MAX_PIES[random_entry];

        if(G_MAX_PIES < 100)
        {
            VDP_drawIntEx_BG_B_CPU(G_MAX_PIES , 2 , 17, 13 , PAL0);
        }

        else
        {
            VDP_drawIntEx_BG_B_CPU(G_MAX_PIES , 3 , 17, 13 , PAL0);
        }




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        sprite_PAUSE = SPR_addSprite(&tiles_SPR_PAUSE,  0, -8, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));




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


        G_REWARD                = 0;


        G_PHASE_SEQUENCE        = CONTRACT_PHASE;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_CONTRACT_WAITERS;
        G_SCENE_NEXT            = SCENE_CONTRACT_WAITERS;

        G_SCENE_LOADED          = TRUE;
    }

    // CONTRACT BOXING //
    else if(G_SCENE_TYPE == SCENE_CONTRACT_BOXING)
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
        //                                   NUMBERS TILESET                                    //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_WAITERS_CONTRACT_NUMBERS.tileset, TILE_FONT_INDEX + 16, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                    SETUP DISPLAY                                     //
        //                                                                                      //
        //**************************************************************************************//

        VDP_setPlaneSize(64,32,TRUE);

        SPR_init();

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_CONTRACT_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CONTRACT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_CONTRACT_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_CONTRACT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         TEXT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        VDP_loadTileSet(image_CONTRACT_BOXING.tileset, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_BOXING.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile), 6, 6, 0, 0, 27, 11, CPU);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        sprite_PAUSE = SPR_addSprite(&tiles_SPR_PAUSE,  0, -8, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));




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


        G_REWARD                = 0;


        G_PHASE_SEQUENCE        = CONTRACT_PHASE;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_CONTRACT_BOXING;
        G_SCENE_NEXT            = SCENE_CONTRACT_BOXING;

        G_SCENE_LOADED          = TRUE;
    }

    // CONTRACT SAFE //
    else if(G_SCENE_TYPE == SCENE_CONTRACT_SAFE)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_init();

        VDP_setHilightShadow(FALSE);




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

        VDP_loadTileSet(image_CONTRACT_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
        VDP_setTileMapEx(BG_B, image_CONTRACT_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         BG_A                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_CONTRACT_BG_B.tileset->numTile;
        VDP_loadTileSet(image_CONTRACT_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
        VDP_setTileMapEx(BG_A, image_CONTRACT_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0,  0, 0, 0, 40, 28, CPU);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         TEXT                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        if(G_LUCK == TRUE)
        {
            VDP_loadTileSet(image_CONTRACT_QUESTION_MARK.tileset, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_CONTRACT_QUESTION_MARK.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile), 6, 6, 0, 0, 27, 11, CPU);
        }

        else
        {
            VDP_loadTileSet(image_CONTRACT_NO_LUCK.tileset, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_CONTRACT_NO_LUCK.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CONTRACT_BG_A.tileset->numTile), 6, 6, 0, 0, 27, 11, CPU);
        }



        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = 0;

        VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
        VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                      SPRITES                                         //
        //                                                                                      //
        //**************************************************************************************//

        sprite_PAUSE = SPR_addSprite(&tiles_SPR_PAUSE,  0, -8, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));




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


        G_PHASE_SEQUENCE        = CONTRACT_PHASE;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_CONTRACT_SAFE;
        G_SCENE_NEXT            = SCENE_CONTRACT_SAFE;

        G_SCENE_LOADED          = TRUE;
    }




    // REWARD //
    else if(G_SCENE_TYPE == SCENE_REWARD)
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

        VDP_setPlaneSize(64,32,TRUE);

        SPR_initEx(200);

        VDP_setHilightShadow(FALSE);

        VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_FONT.tileset, TILE_FONT_INDEX, CPU);

        VDP_loadTileSet(image_TILES_BASE_SGDK.tileset, 0, CPU);


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
        VDP_drawIntEx_BG_A_CPU(G_REWARD,1,26,9,PAL1);




        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                SETUP PLANES POSITION                                 //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        G_POS_Y_CAMERA = -4;


        VDP_setVerticalScroll(BG_A ,G_POS_Y_CAMERA);




        //**************************************************************************************//
        //                                                                                      //
        //                                       SPRITES                                        //
        //                                                                                      //
        //**************************************************************************************//

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                          DAY                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_DAY = SPR_addSprite(&tiles_SPR_DAY,  224, 63, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));
        SPR_setFrame(sprite_DAY , G_DAY - 1);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                        PAUSE                                         //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_PAUSE = SPR_addSprite(&tiles_SPR_PAUSE,  0, -8, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));

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


        G_PHASE_SEQUENCE        = REWARD_PHASE;


        G_SCENE                 = SCENE_FADE_IN;
        G_SCENE_TYPE            = SCENE_REWARD;
        G_SCENE_NEXT            = SCENE_REWARD;

        G_SCENE_LOADED          = TRUE;


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        XGM_startPlay(MUSIC_REWARD);

    }

    // GAME OVER //
    else if(G_SCENE_TYPE == SCENE_GAMEOVER)
    {
        //**************************************************************************************//
        //                                                                                      //
        //                                    SETUP DISPLAY                                     //
        //                                                                                      //
        //**************************************************************************************//

        VDP_setPlaneSize(64,32,TRUE);

        // FAIL //
        /*if(G_MONEY < 5000)
        {
            SPR_initEx(15);//170
        }

        // SUCCESS //
        else
        {
            SPR_initEx(15);//120
        }*/

        SPR_initEx(15);

        VDP_setHilightShadow(FALSE);




        //**************************************************************************************//
        //                                                                                      //
        //                                   NUMBERS TILESET                                    //
        //                                                                                      //
        //**************************************************************************************//

        VDP_loadTileSet(image_BANK_NUMBERS.tileset, TILE_FONT_INDEX + 16, CPU);




        //**************************************************************************************//
        //                                                                                      //
        //                                         BG                                           //
        //                                                                                      //
        //**************************************************************************************//

        G_ADR_VRAM_BG_B = 0;


        //--------------------------------------------------------------------//
        //                                                                    //
        //                     FAIL TO SAVE THE ORPHANAGE                     //
        //                                                                    //
        //--------------------------------------------------------------------//
        if(G_MONEY < 5000)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_INTRO_SCREEN_7_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_7_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                   GRANDMA TILES BG_B                                 //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GRANDMA_INTRO_BG_B_STEP0.tileset, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_GRANDMA_INTRO_BG_B_STEP0.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile), 6, 14, 0, 0, 5, 6, CPU);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile + image_GRANDMA_INTRO_BG_B_STEP0.tileset->numTile;
            VDP_loadTileSet(image_INTRO_SCREEN_7_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);

            VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 2, 0, 2,  4,  4, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                   GRANDMA TILES BG_A                                 //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GRANDMA_INTRO_BG_A_STEP0.tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_A, image_GRANDMA_INTRO_BG_A_STEP0.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile), 6, 14, 0, 0, 5, 6, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                     DIALOG TILES                                     //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile + image_GRANDMA_INTRO_BG_A_STEP0.tileset->numTile;
            VDP_loadTileSet(image_GAMEOVER_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                      TEXT TILES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GAMEOVER_FAIL_TEXT.tileset, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile, CPU);
        }


        //--------------------------------------------------------------------//
        //                                                                    //
        //                         SAVE THE ORPHANAGE                         //
        //                                                                    //
        //--------------------------------------------------------------------//
        else if(G_MONEY < 10000)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_INTRO_SCREEN_7_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_7_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                   GRANDMA TILES BG_B                                 //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GRANDMA_INTRO_BG_B_STEP0.tileset, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_B, image_GRANDMA_INTRO_BG_B_STEP0.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile), 6, 14, 0, 0, 5, 6, CPU);




            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile + image_GRANDMA_INTRO_BG_B_STEP0.tileset->numTile;
            VDP_loadTileSet(image_INTRO_SCREEN_7_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);

            VDP_setTileMapEx(BG_B, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 2, 0, 2,  4,  4, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                   GRANDMA TILES BG_A                                 //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GRANDMA_INTRO_BG_A_STEP0.tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile, CPU);
            VDP_setTileMapEx(BG_A, image_GRANDMA_INTRO_BG_A_STEP0.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile), 6, 14, 0, 0, 5, 6, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                     DIALOG TILES                                     //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile + image_GRANDMA_INTRO_BG_A_STEP0.tileset->numTile;
            VDP_loadTileSet(image_GAMEOVER_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                      TEXT TILES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GAMEOVER_SUCCESS_TEXT.tileset, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile, CPU);
        }


        //--------------------------------------------------------------------//
        //                                                                    //
        //                    SAVE AND REPAIR THE ORPHANAGE                   //
        //                                                                    //
        //--------------------------------------------------------------------//
        else if(G_MONEY < 20000)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GAMEOVER_SUCCESS_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_GAMEOVER_SUCCESS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_GAMEOVER_SUCCESS_BG_B.tileset->numTile;
            VDP_loadTileSet(image_GAMEOVER_SUCCESS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                     DIALOG TILES                                     //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_GAMEOVER_SUCCESS_BG_A.tileset->numTile;
            VDP_loadTileSet(image_GAMEOVER_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                      TEXT TILES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GAMEOVER_SUCCESS_TEXT.tileset, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile, CPU);
        }


        //--------------------------------------------------------------------//
        //                                                                    //
        //       SAVE AND REPAIR THE ORPHANAGE, AND MARRY THE DAUGHTERS       //
        //                                                                    //
        //--------------------------------------------------------------------//
        else
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_B                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GAMEOVER_SUCCESS_BG_B.tileset, G_ADR_VRAM_BG_B, CPU);
            VDP_setTileMapEx(BG_B, image_GAMEOVER_SUCCESS_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                         BG_A                                         //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_GAMEOVER_SUCCESS_BG_B.tileset->numTile;
            VDP_loadTileSet(image_GAMEOVER_SUCCESS_BG_A.tileset, G_ADR_VRAM_BG_A, CPU);
            VDP_setTileMapEx(BG_A, image_GAMEOVER_SUCCESS_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 0, 0, 0, 0, 40, 28, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                     DIALOG TILES                                     //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            G_ADR_VRAM_DIALOG = G_ADR_VRAM_BG_A + image_GAMEOVER_SUCCESS_BG_A.tileset->numTile;
            VDP_loadTileSet(image_GAMEOVER_DIALOG.tileset, G_ADR_VRAM_DIALOG, CPU);


            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                      TEXT TILES                                      //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//

            VDP_loadTileSet(image_GAMEOVER_SUCCESS_TEXT.tileset, G_ADR_VRAM_DIALOG + image_GAMEOVER_DIALOG.tileset->numTile, CPU);
        }




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

        //sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  101, 142, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        sprite_STOOGES = SPR_addSpriteEx(&tiles_SPR_STOOGES_WALK, 101, 147, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 1664 + 40 + 9), SPR_FLAG_AUTO_TILE_UPLOAD);


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                            DIALOG ARROW SPRITE OFF SCREEN                            //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        sprite_ARROW_DIALOG = SPR_addSprite(&tiles_SPR_GAMEOVER_ARROW,   -24, -24, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));


        if(G_MONEY < 5000)
        {
            //--------------------------------------------------------------------------------------//
            //                                                                                      //
            //                                     BANKER SPRITES                                   //
            //                                                                                      //
            //--------------------------------------------------------------------------------------//
            //sprite_BANKER[0] = SPR_addSprite(&tiles_SPR_BANKER_PART2,   118, 125, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
            //sprite_BANKER[1] = SPR_addSprite(&tiles_SPR_BANKER_PART1,   118, 125, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));

            sprite_BANKER[0] = SPR_addSpriteEx(&tiles_SPR_BANKER_PART2, 118, 130, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, 1664), SPR_FLAG_AUTO_TILE_UPLOAD);
            sprite_BANKER[1] = SPR_addSpriteEx(&tiles_SPR_BANKER_PART1, 118, 130, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, 1664 + 40), SPR_FLAG_AUTO_TILE_UPLOAD);

            SPR_setFrame(sprite_BANKER[0] , 3);
            SPR_setFrame(sprite_BANKER[1] , 2);
        }

        else
        {
            SPR_setFrame(sprite_ARROW_DIALOG,1);

            SPR_setPosition(sprite_STOOGES,55,147);
        }


        SPR_setFrame(sprite_STOOGES , 16);


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
        G_SCENE_TYPE        = SCENE_GAMEOVER;
        G_SCENE_NEXT        = SCENE_GAMEOVER;

        G_SCENE_LOADED      = TRUE;

    }


}


void init_THE_END()
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

    VDP_setPlaneSize(64,32,TRUE);

    SPR_initEx(470);

    VDP_setHilightShadow(FALSE);




    //**************************************************************************************//
    //                                                                                      //
    //                                  BASE TILES SGDK                                     //
    //                                                                                      //
    //**************************************************************************************//

    VDP_loadTileSet(image_TILES_BASE_SGDK.tileset, 0, CPU);




    //**************************************************************************************//
    //                                                                                      //
    //                                         BG                                           //
    //                                                                                      //
    //**************************************************************************************//

    G_ADR_VRAM_BG_B = 1;

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_B                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_loadTileSet(image_THE_END.tileset, G_ADR_VRAM_BG_B, CPU);
    VDP_setTileMapEx(BG_B, image_THE_END.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B),  0, 0, 0,  0, 20, 28, CPU);

    G_ADR_VRAM_BG_A = G_ADR_VRAM_BG_B + image_THE_END.tileset->numTile;
    VDP_loadTileSet(image_MOE_HEAD.tileset, G_ADR_VRAM_BG_A, CPU);
    VDP_setTileMapEx(BG_B, image_MOE_HEAD.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 34, 8, 0, 0, 10, 12, CPU);


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         BG_A                                         //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    VDP_setTileMapEx(BG_A, image_THE_END.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 0, 0, 20, 0, 20, 28, CPU);




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                SETUP PLANES POSITION                                 //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_POS_Y_CAMERA = 0;


    VDP_setVerticalScroll(BG_B,G_POS_Y_CAMERA);
    VDP_setVerticalScroll(BG_A,G_POS_Y_CAMERA);

    G_POS_X_CAMERA_CURTAIN_1 = -160;
    G_POS_X_CAMERA_CURTAIN_2 =  320;


    VDP_setHorizontalScroll(BG_B, G_POS_X_CAMERA_CURTAIN_1);
    VDP_setHorizontalScroll(BG_A, G_POS_X_CAMERA_CURTAIN_2);




    //**************************************************************************************//
    //                                                                                      //
    //                                      SPRITES                                         //
    //                                                                                      //
    //**************************************************************************************//

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       THE END                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    sprite_THE_END_1 = SPR_addSprite(&tiles_SPR_THE_END_1,   48,  -96, TILE_ATTR(PAL0, FALSE, FALSE, FALSE)); // 48 , 48

    SPR_update();
    SYS_doVBlankProcess();

    sprite_THE_END_2 = SPR_addSprite(&tiles_SPR_THE_END_2,  160,  -120, TILE_ATTR(PAL0, FALSE, FALSE, FALSE)); // 160 , 8

    SPR_update();
    SYS_doVBlankProcess();


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       THE END                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    sprite_CINEMAWARE = SPR_addSprite(&tiles_SPR_CINEMAWARE,   0, -48, TILE_ATTR(PAL0, FALSE, FALSE, FALSE)); // 96 , 152

    SPR_update();
    SYS_doVBlankProcess();




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    memcpy( &palette_64[0]  , image_THE_END.palette->data               , 16 * 2 );
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

    G_SCENE                 = SCENE_FADE_IN;
    G_SCENE_NEXT            = SCENE_THE_END;

    G_SCENE_LOADED          = TRUE;




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         AUDIO                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    XGM_startPlay(MUSIC_BILLBOARDS);
}