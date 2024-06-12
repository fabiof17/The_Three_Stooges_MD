#include <genesis.h>





#include "structures.h"
#include "variables.h"




#include "maps_CRACKERS.h"




//------------------------------------------------------------------//
//                                                                  //
//                     SPREAD SCREEN ANIMATIONS                     //
//                                                                  //
//------------------------------------------------------------------//

void anim_CRACKERS_SPREAD_1()
{
    if(G_COUNTER_CRACKERS == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 87)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 93)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 100)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 106)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 113)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 119)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 126)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 132)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 139)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 145)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 153)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 159)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 166)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 172)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 179)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 185)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 192)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 198)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 205)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 211)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 219)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 225)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 232)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 238)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 245)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 251)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }




    else if(G_COUNTER_CRACKERS == 311)
    {   
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_CRACKERS = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }


  
    G_COUNTER_CRACKERS += 1;
}


void anim_CRACKERS_SPREAD_2()
{
    if(G_COUNTER_CRACKERS == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 87)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 93)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 100)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 106)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 113)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 119)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 126)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 132)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 139)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 145)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 153)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 159)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 166)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 172)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }



    else if(G_COUNTER_CRACKERS == 232)
    {
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_CRACKERS = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }




    G_COUNTER_CRACKERS += 1;

}


void anim_CRACKERS_SPREAD_3()
{
    if(G_COUNTER_CRACKERS == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 87)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 93)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 100)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 106)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 113)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 119)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }




    else if(G_COUNTER_CRACKERS == 179)
    {
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_CRACKERS = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    



    G_COUNTER_CRACKERS += 1;

}


void anim_CRACKERS_SPREAD_4()
{
    if(G_COUNTER_CRACKERS == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 87)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_CRACKERS == 93)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
        }




    else if(G_COUNTER_CRACKERS == 153)
    {
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_CRACKERS = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    



    G_COUNTER_CRACKERS += 1;

}




void (*TABLE_ANIM_SPREAD_SCREEN[4])(void) =   {
                                                    anim_CRACKERS_SPREAD_1,
                                                    anim_CRACKERS_SPREAD_2,
                                                    anim_CRACKERS_SPREAD_3,
                                                    anim_CRACKERS_SPREAD_4
                                                };








//------------------------------------------------------------------//
//                                                                  //
//                    SURPRISE SCREENS ANIMATIONS                   //
//                                                                  //
//------------------------------------------------------------------//

void (*TABLE_ANIM_INTERMEDIATE_SCREEN[5])(void) =   {
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        NULL
                                                    };







void sequence_CRACKERS_SCREEN()
{
    //------------------------------------------------------------------//
    //                     SPREAD SCREEN ANIMATIONS                     //
    //------------------------------------------------------------------//
    if(G_CRACKERS_SCREEN_TYPE  == CRACKERS_SCREEN_SPREAD)
    {
        // POINTER DECLARATION //
        void (*ptr_INIT_CRACKERS_SCREEN)(void);

        // SETTING POINTER ON STREET INIT FUNCTION //
        ptr_INIT_CRACKERS_SCREEN = TABLE_ANIM_SPREAD_SCREEN[G_ROUND_CRACKERS];

        // RUNNING STREET INIT FUNCTION //
        (*ptr_INIT_CRACKERS_SCREEN)();
    }


    //------------------------------------------------------------------//
    //                     OTHER SCREENS ANIMATIONS                     //
    //------------------------------------------------------------------//
    /*else
    {
        // POINTER DECLARATION //
        void (*ptr_INIT_CRACKERS_SCREEN)(void);

        // SETTING POINTER ON STREET INIT FUNCTION //
        ptr_INIT_CRACKERS_SCREEN = TABLE_ANIM_INTERMEDIATE_SCREEN[G_CRACKERS_SCREEN_TYPE];

        // RUNNING STREET INIT FUNCTION //
        (*ptr_INIT_CRACKERS_SCREEN)();
    }*/
}