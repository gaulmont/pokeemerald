Route111_OldLadysRestStop_MapScripts:: @ 822A916
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition: @ 822A91C
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_22A920:: @ 822A920
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_22A978, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_OldLadysRestStop_EventScript_22A941
	compare VAR_RESULT, 0
	goto_if_eq Route111_OldLadysRestStop_EventScript_22A96E
	end

Route111_OldLadysRestStop_EventScript_22A941:: @ 822A941
	msgbox Route111_OldLadysRestStop_Text_22A9EC, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_22AA16, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_OldLadysRestStop_EventScript_22A941
	compare VAR_RESULT, 0
	goto_if_eq Route111_OldLadysRestStop_EventScript_22A96E
	end

Route111_OldLadysRestStop_EventScript_22A96E:: @ 822A96E
	msgbox Route111_OldLadysRestStop_Text_22AA8F, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_22A978: @ 822A978
	.string "Oh, mon Dieu!\n"
	.string "Tes POKéMON doivent être épuisés!\p"
	.string "Si tu veux, tu peux les laisser se\n"
	.string "reposer ici. Bonne idée, non?$"

Route111_OldLadysRestStop_Text_22A9EC: @ 822A9EC
	.string "Tu as raison.\n"
	.string "Prends ton temps et repose-toi aussi!$"

Route111_OldLadysRestStop_Text_22AA16: @ 822AA16
	.string "Oh, mon Dieu!\n"
	.string "Tes POKéMON sont toujours fatigués?\p"
	.string "Tu devrais rester te reposer ici.\n"
	.string "Bonne idée, n'est-ce pas?$"

Route111_OldLadysRestStop_Text_22AA8F: @ 822AA8F
	.string "Vraiment?\n"
	.string "Ne sois pas timide.$"

