CaveOfOrigin_B1F_MapScripts:: @ 82357A8
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace:: @ 82357A9
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza:: @ 82357F0
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, 0
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin:: @ 823582C
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre:: @ 8235837
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember:: @ 8235842
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar:: @ 823584D
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_KAIDAN
	fadescreenspeed 1, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject 1
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen 0
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory: @ 823586E
	.string "Ah, tu dois être {PLAYER}{KUN}?\n"
	.string "J'ai entendu parler de tes exploits.\p"
	.string "Je m'appelle MARC.\p"
	.string "J'étais autrefois le CHAMPION D'ARENE\n"
	.string "d'ATALANOPOLIS.\p"
	.string "Mais j'ai dû confier la garde de l'ARENE\n"
	.string "à JUAN, mon mentor.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON et KYOGRE, les deux POKéMON\n"
	.string "qui s'affrontent, sont considérés\l"
	.string "comme des POKéMON ancestraux.\p"
	.string "Mais il n'existe pas que deux\n"
	.string "POKéMON ancestraux.\p"
	.string "Il y en a un autre ailleurs.\p"
	.string "Quelque part, se trouve un POKéMON\n"
	.string "ancestral appelé RAYQUAZA.\p"
	.string "On raconte que dans le passé, c'est\n"
	.string "RAYQUAZA qui avait calmé les deux\l"
	.string "combattants.\p"
	.string "Malheureusement, je n'ai aucune idée\n"
	.string "sur l'endroit où peut bien se cacher\l"
	.string "RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza: @ 8235ACE
	.string "MARC: {PLAYER}{KUN}, mais peut-être\n"
	.string "sais-tu, toi, où se trouve RAYQUAZA?\p"
	.string "Si tu le sais, je t'en prie, dis-le moi.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin: @ 8235B23
	.string "MARC: La GROTTE ORIGINE?\p"
	.string "Mais c'est ici!\n"
	.string "Ce n'est pas possible!\p"
	.string "S'il te plaît, essaie de réfléchir à\n"
	.string "l'endroit où RAYQUAZA pourrait\l"
	.string "bien se trouver.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat: @ 8235BBF
	.string "MARC: Le MONT MEMORIA?\p"
	.string "Mais la vieille femme que j'ai rencontrée\n"
	.string "là-bas n'y a fait aucune allusion…\p"
	.string "Et je doute vraiment qu'elle ait essayé\n"
	.string "de me cacher quoi que ce soit.\p"
	.string "{PLAYER}{KUN}, est-ce que tu pourrais y\n"
	.string "réfléchir plus sérieusement?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow: @ 8235C99
	.string "MARC: Hein? Tu ne te souviens plus?\n"
	.string "Hmm… C'est un problème…\p"
	.string "Tu ne peux vraiment pas t'en souvenir?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar: @ 8235CEE
	.string "MARC: Le PILIER CELESTE?\p"
	.string "C'est ça!\n"
	.string "Il doit se trouver au PILIER CELESTE!\p"
	.string "{PLAYER}{KUN}, il n'y a pas un instant à\n"
	.string "perdre! Rendons-nous de suite au\l"
	.string "PILIER CELESTE!$"

