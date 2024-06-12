#include <genesis.h>





#include "structures.h"
#include "variables.h"




#include "maps_CRACKERS.h"




void anim_CRACKERS_ROUND_1()
{
    if(G_COUNTER_1 == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 87)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 93)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 100)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 106)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 113)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 119)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 126)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 132)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 139)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 145)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 153)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 159)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 166)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 172)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 179)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 185)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 192)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 198)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 205)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 211)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 219)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 225)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 232)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 238)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 245)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 251)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }




    else if(G_COUNTER_1 == 311)
    {   
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_1 = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }


  
    G_COUNTER_1 += 1;
}


void anim_CRACKERS_ROUND_2()
{
    if(G_COUNTER_1 == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 87)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 93)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 100)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 106)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 113)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 119)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 126)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 132)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 139)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 145)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 153)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 159)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 166)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 172)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }



    else if(G_COUNTER_1 == 232)
    {
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_1 = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }




    G_COUNTER_1 += 1;

}


void anim_CRACKERS_ROUND_3()
{
    if(G_COUNTER_1 == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 87)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 93)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 100)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 106)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 113)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 119)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }




    else if(G_COUNTER_1 == 179)
    {
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_1 = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    



    G_COUNTER_1 += 1;

}


void anim_CRACKERS_ROUND_4()
{
    if(G_COUNTER_1 == 73)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 79)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 87)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B3.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B3.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A3.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A3.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
    }

    else if(G_COUNTER_1 == 93)
    {
        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_B2.tileset, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_B, image_CRACKERS_SCREEN_SPREAD_BG_B2.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B + image_CRACKERS_SCREEN_SPREAD_BG_B1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);

        VDP_loadTileSet(image_CRACKERS_SCREEN_SPREAD_BG_A2.tileset, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile, DMA_QUEUE);
        VDP_setTileMapEx(BG_A, image_CRACKERS_SCREEN_SPREAD_BG_A2.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_A + image_CRACKERS_SCREEN_SPREAD_BG_A1.tileset->numTile), 10, 15, 0, 0, 11, 9, DMA_QUEUE);
        }




    else if(G_COUNTER_1 == 153)
    {
        PAL_fadeOutAll(2,FALSE);
        
        G_COUNTER_1 = 0;

        // DEFINE NEXT MINIGAME //
        G_SCENE         = SCENE_FADE_OUT_CRACKERS;
        G_SCENE_TYPE    = SCENE_CRACKERS_MINIGAME;
        G_SCENE_NEXT    = SCENE_CRACKERS_MINIGAME;

        G_SCENE_LOADED  = FALSE;

        return;
    }
    



    G_COUNTER_1 += 1;

}








void (*TABLE_ANIM_CRACKERS[4])(void)        =   {
                                                    anim_CRACKERS_ROUND_1,
                                                    anim_CRACKERS_ROUND_2,
                                                    anim_CRACKERS_ROUND_3,
                                                    anim_CRACKERS_ROUND_4
                                                };








void sequence_CRACKERS_SCREEN()
{
    // POINTER DECLARATION //
    void (*ptr_INIT_CRACKERS_SCREEN)(void);

    // SETTING POINTER ON STREET INIT FUNCTION //
    ptr_INIT_CRACKERS_SCREEN = TABLE_ANIM_CRACKERS[G_ROUND_CRACKERS];

    // RUNNING STREET INIT FUNCTION //
    (*ptr_INIT_CRACKERS_SCREEN)();
}