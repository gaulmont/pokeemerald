AquaHideout_B2F_MapScripts:: @ 8233DCF
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition: @ 8233DD5
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_233DDF
	end

AquaHideout_B2F_EventScript_233DDF:: @ 8233DDF
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_233DE5:: @ 8233DE5
	lockall
	setvar VAR_0x8008, 1
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_233E09:: @ 8233E09
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_233EDD, AquaHideout_B2F_Text_233F8D, AquaHideout_B2F_EventScript_233E25
	msgbox AquaHideout_B2F_Text_233FF2, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_233E25:: @ 8233E25
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 4
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_233FA6, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFastestLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_233E80
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_233FF2, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_233E80: @ 8233E80
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AquaHideout_B2F_Movement_233E85: @ 8233E85
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_233E8A:: @ 8233E8A
	trainerbattle_single TRAINER_GRUNT_4, AquaHideout_B2F_Text_2340B4, AquaHideout_B2F_Text_2340F0, AquaHideout_B2F_EventScript_233EA5
	msgbox AquaHideout_B2F_Text_234112, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_233EA5:: @ 8233EA5
	msgbox AquaHideout_B2F_Text_234112, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_233EAF:: @ 8233EAF
	trainerbattle_single TRAINER_GRUNT_22, AquaHideout_B2F_Text_23412D, AquaHideout_B2F_Text_2341CE
	msgbox AquaHideout_B2F_Text_2341FE, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_233EC6:: @ 8233EC6
	trainerbattle_single TRAINER_GRUNT_26, AquaHideout_B2F_Text_23426F, AquaHideout_B2F_Text_2342CC
	msgbox AquaHideout_B2F_Text_2342FF, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_233EDD: @ 8233EDD
	.string "Hé, hé, hé…\p"
	.string "On avait sous-estimé tes compétences!\p"
	.string "Mais cette fois, ça y est!\p"
	.string "Je suis un cran au-dessus des SBIRES\n"
	.string "que tu as vus.\p"
	.string "Je n'vais pas flancher.\n"
	.string "Je vais te pulvériser!$"

AquaHideout_B2F_Text_233F8D: @ 8233F8D
	.string "Hé, hé, hé…\n"
	.string "Alors moi aussi, j'ai perdu…$"

AquaHideout_B2F_Text_233FA6: @ 8233FA6
	.string "Hé, hé, hé!\p"
	.string "Pendant que je m'amusais avec toi,\n"
	.string "notre CHEF a terminé ses préparatifs!$"

AquaHideout_B2F_Text_233FF2: @ 8233FF2
	.string "Hé, hé, hé!\p"
	.string "Notre CHEF est déjà en route vers\n"
	.string "une caverne sous la mer!\p"
	.string "Si tu veux te lancer à sa poursuite, tu\n"
	.string "ferais bien de chercher dans le vaste\l"
	.string "océan derrière NENUCRIQUE.\p"
	.string "Mais est-ce que tu vas la trouver?\n"
	.string "Hé, hé, hé!$"

AquaHideout_B2F_Text_2340B4: @ 82340B4
	.string "Ouaaah, ça m'fatigue d'attendre!\n"
	.string "En plus, tu m'dois un comba!$"

AquaHideout_B2F_Text_2340F0: @ 82340F0
	.string "Fatigué d'attendre…\n"
	.string "Vaincu et abasourdi…$"

AquaHideout_B2F_Text_234112: @ 8234112
	.string "CHEF…\n"
	.string "C'est assez bien?$"

AquaHideout_B2F_Text_23412D: @ 823412D
	.string "Les téléporteurs, c'est la fierté et la\n"
	.string "réussite de notre PLANQUE!\p"
	.string "Tu n'sais pas trop où tu es,\n"
	.string "n'est-ce pas?\p"
	.string "Décontenancer et fatiguer l'ennemi,\n"
	.string "puis lui serrer la vis! C'est notre plan!$"

AquaHideout_B2F_Text_2341CE: @ 82341CE
	.string "Qu'est-ce qui ne va pas chez toi?\n"
	.string "Tu ne montres pas le moindre signe\l"
	.string "de fatigue.$"

AquaHideout_B2F_Text_2341FE: @ 82341FE
	.string "Ça m'rappelle… Je ne sais plus où\n"
	.string "j'ai mis la MASTER BALL.\p"
	.string "Si je n'ai pas réussi à la garder, le\n"
	.string "CHEF va me passer un savon…$"

AquaHideout_B2F_Text_23426F: @ 823426F
	.string "La première chose que j'ai dû faire en\n"
	.string "arrivant ici, c'est comprendre comment\l"
	.string "ces téléporteurs fonctionnent.$"

AquaHideout_B2F_Text_2342CC: @ 82342CC
	.string "J'étais trop occupé à penser aux\n"
	.string "téléporteurs…$"

AquaHideout_B2F_Text_2342FF: @ 82342FF
	.string "Je vais devoir apprendre comment\n"
	.string "me battre plus efficacement.$"
