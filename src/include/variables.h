#ifndef _VARIABLES_H
#define _VARIABLES_H



#include "structures.h"




#define FAILED                          0
#define SUCCESS                         1




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   GAME REEL                                 //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define REEL_DISCLAIMER                 0
#define REEL_LOGO                       1
#define REEL_INTRO                      2
#define REEL_GAME                       3




//-----------------------------------------------------------------------------//
//                                                                             //
//                                 LOGO SCENES                                 //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define SCENE_DISCLAIMER_SCREEN         0




//-----------------------------------------------------------------------------//
//                                                                             //
//                                 LOGO SCENES                                 //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define SCENE_LOGO_SCREEN               0
#define SCENE_LOGO_SKIP                 1




//-----------------------------------------------------------------------------//
//                                                                             //
//                                 INTRO SCENES                                //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define SCENE_INTRO_SCREEN_1            1
#define SCENE_INTRO_SCREEN_2            2
#define SCENE_INTRO_SCREEN_3            3
#define SCENE_INTRO_SCREEN_4            4
#define SCENE_INTRO_SCREEN_5            5
#define SCENE_INTRO_SCREEN_6            6
#define SCENE_INTRO_SCREEN_7            7
#define SCENE_INTRO_EXIT                8

#define SCENE_FADE_IN                   40
#define SCENE_FADE_OUT                  41
#define SCENE_FADE_IN_BOXING            42




//-----------------------------------------------------------------------------//
//                                                                             //
//                                 GAME SCENES                                 //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define SCENE_BANK                      1
#define SCENE_BOXING                    2
#define SCENE_DOCTORS                   3
#define SCENE_DOLLAR                    4
#define SCENE_QUESTION_MARK             5
#define SCENE_SLAP                      6
#define SCENE_SWATTER                   7
#define SCENE_TRIVIA_SELECT             8
#define SCENE_WAITERS                   9
#define SCENE_CRACKERS                  10
#define SCENE_SAFE                      11
#define SCENE_ROULETTE                  12
#define SCENE_BOXING_MINIGAME           13
#define SCENE_TRIVIA_MINIGAME_TYPE1     14
#define SCENE_TRIVIA_MINIGAME_TYPE2     15
#define SCENE_TRIVIA_MINIGAME_TYPE3     16
#define SCENE_TRIVIA_QUESTION           17

#define SCENE_BOXING_SCREEN_TYPE1       18
#define SCENE_BOXING_SCREEN_TYPE2       19
#define SCENE_BOXING_SCREEN_TYPE3       20

#define SCENE_DOCTORS_MINIGAME          21
#define SCENE_WAITERS_MINIGAME          22
#define SCENE_CRACKERS_SCREEN           23
#define SCENE_CRACKERS_MINIGAME         24


#define SCENE_CONTRACT_QUESTION_MARK    27
#define SCENE_CONTRACT_DOCTORS          28
#define SCENE_CONTRACT_WAITERS          29
#define SCENE_CONTRACT_CRACKERS         30
#define SCENE_CONTRACT_BOXING           31
#define SCENE_REWARD                    32


#define SCENE_FADE_IN_CRACKERS          35
#define SCENE_FADE_OUT_CRACKERS         36

#define SCENE_GAMEOVER                  37






//-----------------------------------------------------------------------------//
//                                                                             //
//                                  ROULETTE                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define ROULETTE_PHASE_READY             0
#define ROULETTE_PHASE_CHOICE            1
#define ROULETTE_PHASE_VALIDATED         2
#define ROULETTE_PHASE_WALKOUT           3




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  CONTRACT                                   //
//                                                                             //
//-----------------------------------------------------------------------------//

#define CONTRACT_PHASE                  0
#define CONTRACT_PHASE_FADE_OUT         1




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   BANKER                                    //
//                                                                             //
//-----------------------------------------------------------------------------//

#define BANKER_PHASE_WALKIN              0
#define BANKER_PHASE_APPEAR              1




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   TRIVIA                                    //
//                                                                             //
//-----------------------------------------------------------------------------//

#define TRIVIA_PHASE_WALKIN              0
#define TRIVIA_PHASE_TURN_BACK           1
#define TRIVIA_PHASE_ANIM_ANSWERS        2
#define TRIVIA_PHASE_CHOICE              3
#define TRIVIA_PHASE_RESULT              4




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    SLAP                                     //
//                                                                             //
//-----------------------------------------------------------------------------//

