BattleFrontier_ReceptionGate_MapScripts:: @ 82661DA
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_MapScript2_2661E9
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition: @ 82661E5
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_MapScript2_2661E9: @ 82661E9
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_2661F3
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_2661F3:: @ 82661F3
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_266580, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_2662D2
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_266229
	end

BattleFrontier_ReceptionGate_EventScript_266229:: @ 8266229
	msgbox BattleFrontier_ReceptionGate_Text_2665B2, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_2665F7, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message BattleFrontier_ReceptionGate_Text_266676
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_266695, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_266703, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	applymovement 2, Common_Movement_WalkInPlaceFastestUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	applymovement 2, Common_Movement_ExclamationMark
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_266733, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BattleFrontier_ReceptionGate_Movement_2662F0
	applymovement 2, BattleFrontier_ReceptionGate_Movement_2662F6
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_2662D7
	applymovement 4, BattleFrontier_ReceptionGate_Movement_2662E0
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_266764, MSGBOX_DEFAULT
	closemessage
	applymovement 4, BattleFrontier_ReceptionGate_Movement_2662E8
	waitmovement 0
	removeobject 4
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_2662D2: @ 82662D2
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_2662D7: @ 82662D7
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

BattleFrontier_ReceptionGate_Movement_2662DD: @ 82662DD
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_2662E0: @ 82662E0
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_2662E8: @ 82662E8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_2662F0: @ 82662F0
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

BattleFrontier_ReceptionGate_Movement_2662F6: @ 82662F6
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

BattleFrontier_ReceptionGate_EventScript_2662FC:: @ 82662FC
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_2665B2, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_266310:: @ 8266310
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_266857, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_266320:: @ 8266320
	message BattleFrontier_ReceptionGate_Text_26689D
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_2663AE
	case 1, BattleFrontier_ReceptionGate_EventScript_2663BC
	case 2, BattleFrontier_ReceptionGate_EventScript_2663CA
	case 3, BattleFrontier_ReceptionGate_EventScript_2663D8
	case 4, BattleFrontier_ReceptionGate_EventScript_2663E6
	case 5, BattleFrontier_ReceptionGate_EventScript_2663F4
	case 6, BattleFrontier_ReceptionGate_EventScript_266402
	case 7, BattleFrontier_ReceptionGate_EventScript_266410
	case 8, BattleFrontier_ReceptionGate_EventScript_26641E
	case 9, BattleFrontier_ReceptionGate_EventScript_26642C
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_26642C
	end

BattleFrontier_ReceptionGate_EventScript_2663AE:: @ 82663AE
	msgbox BattleFrontier_ReceptionGate_Text_2668C2, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663BC:: @ 82663BC
	msgbox BattleFrontier_ReceptionGate_Text_26696F, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663CA:: @ 82663CA
	msgbox BattleFrontier_ReceptionGate_Text_266A34, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663D8:: @ 82663D8
	msgbox BattleFrontier_ReceptionGate_Text_266AC2, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663E6:: @ 82663E6
	msgbox BattleFrontier_ReceptionGate_Text_266B5D, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663F4:: @ 82663F4
	msgbox BattleFrontier_ReceptionGate_Text_266C24, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_266402:: @ 8266402
	msgbox BattleFrontier_ReceptionGate_Text_266CBB, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_266410:: @ 8266410
	msgbox BattleFrontier_ReceptionGate_Text_266D1C, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_26641E:: @ 826641E
	msgbox BattleFrontier_ReceptionGate_Text_266DCB, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_26642C:: @ 826642C
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_266436:: @ 8266436
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_266E66, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_266446:: @ 8266446
	message BattleFrontier_ReceptionGate_Text_266EE0
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_2664A4
	case 1, BattleFrontier_ReceptionGate_EventScript_2664B2
	case 2, BattleFrontier_ReceptionGate_EventScript_2664C0
	case 3, BattleFrontier_ReceptionGate_EventScript_2664CE
	case 4, BattleFrontier_ReceptionGate_EventScript_2664DC
	case 5, BattleFrontier_ReceptionGate_EventScript_2664EA
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_2664EA
	end

