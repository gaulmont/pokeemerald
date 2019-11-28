LilycoveCity_LilycoveMuseum_1F_MapScripts:: @ 8218CB8
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_218CB9:: @ 8218CB9
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_218E4B, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218CC2:: @ 8218CC2
	lockall
	applymovement 2, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_218EBC
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_218CF5
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_218CEC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218CEC:: @ 8218CEC
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_218F5C, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218CF5:: @ 8218CF5
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_218F98, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_218D14
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_218D1E
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D14:: @ 8218D14
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_218FF8, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D1E:: @ 8218D1E
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219035, MSGBOX_SIGN
	applymovement 2, LilycoveCity_LilycoveMuseum_1F_Movement_218D99
	waitmovement 0
	removeobject 2
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_218D5A
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_218D6F
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_218D84
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D5A:: @ 8218D5A
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_218DA1
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D6F:: @ 8218D6F
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_218D9B
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D84:: @ 8218D84
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_218D9E
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_218D99: @ 8218D99
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_218D9B: @ 8218D9B
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_218D9E: @ 8218D9E
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_218DA1: @ 8218DA1
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DA4:: @ 8218DA4
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219080, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DAD:: @ 8218DAD
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2190BF, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DB6:: @ 8218DB6
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2190F9, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DBF:: @ 8218DBF
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219142, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DC8:: @ 8218DC8
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2191A2, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DD1:: @ 8218DD1
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_21920D, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DDA:: @ 8218DDA
LilycoveCity_LilycoveMuseum_2F_EventScript_218DDA:: @ 8218DDA
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219260, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DE3:: @ 8218DE3
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2192AA, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DEC:: @ 8218DEC
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219311, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DF5:: @ 8218DF5
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2193B4, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DFE:: @ 8218DFE
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_21941A, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E07:: @ 8218E07
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2194BA, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E10:: @ 8218E10
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2194E1, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E19:: @ 8218E19
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219515, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E22:: @ 8218E22
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_21959B, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E2B:: @ 8218E2B
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2195FF, MSGBOX_DEFAULT
	closemessage
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E42:: @ 8218E42
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_21967A, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_218E4B: @ 8218E4B
	.string "Bienvenue au MUSEE NENUCRIQUE.\p"
	.string "Prenez le temps d'apprécier notre\n"
	.string "superbe collection sur les POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_218EBC: @ 8218EBC
	.string "Je suis le CONSERVATEUR de ce\n"
	.string "MUSEE des beaux-arts.\p"
	.string "C'est encourageant de voir quelqu'un\n"
	.string "d'aussi jeune dans notre MUSEE.\p"
	.string "As-tu déjà vu notre collection de\n"
	.string "tableaux?$"

LilycoveCity_LilycoveMuseum_1F_Text_218F5C: @ 8218F5C
	.string "Bon, alors je ne te dérange pas.\n"
	.string "Prends tout ton temps.$"

LilycoveCity_LilycoveMuseum_1F_Text_218F98: @ 8218F98
	.string "Oh? Tu m'as tout l'air d'un DRESSEUR\n"
	.string "de POKéMON.\p"
	.string "Et tu t'intéresses également à la\n"
	.string "peinture?$"

LilycoveCity_LilycoveMuseum_1F_Text_218FF8: @ 8218FF8
	.string "Je vois…\p"
	.string "Je suis honoré que tu nous rendes\n"
	.string "visite malgré tout.$"

LilycoveCity_LilycoveMuseum_1F_Text_219035: @ 8219035
	.string "Ah, très bien!\n"
	.string "Tu aimes effectivement la peinture!\p"
	.string "Alors peut-être voudrais-tu me suivre?$"

LilycoveCity_LilycoveMuseum_1F_Text_219080: @ 8219080
	.string "C'est un tableau très ancien.\n"
	.string "La peinture s'écaille ici et là.$"

LilycoveCity_LilycoveMuseum_1F_Text_2190BF: @ 82190BF
	.string "C'est un curieux paysage avec des vues\n"
	.string "étranges et fantastiques.$"

LilycoveCity_LilycoveMuseum_1F_Text_2190F9: @ 82190F9
	.string "C'est la représentation d'une\n"
	.string "charmante femme avec un POKéMON\l"
	.string "sur ses genoux.$"