#define SLAP_PHASE_WALKIN               0
#define SLAP_PHASE_ATTACK               1
#define SLAP_PHASE_RESULT_ATTACK        2
#define SLAP_PHASE_PAUSE                3
#define SLAP_PHASE_OVER                 4
#define SLAP_PHASE_HIT                  5


#define LEFT                            0
#define RIGHT                           1


#define SLAP_STATE_BACK_UP              7 // EAR //
#define SLAP_STATE_UP                   6 // FOREHEAD //
#define SLAP_STATE_FRONT_UP             5 // EYES //
#define SLAP_STATE_FRONT                4 // CHEEK //
#define SLAP_STATE_IDLE                 3
#define SLAP_STATE_FRONT_DOWN           2 // BELLY
#define SLAP_STATE_BACK                 1 // KNEE
#define SLAP_STATE_DOWN                 0 // KNEE




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    SLAP                                     //
//                                                                             //
//-----------------------------------------------------------------------------//

#define AXIS_CENTER                     0
#define AXIS_RIGHT                      1
#define AXIS_LEFT                       2




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  DOCTORS                                    //
//                                                                             //
//-----------------------------------------------------------------------------//

#define DOCTORS_PHASE_RACING            0
#define DOCTORS_PHASE_EXIT              1
#define DOCTORS_PHASE_GAME_OVER         2

#define PATIENT_NOT_HIT                 0
#define PATIENT_HIT                     1

#define PATIENT_BOX_MARGIN              16




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  CRACKERS                                   //
//                                                                             //
//-----------------------------------------------------------------------------//

#define CRACKERS_ROUND_1                0
#define CRACKERS_ROUND_2                1
#define CRACKERS_ROUND_3                2
#define CRACKERS_ROUND_4                3

#define CRACKERS_SCREEN_SPREAD          0
#define CRACKERS_SCREEN_SURPRISE_1      1
#define CRACKERS_SCREEN_SURPRISE_2      2
#define CRACKERS_SCREEN_SURPRISE_3      3
#define CRACKERS_SCREEN_SURPRISE_4      4
#define CRACKERS_SCREEN_OVER            5


#define CRACKER_PHASE_FREE              0
#define CRACKER_PHASE_OYSTER_1          1
#define CRACKER_PHASE_OYSTER_2          2
#define CRACKER_PHASE_OYSTER_3          3
#define CRACKER_PHASE_OYSTER_4          4
#define CRACKER_PHASE_OYSTER_5          5
#define CRACKER_PHASE_OYSTER_6          6
#define CRACKER_PHASE_TRAPPED           7
#define CRACKER_PHASE_GRABBED           8
#define CRACKER_PHASE_EATEN             9



#define CRACKER_SPOON_MOVE              0
#define CRACKER_SPOON_GRAB              1
#define CRACKER_SPOON_MISS              2
#define CRACKER_SPOON_TRAPPED           3




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  WAITERS                                    //
//                                                                             //
//-----------------------------------------------------------------------------//

#define WAITER_LARRY                    0
#define WAITER_CURLY                    1
#define WAITER_MOE                      2

#define CHAR_PHASE_IDLE                 0
#define CHAR_PHASE_CROUCH               1
#define CHAR_PHASE_GRAB                 2
#define CHAR_PHASE_AIM                  3
#define CHAR_PHASE_THROW                4
#define CHAR_PHASE_HIT_1                5
#define CHAR_PHASE_HIT_2                6
#define CHAR_PHASE_HIT_3                7
#define CHAR_PHASE_CROUCH_2             8

#define PIE_PHASE_SERVED                0
#define PIE_PHASE_AIM                   1
#define PIE_PHASE_GRAB                  2
#define PIE_PHASE_THROW                 3
#define PIE_PHASE_OUT                   4

#define WAITER_PHASE_DIALOG             0
#define WAITER_PHASE_ACTION             1
#define WAITER_PHASE_GAME_OVER          2

#define GUEST_WOMAN                     0
#define GUEST_MAN_1                     1
#define GUEST_MAN_2                     2

#define NO_DEVIATION                    0
#define UP_DEVIATION                    1
#define DOWN_DEVIATION                  2

#define GUEST_ACTION_DELAY              46



//-----------------------------------------------------------------------------//
//                                                                             //
//                                  ICON TYPES                                 //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define ICON_BANKER                     0
#define ICON_BOXING                     1
#define ICON_DOCTORS                    2
#define ICON_DOLLAR                     3
#define ICON_QUESTION                   4
#define ICON_SLAP                       5
#define ICON_SWATTER                    6
#define ICON_TRIVIA                     7
#define ICON_WAITERS                    8
#define ICON_CRACKERS                   9
#define ICON_SAFE                      10




