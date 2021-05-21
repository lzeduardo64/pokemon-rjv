static const u32 smileyM[] = INCBIN_U32("graphics/mugshots/smiley/smiley.4bpp.lz");
static const u16 smileyMPal[] = INCBIN_U16("graphics/mugshots/smiley/smiley.gbapal");
static const u32 blehM[] = INCBIN_U32("graphics/mugshots/bleh/bleh.4bpp.lz");
static const u16 blehMPal[] = INCBIN_U16("graphics/mugshots/bleh/bleh.gbapal");
static const u32 may[] = INCBIN_U32("graphics/mugshots/may/may.4bpp.lz");
static const u16 mayPal[] = INCBIN_U16("graphics/mugshots/may/may.gbapal");

static const struct CompressedSpriteSheet gMugshotsTable[] = 
{
	MUGSHOT_SPRITE(ICON_PLAYER_MALE, smileyM),
	MUGSHOT_SPRITE(ICON_PLAYER_FEMALE, may),
	MUGSHOT_SPRITE(STEVEN_MUGSHOT, blehM),
};

static const struct SpritePalette gMugshotsPalTable[] = 
{
	MUGSHOT_PAL(ICON_PLAYER_MALE, smileyMPal),
	MUGSHOT_PAL(ICON_PLAYER_FEMALE, mayPal),
	MUGSHOT_PAL(STEVEN_MUGSHOT, blehMPal),
};
