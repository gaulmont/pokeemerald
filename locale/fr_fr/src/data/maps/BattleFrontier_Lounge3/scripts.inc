BattleFrontier_Lounge3_MapScripts:: @ 8261D82
	.byte 0

BattleFrontier_Lounge3_EventScript_261D83:: @ 8261D83
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_BETTOR, BattleFrontier_Lounge3_EventScript_261EF9
	call BattleFrontier_Lounge3_EventScript_261EA0
	compare VAR_0x8004, 2
	goto_if_le BattleFrontier_Lounge3_EventScript_261EEB
	setflag FLAG_MET_BATTLE_FRONTIER_BETTOR
	msgbox BattleFrontier_Lounge3_Text_262061, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261DAF
	end

BattleFrontier_Lounge3_EventScript_261DAF:: @ 8261DAF
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_262A60, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge3_EventScript_261FA5
	msgbox BattleFrontier_Lounge3_Text_262ABD, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge3_EventScript_261FA5
	message BattleFrontier_Lounge3_Text_262B42
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_261DE9
	end

BattleFrontier_Lounge3_EventScript_261DE9:: @ 8261DE9
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, 0
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_261E30
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_261E3B
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_261E46
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_261FAF
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_261FAF
	end

BattleFrontier_Lounge3_EventScript_261E30:: @ 8261E30
	setvar VAR_0x8008, 5
	goto BattleFrontier_Lounge3_EventScript_261E51
	end

BattleFrontier_Lounge3_EventScript_261E3B:: @ 8261E3B
	setvar VAR_0x8008, 10
	goto BattleFrontier_Lounge3_EventScript_261E51
	end

BattleFrontier_Lounge3_EventScript_261E46:: @ 8261E46
	setvar VAR_0x8008, 15
	goto BattleFrontier_Lounge3_EventScript_261E51
	end

BattleFrontier_Lounge3_EventScript_261E51:: @ 8261E51
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge BattleFrontier_Lounge3_EventScript_261E75
	msgbox BattleFrontier_Lounge3_Text_262B6E, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_262B42
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_261DE9
	end

BattleFrontier_Lounge3_EventScript_261E75:: @ 8261E75
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_REGI
	msgbox BattleFrontier_Lounge3_Text_262BE0, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261E96
	end

BattleFrontier_Lounge3_EventScript_261E96:: @ 8261E96
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_261EA0:: @ 8261EA0
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_261EE5
	return

BattleFrontier_Lounge3_EventScript_261EE5:: @ 8261EE5
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_261EEB:: @ 8261EEB
	msgbox BattleFrontier_Lounge3_Text_261FFE, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261EF9:: @ 8261EF9
	msgbox BattleFrontier_Lounge3_Text_26346B, MSGBOX_DEFAULT
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	goto_if_ge BattleFrontier_Lounge3_EventScript_261F12
	goto BattleFrontier_Lounge3_EventScript_261DAF
	end

BattleFrontier_Lounge3_EventScript_261F12:: @ 8261F12
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	goto_if_eq BattleFrontier_Lounge3_EventScript_261F9E
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON
	goto_if_eq BattleFrontier_Lounge3_EventScript_261F2E
	goto BattleFrontier_Lounge3_EventScript_261F71
	end

BattleFrontier_Lounge3_EventScript_261F2E:: @ 8261F2E
	msgbox BattleFrontier_Lounge3_Text_263334, MSGBOX_DEFAULT
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5
	call_if_eq BattleFrontier_Lounge3_EventScript_261F80
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10
	call_if_eq BattleFrontier_Lounge3_EventScript_261F8A
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15
	call_if_eq BattleFrontier_Lounge3_EventScript_261F94
	msgbox BattleFrontier_Lounge3_Text_2633D4, 9
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_2633F2, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_261F71:: @ 8261F71
	msgbox BattleFrontier_Lounge3_Text_263298, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_261F80:: @ 8261F80
	buffernumberstring 0, 10
	setvar VAR_0x8004, 10
	return

BattleFrontier_Lounge3_EventScript_261F8A:: @ 8261F8A
	buffernumberstring 0, 20
	setvar VAR_0x8004, 20
	return

BattleFrontier_Lounge3_EventScript_261F94:: @ 8261F94
	buffernumberstring 0, 30
	setvar VAR_0x8004, 30
	return

