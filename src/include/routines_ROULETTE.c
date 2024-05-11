#include <genesis.h>


#include "outils.h"
#include "palettes.h"
#include "sound.h"
#include "structures.h"
#include "variables.h"



#include "maps_GLOBAL.h"
#include "maps_ROULETTE.h"


#include "sprites_GLOBAL.h"
#include "sprites_ROULETTE.h"


#include "tables_GLOBAL.h"
#include "tables_ROULETTE.h"



void fadeOut_ROULETTE()
{
    // FADE OUT : 40 FRAMES //
    PAL_fadeOutAll(40,FALSE);

    // RESET SCROLLING //
    VDP_setVerticalScroll(BG_B , 0);
    VDP_setVerticalScroll(BG_A , 0);

    // CLEAR PLANES //
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    // RELEASE ALL SPRITES //
    SPR_reset();

    // RANDOM QUESTION //
    G_SELECTED_QUESTION = random_NUMBER(0,9);

    G_COUNTER_ROULETTE      = 0;
    G_CURRENT_TURN          = 9;

    G_PHASE_SEQUENCE = 0;

    // DEFINE NEXT MINIGAME //
    G_SCENE         = SCENE_FADE_IN;
    G_SCENE_TYPE    = TABLE_MINIGAMES[G_SELECTED_ICON_ID];
    G_SCENE_NEXT    = TABLE_MINIGAMES[G_SELECTED_ICON_ID];

    G_SCENE_LOADED  = FALSE;
}




