BattleFrontier_OutsideWest_MapScripts:: @ 823D3E1
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_MapScript1_23D3E7
	.byte 0

BattleFrontier_OutsideWest_MapScript1_23D3E7: @ 823D3E7
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_23D3F0:: @ 823D3F0
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_23D808, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_OutsideWest_EventScript_23D44E
	message BattleFrontier_OutsideWest_Text_23D89D
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_23D416
	end

BattleFrontier_OutsideWest_EventScript_23D416:: @ 823D416
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, 0
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_23D458
	case 1, BattleFrontier_OutsideWest_EventScript_23D483
	case 2, BattleFrontier_OutsideWest_EventScript_23D4D8
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_23D4D8
	end

BattleFrontier_OutsideWest_EventScript_23D44E:: @ 823D44E
	msgbox BattleFrontier_OutsideWest_Text_23D842, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D458:: @ 823D458
	msgbox BattleFrontier_OutsideWest_Text_23D8F2, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_OutsideWest_EventScript_23D4AE
	msgbox BattleFrontier_OutsideWest_Text_23D94B, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_23D4BA
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_23D483:: @ 823D483
	msgbox BattleFrontier_OutsideWest_Text_23D90E, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_OutsideWest_EventScript_23D4AE
	msgbox BattleFrontier_OutsideWest_Text_23D94B, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_23D4BA
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_23D4AE:: @ 823D4AE
	message BattleFrontier_OutsideWest_Text_23D97A
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_23D416
	end

BattleFrontier_OutsideWest_EventScript_23D4BA:: @ 823D4BA
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	hideobjectat 3, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, 2
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_23D4D8:: @ 823D4D8
	msgbox BattleFrontier_OutsideWest_Text_23D929, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D4E2:: @ 823D4E2
	msgbox BattleFrontier_OutsideWest_Text_23D6F7, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_23D4EB:: @ 823D4EB
	msgbox BattleFrontier_OutsideWest_Text_23D737, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_23D4F4:: @ 823D4F4
	msgbox BattleFrontier_OutsideWest_Text_23D772, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_23D4FD:: @ 823D4FD
	msgbox BattleFrontier_OutsideWest_Text_23D7A6, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D506:: @ 823D4FD
	msgbox BattleFrontier_OutsideWest_Text_23D9DD, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D50F:: @ 823D50F
	msgbox BattleFrontier_OutsideWest_Text_23D99C, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D518:: @ 823D518
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_23DA60
	waitmessage
	applymovement 18, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_23D52D:: @ 823D52D
	msgbox BattleFrontier_OutsideWest_Text_23DABF, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D536:: @ 823D536
	lock
	goto BattleFrontier_OutsideWest_EventScript_23D544
	end

BattleFrontier_OutsideWest_EventScript_23D53D:: @ 823D53D
	lock
	goto BattleFrontier_OutsideWest_EventScript_23D544
	end

BattleFrontier_OutsideWest_EventScript_23D544:: @ 823D544
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_23DB7D, MSGBOX_DEFAULT
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_23DBCE, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement 9, Common_Movement_WalkInPlaceFastestUp
	applymovement 10, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_23D57F:: @ 823D57F
	lock
	faceplayer
	delay 20
	compare VAR_FACING, DIR_NORTH
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5BA
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5C5
	compare VAR_FACING, DIR_WEST
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5BA
	compare VAR_FACING, DIR_EAST
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5BA
	msgbox BattleFrontier_OutsideWest_Text_23DC36, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D5BA:: @ 823D5BA
	applymovement 14, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_23D5C5:: @ 823D5C5
	return

BattleFrontier_OutsideWest_EventScript_23D5C6:: @ 823D5C6
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_23DCB0
	waitmessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5FD
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D608
	compare VAR_FACING, DIR_WEST
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D613
	compare VAR_FACING, DIR_EAST
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D61E
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_23D5FD:: @ 823D5FD
	applymovement 12, BattleFrontier_OutsideWest_Movement_23D629
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_23D608:: @ 823D608
	applymovement 12, BattleFrontier_OutsideWest_Movement_23D62C
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_23D613:: @ 823D613
	applymovement 12, BattleFrontier_OutsideWest_Movement_23D62F
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_23D61E:: @ 823D61E
	applymovement 12, BattleFrontier_OutsideWest_Movement_23D632
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_23D629: @ 823D629
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	step_end

