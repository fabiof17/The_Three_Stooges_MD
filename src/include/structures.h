#ifndef _STRUCTURES_H
#define _STRUCTURES_H



typedef struct
{
    u16 num_FRAME;
    const Image *ptr_IMAGE_GRANDMA_BG_B;
    const Image *ptr_IMAGE_GRANDMA_BG_A;

} struct_ANIM_GRANDMA_;


typedef struct
{
    u16 num_FRAME;
    u8 index_SPRITE_FRAME;
    s16 pos_X;

} struct_WALK_STOOGES_;


typedef struct
{
    const Image *ptr_IMAGE_QUESTION;
    const u8 answer;

} struct_QUESTION_;


typedef struct
{
    u16 num_FRAME;
    s16 pos_X;
    s16 pos_Y;

} struct_ICE_CUBE_;















#endif // _MAIN