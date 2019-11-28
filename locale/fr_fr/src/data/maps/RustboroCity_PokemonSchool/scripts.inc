RustboroCity_PokemonSchool_MapScripts:: @ 8213EA8
	.byte 0

RustboroCity_PokemonSchool_EventScript_213EA9:: @ 8213EA9
	lockall
	msgbox RustboroCity_PokemonSchool_Text_2140B2, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_213EB8
	end

RustboroCity_PokemonSchool_EventScript_213EB8:: @ 8213EB8
	message RustboroCity_PokemonSchool_Text_2140F9
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, 0
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_213F17
	case 1, RustboroCity_PokemonSchool_EventScript_213F25
	case 2, RustboroCity_PokemonSchool_EventScript_213F33
	case 3, RustboroCity_PokemonSchool_EventScript_213F41
	case 4, RustboroCity_PokemonSchool_EventScript_213F4F
	case 5, RustboroCity_PokemonSchool_EventScript_213F5D
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_213F5D
	end

RustboroCity_PokemonSchool_EventScript_213F17:: @ 8213F17
	msgbox RustboroCity_PokemonSchool_Text_21411A, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_213EB8
	end

RustboroCity_PokemonSchool_EventScript_213F25:: @ 8213F25
	msgbox RustboroCity_PokemonSchool_Text_2141D8, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_213EB8
	end

RustboroCity_PokemonSchool_EventScript_213F33:: @ 8213F33
	msgbox RustboroCity_PokemonSchool_Text_21427D, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_213EB8
	end

RustboroCity_PokemonSchool_EventScript_213F41:: @ 8213F41
	msgbox RustboroCity_PokemonSchool_Text_214336, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_213EB8
	end

RustboroCity_PokemonSchool_EventScript_213F4F:: @ 8213F4F
	msgbox RustboroCity_PokemonSchool_Text_2143B8, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_213EB8
	end

RustboroCity_PokemonSchool_EventScript_213F5D:: @ 8213F5D
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_213F5F:: @ 8213F5F
	msgbox RustboroCity_PokemonSchool_Text_21459F, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_213F68:: @ 8213F68
	msgbox RustboroCity_PokemonSchool_Text_2145CD, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_213F71:: @ 8213F71
	msgbox RustboroCity_PokemonSchool_Text_214604, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_213F7A:: @ 8213F7A
	msgbox RustboroCity_PokemonSchool_Text_214669, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_213F83:: @ 8213F83
	msgbox RustboroCity_PokemonSchool_Text_214719, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_213F8C:: @ 8213F8C
	msgbox RustboroCity_PokemonSchool_Text_2147A2, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_213F95:: @ 8213F95
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_213FFB
	compare VAR_FACING, DIR_EAST
	call_if_eq RustboroCity_PokemonSchool_EventScript_213FE5
	compare VAR_FACING, DIR_WEST
	call_if_eq RustboroCity_PokemonSchool_EventScript_213FF0
	msgbox RustboroCity_PokemonSchool_Text_214433, MSGBOX_DEFAULT
	giveitem_std ITEM_QUICK_CLAW
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_213FE5:: @ 8213FE5
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_214027
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_213FF0:: @ 8213FF0
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_214010
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_213FFB:: @ 8213FFB
	msgbox RustboroCity_PokemonSchool_Text_2144C8, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_214010: @ 8214010
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_214027: @ 8214027
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_214040:: @ 8214040
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_2140A8
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_21406F
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_214082
	msgbox RustboroCity_PokemonSchool_Text_2148C0, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_21406F:: @ 821406F
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_214090
	msgbox RustboroCity_PokemonSchool_Text_214A5F, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_214082:: @ 8214082
	msgbox RustboroCity_PokemonSchool_Text_214B8A, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_21409E
	end

RustboroCity_PokemonSchool_EventScript_214090:: @ 8214090
	msgbox RustboroCity_PokemonSchool_Text_214AB6, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_21409E
	end

