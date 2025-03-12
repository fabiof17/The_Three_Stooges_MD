#include <genesis.h>



#include "custom_tools.h"
#include "structures.h"
#include "variables.h"



#include "maps_BOXING.h"




#include "tables_BOXING.h"




#include "music.h"




// SCROLLS TRASH SPRITES //
inline static void scroll_TRASH()
{
    u8 i;

    for(i=0 ; i<MAX_OBSTACLES ; i++)
    {
        if(LIST_OBSTACLES[i].type == TYPE_TRASH)
        {
            if(TABLES_OBSTACLES[i].pos_X_ref <= (G_POS_X_CAMERA + 320))
            {
                if(TABLES_OBSTACLES[i].pos_X_ref + LIST_OBSTACLES[i].width + 8 >= G_POS_X_CAMERA)
                {
                    LIST_OBSTACLES[i].pos_X = TABLES_OBSTACLES[i].pos_X_ref - G_POS_X_CAMERA;
                    LIST_OBSTACLES[i].pos_Y = TABLES_OBSTACLES[i].pos_Y_ref - 36;

                    // SCROLL TRASH SPRITES //
                    if(LIST_OBSTACLES[i].type == TYPE_TRASH)
                    {
                        u8 current_trash = LIST_OBSTACLES[i].index_trash;

                        SPR_setPosition(LIST_TRASH[current_trash] , LIST_OBSTACLES[i].pos_X , LIST_OBSTACLES[i].pos_Y);
                    }
                }
            }
        }
    }
}

// SCROLLS OBSTACLES //
inline static void scroll_OBSTACLES()
{
    u8 i;

    for(i=0 ; i<MAX_OBSTACLES ; i++)
    {
        if(TABLES_OBSTACLES[i].pos_X_ref <= (G_POS_X_CAMERA + 320))
        {
            if(TABLES_OBSTACLES[i].pos_X_ref + LIST_OBSTACLES[i].width + 8 >= G_POS_X_CAMERA)
            {
                LIST_OBSTACLES[i].pos_X = TABLES_OBSTACLES[i].pos_X_ref - G_POS_X_CAMERA;
                LIST_OBSTACLES[i].pos_Y = TABLES_OBSTACLES[i].pos_Y_ref;
            }

            else
            {
                LIST_OBSTACLES[i].pos_X = 0;
                LIST_OBSTACLES[i].pos_Y = 0;
            }
        }

        else
        {
            LIST_OBSTACLES[i].pos_X = 0;
            LIST_OBSTACLES[i].pos_Y = 0;
        }
    }
}








inline static void scroll_TILE()
{
    if(G_RUN_DIRECTION == DIRECTION_FW)
    {
        if(G_POS_X_CAMERA + larry_BOXING.velocity <= 6144)
        {
            G_POS_X_CAMERA += larry_BOXING.velocity;
        }

        else
        {
            G_POS_X_CAMERA = 6144;

            G_PHASE_SEQUENCE = BOXING_PHASE_FADEOUT;
        }
    }


    else
    {
        if(G_POS_X_CAMERA - larry_BOXING.velocity >= 128)
        {
            G_POS_X_CAMERA -= larry_BOXING.velocity;
        }

        else
        {
            G_POS_X_CAMERA = 128;

            G_PHASE_SEQUENCE = BOXING_PHASE_SUCCESS;
        }
    }


    u8 i;

    for (i=0; i<14; i++)
    {
        scrollTable_BG[i] = -G_POS_X_CAMERA;
    }

    VDP_setHorizontalScrollTile(BG_B, 13, scrollTable_BG, 14, DMA_QUEUE);
    VDP_setHorizontalScrollTile(BG_A, 13, scrollTable_BG, 14, DMA_QUEUE);
}


inline static void update_TILEMAP_RIGHT()
{
    if(G_POS_X_CAMERA > 15)
    {
        VDP_setTileMapColumnEx(BG_B, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B) , (G_POS_X_CAMERA >> 3) - 2, (G_POS_X_CAMERA >> 3) + 62, 45, 14, DMA_QUEUE);
        VDP_setTileMapColumnEx(BG_A, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B) , (G_POS_X_CAMERA >> 3) - 2, (G_POS_X_CAMERA >> 3) + 62, 13, 14, DMA_QUEUE);
    }
}


inline static void update_TILEMAP_LEFT()
{
    if(G_POS_X_CAMERA > 15)
    {
        VDP_setTileMapColumnEx(BG_B, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B) , (G_POS_X_CAMERA >> 3) - 2, (G_POS_X_CAMERA >> 3) - 2, 45, 14, DMA_QUEUE);
        VDP_setTileMapColumnEx(BG_A, image_BOXING_BG_B_DEF.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B) , (G_POS_X_CAMERA >> 3) - 2, (G_POS_X_CAMERA >> 3) - 2, 13, 14, DMA_QUEUE);

        //VDP_setTileMapColumnEx(BG_B, image_BOXING_BG_B.tilemap,  TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B),  (G_POS_X_CAMERA >> 3) - 2, (G_POS_X_CAMERA >> 3) - 2, 13, 14, DMA_QUEUE);
        //VDP_setTileMapColumnEx(BG_A, image_BOXING_BG_A2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A2), (G_POS_X_CAMERA >> 3) - 2, (G_POS_X_CAMERA >> 3) - 2, 13, 14, DMA_QUEUE);
    }
}








