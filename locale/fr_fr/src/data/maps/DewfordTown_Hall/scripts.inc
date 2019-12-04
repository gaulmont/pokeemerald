DewfordTown_Hall_MapScripts:: @ 81FD4CF
	.byte 0

DewfordTown_Hall_EventScript_1FD4D0:: @ 81FD4D0
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	special TrendyPhraseIsOld
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Hall_EventScript_1FD4EF
	msgbox DewfordTown_Hall_Text_1FD818, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD4EF:: @ 81FD4EF
	msgbox DewfordTown_Hall_Text_1FD877, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD4F9:: @ 81FD4F9
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FD8ED, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD50A:: @ 81FD50A
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	special sub_811EF6C
	msgbox DewfordTown_Hall_Text_1FD948, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Hall_EventScript_1FD533
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_Hall_EventScript_1FD53D
	end

DewfordTown_Hall_EventScript_1FD533:: @ 81FD533
	msgbox DewfordTown_Hall_Text_1FD9B3, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD53D:: @ 81FD53D
	msgbox DewfordTown_Hall_Text_1FDA06, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD547:: @ 81FD547
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FDA5C, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_1FD563:: @ 81FD563
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FDA99, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_1FD57F:: @ 81FD57F
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FDAC4, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1FD590:: @ 81FD590
	lockall
	call DewfordTown_Hall_EventScript_271E8B
	msgbox DewfordTown_Hall_Text_1FDB89, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD5A0:: @ 81FD5A0
	lockall
	call DewfordTown_Hall_EventScript_271E8B
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_1FD607
	case 4, DewfordTown_Hall_EventScript_1FD607
	case 1, DewfordTown_Hall_EventScript_1FD611
	case 5, DewfordTown_Hall_EventScript_1FD607
	case 2, DewfordTown_Hall_EventScript_1FD61B
	case 6, DewfordTown_Hall_EventScript_1FD61B
	case 3, DewfordTown_Hall_EventScript_1FD625
	case 7, DewfordTown_Hall_EventScript_1FD61B
	end

DewfordTown_Hall_EventScript_1FD607:: @ 81FD607
	msgbox DewfordTown_Hall_Text_1FDC05, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD611:: @ 81FD611
	msgbox DewfordTown_Hall_Text_1FDC21, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD61B:: @ 81FD61B
	msgbox DewfordTown_Hall_Text_1FDC3C, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD625:: @ 81FD625
	msgbox DewfordTown_Hall_Text_1FDC57, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD62F:: @ 81FD62F
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_1FD647
	end

DewfordTown_Hall_EventScript_1FD63B:: @ 81FD63B
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_1FD647
	end

DewfordTown_Hall_EventScript_1FD647:: @ 81FD647
	call DewfordTown_Hall_EventScript_271E8B
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_1FD6AD
	case 1, DewfordTown_Hall_EventScript_1FD6AD
	case 2, DewfordTown_Hall_EventScript_1FD6C9
	case 3, DewfordTown_Hall_EventScript_1FD6C9
	case 4, DewfordTown_Hall_EventScript_1FD6E5
	case 5, DewfordTown_Hall_EventScript_1FD6E5
	case 6, DewfordTown_Hall_EventScript_1FD701
	case 7, DewfordTown_Hall_EventScript_1FD71D
	end

DewfordTown_Hall_EventScript_1FD6AD:: @ 81FD6AD
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FDC76, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FDCE2, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD6C9:: @ 81FD6C9
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FDD95, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FDE0E, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD6E5:: @ 81FD6E5
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FDE77, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FDED8, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD701:: @ 81FD701
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FDF72, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FDFF1, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD71D:: @ 81FD71D
	call DewfordTown_Hall_EventScript_1FD73A
	msgbox DewfordTown_Hall_Text_1FE09A, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_1FD772
	msgbox DewfordTown_Hall_Text_1FE0F2, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1FD739:: @ 81FD739
	return

DewfordTown_Hall_EventScript_1FD73A:: @ 81FD73A
	applymovement 8, DewfordTown_Hall_Movement_1FD7D6
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq DewfordTown_Hall_EventScript_1FD75B
	compare VAR_0x8008, 1
	goto_if_eq DewfordTown_Hall_EventScript_1FD771
	end

DewfordTown_Hall_EventScript_1FD75B:: @ 81FD75B
	compare VAR_FACING, DIR_EAST
	goto_if_eq DewfordTown_Hall_EventScript_1FD739
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_1FD771:: @ 81FD771
	return

