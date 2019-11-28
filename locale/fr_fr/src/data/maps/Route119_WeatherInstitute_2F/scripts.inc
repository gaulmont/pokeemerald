Route119_WeatherInstitute_2F_MapScripts:: @ 826FF1E
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition: @ 826FF24
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_2F_EventScript_26FF44
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_WeatherInstitute_2F_EventScript_26FF50
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_26FF5C
	end

Route119_WeatherInstitute_2F_EventScript_26FF44:: @ 826FF44
	setobjectxyperm 5, 1, 6
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_26FF50:: @ 826FF50
	setobjectxyperm 5, 4, 6
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_26FF5C:: @ 826FF5C
	setobjectxyperm 5, 2, 2
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_26FF68:: @ 826FF68
	trainerbattle_single TRAINER_GRUNT_37, Route119_WeatherInstitute_2F_Text_270335, Route119_WeatherInstitute_2F_Text_27039F
	msgbox Route119_WeatherInstitute_2F_Text_2703C0, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_26FF7F:: @ 826FF7F
	trainerbattle_single TRAINER_GRUNT_12, Route119_WeatherInstitute_2F_Text_27019C, Route119_WeatherInstitute_2F_Text_270208
	msgbox Route119_WeatherInstitute_2F_Text_27022B, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_26FF96:: @ 826FF96
	trainerbattle_single TRAINER_GRUNT_13, Route119_WeatherInstitute_2F_Text_270292, Route119_WeatherInstitute_2F_Text_2702CE
	msgbox Route119_WeatherInstitute_2F_Text_2702DA, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_26FFAD:: @ 826FFAD
	trainerbattle_single TRAINER_SHELLY_1, Route119_WeatherInstitute_2F_Text_270409, Route119_WeatherInstitute_2F_Text_2704BD, Route119_WeatherInstitute_2F_EventScript_26FFC8
	msgbox Route119_WeatherInstitute_2F_Text_2704E4, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_26FFC8:: @ 826FFC8
	msgbox Route119_WeatherInstitute_2F_Text_2704E4, MSGBOX_DEFAULT
	closemessage
	addobject 7
	applymovement 7, Route119_WeatherInstitute_2F_Movement_270170
	applymovement EVENT_OBJ_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_27017C
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_270568, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_2705DD, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen 1
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 8
	removeobject 7
	applymovement EVENT_OBJ_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_270184
	waitmovement 0
	fadescreen 0
	applymovement 5, Route119_WeatherInstitute_2F_Movement_270187
	waitmovement 0
	copyobjectxytoperm 5
	goto Route119_WeatherInstitute_2F_EventScript_27004D
	end

Route119_WeatherInstitute_2F_EventScript_27004D:: @ 827004D
	msgbox Route119_WeatherInstitute_2F_Text_270650, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_270085
	compare VAR_RESULT, 1
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700AD
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_270085:: @ 8270085
	call Route119_WeatherInstitute_2F_EventScript_2700DB
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700EA
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_2700EA
	end

Route119_WeatherInstitute_2F_EventScript_2700AD:: @ 82700AD
	call Route119_WeatherInstitute_2F_EventScript_2700DB
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700D0
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_2700D0
	end

Route119_WeatherInstitute_2F_EventScript_2700D0:: @ 82700D0
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_2700EA
	end

Route119_WeatherInstitute_2F_EventScript_2700DB:: @ 82700DB
	playfanfare MUS_FANFA4
	message Route119_WeatherInstitute_2F_Text_2706E8
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_2700EA:: @ 82700EA
	msgbox Route119_WeatherInstitute_2F_Text_2706FE, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_2700F7:: @ 82700F7
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartUnusualWeather
	msgbox Route119_WeatherInstitute_2F_Text_27077E, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartUnusualWeather:: @ 827010A
    @ This code uses VAR_0x8004 to count the number of legendaries the player has defeated
    @ already.
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount
	call_if_set FLAG_DEFEATED_GROUDON, WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount
	compare VAR_0x8004, 2
	goto_if_eq WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeated
	call_if_unset FLAG_TEMP_2, WeatherInstitute_UnusualWeather_EventScript_DoCreateUnusualWeather
	specialvar VAR_RESULT, GetUnusualWeatherMapNameAndType
	compare VAR_RESULT, 1
	goto_if_eq WeatherInstitute_UnusualWeather_EventScript_ShowKyogreWeatherMessage
	msgbox WeatherInstitute_UnusualWeather_GroudonWeatherText, MSGBOX_DEFAULT
	release
	end

WeatherInstitute_UnusualWeather_EventScript_ShowKyogreWeatherMessage:: @ 827014F
	msgbox WeatherInstitute_UnusualWeather_KyogreWeatherText, MSGBOX_DEFAULT
	release
	end

WeatherInstitute_UnusualWeather_EventScript_DoCreateUnusualWeather:: @ 8270159
	special CreateUnusualWeatherEvent
	setflag FLAG_TEMP_2
	return

WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount:: @ 8270160
	addvar VAR_0x8004, 1
	return

WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeated:: @ 8270166
	msgbox WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeatedText, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_270170: @ 8270170
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_27017C: @ 827017C
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_fastest_down
	step_end

Route119_WeatherInstitute_2F_Movement_270184: @ 8270184
	slide_down
	walk_in_place_fastest_left
	step_end

Route119_WeatherInstitute_2F_Movement_270187: @ 8270187
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_27018B:: @ 827018B
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_2700F7
	goto Route119_WeatherInstitute_2F_EventScript_27004D
	end

