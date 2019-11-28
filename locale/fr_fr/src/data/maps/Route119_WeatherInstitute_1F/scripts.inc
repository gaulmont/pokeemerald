Route119_WeatherInstitute_1F_MapScripts:: @ 826FA86
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition: @ 826FA8C
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_1F_EventScript_26FA98
	end

Route119_WeatherInstitute_1F_EventScript_26FA98:: @ 826FA98
	setobjectxyperm 5, 0, 5
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_26FAA4:: @ 826FAA4
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_26FABE
	msgbox Route119_WeatherInstitute_1F_Text_26FCE5, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_26FABE:: @ 826FABE
	msgbox Route119_WeatherInstitute_1F_Text_26FCB7, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_26FAC8:: @ 826FAC8
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_26FB05
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_26FAFF
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_26FAFF
	compare VAR_0x8004, 2
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_26FB05
	msgbox Route119_WeatherInstitute_1F_Text_26FDE8, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_26FAFF:: @ 826FAFF
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_26FB05:: @ 826FB05
	msgbox Route119_WeatherInstitute_1F_Text_26FD2E, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_26FB0F:: @ 826FB0F
	msgbox Route119_WeatherInstitute_1F_Text_26FE94, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_26FB18:: @ 826FB18
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_26FEFC, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_26FB29:: @ 826FB29
	trainerbattle_single TRAINER_GRUNT_11, Route119_WeatherInstitute_1F_Text_26FB57, Route119_WeatherInstitute_1F_Text_26FBBB
	msgbox Route119_WeatherInstitute_1F_Text_26FBD7, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_26FB40:: @ 826FB40
	trainerbattle_single TRAINER_GRUNT_20, Route119_WeatherInstitute_1F_Text_26FC34, Route119_WeatherInstitute_1F_Text_26FC52
	msgbox Route119_WeatherInstitute_1F_Text_26FC60, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_26FB57: @ 826FB57
	.string "Le CHEF s'intéresse aux recherches\n"
	.string "qu'ils font ici.\l"
	.string "C'est pour ça qu'il nous envoie.\p"
	.string "Occupe-toi de tes oignons!$"

Route119_WeatherInstitute_1F_Text_26FBBB: @ 826FBBB
	.string "Quelle humiliation!\n"
	.string "Se faire battre par un gosse…$"

Route119_WeatherInstitute_1F_Text_26FBD7: @ 826FBD7
	.string "Notre CHEF sait tout.\p"
	.string "Mais je ne suis qu'un SBIRE. Je n'ai\n"
	.string "aucune idée de ce qu'il prépare!$"

Route119_WeatherInstitute_1F_Text_26FC34: @ 826FC34
	.string "Hein?\n"
	.string "Qu'est-ce que ce môme fait ici?$"

Route119_WeatherInstitute_1F_Text_26FC52: @ 826FC52
	.string "Hein?\n"
	.string "J'ai perdu?!?$"

Route119_WeatherInstitute_1F_Text_26FC60: @ 826FC60
	.string "Oh, non… J'ai perdu contre un môme.\n"
	.string "Je vais me prendre un de ces savons…\p"
	.string "Je vais aller me reposer…$"

Route119_WeatherInstitute_1F_Text_26FCB7: @ 826FCB7
	.string "Tout le monde est monté à l'étage\n"
	.string "pendant que je dormais!$"

Route119_WeatherInstitute_1F_Text_26FCE5: @ 826FCE5
	.string "Ouah, tu es super balèze!\p"
	.string "J'aimerais devenir un DRESSEUR DE\n"
	.string "POKéMON comme toi!$"

Route119_WeatherInstitute_1F_Text_26FD2E: @ 826FD2E
	.string "Le PROFESSEUR adore la pluie.\n"
	.string "C'est indéniable.\p"
	.string "Mais s'il continue de pleuvoir, les gens\n"
	.string "auront des ennuis.\p"
	.string "Ça aussi, c'est indéniable.\p"
	.string "Le PROFESSEUR étudie donc la pluie\n"
	.string "pour savoir si elle peut être bénéfique.$"

Route119_WeatherInstitute_1F_Text_26FDE8: @ 826FDE8
	.string "Au premier étage du CENTRE, nous\n"
	.string "étudions les conditions météo dans la\l"
	.string "région de HOENN.\p"
	.string "Nous avons observé récemment des\n"
	.string "périodes de sécheresse brèves et\l"
	.string "isolées suivies de fortes pluies…$"

Route119_WeatherInstitute_1F_Text_26FE94: @ 826FE94
	.string "Bonjour!\n"
	.string "Tes actions nous ont sauvés!\p"
	.string "Mais je ne comprends pas ce que\n"
	.string "la TEAM AQUA vient faire là-dedans.$"

Route119_WeatherInstitute_1F_Text_26FEFC: @ 826FEFC
	.string "Il y a un lit…\n"
	.string "Je vais me reposer.$"

