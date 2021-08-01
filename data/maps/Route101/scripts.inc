Route101_MapScripts::
	.byte 0


Route101_SignSlakurg::
	msgbox Route101_Sign_SlakurgText, MSGBOX_SIGN
	end


Route101_SignYurusita::
	msgbox Route101_Sign_YurusitaText, MSGBOX_SIGN
	end


Route101_Sign_SlakurgText::
	.string "ROUTE 101\n"
	.string "{RIGHT_ARROW} Slakurg town$"

Route101_Sign_YurusitaText::
	.string "ROUTE 101\n"
	.string "{LEFT_ARROW} Yurusita town$"
