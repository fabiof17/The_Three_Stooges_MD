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




typedef struct
{
    Sprite *spr_CAR;
    u8 axis_CAR;

    bool hit;

    s16 pos_X;
    s16 pos_Y;
    
    u8 index_WRITE_AXIS;
    u8 index_READ_AXIS;

    u8 TABLE_SPEED[17];
    u8 TABLE_AXIS[17];

} struct_CAR_;




typedef struct
{
    Sprite *spr_NURSE;
    u8 axis_NURSE;

    s16 pos_X;
    s16 pos_Y;
    
    u8 counter_SPRITE_FRAME;
    u8 index_SPRITE_FRAME;

    u8 counter_ITEM;
    u8 index_ITEM;

} struct_NURSE_;




typedef struct
{
    const SpriteDefinition *tiles_PATIENT_TYPE;

    u8 width_PATIENT;
    u8 height_PATIENT;

    u8 number_STEPS;
    u8 number_STEPS_HIT;
    u8 speed_STEPS;

    const s8 *ptr_VELOCITY;

} struct_PATIENT_TYPE_;




typedef struct
{
    Sprite *spr_PATIENT;
    const SpriteDefinition *tiles_PATIENT;

    bool patient_STATE;

    u8 width_PATIENT;
    u8 height_PATIENT;

    u8 number_STEPS;
    u8 number_STEPS_HIT;
    u8 speed_STEPS;
    
    s16 pos_X;
    s16 pos_Y;
    
    u8 counter_SPRITE_FRAME;
    u8 index_SPRITE_FRAME;

    u16 spawn_FRAME;

    const s8 *ptr_VELOCITY;

} struct_PATIENT_;




typedef struct
{    
    const SpriteDefinition *tiles_ITEM;

    u8 reward_ITEM;

} struct_ITEM_TYPE_;




typedef struct
{
    Sprite *spr_ITEM;
    
    const SpriteDefinition *tiles_ITEM;

    u8 axis_ITEM;

    u8 reward_ITEM;

    u8 counter_FRAME;
    u8 index_FRAME;

    s16 pos_X;
    s16 pos_Y;

} struct_ITEM_;




typedef struct
{
    Sprite *spr_CRACKER;

    s16 pos_X;
    s16 pos_Y;

    u8 counter_CRACKER;
    u8 state_CRACKER;

    bool animated;

} struct_CRACKER_;




typedef struct
{
    s16 pos_X;
    s16 pos_Y;

} struct_POSITION_;




typedef struct
{
    Sprite *spr_CHAR_1;
    Sprite *spr_CHAR_2;
    u8 state_CHARACTER;
    u8 counter_CHARACTER;

    Sprite *spr_PIE;
    u8 state_PIE;
    u8 index_ANIM_PIE;

} struct_WAITER_;




typedef struct
{
    s16 pos_X_PIE;
    s16 pos_Y_PIE;

    u8 index_ANIM_PIE;

} struct_PIE_ANIM_;













#endif // _MAIN