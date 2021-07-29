.set LOCALID_MART_EMPLOYEE, 2
.set LOCALID_FOOTPRINTS_MAN, 3
.set LOCALID_RIVAL, 4

SlakurgTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

@to deixando esses comandos pq eu planejo fazer o mesmo na saida de cima ~vinicius

OldaleTown_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
@	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
@	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
@	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

SlakurgTown_EventScript_CitySign:: @ 81E8EEA
	msgbox SlakurgTown_Text_CitySign, MSGBOX_SIGN
	end

SlakurgTown_Text_CitySign:: @ 81E94DA
	.string "Slakurg City\n"
	.string "“A cidade da preguiça”$"


SlakurgTown_EventScript_NpcHouse:: @ 81E8EEA
	msgbox SlakurgTown_Text_NpcHouseSign, MSGBOX_SIGN
	end
	
SlakurgTown_Text_NpcHouseSign::
	.string "essa é uma casa de npc$"
	
SlakurgTown_EventScript_Hall:: @ 81E8EEA
	msgbox SlakurgTown_Text_NpcHallSign, MSGBOX_SIGN
	end
	
SlakurgTown_Text_NpcHallSign::
	.string "Aqui vai ser a prefeitura$"
	