BattleFrontier_OutsideWest_Movement_23D62C: @ 823D62C
	walk_in_place_fastest_up
	walk_in_place_fastest_up
	step_end

BattleFrontier_OutsideWest_Movement_23D62F: @ 823D62F
	walk_in_place_fastest_right
	walk_in_place_fastest_right
	step_end

BattleFrontier_OutsideWest_Movement_23D632: @ 823D632
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	step_end

BattleFrontier_OutsideWest_EventScript_23D635:: @ 823D635
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_23DD3B, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_OutsideWest_EventScript_23D653
	goto BattleFrontier_OutsideWest_EventScript_23D65D
	end

BattleFrontier_OutsideWest_EventScript_23D653:: @ 823D653
	msgbox BattleFrontier_OutsideWest_Text_23DD7A, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D65D:: @ 823D65D
	msgbox BattleFrontier_OutsideWest_Text_23DDAD, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D667:: @ 823D667
	msgbox BattleFrontier_OutsideWest_Text_23DE15, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D670:: @ 823D670
	msgbox BattleFrontier_OutsideWest_Text_23DF7D, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D679:: @ 823D679
	msgbox BattleFrontier_OutsideWest_Text_23DEFD, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D682:: @ 823D682
	msgbox BattleFrontier_OutsideWest_Text_23DEB4, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D68B:: @ 823D68B
	msgbox BattleFrontier_OutsideWest_Text_23DFBF, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D694:: @ 823D694
	msgbox BattleFrontier_OutsideWest_Text_23E01E, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D69D:: @ 823D69D
	msgbox BattleFrontier_OutsideWest_Text_23E09F, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D6A6:: @ 823D6A6
	msgbox BattleFrontier_OutsideWest_Text_23E102, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D6AF:: @ 823D6AF
	msgbox BattleFrontier_OutsideWest_Text_23E154, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D6B8:: @ 823D6B8
	lock
	msgbox BattleFrontier_OutsideWest_Text_23E273, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D6C3:: @ 823D6C3
	lock
	msgbox BattleFrontier_OutsideWest_Text_23E2E9, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D6CE:: @ 823D6CE
	msgbox BattleFrontier_OutsideWest_Text_23E37E, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D6D7:: @ 823D6D7
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_23E410, MSGBOX_DEFAULT
	closemessage
	applymovement 23, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_23D6EE:: @ 823D6EE
	msgbox BattleFrontier_OutsideWest_Text_23E5A5, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_23D6F7: @ 823D6F7
	.string "DOME DE COMBAT\n"
	.string "“La voie toute tracée vers la\l"
	.string "célébrité!”$"

BattleFrontier_OutsideWest_Text_23D737: @ 823D737
	.string "USINE DE COMBAT\n"
	.string "“Nos POKéMON sont les plus forts!”$"

BattleFrontier_OutsideWest_Text_23D772: @ 823D772
	.string "REPTILE DE COMBAT\n"
	.string "“Choisissez un des trois chemins!”$"

BattleFrontier_OutsideWest_Text_23D7A6: @ 823D7A6
	.string "Voici la TOUR DE COMBAT.\p"
	.string "Les DRESSEURS y amènent leurs\n"
	.string "meilleurs POKéMON pour participer à des\l"
	.string "matchs éliminatoires.$"

BattleFrontier_OutsideWest_Text_23D808: @ 823D808
	.string "Bonjour, vous venez pour le ferry?\n"
	.string "Puis-je voir votre PASSE BATEAU?$"

BattleFrontier_OutsideWest_Text_23D842: @ 823D842
	.string "{PLAYER} n'a pas de PASSE BATEAU…\p"
	.string "Je suis absolument désolée.\p"
	.string "Il vous faut un PASSE pour embarquer\n"
	.string "à bord du ferry.$"

BattleFrontier_OutsideWest_Text_23D89D: @ 823D89D
	.string "{PLAYER} montre son PASSE BATEAU.\p"
	.string "Parfait! Vous pouvez entrer!\p"
	.string "Où voulez-vous aller?$"

BattleFrontier_OutsideWest_Text_23D8F2: @ 823D8F2
	.string "POIVRESSEL? C'est parti!$"
	
BattleFrontier_OutsideWest_Text_23D90E: @ 823D90E
	.string "POIVRESSEL? C'est parti!$"

