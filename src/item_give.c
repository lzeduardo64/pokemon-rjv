#include "global.h"
#include "item.h"
#include "item_give.h"
#include "pokemon.h"

void ItemGive_Plate(struct Pokemon* mon, u8 state)
{
	u16 newSpecies;
	u16 species = GetMonData(mon, MON_DATA_SPECIES);
	u16 itemId; // needed in this case because of multiple plates
	switch(state)
	{
		case ITEM_GIVE:
			if (species == SPECIES_ARCEUS)
			{
				itemId = GetMonData(mon, MON_DATA_HELD_ITEM);
				newSpecies = ItemId_GetSecondaryId(itemId) < TYPE_MYSTERY ? SPECIES_ARCEUS_FIGHTING + ItemId_GetSecondaryId(itemId) - 1 : SPECIES_ARCEUS_FIGHTING + ItemId_GetSecondaryId(itemId) - 2;
				SetMonData(mon, MON_DATA_SPECIES, &newSpecies);
			}
			break;
		case ITEM_TAKE:
			if (SPECIES_ARCEUS_FIGHTING <= species && species <= SPECIES_ARCEUS_FAIRY)
			{
				newSpecies = SPECIES_ARCEUS;
				SetMonData(mon, MON_DATA_SPECIES, &newSpecies);
			}
			break;
	}
}
