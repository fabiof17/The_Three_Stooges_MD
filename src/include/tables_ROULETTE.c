#include <genesis.h>



#include "palettes.h"
#include "structures.h"
#include "variables.h"



#include "maps_ROULETTE.h"








const Image     *TABLE_ICONS[10]         =   {
                                                &image_ICON_BANKER,
                                                &image_ICON_BOXING,
                                                &image_ICON_DOCTORS,
                                                &image_ICON_DOLLAR,
                                                &image_ICON_QUESTION,
                                                &image_ICON_SLAP,
                                                &image_ICON_SWATTER,
                                                &image_ICON_TRIVIA,
                                                &image_ICON_WAITERS,
                                                &image_ICON_CRACKERS
                                            };


const u8        TABLE_ICONS_PALETTE_[10]    =   {
                                                    PAL2,
                                                    PAL3,
                                                    PAL2,
                                                    PAL2,
                                                    PAL3,
                                                    PAL3,
                                                    PAL3,
                                                    PAL3,
                                                    PAL2,
                                                    PAL3
                                                };


const u8        TABLE_MINIGAMES[10]     =       {
                                                    SCENE_BANK,
                                                    SCENE_BOXING,
                                                    SCENE_DOCTORS,
                                                    SCENE_DOLLAR,
                                                    SCENE_QUESTION_MARK,
                                                    SCENE_SLAP,
                                                    SCENE_SWATTER,
                                                    SCENE_TRIVIA_SELECT,
                                                    SCENE_WAITERS,
                                                    SCENE_CRACKERS
                                                };


const u8        TABLE_HIGHSTREET[122]   =   {
                                                ICON_DOCTORS,//ICON_BOXING
                                                ICON_SLAP,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_WAITERS,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                // 10
                                                ICON_SLAP,
                                                ICON_DOCTORS,
                                                ICON_SWATTER,
                                                ICON_BANKER,
                                                ICON_WAITERS,
                                                ICON_QUESTION,
                                                ICON_DOLLAR,
                                                ICON_SLAP,
                                                ICON_DOLLAR,
                                                // 20
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_BOXING,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_BANKER,
                                                ICON_DOCTORS,
                                                ICON_SLAP,
                                                // 30
                                                ICON_QUESTION,
                                                ICON_WAITERS,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_DOCTORS,
                                                ICON_DOLLAR,
                                                ICON_SLAP,
                                                // 40
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_BANKER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_DOLLAR,
                                                ICON_BOXING,
                                                ICON_SWATTER,
                                                // 50
                                                ICON_DOCTORS,
                                                ICON_SLAP,
                                                ICON_WAITERS,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_CRACKERS,
                                                // 60
                                                ICON_BANKER,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_SLAP,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_BOXING,
                                                ICON_BANKER,
                                                // 70
                                                ICON_DOCTORS,
                                                ICON_DOLLAR,
                                                ICON_TRIVIA,
                                                ICON_QUESTION,
                                                ICON_CRACKERS,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                // 80
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_WAITERS,
                                                ICON_QUESTION,
                                                ICON_DOLLAR,
                                                ICON_BANKER,
                                                ICON_DOCTORS,
                                                ICON_SWATTER,
                                                // 90
                                                ICON_BOXING,
                                                ICON_DOLLAR,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_SLAP,
                                                ICON_BANKER,
                                                ICON_DOLLAR,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                // 100
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_CRACKERS,
                                                ICON_BANKER,
                                                // GRAB
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_CRACKERS,
                                                // GRAB
                                                ICON_WAITERS,
                                                ICON_TRIVIA,
                                                ICON_SLAP,
                                                ICON_SWATTER,
                                                ICON_BOXING,
                                                ICON_SAFE,
                                                // GRAB
                                                ICON_WAITERS,
                                                ICON_QUESTION,
                                                ICON_BANKER,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_SLAP,
                                                ICON_BANKER,
                                                // GRAB
                                                ICON_SWATTER,
                                                ICON_SLAP,
                                                ICON_BANKER,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER    
                                            };


const u8        TABLE_HAND_MOVE[30][10]     =   {
                                                    {0,4,2,1,2,4,5,3,1,5},
                                                    {0,3,5,2,1,4,3,5,0,4},
                                                    {0,1,3,4,0,2,5,4,0,2},
                                                    {0,2,5,0,3,1,5,2,3,4},
                                                    {0,5,3,5,4,2,1,5,3,1},


                                                    {1,4,2,0,1,3,5,2,4,0},
                                                    {1,3,5,2,5,4,1,4,0,1},
                                                    {1,0,2,4,1,3,0,5,4,0},
                                                    {1,5,4,2,1,3,4,2,5,0},
                                                    {1,4,2,0,4,5,3,4,2,5},


                                                    {2,3,1,4,5,1,4,0,5,2},
                                                    {2,5,4,1,4,0,3,2,1,4},
                                                    {2,1,4,2,4,3,5,0,1,3},
                                                    {2,5,2,4,0,2,1,3,0,2},
                                                    {2,4,1,5,3,1,2,0,3,5},


                                                    {3,2,1,5,4,2,4,0,5,3},
                                                    {3,4,1,2,4,2,1,5,3,0},
                                                    {3,1,3,0,1,2,4,2,1,5},
                                                    {3,5,4,3,1,3,0,2,4,5},
                                                    {3,0,5,4,3,4,0,2,5,1},


                                                    {4,1,2,5,3,5,0,3,0,1},
                                                    {4,3,2,4,5,0,1,3,2,4},
                                                    {4,5,1,5,4,0,2,5,0,3},
                                                    {4,2,0,3,3,1,0,2,5,0},
                                                    {4,0,4,5,2,4,3,1,0,3},


                                                    {5,0,5,1,2,0,2,4,3,4},
                                                    {5,2,1,5,1,3,0,2,4,1},
                                                    {5,0,2,4,1,5,3,2,1,0},
                                                    {5,2,3,0,1,0,4,1,5,3},
                                                    {5,3,0,4,2,4,1,5,3,4}
                                                };


const u8                TABLE_ANIM_STOOGE_ROULETTE[10]  =   {
                                                                17,
                                                                17,
                                                                18,
                                                                17,
                                                                18,
                                                                17,
                                                                18,
                                                                17,
                                                                18,
                                                                17
                                                            };