//-----------------------------------------------------------------------------//
//                                                                             //
//                                 STREET TYPES                                //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define STREET_TYPE_0                   0
#define STREET_DOLLAR_TYPE_1            1
#define STREET_DOLLAR_TYPE_2            2
#define STREET_DOLLAR_TYPE_3            3
//#define STREET_TYPE_4                 4
#define STREET_TYPE_QUESTION_MARK       5
#define STREET_TYPE_BOXING              6
#define STREET_TYPE_DOCTORS             7
#define STREET_TYPE_DOLLAR              8
#define STREET_TYPE_CRACKERS            9
#define STREET_TYPE_TRIVIA_1           10
#define STREET_TYPE_TRIVIA_2           11
#define STREET_TYPE_TRIVIA_3           12
#define STREET_TYPE_WAITERS            13





//-----------------------------------------------------------------------------//
//                                                                             //
//                                     MUSIC                                   //
//                                                                             //
//-----------------------------------------------------------------------------//

#define MUSIC_ROULETTE                  64





//-----------------------------------------------------------------------------//
//                                                                             //
//                                 SOUND EFFECTS                               //
//                                                                             //
//-----------------------------------------------------------------------------//

#define SOUND_INTRO_SCREEN1             69

#define SOUND_SLAP_MISS_1               70
#define SOUND_SLAP_MISS_2               71
#define SOUND_SLAP_MISS_3               72
#define SOUND_SLAP_MISS_4               73

#define SOUND_SLAP_EAR                  74
#define SOUND_SLAP_FOREHEAD             75
#define SOUND_SLAP_EYES                 76
#define SOUND_SLAP_CHEEK                77
#define SOUND_SLAP_BELLY                78
#define SOUND_SLAP_KNEE                 79
#define SOUND_SLAP_HIT                  80

#define SOUND_BANKER_LAUGH              81
#define SOUND_HAND                      82
#define SOUND_WALKOUT                   83
#define SOUND_SWATTER                   84
#define SOUND_HEAD_SHOCK                85
#define SOUND_JOY_CRY                   86
#define SOUND_OYSTER                    87
#define SOUND_MONEY                     88

#define SOUND_CRACKERS_CRY_1            89
#define SOUND_CRACKERS_CRY_2            90
#define SOUND_CRACKERS_CRY_3            91
#define SOUND_CRACKERS_CRY_4            92
#define SOUND_CRACKERS_CRY_5            93

#define SOUND_VOICE_DOCTORS             94
#define SOUND_DOCTORS_CRY_1             95
#define SOUND_DOCTORS_CRY_2             96
#define SOUND_DOCTORS_CRASH_1           97
#define SOUND_DOCTORS_CRASH_2           98
#define SOUND_DOCTORS_CRASH_3           99
#define SOUND_ENGINE_1                 100
#define SOUND_ENGINE_2                 101

#define SOUND_PIE_THROW                102
#define SOUND_PIE_HIT                  103
#define SOUND_PIE_WALL                 104

#define SOUND_BOXING                   105

#define SOUND_TIRE                     106








extern char text_output[5];
extern u16 palette_64[64];




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                  GENERAL VARIABLES                                   //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern u8 G_REEL;

extern u8 G_SCENE;

extern u8 G_SCENE_TYPE;

extern u8 G_SCENE_NEXT;

extern bool G_SCENE_LOADED;

extern u16 G_ADR_VRAM_BG_B;

extern u16 G_ADR_VRAM_BG_A;

extern u16 G_MONEY;

extern u8 G_PHASE_SEQUENCE;

extern bool G_PAUSE;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                        INTRO                                         //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern u16 G_COUNTER_1;

extern u8 G_INDEX_1;

extern u8 G_INDEX_2;

extern u8 G_INDEX_3;

extern u8 G_INDEX_PALETTE_CYCLE;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                      ROULETTE                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern u8 G_DAY;

extern u8 G_STREET_TYPE;

extern u8 G_HIGHSTREET_POSITION;

extern s16 G_POS_Y_CAMERA;

extern u16 G_ADR_VRAM_HUB;

extern u8 G_STREET_TYPE;

extern u16 G_ADR_VRAM_ICONS[6];

extern u8 TABLE_GENERATED_ICONS[6];

