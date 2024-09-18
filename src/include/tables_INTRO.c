#include <genesis.h>



#include "palettes.h"
#include "structures.h"
#include "variables.h"



#include "maps_INTRO.h"


#include "sprites_GLOBAL.h"
#include "sprites_INTRO.h"




//**************************************************************************************//
//                                                                                      //
//                                       SCREEN 1                                       //
//                                                                                      //
//**************************************************************************************// 

const Palette           *TABLE_SCREEN_1_CYCLE[8]        =   {
                                                                &palette_INTRO_SCREEN_1_0,
                                                                &palette_INTRO_SCREEN_1_1,
                                                                &palette_INTRO_SCREEN_1_2,
                                                                &palette_INTRO_SCREEN_1_3,
                                                                &palette_INTRO_SCREEN_1_4,
                                                                &palette_INTRO_SCREEN_1_5,
                                                                &palette_INTRO_SCREEN_1_6,
                                                                &palette_INTRO_SCREEN_1_7
                                                            };














//**************************************************************************************//
//                                                                                      //
//                                       SCREEN 5                                       //
//                                                                                      //
//**************************************************************************************// 

//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                        TABLES                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const u8                        TABLE_BANKER_WALK[8]                    =   {
                                                                                11,
                                                                                3,
                                                                                3,
                                                                                7,
                                                                                8,
                                                                                4,
                                                                                2,
                                                                                6
                                                                            };


const s16                        TABLE_STOOGES_WALK[17]                 =   {
                                                                                9,
                                                                                8,
                                                                                6,
                                                                                8,
                                                                                8,
                                                                                10,
                                                                                6,
                                                                                9,
                                                                                9,
                                                                                8,
                                                                                9,
                                                                                7,
                                                                                8,
                                                                                13,
                                                                                0,
                                                                                -6,
                                                                                6
                                                                            };








