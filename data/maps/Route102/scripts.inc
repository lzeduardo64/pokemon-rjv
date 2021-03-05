Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_Baixin, MSGBOX_NPC
	end

Route102_Text_Baixin:
	.string "Eu não sou muito alto, então eu só\n"
	.string "afundo na grama alta.\p"
	.string "a grama para no meu nariz e... e..\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_EventScript_RouteSignSlakurg::
	msgbox Route102_Text_RouteSignSlakurg, MSGBOX_SIGN
	end

Route102_Text_RouteSignSlakurg:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} Slakurg City$"

Route102_EventScript_RouteSignYurusita:: 
	msgbox Route102_Text_RouteSignYurusita, MSGBOX_SIGN
	end

Route102_Text_RouteSignYurusita: 
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} Vila de Yurusita$"

Route102_EventScript_Tiozin::
	msgbox Route102_Text_VoPegarPokemonPaCarai:, MSGBOX_NPC
	end

Route102_Text_VoPegarPokemonPaCarai:
	.string "Eu vô pegar um montão de\n"
	.string "pokémon, anota aí.$"

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana:: @ 81EC1CA
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen:: @ 81EC1E1
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon: @ 81EC1F8
	.string "WALLY: {PLAYER}…\n"
	.string "Os pokemons se escondem na grama,\l"
	.string "bem por aqui né?\p"
	.string "Por favor, veja se eu consigo\n"
	.string "pegar um direito\p"
	.string "Ah!$"

Route102_Text_WallyIDidIt: @ 81EC271
	.string "WALLY: Eu consegui!!! é....\n"
	.string "é o meu primeiro pokemon$"

Route102_Text_LetsGoBack: @ 81EC297
	.string "{PLAYER}, Obrigado!\n"
	.string "Vamos voltar à cidade$"