extern u8 TABLE_GENERATED_HAND_POSITION[10];

extern u8 G_HAND_SPEED;

extern u16 G_COUNTER_ROULETTE;

extern u8 G_CURRENT_TURN;

extern u8 G_FINGER_NUMBER;

extern u8 G_SELECTED_ICON_ID;

extern bool G_RANDOM_HAND_MOVE_VALIDATED;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                        REWARD                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern u16 G_REWARD;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                        TRIVIA                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern u8 G_SELECTED_QUESTION;

extern u8 G_SELECTED_ANSWER;

extern u16 G_ADR_VRAM_DIALOG;

extern u16 G_ADR_VRAM_QUESTION;

extern bool G_STATUS_MISSION;

extern bool G_QUESTION_LOCKED;

extern u8 G_TRIVIA_TYPE;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                         SLAP                                         //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern bool G_AXIS;

extern s8 G_CURRENT_STATE;

extern s8 G_PREVIOUS_STATE;

extern s16 G_POS_X_METER_SLAP;

extern u8 G_COUNTER_SLAP;

extern u8 G_COUNTER_WAIT;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                   DOCTORS MINIGAME                                   //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern struct_CAR_ list_CARS[3];

extern u8 G_HIT_NUMBER;

extern u8 G_COUNTER_DOCTORS;

extern u8 G_CAR_SPEED;

u8 G_CAR_COUNTER_SPEED;

extern u8 G_PREVIOUS_PATIENT_TYPE;

extern bool G_RANDOM_OK;

extern struct_NURSE_ nurse;

extern struct_PATIENT_ patient;

extern struct_ITEM_ list_ITEM[2];




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                   CRACKERS MINIGAME                                  //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern s16 G_POS_X_PLAYER;

extern s16 G_POS_Y_PLAYER;

extern struct_CRACKER_ list_CRACKER[14];

extern bool G_CRACKERS_INIT;

extern u8 G_CRACKERS_SCREEN_TYPE;

extern u8 G_NUMBER_CRACKERS_MAX;

extern u8 G_NUMBER_CRACKERS;

extern u8 G_NUMBER_GRABBED_CRACKERS;

extern u8 G_SELECTED_CRACKER;

extern u16 G_COUNTER_CRACKERS;

extern u8 G_COUNTER_OYSTER;

extern u8 G_SPOON_FRAME;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                   WAITERS MINIGAME                                   //
//                                                                                      //
//--------------------------------------------------------------------------------------//

extern u16 G_ADR_VRAM_BG_B_PIE_LEFT_0;
extern u16 G_ADR_VRAM_BG_B_PIE_LEFT_1;
extern u16 G_ADR_VRAM_BG_B_PIE_LEFT_2;

extern u16 G_ADR_VRAM_BG_B_PIE_RIGHT_0;
extern u16 G_ADR_VRAM_BG_B_PIE_RIGHT_1;
extern u16 G_ADR_VRAM_BG_B_PIE_RIGHT_2;

extern u16 G_ADR_VRAM_BG_A_PIE_LEFT_0;
extern u16 G_ADR_VRAM_BG_A_PIE_LEFT_1;
extern u16 G_ADR_VRAM_BG_A_PIE_LEFT_2;

extern u16 G_ADR_VRAM_BG_A_PIE_RIGHT_0;
extern u16 G_ADR_VRAM_BG_A_PIE_RIGHT_1;
extern u16 G_ADR_VRAM_BG_A_PIE_RIGHT_2;

extern u16 G_ADR_VRAM_BG_B_PIE_UP_LEFT_0;
extern u16 G_ADR_VRAM_BG_B_PIE_UP_LEFT_1;
extern u16 G_ADR_VRAM_BG_B_PIE_UP_LEFT_2;

extern u16 G_ADR_VRAM_BG_B_PIE_UP_RIGHT_0;
extern u16 G_ADR_VRAM_BG_B_PIE_UP_RIGHT_1;
extern u16 G_ADR_VRAM_BG_B_PIE_UP_RIGHT_2;

extern u16 G_ADR_VRAM_BG_A_PIE_UP_LEFT_0;
extern u16 G_ADR_VRAM_BG_A_PIE_UP_LEFT_1;
extern u16 G_ADR_VRAM_BG_A_PIE_UP_LEFT_2;