inline static void anim_BOXERS()
{
    if(G_COUNTER_BOXERS == 70)
    {
        G_COUNTER_BOXERS = 0;

        G_INDEX_BOXERS += 1;

        if(G_INDEX_BOXERS == 12)
        {
            G_INDEX_BOXERS = 0;
        }

        SPR_setFrame(sprite_BOXERS,TABLE_BOXERS[G_INDEX_BOXERS]);
    }

    G_COUNTER_BOXERS += 1;
}


inline static void anim_WATCH_HAND()
{
    // WATCH HAND COUNTER //
    // ORIGINAL TIMER : 79 //
    if(G_COUNTER_WATCH_HAND == 89)
    {
        G_COUNTER_WATCH_HAND = 0;

        // WATCH HAND SPRITE FRAME INDEX //
        G_INDEX_WATCH += 1;

        if(G_INDEX_WATCH == 1)
        {
            // UPDATE CHRONO SPRITE //
            SPR_setFrame(sprite_CHRONO,0);

            // UPDATE HAMMER SPRITE //
            SPR_setFrame(sprite_HAMMER,0);
            SPR_setPosition(sprite_HAMMER,280,24);


            // UPDATE THUMB //
            VDP_loadTileSet(image_THUMB1_BG_A.tileset, G_ADR_VRAM_THUMB, DMA_QUEUE);

            // UPDATE DESK //
            VDP_loadTileSet(image_DESK1_BG_A.tileset, G_ADR_VRAM_DESK, DMA_QUEUE);

            // UPDATE GONG //
            VDP_loadTileSet(image_GONG1_BG_B.tileset, G_ADR_VRAM_GONG, DMA_QUEUE);
        }


        else if(G_INDEX_WATCH == 12)
        {
            G_INDEX_WATCH = 0;

            // UPDATE CHRONO SPRITE //
            SPR_setFrame(sprite_CHRONO,1);

            // UPDATE HAMMER SPRITE //
            SPR_setFrame(sprite_HAMMER,1);
            SPR_setPosition(sprite_HAMMER,277,40);


            // UPDATE THUMB //
            VDP_loadTileSet(image_THUMB2_BG_A.tileset, G_ADR_VRAM_THUMB, DMA_QUEUE);

            // UPDATE DESK //
            VDP_loadTileSet(image_DESK2_BG_A.tileset, G_ADR_VRAM_DESK, DMA_QUEUE);

            // UPDATE GONG //
            VDP_loadTileSet(image_GONG2_BG_B.tileset, G_ADR_VRAM_GONG, DMA_QUEUE);


            // UPDATE ROUND NUMBER //
            if(G_INDEX_ROUND <6)
            {
                G_INDEX_ROUND += 1;

                SPR_setFrame(sprite_ROUND,G_INDEX_ROUND);
            }

            else
            {
                G_PHASE_SEQUENCE = BOXING_PHASE_FAIL;
            }

            XGM_startPlayPCM(SOUND_GONG , 15 , SOUND_PCM_CH3);
        }

        // UPDATE WATCH HAND SPRITE //
        SPR_setFrame(sprite_WATCH_HAND,G_INDEX_WATCH);

        return;
    }

    G_COUNTER_WATCH_HAND += 1;
}


inline static void anim_LARRY()
{
    if(larry_BOXING.state == LARRY_PHASE_RUN)
    {
        if(larry_BOXING.counter_SPRITE_FRAME == 5)
        {
            larry_BOXING.index_SPRITE_FRAME += 1;

            if(larry_BOXING.index_SPRITE_FRAME == 8)
            {
                larry_BOXING.index_SPRITE_FRAME = 0;
            }


            SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.index_SPRITE_FRAME);

            larry_BOXING.counter_SPRITE_FRAME = 0;

            return;
        }

        larry_BOXING.counter_SPRITE_FRAME += 1;
    }


    else if(larry_BOXING.state == LARRY_PHASE_JUMP)
    {
        larry_BOXING.pos_Y += fix32ToInt(larry_BOXING.gravity);


        if(larry_BOXING.row == ROW_BG)
        {
            if(larry_BOXING.gravity > 0)
            {
                if(larry_BOXING.pos_Y >= TOP_BOUND)
                {
                    larry_BOXING.pos_Y = TOP_BOUND;

                    larry_BOXING.counter_SPRITE_FRAME = 0;

                    larry_BOXING.index_SPRITE_FRAME = 0;

                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.index_SPRITE_FRAME);

                    larry_BOXING.state = LARRY_PHASE_RUN;
                }
            }
        }


        else if(larry_BOXING.row == ROW_FG)
        {
            if(larry_BOXING.gravity > 0)
            {
                if(larry_BOXING.pos_Y >= BOTTOM_BOUND)
                {
                    larry_BOXING.pos_Y = BOTTOM_BOUND;

                    larry_BOXING.counter_SPRITE_FRAME = 0;

                    larry_BOXING.index_SPRITE_FRAME = 0;

                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.index_SPRITE_FRAME);

                    larry_BOXING.state = LARRY_PHASE_RUN;
                }
            }
        }

        SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);


        if(larry_BOXING.gravity < 0)
        {
            larry_BOXING.gravity += FIX32(0.19);//0.25
        }


        else
        {
            larry_BOXING.gravity += FIX32(0.13);
        }
    }
}








