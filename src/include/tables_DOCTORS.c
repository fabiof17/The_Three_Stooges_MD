#include <genesis.h>




#include "structures.h"




#include "sprites_DOCTORS.h"




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                         NURSE VELOCITY FOR EACH SPRITE FRAME                         //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const u8                            TABLE_NURSE_VELOCITY[4]         =   {
                                                                            26,
                                                                            16,
                                                                            6,
                                                                            16
                                                                        };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                   NURSE ITEM TYPES                                   //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const struct_ITEM_TYPE_                  TABLE_ITEM_TYPE[3]           =   {
                                                                            { &tiles_SPR_ITEM_1 ,  5 },
                                                                            { &tiles_SPR_ITEM_2 , 10 },
                                                                            { &tiles_SPR_ITEM_3 , 15 }
                                                                        };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                        CRUTCHES VELOCITY FOR EACH SPRITE FRAME                       //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const s8                            TABLE_VELOCITY_CRUTCHES[3]      =   {
                                                                            14,
                                                                            16,
                                                                            17
                                                                        };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                       WHEELCHAIR VELOCITY FOR EACH SPRITE FRAME                      //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const s8                            TABLE_VELOCITY_WHEELCHAIR[3]    =   {
                                                                            8,//8
                                                                            9,//9
                                                                            5//5
                                                                        };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                       STRETCHER 1 VELOCITY FOR EACH SPRITE FRAME                     //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const s8                            TABLE_VELOCITY_STRETCHER_1[8]   =   {
                                                                            6,
                                                                            9,
                                                                            4,
                                                                            12,
                                                                            7,
                                                                            10,
                                                                            3,
                                                                            13
                                                                        };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                       STRETCHER 2 VELOCITY FOR EACH SPRITE FRAME                     //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const s8                            TABLE_VELOCITY_STRETCHER_2[8]   =   {
                                                                              0,
                                                                            -12,
                                                                            -12,
                                                                              0,
                                                                              0,
                                                                            -12,
                                                                            -12,
                                                                              0
                                                                        };








//--------------------------------------------------------------------------------------//
//                                                                                      //
//                              ALL POSSIBLE SPAWN POSITIONS                            //
//                                                                                      //
//--------------------------------------------------------------------------------------//

const u16                           TABLE_PATIENT_SPAWN_POSITION[11] =   {
                                                                            48,//48
                                                                            64,
                                                                            80,
                                                                            96,
                                                                            112,
                                                                            128,
                                                                            144,
                                                                            160,
                                                                            176,
                                                                            192,
                                                                            208
                                                                        };








//--------------------------------------------------------------------------------------//
//                                                                                      //
//                             4 DIFFERENT TYPES OF PATIENT                             //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const struct_PATIENT_TYPE_          TABLE_PATIENT_TYPE[4]           =   {
                                                                            // CRUTCHES //
                                                                            { &tiles_SPR_CRUTCHES    , 48 ,  40 , 3 ,  4 , 14 , &TABLE_VELOCITY_CRUTCHES[0]    },
                                                                            
                                                                            // WHEELCHAIR //
                                                                            { &tiles_SPR_WHEELCHAIR  , 56 ,  56 , 3 ,  8 ,  8 , &TABLE_VELOCITY_WHEELCHAIR[0]  },

                                                                            // STRETCHER 1 //
                                                                            { &tiles_SPR_STRETCHER_1 , 48 , 112 , 8 ,  4 ,  6 , &TABLE_VELOCITY_STRETCHER_1[0] },

                                                                            // STRETCHER 2 //
                                                                            { &tiles_SPR_STRETCHER_2 , 48 , 112 , 8 ,  4 ,  4 , &TABLE_VELOCITY_STRETCHER_2[0] }
                                                                        };





const u8                      TABLE_ID_PCM_DOCTORS_MINIGAME_CRY[4]    = {
                                                                          95,
                                                                          90,
                                                                          70,
                                                                          96
                                                                        };

const u8                      TABLE_ID_PCM_DOCTORS_MINIGAME_CRASH[2]  = {
                                                                          97,
                                                                          98
                                                                          };








