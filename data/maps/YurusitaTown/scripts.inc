YurusitaTown_MapScripts::
	.byte 0

YurusitaTown_Script_MeninaGasosa::
		createicons ICON_PLAYER_FEMALE, ICON_PLAYER_MALE
		updateicons 0 @ n funciona ainda
        msgbox YurusitaTown_Text_MeninaGasosa, MSGBOX_NPC
        destroyicons
        createicons ICON_PLAYER_MALE, ICON_PLAYER_FEMALE
        updateicons 0 @ n funciona ainda
        msgbox YurusitaTown_Text_MeninaGasosa, MSGBOX_NPC
        destroyicons
        end

YurusitaTown_Text_MeninaGasosa::
	.string "Steven: O Luiz é meu Deus.\n"
	.string "{PLAYER}: Concordo plenamente.$"
	@.string "MEU DEUS!!!\n"
	@.string "essa menina tá mt boca suja\l"
	@.string "vo falar com a mãe dela!$"
	
YurusitaTown_Script_MolequinNinja::
	gettime
	buffernumberstring 0, VAR_0x8000
	msgbox YurusitaTown_Text_MolequinNinja, MSGBOX_NPC
	end
	
YurusitaTown_Text_MolequinNinja::
	.string "qual foi, {PLAYER}?\p"
	.string "hã? vai se fuder mlk.\n"
	.string "ainda te quebro na porrada.\p"
	.string "no meu relogio são {STR_VAR_1} horas, yey!$"

	
YurusitaTown_Script_Uepa::
	lock
	getpartysize
	compare VAR_RESULT, 1
	goto_if_le YurusitaTown_Script_MoveAway
	release
	end
	
YurusitaTown_Script_MoveAway::
	applymovement OBJ_EVENT_ID_PLAYER, YurusitaTown_Move_FaceUp
	waitmovement 0
	msgbox YurusitaTown_Text_Away, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, YurusitaTown_Move_Away
	waitmovement 0
	release
	end

YurusitaTown_Text_Away::
	.string "Qual foi {PLAYER}?\n"
	.string "tu não pode sair ainda mlk\l"
	.string "não sou eu que faço as regras.$"
	
YurusitaTown_Move_FaceUp::
	face_up
	step_end
	
YurusitaTown_Move_Away::
	walk_left
	step_end
	
YurusitaTown_Script_CornoConformado::
	msgbox YurusitaTown_Text_CornoConformado, MSGBOX_NPC
	end
	
YurusitaTown_Text_CornoConformado:
	.string "minha mulher anda bastante com o\n"
	.string "vizinho, eles são muito amigos,\p"
	.string "ela até já dormiu na casa dele.\p"
	.string "acho que vou dar um presente a \n"
	.string "ele por ser um amigo tão bom$"
	
YurusitaTown_Script_Guarda::
	msgbox YurusitaTown_Text_Guarda, MSGBOX_NPC
	applymovement 1, YurusitaTown_Move_Guarda
	waitmovement 0
	end
	
YurusitaTown_Text_Guarda::
	.string "E aí {PLAYER}?\n"
	.string "quer sair da cidade?.\l"
	.string "Limão. tu nem tem pokemon$"

YurusitaTown_Move_Guarda::
	face_down
	step_end

YurusitaTown_Script_Givepkm::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	special ChooseStarter
	waitstate
	@msgbox YurusitaTown_Text_Givepkm, MSGBOX_NPC
	@getpartysize
	@compare VAR_RESULT, 6
	@goto_if_eq LittlerootTown_Script_Fullptr
	@givemon SPECIES_TORCHIC, 5, ITEM_NONE
	end
	
YurusitaTown_Text_Givepkm::
	.string "Aqui mlk, do jeito que tu pediu.\n"
	.string "só escolhe um logo.\p"
	.string "se não.... você sabe o que...\n"
	.string "eu não quero ser preso agora.$"
	
YurusitaTown_Script_Fullptr::
	msgbox YurusitaTown_Text_Fullptr, MSGBOX_NPC
	end
	
YurusitaTown_Text_Fullptr::
	.string "Opa! Sua equipe esta cheia...$"
	
YurusitaTown_Script_Sign::
	msgbox YurusitaTown_Text_Sign, MSGBOX_SIGN
	end

YurusitaTown_Text_Sign::
	.string "Vila de Yurusita,\n"
	.string "onde tudo começa.$"