BattleFrontier_Lounge3_EventScript_261F9E:: @ 8261F9E
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_261FA5:: @ 8261FA5
	msgbox BattleFrontier_Lounge3_Text_26342D, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_261FAF:: @ 8261FAF
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_261FA5
	end

BattleFrontier_Lounge3_EventScript_261FB8:: @ 8261FB8
	msgbox BattleFrontier_Lounge3_Text_263545, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_261FC1:: @ 8261FC1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_26346F, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FD1:: @ 8261FD1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_26351D, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FE1:: @ 8261FE1
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_2634C9, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_261FF1
	end

BattleFrontier_Lounge3_EventScript_261FF1:: @ 8261FF1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_261FFE:: @ 8261FFE
	.string "Qu'est-ce que tu veux?\p"
	.string "Nous sommes occupés.\n"
	.string "Tu ne peux pas revenir plus tard?$"

BattleFrontier_Lounge3_Text_262061:: @ 8262061
	.string "…\n"
	.string "Tu as l'air d'être un bon DRESSEUR.\p"
	.string "Hé, hé…\n"
	.string "J'ai quelque chose à te proposer.\p"
	.string "On est un petit groupe et on joue\n"
	.string "à un petit jeu ici. On mise sur ce qui\l"
	.string "se passe à la ZONE DE COMBAT.\p"
	.string "Les règles sont simples.\p"
	.string "D'abord, on choisit un des bâtiments\n"
	.string "de la ZONE DE COMBAT.\p"
	.string "Ensuite, on choisit chacun un DRESSEUR\n"
	.string "qui relève le défi de ce bâtiment et on\l"
	.string "mise des POINTS DE COMBAT dessus.\p"
	.string "Celui qui a misé sur le DRESSEUR qui\n"
	.string "fait le meilleur score récolte tous les\l"
	.string "POINTS DE COMBAT mis en jeu.\p"
	.string "Plutôt simple, non?\n"
	.string "De toute façon…$"

BattleFrontier_Lounge3_Text_262261:: @ 8262261
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des SALLES DE COMBAT SOLO\l"
	.string "de la TOUR DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_26230D:: @ 826230D
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des SALLES DE COMBAT DUO\l"
	.string "de la TOUR DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_2623B9:: @ 82623B9
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des SALLES DE COMBAT MULTI\l"
	.string "de la TOUR DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_262464:: @ 8262464
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI DE COMBAT\l"
	.string "SOLO du DOME DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_26250E:: @ 826250E
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI DE COMBAT\l"
	.string "DUO du DOME DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_2625B8:: @ 82625B8
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI COMBAT\l"
	.string "ECHANGE SOLO de l'USINE DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_26266A:: @ 826266A
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI COMBAT\l"
	.string "ECHANGE DUO de l'USINE DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_26271C:: @ 826271C
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des HALLS DE COMBAT SOLO\l"
	.string "du PALACE DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_2627C9:: @ 82627C9
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des HALLS DE COMBAT DUO\l"
	.string "du PALACE DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_262876:: @ 8262876
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI K.O. du\l"
	.string "DOJO DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_26291A:: @ 826291A
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi du COMBAT HASARD\l"
	.string "au REPTILE DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_2629BC:: @ 82629BC
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi du COMBAT QUETE\l"
	.string "dans la PYRAMIDE DE COMBAT.\p"
	.string "Mais je n'ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_262A60:: @ 8262A60
	.string "Bien sûr, tu ne feras pas ça pour rien.\n"
	.string "Qu'est-ce que tu en dis?\l"
	.string "Tu veux bien être ce DRESSEUR?$"

BattleFrontier_Lounge3_Text_262ABD:: @ 8262ABD
	.string "Très bien. Parfait.\n"
	.string "Heu… Tu veux bien me prêter\l"
	.string "quelques POINTS DE COMBAT?\p"
	.string "Fais-moi confiance, je te remercierai\n"
	.string "comme il se doit.$"

BattleFrontier_Lounge3_Text_262B42:: @ 8262B42
	.string "Super!\n"
	.string "Combien tu peux me prêter?$"

BattleFrontier_Lounge3_Text_262B6E:: @ 8262B6E
	.string "Non mais!\n"
	.string "Tu n'as pas assez de POINTS DE COMBAT!\p"
	.string "Ça t'amuse de faire perdre leur temps\n"
	.string "aux honnêtes gens?$"

