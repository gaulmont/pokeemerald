Route114_LanettesHouse_MapScripts:: @ 822B2C8
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition: @ 822B2CE
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_22B2D2:: @ 822B2D2
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_22B2FF
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_22B34E, MSGBOX_DEFAULT
	givedecoration_std DECOR_LOTAD_DOLL
	compare VAR_RESULT, 0
	goto_if_eq Route114_LanettesHouse_EventScript_272067
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_22B2FF:: @ 822B2FF
	msgbox Route114_LanettesHouse_Text_22B407, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_22B309:: @ 822B309
	lockall
	msgbox Route114_LanettesHouse_Text_22B485, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route114_LanettesHouse_EventScript_22B327
	msgbox Route114_LanettesHouse_Text_22B6E4, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_22B327:: @ 822B327
	msgbox Route114_LanettesHouse_Text_22B53C, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq Route114_LanettesHouse_EventScript_22B33C
	releaseall
	end

Route114_LanettesHouse_EventScript_22B33C:: @ 822B33C
	msgbox Route114_LanettesHouse_Text_22B5EF, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_22B345:: @ 822B345
	msgbox Route114_LanettesHouse_Text_22B6FC, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_22B34E: @ 822B34E
	.string "ANNETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Je suis désolée. C'est la pagaille. Quand\n"
	.string "je suis plongée dans mes recherches,\l"
	.string "je n'ai pas le temps de ranger…\p"
	.string "C'est très embarrassant… Si tu n'en\n"
	.string "parles à personne, je te donne ça.$"

Route114_LanettesHouse_Text_22B407: @ 822B407
	.string "Je peux te donner un conseil sur mon\n"
	.string "programme de Gestion de Stocks de\l"
	.string "POKéMON?\p"
	.string "Tu peux organiser tes BOITES pour\n"
	.string "savoir quels POKéMON elles contiennent.$"

Route114_LanettesHouse_Text_22B485: @ 822B485
	.string "Ce sont les notes d'ANNETTE.\n"
	.string "Il y a des informations sur les BOITES.\p"
	.string "Concevoir des BOITES pouvant contenir\n"
	.string "30 POKéMON chacune.\p"
	.string "Chaque DRESSEUR doit pouvoir stocker\n"
	.string "420 POKéMON sur son PC.\p"
	.string "Continuer à lire?$"

Route114_LanettesHouse_Text_22B53C: @ 822B53C
	.string "Ajouter un système de marquage pour\n"
	.string "faciliter l'organisation des POKéMON.\p"
	.string "Le nom et le fond de chaque BOITE\n"
	.string "pourront être modifiés pour satisfaire\l"
	.string "les POKéMON stockés.\p"
	.string "Continuer à lire?$"

Route114_LanettesHouse_Text_22B5EF: @ 822B5EF
	.string "Quand un POKéMON est stocké, il est\n"
	.string "envoyé dans la dernière BOITE ouverte.\p"
	.string "Si cette BOITE est pleine, le POKéMON\n"
	.string "reçu sera stocké dans la suivante.\p"
	.string "En bref, la dernière BOITE ouverte\n"
	.string "devient la BOITE dans laquelle les\l"
	.string "POKéMON seront envoyés.$"

Route114_LanettesHouse_Text_22B6E4: @ 822B6E4
	.string "{PLAYER} ferme le cahier.$"

Route114_LanettesHouse_Text_22B6FC: @ 822B6FC
	.string "Il y a un e-mail sur le PC.\p"
	.string "“… … … … … … …\p"
	.string "“Votre programme de Gestion de Stocks\n"
	.string "est plus performant que le mien.\p"
	.string "“La simplicité d'utilisation en fait\n"
	.string "un outil à la fois amusant et utile.\p"
	.string "“Je suis très content d'avoir\n"
	.string "participé à son développement.\p"
	.string "“J'espère que vous continuerez vos\n"
	.string "recherches sur la Gestion de Stocks.\p"
	.string "“De la part de LEO.\n"
	.string "… … … … … … … …”$"

