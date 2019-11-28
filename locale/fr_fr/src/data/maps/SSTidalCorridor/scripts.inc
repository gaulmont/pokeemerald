SSTidalCorridor_MapScripts:: @ 823BFCF
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_MapScript2_23BFD5
	.byte 0

SSTidalCorridor_MapScript2_23BFD5: @ 823BFD5
	map_script_2 VAR_SS_TIDAL_SCOTT_STATE, 0, SSTidalCorridor_EventScript_23C219
	map_script_2 VAR_PORTHOLE_STATE, 1, SSTidalCorridor_EventScript_23BFFF
	map_script_2 VAR_PORTHOLE_STATE, 5, SSTidalCorridor_EventScript_23C015
	map_script_2 VAR_PORTHOLE_STATE, 9, SSTidalCorridor_EventScript_23C067
	map_script_2 VAR_PORTHOLE_STATE, 10, SSTidalCorridor_EventScript_23C07D
	.2byte 0

SSTidalCorridor_EventScript_23BFFF:: @ 823BFFF
	special SetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 2
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C462, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_23C015:: @ 823C015
	setvar VAR_PORTHOLE_STATE, 6
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C4E3, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_23C028:: @ 823C028
	special SetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 7
	playse SE_PINPON
	msgbox SSTidalRooms_Text_23C462, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_23C03C:: @ 823C03C
	special ResetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 4
	playse SE_PINPON
	msgbox SSTidalRooms_Text_23C553, MSGBOX_DEFAULT
	return

SSTidalCorridor_EventScript_23C050:: @ 823C050
	compare VAR_PORTHOLE_STATE, 2
	goto_if_eq SSTidalCorridor_EventScript_23C067
	compare VAR_PORTHOLE_STATE, 7
	goto_if_eq SSTidalCorridor_EventScript_23C07D
	end

SSTidalCorridor_EventScript_23C067:: @ 823C067
	special ResetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 3
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C4E3, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_23C07D:: @ 823C07D
	special ResetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 8
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C50F, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_23C093:: @ 823C093
	special ResetSSTidalFlag
	setvar VAR_PORTHOLE_STATE, 8
	playse SE_PINPON
	msgbox SSTidalRooms_Text_23C50F, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_23C0A7:: @ 823C0A7
	switch VAR_PORTHOLE_STATE
	case 2, SSTidalRooms_EventScript_23C03C
	case 3, SSTidalRooms_EventScript_23C03C
	case 6, SSTidalRooms_EventScript_23C028
	case 7, SSTidalRooms_EventScript_23C093
	return

SSTidalCorridor_EventScript_23C0D9:: @ 823C0D9
	msgbox SSTidalCorridor_Text_23C6EC, MSGBOX_NPC
	end

SSTidalCorridor_EventScript_23C0E2:: @ 823C0E2
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox SSTidalCorridor_Text_23C7E1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SSTidalCorridor_EventScript_23C0F5:: @ 823C0F5
	msgbox SSTidalCorridor_Text_23C7F8, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_23C0FE:: @ 823C0FE
	msgbox SSTidalCorridor_Text_23C800, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_23C107:: @ 823C107
	msgbox SSTidalCorridor_Text_23C808, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_23C110:: @ 823C110
	msgbox SSTidalCorridor_Text_23C810, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_23C119:: @ 823C119
	lock
	faceplayer
	compare VAR_PORTHOLE_STATE, 4
	goto_if_eq SSTidalCorridor_EventScript_23C13B
	compare VAR_PORTHOLE_STATE, 8
	goto_if_eq SSTidalCorridor_EventScript_23C15A
	msgbox SSTidalCorridor_Text_23C596, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_23C13B:: @ 823C13B
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	msgbox SSTidalCorridor_Text_23C64F, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM49, SSTidalCorridor_EventScript_23C179
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_23C15A:: @ 823C15A
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	msgbox SSTidalCorridor_Text_23C64F, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM49, SSTidalCorridor_EventScript_23C179
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_23C179:: @ 823C179
	setflag FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER
	return

SSTidalCorridor_EventScript_23C17D:: @ 823C17D
	lockall
	compare VAR_PORTHOLE_STATE, 2
	goto_if_eq SSTidalCorridor_EventScript_23C19E
	compare VAR_PORTHOLE_STATE, 7
	goto_if_eq SSTidalCorridor_EventScript_23C19E
	msgbox SSTidalCorridor_Text_23C6C3, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_23C19E:: @ 823C19E
	special sub_80FB7A4
	waitstate
	end

SSTidalCorridor_EventScript_23C1A3:: @ 823C1A3
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SS_TIDAL_TRAINERS, SSTidalCorridor_EventScript_23C1BD
	call SSTidalCorridor_EventScript_23C1C7
	msgbox SSTidalCorridor_Text_23C65E, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_23C1BD:: @ 823C1BD
	msgbox SSTidalCorridor_Text_23C6B0, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_23C1C7:: @ 823C1C7
	checktrainerflag TRAINER_PHILLIP
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_LEONARD
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_COLTON
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_MICAH
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_THOMAS
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_LEA_AND_JED
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_GARRET
	goto_if_lt SSTidalCorridor_EventScript_23C218
	checktrainerflag TRAINER_NAOMI
	goto_if_lt SSTidalCorridor_EventScript_23C218
	setflag FLAG_DEFEATED_SS_TIDAL_TRAINERS
	goto SSTidalCorridor_EventScript_23C1BD
	return