BattleFrontier_ReceptionGate_EventScript_2664A4:: @ 82664A4
	msgbox BattleFrontier_ReceptionGate_Text_266F04, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664B2:: @ 82664B2
	msgbox BattleFrontier_ReceptionGate_Text_266F69, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664C0:: @ 82664C0
	msgbox BattleFrontier_ReceptionGate_Text_267080, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664CE:: @ 82664CE
	msgbox BattleFrontier_ReceptionGate_Text_26716A, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664DC:: @ 82664DC
	msgbox BattleFrontier_ReceptionGate_Text_267298, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664EA:: @ 82664EA
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_2664F4:: @ 82664F4
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_267357, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266504
	end

BattleFrontier_ReceptionGate_EventScript_266504:: @ 8266504
	message BattleFrontier_ReceptionGate_Text_26737C
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_26654C
	case 1, BattleFrontier_ReceptionGate_EventScript_26655A
	case 2, BattleFrontier_ReceptionGate_EventScript_266568
	case 3, BattleFrontier_ReceptionGate_EventScript_266576
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_266576
	end

BattleFrontier_ReceptionGate_EventScript_26654C:: @ 826654C
	msgbox BattleFrontier_ReceptionGate_Text_2673A1, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266504
	end

BattleFrontier_ReceptionGate_EventScript_26655A:: @ 826655A
	msgbox BattleFrontier_ReceptionGate_Text_2674F3, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266504
	end

BattleFrontier_ReceptionGate_EventScript_266568:: @ 8266568
	msgbox BattleFrontier_ReceptionGate_Text_26761C, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266504
	end

BattleFrontier_ReceptionGate_EventScript_266576:: @ 8266576
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_266580: @ 8266580
	.string "C'est la première fois que vous venez?\n"
	.string "Par ici, s'il vous plaît!$"

BattleFrontier_ReceptionGate_Text_2665B2: @ 82665B2
	.string "Bienvenue à la ZONE DE COMBAT!\n"
	.string "Le summum des combats de POKéMON!$"

BattleFrontier_ReceptionGate_Text_2665F7: @ 82665F7
	.string "Pour votre première visite, nous devons\n"
	.string "vous délivrer le PASSE ZONE.\p"
	.string "Vous pourrez l'utiliser dans toute la\n"
	.string "ZONE DE COMBAT.\p"
	.string "Tenez!$"

BattleFrontier_ReceptionGate_Text_266676: @ 8266676
	.string "{PLAYER} obtient\n"
	.string "le PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_266695: @ 8266695
	.string "{PLAYER} place la CARTE DE DRESSEUR\n"
	.string "dans le PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_2666C6: @ 82666C6
	.string "Nous espérons que vous passerez un\n"
	.string "agréable moment à la ZONE DE COMBAT!$"

BattleFrontier_ReceptionGate_Text_266703: @ 8266703
	.string "???: Tiens, mais c'est {PLAYER}{KUN}!\n"
	.string "Content de te voir ici!$"

BattleFrontier_ReceptionGate_Text_266733: @ 8266733
	.string "GUIDE: Oh! SCOTT!\n"
	.string "Quel plaisir de vous voir!$"

BattleFrontier_ReceptionGate_Text_266764: @ 8266764
	.string "SCOTT: Je suis très heureux de te\n"
	.string "voir ici!\p"
	.string "J'espère que tu prendras le temps\n"
	.string "de tout visiter.\p"
	.string "Naturellement, j'espère aussi que tu\n"
	.string "profiteras de l'essence même du combat.\p"
	.string "J'ai également une maison ici,\n"
	.string "n'hésite pas à me rendre visite.$"

BattleFrontier_ReceptionGate_Text_266857: @ 8266857
	.string "Je suis là pour vous guider parmi\n"
	.string "les installations de la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_26689D: @ 826689D
	.string "Sur quel bâtiment souhaitez-vous\n"
	.string "avoir des informations?$"

