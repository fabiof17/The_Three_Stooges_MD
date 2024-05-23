#include <genesis.h>




#include "structures.h"




#include "sprites_DOCTORS.h"




const u8                            TABLE_NURSE_VELOCITY[4]     =   {
                                                                        26,
                                                                        16,
                                                                        6,
                                                                        16
                                                                    };




const u8                            TABLE_VELOCITY_CRUTCHES[3]  =   {
                                                                        14,
                                                                        16,
                                                                        17
                                                                    };




const struct_PATIENT_               TABLE_PATIENTS[10]          =   {
                                                                        { NULL , &tiles_SPR_CRUTCHES , 0 , 88 , -40 , 0 , 0 , 150 , &TABLE_VELOCITY_CRUTCHES[0] }
                                                                    };