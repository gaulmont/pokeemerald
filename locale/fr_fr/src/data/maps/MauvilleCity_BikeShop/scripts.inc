MauvilleCity_BikeShop_MapScripts:: @ 820EBBB
	.byte 0

MauvilleCity_BikeShop_EventScript_20EBBC:: @ 820EBBC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_20EC94
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_20EBF7
	msgbox MauvilleCity_BikeShop_Text_20EE22, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_20EE99, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20EC4A
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_20EC3D
	end

MauvilleCity_BikeShop_EventScript_20EBF7:: @ 820EBF7
	msgbox MauvilleCity_BikeShop_Text_20EE99, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20EC4A
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_20EC3D
	end

MauvilleCity_BikeShop_EventScript_20EC16:: @ 820EC16
	message MauvilleCity_BikeShop_Text_20EF32
	waitmessage
	multichoice 21, 8, MULTI_BIKE, 1
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_20EC53
	case 1, MauvilleCity_BikeShop_EventScript_20EC6D
	end

MauvilleCity_BikeShop_EventScript_20EC3D:: @ 820EC3D
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_20EEE8, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_20EC4A:: @ 820EC4A
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC16
	end

MauvilleCity_BikeShop_EventScript_20EC53:: @ 820EC53
	msgbox MauvilleCity_BikeShop_Text_20F18D, MSGBOX_DEFAULT
	giveitem_std ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC87
	end

MauvilleCity_BikeShop_EventScript_20EC6D:: @ 820EC6D
	msgbox MauvilleCity_BikeShop_Text_20F1A5, MSGBOX_DEFAULT
	giveitem_std ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC87
	end

MauvilleCity_BikeShop_EventScript_20EC87:: @ 820EC87
	msgbox MauvilleCity_BikeShop_Text_20F1BD, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_20EC94:: @ 820EC94
	msgbox MauvilleCity_BikeShop_Text_20F1FB, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20ECB3
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_20ECE5
	end

MauvilleCity_BikeShop_EventScript_20ECB3:: @ 820ECB3
	msgbox MauvilleCity_BikeShop_Text_20F22F, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20ECEF
	checkitem ITEM_MACH_BIKE, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_20ED10
	msgbox MauvilleCity_BikeShop_Text_20F2F3, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_20ECE5:: @ 820ECE5
	msgbox MauvilleCity_BikeShop_Text_20F2C4, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_20ECEF:: @ 820ECEF
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_20F294, MSGBOX_DEFAULT
	takeitem ITEM_ACRO_BIKE, 1
	giveitem_std ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC87
	end

MauvilleCity_BikeShop_EventScript_20ED10:: @ 820ED10
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_20F263, MSGBOX_DEFAULT
	takeitem ITEM_MACH_BIKE, 1
	giveitem_std ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_20EC87
	end

MauvilleCity_BikeShop_EventScript_20ED31:: @ 820ED31
	msgbox MauvilleCity_BikeShop_Text_20F3C3, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_20ED3A:: @ 820ED3A
	message MauvilleCity_BikeShop_Text_20F445
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20ED46
	end

MauvilleCity_BikeShop_EventScript_20ED46:: @ 820ED46
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, 0
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_20ED88
	case 1, MauvilleCity_BikeShop_EventScript_20ED94
	case 2, MauvilleCity_BikeShop_EventScript_20EDA0
	case 3, MauvilleCity_BikeShop_EventScript_20EDAC
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_20EDAC
	end

MauvilleCity_BikeShop_EventScript_20ED88:: @ 820ED88
	message MauvilleCity_BikeShop_Text_20F487
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20ED46
	end

MauvilleCity_BikeShop_EventScript_20ED94:: @ 820ED94
	message MauvilleCity_BikeShop_Text_20F550
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20ED46
	end

MauvilleCity_BikeShop_EventScript_20EDA0:: @ 820EDA0
	message MauvilleCity_BikeShop_Text_20F61A
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20ED46
	end