extern u16 G_ADR_VRAM_BG_A_PIE_UP_RIGHT_0;
extern u16 G_ADR_VRAM_BG_A_PIE_UP_RIGHT_1;
extern u16 G_ADR_VRAM_BG_A_PIE_UP_RIGHT_2;

extern u16 G_ADR_VRAM_BG_B_PIE_DOWN_0;
extern u16 G_ADR_VRAM_BG_B_PIE_DOWN_1;
extern u16 G_ADR_VRAM_BG_B_PIE_DOWN_2;

extern u16 G_ADR_VRAM_BG_A_PIE_DOWN_0;
extern u16 G_ADR_VRAM_BG_A_PIE_DOWN_1;
extern u16 G_ADR_VRAM_BG_A_PIE_DOWN_2;

extern u16 G_ADR_VRAM_TILES_MAN_1;
extern u16 G_ADR_VRAM_TILES_CURLY;


extern bool G_ACTION_WAITER_AUTHORIZED;
extern bool G_ACTION_GUEST_AUTHORIZED;

extern bool G_GUEST_SHOT_AUTHORIZED;

extern u8 G_DELAY_ACTION_WAITERS;


extern struct_WAITER_ list_WAITERS[3];
extern struct_WAITER_ list_GUESTS[3];


extern u8 G_SELECTED_WAITER;

extern u8 G_MAX_PIES;

extern u8 G_SERVED_PIES;

extern u8 G_USED_PIES;

extern u8 G_COUNTER_ACTION_WAITERS;

//extern u8 G_COUNTER_ACTION_GUESTS;

extern struct_WALL_PIE_ list_WALL_PIES_LEFT_BG_B[3];
extern struct_WALL_PIE_ list_WALL_PIES_RIGHT_BG_B[3];

extern struct_WALL_PIE_ list_WALL_PIES_LEFT_BG_A[3];
extern struct_WALL_PIE_ list_WALL_PIES_RIGHT_BG_A[3];

extern struct_WALL_PIE_ list_WALL_PIES_UP_LEFT_BG_B[3];
extern struct_WALL_PIE_ list_WALL_PIES_UP_RIGHT_BG_B[3];

extern struct_WALL_PIE_ list_WALL_PIES_UP_LEFT_BG_A[3];
extern struct_WALL_PIE_ list_WALL_PIES_UP_RIGHT_BG_A[3];

extern struct_WALL_PIE_ list_WALL_PIES_DOWN_BG_B[3];
extern struct_WALL_PIE_ list_WALL_PIES_DOWN_BG_A[3];






//**************************************************************************************//
//                                                                                      //
//                                      SPRITES                                         //
//                                                                                      //
//**************************************************************************************//

//-----------------------------------------------------------------------------//
//                                                                             //
//                                   SCREEN 1                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_DEFENDER_1;
extern Sprite *sprite_DEFENDER_2;
extern Sprite *sprite_DEFENDER_3;
extern Sprite *sprite_DEFENDER_4;
extern Sprite *sprite_OF;
extern Sprite *sprite_THE;
extern Sprite *sprite_CROWN;

extern Sprite *sprite_SH_INTRO_SCREEN_1[14];




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   SCREEN 2                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_RADAR;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   SCREEN 7                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_STOOGES;

extern Sprite *sprite_BANKER[2];




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    GLOBAL                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_PAUSE;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                     BANK                                    //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_DIALOG;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    DOLLAR                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_DOLLAR_BAG;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   ROULETTE                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_HAND_ROULETTE;

extern Sprite *sprite_ARROW_HUB;

extern Sprite *sprite_ICON_BANKER;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                     SLAP                                    //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_HAND_SLAP;

extern Sprite *sprite_METER_SLAP;

extern Sprite *sprite_MOE;

extern Sprite *sprite_LARRY;

extern Sprite *sprite_CURLY;

extern Sprite *sprite_COUNTER_SLAP;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    TRIVIA                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_ARROW_DIALOG;

extern Sprite *sprite_ANSWER_A;

extern Sprite *sprite_ANSWER_B;

extern Sprite *sprite_ANSWER_C;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    REWARD                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_DAY;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                 QUESTION_MARK                               //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_SCISSOR;

extern Sprite *sprite_ICE_CUBE;

extern Sprite *sprite_ICE_CUBE_SHADOW;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  CRACKERS                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_HAND[3];

extern Sprite *sprite_SPLASH;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  WAITERS                                    //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_HAND_WAITERS;

extern Sprite *sprite_BULB[5];




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    STREETS                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_STREET[3];






























#endif // _VARIABLES_H