#include <genesis.h>





#include "palettes.h"
#include "structures.h"
#include "variables.h"




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                      ANIMATIONS                                      //
//                                                                                      //
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                       STOOGES                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const struct_WALK_STOOGES_              TABLE_ANIM_STOOGES_BOXING[26]       =   {
                                                                                    {   33 ,  0 , -87 },
                                                                                    {   39 ,  1 , -79 },
                                                                                    {   44 ,  2 , -73 },
                                                                                    {   50 ,  3 , -65 },
                                                                                    {   55 ,  4 , -57 },
                                                                                    {   60 ,  5 , -49 },
                                                                                    {   66 ,  6 , -40 },
                                                                                    {   69 ,  7 , -31 },
                                                                                    {   75 ,  0 , -23 },
                                                                                    {   81 ,  1 , -17 },
                                                                                    {   86 ,  2 ,  -9 },
                                                                                    {   91 ,  3 ,  -1 },
                                                                                    {   96 ,  4 ,  7  },
                                                                                    {  100 ,  5 ,  17 },
                                                                                    {  105 ,  6 ,  23 },
                                                                                    {  110 ,  7 ,  32 },
                                                                                    {  115 ,  0 ,  41 },
                                                                                    {  120 ,  1 ,  49 },
                                                                                    {  124 ,  2 ,  55 },
                                                                                    {  129 ,  3 ,  63 },
                                                                                    {  134 ,  4 ,  71 },
                                                                                    {  141 ,  5 ,  81 },
                                                                                    {  147 , 10 ,  88 },
                                                                                    {  153 , 11 ,  95 },
                                                                                    {  162 , 12 ,  95 },
                                                                                    {  168 , 16 , 114 }
                                                                                };


const Palette           *TABLE_BOXING_CYCLE[5]      =   {
                                                            &palette_BOXING_SCREEN_2_1,
                                                            &palette_BOXING_SCREEN_2_2,
                                                            &palette_BOXING_SCREEN_2_3,
                                                            &palette_BOXING_SCREEN_2_4,
                                                            &palette_BOXING_SCREEN_2_0
                                                        };


const u8                TABLE_BOXERS[12]             =   {
                                                            0,
                                                            1,
                                                            2,
                                                            3,
                                                            4,
                                                            5,
                                                            0,
                                                            1,
                                                            5,
                                                            6,
                                                            7,
                                                            8
                                                        };




