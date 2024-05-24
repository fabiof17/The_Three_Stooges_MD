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
//                        CRUTCHES VELOCITY FOR EACH SPRITE FRAME                       //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const u8                            TABLE_VELOCITY_CRUTCHES[3]      =   {
                                                                            14,
                                                                            16,
                                                                            17
                                                                        };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                       WHEELCHAIR VELOCITY FOR EACH SPRITE FRAME                      //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const u8                            TABLE_VELOCITY_WHEELCHAIR[3]    =   {
                                                                            8,
                                                                            9,
                                                                            5
                                                                        };




//--------------------------------------------------------------------------------------//
//                                                                                      //
//                       STRETCHER 1 VELOCITY FOR EACH SPRITE FRAME                     //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const u8                            TABLE_VELOCITY_STRETCHER_1[8]   =   {
                                                                            6,//6
                                                                            9,//9
                                                                            4,//4
                                                                            12,//12
                                                                            7,//7
                                                                            10,//10
                                                                            3,//3
                                                                            13//13
                                                                        };








const u16                           TABLE_PATIENT_SPAWN_POSITION[11] =   {
                                                                            48,
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
                                                                            { &tiles_SPR_WHEELCHAIR  , 48 ,  56 , 3 ,  8 ,  8 , &TABLE_VELOCITY_WHEELCHAIR[0]  },

                                                                            // STRETCHER 1 //
                                                                            { &tiles_SPR_STRETCHER_1 , 48 , 112 , 8 ,  4 ,  6 , &TABLE_VELOCITY_STRETCHER_1[0] }
                                                                        };
