BattleFrontier_OutsideWest_Text_23D929: @ 823D929
	.string "Revenez nous voir une autre fois!$"

BattleFrontier_OutsideWest_Text_23D94B: @ 823D94B
	.string "Veuillez embarquer à bord du ferry et\n"
	.string "attendre le départ.$"

BattleFrontier_OutsideWest_Text_23D97A: @ 823D97A
	.string "Alors, où voulez-vous aller?$"

BattleFrontier_OutsideWest_Text_23D99C: @ 823D99C
	.string "Je suis meilleur que tous mes copains.\n"
	.string "Mais ici…\l"
	.string "Je suis nul!$"

BattleFrontier_OutsideWest_Text_23D9DD: @ 823D9DD
	.string "Je veux aller à la TOUR DE COMBAT,\n"
	.string "mais je ne la trouve pas. Pourtant, j'ai\l"
	.string "une carte de la ZONE DE COMBAT.\p"
	.string "Cet endroit est vraiment immense!$"

BattleFrontier_OutsideWest_Text_23DA60: @ 823DA60
	.string "Mon intention était de relever un défi\n"
	.string "dès mon arrivée ici.\p"
	.string "Mais en chemin, j'ai eu le mal de mer…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_23DABF: @ 823DABF
	.string "Tout le monde ne peut pas venir ici,\n"
	.string "tu sais.\p"
	.string "Seuls les DRESSEURS dont le talent\n"
	.string "a été reconnu sont ici.\p"
	.string "Beaucoup de DRESSEURS n'ont jamais\n"
	.string "entendu parler de la ZONE DE COMBAT.$"

BattleFrontier_OutsideWest_Text_23DB7D: @ 823DB7D
	.string "Dis…\p"
	.string "Tu penses qu'on peut participer même si\n"
	.string "on n'a pas de POKéMON?$"

BattleFrontier_OutsideWest_Text_23DBCE: @ 823DBCE
	.string "Heu…\n"
	.string "Ben, c'est ce qu'on m'a dit.\p"
	.string "Enfin, je crois…\p"
	.string "Et tu te souviens de ce que m'a dit le\n"
	.string "colosse?\p"
	.string "Il m'a dit qu'il me prêterait des\n"
	.string "POKéMON!$"

BattleFrontier_OutsideWest_Text_23DC36: @ 823DC36
	.string "C'est l'USINE DE COMBAT.\n"
	.string "Tu peux y louer des POKéMON très forts.\p"
	.string "Mais au fait… Je me demande\n"
	.string "qui élève ces POKéMON de location!?!$"

BattleFrontier_OutsideWest_Text_23DCB0: @ 823DCB0
	.string "J'ai peur d'aller au REPTILE DE COMBAT\n"
	.string "à cause de SEVIPER…\p"
	.string "Mais je ne suis pas venue ici pour rien!\n"
	.string "Je vais me battre!\l"
	.string "… J'ai peur…$"

BattleFrontier_OutsideWest_Text_23DD3B: @ 823DD3B
	.string "Jouons à pierre, papier, ciseaux!\n"
	.string "Un, deux, trois!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_23DD7A: @ 823DD7A
	.string "Oui! J'ai gagné! Je vais relever le défi\n"
	.string "du REPTILE DE COMBAT!$"

BattleFrontier_OutsideWest_Text_23DDAD: @ 823DDAD
	.string "Oh, non…\n"
	.string "J'ai perdu.\p"
	.string "Ce n'est pas mon jour de chance.\n"
	.string "Je vais attendre demain pour relever le\l"
	.string "défi du REPTILE DE COMBAT.$"

BattleFrontier_OutsideWest_Text_23DE15: @ 823DE15
	.string "Je suis persuadé que je suis la seule\n"
	.string "personne ici qui préfère la pêche aux\l"
	.string "combats.\p"
	.string "Comment? Il n'y a rien à pêcher ici?\n"
	.string "C'est dommage, c'est un bel endroit…$"

BattleFrontier_OutsideWest_Text_23DEB4: @ 823DEB4
	.string "Aujourd'hui, je n'arrêterai de combattre\n"
	.string "que quand j'aurai un symbole!$"

BattleFrontier_OutsideWest_Text_23DEFD: @ 823DEFD
	.string "Tu veux relever le défi du DOME DE\n"
	.string "COMBAT?\p"
	.string "Je te souhaite bonne chance.\n"
	.string "Ce serait amusant, si l'on se retrouvait\l"
	.string "face à face lors d'un combat.$"