RustboroCity_PokemonSchool_EventScript_21409E:: @ 821409E
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_2140A8:: @ 82140A8
	msgbox RustboroCity_PokemonSchool_Text_214A5F, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_2140B2: @ 82140B2
	.string "Ce tableau liste les changements de\n"
	.string "statut pouvant toucher les POKéMON\l"
	.string "au combat.$"

RustboroCity_PokemonSchool_Text_2140F9: @ 82140F9
	.string "Lire quel sujet?$"

RustboroCity_PokemonSchool_Text_21411A: @ 821411A
	.string "Si un POKéMON est empoisonné, ses PV\n"
	.string "diminuent régulièrement.\p"
	.string "Les effets du poison perdurent\n"
	.string "après un combat.\p"
	.string "Les PV d'un POKéMON empoisonné\n"
	.string "continuent à diminuer hors combat.\p"
	.string "L'ANTIDOTE remédie à l'empoisonnement.$"

RustboroCity_PokemonSchool_Text_2141D8: @ 82141D8
	.string "Si un POKéMON est paralysé, sa\n"
	.string "VITESSE diminue.\p"
	.string "Il peut aussi être dans l'incapacité\n"
	.string "de se déplacer pendant le combat.\p"
	.string "La paralysie persiste après le combat.\n"
	.string "L'ANTI-PARA permet d'y remédier.$"

RustboroCity_PokemonSchool_Text_21427D: @ 821427D
	.string "Si un POKéMON s'endort, il est\n"
	.string "dans l'incapacité d'attaquer.\p"
	.string "Le POKéMON peut se réveiller de\n"
	.string "lui-même, mais s'il est endormi à\l"
	.string "la fin du combat, il le restera ensuite.\p"
	.string "Le REVEIL le sortira de son sommeil.$"

RustboroCity_PokemonSchool_Text_214336: @ 8214336
	.string "Une brûlure réduit la puissance\n"
	.string "d'ATTAQUE et les PV de la victime.\p"
	.string "Une brûlure persiste après le combat..\n"
	.string "L'ANTI-BRULE permet d'y remédier.$"

RustboroCity_PokemonSchool_Text_2143B8: @ 82143B8
	.string "Si un POKéMON est gelé, il n'est\n"
	.string "plus d'aucune aide.\p"
	.string "Il restera gelé après le combat.\n"
	.string "L'ANTIGEL permet de le dégeler.$"

RustboroCity_PokemonSchool_Text_214433: @ 8214433
	.string "Les élèves qui ne travaillent pas n'ont\n"
	.string "qu'un petit échantillon de ma VIVE\l"
	.string "GRIFFE.\p"
	.string "La manière dont tu utiliseras cet objet\n"
	.string "indiquera de façon évidente si tu\l"
	.string "apprends bien ou pas.$"

RustboroCity_PokemonSchool_Text_2144C8: @ 82144C8
	.string "Un POKéMON qui porte VIVE GRIFFE\n"
	.string "pourra parfois augmenter sa vitesse\l"
	.string "et attaquer avant son adversaire.\p"
	.string "D'autres objets comme celui-ci sont\n"
	.string "faits pour être portés par un POKéMON.\p"
	.string "Mais celui-ci te donnera déjà matière\n"
	.string "à réfléchir!$"

RustboroCity_PokemonSchool_Text_21459F: @ 821459F
	.string "Je vais dès maintenant faire un\n"
	.string "échange de POKéMON avec mon ami.$"

RustboroCity_PokemonSchool_Text_2145CD: @ 82145CD
	.string "J'ai toujours voulu un GRAINIPIOT\n"
	.string "et j'ai enfin réussi à en avoir un!$"

RustboroCity_PokemonSchool_Text_214604: @ 8214604
	.string "Les POKéMON peuvent porter des objets,\n"
	.string "mais ne savent pas utiliser les objets\l"
	.string "conçus par les hommes, tels que la\l"
	.string "POTION ou l'ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_214669: @ 8214669
	.string "Tu sais combien certaines capacités\n"
	.string "peuvent troubler un POKéMON?\p"
	.string "Un POKéMON confus peut parfois\n"
	.string "se blesser sans le vouloir.\p"
	.string "Mais après le combat, il retrouve\n"
	.string "ses esprits.$"