void init_HUB()
{
    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                LOADING ROULETTE TILES                                //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    // DRAW HUB //
    VDP_loadTileSet(image_ROULETTE_HUB.tileset, G_ADR_VRAM_HUB, CPU);
    VDP_setTileMapEx(BG_B, image_ROULETTE_HUB.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, G_ADR_VRAM_HUB), 1, 3, 0, 0, 38, 10, CPU);
    SYS_doVBlankProcess();

    // DRAW SLABS //
    VDP_loadTileSet(image_ROULETTE_SLAB.tileset, G_ADR_VRAM_HUB + image_ROULETTE_HUB.tileset->numTile, CPU);
    VDP_setTileMapEx(BG_B, image_ROULETTE_SLAB.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_HUB + image_ROULETTE_HUB.tileset->numTile), 2, 4, 0, 0, 36, 6, CPU);
    SYS_doVBlankProcess();

    // CLEAR BG_A AT HUB LOCATION //
    VDP_setTileMapEx(BG_A, image_ROULETTE_FILL.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, 0), 1,  3, 0, 0, 38, 10, CPU);
    SYS_doVBlankProcess();


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                  GENERATE ICONS IDS                                  //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    u16 i = 0;

    for(i=0 ; i<6 ; i++)
    {
        // WE STORE THE 6 ICONS ID //
        TABLE_GENERATED_ICONS[i] = TABLE_HIGHSTREET[G_HIGHSTREET_POSITION + i];
    }




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                 LOADING ICONS TILES                                  //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    G_ADR_VRAM_ICONS[0] = G_ADR_VRAM_HUB + image_ROULETTE_HUB.tileset->numTile + image_ROULETTE_SLAB.tileset->numTile;

    for(i=0 ; i<6 ; i++)
    {
        VDP_loadTileSet(TABLE_ICONS[TABLE_GENERATED_ICONS[i]]->tileset, G_ADR_VRAM_ICONS[i], CPU);
        VDP_setTileMapEx(BG_A, TABLE_ICONS[TABLE_GENERATED_ICONS[i]]->tilemap, TILE_ATTR_FULL(TABLE_ICONS_PALETTE_[TABLE_GENERATED_ICONS[i]], TRUE, FALSE, FALSE, G_ADR_VRAM_ICONS[i]), 2 + (i*6), 4, 0, 0, 6, 6, CPU);

        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                  BANKER ICON SPRITE                                  //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        // EDGE CASE //
        // BANKER ICON NEEDS A SPRITE TO BE FULLY DISPLAYED //
        if(TABLE_GENERATED_ICONS[i] == ICON_BANKER)
        {
            sprite_ICON_BANKER = SPR_addSprite(&tiles_SPR_ICON_BANKER,  16 + (i*48), 32 - G_POS_Y_CAMERA, TILE_ATTR(PAL3, TRUE, FALSE, FALSE)); // -95 , 142
        }

        if(i < 5)
        {
            G_ADR_VRAM_ICONS[i+1] = G_ADR_VRAM_ICONS[i] + TABLE_ICONS[TABLE_GENERATED_ICONS[i]]->tileset->numTile;
        } 
    }


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                      PRINT TEXT                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    // DAY //
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 36), 4 , 11 , 0, 0, 1, 1, CPU);
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 33), 5 , 11 , 0, 0, 1, 1, CPU);
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 57), 6 , 11 , 0, 0, 1, 1, CPU);

    // PRINT DAY NUMBER //
    if(G_DAY < 10)
    {
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + G_DAY), 8 , 11 , 0, 0, 1, 1, CPU);
    }
    else
    {
        u8 number1 = G_DAY / 10;
        u8 number2 = G_DAY - (number1*10);

        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 8 , 11 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 9 , 11 , 0, 0, 1, 1, CPU);

    }
    

    // READY? //
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 50), 18 , 11 , 0, 0, 1, 1, CPU);
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 37), 19 , 11 , 0, 0, 1, 1, CPU);
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 33), 20 , 11 , 0, 0, 1, 1, CPU);
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 36), 21 , 11 , 0, 0, 1, 1, CPU);
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 57), 22 , 11 , 0, 0, 1, 1, CPU);
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 31), 23 , 11 , 0, 0, 1, 1, CPU);


    // DOLLAR SYMBOL //
    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 4), 31 , 11 , 0, 0, 1, 1, CPU);

    // MONEY AMOUNT //
    if(G_MONEY < 10)
    {
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + G_MONEY), 32 , 11 , 0, 0, 1, 1, CPU);
    }

    else if(G_MONEY < 100)
    {
        u8 number1 = G_MONEY / 10;
        u8 number2 = G_MONEY - (number1*10);

        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 32 , 11 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 33 , 11 , 0, 0, 1, 1, CPU);
    }

    else if(G_MONEY < 1000)
    {
        u8 number1 = G_MONEY / 100;
        u8 number2 = (G_MONEY - (number1*100)) / 10;
        u8 number3 = G_MONEY - (number1*100) - (number2*10);

        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 32 , 11 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 33 , 11 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number3), 34 , 11 , 0, 0, 1, 1, CPU);
    }

    else
    {
        u8 number1 = G_MONEY / 1000;
        u8 number2 = (G_MONEY - (number1*1000)) / 100;
        u8 number3 = (G_MONEY - (number1*1000) - (number2*100)) / 10;
        u8 number4 = G_MONEY - (number1*1000) - (number2*100) - (number3*10);

        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number1), 32 , 11 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number2), 33 , 11 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number3), 34 , 11 , 0, 0, 1, 1, CPU);
        VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + number4), 35 , 11 , 0, 0, 1, 1, CPU);
    }


    //**************************************************************************************//
    //                                                                                      //
    //                                      SPRITES                                         //
    //                                                                                      //
    //**************************************************************************************// 

    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                     HAND SPRITE                                      //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    sprite_HAND_ROULETTE = SPR_addSprite(&tiles_SPR_HAND,  -48, 56, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));
    SPR_setAnim(sprite_HAND_ROULETTE , G_FINGER_NUMBER - 1);
    SPR_setZ(sprite_HAND_ROULETTE  ,0);


    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                     ARROW SPRITE                                     //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    sprite_ARROW = SPR_addSprite(&tiles_SPR_ARROW,  125, 104, TILE_ATTR(PAL3, TRUE, FALSE, FALSE));


    SPR_update();
    SYS_doVBlankProcess();




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                       PALETTES                                       //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    //memcpy( &palette_64[0]  , palette_BLACK.data                        , 16 * 2 );
    //memcpy( &palette_64[16] , palette_BLACK.data                        , 16 * 2 );
    memcpy( &palette_64[32] , palette_ROULETTE_ICONS.data               , 16 * 2 );
    memcpy( &palette_64[48] , palette_SPR_STOOGES.data                  , 16 * 2 );




    //--------------------------------------------------------------------------------------//
    //                                                                                      //
    //                                         AUDIO                                        //
    //                                                                                      //
    //--------------------------------------------------------------------------------------//

    XGM_setPCM(SOUND_HAND, PCM_HAND, sizeof(PCM_HAND));
}


inline static void clear_HUB()
{
    VDP_setVerticalScrollVSync(BG_B , 224);
    VDP_setVerticalScrollVSync(BG_A , 224);

    SPR_releaseSprite(sprite_HAND_ROULETTE);
    SPR_releaseSprite(sprite_ARROW);

    sprite_HAND_ROULETTE     = NULL;
    sprite_ARROW    = NULL;

    if(sprite_ICON_BANKER != NULL)
    {
        SPR_releaseSprite(sprite_ICON_BANKER);
        sprite_ICON_BANKER = NULL;
    }

}