BattleFrontier_OutsideWest_Text_23DF7D: @ 823DF7D
	.string "Papy, par ici!\n"
	.string "Le DOME DE COMBAT est là!\l"
	.string "Vas-y, papy!$"

BattleFrontier_OutsideWest_Text_23DFBF: @ 823DFBF
	.string "C'est donc ça, le DOME DE COMBAT?\n"
	.string "Aucun GENTLEMAN ne pourra me battre!\p"
	.string "Mais où est l'entrée?$"

BattleFrontier_OutsideWest_Text_23E01E: @ 823E01E
	.string "Il n'y a pas si longtemps, il n'y avait\n"
	.string "rien à cet endroit.\p"
	.string "Mais maintenant, regarde! Incroyable!\n"
	.string "Il faut que j'emmène ma mère ici.$"

BattleFrontier_OutsideWest_Text_23E09F: @ 823E09F
	.string "Je suis enfin arrivée à la ZONE DE\n"
	.string "COMBAT!\p"
	.string "Mon physique avantageux et ma\n"
	.string "technique me feront sûrement gagner!$"

BattleFrontier_OutsideWest_Text_23E102: @ 823E102
	.string "Miam, miam…\p"
	.string "On dirait que tout le monde est très\n"
	.string "fort ici.\p"
	.string "Miam, miam…$"

BattleFrontier_OutsideWest_Text_23E154: @ 823E154
	.string "Miam, miam…\p"
	.string "Il y a un certain temps, j'ai rencontré\n"
	.string "cette femme au REPTILE DE COMBAT.\p"
	.string "Elle avait un regard effrayant, ça m'a\n"
	.string "fichu la frousse.\p"
	.string "Miam, miam…\p"
	.string "Elle m'a hurlé dessus: “Arrête de\n"
	.string "manger!” et s'est mise à rire!\p"
	.string "J'en ai eu la chair de poule…\n"
	.string "J'entends encore son rire…\p"
	.string "Miam, miam…$"

BattleFrontier_OutsideWest_Text_23E273: @ 823E273
	.string "Non mais, écoute ce que tu dis!\n"
	.string "Ça ne veut rien dire, ça!\p"
	.string "Lors du dernier match, il m'a regardée\n"
	.string "et j'ai vu des étincelles dans ses yeux!$"

BattleFrontier_OutsideWest_Text_23E2E9: @ 823E2E9
	.string "Quoi???\n"
	.string "Pfft!\p"
	.string "Si je n'avais pas été assis à côté de\n"
	.string "toi, il ne t'aurait même pas regardée!\p"
	.string "Ce sont mes encouragements qui ont\n"
	.string "attiré le regard de la STAR DU DOME!$"

BattleFrontier_OutsideWest_Text_23E37E: @ 823E37E
	.string "Oh, chut!\n"
	.string "Mettez-la un peu en sourdine!\p"
	.string "Vous, les fans, vous devriez vous\n"
	.string "contenter des CHAMPION D'ARENE!\p"
	.string "La STAR DU DOME est à moi!\n"
	.string "C'est mon idole!$"

BattleFrontier_OutsideWest_Text_23E410: @ 823E410
	.string "Ces gens qui se disputent là-bas…\p"
	.string "C'est dur à croire, mais ils étaient\n"
	.string "DRESSEURS, avant. Ils étaient bons.\p"
	.string "Ils avaient une force incroyable et ils\n"
	.string "étaient même célèbres!\p"
	.string "Mais ils se sont fait écraser par un\n"
	.string "DRESSEUR lors d'un tournoi.\p"
	.string "Leur défaite a été telle qu'ils ont été\n"
	.string "subjugués par lui.\p"
	.string "Maintenant, ce sont des fans.\n"
	.string "Ils vont au DOME DE COMBAT\l"
	.string "tous les jours pour l'encourager.$"

BattleFrontier_OutsideWest_Text_23E5A5: @ 823E5A5
	.string "Il paraît que quelqu'un a vu un POKéMON\n"
	.string "avec une queue incroyablement\l"
	.string "longue dans la ZONE DE COMBAT.\p"
	.string "Il doit être adorable…\p"
	.string "Les défis peuvent bien attendre!\n"
	.string "Je vais tenter de trouver cette\l"
	.string "charmante créature!$"

