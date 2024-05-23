#ifndef _VARIABLES_H
#define _VARIABLES_H



#include "structures.h"




#define FAILED                      0
#define SUCCESS                     1




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   GAME REEL                                 //
//                                                                             //
//-----------------------------------------------------------------------------// 

#define REEL_INTRO                  0
#define REEL_GAME                   1




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

#define SCENE_FADE_IN                   30
#define SCENE_FADE_OUT                  31




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


#define SCENE_CONTRACT_QUESTION_MARK    27
#define SCENE_CONTRACT_DOCTORS          28
#define SCENE_REWARD                    29


#define SCENE_CONTRACT_WAITERS          30







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
//                                   BANKER                                    //
//                                                                             //
//-----------------------------------------------------------------------------//

#define BANKER_PHASE_WALKIN             0
#define BANKER_PHASE_APPEAR             1




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   TRIVIA                                    //
//                                                                             //
//-----------------------------------------------------------------------------//

#define TRIVIA_PHASE_WALKIN             0
#define TRIVIA_PHASE_TURN_BACK          1
#define TRIVIA_PHASE_ANIM_ANSWERS       2
#define TRIVIA_PHASE_CHOICE             3
#define TRIVIA_PHASE_RESULT             4




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


#define LEFT                            0
#define RIGHT                           1


#define SLAP_STATE_BACK_UP              7
#define SLAP_STATE_UP                   6
#define SLAP_STATE_FRONT_UP             5
#define SLAP_STATE_FRONT                4
#define SLAP_STATE_IDLE                 3
#define SLAP_STATE_FRONT_DOWN           2
#define SLAP_STATE_BACK                 1
#define SLAP_STATE_DOWN                 0




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
#define DOCTORS_PHASE_TIME_OVER         1
#define DOCTORS_PHASE_RACING_OVER       2




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
//#define STREET_TYPE_SLAP              9
#define STREET_TYPE_TRIVIA_1            10
#define STREET_TYPE_TRIVIA_2            11
#define STREET_TYPE_TRIVIA_3            12
#define STREET_TYPE_WAITERS             13





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

#define SOUND_INTRO_SCREEN1             74
#define SOUND_BANKER_LAUGH              80
#define SOUND_HAND                      81
#define SOUND_WALKOUT                   82
#define SOUND_SWATTER                   83
#define SOUND_HEAD_SHOCK                84
#define SOUND_JOY_CRY                   85























extern char text_output[3];
extern u16 palette_64[64];




//**************************************************************************************//
//                                                                                      //
//                                      GENERAL                                         //
//                                                                                      //
//**************************************************************************************//

extern u8 G_REEL;

extern u8 G_SCENE;
extern u8 G_SCENE_TYPE;
extern u8 G_SCENE_NEXT;
extern bool G_SCENE_LOADED;


extern u16 G_ADR_VRAM_BG_B;
extern u16 G_ADR_VRAM_BG_A;


extern u8 G_DAY;
extern u16 G_MONEY;


extern u8 G_STREET_TYPE;
extern u8 G_PHASE_SEQUENCE;


extern u8 G_HIGHSTREET_POSITION;


extern s16 G_POS_Y_CAMERA;


extern bool G_AXIS;




//**************************************************************************************//
//                                                                                      //
//                                       INTRO                                          //
//                                                                                      //
//**************************************************************************************//

extern u16 G_COUNTER_1;
extern u8 G_INDEX_1;
extern u8 G_INDEX_2;
extern u8 G_INDEX_3;

extern u8 G_INDEX_PALETTE_CYCLE;



//**************************************************************************************//
//                                                                                      //
//                                       ROULETTE                                       //
//                                                                                      //
//**************************************************************************************//

extern u16 G_ADR_VRAM_HUB;;

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




//**************************************************************************************//
//                                                                                      //
//                                        REWARD                                        //
//                                                                                      //
//**************************************************************************************//

extern u16 G_REWARD;




//**************************************************************************************//
//                                                                                      //
//                                        TRIVIA                                        //
//                                                                                      //
//**************************************************************************************//

extern u8 G_SELECTED_QUESTION;
extern u8 G_SELECTED_ANSWER;

extern u16 G_ADR_VRAM_DIALOG;
extern u16 G_ADR_VRAM_QUESTION;

extern bool G_STATUS_MISSION;

extern bool G_QUESTION_LOCKED;

extern u8 G_TRIVIA_TYPE;




//**************************************************************************************//
//                                                                                      //
//                                         SLAP                                         //
//                                                                                      //
//**************************************************************************************//

extern s8 G_CURRENT_STATE;
extern s8 G_PREVIOUS_STATE;

extern s16 G_POS_X_METER_SLAP;

extern u8 G_COUNTER_SLAP;




//**************************************************************************************//
//                                                                                      //
//                                   DOCTORS MINIGAME                                   //
//                                                                                      //
//**************************************************************************************//

extern struct_CAR_ list_CARS[3];

extern u8 G_HIT_NUMBER;

extern u8 G_COUNTER_DOCTORS;

extern u8 G_CAR_SPEED;

extern u16 G_INDEX_SPAWN_PATIENT;

extern struct_NURSE_ nurse;

extern struct_PATIENT_ patient;




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

extern Sprite *sprite_DEFENDER;
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
extern Sprite *sprite_ICE_CUBE;
extern Sprite *sprite_ICE_CUBE_SHADOW;







//-----------------------------------------------------------------------------//
//                                                                             //
//                                 QUESTION_MARK                               //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_SCISSOR;








//-----------------------------------------------------------------------------//
//                                                                             //
//                                    STREETS                                  //
//                                                                             //
//-----------------------------------------------------------------------------// 

extern Sprite *sprite_STREET[3];






























#endif // _VARIABLES_H