YurusitaTown_MapScripts::
	.byte 0
	
LittlerootTown_Script_ESquisito::
	msgbox LittlerootTown_Text_ESquisito, MSGBOX_NPC
	end
	
LittlerootTown_Text_ESquisito::
	.string "vai se fuder, {PLAYER}!\n"
	.string "mlk um dia te deito na porrada.$"
	
LittlerootTown_Script_Uepa::
	lock
	msgbox LittlerootTown_Text_Away, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Move_Away
	waitmovement 0
	release
	end

LittlerootTown_Text_Away::
	.string "Essa area ainda nao ta pronta.\n"
	.string "Volte para dentro.$"
	
LittlerootTown_Move_Away::
	face_up
	walk_left
	step_end
	
LittlerootTown_Script_eita::
	msgbox LittlerootTown_Text_eita, MSGBOX_NPC
	end
	
LittlerootTown_Text_eita:
	.string "Fui entrar em casa e minha mulher\n"
	.string "tava com o vizinho.\p"
	.string "Eles ainda nao terminaram...$"
	
LittlerootTown_Script_Guarda::
	msgbox LittlerootTown_Text_Guarda, MSGBOX_NPC
	applymovement 1, LittlerootTown_Move_Guarda
	waitmovement 0
	end
	
LittlerootTown_Text_Guarda::
	.string "Imagina querer sair da cidade depois de\n"
	.string "apanhar pro Juca.\l"
	.string "Limao.$"

LittlerootTown_Move_Guarda::
	face_down
	step_end

LittlerootTown_Script_Givepkm::
	setflag FLAG_SYS_POKEMON_GET
	special ChooseStarter
	waitstate
	special HealPlayerParty
	@msgbox LittlerootTown_Text_Givepkm, MSGBOX_NPC
	@getpartysize
	@compare VAR_RESULT, 6
	@goto_if_eq LittlerootTown_Script_Fullptr
	@givemon SPECIES_TORCHIC, 5, ITEM_NONE
	end
	
LittlerootTown_Text_Givepkm::
	.string "Toma aqui esse pokemon.$"
	
LittlerootTown_Script_Fullptr::
	msgbox LittlerootTown_Text_Fullptr, MSGBOX_NPC
	end
	
LittlerootTown_Text_Fullptr::
	.string "Opa! Sua equipe esta cheia...$"
	