inline static void joypad_BOXING_MINIGAME_FW()
{
    u16 value=JOY_readJoypad(JOY_1);

    if(G_PHASE_SEQUENCE == BOXING_PHASE_RUN)
    {
        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON LEFT                          //
        //                                                              //
        //--------------------------------------------------------------//

        if(value & BUTTON_LEFT)
        {
            if(larry_BOXING.state == LARRY_PHASE_RUN)
            {
                larry_BOXING.velocity = 2;

                larry_BOXING.pos_X -= 1;

                if(larry_BOXING.pos_X < LEFT_BOUND_FW)
                {
                    larry_BOXING.pos_X = LEFT_BOUND_FW;
                }


                if(value & BUTTON_UP)
                {
                    if(larry_BOXING.row != ROW_BG)
                    {
                        larry_BOXING.row = ROW_BG;

                        larry_BOXING.pos_Y = TOP_BOUND;

                        SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,FALSE);

                        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH);
                        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH + 1);
                        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                    }
                }

                else if(value & BUTTON_DOWN)
                {
                    if(larry_BOXING.row != ROW_FG)
                    {
                        larry_BOXING.row = ROW_FG;

                        larry_BOXING.pos_Y = BOTTOM_BOUND;

                        SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,TRUE);

                        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH);
                        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH + 1);
                        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                    }
                }

                SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);
            }
        }

        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON RIGHT                         //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_RIGHT)
        {
            if(larry_BOXING.state == LARRY_PHASE_RUN)
            {
                larry_BOXING.velocity = 4;

                larry_BOXING.pos_X += 2;

                if(larry_BOXING.pos_X > RIGHT_BOUND_FW)
                {
                    larry_BOXING.pos_X = RIGHT_BOUND_FW;
                }


                if(value & BUTTON_UP)
                {
                    if(larry_BOXING.row != ROW_BG)
                    {
                        larry_BOXING.row = ROW_BG;

                        larry_BOXING.pos_Y = TOP_BOUND;

                        SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,FALSE);

                        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH);
                        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH + 1);
                        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                    }
                }

                else if(value & BUTTON_DOWN)
                {
                    if(larry_BOXING.row != ROW_FG)
                    {
                        larry_BOXING.row = ROW_FG;

                        larry_BOXING.pos_Y = BOTTOM_BOUND;

                        SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,TRUE);

                        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH);
                        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH + 1);
                        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                    }
                }

                SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);
            }
        }

        //--------------------------------------------------------------//
        //                                                              //
        //                          BUTTON UP                           //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_UP)
        {
            if(larry_BOXING.state == LARRY_PHASE_RUN)
            {
                if(larry_BOXING.row != ROW_BG)
                {
                    larry_BOXING.row = ROW_BG;

                    larry_BOXING.pos_Y = TOP_BOUND;

                    SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

                    SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,FALSE);

                    SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH);
                    SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH + 1);
                    SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                }
            }
        }

        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON DOWN                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_DOWN)
        {
            if(larry_BOXING.state == LARRY_PHASE_RUN)
            {
                if(larry_BOXING.row != ROW_FG)
                {
                    larry_BOXING.row = ROW_FG;

                    larry_BOXING.pos_Y = BOTTOM_BOUND;

                    SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

                    SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,TRUE);

                    SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH);
                    SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH + 1);
                    SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                }
            }
        }
    }
}


