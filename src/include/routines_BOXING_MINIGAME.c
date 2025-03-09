#include <genesis.h>



#include "custom_tools.h"
#include "structures.h"
#include "variables.h"


//#include "joypad_BUTTONS.h"


#include "maps_BOXING.h"


#include "tables_BOXING.h"




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
    if(G_POS_X_CAMERA + larry_BOXING.velocity < 6144)
    {
        G_POS_X_CAMERA += larry_BOXING.velocity;
    }

    else
    {
        G_POS_X_CAMERA = 6144;
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


/*inline static void update_TILEMAP_LEFT()
{
    if(G_POS_X_CAMERA > 15)
    {
        VDP_setTileMapColumnEx(BG_B, image_BOXING_BG_B.tilemap,  TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B),  (G_POS_X_CAMERA >> 3) - 2, (G_POS_X_CAMERA >> 3) - 2, 13, 14, DMA_QUEUE);
        VDP_setTileMapColumnEx(BG_A, image_BOXING_BG_A2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A2), (G_POS_X_CAMERA >> 3) - 2, (G_POS_X_CAMERA >> 3) - 2, 13, 14, DMA_QUEUE);
    }
}*/




inline static void anim_BOXERS()
{
    if(G_COUNTER_BOXERS == 70)
    {
        G_COUNTER_BOXERS = 0;

        G_INDEX_2 += 1;

        if(G_INDEX_2 == 12)
        {
            G_INDEX_2 = 0;
        }

        SPR_setFrame(sprite_BOXERS,TABLE_BOXERS[G_INDEX_2]);
    }

    G_COUNTER_BOXERS += 1;
}


inline static void anim_WATCH_HAND()
{
    // WATCH HAND COUNTER //
    if(G_COUNTER_WATCH_HAND == 79)
    {
        G_COUNTER_WATCH_HAND = 0;

        // WATCH HAND SPRITE FRAME INDEX //
        G_INDEX_1 += 1;

        if(G_INDEX_1 == 1)
        {
            // UPDATE CHRONO SPRITE //
            SPR_setFrame(sprite_CHRONO,0);

            // UPDATE HAMMER SPRITE //
            //SPR_setFrame(sprite_HAMMER,0);
            //SPR_setPosition(sprite_HAMMER,280,24);


            // UPDATE THUMB //
            VDP_loadTileSet(image_THUMB1_BG_A.tileset, G_ADR_VRAM_THUMB, DMA_QUEUE);

            // UPDATE DESK //
            VDP_loadTileSet(image_DESK1_BG_A.tileset, G_ADR_VRAM_DESK, DMA_QUEUE);

            // UPDATE GONG //
            VDP_loadTileSet(image_GONG1_BG_B.tileset, G_ADR_VRAM_GONG, DMA_QUEUE);
        }


        else if(G_INDEX_1 == 12)
        {
            G_INDEX_1 = 0;

            // UPDATE CHRONO SPRITE //
            SPR_setFrame(sprite_CHRONO,1);

            // UPDATE HAMMER SPRITE //
            //SPR_setFrame(sprite_HAMMER,1);
            //SPR_setPosition(sprite_HAMMER,277,40);


            // UPDATE THUMB //
            VDP_loadTileSet(image_THUMB2_BG_A.tileset, G_ADR_VRAM_THUMB, DMA_QUEUE);

            // UPDATE DESK //
            VDP_loadTileSet(image_DESK2_BG_A.tileset, G_ADR_VRAM_DESK, DMA_QUEUE);

            // UPDATE GONG //
            VDP_loadTileSet(image_GONG2_BG_B.tileset, G_ADR_VRAM_GONG, DMA_QUEUE);


            // UPDATE ROUND NUMBER //
            if(G_INDEX_3 <6)
            {
                G_INDEX_3 += 1;

                //SPR_setFrame(sprite_ROUND,G_INDEX_3);
            }
        }

        // UPDATE WATCH HAND SPRITE //
        SPR_setFrame(sprite_WATCH_HAND,G_INDEX_1);

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
                if(larry_BOXING.pos_Y >= 118)
                {
                    larry_BOXING.pos_Y = 118;

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
                if(larry_BOXING.pos_Y >= 125)
                {
                    larry_BOXING.pos_Y = 125;

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




inline static void joypad_BOXING_MINIGAME()
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

                if(larry_BOXING.pos_X < 128)
                {
                    larry_BOXING.pos_X = 128;
                }


                if(value & BUTTON_UP)
                {
                    if(larry_BOXING.row != ROW_BG)
                    {
                        larry_BOXING.row = ROW_BG;

                        larry_BOXING.pos_Y = 118;

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

                        larry_BOXING.pos_Y = 125;

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

                if(larry_BOXING.pos_X > 192)
                {
                    larry_BOXING.pos_X = 192;
                }


                if(value & BUTTON_UP)
                {
                    if(larry_BOXING.row != ROW_BG)
                    {
                        larry_BOXING.row = ROW_BG;

                        larry_BOXING.pos_Y = 118;

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

                        larry_BOXING.pos_Y = 125;

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

                    larry_BOXING.pos_Y = 118;

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

                    larry_BOXING.pos_Y = 125;

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




inline static void collision_OBSTACLES_RIGHT()
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

                            //larry_BOXING.state = LARRY_PHASE_HIT;


                            // IF LARRY HITS A LAMP //
                            if(LIST_OBSTACLES[i].type == TYPE_LAMP)
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);

                                larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 8;
                            }

                            // IF LARRY HITS A POST //
                            else if(LIST_OBSTACLES[i].type == TYPE_POST)
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);

                                larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 22;
                            }

                            // IF LARRY HITS A LADDER //
                            else if(LIST_OBSTACLES[i].type == TYPE_LADDER)
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);

                                larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 14;
                            }

                            // IF LARRY HITS A DOOR //
                            else if(LIST_OBSTACLES[i].type == TYPE_DOOR)
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,9);

                                larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 20;

                                larry_BOXING.pos_Y -= 7;
                            }

                            else
                            {
                                SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,10);

                                larry_BOXING.pos_X += 24; // larry_BOXING.pos_X = LIST_OBSTACLES[i].pos_X - 4;
                            }




                            SPR_setPosition(larry_BOXING.spr_LARRY_BOXING,larry_BOXING.pos_X,larry_BOXING.pos_Y);

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
    if(G_PHASE_SEQUENCE == BOXING_PHASE_RUN)
    {
        if(G_RUN_DIRECTION == DIRECTION_FW)
        {
            joypad_BOXING_MINIGAME();

            scroll_TILE();
            update_TILEMAP_RIGHT();

            scroll_TRASH();
            scroll_OBSTACLES();

            anim_LARRY();

            collision_OBSTACLES_RIGHT();
        }

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
                G_PHASE_SEQUENCE = BOXING_PHASE_KO;
            }

            // IF LARRY WAS JUMPING WHEN HE HIT THE OBSTACLE
            else if(larry_BOXING.state == LARRY_PHASE_JUMP)
            {
                G_PHASE_SEQUENCE = BOXING_PHASE_SLIDE;
            }

            return;
        }

        larry_BOXING.counter_HIT += 1;
    }


    else if(G_PHASE_SEQUENCE == BOXING_PHASE_KO)
    {
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
            SPR_setFrame(larry_BOXING.spr_LARRY_BOXING,0);

            larry_BOXING.counter_HIT = 0;

            return;
        }



        larry_BOXING.counter_HIT += 1;
    }

    VDP_drawIntEx_BG_A_QUEUE(G_PHASE_SEQUENCE,1,0,0,PAL0);
}