LilycoveCity_LilycoveMuseum_1F_Text_219142: @ 8219142
	.string "C'est la représentation d'un POKéMON\n"
	.string "légendaire de l'ancien temps.\p"
	.string "Il est issu de l'imagination du peintre.$"

LilycoveCity_LilycoveMuseum_1F_Text_2191A2: @ 82191A2
	.string "C'est la représentation de POKéMON du\n"
	.string "type PLANTE qui vacillent au vent.\p"
	.string "Ils ont l'air d'aimer sentir la caresse\n"
	.string "du vent.$"

LilycoveCity_LilycoveMuseum_1F_Text_21920D: @ 821920D
	.string "C'est une exquise représentation\n"
	.string "de BAIES.\p"
	.string "Ce tableau vous donnerait faim!$"

LilycoveCity_LilycoveMuseum_1F_Text_219260: @ 8219260
	.string "C'est une réplique de sculpture connue.\p"
	.string "C'est un antique POKéMON OISEAU.$"

LilycoveCity_LilycoveMuseum_1F_Text_2192AA: @ 82192AA
	.string "C'est une grosse POKé BALL sculptée\n"
	.string "dans une pierre noire.\p"
	.string "Elle était apparemment utilisée jadis,\n"
	.string "lors de festivals.$"

LilycoveCity_LilycoveMuseum_1F_Text_219311: @ 8219311
	.string "C'est une immense plaque en pierre\n"
	.string "Des POKéMON et un texte compact,\l"
	.string "écrit dans une langue ancienne\l"
	.string "indéchiffrable, sont gravés dessus.$"

LilycoveCity_LilycoveMuseum_1F_Text_21938C: @ 821938C
	.string "Hmmm…\n"
	.string "Quel travail somptueux…$"

LilycoveCity_LilycoveMuseum_1F_Text_2193B4: @ 82193B4
	.string "C'est un plaisir d'affronter les\n"
	.string "POKéMON, je te l'accorde.\p"
	.string "Mais il ne faut pas oublier notre amour\n"
	.string "pour les beaux-arts.$"

LilycoveCity_LilycoveMuseum_1F_Text_21941A: @ 821941A
	.string "Ce MUSEE D'ART… Eh bien, tu peux y\n"
	.string "voir beaucoup de fabuleux tableaux.\p"
	.string "Et le CONSERVATEUR est extraordinaire.\p"
	.string "Pour les artistes tels que moi, ce MUSEE\n"
	.string "est une véritable source d'inspiration.$"

LilycoveCity_LilycoveMuseum_1F_Text_2194BA: @ 82194BA
	.string "Cette dame est jolie!\n"
	.string "Elle est comme maman!$"

LilycoveCity_LilycoveMuseum_1F_Text_2194E1: @ 82194E1
	.string "Ce POKéMON est adorable!\n"
	.string "Tout comme notre petit fiston!$"

LilycoveCity_LilycoveMuseum_1F_Text_219515: @ 8219515
	.string "J'ai entendu dire que ce MUSEE D'ART\n"
	.string "avait acquis de nouveaux tableaux.\p"
	.string "Alors évidemment, je m'y suis\n"
	.string "précipitée.\p"
	.string "Les nouveaux tableaux sont-ils en\n"
	.string "haut, à l'étage?$"

LilycoveCity_LilycoveMuseum_1F_Text_21959B: @ 821959B
	.string "Ces temps-ci, le CONSERVATEUR est\n"
	.string "plus joyeux que d'habitude.\p"
	.string "Je parie qu'il lui est arrivé quelque\n"
	.string "chose de bien. C'est sûr.$"

LilycoveCity_LilycoveMuseum_1F_Text_2195FF: @ 82195FF
	.string "Je viens ici pour voir plein de grands\n"
	.string "tableaux et en tirer des enseignements.\p"
	.string "Je rêve d'avoir un jour mes œuvres\n"
	.string "exposées ici.$"

LilycoveCity_LilycoveMuseum_1F_Text_21967A: @ 821967A
	.string "Le MUSEE D'ART est devenu très\n"
	.string "prisé par les touristes.\p"
	.string "C'est super pour NENUCRIQUE.\n"
	.string "Non, super pour la région de HOENN!\p"
	.string "J'ai entendu dire que tous les tableaux\n"
	.string "du haut proviennent du même DRESSEUR.$"