inline static void joypad_BOXING_MINIGAME_BW()
{
    u16 value=JOY_readJoypad(JOY_1);

    if(G_PHASE_SEQUENCE == BOXING_PHASE_RUN)
    {
        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON RIGHT                         //
        //                                                              //
        //--------------------------------------------------------------//

        if(value & BUTTON_RIGHT)
        {
            if(larry_BOXING.state == LARRY_PHASE_RUN)
            {
                larry_BOXING.velocity = 2;

                larry_BOXING.pos_X += 1;

                if(larry_BOXING.pos_X > RIGHT_BOUND_BW)
                {
                    larry_BOXING.pos_X = RIGHT_BOUND_BW;
                }


                if(value & BUTTON_UP)
                {
                    if(larry_BOXING.row != ROW_BG)
                    {
                        larry_BOXING.row = ROW_BG;

                        larry_BOXING.pos_Y = TOP_BOUND;

                        SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,FALSE);

                        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH);
                        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH + 1);
                        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                    }
                }

                else if(value & BUTTON_DOWN)
                {
                    if(larry_BOXING.row != ROW_FG)
                    {
                        larry_BOXING.row = ROW_FG;

                        larry_BOXING.pos_Y = BOTTOM_BOUND;

                        SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,TRUE);

                        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH);
                        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH + 1);
                        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                    }
                }

                SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);
            }
        }

        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON LEFT                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_LEFT)
        {
            if(larry_BOXING.state == LARRY_PHASE_RUN)
            {
                larry_BOXING.velocity = 4;

                larry_BOXING.pos_X -= 2;

                if(larry_BOXING.pos_X < LEFT_BOUND_BW)
                {
                    larry_BOXING.pos_X = LEFT_BOUND_BW;
                }


                if(value & BUTTON_UP)
                {
                    if(larry_BOXING.row != ROW_BG)
                    {
                        larry_BOXING.row = ROW_BG;

                        larry_BOXING.pos_Y = TOP_BOUND;

                        SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,FALSE);

                        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH);
                        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH + 1);
                        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                    }
                }

                else if(value & BUTTON_DOWN)
                {
                    if(larry_BOXING.row != ROW_FG)
                    {
                        larry_BOXING.row = ROW_FG;

                        larry_BOXING.pos_Y = BOTTOM_BOUND;

                        SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,TRUE);

                        SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH);
                        SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH + 1);
                        SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                    }
                }

                SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);
            }
        }

        //--------------------------------------------------------------//
        //                                                              //
        //                          BUTTON UP                           //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_UP)
        {
            if(larry_BOXING.state == LARRY_PHASE_RUN)
            {
                if(larry_BOXING.row != ROW_BG)
                {
                    larry_BOXING.row = ROW_BG;

                    larry_BOXING.pos_Y = TOP_BOUND;

                    SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

                    SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,FALSE);

                    SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH);
                    SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH + 1);
                    SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                }
            }
        }

        //--------------------------------------------------------------//
        //                                                              //
        //                         BUTTON DOWN                          //
        //                                                              //
        //--------------------------------------------------------------//

        else if(value & BUTTON_DOWN)
        {
            if(larry_BOXING.state == LARRY_PHASE_RUN)
            {
                if(larry_BOXING.row != ROW_FG)
                {
                    larry_BOXING.row = ROW_FG;

                    larry_BOXING.pos_Y = BOTTOM_BOUND;

                    SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

                    SPR_setPriority(larry_BOXING.spr_LARRY_BOXING,TRUE);

                    SPR_setDepth(larry_BOXING.spr_LARRY_BOXING,SPR_MIN_DEPTH);
                    SPR_setDepth(LIST_TRASH[0],SPR_MIN_DEPTH + 1);
                    SPR_setDepth(LIST_TRASH[1],SPR_MIN_DEPTH + 2);
                }
            }
        }
    }
}




inline static void collision_OBSTACLES_FW()
{
    u8 i;

    for(i=0 ; i<MAX_OBSTACLES ; i++)
    {
        if(LIST_OBSTACLES[i].hit == FALSE)
        {
            // IF LARRY AND THE OBSTACLE ARE ON THE SAME ROW //
            if(LIST_OBSTACLES[i].row == larry_BOXING.row)
            {
                if( (larry_BOXING.pos_X + 28) >= (LIST_OBSTACLES[i].pos_X) ) // REDUCE -8 TO REDUCE COLLISON BOX (-7,-6,-5,...)
                {
                    if( (larry_BOXING.pos_X + 28) <= (LIST_OBSTACLES[i].pos_X + LIST_OBSTACLES[i].width) ) // REDUCE +8 TO REDUCE COLLISON BOX (7,6,5,...)
                    {
                        if(larry_BOXING.pos_Y + 63 >= LIST_OBSTACLES[i].pos_Y)
                        {
                            LIST_OBSTACLES[i].hit = TRUE;

                            larry_BOXING.velocity = 2;

                            larry_BOXING.counter_HIT = 0;




                            //*************************************************//
                            //                                                 //
                            //                      OBSTACLES                  //
                            //                                                 //
                            //*************************************************//

                            //-------------------------------------------------//
                            //                      LAMP                       //
                            //-------------------------------------------------//

                            if(LIST_OBSTACLES[i].type == TYPE_LAMP)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 8 >= LEFT_BOUND_FW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 8;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = LEFT_BOUND_FW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_LAMP , 15 , SOUND_PCM_CH4);
                            }


                            //-------------------------------------------------//
                            //                      POST                       //
                            //-------------------------------------------------//

                            else if(LIST_OBSTACLES[i].type == TYPE_POST)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 22 >= LEFT_BOUND_FW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 22;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = LEFT_BOUND_FW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_LAMP , 15 , SOUND_PCM_CH4);
                            }




                            //-------------------------------------------------//
                            //                     LADDER                      //
                            //-------------------------------------------------//

                            else if(LIST_OBSTACLES[i].type == TYPE_LADDER)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 14 >= LEFT_BOUND_FW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 14;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = LEFT_BOUND_FW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_LAMP , 15 , SOUND_PCM_CH4);
                            }




                            //-------------------------------------------------//
                            //                      DOOR                       //
                            //-------------------------------------------------//

                            else if(LIST_OBSTACLES[i].type == TYPE_DOOR)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 20 >= LEFT_BOUND_FW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 20;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = LEFT_BOUND_FW;
                                }

                                larry_BOXING.pos_Y -= 7;

                                XGM_startPlayPCM(SOUND_HIT_OBSTACLE , 15 , SOUND_PCM_CH4);
                            }




                            //-------------------------------------------------//
                            //                   BIG LETTERS                   //
                            //-------------------------------------------------//

                            else if(LIST_OBSTACLES[i].type == TYPE_LETTERS_BIG)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 23 >= LEFT_BOUND_FW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 23;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = LEFT_BOUND_FW;
                                }


                                if(larry_BOXING.row == ROW_BG)
                                {
                                    larry_BOXING.pos_Y = 120;
                                }

                                else
                                {
                                    larry_BOXING.pos_Y = 127;
                                }

                                larry_BOXING.state = LARRY_PHASE_RUN;

                                XGM_startPlayPCM(SOUND_HIT_OBSTACLE , 15 , SOUND_PCM_CH4);
                            }




                            //-------------------------------------------------//
                            //                       DOG                       //
                            //-------------------------------------------------//

                            else if(LIST_OBSTACLES[i].type == TYPE_DOG)
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);

                                if(larry_BOXING.pos_X + 24 <= RIGHT_BOUND_FW)
                                {
                                    larry_BOXING.pos_X += 24;
                                }

                                else
                                {
                                    larry_BOXING.pos_X = RIGHT_BOUND_FW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_BARGING , 15 , SOUND_PCM_CH4);
                            }




                            else
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);

                                if(larry_BOXING.pos_X + 24 <= RIGHT_BOUND_FW)
                                {
                                    larry_BOXING.pos_X += 24;
                                }

                                else
                                {
                                    larry_BOXING.pos_X = RIGHT_BOUND_FW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_OBSTACLE , 15 , SOUND_PCM_CH4);
                            }




                            larry_BOXING.counter_SPRITE_FRAME = 0;

                            larry_BOXING.index_SPRITE_FRAME = 0;

                            SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

                            G_OBSTACLE_TYPE = LIST_OBSTACLES[i].type;




                            G_PHASE_SEQUENCE = BOXING_PHASE_HIT;

                            return;
                        }
                    }
                }
            }
        }
    }
}




