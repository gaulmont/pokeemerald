MossdeepCity_MapScripts:: @ 81E4A96
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition: @ 81E4A9C
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	end

MossdeepCity_EventScript_1E4AB2:: @ 81E4AB2
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_1E4AC7
	msgbox MossdeepCity_Text_1E4E90, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4AC7:: @ 81E4AC7
	msgbox MossdeepCity_Text_1E4F15, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4AD1:: @ 81E4AD1
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_1E4AE6
	msgbox MossdeepCity_Text_1E4F50, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4AE6:: @ 81E4AE6
	msgbox MossdeepCity_Text_1E5051, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4AF0:: @ 81E4AF0
	msgbox MossdeepCity_Text_1E4E22, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4AF9:: @ 81E4AF9
	msgbox MossdeepCity_Text_1E5135, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4B02:: @ 81E4B02
	msgbox MossdeepCity_Text_1E50D9, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4B0B:: @ 81E4B0B
	msgbox MossdeepCity_Text_1E529D, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4B14:: @ 81E4B14
	msgbox MossdeepCity_Text_1E5396, MSGBOX_SIGN
	end

MossdeepCity_EventScript_1E4B1D:: @ 81E4B1D
	msgbox MossdeepCity_Text_1E53A9, MSGBOX_SIGN
	end

MossdeepCity_EventScript_1E4B26:: @ 81E4B26
	msgbox MossdeepCity_Text_1E53F2, MSGBOX_SIGN
	end

MossdeepCity_EventScript_1E4B2F:: @ 81E4B2F
	msgbox MossdeepCity_Text_1E541F, MSGBOX_SIGN
	end

MossdeepCity_EventScript_1E4B38:: @ 81E4B38
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_1E4B41:: @ 81E4B41
	lockall
	applymovement 14, MossdeepCity_Movement_1E4BAD
	waitmovement 0
	applymovement 10, MossdeepCity_Movement_1E4BB7
	applymovement 11, MossdeepCity_Movement_1E4BB7
	applymovement 12, MossdeepCity_Movement_1E4BB7
	applymovement 13, MossdeepCity_Movement_1E4BB7
	waitmovement 0
	applymovement 14, MossdeepCity_Movement_1E4BBC
	applymovement 10, MossdeepCity_Movement_1E4BCA
	applymovement 11, MossdeepCity_Movement_1E4BDD
	applymovement 12, MossdeepCity_Movement_1E4BEF
	applymovement 13, MossdeepCity_Movement_1E4C00
	waitmovement 0
	removeobject 14
	removeobject 10
	removeobject 11
	removeobject 12
	removeobject 13
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_1E4BAD: @ 81E4BAD
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_1E4BB7: @ 81E4BB7
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_1E4BBC: @ 81E4BBC
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_1E4BCA: @ 81E4BCA
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_1E4BDD: @ 81E4BDD
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_1E4BEF: @ 81E4BEF
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_1E4C00: @ 81E4C00
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_1E4C10:: @ 81E4C10
	lock
	faceplayer
	msgbox MossdeepCity_Text_1E5213, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_1E4C26:: @ 81E4C26
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_1E4C68
	msgbox MossdeepCity_Text_1E4CED, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_EventScript_1E4C72
	msgbox MossdeepCity_Text_1E4D5B, MSGBOX_DEFAULT
	giveitem_std ITEM_KINGS_ROCK
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_1E4C68:: @ 81E4C68
	msgbox MossdeepCity_Text_1E4DB3, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4C72:: @ 81E4C72
	msgbox MossdeepCity_Text_1E4DD7, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4C7C:: @ 81E4C7C
	msgbox MossdeepCity_Text_1E5581, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4C85:: @ 81E4C85
	lock
	faceplayer
	msgbox MossdeepCity_Text_1E5453, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq MossdeepCity_EventScript_1E4CB0
	compare VAR_FACING, DIR_EAST
	call_if_eq MossdeepCity_EventScript_1E4CC2
	addvar VAR_SCOTT_STATE, 1
	removeobject 16
	release
	end

MossdeepCity_EventScript_1E4CB0:: @ 81E4CB0
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_1E4CD4
	applymovement 16, MossdeepCity_Movement_1E4CD8
	waitmovement 0
	return

MossdeepCity_EventScript_1E4CC2:: @ 81E4CC2
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_1E4CD4
	applymovement 16, MossdeepCity_Movement_1E4CE2
	waitmovement 0
	return

MossdeepCity_Movement_1E4CD4: @ 81E4CD4
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MossdeepCity_Movement_1E4CD8: @ 81E4CD8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_1E4CE2: @ 81E4CE2
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


MossdeepCity_Text_1E4CED: @ 81E4CED
	.string "C'est PIERRE qui m'a donné ça, mais\n"
	.string "je ne sais pas à quoi ça sert au juste.\p"
	.string "Je crois qu'on appelle ça la ROCHE\n"
	.string "ROYALE. Tu la veux?$"

MossdeepCity_Text_1E4D5B: @ 81E4D5B
	.string "Pourquoi en voudrais-tu?\n"
	.string "C'est bizarre.\p"
	.string "Tu peux la garder, mais il ne faut pas\n"
	.string "que PIERRE le sache.$"

MossdeepCity_Text_1E4DB3: @ 81E4DB3
	.string "La maison de PIERRE est juste là!$"