inline static void wait_PLAYER_CHOICE()
{
    // WE INIT HAND AT FIRST POSITION //
    if(G_COUNTER_ROULETTE == 0)
    {
        // DISPLAY HAND //
        s16 pos_X_HAND = TABLE_GENERATED_HAND_POSITION[G_CURRENT_TURN];
        SPR_setPosition( sprite_HAND_ROULETTE , 16 + (pos_X_HAND * 48) , 48 );

        // CHANGE STOOGES FRAME //
        SPR_setFrame(sprite_STOOGES,TABLE_ANIM_STOOGE_ROULETTE[G_CURRENT_TURN]);

        // PLAY HAND SOUND //
        XGM_startPlayPCM(SOUND_HAND,15,SOUND_PCM_CH4);
    }
    
    else if(G_COUNTER_ROULETTE == G_HAND_SPEED)
    {
        // NEXT TURN //
        if(G_CURRENT_TURN > 0)
        {
            G_CURRENT_TURN -= 1;

            // REINIT COUNTER //
            G_COUNTER_ROULETTE = 0;

            // CHANGE STOOGES FRAME //
            SPR_setFrame(sprite_STOOGES,TABLE_ANIM_STOOGE_ROULETTE[G_CURRENT_TURN]);

            // MOVE HAND //
            s16 pos_X_HAND = TABLE_GENERATED_HAND_POSITION[G_CURRENT_TURN];
            SPR_setPosition( sprite_HAND_ROULETTE , 16 + (pos_X_HAND * 48) , 48 );

            // DISPLAY TURN NUMBER //
            VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + G_CURRENT_TURN), 21 , 11 , 0, 0, 1, 1, CPU);

            // PLAY HAND SOUND //
            XGM_startPlayPCM(SOUND_HAND,15,SOUND_PCM_CH4);

            return;
        }
        
        // NO MORE TURN //
        else
        {
            // REINIT COUNTER //
            G_COUNTER_ROULETTE = 0;

            // GET SELECTED ICON ID //
            G_SELECTED_ICON_ID = TABLE_GENERATED_ICONS[TABLE_GENERATED_HAND_POSITION[G_CURRENT_TURN]];

            //VDP_drawInt(G_SELECTED_ICON_ID,1,0,0);
            
            // ICON SELECTED //
            G_PHASE_SEQUENCE = ROULETTE_PHASE_VALIDATED;

            return ;
        }        
    }

    G_COUNTER_ROULETTE += 1;
}


inline static void anim_WALKOUT()
{
    // STOOGES ANIMATION //
    // SETUP POINTER TO STOOGES ANIMATION TABLE //
    const struct_WALK_STOOGES_ *ptr_ANIM_STOOGES = &TABLE_ANIM_STOOGES_WALKOUT[G_INDEX_3];

    if(G_COUNTER_ROULETTE == ptr_ANIM_STOOGES->num_FRAME)
    {
        // CHANGING SPRITE ANIMATION FRAME //
        SPR_setFrame( sprite_STOOGES , ptr_ANIM_STOOGES->index_SPRITE_FRAME );

        // RETRIEVE X POSITION FROM TABLE //
        SPR_setPosition( sprite_STOOGES , ptr_ANIM_STOOGES->pos_X , 133 );


        // UPDATE INDEX IN STOOGES ANIMATION TABLE //
        // UP TO 28 (LAST INDEX IN ARRAY OF 29 ENTRIES) //
        if(G_INDEX_3 < 28)
        {
            G_INDEX_3 += 1;
        }
    }

    // FADE OUT //
    if(G_COUNTER_ROULETTE == 337)
    {
        // COUNTERS RESET //
        G_COUNTER_ROULETTE      = 0;
        G_INDEX_1               = 0;
        G_INDEX_2               = 0;
        G_INDEX_3               = 0;

        
        // GO TO FADE OUT SEQUENCE //
        G_SCENE     = SCENE_FADE_OUT;

        return;
    }


    G_COUNTER_ROULETTE += 1;
}









