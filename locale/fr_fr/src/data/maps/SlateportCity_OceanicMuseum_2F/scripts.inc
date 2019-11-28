SlateportCity_OceanicMuseum_2F_MapScripts:: @ 820BAFF
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_20BB00:: @ 820BB00
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BD8D, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_AQA_0, 1
	addobject 3
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_20BCE4
	waitmovement 0
	addobject 4
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCF3
	waitmovement 0
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_20BCE8
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCF5
	waitmovement 0
	compare VAR_FACING, DIR_SOUTH
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BC92
	compare VAR_FACING, DIR_EAST
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BC92
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BE40, MSGBOX_DEFAULT
	compare VAR_FACING, DIR_EAST
	call_if_ne SlateportCity_OceanicMuseum_2F_EventScript_20BC9D
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BE69, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BE93, MSGBOX_DEFAULT
	closemessage
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCE2
	waitmovement 0
	compare VAR_FACING, DIR_SOUTH
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BCA8
	compare VAR_FACING, DIR_WEST
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BCB3
	trainerbattle_no_intro TRAINER_GRUNT_14, SlateportCity_OceanicMuseum_2F_Text_20BEE2
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BEFA, MSGBOX_DEFAULT
	closemessage
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCEF
	waitmovement 0
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_20BCE2
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BF35, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_15, SlateportCity_OceanicMuseum_2F_Text_20BF66
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_20BCEF
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BF7A, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject 2
	applymovement 2, SlateportCity_OceanicMuseum_2F_Movement_20BCD8
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCFE
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BFF2, MSGBOX_DEFAULT
	closemessage
	applymovement 2, SlateportCity_OceanicMuseum_2F_Movement_20BCD6
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C059, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen 1
	removeobject 2
	removeobject 3
	removeobject 4
	fadescreen 0
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C2BE, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C36C, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	removeobject 1
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	compare VAR_REGISTER_BIRCH_STATE, 0
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BC8C
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen 0
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BC8C:: @ 820BC8C
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_20BC92:: @ 820BC92
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_20BC9D:: @ 820BC9D
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_20BCA8:: @ 820BCA8
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_20BCBE
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_20BCB3:: @ 820BCB3
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_20BCC2
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_20BCBE: @ 820BCBE
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCC2: @ 820BCC2
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCC8: @ 820BCC8
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCD6: @ 820BCD6
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCD8: @ 820BCD8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCE2: @ 820BCE2
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCE4: @ 820BCE4
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCE8: @ 820BCE8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCEF: @ 820BCEF
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCF3: @ 820BCF3
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCF5: @ 820BCF5
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCFE: @ 820BCFE
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_fastest_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_20BD0A:: @ 820BD0A
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C4F9, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD13:: @ 820BD13
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C566, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD1C:: @ 820BD1C
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C5C6, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD25:: @ 820BD25
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C6C7, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD2E:: @ 820BD2E
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C72F, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD37:: @ 820BD37
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C7C1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD40:: @ 820BD40
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C82F, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD49:: @ 820BD49
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C88B, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD52:: @ 820BD52
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C8E8, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD5B:: @ 820BD5B
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C93A, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD64:: @ 820BD64
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C43F, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD6D:: @ 820BD6D
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C495, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD76:: @ 820BD76
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C4C2, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_20BD8D: @ 820BD8D
	.string "Oui? Si tu cherches POUPE,\n"
	.string "c'est bien moi.\p"
	.string "Ah! Ça doit être ce que j'avais\n"
	.string "commandé à M. ROCHARD de DEVON.\p"
	.string "Merci. Formidable! Nous allons désormais\n"
	.string "pouvoir préparer l'expédition!$"

SlateportCity_OceanicMuseum_2F_Text_20BE40: @ 820BE40
	.string "Hé, hé, hé, pas si vite!\n"
	.string "On va prendre ces pièces!$"