struct_OBSTACLE_TYPE    TABLES_OBSTACLES[MAX_OBSTACLES]     =   {
                                                                    { ROW_BG , TYPE_TRASH         ,  464 , 144 ,    32 , 40 , 1 },//TRASH
                                                                    { ROW_FG , TYPE_HYDRANT       ,  720 , 168 ,    24 , 24 , 0 },//HYDRANT
                                                                    { ROW_FG , TYPE_POST          ,  920 , 104 ,    16 , 88 , 0 },//POST
                                                                    { ROW_BG , TYPE_DOG           , 1096 , 160 ,    48 , 24 , 0 },//DOG
                                                                    { ROW_FG , TYPE_LETTERS_SMALL , 1232 , 168 ,    32 , 24 , 0 },//LETTERS SMALL
                                                                    { ROW_BG , TYPE_DOOR          , 1416 , 104 ,    24 , 72 , 0 },//DOOR
                                                                    { ROW_FG , TYPE_LETTERS_BIG   , 1616 , 136 ,    56 , 56 , 0 },//LETTERS BIG
                                                                    { ROW_FG , TYPE_LADDER        , 1818 , 104 ,    32 , 88 , 0 },//LADDER
                                                                    { ROW_FG , TYPE_HYDRANT       , 2064 , 168 ,    24 , 24 , 0 },//HYDRANT
                                                                    { ROW_BG , TYPE_DOOR          , 2248 , 104 ,    24 , 72 , 0 },//DOOR
                                                                    { ROW_FG , TYPE_LETTERS_SMALL , 2320 , 168 ,    32 , 24 , 0 },//LETTERS SMALL
                                                                    { ROW_BG , TYPE_LETTERS_BIG   , 2384 , 128 ,    56 , 56 , 0 },//LETTERS BIG
                                                                    { ROW_FG , TYPE_BOX           , 2440 , 168 ,    40 , 24 , 0 },//BOX
                                                                    { ROW_FG , TYPE_LAMP          , 2576 , 104 ,    32 , 88 , 0 },//LAMP
                                                                    { ROW_BG , TYPE_DOG           , 2696 , 160 ,    48 , 24 , 0 },//DOG
                                                                    { ROW_FG , TYPE_POST          , 2920 , 104 ,    16 , 88 , 0 },//POST
                                                                    { ROW_BG , TYPE_DOOR          , 3408 , 104 ,    24 , 72 , 0 },//DOOR
                                                                    { ROW_FG , TYPE_HYDRANT       , 3472 , 168 ,    24 , 24 , 0 },//HYDRANT
                                                                    { ROW_BG , TYPE_LETTERS_BIG   , 3600 , 128 ,    56 , 56 , 0 },//LETTERS BIG
                                                                    { ROW_FG , TYPE_TRASH         , 3672 , 152 ,    32 , 40 , 0 },//TRASH
                                                                    { ROW_BG , TYPE_TRASH         , 3792 , 144 ,    32 , 40 , 1 },//TRASH
                                                                    { ROW_FG , TYPE_BOX           , 3856 , 168 ,    40 , 24 , 0 },//BOX
                                                                    { ROW_BG , TYPE_LETTERS_SMALL , 3992 , 160 ,    32 , 24 , 0 },//LETTERS SMALL
                                                                    { ROW_FG , TYPE_LETTERS_SMALL , 4056 , 168 ,    32 , 24 , 0 },//LETTERS SMALL
                                                                    { ROW_BG , TYPE_DOG           , 4168 , 160 ,    48 , 24 , 0 },//DOG
                                                                    { ROW_FG , TYPE_LAMP          , 4240 , 104 ,    32 , 88 , 0 },//LAMP
                                                                    { ROW_FG , TYPE_LADDER        , 4632 , 104 ,    32 , 88 , 0 },//LADDER
                                                                    { ROW_BG , TYPE_LETTERS_SMALL , 4696 , 160 ,    32 , 24 , 0 },//LETTERS SMALL
                                                                    { ROW_FG , TYPE_POST          , 4824 , 104 ,    16 , 88 , 0 },//POST
                                                                    { ROW_BG , TYPE_BOX           , 4864 , 160 ,    40 , 24 , 0 },//BOX
                                                                    { ROW_FG , TYPE_LAMP          , 5008 , 104 ,    32 , 88 , 0 },//LAMP
                                                                    { ROW_BG , TYPE_TRASH         , 5072 , 144 ,    32 , 40 , 1 },//TRASH
                                                                    { ROW_BG , TYPE_LETTERS_BIG   , 5200 , 128 ,    56 , 56 , 0 },//LETTERS BIG
                                                                    { ROW_FG , TYPE_HYDRANT       , 5272 , 168 ,    24 , 24 , 0 },//HYDRANT
                                                                    { ROW_BG , TYPE_DOOR          , 5328 , 104 ,    24 , 72 , 0 },//DOOR
                                                                    { ROW_FG , TYPE_POST          , 5472 , 104 ,    16 , 88 , 0 },//POST
                                                                    { ROW_BG , TYPE_TRASH         , 5528 , 144 ,    32 , 40 , 1 },//TRASH
                                                                    { ROW_FG , TYPE_LADDER        , 5592 , 104 ,    32 , 88 , 0 },//LADDER
                                                                    { ROW_BG , TYPE_LETTERS_BIG   , 5712 , 128 ,    56 , 56 , 0 },//LETTERS BIG
                                                                    { ROW_BG , TYPE_LETTERS_BIG   , 5776 , 128 ,    56 , 56 , 0 },//LETTERS BIG
                                                                    { ROW_FG , TYPE_HYDRANT       , 5848 , 168 ,    24 , 24 , 0 },//HYDRANT
                                                                    { ROW_BG , TYPE_BOX           , 5960 , 160 ,    40 , 24 , 0 },//BOX
                                                                    { ROW_BG , TYPE_DOOR          , 6096 , 104 ,    24 , 72 , 0 } //DOOR
                                                                };