inline static void collision_OBSTACLES_BW()
{
    u8 i;

    for(i=0 ; i<MAX_OBSTACLES ; i++)
    {
        if(LIST_OBSTACLES[i].hit == FALSE)
        {
            // IF LARRY AND THE OBSTACLE ARE ON THE SAME ROW //
            if(LIST_OBSTACLES[i].row == larry_BOXING.row)
            {
                if( (larry_BOXING.pos_X + 28) >= (LIST_OBSTACLES[i].pos_X) ) // REDUCE -8 TO REDUCE COLLISON BOX (-7,-6,-5,...)
                {
                    if( (larry_BOXING.pos_X + 28) <= (LIST_OBSTACLES[i].pos_X + LIST_OBSTACLES[i].width) ) // REDUCE +8 TO REDUCE COLLISON BOX (7,6,5,...)
                    {
                        if(larry_BOXING.pos_Y + 63 >= LIST_OBSTACLES[i].pos_Y)
                        {
                            LIST_OBSTACLES[i].hit = TRUE;

                            larry_BOXING.velocity = 2;

                            larry_BOXING.counter_HIT = 0;




                            //*************************************************//
                            //                                                 //
                            //                      OBSTACLES                  //
                            //                                                 //
                            //*************************************************//

                            //-------------------------------------------------//
                            //                     HYDRANT                     //
                            //-------------------------------------------------//
                            //**
                            if(LIST_OBSTACLES[i].type == TYPE_HYDRANT)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 24 >= LEFT_BOUND_BW)
                                {
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 24;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    larry_BOXING.pos_X = LEFT_BOUND_BW;
                                }

                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_LAMP , 15 , SOUND_PCM_CH4);
                            }


                            //-------------------------------------------------//
                            //                      LAMP                       //
                            //-------------------------------------------------//
                            //**
                            else if(LIST_OBSTACLES[i].type == TYPE_LAMP)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 5 >= LEFT_BOUND_BW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 5;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = LEFT_BOUND_BW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_LAMP , 15 , SOUND_PCM_CH4);
                            }


                            //-------------------------------------------------//
                            //                      POST                       //
                            //-------------------------------------------------//
                            //**
                            else if(LIST_OBSTACLES[i].type == TYPE_POST)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 10 >= LEFT_BOUND_BW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 10;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = LEFT_BOUND_BW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_LAMP , 15 , SOUND_PCM_CH4);
                            }




                            //-------------------------------------------------//
                            //                     LADDER                      //
                            //-------------------------------------------------//
                            //**
                            else if(LIST_OBSTACLES[i].type == TYPE_LADDER)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X <= RIGHT_BOUND_BW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X + 5;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = RIGHT_BOUND_BW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_LAMP , 15 , SOUND_PCM_CH4);
                            }




                            //-------------------------------------------------//
                            //                      DOOR                       //
                            //-------------------------------------------------//
                            //**
                            else if(LIST_OBSTACLES[i].type == TYPE_DOOR)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X - 12 <= RIGHT_BOUND_BW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 8;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = RIGHT_BOUND_BW;
                                }

                                larry_BOXING.pos_Y -= 7;

                                XGM_startPlayPCM(SOUND_HIT_OBSTACLE , 15 , SOUND_PCM_CH4);
                            }




                            //-------------------------------------------------//
                            //                   BIG LETTERS                   //
                            //-------------------------------------------------//
                            //**
                            else if(LIST_OBSTACLES[i].type == TYPE_LETTERS_BIG)
                            {
                                // IF THERE IS ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                if(LIST_OBSTACLES[i].pos_X + 25 <= RIGHT_BOUND_BW)
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X +25;
                                }

                                // IF THERE IS not ENOUGH ROOM AT THE LEFT OF THE OBSTACLE //
                                else
                                {
                                    SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);
                                    larry_BOXING.pos_X = RIGHT_BOUND_BW;
                                }


                                if(larry_BOXING.row == ROW_BG)
                                {
                                    larry_BOXING.pos_Y = 120;
                                }

                                else
                                {
                                    larry_BOXING.pos_Y = 127;
                                }

                                larry_BOXING.state = LARRY_PHASE_RUN;

                                XGM_startPlayPCM(SOUND_HIT_OBSTACLE , 15 , SOUND_PCM_CH4);
                            }




                            //-------------------------------------------------//
                            //                       DOG                       //
                            //-------------------------------------------------//
                            //**
                            else if(LIST_OBSTACLES[i].type == TYPE_DOG)
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);

                                if(LIST_OBSTACLES[i].pos_X <= RIGHT_BOUND_BW)
                                {
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X + 16;
                                }

                                else
                                {
                                    larry_BOXING.pos_X = RIGHT_BOUND_BW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_BARGING , 15 , SOUND_PCM_CH4);
                            }



                            //**
                            else
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);

                                if(LIST_OBSTACLES[i].pos_X + 16 <= RIGHT_BOUND_BW)
                                {
                                    larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X + 16;
                                }

                                else
                                {
                                    larry_BOXING.pos_X = RIGHT_BOUND_BW;
                                }

                                larry_BOXING.pos_Y += 2;

                                XGM_startPlayPCM(SOUND_HIT_OBSTACLE , 15 , SOUND_PCM_CH4);
                            }




                            larry_BOXING.counter_SPRITE_FRAME = 0;

                            larry_BOXING.index_SPRITE_FRAME = 0;

                            SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

                            G_OBSTACLE_TYPE = LIST_OBSTACLES[i].type;




                            G_PHASE_SEQUENCE = BOXING_PHASE_HIT;

                            return;
                        }
                    }
                }
            }
        }
    }
}