SlateportCity_OceanicMuseum_2F_Text_20BE69: @ 820BE69
	.string "CAPT. POUPE: Qu… quoi?\n"
	.string "Qui êtes-vous, jeunes gens?$"

SlateportCity_OceanicMuseum_2F_Text_20BE93: @ 820BE93
	.string "On est la TEAM AQUA!\p"
	.string "Notre CHEF veut ces pièces!\n"
	.string "Ferme-la et balance-les!$"

SlateportCity_OceanicMuseum_2F_Text_20BEE2: @ 820BEE2
	.string "Aaaaah!\n"
	.string "Se faire battre par un gosse!$"

SlateportCity_OceanicMuseum_2F_Text_20BEFA: @ 820BEFA
	.string "Oh, mon dieu, quel désastre…\n"
	.string "Le CHEF va être furieux…$"

SlateportCity_OceanicMuseum_2F_Text_20BF35: @ 820BF35
	.string "Hum, espèce de mauviette!\n"
	.string "Laisse-moi régler ça!$"

SlateportCity_OceanicMuseum_2F_Text_20BF66: @ 820BF66
	.string "Quoi?!\n"
	.string "Moi aussi, j'ai perdu!$"

SlateportCity_OceanicMuseum_2F_Text_20BF7A: @ 820BF7A
	.string "Et maintenant? Si on ne récupère\n"
	.string "pas les pièces, on est faits!\p"
	.string "Ah, j'avais pas prévu d'être gêné\n"
	.string "par un mouflet qui se mêle de tout!$"

SlateportCity_OceanicMuseum_2F_Text_20BFF2: @ 820BFF2
	.string "Je venais voir pourquoi vous mettiez\n"
	.string "tant de temps à récupérer les pièces et\l"
	.string "je constate que vous êtes retenus par\n"
	.string "un simple mioche!$"

SlateportCity_OceanicMuseum_2F_Text_20C059: @ 820C059
	.string "Nous sommes la TEAM AQUA,\n"
	.string "et nous adorons la mer!\p"
	.string "Moi, je suis ARTHUR, le leader\n"
	.string "de la TEAM AQUA.\p"
	.string "Dis-moi, pourquoi te mêles-tu de\n"
	.string "nos affaires?\p"
	.string "Attends un peu, appartiendrais-tu\n"
	.string "à la TEAM MAGMA?\p"
	.string "Non, ce n'est pas possible, tu ne\n"
	.string "portes pas leur uniforme.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Les POKéMON, les gens, toute la vie\n"
	.string "dépend de la mer.\p"
	.string "C'est pourquoi le but premier de la\n"
	.string "TEAM AQUA est l'expansion de la mer.\p"
	.string "Nous défendons une noble cause.\n"
	.string "Tu ne crois pas?\p"
	.string "Ah, oui…\n"
	.string "Tu es trop jeune pour comprendre.\p"
	.string "Ça ne facilite pas les choses que tu\n"
	.string "ne comprennes pas nos idéaux.\p"
	.string "Mais je te préviens, ne t'avise pas\n"
	.string "de te mêler encore de nos histoires.\p"
	.string "Les conséquences seraient terribles.\p"
	.string "N'oublie pas ce conseil!$"

SlateportCity_OceanicMuseum_2F_Text_20C2BE: @ 820C2BE
	.string "CAPT. POUPE: Tu es…\n"
	.string "Ah oui, tu es {PLAYER}{KUN}…\p"
	.string "En tout cas, que de tension!\n"
	.string "Merci de nous avoir sauvés!\p"
	.string "Ah oui, j'avais presque oublié que tu\n"
	.string "avais apporté les pièces de DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_20C36C: @ 820C36C
	.string "CAPT. POUPE: Zou!\n"
	.string "Il n'y a pas de temps à perdre!\p"
	.string "Il faut qu'on prépare cette expédition\n"
	.string "sous-marine au plus vite.\p"
	.string "Merci encore, mais il faut que j'y\n"
	.string "aille maintenant.\p"
	.string "Mais n'hésite pas à jeter un œil\n"
	.string "ici si tu en as envie.$"

