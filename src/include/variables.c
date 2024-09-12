#include <genesis.h>




#include "structures.h"







char text_output[5];
u16 palette_64[64];




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                  GENERAL VARIABLES                                   //
//                                                                                      //
//--------------------------------------------------------------------------------------//

u8 G_REEL;

u8 G_SCENE;

u8 G_SCENE_TYPE;

u8 G_SCENE_NEXT;

bool G_SCENE_LOADED;

u16 G_ADR_VRAM_BG_B;

u16 G_ADR_VRAM_BG_A;

u16 G_MONEY;

u8 G_PHASE_SEQUENCE;

bool G_PAUSE;

bool G_LUCK;

//u16 G_BILL;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                        INTRO                                         //
//                                                                                      //
//--------------------------------------------------------------------------------------//

u16 G_COUNTER_1;

u8 G_INDEX_1;

u8 G_INDEX_2;

u8 G_INDEX_3;

u8 G_INDEX_PALETTE_CYCLE;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                      ROULETTE                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

u8 G_DAY;

u8 G_STREET_TYPE;

u8 G_HIGHSTREET_POSITION;

s16 G_POS_Y_CAMERA;

u16 G_ADR_VRAM_HUB;

// BG TO BE DISPLAYED DURING THE ROULETTE SEQUENCE //
u8 G_STREET_TYPE;

// DYNAMICALLY ALLOCATE VRAM ADRESSES FOR GENERATED ICONS DURING THE ROULETTE SEQUENCE //
u16 G_ADR_VRAM_ICONS[6];

// STORES ICONS ID RANDOMLY GENERATED FOR THE ROULETTE SEQUENCE //
u8 TABLE_GENERATED_ICONS[6];

// STORES DIFFERENT HAND POSITIONS //
u8 TABLE_GENERATED_HAND_POSITION[10];

// NUMBER OF FRAMES TO WAIT BEFORE HAND MOVES TO NEXT ICON //
u8 G_HAND_SPEED;

u16 G_COUNTER_ROULETTE;

u8 G_CURRENT_TURN;

u8 G_FINGER_NUMBER;

u8 G_SELECTED_ICON_ID;

bool G_RANDOM_HAND_MOVE_VALIDATED;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                        REWARD                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

u16 G_REWARD;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                        DOLLAR                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

u8 G_DOLLAR_TYPE;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                        TRIVIA                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

u8 G_SELECTED_QUESTION;

u8 G_SELECTED_ANSWER;

u16 G_ADR_VRAM_DIALOG;

u16 G_ADR_VRAM_QUESTION;

bool G_STATUS_MISSION;

bool G_QUESTION_LOCKED;

u8 G_TRIVIA_TYPE;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                         SLAP                                         //
//                                                                                      //
//--------------------------------------------------------------------------------------//

bool G_AXIS;

s8 G_CURRENT_STATE;

s8 G_PREVIOUS_STATE;

s16 G_POS_X_METER_SLAP;

u8 G_COUNTER_SLAP;

u8 G_COUNTER_WAIT;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                   DOCTORS MINIGAME                                   //
//                                                                                      //
//--------------------------------------------------------------------------------------//

struct_CAR_ list_CARS[3];

u8 G_HIT_NUMBER;

u8 G_COUNTER_DOCTORS;

u8 G_CAR_SPEED;

u8 G_CAR_COUNTER_SPEED;

u8 G_PREVIOUS_PATIENT_TYPE;

bool G_RANDOM_OK;

struct_NURSE_ nurse;

struct_PATIENT_ patient;

struct_ITEM_ list_ITEM[2];




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                   CRACKERS MINIGAME                                  //
//                                                                                      //
//--------------------------------------------------------------------------------------//

s16 G_POS_X_PLAYER;

s16 G_POS_Y_PLAYER;

struct_CRACKER_ list_CRACKER[14];

bool G_CRACKERS_INIT;

u8 G_CRACKERS_SCREEN_TYPE;

u8 G_NUMBER_CRACKERS_MAX;

u8 G_NUMBER_CRACKERS;

u8 G_NUMBER_GRABBED_CRACKERS;

u8 G_SELECTED_CRACKER;

u16 G_COUNTER_CRACKERS;

u8 G_COUNTER_OYSTER;

u8 G_SPOON_FRAME;




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                   WAITERS MINIGAME                                   //
//                                                                                      //
//--------------------------------------------------------------------------------------//

u16 G_ADR_VRAM_BG_B_PIE_LEFT_0;
u16 G_ADR_VRAM_BG_B_PIE_LEFT_1;
u16 G_ADR_VRAM_BG_B_PIE_LEFT_2;

u16 G_ADR_VRAM_BG_B_PIE_RIGHT_0;
u16 G_ADR_VRAM_BG_B_PIE_RIGHT_1;
u16 G_ADR_VRAM_BG_B_PIE_RIGHT_2;

u16 G_ADR_VRAM_BG_A_PIE_LEFT_0;
u16 G_ADR_VRAM_BG_A_PIE_LEFT_1;
u16 G_ADR_VRAM_BG_A_PIE_LEFT_2;

u16 G_ADR_VRAM_BG_A_PIE_RIGHT_0;
u16 G_ADR_VRAM_BG_A_PIE_RIGHT_1;
u16 G_ADR_VRAM_BG_A_PIE_RIGHT_2;