DewfordTown_Hall_EventScript_1FD772:: @ 81FD772
	applymovement 7, DewfordTown_Hall_Movement_1FD7D8
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq DewfordTown_Hall_EventScript_1FD793
	compare VAR_0x8008, 1
	goto_if_eq DewfordTown_Hall_EventScript_1FD7C0
	end

DewfordTown_Hall_EventScript_1FD793:: @ 81FD793
	compare VAR_FACING, DIR_NORTH
	call_if_eq DewfordTown_Hall_EventScript_1FD7AA
	compare VAR_FACING, DIR_SOUTH
	call_if_eq DewfordTown_Hall_EventScript_1FD7B5
	return

DewfordTown_Hall_EventScript_1FD7AA:: @ 81FD7AA
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_1FD7B5:: @ 81FD7B5
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_1FD7C0:: @ 81FD7C0
	compare VAR_FACING, DIR_WEST
	goto_if_eq DewfordTown_Hall_EventScript_1FD739
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_1FD7D6: @ 81FD7D6
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_1FD7D8: @ 81FD7D8
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_1FD7DA:: @ 81FD7DA
	lock
	faceplayer
	call DewfordTown_Hall_EventScript_271E8B
	goto_if_set FLAG_RECEIVED_TM36, DewfordTown_Hall_EventScript_1FD80E
	msgbox DewfordTown_Hall_Text_1FE142, MSGBOX_DEFAULT
	giveitem_std ITEM_TM36
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM36
	release
	end

DewfordTown_Hall_EventScript_1FD80E:: @ 81FD80E
	msgbox DewfordTown_Hall_Text_1FE1ED, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_1FD818: @ 81FD818
	.string "Qu'est-ce qui est à la mode? Heu, sans\n"
	.string "doute “{STR_VAR_1}”!\p"
	.string "Je n'imagine pas la vie sans\n"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_1FD877: @ 81FD877
	.string "Qu'est-ce qui est à la mode? Heu, sans\n"
	.string "doute “{STR_VAR_1}”!\p"
	.string "Mais ça commence à me lasser.\p"
	.string "Je vais trouver un nouveau truc\n"
	.string "à la mode.$"

DewfordTown_Hall_Text_1FD8ED: @ 81FD8ED
	.string "J'essaie d'apprendre\n"
	.string "“{STR_VAR_1}” à mon\l"
	.string "POKéMON, mais ça ne marche pas bien.\p"
	.string "Ça doit être un peu trop compliqué.$"

DewfordTown_Hall_Text_1FD948: @ 81FD948
	.string "En ce moment, j'étudie cette mode du\n"
	.string "“{STR_VAR_1}”.\p"
	.string "C'est vrai qu'il y a un lien solide entre\n"
	.string "“{STR_VAR_1}”\l"
	.string "et “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_1FD9B3: @ 81FD9B3
	.string "Oh!\n"
	.string "J'ai eu une bonne intuition, alors!\p"
	.string "Je dois être encore branché,\n"
	.string "yéhé!$"

DewfordTown_Hall_Text_1FDA06: @ 81FDA06
	.string "Quoi?!?\n"
	.string "Vraiment?!?\p"
	.string "Oh, ce n'est pas facile de suivre les\n"
	.string "modes sans se tromper!$"

DewfordTown_Hall_Text_1FDA5C: @ 81FDA5C
	.string "Tout le monde parle de\n"
	.string "“{STR_VAR_1}”…\l"
	.string "N'y aurait-il pas une émission de télé\l"
	.string "là-dessus?$"

DewfordTown_Hall_Text_1FDA99: @ 81FDA99
	.string "De l'autre côté de l'océan?\p"
	.string "Tu crois que “{STR_VAR_1}”\n"
	.string "est encore plus célèbre de l'autre\l"
	.string "côté de l'océan?$"

DewfordTown_Hall_Text_1FDAC4: @ 81FDAC4
	.string "Je collectionne les objets dérivés de\n"
	.string "“{STR_VAR_1}”…\p"
	.string "J'ai les poupées officielles de\n"
	.string "“{STR_VAR_1}”…\p"
	.string "La marque de vêtements officielle de\p"
	.string "“{STR_VAR_1}”…\p"
	.string "Et les albums photos officiels de\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Hé hé, tout ça, c'est à moi!\n"
	.string "Et je ne partagerai rien avec toi!$"

