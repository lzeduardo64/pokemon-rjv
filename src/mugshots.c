#include "global.h"
#include "mugshots.h"
#include "sprite.h"
#include "decompress.h"
#include "palette.h"
#include "day_night.h"
#include "constants/mugshots.h"
#include "constants/rgb.h"
#include "util.h"

#define MUGSHOT_SPRITE(id, data) [id] = { data, MUG_SIZE, mugshotTag + id }
#define MUGSHOT_PAL(id, data) [id] = { data, mugshotTag + id }

#include "data/graphics/mugshots.h"

static const struct OamData MugshotOam =
{
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 0,
	.matrixNum = 0, // scale
};

static EWRAM_DATA struct SpriteTemplate template = {};
static EWRAM_DATA u8 id[2];
static EWRAM_DATA u8 loadedID[2];

static void restoreSprite(u8 id, u8 loaded);

#define rID id[1]
#define lID id[0]

void drawIcons(u8 left, u8 right)
{
	u8 leftToLoad, rightToLoad;
	template.images = NULL;
    template.affineAnims = NULL;
    template.callback = SpriteCallbackDummy;
    template.anims = gDummySpriteAnimTable;
    template.oam = &MugshotOam;

    leftToLoad = left == ICON_PLAYER ? gSaveBlock2Ptr->playerGender : left;
    rightToLoad = right == ICON_PLAYER ? gSaveBlock2Ptr->playerGender : right;

	template.tileTag = gMugshotsTable[left].tag;
	template.paletteTag = gMugshotsPalTable[left].tag;
	LoadCompressedSpriteSheet(&gMugshotsTable[left]);
	LoadSpritePalette(&gMugshotsPalTable[left]);
	lID = CreateSprite(&template, 32, 83, 0);

	template.tileTag = gMugshotsTable[right].tag;
	template.paletteTag = gMugshotsPalTable[right].tag;
	LoadCompressedSpriteSheet(&gMugshotsTable[right]);
	LoadSpritePalette(&gMugshotsPalTable[right]);
	rID = CreateSprite(&template, 204, 83, 0);
	gSprites[rID].oam.matrixNum = 8;

	loadedID[0] = leftToLoad;
	loadedID[1] = rightToLoad;
}

void updateIcons(u8 state)
{	
	switch (state)
	{
		case R_ACTIVE:
			BlendPalette_Grayscale(IndexOfSpritePaletteTag(gSprites[lID].template->paletteTag) * 16 + 0x100, 16);
			restoreSprite(rID, loadedID[1]);
			break;
		case L_ACTIVE:
			restoreSprite(lID, loadedID[0]);
			BlendPalette_Grayscale(IndexOfSpritePaletteTag(gSprites[rID].template->paletteTag) * 16 + 0x100, 16);
			break;
		case RL_ACTIVE:
			restoreSprite(lID, loadedID[0]);
			restoreSprite(rID, loadedID[1]);
			break;
		default:
			BlendPalette_Grayscale(IndexOfSpritePaletteTag(gSprites[lID].template->paletteTag) * 16 + 0x100, 16);
			BlendPalette_Grayscale(IndexOfSpritePaletteTag(gSprites[rID].template->paletteTag) * 16 + 0x100, 16);
	}
}

void destroyIcons()
{
	DestroySpriteAndFreeResources(&gSprites[id[0]]);
	DestroySpriteAndFreeResources(&gSprites[id[1]]);
}

static void restoreSprite(u8 id, u8 loaded)
{
	u16 palette[16];
	u16 index;
	index = IndexOfSpritePaletteTag(gSprites[id].template->paletteTag) * 16;
	
	memcpy(palette, gMugshotsPalTable[loaded].data, 32);
	LoadPalette(palette, index, 32);
}
