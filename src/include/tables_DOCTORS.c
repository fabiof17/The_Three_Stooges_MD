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







const u16                           TABLE_PATIENT_SPAWN_POSITION[4] =   {
                                                                            51
                                                                        };








//--------------------------------------------------------------------------------------//
//                                                                                      //
//                             4 DIFFERENT TYPES OF PATIENT                             //
//                                                                                      //
//--------------------------------------------------------------------------------------//
const struct_PATIENT_TYPE_          TABLE_PATIENT_TYPE[4]           =   {
                                                                            // CRUTCHES //
                                                                            { &tiles_SPR_CRUTCHES   , 48 , 40 , &TABLE_VELOCITY_CRUTCHES[0]   },
                                                                            
                                                                            // WHEELCHAIR //
                                                                            { &tiles_SPR_WHEELCHAIR , 48 , 56 , &TABLE_VELOCITY_WHEELCHAIR[0] }
                                                                        };







/*
const struct_PATIENT_               TABLE_PATIENTS[10]          =   {
                                                                        { NULL , &tiles_SPR_CRUTCHES   , 0 ,  88 , -40 , 0 , 0 , 150 , &TABLE_VELOCITY_CRUTCHES[0]   },
                                                                        { NULL , &tiles_SPR_WHEELCHAIR , 0 , 162 , -40 , 0 , 0 , 800 , &TABLE_VELOCITY_WHEELCHAIR[0] },
                                                                        { NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL }
                                                                    };
*/