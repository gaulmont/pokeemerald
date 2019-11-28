MagmaHideout_4F_MapScripts:: @ 823A55F
	.byte 0

MagmaHideout_4F_EventScript_23A560:: @ 823A560
	lockall
	playbgm MUS_MGM0, 0
	msgbox MagmaHideout_4F_Text_23A9F4, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_W197
	setfieldeffectargument 0, 18
	setfieldeffectargument 1, 42
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_ME_TAMA
	playse SE_TAMA
	special sub_80B0534
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 150
	removeobject 7
	addobject 1
	waitstate
	delay 60
	applymovement 1, MagmaHideout_4F_Movement_23A672
	waitmovement 0
	special sub_80B058C
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 1, MagmaHideout_4F_Movement_23A67D
	waitmovement 0
	removeobject 1
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement 6, MagmaHideout_4F_Movement_23A680
	waitmovement 0
	msgbox MagmaHideout_4F_Text_23AADA, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_23AB33, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_1, MagmaHideout_4F_Text_23ABB5
	msgbox MagmaHideout_4F_Text_23ABE2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen 1
	removeobject 6
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen 0
	releaseall
	end

MagmaHideout_4F_Movement_23A672: @ 823A672
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_23A67D: @ 823A67D
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_23A680: @ 823A680
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_23A68C:: @ 823A68C
	trainerbattle_single TRAINER_GRUNT_48, MagmaHideout_4F_Text_23A6E8, MagmaHideout_4F_Text_23A775
	msgbox MagmaHideout_4F_Text_23A7B5, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_23A6A3:: @ 823A6A3
	trainerbattle_single TRAINER_GRUNT_49, MagmaHideout_4F_Text_23A7DA, MagmaHideout_4F_Text_23A81B
	msgbox MagmaHideout_4F_Text_23A841, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_23A6BA:: @ 823A6BA
	trainerbattle_single TRAINER_GRUNT_50, MagmaHideout_4F_Text_23A86D, MagmaHideout_4F_Text_23A8A7
	msgbox MagmaHideout_4F_Text_23A8C6, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_23A6D1:: @ 823A6D1
	trainerbattle_single TRAINER_TABITHA_3, MagmaHideout_4F_Text_23A8E1, MagmaHideout_4F_Text_23A994
	msgbox MagmaHideout_4F_Text_23A9AC, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_23A6E8: @ 823A6E8
	.string "Moi aussi je voudrais voir GROUDON…\n"
	.string "Mais ils ne me laissent même pas voir\l"
	.string "le bout de sa queue.\p"
	.string "C'est vraiment pas sympa.\p"
	.string "Oh non! Je viens de cracher\n"
	.string "le morceau!$"

MagmaHideout_4F_Text_23A775: @ 823A775
	.string "Je devais être trop énervé pour pouvoir\n"
	.string "gagner ce combat.$"

MagmaHideout_4F_Text_23A7B5: @ 823A7B5
	.string "En fait, je ne sais même pas si\n"
	.string "GROUDON a une queue…$"

MagmaHideout_4F_Text_23A7DA: @ 823A7DA
	.string "Wahaha!\n"
	.string "Bientôt… Très bientôt!\l"
	.string "Nous sommes sur le point de réussir!$"

MagmaHideout_4F_Text_23A81B: @ 823A81B
	.string "Grrr…\n"
	.string "J'y étais presque!$"

MagmaHideout_4F_Text_23A841: @ 823A841
	.string "MAX!\n"
	.string "Un intrus vient vers vous!$"

MagmaHideout_4F_Text_23A86D: @ 823A86D
	.string "Ne crois pas pouvoir passer facilement.\n"
	.string "Tu ne m'as pas encore battu!$"

MagmaHideout_4F_Text_23A8A7: @ 823A8A7
	.string "T'as juste eu de la chance!$"

MagmaHideout_4F_Text_23A8C6: @ 823A8C6
	.string "Allez… Encore un combat…$"

MagmaHideout_4F_Text_23A8E1: @ 823A8E1
	.string "Héhéhé…\n"
	.string "Tu as réussi à venir jusqu'ici, alors je\l"
	.string "vais tout te raconter!\p"
	.string "C'est bien ça!\n"
	.string "GROUDON est en train de dormir,\l"
	.string "juste un peu plus loin.\p"
	.string "Mais MAX doit déjà être avec lui.\p"
	.string "Ce n'est plus qu'une question de\n"
	.string "secondes avant qu'il ne le réveille!$"

MagmaHideout_4F_Text_23A994: @ 823A994
	.string "Je suis humilié…\n"
	.string "Encore une fois…$"

MagmaHideout_4F_Text_23A9AC: @ 823A9AC
	.string "Mais pendant que tu perdais ton temps\n"
	.string "avec moi, MAX a dû réveiller GROUDON…$"

MagmaHideout_4F_Text_23A9F4: @ 823A9F4
	.string "MAX: GROUDON…\p"
	.string "Rien n'a encore pu te réveiller de ton\n"
	.string "sommeil dans ce bain de magma…\p"
	.string "Cet ORBE BLEU, il te manquait,\n"
	.string "n'est-ce pas?\p"
	.string "Je t'ai ramené l'ORBE BLEU.\n"
	.string "Que sa lumière te réveille!\p"
	.string "Et montre-moi…\n"
	.string "Montre-moi l'étendue de ta puissance!$"

MagmaHideout_4F_Text_23AADA: @ 823AADA
	.string "MAX: GROUDON!\n"
	.string "Que se passe-t-il?\p"
	.string "L'ORBE BLEU était bien la clef?\p"
	.string "GROUDON!\n"
	.string "Où es-tu parti?$"

MagmaHideout_4F_Text_23AB33: @ 823AB33
	.string "MAX: Oh, c'était donc toi?\p"
	.string "Tu n'as pas arrêté d'apparaître ici\n"
	.string "et là…\p"
	.string "Je comprends maintenant!\n"
	.string "C'est sûrement à cause de toi!$"

MagmaHideout_4F_Text_23ABB5: @ 823ABB5
	.string "D'où te vient cette maîtrise\n"
	.string "des POKéMON?$"

MagmaHideout_4F_Text_23ABE2: @ 823ABE2
	.string "MAX: Il doit bien y avoir une raison pour\n"
	.string "que GROUDON soit parti comme ça…\p"
	.string "C'est ce que tu essaies de me dire,\n"
	.string "c'est ça?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humpf…\n"
	.string "Et tu crois que je le savais pas?\p"
	.string "GROUDON parti, nous n'avons plus rien\n"
	.string "à faire dans ce volcan.\p"
	.string "Je pars à sa recherche, nos chemins\n"
	.string "se séparent ici!$"
