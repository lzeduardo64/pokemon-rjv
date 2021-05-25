#include "global.h"
#include "mugshots.h"
#include "sprite.h"
#include "decompress.h"
#include "palette.h"
#include "day_night.h"
#include "constants/mugshots.h"

#define MUGSHOT_SPRITE(id, data) [id] = { data, MUG_SIZE, mugshotTag + id }
#define MUGSHOT_PAL(id, data) [id] = { data, mugshotTag + id }

#include "data/graphics/mugshots.h"

static const struct OamData LeftActive =
{
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 0,
	.matrixNum = 0, // scale
};

static const struct OamData LeftInactive =
{
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 0,
    .matrixNum = 0, // scale
};

static const struct OamData RightActive =
{
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 0,
    .matrixNum = 8,
};

static const struct OamData RightInactive =
{
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 0,
    .matrixNum = 8, // scale and vflip
};

static const union AffineAnimCmd scale[] = 
{ 
	AFFINEANIMCMD_FRAME(2, 3, 0, 1),
	AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const Anim[] = 
{
	scale,
};

static EWRAM_DATA struct SpriteTemplate template = {};
static EWRAM_DATA u8 id[2];
static EWRAM_DATA u8 loadedID[2];

static void MugshotSpriteCallback(struct Sprite*);

#define rID id[1]
#define lID id[0]

void drawIcons(u8 left, u8 right)
{
	template.images = NULL;
    template.affineAnims = Anim;
    template.callback = SpriteCallbackDummy;
    template.anims = gDummySpriteAnimTable;
    
    left = left == ICON_PLAYER ? gSaveBlock2Ptr->playerGender : left;
    right = right == ICON_PLAYER ? gSaveBlock2Ptr->playerGender : right;

	template.oam = &LeftActive;
	template.tileTag = gMugshotsTable[left].tag;
	template.paletteTag = gMugshotsPalTable[left].tag;
	LoadCompressedSpriteSheet(&gMugshotsTable[left]);
	LoadSpritePalette(&gMugshotsPalTable[left]);
	lID = CreateSprite(&template, 32, 83, 0);

	template.oam = &RightActive;
	template.tileTag = gMugshotsTable[right].tag;
	template.paletteTag = gMugshotsPalTable[right].tag;
	LoadCompressedSpriteSheet(&gMugshotsTable[right]);
	LoadSpritePalette(&gMugshotsPalTable[right]);
	rID = CreateSprite(&template, 204, 83, 0);
	
	loadedID[0] = left;
	loadedID[1] = right;
}

void updateIcons(u8 left, u8 right)
{
	u16 pal[16];
	u8 index;

	index = IndexOfSpritePaletteTag(gSprites[lID].template->paletteTag);
	memcpy(pal, gMugshotsPalTable[loadedID[0]].data, 32);
	TintPalette_GrayScale2(pal, 16);
	LoadPalette(pal, 16 * index - 16 + 0x100, 32);
	

	/*rIndex = IndexOfSpritePaletteTag(gSprites[rID].template->paletteTag);
	GetPalette(rPal, 16 * rIndex + 0x100, 32);
	TintPalette_GrayScale2(rPal, 16);
	LoadPalette(rPal, 16 * rIndex + 0x100, 32);*/
	
}

void destroyIcons()
{
	DestroySpriteAndFreeResources(&gSprites[id[0]]);
	DestroySpriteAndFreeResources(&gSprites[id[1]]);
}

static void MugshotSpriteCallback(struct Sprite* sprite)
{
	if (sprite->animEnded)
	{
	
	}
}