Route119_WeatherInstitute_2F_Text_27019C: @ 827019C
	.string "Le CENTRE METEO a créé un type\n"
	.string "de POKéMON basé sur le climat.\p"
	.string "Nous sommes là pour le voler!$"

Route119_WeatherInstitute_2F_Text_270208: @ 8270208
	.string "Notre plan échoue à cause d'un mioche?$"

Route119_WeatherInstitute_2F_Text_27022B: @ 827022B
	.string "Si le POKéMON qu'ils ont créé peut\n"
	.string "contrôler le climat, la TEAM AQUA doit\l"
	.string "absolument l'avoir!$"

Route119_WeatherInstitute_2F_Text_270292: @ 8270292
	.string "Nous sommes la TEAM AQUA!\n"
	.string "Nous surgissons dès que quelque chose\l"
	.string "de rare se produit!$"

Route119_WeatherInstitute_2F_Text_2702CE: @ 82702CE
	.string "Tu m'as eu!$"

Route119_WeatherInstitute_2F_Text_2702DA: @ 82702DA
	.string "Tu n'as aucune idée de ce que nous,\n"
	.string "la TEAM AQUA, avons l'intention de\l"
	.string "faire! Ne reste pas dans nos pattes!$"

Route119_WeatherInstitute_2F_Text_270335: @ 8270335
	.string "Ne me dis pas que tu cherches le\n"
	.string "POKéMON météo, toi aussi?\p"
	.string "Alors là, non!!!\n"
	.string "Nous étions là avant!$"

Route119_WeatherInstitute_2F_Text_27039F: @ 827039F
	.string "Tu jettes un œil à mes POKéMON?$"

Route119_WeatherInstitute_2F_Text_2703C0: @ 82703C0
	.string "Alors?\n"
	.string "Ce que nous voulons…\p"
	.string "Ce que nous voulons vraiment n'est\n"
	.string "pas ici…$"

Route119_WeatherInstitute_2F_Text_270409: @ 8270409
	.string "Ha, ha, ha, ha, ha!\p"
	.string "Tu veux te mêler des affaires de la\n"
	.string "TEAM AQUA?\p"
	.string "Soit tu es intrépide, soit tu es\n"
	.string "complètement stupide, ou les deux!\p"
	.string "Tu es tellement chou, c'est dégoûtant!\n"
	.string "Je vais t'apprendre la vie, sale mioche!$"

Route119_WeatherInstitute_2F_Text_2704BD: @ 82704BD
	.string "Ha, ha, ha, ha, ha! Tu es tellement\n"
	.string "balèze, c'est dégoûtant!$"

Route119_WeatherInstitute_2F_Text_2704E4: @ 82704E4
	.string "On en avait déjà marre de la TEAM MAGMA,\n"
	.string "et maintenant te voilà!\p"
	.string "Mais qu'est-ce que tu viens fouiner ici?$"

Route119_WeatherInstitute_2F_Text_270568: @ 8270568
	.string "On a un problème!\p"
	.string "Un groupe de la TEAM MAGMA vient de\n"
	.string "passer devant le CENTRE METEO.\p"
	.string "Ils se dirigeaient vers le MONT MEMORIA!$"

Route119_WeatherInstitute_2F_Text_2705DD: @ 82705DD
	.string "Quoi?!?\p"
	.string "Ne perdons pas de temps!\n"
	.string "Vite, au MONT MEMORIA!\p"
	.string "Ahhh!\n"
	.string "On va lui apprendre à vivre, à cette\l"
	.string "TEAM MAGMA!$"

Route119_WeatherInstitute_2F_Text_270650: @ 8270650
	.string "Merci mille fois!\n"
	.string "Grâce à toi, nous sommes sauvés!\p"
	.string "C'est peut-être une drôle de façon de\n"
	.string "te remercier, mais prends ce POKéMON.$"

Route119_WeatherInstitute_2F_Text_2706B2: @ 82706B2
	.string "Hm? You don't seem to have any room\n"
	.string "for this POKéMON.$"

Route119_WeatherInstitute_2F_Text_2706E8: @ 82706E8
	.string "{PLAYER} reçoit MORPHEO!$"

Route119_WeatherInstitute_2F_Text_2706FE: @ 82706FE
	.string "Ce POKéMON change de forme en\n"
	.string "fonction des conditions météo.\p"
	.string "On en a plusieurs au CENTRE METEO.\n"
	.string "Vas-y, prends-le.$"

Route119_WeatherInstitute_2F_Text_27077E: @ 827077E
	.string "Je fais des études sur la pluie depuis\n"
	.string "des années, mais c'est ridicule de\l"
	.string "croire qu'il est possible de contrôler\l"
	.string "le temps.$"

WeatherInstitute_UnusualWeather_GroudonWeatherText: @ 82707F1
	.string "J'étudie les conditions météo dans\n"
	.string "la région de HOENN.\p"
	.string "Nous observons actuellement une\n"
	.string "sécheresse sur la {STR_VAR_1}.\p"
	.string "Enfin, quelque part dans cette\n"
	.string "zone…$"

WeatherInstitute_UnusualWeather_KyogreWeatherText: @ 8270873
	.string "J'étudie les conditions météo dans\n"
	.string "la région de HOENN.\p"
	.string "Nous enregistrons actuellement de\n"
	.string "fortes pluies sur le {STR_VAR_1}.\p"
	.string "Enfin, quelque part dans cette\n"
	.string "zone…$"

WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeatedText: @ 82708FC
	.string "Pas de conditions météo anormales\n"
	.string "enregistrées actuellement.\p"
	.string "Les chutes de pluie occasionnelles\n"
	.string "sont une vraie bénédiction.$"