MauvilleCity_BikeShop_EventScript_20EDAC:: @ 820EDAC
	release
	end

MauvilleCity_BikeShop_EventScript_20EDAE:: @ 820EDAE
	message MauvilleCity_BikeShop_Text_20F6ED
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20EDBA
	end

MauvilleCity_BikeShop_EventScript_20EDBA:: @ 820EDBA
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, 0
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_20EDFC
	case 1, MauvilleCity_BikeShop_EventScript_20EE08
	case 2, MauvilleCity_BikeShop_EventScript_20EE14
	case 3, MauvilleCity_BikeShop_EventScript_20EE20
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_20EE20
	end

MauvilleCity_BikeShop_EventScript_20EDFC:: @ 820EDFC
	message MauvilleCity_BikeShop_Text_20F72F
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20EDBA
	end

MauvilleCity_BikeShop_EventScript_20EE08:: @ 820EE08
	message MauvilleCity_BikeShop_Text_20F7F5
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20EDBA
	end

MauvilleCity_BikeShop_EventScript_20EE14:: @ 820EE14
	message MauvilleCity_BikeShop_Text_20F898
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_20EDBA
	end

MauvilleCity_BikeShop_EventScript_20EE20:: @ 820EE20
	release
	end

MauvilleCity_BikeShop_Text_20EE22: @ 820EE22
	.string "Bon, bon, bon… Qu'est-ce qu'on a là?\n"
	.string "Un client des plus énergiques!\p"
	.string "Moi? Tu peux m'appeler RODOLPHE.\n"
	.string "Je suis le propriétaire de ce magasin\l"
	.string "de vélos.$"

MauvilleCity_BikeShop_Text_20EE99: @ 820EE99
	.string "RODOLPHE: Tes CHAUSSURES DE SPORT…\n"
	.string "Elles sont dégoûtantes!\p"
	.string "Tu viens de loin?$"

MauvilleCity_BikeShop_Text_20EEE8: @ 820EEE8
	.string "RODOLPHE: C'est vrai?\p"
	.string "Alors je suppose que tu n'as pas\n"
	.string "besoin de mes VELOS.$"

MauvilleCity_BikeShop_Text_20EF32: @ 820EF32
	.string "RODOLPHE: Hum, hum… … … … …\p"
	.string "Tu veux dire que tu as fait toute\n"
	.string "la route depuis BOURG-EN-VOL?\p"
	.string "Mon dieu!\n"
	.string "C'est terriblement loin!\p"
	.string "Si tu avais un de mes VELOS, tu pourrais\n"
	.string "aller n'importe où sans problème, en\l"
	.string "sentant le vent te caresser le visage!\p"
	.string "Tu sais quoi?\n"
	.string "Je vais te donner un VELO!\p"
	.string "Oh, attends une seconde!\p"
	.string "J'ai oublié de te préciser qu'il y\n"
	.string "a deux sortes de VELOS.\p"
	.string "Il y a le VELO COURSE et le\n"
	.string "VELO CROSS.\p"
	.string "Le VELO COURSE est pour ceux qui\n"
	.string "veulent sentir le souffle du vent.\p"
	.string "Et le VELO CROSS est pour ceux qui\n"
	.string "préfèrent les performances techniques..\p"
	.string "Je suis un vrai passionné. Tu peux\n"
	.string "prendre celui que tu veux.\p"
	.string "Alors, tu choisis lequel?$"

MauvilleCity_BikeShop_Text_20F18D: @ 820F18D
	.string "{PLAYER} choisit le VELO COURSE.$"

MauvilleCity_BikeShop_Text_20F1A5: @ 820F1A5
	.string "{PLAYER} choisit le VELO CROSS.$"

MauvilleCity_BikeShop_Text_20F1BD: @ 820F1BD
	.string "RODOLPHE: Si tu as besoin de changer de\n"
	.string "VELO, n'hésite pas à venir me voir!$"

MauvilleCity_BikeShop_Text_20F1FB: @ 820F1FB
	.string "RODOLPHE: Oh? Tu voudrais changer\n"
	.string "de VELO?$"

