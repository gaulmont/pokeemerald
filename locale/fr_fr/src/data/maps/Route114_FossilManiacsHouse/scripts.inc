Route114_FossilManiacsHouse_MapScripts:: @ 822AD30
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition: @ 822AD36
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_22AD3A:: @ 822AD3A
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM28, Route114_FossilManiacsHouse_EventScript_22AD69
	msgbox Route114_FossilManiacsHouse_Text_22AD85, MSGBOX_DEFAULT
	giveitem_std ITEM_TM28
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM28
	release
	end

Route114_FossilManiacsHouse_EventScript_22AD69:: @ 822AD69
	msgbox Route114_FossilManiacsHouse_Text_22AE48, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_22AD73:: @ 822AD73
	msgbox Route114_FossilManiacsHouse_Text_22AE92, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_22AD7C:: @ 822AD7C
	msgbox Route114_FossilManiacsHouse_Text_22AEC2, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_22AD85: @ 822AD85
	.string "Mon grand frère est le MANIAQUE\n"
	.string "DES FOSSILES… C'est un gentil\l"
	.string "garçon passionné de FOSSILES…\p"
	.string "Il adore creuser des trous, aussi…\n"
	.string "Il a creusé ce trou tout seul…\p"
	.string "Tiens, prends ça, tu pourras utiliser\n"
	.string "TUNNEL, comme mon grand frère…$"

Route114_FossilManiacsHouse_Text_22AE48: @ 822AE48
	.string "Si ton POKéMON utilise TUNNEL dans une\n"
	.string "caverne, tu retournes à l'entrée…$"

Route114_FossilManiacsHouse_Text_22AE92: @ 822AE92
	.string "Des roches aux formes étranges\n"
	.string "sont disposées dans la vitrine…$"

Route114_FossilManiacsHouse_Text_22AEC2: @ 822AEC2
	.string "LA COMPOSITION DES STRATES…\n"
	.string "LA PLUIE, L'EROSION ET LA TERRE…\l"
	.string "PIERRES, TERRE ET AUTRES ROCHERS…\p"
	.string "C'est rempli de livres.$"

