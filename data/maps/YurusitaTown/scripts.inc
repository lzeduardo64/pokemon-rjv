LittlerootTown_MapScripts::
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