BattleFrontier_ReceptionGate_Text_2668C2: @ 82668C2
	.string "C'est la tour gigantesque considérée\n"
	.string "comme le symbole de la ZONE DE COMBAT.\p"
	.string "Il y a quatre types de SALLES DE\n"
	.string "COMBAT, pour les COMBATS SOLO, DUO,\l"
	.string "MULTI et MULTI LINK.$"

BattleFrontier_ReceptionGate_Text_26696F: @ 826696F
	.string "Le DOME DE COMBAT est un grand\n"
	.string "bâtiment en forme d'œuf.\p"
	.string "Des TOURNOIS DE COMBAT y ont lieu.\p"
	.string "Les TOURNOIS DE COMBAT se jouent en\n"
	.string "COMBATS SOLO ou DUO.$"

BattleFrontier_ReceptionGate_Text_266A34: @ 8266A34
	.string "Le PALACE DE COMBAT est le bâtiment\n"
	.string "rouge à droite dans la ZONE DE COMBAT.\p"
	.string "Il contient deux types de HALLS DE\n"
	.string "COMBAT, pour les COMBATS SOLO et DUO.$"

BattleFrontier_ReceptionGate_Text_266AC2: @ 8266AC2
	.string "Le DOJO DE COMBAT se trouve à la\n"
	.string "droite du centre de la ZONE DE COMBAT.\p"
	.string "Des TOURNOIS K.O. y ont lieu.$"

BattleFrontier_ReceptionGate_Text_266B5D: @ 8266B5D
	.string "L'USINE DE COMBAT est le grand bâtiment\n"
	.string "tout près d'ici.\p"
	.string "On y propose le COMBAT ECHANGE.\p"
	.string "Ce défi peut prendre la forme de\n"
	.string "COMBATS SOLO ou de COMBATS DUO.$"

BattleFrontier_ReceptionGate_Text_266C24: @ 8266C24
	.string "Le REPTILE DE COMBAT est le bâtiment\n"
	.string "qui a la forme d'un POKéMON, à la\l"
	.string "gauche du centre de la ZONE DE COMBAT.\p"
	.string "L'évènement appelé COMBAT HASARD\n"
	.string "y prend place.$"

BattleFrontier_ReceptionGate_Text_266CBB: @ 8266CBB
	.string "La PYRAMIDE DE COMBAT est l'énorme\n"
	.string "pyramide.\p"
	.string "L'évènement appelé COMBAT QUETE\n"
	.string "y a lieu.$"

BattleFrontier_ReceptionGate_Text_266D1C: @ 8266D1C
	.string "Le HALL DE CLASSEMENT se trouve près\n"
	.string "de la TOUR DE COMBAT.\p"
	.string "On peut y consulter les records des\n"
	.string "meilleurs DRESSEURS s'étant battus\l"
	.string "dans la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_266DCB: @ 8266DCB
	.string "Le SERVICE D'ECHANGE se trouve près\n"
	.string "de la TOUR DE COMBAT.\p"
	.string "Vous pouvez y échanger les POINTS DE\n"
	.string "COMBAT obtenus dans la ZONE DE\l"
	.string "COMBAT contre des prix fabuleux.$"

BattleFrontier_ReceptionGate_Text_266E66: @ 8266E66
	.string "Je peux vous expliquer les règles de\n"
	.string "base communes aux défis des différents\l"
	.string "bâtiments de la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_266EE0: @ 8266EE0
	.string "Sur quel sujet désirez-vous obtenir\n"
	.string "des informations?$"

BattleFrontier_ReceptionGate_Text_266F04: @ 8266F04
	.string "Pour tous les défis de la ZONE DE\n"
	.string "COMBAT, vous pouvez choisir entre\l"
	.string "niveau 50 et niveau libre.$"

