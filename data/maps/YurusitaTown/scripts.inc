YurusitaTown_MapScripts::
	.byte 0


YurusitaTown_Script_MeninaGasosa::
	createicons ICON_PLAYER_FEMALE, ICON_PLAYER_MALE
	updateicons R_ACTIVE
	msgbox YurusitaTown_Text_MeninaGasosa, MSGBOX_NPC
	destroyicons
	end


YurusitaTown_Script_MolequinNinja::
	gettime
	buffernumberstring 0, VAR_0x8000
	buffernumberstring 1, VAR_0x8001
	createicons ICON_PLAYER_FEMALE, ICON_PLAYER_MALE
	msgbox YurusitaTown_Text_MolequinNinja, MSGBOX_NPC
	destroyicons
	end


YurusitaTown_Script_Uepa::
	getpartysize
	compare VAR_RESULT, 1
	goto_if_lt YurusitaTown_Script_Uepa_2
YurusitaTown_Script_Uepa_1:
	release
	end

YurusitaTown_Script_Uepa_2:
	applymovement OBJ_EVENT_ID_PLAYER, YurusitaTown_Move_FaceUp
	waitmovement 0
	msgbox YurusitaTown_Text_Away, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, YurusitaTown_Move_Away
	waitmovement 0
	goto YurusitaTown_Script_Uepa_1


YurusitaTown_Move_FaceUp:
	emote_exclamation_mark
	face_up
	step_end

YurusitaTown_Move_Away:
	walk_left
	step_end

YurusitaTown_Script_CornoConformado::
	msgbox YurusitaTown_Script_CornoConformado_Text_0, MSGBOX_NPC
	end


YurusitaTown_Script_Guarda::
	getpartysize
	compare VAR_RESULT, 1
	goto_if_lt YurusitaTown_Script_Guarda_2
	msgbox YurusitaTown_Script_Guarda_Text_1, MSGBOX_NPC
YurusitaTown_Script_Guarda_1:
	applymovement 1, YurusitaTown_Move_Guarda
	waitmovement 0
	end

YurusitaTown_Script_Guarda_2:
	msgbox YurusitaTown_Script_Guarda_Text_0, MSGBOX_NPC
	goto YurusitaTown_Script_Guarda_1


YurusitaTown_Move_Guarda:
	face_down
	step_end

YurusitaTown_Script_Givepkm::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox YurusitaTown_Script_Givepkm_Text_0, MSGBOX_NPC
	special ChooseStarter
	waitstate
	end


YurusitaTown_Script_Sign::
	msgbox YurusitaTown_Script_Sign_Text_0, MSGBOX_SIGN
	end


YurusitaTown_Script_CornoConformado_Text_0:
	.string "minha mulher anda bastante com o\n"
	.string "vizinho, eles são muito amigos, ela até\l"
	.string "já dormiu na casa dele.\n"
	.string "Acho que vou dar um presente a ele por\l"
	.string "ser um amigo tão bom!$"

YurusitaTown_Script_Guarda_Text_0:
	.string "E aí {PLAYER}? Quer sair da cidade?\n"
	.string "Nem Pokémon tu tem limao.$"

YurusitaTown_Script_Guarda_Text_1:
	.string "Onde tu conseguiu isso?$"

YurusitaTown_Script_Givepkm_Text_0:
	.string "Aqui mlk, do jeito que tu pediu. Só\n"
	.string "escolhe um logo. Se não.... você sabe o\l"
	.string "que... Eu não quero ser preso agora.$"

YurusitaTown_Script_Sign_Text_0:
	.string "Vila de Yurusita,\n"
	.string "onde tudo começa.$"

YurusitaTown_Text_MeninaGasosa::
	.string "Steven: O Luiz é meu Deus.\n"
	.string "{PLAYER}: Concordo plenamente.$"

YurusitaTown_Text_MolequinNinja::
	.string "São {STR_VAR_1}:{STR_VAR_2}.$"

YurusitaTown_Text_Away::
	.string "Qual foi {PLAYER}?\n"
	.string "tu não pode sair ainda mlk\l"
	.string "não sou eu que faço as regras.$"
