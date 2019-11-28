JaggedPass_MapScripts:: @ 8230656
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_MapScript1_230666
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_MapScript1_23069C
	.byte 0

JaggedPass_MapScript1_230666: @ 8230666
	setstepcallback STEP_CB_ASH
	compare VAR_JAGGED_PASS_STATE, 0
	call_if_eq JaggedPass_EventScript_230674
	end

JaggedPass_EventScript_230674:: @ 8230674
	checkitem ITEM_MAGMA_EMBLEM, 1
	compare VAR_RESULT, 1
	goto_if_eq JaggedPass_EventScript_230685
	return

JaggedPass_EventScript_230685:: @ 8230685
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition: @ 823068B
	compare VAR_JAGGED_PASS_ASH_WEATHER, 1
	call_if_eq JaggedPass_EventScript_230697
	end

JaggedPass_EventScript_230697:: @ 8230697
	setweather WEATHER_ASH
	doweather
	return

JaggedPass_MapScript1_23069C: @ 823069C
	compare VAR_JAGGED_PASS_STATE, 1
	goto_if_le JaggedPass_EventScript_2306A8
	end

JaggedPass_EventScript_2306A8:: @ 82306A8
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, 1
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, 1
	end

JaggedPass_EventScript_2306BB:: @ 82306BB
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_230DBA, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_KOUKA_M
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, 1
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, 0
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_230718:: @ 8230718
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_230766
	waitse
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_230CCB, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_30, JaggedPass_Text_230D2D
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_230766:: @ 8230766
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_230D65, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_230785:: @ 8230785
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_230888, JaggedPass_Text_2308FF
	msgbox JaggedPass_Text_230916, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_23079C:: @ 823079C
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_230974, JaggedPass_Text_2309B5, JaggedPass_EventScript_2307C8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq JaggedPass_EventScript_2307E4
	msgbox JaggedPass_Text_2309D8, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_2307C8:: @ 82307C8
	special sub_80B4808
	msgbox JaggedPass_Text_230A2C, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_2307E4:: @ 82307E4
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_230A76, JaggedPass_Text_230AAA
	msgbox JaggedPass_Text_230AD7, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_2307FB:: @ 82307FB
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_230B10, JaggedPass_Text_230B50, JaggedPass_EventScript_230827
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq JaggedPass_EventScript_230843
	msgbox JaggedPass_Text_230B93, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_230827:: @ 8230827
	special sub_80B4808
	msgbox JaggedPass_Text_230BC6, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_230843:: @ 8230843
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_230C28, JaggedPass_Text_230C60
	msgbox JaggedPass_Text_230C94, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_23085A:: @ 823085A
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_230DF7, JaggedPass_Text_230E38
	msgbox JaggedPass_Text_230E57, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_230871:: @ 8230871
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_230E8E, JaggedPass_Text_230ECD
	msgbox JaggedPass_Text_230EE3, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_230888: @ 8230888
	.string "Le SENTIER SINUROC du MONT CHIMNEE…\p"
	.string "J'ai toujours rêvé d'un endroit pareil…\p"
	.string "Ce relief accidenté…\n"
	.string "J'adore ça!$"

JaggedPass_Text_2308FF: @ 82308FF
	.string "La défaite me laisse amer!$"

JaggedPass_Text_230916: @ 8230916
	.string "Oui, je peux perdre avec les POKéMON…\p"
	.string "Mais s'il s'agissait de notre amour pour\n"
	.string "la montagne, je te battrais!$"

JaggedPass_Text_230974: @ 8230974
	.string "Tu n'te promènes pas ici par hasard.\n"
	.string "T'es pas là pour pique-niquer.$"

JaggedPass_Text_2309B5: @ 82309B5
	.string "Oooh, non!\n"
	.string "Ce sol est trop bosselé…$"

JaggedPass_Text_2309D8: @ 82309D8
	.string "Tu savais ça?\p"
	.string "Les plus habiles utilisent leur VELO\n"
	.string "pour passer ce col très accidenté.$"