BattleFrontier_Lounge3_Text_262BE0:: @ 8262BE0
	.string "Hé, hé! Merci bien!\n"
	.string "C'est parti!$"

BattleFrontier_Lounge3_Text_262C04:: @ 8262C04
	.string "Vite, les SALLES DE COMBAT SOLO\n"
	.string "de la TOUR DE COMBAT t'attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_262C90:: @ 8262C90
	.string "Vite, les SALLES DE COMBAT DUO\n"
	.string "de la TOUR DE COMBAT t'attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_262D1C:: @ 8262D1C
	.string "Vite, les SALLES DE COMBAT MULTI\n"
	.string "de la TOUR DE COMBAT t'attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_262DA7:: @ 8262DA7
	.string "Vite, le TOURNOI DE COMBAT SOLO\n"
	.string "du DOME DE COMBAT t'attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_262E34:: @ 8262E34
	.string "Vite, le TOURNOI DE COMBAT DUO\n"
	.string "du DOME DE COMBAT t'attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_262EC1:: @ 8262EC1
	.string "Vite, le TOURNOI COMBAT ECHANGE\n"
	.string "SOLO de l'USINE DE COMBAT t'attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_262F56:: @ 8262F56
	.string "Vite, le TOURNOI COMBAT ECHANGE\n"
	.string "DUO de l'USINE DE COMBAT t'attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_262FEB:: @ 8262FEB
	.string "Vite, les HALLS DE COMBAT SOLO\n"
	.string "du PALACE DE COMBAT t'attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_263078:: @ 8263078
	.string "Vite, les HALLS DE COMBAT DUO\n"
	.string "du PALACE DE COMBAT t'attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_263105:: @ 8263105
	.string "Vite, le TOURNOI K.O. du DOJO DE\n"
	.string "COMBAT t'attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_26318C:: @ 826318C
	.string "Vite, le défi du COMBAT HASARD\n"
	.string "t'attend au REPTILE DE COMBAT!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_263211:: @ 8263211
	.string "Vite, le défi du COMBAT QUETE\n"
	.string "t'attend dans la PYRAMIDE DE COMBAT!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_263298:: @ 8263298
	.string "Oh, c'est toi…\n"
	.string "C'était bien tenté…\p"
	.string "Malheureusement, je ne peux pas te\n"
	.string "rendre ce que tu m'as prêté…\p"
	.string "Ça nous apprendra à faire plus\n"
	.string "attention la prochaine fois!$"

BattleFrontier_Lounge3_Text_263334:: @ 8263334
	.string "Bravo!\n"
	.string "Tu as été formidable!\p"
	.string "Je le savais!\n"
	.string "Je te faisais confiance!\l"
	.string "On est les meilleurs!\p"
	.string "Je te rends ce que tu m'as prêté avec\n"
	.string "un petit extra!$"

BattleFrontier_Lounge3_Text_2633D4:: @ 82633D4
	.string "{PLAYER} reçoit\n"
	.string "{STR_VAR_1} POINTS DE COMBAT.$"

BattleFrontier_Lounge3_Text_2633F2:: @ 82633F2
	.string "Si tu as envie de relever un autre\n"
	.string "défi, pense à moi!$"

BattleFrontier_Lounge3_Text_26342D:: @ 826342D
	.string "Ça ne t'intéresse pas?\n"
	.string "Penses-y, au moins!$"

BattleFrontier_Lounge3_Text_26346B:: @ 826346B
	.string "Oh…$"

BattleFrontier_Lounge3_Text_26346F:: @ 826346F
	.string "J'ai encore misé sur le mauvais\n"
	.string "DRESSEUR!\p"
	.string "Je crois que je devrais arrêter ces\n"
	.string "bêtises…$"

BattleFrontier_Lounge3_Text_2634C9:: @ 82634C9
	.string "Ce DRESSEUR…\p"
	.string "Il est bon, mais il n'a pas les nerfs\n"
	.string "assez solides pour le DOME DE COMBAT…$"

BattleFrontier_Lounge3_Text_26351D:: @ 826351D
	.string "Hi, hi, hi!\n"
	.string "Je sais reconnaître un gagnant!$"

BattleFrontier_Lounge3_Text_263545:: @ 8263545
	.string "Ces DRESSEURS…\n"
	.string "Mais que font-ils?\l"
	.string "Ils devraient aller se battre.$"