BattleFrontier_ReceptionGate_Text_266F69: @ 8266F69
	.string "Niveau 50 est ouvert aux POKéMON\n"
	.string "dont le niveau est de 50 ou moins.\p"
	.string "Cependant, aucun des DRESSEURS que\n"
	.string "vous affronterez n'aura de POKéMON\l"
	.string "dont le niveau est inférieur à 50.\p"
	.string "C'est le niveau le plus bas pour les\n"
	.string "combats de la ZONE DE COMBAT.\p"
	.string "Pour commencer, nous vous conseillons\n"
	.string "donc de choisir niveau 50.$"

BattleFrontier_ReceptionGate_Text_267080: @ 8267080
	.string "Niveau libre ne fixe pas de limite au\n"
	.string "niveau des POKéMON participant à\l"
	.string "un défi.\p"
	.string "Le niveau de vos adversaires sera\n"
	.string "ajusté en fonction du niveau de vos\l"
	.string "POKéMON.\p"
	.string "Cependant, aucun des DRESSEURS que\n"
	.string "vous affronterez n'aura de POKéMON\l"
	.string "dont le niveau est inférieur à 60.$"

BattleFrontier_ReceptionGate_Text_26716A: @ 826716A
	.string "Presque tous les POKéMON peuvent\n"
	.string "relever les défis de tous les bâtiments.\p"
	.string "Les OEUFS et certains POKéMON ne\n"
	.string "sont pas autorisés.\p"
	.string "Le nombre de POKéMON nécessaires pour\n"
	.string "participer varie selon l'endroit.\p"
	.string "Cependant, il est impossible d'inscrire\n"
	.string "deux POKéMON identiques.$"

BattleFrontier_ReceptionGate_Text_267298: @ 8267298
	.string "Lorsque vous relevez un défi de la ZONE\n"
	.string "DE COMBAT, il ne faut pas que deux de\l"
	.string "vos POKéMON portent le même objet.\p"
	.string "Assurez-vous que les POKéMON que vous\n"
	.string "voulez inscrire à un défi portent tous\l"
	.string "des objets différents.$"

BattleFrontier_ReceptionGate_Text_267357: @ 8267357
	.string "Je peux tout vous expliquer sur le\n"
	.string "PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_26737C: @ 826737C
	.string "Sur quel sujet désirez-vous obtenir\n"
	.string "des informations?$"

BattleFrontier_ReceptionGate_Text_2673A1: @ 82673A1
	.string "Il y a sept bâtiments dans la ZONE DE\n"
	.string "COMBAT où gagner des symboles.\p"
	.string "Les DRESSEURS qui ont du succès\n"
	.string "peuvent se voir récompensés par des\l"
	.string "symboles.\p"
	.string "Pour obtenir un symbole, un DRESSEUR\n"
	.string "devra peut-être battre plusieurs\l"
	.string "DRESSEURS à la suite et remporter un\l"
	.string "évènement plusieurs fois.\p"
	.string "Obtenir des symboles n'est pas facile.\n"
	.string "Je vous souhaite bonne chance!$"

BattleFrontier_ReceptionGate_Text_2674F3: @ 82674F3
	.string "Il est possible d'enregistrer un combat\n"
	.string "sur votre PASSE ZONE.\p"
	.string "Vous pouvez par exemple enregistrer\n"
	.string "un combat contre un ou plusieurs amis.\p"
	.string "Vous pouvez également enregistrer un\n"
	.string "combat ayant eu lieu dans la ZONE DE\l"
	.string "COMBAT, sauf au REPTILE DE\l"
	.string "COMBAT et dans la PYRAMIDE DE COMBAT.\p"
	.string "Vous pouvez décider d'enregistrer ou\n"
	.string "non à la fin du combat.$"

BattleFrontier_ReceptionGate_Text_26761C: @ 826761C
	.string "Les POINTS DE COMBAT récompensent\n"
	.string "les DRESSEURS qui font de beaux\l"
	.string "combats dans la ZONE DE COMBAT.\p"
	.string "Vous pouvez échanger vos POINTS DE\n"
	.string "COMBAT contre des prix au SERVICE\l"
	.string "D'ECHANGE.$"
