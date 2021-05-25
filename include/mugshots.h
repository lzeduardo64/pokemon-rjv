#ifndef GUARD_MUGSHOTS_H
#define GUARD_MUGSHOTS_H

#define MUG_SIZE 0x800

#define mugshotTag 40000

#define TINT_NOT_SPEAKING Q_8_8(0.95), Q_8_8(0.95), Q_8_8(0.95)

enum
{
	MUGSHOT_INVISIBLE = 0,
	MUGSHOT_NORMAL,
	MUGSHOT_BLACK,
};

void drawIcons(u8 left, u8 right);
void updateIcons(u8 left, u8 right);
void destroyIcons();

#endif