void sequence_ROULETTE()
{
    if(G_PHASE_SEQUENCE == ROULETTE_PHASE_READY)
    {
        if(G_COUNTER_ROULETTE == 0)
        {
            SPR_setPosition(sprite_ARROW , 125 , 104 );

            SPR_setFrame(sprite_STOOGES , 18);
        }

        // WAIT 95 FRAMES BEFORE HAND APPEARS //
        else if(G_COUNTER_ROULETTE == 95)
        {
            // CLEAR READY? //
            VDP_setTileMapEx(BG_A, image_ROULETTE_FILL.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, 0), 18, 11, 0, 0, 6, 1, DMA);

            // DISPLAY TURN NUMBER //
            VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, TILE_FONT_INDEX + 16 + G_CURRENT_TURN), 21 , 11 , 0, 0, 1, 1, CPU);

            // REINIT COUNTER //
            G_COUNTER_ROULETTE = 0;
            
            // GO TO CHOICE PHASE //
            G_PHASE_SEQUENCE = ROULETTE_PHASE_CHOICE;

            return;
        }

        G_COUNTER_ROULETTE += 1;
    }


    else if(G_PHASE_SEQUENCE == ROULETTE_PHASE_CHOICE)
    {
        wait_PLAYER_CHOICE();
    }


    else if(G_PHASE_SEQUENCE == ROULETTE_PHASE_VALIDATED)
    {
        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                 SWATTER ICON SELECTED                                //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        if(G_SELECTED_ICON_ID == ICON_SWATTER)
        {
            if(G_COUNTER_ROULETTE == 0)
            {
                // LOAD TRIGERRED SWATTER TILES FOR CURRENT ICON //
                VDP_loadTileSet(image_ICON_SWATTER_2.tileset, G_ADR_VRAM_ICONS[TABLE_GENERATED_HAND_POSITION[G_CURRENT_TURN]], DMA);
                
                // CHANGE HAND FRAME (CAUGHT) //
                SPR_setFrame( sprite_HAND_ROULETTE , 1);

                // PLAY SWATTER SOUND //
                XGM_startPlayPCM(SOUND_SWATTER,15,SOUND_PCM_CH4);

            }

            else if(G_COUNTER_ROULETTE == 180)
            {
                //--------------------------------------------------------------------------------------//
                //                       IF HAND HAS MORE THAN 1 REMAINING FINGER                       //
                //--------------------------------------------------------------------------------------//

                if(G_FINGER_NUMBER > 1)
                {
                    // LOAD REARMED SWATTER TILES FOR CURRENT ICON //
                    VDP_loadTileSet(image_ICON_SWATTER.tileset, G_ADR_VRAM_ICONS[TABLE_GENERATED_HAND_POSITION[G_CURRENT_TURN]], DMA);
                    

                    // GENERATE NEW HAND MOVE SEQUENCE //
                    generate_RANDOM_HAND_MOVE_SWATTER();


                    // RESET TURN NUMBER //
                    G_CURRENT_TURN = 9;




                    // PLAYER LOSE 1 FINGER //
                    G_FINGER_NUMBER -= 1;

                    // UPDATE HAND SPRITE WITH 1 FINGER LESS //
                    SPR_setAnim(sprite_HAND_ROULETTE , G_FINGER_NUMBER - 1);

                    // HAND RELEASED //
                    SPR_setFrame(sprite_HAND_ROULETTE , 0);

                    // SET HAND POSITION AT 1RST POSITION IN SEQUENCE //
                    s16 pos_X_HAND = TABLE_GENERATED_HAND_POSITION[G_CURRENT_TURN];
                    SPR_setPosition( sprite_HAND_ROULETTE , 16 + (pos_X_HAND * 48) , 48 );

                    

                    //--------------------------------------------------------------------------------------//
                    //                                      UPDATE HUB                                      //
                    //--------------------------------------------------------------------------------------//

                    // DISPLAY TURN NUMBER //
                    VDP_setTileMapEx(BG_A, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, TILE_FONT_INDEX + 16 + G_CURRENT_TURN), 21 , 11 , 0, 0, 1, 1, CPU);




                    // REINIT COUNTER //
                    G_COUNTER_ROULETTE = 0;

                    // GO TO HAND MOVING SEQUENCE //
                    G_PHASE_SEQUENCE = ROULETTE_PHASE_CHOICE;

                }




                //--------------------------------------------------------------------------------------//
                //                          IF HAND HAS ONLY 1 REMAINING FINGER                         //
                //--------------------------------------------------------------------------------------//

                else
                {
                    // GAME OVER //
                }

                return;
            }
        }


        //--------------------------------------------------------------------------------------//
        //                                                                                      //
        //                                ANY OTHER ICON SELECTED                               //
        //                                                                                      //
        //--------------------------------------------------------------------------------------//

        else
        {
            if(G_COUNTER_ROULETTE == 180)
            {
                clear_HUB();

                // PLAY VOICE //
                XGM_startPlayPCM(SOUND_WALKOUT,15,SOUND_PCM_CH4);
            }
            
            // WAIT 3 SECONDS //
            else if(G_COUNTER_ROULETTE == 300)
            {
                /// PLAY MUSIC //
                //XGM_startPlayPCM(MUSIC_ROULETTE,15,SOUND_PCM_CH4);

                // REINIT COUNTER //
                G_COUNTER_ROULETTE = 0;

                G_PHASE_SEQUENCE   = ROULETTE_PHASE_WALKOUT;
                
                return ;
            }
        }
        
        G_COUNTER_ROULETTE += 1;
    }


    else if(G_PHASE_SEQUENCE == ROULETTE_PHASE_WALKOUT)
    {
        anim_WALKOUT();
    }

}