MossdeepCity_Text_1E4DD7: @ 81E4DD7
	.string "Hé, tu trouves aussi! Qu'est-ce qu'on\n"
	.string "peut bien pouvoir faire avec de drôles\n"
	.string "de pierrres?$"

MossdeepCity_Text_1E4E22: @ 81E4E22
	.string "Aux alentours d'ALGATIA, tu peux\n"
	.string "voir des WAILMER sauvages.\p"
	.string "Ça s'appelle, euh…\n"
	.string "Comment c'est déjà…\p"
	.string "Attends, attends, attends…\p"
	.string "L'observation de WAILMER!$"

MossdeepCity_Text_1E4E90: @ 81E4E90
	.string "Ce CENTRE SPATIAL insulaire a lancé\n"
	.string "de très grosses fusées.\p"
	.string "Mais ils sont très inquiets depuis qu'ils\n"
	.string "ont reçu une certaine lettre.$"

MossdeepCity_Text_1E4F15: @ 81E4F15
	.string "Ce CENTRE SPATIAL insulaire a lancé\n"
	.string "de très grosses fusées.$"

MossdeepCity_Text_1E4F50: @ 81E4F50
	.string "J'ai appris d'un ami MARIN que la\n"
	.string "TEAM AQUA s'est installée à NENUCRIQUE.\p"
	.string "J'ai aussi appris que quelqu'un s'est\n"
	.string "mêlé de leurs affaires!\p"
	.string "Mais ALGATIA est déjà la cible de la\n"
	.string "TEAM MAGMA.\p"
	.string "Si tu veux savoir ce qu'ils manigancent,\n"
	.string "tu devrais aller au CENTRE SPATIAL.$"

MossdeepCity_Text_1E5051: @ 81E5051
	.string "Je suis MARIN, la mer est donc très\n"
	.string "importante pour moi.\p"
	.string "Mais tu sais, après un long voyage\n"
	.string "en mer, je me sens soulagé de poser\n"
	.string "le pied à terre.$"

MossdeepCity_Text_1E50D9: @ 81E50D9
	.string "Ça ne serait pas charmant?\p"
	.string "Si le monde entier était recouvert de\n"
	.string "plantes et de fleurs comme cette île?$"

MossdeepCity_Text_1E5135: @ 81E5135
	.string "Toute forme de vie, même terrestre,\n"
	.string "a besoin de la mer pour vivre.\p"
	.string "La vie, une fois consumée, n'est plus\n"
	.string "que poussière qui retourne à la terre.\p"
	.string "Et la mer est toujours reliée à la terre.\p"
	.string "Oui, comme le rivage ici.$"

MossdeepCity_Text_1E5213: @ 81E5213
	.string "C'est sympa de voyager sur un bateau.\p"
	.string "Mais traverser la mer avec un POKéMON\n"
	.string "qui utilise SURF…\p"
	.string "Là, c'est un voyage grisant!\n"
	.string "T'es pas d'accord, mon p'tit??$"

MossdeepCity_Text_1E529D: @ 81E529D
	.string "Cette pierre a un sens particulier\n"
	.string "pour les gens du CENTRE SPATIAL.\p"
	.string "Ils l'ont posée là et fait le vœu que\n"
	.string "leurs fusées volent en toute sécurité.\p"
	.string "Tu fais comment, toi, pour faire un\n"
	.string "vœu? T'attends de voir une étoile\n"
	.string "filante?\p"
	.string "Moi, je jette une pièce dans une.\n"
	.string "fontaine pour que mon vœu se réalise.$"

MossdeepCity_Text_1E5396: @ 81E5396
	.string "C'est une pierre blanche.$"

MossdeepCity_Text_1E53A9: @ 81E53A9
	.string "ARENE POKéMON d'ALGATIA\n"
	.string "CHAMPIONS: TATIA et LEVY\p"
	.string "“La combinaison mystique!”$"

MossdeepCity_Text_1E53F2: @ 81E53F2
	.string "ALGATIA\n"
	.string "“Notre slogan: chérir les POKéMON!”$"

MossdeepCity_Text_1E541F: @ 81E541F
	.string "CENTRE SPATIAL D'ALGATIA\n"
	.string "“L'endroit le plus proche de l'espace.”$"

MossdeepCity_Text_1E5453: @ 81E5453
	.string "SCOTT: Comment ça va, {PLAYER}{KUN}?\n"
	.string "Pour moi ça roule en tout cas!\p"
	.string "J'ai entendu dire que le CHAMPION\n"
	.string "D'ARENE d'ALGATIA est assez fort, alors\l"
	.string "je viens voir ça de mes propres yeux.\p"
	.string "Mais il y a quelque chose d'étrange\n"
	.string "qui se passe ici.\p"
	.string "Les gens parlent d'une lettre et du\n"
	.string "CENTRE SPATIAL…\p"
	.string "Mais tout ça ne me concerne pas de\n"
	.string "toute façon.$"

MossdeepCity_Text_1E5581: @ 81E5581
	.string "Ahh… C'est tellement bon de laisser\n"
	.string "les embruns caresser mon visage…\p"
	.string "En parlant de la mer, tu connais cette\n"
	.string "ville insulaire, ATALANOPOLIS?\p"
	.string "Je crois qu'ils ont un nouveau CHAMPION\n"
	.string "dans leur ARENE.\p"
	.string "Il paraît que ce nouveau CHAMPION\n"
	.string "était le mentor de MARC.$"