SlateportCity_OceanicMuseum_2F_Text_20C43F: @ 820C43F
	.string "J'ai vu la maquette d'un bateau ici.\p"
	.string "Ça m'a fait penser à l'EPAVE,\n"
	.string "près du VILLAGE MYOKARA…$"

SlateportCity_OceanicMuseum_2F_Text_20C495: @ 820C495
	.string "N'essaie même pas de courir\n"
	.string "dans le MUSEE!$"

SlateportCity_OceanicMuseum_2F_Text_20C4C2: @ 820C4C2
	.string "Waouh, quel sous-marin imposant!\n"
	.string "Je veux faire un tour!$"

SlateportCity_OceanicMuseum_2F_Text_20C4F9: @ 820C4F9
	.string "L'étiquette indique: “ECHANTILLON\n"
	.string "POUR TEST DE LA QUALITE DE L'EAU”.\p"
	.string "La mer forme un seul ensemble, mais\n"
	.string "l'eau est différente selon les régions.$"

SlateportCity_OceanicMuseum_2F_Text_20C566: @ 820C566
	.string "L'étiquette indique: “ECHANTILLON\n"
	.string "POUR TEST DE LA QUALITE DE L'EAU”.\p"
	.string "La salinité de l'eau diffère peut-être\n"
	.string "d'une région à l'autre…$"

SlateportCity_OceanicMuseum_2F_Text_20C5C6: @ 820C5C6
	.string "Une balle en caoutchouc s'allonge\n"
	.string "et rétrécit.\p"
	.string "“Dans la mer, le poids de l'eau\n"
	.string "exerce lui-même une pression.”\p"
	.string "“En eau peu profonde, la pression\n"
	.string "n'est pas très élevée.”\p"
	.string "“Par contre, en profondeur, la pression\n"
	.string "peut atteindre des dizaines de milliers\l"
	.string "de tonnes sur une petite surface.”$"

SlateportCity_OceanicMuseum_2F_Text_20C6C7: @ 820C6C7
	.string "“MAQUETTE DE LA REGION DE HOENN”\p"
	.string "C'est un diorama de la région de HOENN.\p"
	.string "Où est représenté BOURG-EN-VOL?$"

SlateportCity_OceanicMuseum_2F_Text_20C72F: @ 820C72F
	.string "C'est la représentation du mouvement\n"
	.string "de l'eau de mer.\p"
	.string "“Au fond de la mer, les variations de\n"
	.string "certains facteurs tels que la\l"
	.string "température et la salinité provoquent\l"
	.string "le mouvement de l'eau.”$"

SlateportCity_OceanicMuseum_2F_Text_20C7C1: @ 820C7C1
	.string "C'est la représentation du mouvement\n"
	.string "de l'eau de mer.\p"
	.string "“En surface, l'eau de mer circule comme\n"
	.string "des courants poussés par le vent.”$"

SlateportCity_OceanicMuseum_2F_Text_20C82F: @ 820C82F
	.string "“Le ferry LE MARINA\p"
	.string "“Réplique à l'échelle du bateau en\n"
	.string "construction au CHANTIER NAVAL\l"
	.string "DE POUPE.”$"

SlateportCity_OceanicMuseum_2F_Text_20C88B: @ 820C88B
	.string "“SOUS-MARIN D'EXPLORATION 1\p"
	.string "“Réplique du performant sous-marin\n"
	.string "d'exploration des fonds marins.”$"

SlateportCity_OceanicMuseum_2F_Text_20C8E8: @ 820C8E8
	.string "“CAPSULE SUBMERSIBLE\p"
	.string "“Réplique d'une capsule compacte\n"
	.string "pour explorer les fonds marins.”$"

SlateportCity_OceanicMuseum_2F_Text_20C93A: @ 820C93A
	.string "“L'OCEANE\p"
	.string "“Réplique du luxueux paquebot\n"
	.string "qui fait le tour de la planète.”$"