JaggedPass_Text_230A2C: @ 8230A2C
	.string "Tu reviendras un jour par ici?\n"
	.string "Si c'est le cas, j'aimerais bien\l"
	.string "refaire un match avec toi…$"

JaggedPass_Text_230A76: @ 8230A76
	.string "Un pique-nique, c'est toujours sympa.\n"
	.string "Exactement comme les POKéMON!$"

JaggedPass_Text_230AAA: @ 8230AAA
	.string "Si j'ai perdu, c'est juste à cause de ce\n"
	.string "sol trop bosselé!$"

JaggedPass_Text_230AD7: @ 8230AD7
	.string "Je vais oublier ma défaite et apprécier\n"
	.string "cette randonnée à travers les bosses.$"

JaggedPass_Text_230B10: @ 8230B10
	.string "C'est dur de marcher sur le SENTIER\n"
	.string "SINUROC.\p"
	.string "Mais c'est super pour s'entraîner!$"

JaggedPass_Text_230B50: @ 8230B50
	.string "On essayait encore de trouver une\n"
	.string "bonne prise, alors que tout était\l"
	.string "déjà terminé.$"

JaggedPass_Text_230B93: @ 8230B93
	.string "Si j'avais un VELO CROSS, je pourrais\n"
	.string "sauter sur ces rebords rocheux.$"

JaggedPass_Text_230BC6: @ 8230BC6
	.string "J'arriverai à te battre quand je me\n"
	.string "serai habitué à ces bosses!\p"
	.string "Tu peux m'enregistrer dans ton\n"
	.string "POKéNAV?$"

JaggedPass_Text_230C28: @ 8230C28
	.string "Je suis habitué à toutes ces bosses.\n"
	.string "Maintenant, je chante en grimpant.$"

JaggedPass_Text_230C60: @ 8230C60
	.string "C'est quand même pas facile de se\n"
	.string "battre sur ce sol tout bosselé…$"

JaggedPass_Text_230C94: @ 8230C94
	.string "Il faudrait que j'aille à LAVANDIA pour\n"
	.string "que RODOLPHE me donne un VELO CROSS.$"

JaggedPass_Text_230CCB: @ 8230CCB
	.string "Quoi!\n"
	.string "Qu'est-ce que tu fais là?\p"
	.string "Qu'est-ce que je fais dans un endroit\n"
	.string "pareil?\p"
	.string "Ça te regarde?$"

JaggedPass_Text_230D2D: @ 8230D2D
	.string "Urrrgh…\p"
	.string "J'aurais dû rester caché dans la\n"
	.string "PLANQUE…$"

JaggedPass_Text_230D65: @ 8230D65
	.string "OK, OK…\n"
	.string "Je dois l'avouer, tu sais te battre!\p"
	.string "Ne t'inquiète pas pour moi. Tu peux\n"
	.string "aller où tu veux!$"

JaggedPass_Text_230DBA: @ 8230DBA
	.string "Oh! Ce rocher semble réagir à la\n"
	.string "présence du SCEAU MAGMA!$"

JaggedPass_Text_230DF7: @ 8230DF7
	.string "Ça fait super peur de descendre la\n"
	.string "montagne d'un coup!$"

JaggedPass_Text_230E38: @ 8230E38
	.string "J'ai l'impression de tomber en morceaux…$"

JaggedPass_Text_230E57: @ 8230E57
	.string "Mon vélo s'est pris tellement de bosses\n"
	.string "que je ne sens plus mon dos$"

JaggedPass_Text_230E8E: @ 8230E8E
	.string "Je gravis cette colline chaque jour.\n"
	.string "J'ai confiance en ma force!$"

JaggedPass_Text_230ECD: @ 8230ECD
	.string "Hum…\n"
	.string "Qu'est-ce qui s'est passé?$"

JaggedPass_Text_230EE3: @ 8230EE3
	.string "Est-ce que tu sais ce qu'est cette\n"
	.string "étrange avancée rocheuse un peu\l"
	.string "plus loin?$"