SSTidalCorridor_EventScript_23C218:: @ 823C218
	return

SSTidalCorridor_EventScript_23C219:: @ 823C219
	lockall
	applymovement 5, SSTidalCorridor_Movement_23C26D
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox SSTidalCorridor_Text_23C28F, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, SSTidalCorridor_Movement_23C27D
	applymovement 1, SSTidalCorridor_Movement_23C284
	applymovement 5, SSTidalCorridor_Movement_23C275
	waitmovement 0
	playse SE_KAIDAN
	waitse
	removeobject 5
	applymovement 1, SSTidalCorridor_Movement_23C28B
	waitmovement 0
	delay 30
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
	setvar VAR_SS_TIDAL_SCOTT_STATE, 1
	releaseall
	end

SSTidalCorridor_Movement_23C26D: @ 823C26D
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SSTidalCorridor_Movement_23C275: @ 823C275
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SSTidalCorridor_Movement_23C27D: @ 823C27D
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_down
	step_end

SSTidalCorridor_Movement_23C284: @ 823C284
	delay_16
	walk_right
	walk_right
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_left
	step_end

SSTidalCorridor_Movement_23C28B: @ 823C28B
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

SSTidalCorridor_Text_23C28F: @ 823C28F
	.string "SCOTT: Hé, bonjour, bonjour!\n"
	.string "{PLAYER}{KUN}, {PLAYER}{KUN}!\p"
	.string "Je suis pressé là, mais ça me fait\n"
	.string "plaisir de te voir!\p"
	.string "Félicitations, MAITRE de la LIGUE!\p"
	.string "Il y a un endroit où j'aimerais t'inviter.\n"
	.string "C'est pour les gens comme toi.\p"
	.string "C'est la…\n"
	.string "ZONE DE COMBAT!\p"
	.string "A quoi ça ressemble?\n"
	.string "Tu verras bien quand tu y seras!\p"
	.string "J'en ai justement parlé avec le\n"
	.string "CAPITAINE.\p"
	.string "La prochaine fois que tu prendras ce\n"
	.string "ferry, tu pourras demander à ce qu'on\l"
	.string "t'emmène dans la ZONE DE COMBAT.\p"
	.string "Bien, {PLAYER}{KUN}. A bientôt dans la \n"
	.string "ZONE DE COMBAT, j'espère!$"

SSTidalCorridor_Text_23C462: @ 823C462
SSTidalRooms_Text_23C462: @ 823C462
	.string "Ce ferry est conçu pour naviguer dans\n"
	.string "les courants rapides.\p"
	.string "Nous espérons que vous apprécierez\n"
	.string "votre voyage\p"
	.string "N'hésitez pas à explorer le navire.$"

SSTidalCorridor_Text_23C4E3: @ 823C4E3
	.string "Nous espérons que vous apprécierez\n"
	.string "votre voyage à bord de notre ferry.$"

SSTidalCorridor_Text_23C50F: @ 823C50F
SSTidalRooms_Text_23C50F: @ 823C50F
	.string "Nous avons touché terre à\n"
	.string "POIVRESSEL.\p"
	.string "Merci d'avoir navigué avec nous.$"

SSTidalRooms_Text_23C553: @ 823C553
	.string "Nous avons touché terre à NENUCRIQUE.\n"
	.string "Merci d'avoir navigué avec nous.$"

SSTidalCorridor_Text_23C596: @ 823C596
	.string "A mon avis, nous ne toucherons pas\n"
	.string "terre avant un petit moment.\p"
	.string "Allez vous reposer dans votre cabine.\n"
	.string "C'est la Nº 2.\p"
	.string "Le lit est mou et épais.\n"
	.string "Croyez-moi, il est confortable!$"

SSTidalCorridor_Text_23C64F: @ 823C64F
	.string "Nous sommes arrivés!$"

SSTidalCorridor_Text_23C65E: @ 823C65E
	.string "N'hésitez pas à entrer dans les\n"
	.string "autres cabines.\p"
	.string "Les DRESSEURS qui s'ennuient sur le\n"
	.string "ferry seront partants pour un combat.$"

SSTidalCorridor_Text_23C6B0: @ 823C6B0
	.string "Amusez-vous bien pendant la croisière!$"

SSTidalCorridor_Text_23C6C3: @ 823C6C3
	.string "Le hublot offre une belle vue sur\n"
	.string "l'horizon.$"

SSTidalCorridor_Text_23C6EC: @ 823C6EC
	.string "M. MARCO: Bienvenue à bord, {PLAYER}{KUN}!\p"
	.string "Ils m'ont nommé capitaine du MARINA,\n"
	.string "à titre honorifique!\p"
	.string "Tu peux m'appeler CAPITAINE MARCO,\n"
	.string "maintenant!\p"
	.string "Tu sais, j'avais pris ma retraite, mais\n"
	.string "quand j'ai vu ce magnifique bateau…\p"
	.string "Disons simplement que ça a réveillé\n"
	.string "mon âme de marin!$"

SSTidalCorridor_Text_23C7E1: @ 823C7E1
	.string "PIKO: Pihioo pihikooo…$"

SSTidalCorridor_Text_23C7F8: @ 823C7F8
	.string "Cabine 1$"

SSTidalCorridor_Text_23C800: @ 823C800
	.string "Cabine 2$"

SSTidalCorridor_Text_23C808: @ 823C808
	.string "Cabine 3$"

SSTidalCorridor_Text_23C810: @ 823C810
	.string "Cabine 4$"