RustboroCity_PokemonSchool_Text_214719: @ 8214719
	.string "Un POKéMON qui porte une BAIE\n"
	.string "se soignera lui-même…\p"
	.string "Il existe de nombreuses sortes\n"
	.string "d'objets qu'un POKéMON peut porter…\p"
	.string "C'est sûr, c'est pas facile d'arriver\n"
	.string "à tout noter…$"

RustboroCity_PokemonSchool_Text_2147A2: @ 82147A2
	.string "C'est le carnet de cet étudiant…\p"
	.string "On attrape les POKéMON avec des\n"
	.string "POKé BALLS.\p"
	.string "Jusqu'à six POKéMON peuvent\n"
	.string "accompagner un DRESSEUR.\p"
	.string "Un DRESSEUR est une personne\n"
	.string "qui attrape des POKéMON, les fait\l"
	.string "progresser et se bat avec eux.\p"
	.string "L'objectif du DRESSEUR est de battre\n"
	.string "les puissants CHAMPIONS qui attendent\l"
	.string "les adversaires dans les ARENES POKéMON.$"

RustboroCity_PokemonSchool_Text_2148C0: @ 82148C0
	.string "Salut! On s'est déjà vus, non?\n"
	.string "Je crois que c'était à CLEMENTI-VILLE.\p"
	.string "Je me présente. Je m'appelle SCOTT.\p"
	.string "Je voyage un peu partout à la recherche\n"
	.string "de DRESSEURS de talent.\p"
	.string "Plus précisément, je recherche des\n"
	.string "experts en combats de POKéMON.\p"
	.string "Alors dis-moi, qu'est-ce qui t'amène\n"
	.string "dans cette ECOLE? Es-tu aussi\l"
	.string "un DRESSEUR?\p"
	.string "La première chose que tu devrais faire\n"
	.string "est d'enseigner la capacité COUPE à\l"
	.string "un de tes POKéMON.\p"
	.string "Si je me souviens bien, quelqu'un\n"
	.string "dans cette ville possède COUPE.$"

RustboroCity_PokemonSchool_Text_214A5F: @ 8214A5F
	.string "SCOTT: Hmm…\p"
	.string "Je ne connais pas le niveau de ces\n"
	.string "étudiants, mais il y a du potentiel.$"

RustboroCity_PokemonSchool_Text_214AB6: @ 8214AB6
	.string "SCOTT: Oh, qu'est-ce que c'est?\p"
	.string "C'est le BADGE ROCHE, n'est-ce pas?\n"
	.string "Je dois dire que je suis impressionné.\p"
	.string "Tu sais, j'aurais beaucoup aimé te voir\n"
	.string "en plein combat.\p"
	.string "Il est difficile d'imaginer quel genre de\n"
	.string "DRESSEUR tu es, à partir d'un\l"
	.string "BADGE de la LIGUE.$"

RustboroCity_PokemonSchool_Text_214B8A: @ 8214B8A
	.string "Salut! On s'est déjà vus, non?\n"
	.string "Je crois que c'était à CLEMENTI-VILLE.\p"
	.string "Je me présente. Je m'appelle SCOTT.\p"
	.string "Je voyage un peu partout à la recherche\n"
	.string "de DRESSEURS de talent.\p"
	.string "Plus précisément, je recherche des\n"
	.string "experts en combats de POKéMON.\p"
	.string "Oh, qu'est-ce que c'est?\p"
	.string "C'est le BADGE ROCHE, n'est-ce pas?\n"
	.string "Je dois dire que je suis impressionné.\p"
	.string "Tu sais, j'aurais beaucoup aimé te voir\n"
	.string "en plein combat.\p"
	.string "Il est difficile d'imaginer quel genre de\n"
	.string "DRESSEUR tu es, à partir d'un\l"
	.string "BADGE de la LIGUE.$"

