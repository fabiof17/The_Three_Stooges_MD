#include <genesis.h>



#include "palettes.h"
#include "structures.h"
#include "variables.h"



#include "maps_ROULETTE.h"








const Image     *TABLE_ICONS[11]         =   {
                                                &image_ICON_BANKER,
                                                &image_ICON_BOXING,
                                                &image_ICON_DOCTORS,
                                                &image_ICON_DOLLAR,
                                                &image_ICON_QUESTION,
                                                &image_ICON_SLAP,
                                                &image_ICON_SWATTER,
                                                &image_ICON_TRIVIA,
                                                &image_ICON_WAITERS,
                                                &image_ICON_CRACKERS,
                                                &image_ICON_SAFE
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


const u8        TABLE_HIGHSTREET[180]   =   {
                                                // DAY 1
                                                ICON_BOXING,
                                                ICON_SLAP,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_WAITERS,
                                                ICON_DOLLAR,

                                                // DAY 2
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_SLAP,
                                                ICON_DOCTORS,

                                                // DAY 3
                                                ICON_SWATTER,
                                                ICON_BANKER,
                                                ICON_WAITERS,
                                                ICON_QUESTION,
                                                ICON_DOLLAR,
                                                ICON_SLAP,

                                                // DAY 4
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_BOXING,

                                                // DAY 5
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_BANKER,
                                                ICON_DOCTORS,
                                                ICON_SLAP,
                                                ICON_QUESTION,

                                                // DAY 6
                                                ICON_WAITERS,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_DOCTORS,

                                                // DAY 7
                                                ICON_DOLLAR,
                                                ICON_SLAP,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_BANKER,
                                                ICON_TRIVIA,

                                                // DAY 8
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_DOLLAR,
                                                ICON_BOXING,
                                                ICON_SWATTER,
                                                ICON_DOCTORS,

                                                // DAY 9
                                                ICON_SLAP,
                                                ICON_WAITERS,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,

                                                // DAY 10
                                                ICON_SWATTER,
                                                ICON_CRACKERS,
                                                ICON_BANKER,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_SLAP,

                                                // DAY 11
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_BOXING,
                                                ICON_BANKER,
                                                ICON_DOCTORS,

                                                // DAY 12
                                                ICON_DOLLAR,
                                                ICON_TRIVIA,
                                                ICON_QUESTION,
                                                ICON_CRACKERS,
                                                ICON_SWATTER,
                                                ICON_QUESTION,

                                                // DAY 13
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_WAITERS,

                                                // DAY 14
                                                ICON_QUESTION,
                                                ICON_DOLLAR,
                                                ICON_BANKER,
                                                ICON_DOCTORS,
                                                ICON_SWATTER,
                                                ICON_BOXING,

                                                // DAY 15
                                                ICON_DOLLAR,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_SLAP,
                                                ICON_BANKER,
                                                ICON_DOLLAR,

                                                // DAY 16
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_CRACKERS,

                                                // DAY 17
                                                ICON_BANKER,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_DOCTORS,

                                                // DAY 18
                                                ICON_WAITERS,
                                                ICON_TRIVIA,
                                                ICON_SLAP,
                                                ICON_SWATTER,
                                                ICON_BOXING,
                                                ICON_SAFE,

                                                // DAY 19
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_CRACKERS,

                                                // DAY 20
                                                ICON_WAITERS,
                                                ICON_QUESTION,
                                                ICON_BANKER,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_SLAP,

                                                // DAY 21
                                                ICON_BANKER,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_CRACKERS,

                                                // DAY 22
                                                ICON_BOXING,
                                                ICON_DOLLAR,
                                                ICON_SLAP,
                                                ICON_SWATTER,
                                                ICON_SWATTER,
                                                ICON_TRIVIA,
                                                
                                                // DAY 23
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_DOCTORS,
                                                ICON_SWATTER,
                                                ICON_BANKER,
                                                ICON_WAITERS,

                                                // DAY 24
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_QUESTION,

                                                // DAY 25
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_QUESTION,

                                                // DAY 26
                                                ICON_TRIVIA,
                                                ICON_BOXING,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_CRACKERS,
                                                ICON_SAFE,

                                                // DAY 27
                                                ICON_SLAP,
                                                ICON_QUESTION,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,
                                                ICON_SWATTER,
                                                ICON_DOCTORS,

                                                // DAY 28
                                                ICON_SWATTER,
                                                ICON_BANKER,
                                                ICON_BOXING,
                                                ICON_BANKER,
                                                ICON_BOXING,
                                                ICON_QUESTION,

                                                // DAY 29
                                                ICON_TRIVIA,
                                                ICON_SLAP,
                                                ICON_SWATTER,
                                                ICON_WAITERS,
                                                ICON_SWATTER,
                                                ICON_DOLLAR,

                                                // DAY 30
                                                ICON_QUESTION,
                                                ICON_TRIVIA,
                                                ICON_SWATTER,
                                                ICON_DOCTORS,
                                                ICON_SWATTER,
                                                ICON_QUESTION,
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