DewfordTown_Hall_Text_1FDB89: @ 81FDB89
	.string "RECONNAITRE LES BONS\n"
	.string "“{STR_VAR_1}”\l"
	.string "ET LES MAUVAIS\l"
	.string "“{STR_VAR_1}”…\p"
	.string "LE LIEN ENTRE\n"
	.string "“{STR_VAR_1}” ET LES\l"
	.string "POKéMON…\p"
	.string "L'UTILITE DE\n"
	.string "“{STR_VAR_1}”…\p"
	.string "C'est vraiment plein de livres sur\n"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_1FDC05: @ 81FDC05
	.string "Le titre est: “L'UTILITE DE'\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_1FDC21: @ 81FDC21
	.string "Le titre est: “LE SOURIRE DE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_1FDC3C: @ 81FDC3C
	.string "Le titre est: “LE DERNIER\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_1FDC57: @ 81FDC57
	.string "Le titre est: “LA NAISSANCE DE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_1FDC76: @ 81FDC76
	.string "J'ai vu “{STR_VAR_1}”!\n"
	.string "Cool, hein?\p"
	.string "C'est le truc le plus génial de la\n"
	.string "journée!\p"
	.string "C'était d'enfer!\n"
	.string "Carrément ahurissant!$"

DewfordTown_Hall_Text_1FDCE2: @ 81FDCE2
	.string "Oh, non, non, non.\p"
	.string "Ce“{STR_VAR_1}”\n"
	.string "que tu prétends avoir vu.\l"
	.string "Ça ne peut pas être ça.\p"
	.string "Le véritable article est beaucoup plus…\n"
	.string "Comment dire?\l"
	.string "Précis et plus mélodieux!\p"
	.string "Ah, pas de doute. C'est étonnant!$"

DewfordTown_Hall_Text_1FDD95: @ 81FDD95
	.string "Hé, écoute, j'ai composé une chanson\n"
	.string "sur “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "est très célèbre, maintenant.\p"
	.string "Bon, écoute!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Super\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_1FDE0E: @ 81FDE0E
	.string "… …\p"
	.string "Si je peux me permettre, mon cher ami,\n"
	.string "tu devrais apprendre à chanter\l"
	.string "avant d'essayer de nous divertir avec\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_1FDE77: @ 81FDE77
	.string "De toute façon, je crois que nous\n"
	.string "devrions organiser une grande fête\l"
	.string "sur l'île en l'honneur de\l"
	.string "“{STR_VAR_1}”.$"

DewfordTown_Hall_Text_1FDED8: @ 81FDED8
	.string "Oh, quelle excellente idée!\p"
	.string "On pourra enfin déterminer qui en\n"
	.string "connaît le plus sur\l"
	.string "“{STR_VAR_1}.”\l"
	.string "C'est une idée de génie, vraiment!\p"
	.string "Dès maintenant, nos vies seront axées\n"
	.string "sur “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_1FDF72: @ 81FDF72
	.string "Mais je me disais…\p"
	.string "Vous ne croyez pas que\n"
	.string "“{STR_VAR_1}”, qui\l"
	.string "n'était qu'une mode, est maintenant\l"
	.string "quelque chose de tout à fait courant?$"

DewfordTown_Hall_Text_1FDFF1: @ 81FDFF1
	.string "Ah, pardon?\n"
	.string "Autant que ça?\p"
	.string "Cependant, il est vrai que\n"
	.string "“{STR_VAR_1}”\l"
	.string "est très présent dans nos esprits,\l"
	.string "même lorsqu'on dort.\p"
	.string "Absolument, tu es le PROF de\n"
	.string "“{STR_VAR_1}”\l"
	.string "mon vieux!$"

DewfordTown_Hall_Text_1FE09A: @ 81FE09A
	.string "Si nous formons une équipe, nous\n"
	.string "serons invincibles, dès qu'il s'agira de\l"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_1FE0F2: @ 81FE0F2
	.string "Bien vu, camarade!\p"
	.string "Nous serons le DUO \n"
	.string "“{STR_VAR_1}”!\p"
	.string "Quelle image respectable, n'est-ce pas?\n"
	.string "Hahahah!$"

DewfordTown_Hall_Text_1FE142: @ 81FE142
	.string "Pour moi, la BOMB-BEURK, c'est le nec\n"
	.string "plus ultra. Pas de doute possible.\p"
	.string "Hein? Tu ne sais pas ce que c'est\n"
	.string "qu'une BOMB-BEURK?\p"
	.string "C'est carrément dommage.\n"
	.string "Je t'en donnerai une.$"

DewfordTown_Hall_Text_1FE1ED: @ 81FE1ED
	.string "J'adore la BOMB-BEURK.\p"
	.string "Mais c'est vrai que l'expression\n"
	.string "“{STR_VAR_1}”\l"
	.string "est pas mal non plus.$"