//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                      ANIMATIONS                                      //
//                                                                                      //
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                       SCREEN 1                                       //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const struct_WALK_STOOGES_      TABLE_ANIM_STOOGES_SCREEN_1[29]             =   {
                                                                                    {  400 ,  1 , -87 },
                                                                                    {  408 ,  2 , -81 },
                                                                                    {  418 ,  3 , -73 },
                                                                                    {  425 ,  4 , -65 },
                                                                                    {  435 ,  5 , -55 },
                                                                                    {  442 ,  6 , -49 },
                                                                                    {  450 ,  7 , -40 },
                                                                                    {  460 ,  0 , -31 },
                                                                                    {  467 ,  1 , -23 },
                                                                                    {  477 ,  2 , -17 },
                                                                                    {  484 ,  3 , -9  },
                                                                                    {  491 ,  4 , -1  },
                                                                                    {  501 ,  5 ,  9  },
                                                                                    {  508 ,  6 , 15  },
                                                                                    {  515 ,  7 , 24  },
                                                                                    {  522 ,  0 , 33  },
                                                                                    {  532 ,  1 , 41  },
                                                                                    {  538 ,  2 , 47  },
                                                                                    {  546 ,  3 , 55  },
                                                                                    {  555 ,  4 , 63  },
                                                                                    {  562 ,  5 , 73  },
                                                                                    {  570 ,  6 , 79  },
                                                                                    {  579 , 10 , 88  },
                                                                                    {  586 , 11 , 95  },
                                                                                    {  592 , 12 , 95  },
                                                                                    {  599 , 13 , 116 },
                                                                                    {  605 , 14 , 116 },
                                                                                    { 1048 , 15 , 110 },
                                                                                    { 1063 , 14 , 116 }
                                                                                };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                       SCREEN 3                                       //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const struct_WALK_STOOGES_              TABLE_ANIM_STOOGES_SCREEN_3[26]     =   {
                                                                                    {    5 ,  3  , 119 },
                                                                                    {   12 ,  4  , 127 },
                                                                                    {   18 ,  5  , 137 },
                                                                                    {   26 ,  6  , 143 },
                                                                                    {   32 ,  7  , 152 },
                                                                                    {   39 ,  0  , 161 },
                                                                                    {   45 ,  1  , 169 },
                                                                                    {   52 ,  2  , 175 },
                                                                                    {   58 ,  3  , 183 },
                                                                                    {   65 ,  4  , 191 },
                                                                                    {   71 ,  5  , 201 },
                                                                                    {   78 ,  6  , 207 },
                                                                                    {   87 ,  7  , 216 },
                                                                                    {   93 ,  0  , 225 },
                                                                                    {  100 ,  1  , 233 },
                                                                                    {  107 ,  2  , 239 },
                                                                                    {  114 ,  3  , 247 },
                                                                                    {  122 ,  4  , 255 },
                                                                                    {  129 ,  5  , 265 },
                                                                                    {  136 ,  6  , 271 },
                                                                                    {  143 ,  7  , 280 },
                                                                                    {  150 ,  0  , 289 },
                                                                                    {  159 ,  1  , 297 },
                                                                                    {  164 ,  2  , 303 },
                                                                                    {  172 ,  3  , 311 },
                                                                                    {  180 ,  4  , 320 }
                                                                                };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                     SCREENS 4-5-6                                    //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const struct_WALK_STOOGES_              TABLE_ANIM_STOOGES_SCREEN_4[52]     =   {
                                                                                    {    5 ,  0 , -87 },
                                                                                    {   13 ,  1 , -79 },
                                                                                    {   21 ,  2 , -73 },
                                                                                    {   30 ,  3 , -65 },
                                                                                    {   38 ,  4 , -57 },
                                                                                    {   47 ,  5 , -49 },
                                                                                    {   55 ,  6 , -40 },
                                                                                    {   63 ,  7 , -31 },
                                                                                    {   72 ,  0 , -23 },
                                                                                    {   81 ,  1 , -17 },
                                                                                    {   89 ,  2 ,  -9 },
                                                                                    {   97 ,  3 ,  -1 },
                                                                                    {  105 ,  4 ,  7  },
                                                                                    {  114 ,  5 ,  17 },
                                                                                    {  122 ,  6 ,  23 },
                                                                                    {  131 ,  7 ,  32 },

                                                                                    {  140 ,  0 ,  40 },
                                                                                    {  149 ,  1 ,  46 },
                                                                                    {  157 ,  2 ,  54 },
                                                                                    {  165 ,  3 ,  62 },
                                                                                    {  172 ,  4 ,  70 },
                                                                                    {  181 ,  5 ,  80 },
                                                                                    {  189 ,  6 ,  86 },
                                                                                    {  198 ,  7 ,  95 },
                                                                                    
                                                                                    {  207 ,  0 , 103 },
                                                                                    {  216 ,  1 , 109 },
                                                                                    {  224 ,  2 , 117 },
                                                                                    {  232 ,  3 , 125 },
                                                                                    {  239 ,  4 , 133 },
                                                                                    {  248 ,  5 , 143 },
                                                                                    {  256 ,  6 , 149 },
                                                                                    {  265 ,  7 , 158 },

                                                                                    {  274 ,  0 , 166 },
                                                                                    {  283 ,  1 , 172 },
                                                                                    {  291 ,  2 , 180 },
                                                                                    {  299 ,  3 , 188 },
                                                                                    {  306 ,  4 , 196 },
                                                                                    {  315 ,  5 , 206 },
                                                                                    {  323 ,  6 , 212 },
                                                                                    {  332 ,  7 , 221 },

                                                                                    {  341 ,  0 , 229 },
                                                                                    {  350 ,  1 , 235 },
                                                                                    {  358 ,  2 , 243 },
                                                                                    {  366 ,  3 , 251 },
                                                                                    {  373 ,  4 , 259 },
                                                                                    {  382 ,  5 , 269 },
                                                                                    {  390 ,  6 , 275 },
                                                                                    {  399 ,  7 , 284 },

                                                                                    {  408 ,  0 , 292 },
                                                                                    {  417 ,  1 , 298 },
                                                                                    {  425 ,  2 , 306 },
                                                                                    {  433 ,  3 , 314 }
                                                                                };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                       SCREEN 7                                       //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const struct_ANIM_GRANDMA_      TABLE_ANIM_GRANDMA_SCREEN_7_1[20]       =   {
                                                                                {   0 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                {   9 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                {  24 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                {  29 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                {  38 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                {  53 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                {  57 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                {  67 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                {  77 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                {  81 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                {  91 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 105 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 120 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 125 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 134 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 144 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 149 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 159 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 163 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 177 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 }
                                                                            };


const struct_ANIM_GRANDMA_      TABLE_ANIM_GRANDMA_SCREEN_7_2[13]       =   {
                                                                                { 215 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 229 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 237 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 245 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 261 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 323 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 339 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 346 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 354 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 363 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 371 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 387 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 402 , &image_GRANDMA_INTRO_BG_B_STEP0 , &image_GRANDMA_INTRO_BG_A_STEP0 }
                                                                            };


const struct_WALK_STOOGES_      TABLE_ANIM_STOOGES_SCREEN_7_2[21]       =   {
                                                                                    {  237 ,  1 , -87 },
                                                                                    {  245 ,  2 , -81 },
                                                                                    {  252 ,  3 , -73 },
                                                                                    {  261 ,  4 , -65 },
                                                                                    {  267 ,  5 , -55 },
                                                                                    {  276 ,  6 , -49 },
                                                                                    {  283 ,  7 , -40 },
                                                                                    {  292 ,  0 , -31 },
                                                                                    {  300 ,  1 , -23 },
                                                                                    {  307 ,  2 , -17 },
                                                                                    {  315 ,  3 , -9  },
                                                                                    {  323 ,  4 , -1  },
                                                                                    {  331 ,  5 ,  9  },
                                                                                    {  339 ,  6 , 15  },
                                                                                    {  346 , 10 , 24  },
                                                                                    {  354 , 11 , 31  },
                                                                                    {  363 , 12 , 31  },
                                                                                    {  371 , 13 , 52  },
                                                                                    {  379 , 14 , 52  },
                                                                                    {  387 , 15 , 46  },
                                                                                    {  394 , 16 , 50  }
                                                                            };




const struct_ANIM_GRANDMA_      TABLE_ANIM_GRANDMA_SCREEN_7_3[33]       =   {
                                                                                {    0 , &image_GRANDMA_INTRO_BG_B_STEP0 , &image_GRANDMA_INTRO_BG_A_STEP0 },
                                                                                { 1873 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 1882 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 1889 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 1897 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 1912 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 1919 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 1935 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 1942 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 1949 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 1956 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 1963 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 1971 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 1978 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 1986 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 1993 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2001 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 2008 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2017 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 2023 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2040 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 2047 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2055 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 2063 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2070 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 2079 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2107 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 2116 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2137 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 2152 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2159 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 },
                                                                                { 2173 , &image_GRANDMA_INTRO_BG_B_STEP1 , &image_GRANDMA_INTRO_BG_A_STEP1 },
                                                                                { 2181 , &image_GRANDMA_INTRO_BG_B_STEP2 , &image_GRANDMA_INTRO_BG_A_STEP2 }   
                                                                            };


const struct_WALK_STOOGES_      TABLE_ANIM_STOOGES_SCREEN_7_3[35]       =   {
                                                                                { 1867 ,  2 ,  47 },
                                                                                { 1873 ,  3 ,  55 },
                                                                                { 1882 ,  4 ,  63 },
                                                                                { 1889 ,  5 ,  73 },
                                                                                { 1897 ,  6 ,  79 },
                                                                                { 1905 ,  7 ,  88 },
                                                                                { 1912 ,  0 ,  97 },
                                                                                { 1919 ,  1 , 105 },
                                                                                { 1926 ,  2 , 111 },
                                                                                { 1935 ,  3 , 119 },
                                                                                { 1942 ,  4 , 127 },
                                                                                { 1949 ,  5 , 137 },
                                                                                { 1956 ,  6 , 143 },
                                                                                { 1963 ,  7 , 152 },
                                                                                { 1971 ,  0 , 161 },
                                                                                { 1978 ,  1 , 169 },
                                                                                { 1986 ,  2 , 175 },
                                                                                { 1993 ,  3 , 183 },
                                                                                { 2001 ,  4 , 191 },
                                                                                { 2008 ,  5 , 201 },
                                                                                { 2017 ,  6 , 207 },
                                                                                { 2023 ,  7 , 216 },
                                                                                { 2032 ,  0 , 225 },
                                                                                { 2040 ,  1 , 233 },
                                                                                { 2047 ,  2 , 239 },
                                                                                { 2055 ,  3 , 247 },
                                                                                { 2063 ,  4 , 255 },
                                                                                { 2070 ,  5 , 265 },
                                                                                { 2079 ,  6 , 271 },
                                                                                { 2086 ,  7 , 280 },
                                                                                { 2094 ,  0 , 289 },
                                                                                { 2101 ,  1 , 297 },
                                                                                { 2107 ,  2 , 303 },
                                                                                { 2116 ,  3 , 311 },
                                                                                { 2123 ,  4 , 320 }
                                                                            };








// SCREEN 1 ANIMATION //

void anim_INTRO_SCREEN_1()
{
    // PALETTE CYCLING //
    if (G_COUNTER_1%10 == TRUE)
    {
        G_INDEX_PALETTE_CYCLE += 1;

        if(G_INDEX_PALETTE_CYCLE > 7)
        {
            G_INDEX_PALETTE_CYCLE = 0;
        }

        PAL_setPalette( PAL0 , TABLE_SCREEN_1_CYCLE[G_INDEX_PALETTE_CYCLE]->data , DMA);
    }


    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_SCREEN_1[G_INDEX_3];

    if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
    {
        // CHANGING SPRITE ANIMATION FRAME //
        SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

        // RETRIEVE X POSITION FROM TABLE //
        SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 154 );


        // UPDATE INDEX IN STOOGES ANIMATION TABLE //
        // UP TO 28 (LAST INDEX IN ARRAY OF 29 ENTRIES) //
        if(G_INDEX_3 < 28)
        {
            G_INDEX_3 += 1;
        }
    }


    // PLAY VOICE PCM //
    if(G_COUNTER_1 == 720) // 870 : SHORT
    {
        XGM_stopPlay();
        
        XGM_startPlayPCM(SOUND_INTRO_SCREEN1,15,SOUND_PCM_CH4);
    }


    // FADE OUT //
    else if(G_COUNTER_1 == 1067)
    {
        // COUNTERS RESET //
        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;

        G_INDEX_PALETTE_CYCLE   = 0;
        
        // GO TO FADE OUT SEQUENCE //
        G_SCENE     = SCENE_FADE_OUT;

        return;
    }


    G_COUNTER_1 += 1;
}




// SCREEN 2 ANIMATION //

void anim_INTRO_SCREEN_2()
{
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                            RADAR AND SCRATCHES ANIMATION                             //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    if(G_INDEX_1 == 0)
    {
        SPR_setFrame(sprite_RADAR,0);
        SPR_setPosition(sprite_RADAR,160,16);
    }

    else if(G_INDEX_1 == 4)
    {
        SPR_setFrame(sprite_RADAR,1);
    }

    else if(G_INDEX_1 == 9)
    {
        SPR_setFrame(sprite_RADAR,2);
    }

    else if(G_INDEX_1 == 15)
    {
        SPR_setFrame(sprite_RADAR,3);
        SPR_setPosition(sprite_RADAR,160,112);
    }

    else if(G_INDEX_1 == 18)
    {
        SPR_setFrame(sprite_RADAR,4);
    }

    else if(G_INDEX_1 == 24)
    {
        SPR_setFrame(sprite_RADAR,5);
    }

    else if(G_INDEX_1 == 28)
    {
        SPR_setHFlip(sprite_RADAR,TRUE);
        SPR_setPosition(sprite_RADAR,0,112);
    }

    else if(G_INDEX_1 == 34)
    {
        SPR_setFrame(sprite_RADAR,4);
    }

    else if(G_INDEX_1 == 39)
    {
        SPR_setFrame(sprite_RADAR,3);
    }

    else if(G_INDEX_1 == 44)
    {
        SPR_setFrame(sprite_RADAR,2);
        SPR_setPosition(sprite_RADAR,0,16);
    }

    else if(G_INDEX_1 == 48)
    {
        SPR_setFrame(sprite_RADAR,1);
    }

    else if(G_INDEX_1 == 54)
    {
        SPR_setFrame(sprite_RADAR,0);
    }

    else if(G_INDEX_1 == 59)
    {
        SPR_setFrame(sprite_RADAR,6);
        SPR_setPosition(sprite_RADAR,158,16);
        SPR_setHFlip(sprite_RADAR,FALSE);
    }

    else if(G_INDEX_1 == 64)
    {
        G_INDEX_1 = 0;
    }


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                  NUMBERS ANIMATION                                   //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    // DISPLAY NUMBER 4 //
    if(G_COUNTER_1 == 64)
    {
        VDP_loadTileSet(image_INTRO_SCREEN_2_BG_A2.tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_2_BG_A.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_2_BG_A2.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_2_BG_A.tileset->numTile), 12, 5, 0, 0, 17, 18, DMA_QUEUE);
    }
    
    // DISPLAY NUMBER 3 //
    else if(G_COUNTER_1 == 130)
    {
        VDP_loadTileSet(image_INTRO_SCREEN_2_BG_A3.tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_2_BG_A.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_2_BG_A3.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_2_BG_A.tileset->numTile), 12, 5, 0, 0, 17, 18, DMA_QUEUE);
    }    
    



    else if(G_COUNTER_1 == 194)
    {
        // COUNTERS RESET //
        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;
        
        // GO TO FADE OUT SEQUENCE //
        G_SCENE     = SCENE_FADE_OUT;

        return;
    }


    G_INDEX_1 += 1;

    G_COUNTER_1 += 1;
}




// SCREEN 3 ANIMATION //

void anim_INTRO_SCREEN_3_0()
{
    if(G_COUNTER_1 == 76)
    {
        VDP_setHorizontalScrollVSync(BG_A , -182);
    }

    else if(G_COUNTER_1 == 201)
    {
        VDP_setHorizontalScrollVSync(BG_A , 0);
        
        SPR_setFrame(sprite_STOOGES,0);

        // REINIT COUNTER //
        G_COUNTER_1   = 0;

        // NEXT ANIMATION //
        G_INDEX_1     = 1;

        // SKIP COUNTER INCREMENT //
        return;
    }

    G_COUNTER_1 += 1;
}


void anim_INTRO_SCREEN_3_1()
{
    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_SCREEN_3[G_INDEX_3];

    if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
    {
        // CHANGING SPRITE ANIMATION FRAME //
        SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

        // RETRIEVE X POSITION FROM TABLE //
        SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 154 );


        // UPDATE INDEX IN STOOGES ANIMATION TABLE //
        // UP TO 25 (LAST INDEX IN ARRAY OF 26 ENTRIES) //
        if(G_INDEX_3 < 25)
        {
            G_INDEX_3 += 1;
        }
    }


    if(G_COUNTER_1 == 1147)
    {
        // COUNTERS RESET //
        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;
        
        // GO TO FADE OUT SEQUENCE //
        G_SCENE     = SCENE_FADE_OUT;

        return;
    }


    G_COUNTER_1 += 1;
}




void (*TABLE_ANIM_INTRO_3[2])(void)         =       {
                                                        anim_INTRO_SCREEN_3_0,
                                                        anim_INTRO_SCREEN_3_1
                                                    };




// SCREENS 4-5-6 ANIMATION //

void anim_INTRO_SCREEN_4_5_6()
{
    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_SCREEN_4[G_INDEX_3];

    if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
    {
        // CHANGING SPRITE ANIMATION FRAME //
        SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

        // RETRIEVE X POSITION FROM TABLE //
        SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 142 );


        // UPDATE INDEX IN STOOGES ANIMATION TABLE //
        // UP TO 51 (LAST INDEX IN ARRAY OF 52 ENTRIES) //
        if(G_INDEX_3 < 51)
        {
            G_INDEX_3 += 1;
        }
    }


    if(G_COUNTER_1 == 440)
    {
        // COUNTERS RESET //
        G_COUNTER_1             = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;
        
        // GO TO FADE OUT SEQUENCE //
        G_SCENE     = SCENE_FADE_OUT;

        return;
    }

    G_COUNTER_1 += 1;
}




// SCREEN 7 ANIMATION //

void anim_INTRO_SCREEN_7_0()
{
    if(G_COUNTER_1 == 28)
    {
        SPR_setFrame( sprite_BANKER[0] , 1 );
        SPR_setFrame( sprite_BANKER[1] , 1 );
    }
    
    else if(G_COUNTER_1 == 61)
    {
        SPR_setFrame( sprite_BANKER[0] , 0 );
        SPR_setFrame( sprite_BANKER[1] , 0 );
    }

    else if(G_COUNTER_1 == 70)
    {
        SPR_setFrame( sprite_BANKER[0] , 1 );
        SPR_setFrame( sprite_BANKER[1] , 1 );
    }

    else if(G_COUNTER_1 == 77)
    {
        SPR_setFrame( sprite_BANKER[0] , 0 );
        SPR_setFrame( sprite_BANKER[1] , 0 );
    }    
    
    else if(G_COUNTER_1 == 94)
    {
        SPR_setFrame( sprite_BANKER[0] , 1 );
        SPR_setFrame( sprite_BANKER[1] , 1 );
    }    

    else if(G_COUNTER_1 == 112)
    {
        SPR_setFrame( sprite_BANKER[0] , 0 );
        SPR_setFrame( sprite_BANKER[1] , 0 );
    }  

    else if(G_COUNTER_1 == 129)
    {
        SPR_setFrame( sprite_BANKER[0] , 1 );
        SPR_setFrame( sprite_BANKER[1] , 1 );
    }   

    else if(G_COUNTER_1 == 171)
    {
        SPR_setFrame( sprite_BANKER[0] , 0 );
        SPR_setFrame( sprite_BANKER[1] , 0 );
    } 

    else if(G_COUNTER_1 == 197)
    {
        SPR_setFrame( sprite_BANKER[0] , 2 );
        SPR_setFrame( sprite_BANKER[1] , 2 );
    }


    // TRIGGER EVIL LAUGH // 
    else if(G_COUNTER_1 == 345)
    {
        XGM_startPlayPCM(SOUND_BANKER_LAUGH,15,SOUND_PCM_CH4);
    }


    // GO TO NEXT ANIMATION //
    else if(G_COUNTER_1 == 465)
    {
        // REINIT COUNTER //
        G_COUNTER_1   = 0;

        // NEXT ANIMATION //
        G_INDEX_1     = 1;

        // SKIP COUNTER INCREMENT //
        return;
    } 


    G_COUNTER_1 += 1;
}


void anim_INTRO_SCREEN_7_1()
{
    // BANKER ANIMATION //
    if(G_COUNTER_1%5 == TRUE)
    {    
        s16 pos_X_SPRITE = SPR_getPositionX(sprite_BANKER[0]);

        SPR_setPosition( sprite_BANKER[0] , pos_X_SPRITE + TABLE_BANKER_WALK[G_INDEX_2] , 132 );
        SPR_setPosition( sprite_BANKER[1] , pos_X_SPRITE + TABLE_BANKER_WALK[G_INDEX_2] , 132 );

        SPR_setAnimAndFrame( sprite_BANKER[0] , 1 , G_INDEX_2 );
        SPR_setAnimAndFrame( sprite_BANKER[1] , 1 , G_INDEX_2 );


        G_INDEX_2 += 1;

        if(G_INDEX_2 == 8)
        {
            G_INDEX_2 = 0;
        }
    }


    // GRANDMA ANIMATION //
    // SETUP POINTER TO GRANDMA ANIMATION TABLE //
    const struct_ANIM_GRANDMA_ *ptr_ANIM_GRANDMA = &TABLE_ANIM_GRANDMA_SCREEN_7_1[G_INDEX_3];

    if(G_COUNTER_1 == ptr_ANIM_GRANDMA->num_FRAME)
    {
        VDP_loadTileSet(ptr_ANIM_GRANDMA->ptr_IMAGE_GRANDMA_BG_B->tileset, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile, DMA);
        VDP_loadTileSet(ptr_ANIM_GRANDMA->ptr_IMAGE_GRANDMA_BG_A->tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile, DMA);

        // UPDATE INDEX IN GRANDMA ANIMATION TABLE //
        // UP TO 18 (LAST INDEX IN ARRAY) //
        if(G_INDEX_3 < 19)
        {
            G_INDEX_3 += 1;
        }
    }


    // GO TO NEXT ANIMATION //
    else if(G_COUNTER_1 == 193)
    {
        // RELEASE BANKER SPRITES //
        SPR_releaseSprite(sprite_BANKER[0]);
        SPR_releaseSprite(sprite_BANKER[1]);

        sprite_BANKER[0]    = NULL;
        sprite_BANKER[1]    = NULL;

        sprite_STOOGES = SPR_addSprite(&tiles_SPR_STOOGES_WALK,  -95, 142, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
        
        // REINIT COUNTER //
        G_COUNTER_1   = 0;

        // NEXT ANIMATION //
        G_INDEX_1       = 2;
        G_INDEX_2       = 0;
        G_INDEX_3       = 0;

        // SKIP COUNTER INCREMENT //
        return;
    }


    G_COUNTER_1 += 1;
}


void anim_INTRO_SCREEN_7_2()
{
    // GRANDMA ANIMATION //
    // SETUP POINTER TO GRANDMA ANIMATION TABLE //
    const struct_ANIM_GRANDMA_ *ptr_ANIM_GRANDMA = &TABLE_ANIM_GRANDMA_SCREEN_7_2[G_INDEX_2];

    if(G_COUNTER_1 == ptr_ANIM_GRANDMA->num_FRAME)
    {
        // UPDATE GRANDMA TILESET //
        VDP_loadTileSet(ptr_ANIM_GRANDMA->ptr_IMAGE_GRANDMA_BG_B->tileset, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile, DMA);
        VDP_loadTileSet(ptr_ANIM_GRANDMA->ptr_IMAGE_GRANDMA_BG_A->tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile, DMA);


        // UPDATE INDEX IN GRANDMA ANIMATION TABLE //
        // UP TO 12 (LAST INDEX IN ARRAY OF 13 ENTRIES) //
        if(G_INDEX_2 < 12)
        {
            G_INDEX_2 += 1;
        }
    }


    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_SCREEN_7_2[G_INDEX_3];

    if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
    {
        // CHANGING SPRITE ANIMATION FRAME //
        SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

        // RETRIEVE X POSITION FROM TABLE //
        SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 142 );


        // UPDATE INDEX IN STOOGES ANIMATION TABLE //
        // UP TO 20 (LAST INDEX IN ARRAY OF 21 ENTRIES) //
        if(G_INDEX_3 < 20)
        {
            G_INDEX_3 += 1;
        }
    }


    // GO TO NEXT ANIMATION //
    else if(G_COUNTER_1 == 401)
    {        
        // REINIT COUNTER //
        G_COUNTER_1   = 0;

        // NEXT ANIMATION //
        G_INDEX_1       = 3;
        G_INDEX_2       = 0;
        G_INDEX_3       = 0;

        // SKIP COUNTER INCREMENT //
        return;
    }


    G_COUNTER_1 += 1;
}


void anim_INTRO_SCREEN_7_3()
{
    // GRANDMA ANIMATION //
    // SETUP POINTER TO GRANDMA ANIMATION TABLE //
    const struct_ANIM_GRANDMA_ *ptr_ANIM_GRANDMA = &TABLE_ANIM_GRANDMA_SCREEN_7_3[G_INDEX_2];

    if(G_COUNTER_1 == ptr_ANIM_GRANDMA->num_FRAME)
    {
        // UPDATE GRANDMA TILESET //
        VDP_loadTileSet(ptr_ANIM_GRANDMA->ptr_IMAGE_GRANDMA_BG_B->tileset, G_ADR_VRAM_BG_B + image_INTRO_SCREEN_7_BG_B.tileset->numTile, DMA);
        VDP_loadTileSet(ptr_ANIM_GRANDMA->ptr_IMAGE_GRANDMA_BG_A->tileset, G_ADR_VRAM_BG_A + image_INTRO_SCREEN_7_BG_A.tileset->numTile, DMA);


        // UPDATE INDEX IN GRANDMA ANIMATION TABLE //
        // UP TO 32 (LAST INDEX IN ARRAY OF 33 ENTRIES) //
        if(G_INDEX_2 < 31)
        {
            G_INDEX_2 += 1;
        }
    }


    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_SCREEN_7_3[G_INDEX_3];

    if(G_COUNTER_1 == ptr_ANIM_STOOGES->num_FRAME)
    {
        // CHANGING SPRITE ANIMATION FRAME //
        SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

        // RETRIEVE X POSITION FROM TABLE //
        SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 142 );


        // UPDATE INDEX IN STOOGES ANIMATION TABLE //
        // UP TO 34 (LAST INDEX IN ARRAY OF 35 ENTRIES) //
        if(G_INDEX_3 < 34)
        {
            G_INDEX_3 += 1;
        }
    }


    

    // WHAT'S THE MATTER LADY ? //
    if(G_COUNTER_1 == 0)
    {
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 10, 12, 0, 0, 14, 4, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_INTRO_SCREEN_7_DIALOG.tileset->numTile), 11, 13, 0, 0, 12, 2, DMA_QUEUE);

        SPR_setPosition(sprite_ARROW_DIALOG , 125 , 128);
    }

    else if(G_COUNTER_1 == 249)
    {
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 10, 12, 10, 12, 14, 4, DMA_QUEUE);

        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 2, 4, 0, 4, 17, 7, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_INTRO_SCREEN_7_DIALOG.tileset->numTile), 3, 5, 0, 3, 15, 5, DMA_QUEUE);

        SPR_setPosition(sprite_ARROW_DIALOG , 61 , 88);
        SPR_setFrame(sprite_ARROW_DIALOG , 1);
    }

    else if(G_COUNTER_1 == 621)
    {
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_INTRO_SCREEN_7_DIALOG.tileset->numTile), 3, 5, 0, 9, 15, 5, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 1447)
    {
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 2, 4, 2, 4, 17, 7, DMA_QUEUE);

        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_DIALOG.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG), 10, 10, 0, 11, 15, 6, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_TEXT.tilemap, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, G_ADR_VRAM_DIALOG + image_INTRO_SCREEN_7_DIALOG.tileset->numTile), 11, 11, 0, 15, 13, 4, DMA_QUEUE);

        SPR_setPosition(sprite_ARROW_DIALOG , 125 , 128);
        SPR_setFrame(sprite_ARROW_DIALOG , 0);
    }

    else if(G_COUNTER_1 == 1681)
    {
        VDP_setTileMapEx(BG_A, image_INTRO_SCREEN_7_BG_A.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A), 10, 10, 10, 10, 15, 6, DMA_QUEUE);

        SPR_releaseSprite(sprite_ARROW_DIALOG);
        sprite_ARROW_DIALOG = NULL;
    }


    // FADE OUT //
    else if(G_COUNTER_1 == 3149)
    {
        // COUNTERS RESET //
        G_COUNTER_1 = 0;
        G_INDEX_1   = 0;
        G_INDEX_2   = 0;
        G_INDEX_3   = 0;
        
        // GO TO FADE OUT SEQUENCE //
        G_SCENE     = SCENE_FADE_OUT;

        return;
    }


    G_COUNTER_1 += 1;

}




void (*TABLE_ANIM_INTRO_7[4])(void)         =       {
                                                        anim_INTRO_SCREEN_7_0,
                                                        anim_INTRO_SCREEN_7_1,
                                                        anim_INTRO_SCREEN_7_2,
                                                        anim_INTRO_SCREEN_7_3
                                                    };