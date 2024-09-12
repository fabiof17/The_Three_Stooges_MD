#include <genesis.h>




#include "maps_GLOBAL.h"
#include "maps_THE_END.h"




#include "palettes.h"




#include "variables.h"




void sequence_THE_END()
{
    if(G_INDEX_1 == 2)
    {
        // THREE STOOGES LOGO //
        if(G_COUNTER_1 == 97)
        {
            VDP_setTileMapEx(BG_B, image_THE_END.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 21, 8, 0, 28, 38, 12, DMA_QUEUE);
        }

        // CODING : FABIO //
        else if(G_COUNTER_1 == 214)
        {
            // CLEAR THREE STOOGES LOGO //
            VDP_setTileMapEx(BG_B, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, 0), 21, 8, 0, 0, 38, 12, DMA_QUEUE);

            VDP_setTileMapEx(BG_B, image_THE_END.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 37, 13, 0, 40, 6, 2, DMA_QUEUE);
        }

        // MEGADRIVE SCORE : CYBERDEOUS //
        else if(G_COUNTER_1 == 347)
        {
            VDP_setTileMapEx(BG_B, image_THE_END.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_B), 33, 13, 6, 40, 14, 2, DMA_QUEUE);
        }

        // THE END LOGO //
        else if(G_COUNTER_1 == 453)
        {
            VDP_setTileMapEx(BG_B, image_EMPTY_TILE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, 0), 33, 13, 0, 0, 14, 2, DMA_QUEUE);

            SPR_setPosition(sprite_THE_END_1,48,48);
            SPR_setPosition(sprite_THE_END_2,160,8);

            SPR_setPosition(sprite_CINEMAWARE,96,152);
        }


        else if(G_COUNTER_1 > 461)
        {           
            if(G_COUNTER_1%5 == TRUE)
            {
                if(G_POS_X_CAMERA_CURTAIN_1 != 0)
                {
                    G_POS_X_CAMERA_CURTAIN_1 += 1;
                }

                if(G_POS_X_CAMERA_CURTAIN_2 != 160)
                {
                    G_POS_X_CAMERA_CURTAIN_2 -= 1;
                }


                VDP_setHorizontalScrollVSync(BG_B, G_POS_X_CAMERA_CURTAIN_1);
                VDP_setHorizontalScrollVSync(BG_A, G_POS_X_CAMERA_CURTAIN_2);
            }
        }


        if(G_COUNTER_1 == 1270)
        {           
            PAL_setPalette(PAL0,palette_BLACK.data,DMA_QUEUE);
        }
    }



    //-----------------------------------------------------------//
    //                                                           //
    //                       STOOGES HEADS                       //
    //                                                           //
    //-----------------------------------------------------------//

    if(G_COUNTER_1 == 104)
    {
        if(G_INDEX_1 < 2)
        {
            // LARRY'S HEAD //
            if(G_INDEX_1 == 0)
            {
                PAL_setPalette(PAL0,palette_BLACK.data,DMA_QUEUE);

                VDP_loadTileSet(image_LARRY_HEAD.tileset, G_ADR_VRAM_BG_A, DMA_QUEUE);
                VDP_setTileMapEx(BG_B, image_LARRY_HEAD.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 34, 8, 0, 0, 10, 12, DMA_QUEUE);

                memcpy( &palette_64[0] , image_THE_END.palette->data , 16 * 2 );

                PAL_fadeInAll(palette_64, 30, FALSE);

                G_COUNTER_1 = 0;
            }

            // CURLY'S HEAD //
            else if(G_INDEX_1 == 1)
            {
                PAL_setPalette(PAL0,palette_BLACK.data,DMA_QUEUE);

                VDP_loadTileSet(image_CURLY_HEAD.tileset, G_ADR_VRAM_BG_A, DMA_QUEUE);
                VDP_setTileMapEx(BG_B, image_CURLY_HEAD.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, G_ADR_VRAM_BG_A), 34, 8, 0, 0, 10, 12, DMA_QUEUE);

                memcpy( &palette_64[0] , image_THE_END.palette->data , 16 * 2 );

                PAL_fadeInAll(palette_64, 30, FALSE);

                G_COUNTER_1 = 0;
            }

            G_INDEX_1 += 1;
        }
    }


    G_COUNTER_1 += 1;


    if(G_COUNTER_1 == 1272)
    {
        G_COUNTER_1 = 1271;
    }
}