u16 G_ADR_VRAM_BG_B_PIE_UP_LEFT_0;
u16 G_ADR_VRAM_BG_B_PIE_UP_LEFT_1;
u16 G_ADR_VRAM_BG_B_PIE_UP_LEFT_2;

u16 G_ADR_VRAM_BG_B_PIE_UP_RIGHT_0;
u16 G_ADR_VRAM_BG_B_PIE_UP_RIGHT_1;
u16 G_ADR_VRAM_BG_B_PIE_UP_RIGHT_2;

u16 G_ADR_VRAM_BG_A_PIE_UP_LEFT_0;
u16 G_ADR_VRAM_BG_A_PIE_UP_LEFT_1;
u16 G_ADR_VRAM_BG_A_PIE_UP_LEFT_2;

u16 G_ADR_VRAM_BG_A_PIE_UP_RIGHT_0;
u16 G_ADR_VRAM_BG_A_PIE_UP_RIGHT_1;
u16 G_ADR_VRAM_BG_A_PIE_UP_RIGHT_2;

u16 G_ADR_VRAM_BG_B_PIE_DOWN_0;
u16 G_ADR_VRAM_BG_B_PIE_DOWN_1;
u16 G_ADR_VRAM_BG_B_PIE_DOWN_2;

u16 G_ADR_VRAM_BG_A_PIE_DOWN_0;
u16 G_ADR_VRAM_BG_A_PIE_DOWN_1;
u16 G_ADR_VRAM_BG_A_PIE_DOWN_2;

u16 G_ADR_VRAM_TILES_MAN_1;
u16 G_ADR_VRAM_TILES_CURLY;




bool G_ACTION_WAITER_AUTHORIZED;
bool G_ACTION_GUEST_AUTHORIZED;

bool G_GUEST_SHOT_AUTHORIZED;

u8 G_DELAY_ACTION_WAITERS;


struct_WAITER_ list_WAITERS[3];
struct_WAITER_ list_GUESTS[3];


u8 G_SELECTED_WAITER;

u8 G_MAX_PIES;

u8 G_SERVED_PIES;

u8 G_USED_PIES;

u8 G_COUNTER_ACTION_WAITERS;

struct_WALL_PIE_ list_WALL_PIES_LEFT_BG_B[3];
struct_WALL_PIE_ list_WALL_PIES_RIGHT_BG_B[3];

struct_WALL_PIE_ list_WALL_PIES_LEFT_BG_A[3];
struct_WALL_PIE_ list_WALL_PIES_RIGHT_BG_A[3];

struct_WALL_PIE_ list_WALL_PIES_UP_LEFT_BG_B[3];
struct_WALL_PIE_ list_WALL_PIES_UP_RIGHT_BG_B[3];

struct_WALL_PIE_ list_WALL_PIES_UP_LEFT_BG_A[3];
struct_WALL_PIE_ list_WALL_PIES_UP_RIGHT_BG_A[3];

struct_WALL_PIE_ list_WALL_PIES_DOWN_BG_B[3];
struct_WALL_PIE_ list_WALL_PIES_DOWN_BG_A[3];




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                       THE END                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

s16 G_POS_X_CAMERA_CURTAIN_1;
s16 G_POS_X_CAMERA_CURTAIN_2;






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

Sprite *sprite_DEFENDER_1;
Sprite *sprite_DEFENDER_2;
Sprite *sprite_DEFENDER_3;
Sprite *sprite_DEFENDER_4;
Sprite *sprite_OF;
Sprite *sprite_THE;
Sprite *sprite_CROWN;

Sprite *sprite_SH_INTRO_SCREEN_1[14];




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   SCREEN 2                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_RADAR;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   SCREEN 7                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_STOOGES;

Sprite *sprite_BANKER[2];




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    GLOBAL                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_PAUSE;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                     BANK                                    //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_DIALOG;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    DOLLAR                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_DOLLAR_BAG;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   ROULETTE                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_HAND_ROULETTE;

Sprite *sprite_ARROW_HUB;

Sprite *sprite_ICON_BANKER;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                     SLAP                                    //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_HAND_SLAP;

Sprite *sprite_METER_SLAP;

Sprite *sprite_MOE;

Sprite *sprite_LARRY;

Sprite *sprite_CURLY;

Sprite *sprite_COUNTER_SLAP;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    TRIVIA                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_ARROW_DIALOG;

Sprite *sprite_ANSWER_A;

Sprite *sprite_ANSWER_B;

Sprite *sprite_ANSWER_C;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    REWARD                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_DAY;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                QUESTION MARK                                //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_SCISSOR;

Sprite *sprite_ICE_CUBE;

Sprite *sprite_ICE_CUBE_SHADOW;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  CRACKERS                                   //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_HAND[3];

Sprite *sprite_SPLASH;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  WAITERS                                    //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_HAND_WAITERS;

Sprite *sprite_BULB[5];




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  WAITERS                                    //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_CHEST;
Sprite *sprite_ROPE;




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    STREETS                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_STREET[3];




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    THE_END                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

Sprite *sprite_THE_END_1;
Sprite *sprite_THE_END_2;
Sprite *sprite_CINEMAWARE;









