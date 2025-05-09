#include <genesis.h>




#include "structures.h"
#include "variables.h"




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                      ANIMATIONS                                      //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const struct_WALK_STOOGES_      TABLE_ANIM_STOOGES_WALKIN_SLAP[26]          =   {
                                                                                    {   34 ,  0 , -87 },
                                                                                    {   36 ,  1 , -79 },
                                                                                    {   41 ,  2 , -73 },
                                                                                    {   45 ,  3 , -65 },
                                                                                    {   48 ,  4 , -57 },
                                                                                    {   52 ,  5 , -49 },
                                                                                    {   54 ,  6 , -40 },
                                                                                    {   59 ,  7 , -31 },
                                                                                    {   63 ,  0 , -23 },
                                                                                    {   66 ,  1 , -17 },
                                                                                    {   70 ,  2 ,  -9 },
                                                                                    {   72 ,  3 ,  -1 },
                                                                                    {   77 ,  4 ,   7 },
                                                                                    {   80 ,  5 ,  17 },
                                                                                    {   84 ,  6 ,  23 },
                                                                                    {   88 ,  7 ,  32 },
                                                                                    {   90 ,  0 ,  41 },
                                                                                    {   95 ,  1 ,  49 },
                                                                                    {   99 ,  2 ,  55 },
                                                                                    {  102 ,  3 ,  63 },
                                                                                    {  106 ,  4 ,  71 },
                                                                                    {  108 ,  5 ,  81 },
                                                                                    {  114 , 10 ,  88 },
                                                                                    {  120 , 11 ,  95 },
                                                                                    {  128 , 12 ,  95 },
                                                                                    {  131 , 14 , 116 }
                                                                                };




const bool                      TABLE_PROBABILITY_85[20]               =   {
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE
                                                                                };


const bool                      TABLE_PROBABILITY_80[20]               =   {
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE
                                                                                };


const bool                      TABLE_PROBABILITY_75[20]               =   {
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE
                                                                                };


const bool                      TABLE_PROBABILITY_70[20]               =   {
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE
                                                                                };


const bool                      TABLE_PROBABILITY_65[20]               =   {
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE
                                                                                };

/*
const bool                      TABLE_PROBABILITY_60[20]               =   {
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE
                                                                                };


const bool                      TABLE_PROBABILITY_55[20]               =   {
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE
                                                                                };


const bool                      TABLE_PROBABILITY_50[20]               =   {
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE
                                                                                };


const bool                      TABLE_PROBABILITY_45[20]               =   {
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE
                                                                                };


const bool                      TABLE_PROBABILITY_40[20]               =   {
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE,
                                                                                    FALSE,
                                                                                    TRUE,
                                                                                    FALSE
                                                                                };*/








const bool                     *TABLE_PROBABILITY_SLAP_ATTACK[7]            =   {
                                                                                    &TABLE_PROBABILITY_70[0],
                                                                                    &TABLE_PROBABILITY_75[0],
                                                                                    &TABLE_PROBABILITY_75[0],
                                                                                    &TABLE_PROBABILITY_80[0],
                                                                                    &TABLE_PROBABILITY_80[0],
                                                                                    &TABLE_PROBABILITY_85[0],
                                                                                    &TABLE_PROBABILITY_85[0]
                                                                                };


const u8                        TABLE_ID_PCM_SLAP_HIT[8]                    =   {
                                                                                    79,
                                                                                    79,
                                                                                    78,
                                                                                    NULL,
                                                                                    77,
                                                                                    76,
                                                                                    75,
                                                                                    74
                                                                                };


