void sequence_BOXING_MINIGAME()
{
    if(G_RUN_DIRECTION == DIRECTION_FW)
    {
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                         AUDIO                                        //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        //--------------------------------------------------------------------------------------//
        //                                   LOOP CROWD SOUND                                   //
        //--------------------------------------------------------------------------------------//
        if(XGM_isPlayingPCM(SOUND_PCM_CH2_MSK) == 0)
        {
            XGM_startPlayPCM(SOUND_CROWD , 15 , SOUND_PCM_CH2);
        }


        if(G_PHASE_SEQUENCE == BOXING_PHASE_RUN)
        {
            joypad_BOXING_MINIGAME_FW();


            scroll_TILE();
            update_TILEMAP_RIGHT();

            scroll_TRASH();
            scroll_OBSTACLES();

            anim_LARRY();

            collision_OBSTACLES_FW();


            anim_WATCH_HAND();
            anim_BOXERS();
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_HIT)
        {
            if(larry_BOXING.counter_HIT == 40)
            {
                larry_BOXING.counter_HIT = 0;

                // IF LARRY WAS RUNNING WHEN HE HIT THE OBSTACLE //
                if(larry_BOXING.state == LARRY_PHASE_RUN)
                {
                    if(G_OBSTACLE_TYPE == TYPE_DOOR)
                    {
                        larry_BOXING.pos_Y += 7;

                        SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);
                    }

                    G_PHASE_SEQUENCE = BOXING_PHASE_KO;

                    XGM_startPlayPCM(SOUND_KO , 15 , SOUND_PCM_CH4);
                }

                // IF LARRY WAS JUMPING WHEN HE HIT THE OBSTACLE
                else if(larry_BOXING.state == LARRY_PHASE_JUMP)
                {
                    G_PHASE_SEQUENCE = BOXING_PHASE_SLIDE;

                    XGM_startPlayPCM(SOUND_SLIDE , 15 , SOUND_PCM_CH4);
                }

                return;
            }

            larry_BOXING.counter_HIT += 1;
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_SLIDE)
        {
            anim_WATCH_HAND();
            anim_BOXERS();

            larry_BOXING.pos_Y += 1;

            SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

            if(larry_BOXING.row == ROW_FG)
            {
                if(larry_BOXING.pos_Y == 127)
                {
                    G_PHASE_SEQUENCE = BOXING_PHASE_KO;

                    XGM_startPlayPCM(SOUND_KO , 15 , SOUND_PCM_CH4);
                }
            }

            else
            {
                if(larry_BOXING.pos_Y == 120)
                {
                    G_PHASE_SEQUENCE = BOXING_PHASE_KO;

                    XGM_startPlayPCM(SOUND_KO , 15 , SOUND_PCM_CH4);
                }
            }
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_KO)
        {
            anim_WATCH_HAND();
            anim_BOXERS();

            if(larry_BOXING.counter_HIT == 0)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 5)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 9)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 13)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 17)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 21)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 25)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 30)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 35)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 40)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 44)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 49)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 53)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 58)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 62)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 67)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 72)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 76)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 81)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 86)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 91)
            {
                larry_BOXING.counter_HIT = 0;

                larry_BOXING.gravity = 0;

                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,0);

                if(larry_BOXING.row == ROW_BG)
                {
                    larry_BOXING.pos_Y = TOP_BOUND;
                }

                else
                {
                    larry_BOXING.pos_Y = BOTTOM_BOUND;
                }

                SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

                G_PHASE_SEQUENCE = BOXING_PHASE_RECENTER;

                return;
            }



            larry_BOXING.counter_HIT += 1;
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_RECENTER)
        {
            scroll_TILE();
            update_TILEMAP_RIGHT();

            scroll_TRASH();
            scroll_OBSTACLES();

            anim_LARRY();

            anim_WATCH_HAND();
            anim_BOXERS();




            larry_BOXING.pos_X -= 2;

            if(larry_BOXING.pos_X < LEFT_BOUND_FW)
            {
                larry_BOXING.pos_X = LEFT_BOUND_FW;
            }

            SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);




            if(larry_BOXING.counter_HIT == 24)
            {
                larry_BOXING.state = LARRY_PHASE_RUN;

                G_PHASE_SEQUENCE = BOXING_PHASE_RUN;

                return;
            }

            larry_BOXING.counter_HIT += 1;
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_FADEOUT)
        {
            // FADE OUT : 40 FRAMES //
            PAL_fadeOutAll(40,FALSE);

            // CLEAR PLANES //
            VDP_clearPlane(BG_B,TRUE);
            VDP_clearPlane(BG_A,TRUE);

            // RELEASE ALL SPRITES //
            SPR_reset();

            G_RUN_DIRECTION = DIRECTION_BW;

            // DEFINE NEXT MINIGAME //
            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_BOXING_MINIGAME;
            G_SCENE_NEXT    = SCENE_BOXING_MINIGAME;

            G_SCENE_LOADED  = FALSE;

            XGM_stopPlayPCM(SOUND_PCM_CH2);
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_FAIL)
        {
            // FADE OUT : 40 FRAMES //
            PAL_fadeOutAll(40,FALSE);

            // RESET SCROLLING //
            u8 i;

            for (i=0; i<14; i++)
            {
                scrollTable_BG[i] = 0;
            }

            VDP_setHorizontalScrollTile(BG_B, 13, scrollTable_BG, 14, CPU);
            VDP_setHorizontalScrollTile(BG_A, 13, scrollTable_BG, 14, CPU);

            // CLEAR PLANES //
            VDP_clearPlane(BG_B,TRUE);
            VDP_clearPlane(BG_A,TRUE);
            VDP_clearPlane(WINDOW,TRUE);

            // RELEASE ALL SPRITES //
            SPR_reset();


            // 1 DAY SPENT //
            G_DAY += 1;

            //G_PHASE_SEQUENCE = 0;

            G_RUN_DIRECTION = DIRECTION_FW;


            // DEFINE NEXT MINIGAME //
            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_ROULETTE;
            G_SCENE_NEXT    = SCENE_ROULETTE;

            G_SCENE_LOADED  = FALSE;

            // STOP MUSIC //
            if(XGM_isPlaying() != FALSE)
            {
                XGM_stopPlay();
            }

            waitMs(3500);
        }
    }


    else
    {
        if(G_PHASE_SEQUENCE == BOXING_PHASE_EXIT_STORE)
        {
            if(larry_BOXING.pos_X > 122)
            {
                larry_BOXING.pos_X -= 2;

                SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);
            }

            else
            {
                G_PHASE_SEQUENCE = BOXING_PHASE_RUN;
            }

            anim_LARRY();

            anim_WATCH_HAND();
            anim_BOXERS();
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_RUN)
        {
            joypad_BOXING_MINIGAME_BW();


            scroll_TILE();
            update_TILEMAP_LEFT();

            scroll_TRASH();
            scroll_OBSTACLES();

            anim_LARRY();

            collision_OBSTACLES_BW();


            anim_WATCH_HAND();
            anim_BOXERS();

            if(XGM_isPlaying() < 64)
            {
                XGM_startPlay(MUSIC_BOXING);
            }
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_HIT)
        {
            if(larry_BOXING.counter_HIT == 40)
            {
                larry_BOXING.counter_HIT = 0;

                // IF LARRY WAS RUNNING WHEN HE HIT THE OBSTACLE //
                if(larry_BOXING.state == LARRY_PHASE_RUN)
                {
                    if(G_OBSTACLE_TYPE == TYPE_DOOR)
                    {
                        larry_BOXING.pos_Y += 7;

                        SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);
                    }

                    G_PHASE_SEQUENCE = BOXING_PHASE_KO;

                    XGM_startPlayPCM(SOUND_KO , 15 , SOUND_PCM_CH4);
                }

                // IF LARRY WAS JUMPING WHEN HE HIT THE OBSTACLE
                else if(larry_BOXING.state == LARRY_PHASE_JUMP)
                {
                    G_PHASE_SEQUENCE = BOXING_PHASE_SLIDE;

                    XGM_startPlayPCM(SOUND_SLIDE , 15 , SOUND_PCM_CH4);
                }

                return;
            }

            larry_BOXING.counter_HIT += 1;
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_SLIDE)
        {
            anim_WATCH_HAND();
            anim_BOXERS();

            larry_BOXING.pos_Y += 1;

            SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

            if(larry_BOXING.row == ROW_FG)
            {
                if(larry_BOXING.pos_Y == 127)
                {
                    G_PHASE_SEQUENCE = BOXING_PHASE_KO;

                    XGM_startPlayPCM(SOUND_KO , 15 , SOUND_PCM_CH4);
                }
            }

            else
            {
                if(larry_BOXING.pos_Y == 120)
                {
                    G_PHASE_SEQUENCE = BOXING_PHASE_KO;

                    XGM_startPlayPCM(SOUND_KO , 15 , SOUND_PCM_CH4);
                }
            }
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_KO)
        {
            anim_WATCH_HAND();
            anim_BOXERS();

            if(larry_BOXING.counter_HIT == 0)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 5)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 9)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 13)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 17)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 21)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 25)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 30)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 35)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 40)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 44)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 49)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 53)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 58)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 62)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 67)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 72)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 76)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 81)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,11);
            }

            else if(larry_BOXING.counter_HIT == 86)
            {
                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,12);
            }

            else if(larry_BOXING.counter_HIT == 91)
            {
                larry_BOXING.counter_HIT = 0;

                larry_BOXING.gravity = 0;

                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,0);

                if(larry_BOXING.row == ROW_BG)
                {
                    larry_BOXING.pos_Y = TOP_BOUND;
                }

                else
                {
                    larry_BOXING.pos_Y = BOTTOM_BOUND;
                }

                SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

                G_PHASE_SEQUENCE = BOXING_PHASE_RECENTER;

                return;
            }



            larry_BOXING.counter_HIT += 1;
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_RECENTER)
        {
            scroll_TILE();
            update_TILEMAP_LEFT();

            scroll_TRASH();
            scroll_OBSTACLES();

            anim_LARRY();

            anim_WATCH_HAND();
            anim_BOXERS();




            larry_BOXING.pos_X += 2;

            if(larry_BOXING.pos_X > RIGHT_BOUND_BW)
            {
                larry_BOXING.pos_X = RIGHT_BOUND_BW;
            }

            SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);




            if(larry_BOXING.counter_HIT == 24)
            {
                larry_BOXING.state = LARRY_PHASE_RUN;

                G_PHASE_SEQUENCE = BOXING_PHASE_RUN;

                return;
            }

            larry_BOXING.counter_HIT += 1;
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_FAIL)
        {
            // FADE OUT : 40 FRAMES //
            PAL_fadeOutAll(40,FALSE);

            // RESET SCROLLING //
            u8 i;

            for (i=0; i<14; i++)
            {
                scrollTable_BG[i] = 0;
            }

            VDP_setHorizontalScrollTile(BG_B, 13, scrollTable_BG, 14, CPU);
            VDP_setHorizontalScrollTile(BG_A, 13, scrollTable_BG, 14, CPU);

            // CLEAR PLANES //
            VDP_clearPlane(BG_B,TRUE);
            VDP_clearPlane(BG_A,TRUE);
            VDP_clearPlane(WINDOW,TRUE);

            // RELEASE ALL SPRITES //
            SPR_reset();


            // 1 DAY SPENT //
            G_DAY += 1;

            //G_PHASE_SEQUENCE = 0;

            G_RUN_DIRECTION = DIRECTION_FW;


            // DEFINE NEXT MINIGAME //
            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_ROULETTE;
            G_SCENE_NEXT    = SCENE_ROULETTE;

            G_SCENE_LOADED  = FALSE;

            // STOP MUSIC //
            if(XGM_isPlaying() != FALSE)
            {
                XGM_stopPlay();
            }

            waitMs(3500);
        }


        else if(G_PHASE_SEQUENCE == BOXING_PHASE_SUCCESS)
        {
            // FADE OUT : 40 FRAMES //
            PAL_fadeOutAll(40,FALSE);

            // RESET SCROLLING //
            u8 i;

            for (i=0; i<14; i++)
            {
                scrollTable_BG[i] = 0;
            }

            VDP_setHorizontalScrollTile(BG_B, 13, scrollTable_BG, 14, CPU);
            VDP_setHorizontalScrollTile(BG_A, 13, scrollTable_BG, 14, CPU);

            // CLEAR PLANES //
            VDP_clearPlane(BG_B,TRUE);
            VDP_clearPlane(BG_A,TRUE);
            VDP_clearPlane(WINDOW,TRUE);

            // RELEASE ALL SPRITES //
            SPR_reset();


            G_RUN_DIRECTION = DIRECTION_FW;


            // DEFINE NEXT MINIGAME //
            G_SCENE         = SCENE_FADE_IN;
            G_SCENE_TYPE    = SCENE_BOXING_SCREEN_TYPE3;
            G_SCENE_NEXT    = SCENE_BOXING_SCREEN_TYPE3;

            G_SCENE_LOADED  = FALSE;

            G_REWARD = 450;

            waitMs(4500);

            XGM_stopPlay();
        }
    }

    //VDP_drawIntEx_BG_A_QUEUE(G_PHASE_SEQUENCE,1,0,0,PAL0);
}