MauvilleCity_BikeShop_Text_20F22F: @ 820F22F
	.string "RODOLPHE: D'accord, pas de problème!\n"
	.string "Je t'échange ton VELO contre l'autre.$"

MauvilleCity_BikeShop_Text_20F263: @ 820F263
	.string "{PLAYER} reçoit le VELO CROSS en\n"
	.string "échange du VELO COURSE.$"

MauvilleCity_BikeShop_Text_20F294: @ 820F294
	.string "{PLAYER} reçoit le VELO COURSE en\n"
	.string "échange du VELO CROSS.$"

MauvilleCity_BikeShop_Text_20F2C4: @ 820F2C4
	.string "RODOLPHE: Très bien!\n"
	.string "Content qu'il te convienne!$"

MauvilleCity_BikeShop_Text_20F2F3: @ 820F2F3
	.string "Oh? Qu'est-ce qui est arrivé au VELO\n"
	.string "que je t'avais donné?\p"
	.string "Ah, je vois! Tu l'as stocké sur ton PC.\p"
	.string "Bon, sors-le du PC et je te l'échangerai!\p"
	.string "Que les vents te soient favorables!$"

MauvilleCity_BikeShop_Text_20F3C3: @ 820F3C3
	.string "J'apprends beaucoup de choses sur les\n"
	.string "VELOS depuis que je travaille ici.\p"
	.string "Si tu as besoin de conseils pour\n"
	.string "conduire ton vélo, il y a deux ou\l"
	.string "trois manuels derrière.$"

MauvilleCity_BikeShop_Text_20F445: @ 820F445
	.string "C'est un guide sur le VELO COURSE.\p"
	.string "Lire quelle page?$"

MauvilleCity_BikeShop_Text_20F487: @ 820F487
	.string "Le VELO prend la direction indiquée\n"
	.string "sur la manette +.\p"
	.string "Il accélère dès qu'il commence à rouler.\p"
	.string "Quand la manette + n'est plus utilisée,\n"
	.string "le VELO ralentit et s'arrête.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_20F550: @ 820F550
	.string "Le VELO COURSE est rapide, mais il ne\n"
	.string "s'arrête pas immédiatement.\p"
	.string "C'est aussi un peu difficile de prendre\n"
	.string "les virages.\p"
	.string "Il faut relâcher la manette +\n"
	.string "et ralentir un peu avant le virage.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_20F61A: @ 820F61A
	.string "De petites coulées de sable parsèment\n"
	.string "toute la région de HOENN.\p"
	.string "Ce sable fin empêche d'avancer\n"
	.string "normalement.\p"
	.string "Mais avec un VELO COURSE, il est\n"
	.string "possible de gravir un versant de sable.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_20F6ED: @ 820F6ED
	.string "C'est un guide sur le VELO CROSS.\p"
	.string "Lire quelle page?$"

MauvilleCity_BikeShop_Text_20F72F: @ 820F72F
	.string "Si vous appuyez sur le bouton B en\n"
	.string "roulant, la roue avant se soulève.\p"
	.string "Vous pouvez rouler sur une roue\n"
	.string "en utilisant la manette +.\p"
	.string "Cette technique se nomme\n"
	.string "la roue arrière.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_20F7F5: @ 820F7F5
	.string "En maintenant le bouton B enfoncé,\n"
	.string "vous pourrez sauter sur des rebords.\p"
	.string "Cette technique est appelée bunny hop.\p"
	.string "Vous pouvez aussi avancer en sautant.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_20F898: @ 820F898
	.string "Appuyez simultanément sur le bouton B\n"
	.string "et sur la manette + pour faire un saut.\p"
	.string "Appuyez sur gauche ou droite sur la\n"
	.string "manette + pour faire un saut latéral.\p"
	.string "Appuyez sur haut sur la manette + pour\n"
	.string "changer de direction en sautant.\p"
	.string "Lire une autre page?$"

