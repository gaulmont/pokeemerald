#include "constants/apprentice.h"

.macro apprentice_msg waitbuttonpress which
setvar VAR_0x8004, 8
setvar VAR_0x8005, \waitbuttonpress
setvar VAR_0x8006, \which
special CallApprenticeFunction
waitstate
.endm

.macro apprentice_buff whichstringvar tobuff
setvar VAR_0x8004, 16
setvar VAR_0x8005, \whichstringvar
setvar VAR_0x8006, \tobuff
special CallApprenticeFunction
.endm

.macro apprentice_menu which
setvar VAR_0x8004, 7
setvar VAR_0x8005, \which
special CallApprenticeFunction
waitstate
.endm

EventScript_Apprentice:: @ 82B688D
	lock
	faceplayer
	setvar VAR_0x8004, 0
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq Script_Apprentice_FirstMeeting
	setvar VAR_0x8004, 10
	special CallApprenticeFunction
	compare VAR_0x8004, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B68BE
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, Script_Apprentice_ReleaseAndEnd

BattleFrontier_BattleTowerLobby_EventScript_2B68BE:
	setvar VAR_0x8004, 11
	special CallApprenticeFunction
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B69D3
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6ACF
	compare VAR_RESULT, 3
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C77
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D5C
	compare VAR_RESULT, 5
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6DD4
	release
	releaseall
	end

Script_Apprentice_FirstMeeting:
	apprentice_buff 0, APPRENTICE_BUFF_NAME
	apprentice_msg FALSE, 0

Script_Apprentice_FirstMeetingNag:
	apprentice_menu APPRENTICE_ASK_YES_NO
	compare VAR_RESULT, 1
	goto_if_eq Script_Apprentice_FirstMeetingAskAgain
	apprentice_msg FALSE, 2
	apprentice_menu APPRENTICE_ASK_WHICH_LEVEL
	setvar VAR_0x8004, 1
	setorcopyvar VAR_0x8005, VAR_RESULT
	addvar VAR_0x8005, 1
	special CallApprenticeFunction
	setvar VAR_0x8004, 3
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_LEVEL
	apprentice_msg TRUE, 3
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

Script_Apprentice_FirstMeetingAskAgain:
	apprentice_msg FALSE, 1
	goto Script_Apprentice_FirstMeetingNag

BattleFrontier_BattleTowerLobby_EventScript_2B69D3:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 2
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES1
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES2
	apprentice_msg FALSE, 6
	apprentice_menu APPRENTICE_ASK_2SPECIES
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6ABA
	compare VAR_0x8005, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6AC0
	setvar VAR_0x8004, 12
	special CallApprenticeFunction
	copyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, 13
	special CallApprenticeFunction
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	setvar VAR_0x8004, 12
	special CallApprenticeFunction
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6AC6
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	copyvar VAR_0x8006, VAR_0x8007
	special CallApprenticeFunction
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	apprentice_msg TRUE, 7
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6ABA:
	setvar VAR_0x8007, 0
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6AC0:
	setvar VAR_0x8007, 1
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6AC6:
	setvar VAR_0x8004, 4
	special CallApprenticeFunction
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6ACF:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_msg TRUE, 10
	setvar VAR_0x8004, 15
	special CallApprenticeFunction

BattleFrontier_BattleTowerLobby_EventScript_2B6B09:
	fadescreen 1
	setvar VAR_RESULT, 0
	setvar VAR_0x8004, 19
	special CallApprenticeFunction
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B81
	setvar VAR_0x8004, 20
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C0C
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
	apprentice_msg TRUE, 12
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6B81:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, 13
	apprentice_menu APPRENTICE_ASK_GIVE
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B09

BattleFrontier_BattleTowerLobby_EventScript_2B6BD4:
	apprentice_msg TRUE, 14
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6C0C:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, 16
	apprentice_menu APPRENTICE_ASK_GIVE
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B09
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6BD4
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6C77:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 3
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_buff 1, APPRENTICE_BUFF_MOVE1
	apprentice_buff 2, APPRENTICE_BUFF_MOVE2
	apprentice_msg FALSE, 8
	apprentice_menu APPRENTICE_ASK_MOVES
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D50
	compare VAR_0x8005, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D56
	setvar VAR_0x8004, 17
	special CallApprenticeFunction
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	copyvar VAR_0x8006, VAR_0x8007
	special CallApprenticeFunction
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	apprentice_msg TRUE, 9
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6D50:
	setvar VAR_0x8007, 3
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6D56:
	setvar VAR_0x8007, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6D5C:
	apprentice_msg FALSE, 4
	apprentice_menu APPRENTICE_ASK_3SPECIES
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_0x8004, 18
	special CallApprenticeFunction
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES4
	apprentice_msg TRUE, 5
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6DD4:
	apprentice_msg TRUE, 11
	setvar VAR_0x8004, 25
	special CallApprenticeFunction
	setvar VAR_0x8004, EASY_CHAT_TYPE_APPRENTICE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	setvar VAR_0x8004, 21
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_EASY_CHAT
	apprentice_msg TRUE, 15
	setvar VAR_0x8004, 9
	special CallApprenticeFunction
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case DIR_NORTH, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

Script_Apprentice_SetLeavingFlags:
	setflag FLAG_HIDE_APPRENTICE
	setflag FLAG_DAILY_APPRENTICE_LEAVES
	return

Script_Apprentice_LeaveGoRight:
	setvar VAR_0x8004, 24
	special CallApprenticeFunction
	compare VAR_0x8004, 0
	goto_if_eq Script_Apprentice_End
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E94
	waitmovement 0
	end

Script_Apprentice_Leave:
	setvar VAR_0x8004, 24
	special CallApprenticeFunction
	compare VAR_0x8004, 0
	goto_if_eq Script_Apprentice_End
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E95
	waitmovement 0
	end

Script_Apprentice_ReleaseAndEnd:
	release
	releaseall
	end

Script_Apprentice_End:
	end

BattleFrontier_BattleTowerLobby_Movement_2B6E94: @ 82B6E94
	walk_fast_right

BattleFrontier_BattleTowerLobby_Movement_2B6E95: @ 82B6E95
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	slide_down
	slide_down
	slide_down
	step_end

gText_082B6EA5:: @ 82B6EA5
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.\n"
	.string "Sniff… J'ai le trac…$"

gText_082B6EEC:: @ 82B6EEC
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "Attention, nous voilà!$"

gText_082B6F16:: @ 82B6F16
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "Vas-y, mesure-toi à moi!$"

gText_082B6F4C:: @ 82B6F4C
	.string "Je suis l'apprentie nº {STR_VAR_2} de {STR_VAR_1}…\n"
	.string "Je vais perdre, mais je veux essayer…$"

gText_082B6F92:: @ 82B6F92
	.string "Je suis l'apprentie nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "Je t'autorise à te mesurer à moi!$"

gText_082B6FC9:: @ 82B6FC9
	.string "Je suis très occupé, mais je suis quand\n"
	.string "même l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.$"

gText_082B700C:: @ 82B700C
	.string "Je suis l'apprentie nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "Je suis ravie de te rencontrer!$"

gText_082B703A:: @ 82B703A
	.string "Je suis l'apprentie nº {STR_VAR_2} de {STR_VAR_1}.\n"
	.string "Puis-je commencer?$"

gText_082B706A:: @ 82B706A
	.string "Je suis l'apprentie nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "Je vais faire de mon mieux!$"

gText_082B709C:: @ 82B709C
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "Voyons ce que tu as dans le ventre!$"

gText_082B70CC:: @ 82B70CC
	.string "Je suis l'apprenti nº 1 000 de {STR_VAR_1}!\n"
	.string "Mais non, le nº {STR_VAR_2}! C'est parti!$"

gText_082B710A:: @ 82B710A
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "Ohé, ça va tanguer!$"

gText_082B714D:: @ 82B714D
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "Oui, oui!$"

gText_082B7185:: @ 82B7185
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!\n"
	.string "J'ai chopé un mauvais microbe!$"

gText_082B71C1:: @ 82B71C1
	.string "C'est vraiment stressant ici…\n"
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.$"

gText_082B71F9:: @ 82B71F9
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.\n"
	.string "Je t'assure!$"

gText_082B7229:: @ 82B7229
	.string "{PLAYER}, c'est bien toi?\n"
	.string "Oh! Sniff…\p"
	.string "Oh! Je suis désolé…\n"
	.string "C'est l'émotion…\p"
	.string "Je m'appelle {STR_VAR_1}. Je suis un de\n"
	.string "tes plus grands fans, tu sais?\p"
	.string "Te rencontrer… c'était un de mes rêves.\n"
	.string "Et il se réalise à l'instant!\p"
	.string "S'il te plaît, {PLAYER}, apprends-moi ce\n"
	.string "que tu sais sur les POKéMON!$"

gText_082B731C:: @ 82B731C
	.string "Oh… Mais…\n"
	.string "Sniff…\p"
	.string "S'il te plaît!\n"
	.string "Je t'en supplie!$"

gText_082B735B:: @ 82B735B
	.string "Vraiment?\n"
	.string "C'est vraiment super sympa\l"
	.string "de ta part!\p"
	.string "Oh… Je suis désolé…\n"
	.string "Ce sont des larmes de joie…\p"
	.string "Hum… J'ai une question\n"
	.string "sur la TOUR DE COMBAT.\p"
	.string "Qu'est-ce que je dois choisir: niveau 50\n"
	.string "ou niveau libre?$"

gText_082B7423:: @ 82B7423
	.string "{STR_VAR_1}?\n"
	.string "Ouin!!!\p"
	.string "Oh! Je suis désolé!\n"
	.string "Ce sont des larmes de joie…\l"
	.string "Je suis si heureux de te connaître!\p"
	.string "Sniff…\n"
	.string "Je te remercie!\l"
	.string "Reviens me voir!$"

gText_082B74C1:: @ 82B74C1
	.string "Waouh! Tu es {PLAYER}, non?\n"
	.string "Tout le monde parle de toi!\p"
	.string "Je m'appelle {STR_VAR_1}!\n"
	.string "Et je suis un DRESSEUR!\p"
	.string "Dis, {PLAYER}…\n"
	.string "Tu pourrais m'apprendre deux ou trois\l"
	.string "trucs?$"

gText_082B756F:: @ 82B756F
	.string "Pourquoi?\n"
	.string "Oh, s'il te plaît! S'il te plaît!\l"
	.string "Apprends-moi des trucs!$"

gText_082B75B2:: @ 82B75B2
	.string "Génial!\p"
	.string "Je vais commencer par une question\n"
	.string "sur la TOUR DE COMBAT.\p"
	.string "Tu crois que je devrais choisir\n"
	.string "niveau 50 ou plutôt niveau libre?$"

gText_082B763F:: @ 82B763F
	.string "{STR_VAR_1}? D'accord!\n"
	.string "Je vais choisir ça!\p"
	.string "J'espère qu'on se reverra, j'ai encore\n"
	.string "plein de trucs à apprendre!$"

gText_082B76AC:: @ 82B76AC
	.string "Tu ne serais pas {PLAYER}, par hasard?\n"
	.string "Moi, c'est {STR_VAR_1}.\p"
	.string "Je veux devenir DRESSEUR, mais je ne\n"
	.string "sais pas quoi faire…\p"
	.string "Comme tu es célèbre, eh bien…\n"
	.string "Je pensais que tu pourrais m'aider.\p"
	.string "{PLAYER}, tu pourrais me conseiller?$"

gText_082B7772:: @ 82B7772
	.string "Mais…\p"
	.string "Je veux vraiment devenir DRESSEUR!\n"
	.string "Je suis sûr que tu ne me crois pas…\p"
	.string "Allez… Tu peux me conseiller?$"

gText_082B77CE:: @ 82B77CE
	.string "Merci!\n"
	.string "Voici ma première question!\p"
	.string "Dans la TOUR DE COMBAT, tu peux choisir\n"
	.string "entre niveau 50 et niveau libre…\p"
	.string "Qu'est-ce que je devrais choisir,\n"
	.string "d'après toi?$"

gText_082B7871:: @ 82B7871
	.string "{STR_VAR_1}?\n"
	.string "Compris!\p"
	.string "Si j'ai d'autres questions, je reviendrai\n"
	.string "te demander conseil!$"

gText_082B78D4:: @ 82B78D4
	.string "Non…\n"
	.string "Je n'arrive pas à y croire.\p"
	.string "Si on m'avait dit que j'allais rencontrer\n"
	.string "{PLAYER}, je ne l'aurais pas cru!\p"
	.string "Dis, tu es {PLAYER}, n'est-ce pas?\n"
	.string "Je n'arrive pas à y croire!\p"
	.string "En général, quand j'ai autant de chance,\n"
	.string "il m'arrive une catastrophe après.\l"
	.string "Qu'est-ce que ce sera, cette fois-ci!?!\p"
	.string "Mais j'oublie mes bonnes manières!\n"
	.string "Je m'appelle {STR_VAR_1}. Enchantée!\p"
	.string "Il n'y a pas grand chose à dire sur moi.\n"
	.string "Je n'ai rien d'exceptionnel…\p"
	.string "Ma vie est tellement banale que ça\n"
	.string "t'ennuierait, de toute façon…\p"
	.string "Pour une fois qu'un truc intéressant\n"
	.string "m'arrive… {PLAYER}, tu voudrais bien me\l"
	.string "donner quelques conseils?\p"
	.string "Je suis sûre que tu vas refuser, mais ça\n"
	.string "ne coûte rien de demander.\p"
	.string "… … …\n"
	.string "Alors? Tu acceptes?$"

gText_082B7B1A:: @ 82B7B1A
	.string "Je le savais, bah…\p"
	.string "Je suppose que je ne suis pas\n"
	.string "assez intéressante pour toi…\p"
	.string "Rien ne te fera changer d'avis…\n"
	.string "N'est-ce pas?\p"
	.string "Non. Je ne peux pas abandonner comme\n"
	.string "ça!\p"
	.string "S'il te plaît, tu veux bien me donner\n"
	.string "quelques conseils?$"

gText_082B7C13:: @ 82B7C13
	.string "Vraiment? C'est si gentil!\n"
	.string "C'est le plus beau jour de ma vie!\l"
	.string "Je suis si heureuse…\p"
	.string "J'ai une question sur la TOUR DE\n"
	.string "COMBAT…\p"
	.string "C'est tout bête, mais je n'arrive pas à\n"
	.string "choisir entre niveau 50 et niveau libre.\p"
	.string "Tu me conseilles quoi? Je comprendrais\n"
	.string "que tu ne veuilles pas répondre…$"

gText_082B7D18:: @ 82B7D18
	.string "{STR_VAR_1}? D'accord!\n"
	.string "Mais tu penses que j'ai mes chances?\l"
	.string "Je suis sûre que je vais perdre…\p"
	.string "Peu importe, je ferai de mon mieux.\n"
	.string "On verra bien…\p"
	.string "Je t'ai fait perdre ton temps, tu dois\n"
	.string "avoir un tas de choses à faire.$"

gText_082B7DD4:: @ 82B7DD4
	.string "Oh! Super, {PLAYER}{KUN}!\p"
	.string "J'ai beaucoup entendu parler de toi!\n"
	.string "Quel DRESSEUR!\p"
	.string "Je m'appelle {STR_VAR_1}!\n"
	.string "Je suis ta copine, maintenant!\p"
	.string "Au fait, tu savais?\p"
	.string "Tout ce qu'on nous apprend à l'ECOLE DE\n"
	.string "DRESSEURS, ça ne sert à rien dans\l"
	.string "la ZONE DE COMBAT…\p"
	.string "J'aimerais bien que tu me donnes\n"
	.string "quelques trucs. Tu veux bien?$"

gText_082B7EE5:: @ 82B7EE5
	.string "Pourquoi tu ne veux pas!?!\n"
	.string "Tu es célèbre, alors tu ne veux pas\l"
	.string "t'abaisser à me parler, c'est ça?$"

gText_082B7F35:: @ 82B7F35
	.string "Bon, j'ai quelque chose à te demander.\n"
	.string "Donne-moi ton avis.\p"
	.string "Tu sais, il y a niveau 50 et niveau libre\n"
	.string "dans la TOUR DE COMBAT.\p"
	.string "Je ne sais pas quoi choisir, moi!\n"
	.string "Tu me conseilles quoi, {PLAYER}{KUN}?$"

gText_082B7FE8:: @ 82B7FE8
	.string "Tu me conseilles {STR_VAR_1}?\n"
	.string "Super, merci!\p"
	.string "Comme c'est ta décision, ce sera\n"
	.string "de ta faute si je perds, {PLAYER}{KUN}!\p"
	.string "Non, sérieusement. Je te fais\n"
	.string "entièrement confiance. Salut!$"

gText_082B8087:: @ 82B8087
	.string "Bonjour!\n"
	.string "Tu es {PLAYER}{KUN}? C'est ça?\l"
	.string "Moi, je m'appelle {STR_VAR_1}.\p"
	.string "Je suis un TRIATHLETE, mais je fais\n"
	.string "aussi des combats de POKéMON.\p"
	.string "J'aime aussi travailler, faire la sieste,\n"
	.string "prendre des cours de danse de salon…\p"
	.string "Du coup, il me reste très peu de temps\n"
	.string "pour les POKéMON.\p"
	.string "J'aimerais te proposer quelque chose!\p"
	.string "Je pense qu'on ne s'est pas rencontrés\n"
	.string "par hasard. {PLAYER}{KUN}, tu voudrais me\l"
	.string "faire profiter de ton savoir?$"

gText_082B822B:: @ 82B822B
	.string "S'il te plaît! J'ai vraiment besoin de\n"
	.string "quelqu'un comme toi pour me guider et\l"
	.string "me motiver, {PLAYER}{KUN}!\p"
	.string "Sincèrement, j'ai besoin de toi!$"

gText_082B8286:: @ 82B8286
	.string "Merci!\n"
	.string "Ton soutien me sera précieux!\p"
	.string "Tu connais la TOUR DE COMBAT, non?\n"
	.string "Il y a niveau 50 et niveau libre.\p"
	.string "Lequel me conviendrait le mieux?$"

gText_082B8356:: @ 82B8356
	.string "{STR_VAR_1}? C'est compris.\n"
	.string "J'irai dès que j'aurai le temps!\p"
	.string "Je vais être en retard au travail.\n"
	.string "Je me sauve!$"

gText_082B83CE:: @ 82B83CE
	.string "Je n'y crois pas! Ne me dis\n"
	.string "pas que tu es {PLAYER}!?!\p"
	.string "Incroyable! Je m'appelle {STR_VAR_1}.\n"
	.string "Je suis contente de te rencontrer!\p"
	.string "{PLAYER}, tu as une force incroyable,\n"
	.string "tu sais?\p"
	.string "On ne parle plus que de toi, ici!\p"
	.string "Oh! J'ai une idée. Je vais te\n"
	.string "demander conseil, {PLAYER}!\l"
	.string "Je suis sûre que tu peux m'aider!\p"
	.string "C'est une bonne idée, non?\n"
	.string "Allez, tu me donnes un conseil?$"

gText_082B84FC:: @ 82B84FC
	.string "Tu veux te faire passer pour quelqu'un\n"
	.string "de méchant, mais je ne suis pas dupe!\l"
	.string "Allez, tu me donnes un petit conseil?$"

gText_082B8559:: @ 82B8559
	.string "Youpi! Je savais que tu avais un cœur\n"
	.string "gros comme ça, {PLAYER}! \p"
	.string "Que vais-je bien pouvoir te demander…\n"
	.string "Ça y est, je sais!\p"
	.string "Roulement de tambour!\n"
	.string "Voici ma question.\p"
	.string "Je veux me battre dans la TOUR DE\n"
	.string "COMBAT. Que me conseilles-tu?\p"
	.string "Niveau 50 ou niveau libre?\n"
	.string "Lequel est le mieux pour moi?$"

gText_082B8656:: @ 82B8656
	.string "Ah, oui? {STR_VAR_1}, tu penses?\n"
	.string "Merci, je suivrai ton conseil!\p"
	.string "Bon, c'est tout ce que j'avais à te\n"
	.string "demander, je crois.\p"
	.string "Mais on se reverra sûrement!\n"
	.string "Merci encore!$"

gText_082B86EA:: @ 82B86EA
	.string "Je te prie de m'excuser…\n"
	.string "Serais-tu par hasard {PLAYER}?\p"
	.string "Je m'appelle {STR_VAR_1} et je suis\n"
	.string "enchantée de faire ta connaissance!\p"
	.string "Je suis une fan, tu sais? Ça fait très\n"
	.string "longtemps que je suis tes exploits…\p"
	.string "… … … … … …\p"
	.string "Euh… J'espère que je n'abuse pas,\n"
	.string "je ne veux pas te forcer, mais…\p"
	.string "Est-ce que je peux être ton apprentie,\n"
	.string "{PLAYER}?$"

gText_082B87DA:: @ 82B87DA
	.string "Oh!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Désolée, je n'ai pas bien entendu,\n"
	.string "tu peux répéter?\p"
	.string "S'il te plaît! Dis-moi que tu acceptes\n"
	.string "de me prendre comme apprentie!$"

gText_082B887C:: @ 82B887C
	.string "Oh! Ça me fait plaisir!\p"
	.string "Je ne veux pas te faire perdre ton\n"
	.string "temps, donc je me dépêche.\p"
	.string "J'ai prévu de relever le défi de la\n"
	.string "TOUR DE COMBAT très bientôt.\p"
	.string "Mais il y a deux niveaux et je ne sais\n"
	.string "pas lequel choisir…\p"
	.string "Lequel me conseilles-tu?\n"
	.string "Niveau 50 ou niveau libre?$"

gText_082B8957:: @ 82B8957
	.string "Tu me conseilles {STR_VAR_1}?\n"
	.string "Très bien, tu dois avoir raison!\p"
	.string "Merci, {PLAYER}.\n"
	.string "Je savais que je pouvais compter sur\l"
	.string "toi. A bientôt!$"

gText_082B89C6:: @ 82B89C6
	.string "Comment? {PLAYER}!\n"
	.string "Et tu me parles? A moi!?!\l"
	.string "Oh… Quelle chance!\p"
	.string "Moi, je m'appelle {STR_VAR_1}!\n"
	.string "Je viens de devenir DRESSEUR!\p"
	.string "Quel honneur de te parler, {PLAYER}.\n"
	.string "Si je m'attendais à ça…\p"
	.string "Et si j'en profitais pour te demander un\n"
	.string "service, {PLAYER}? Allez, j'ose…\p"
	.string "Est-ce que je peux être ton apprentie?\n"
	.string "Apprends-moi tout ce que tu sais!$"

gText_082B8ACF:: @ 82B8ACF
	.string "Oh…\n"
	.string "Je viens d'être rejetée par {PLAYER}…\l"
	.string "Quelle expérience!\p"
	.string "Mais je t'en prie, {PLAYER}! Dis-moi que\n"
	.string "tu acceptes, cette fois-ci!\p"
	.string "Accorde-moi ton aide!$"

gText_082B8B66:: @ 82B8B66
	.string "Ouiiiii! {PLAYER} a dit oui!\n"
	.string "{PLAYER} a dit oui!\p"
	.string "Je ne vais pas en dormir de la nuit…\n"
	.string "Merci! Merci!!!\p"
	.string "Bon, j'ai une question à te poser!\p"
	.string "Dans la TOUR DE COMBAT, je dois plutôt\n"
	.string "choisir niveau 50 ou niveau libre?$"

gText_082B8C20:: @ 82B8C20
	.string "{STR_VAR_1}, d'accord! Je choisirai\n"
	.string "ça, puisque tel est ton conseil!\p"
	.string "J'espère que tu m'en donneras\n"
	.string "encore plein!$"

gText_082B8CAA:: @ 82B8CAA
	.string "Waouh! On dirait… Tu ne serais pas…\n"
	.string "{PLAYER}{KUN}? Le célèbre DRESSEUR?\l"
	.string "On dirait que c'est mon jour de chance!\p"
	.string "Bonjour, au fait! Je m'appelle\n"
	.string "{STR_VAR_1}!\p"
	.string "Je cherchais justement quelqu'un pour\n"
	.string "tout m'enseigner sur les POKéMON.\p"
	.string "Et qui est-ce que je vois arriver?\n"
	.string "Eh bien, {PLAYER}{KUN}!\p"
	.string "C'est le destin! Tu ne peux pas refuser,\n"
	.string "{PLAYER}{KUN}! Je peux être ton apprenti?$"

gText_082B8DD3:: @ 82B8DD3
	.string "Quoi?!?\n"
	.string "Je sais, tu es quelqu'un d'important…\p"
	.string "Tu veux te faire prier un peu…\n"
	.string "S'il te plaît, ce serait un tel honneur!$"

gText_082B8E24:: @ 82B8E24
	.string "Oui, excellente réponse!\n"
	.string "Ça me fait sacrément plaisir!\p"
	.string "Si on commençait par un conseil sur\n"
	.string "la TOUR DE COMBAT?\p"
	.string "Qu'est-ce que tu me conseillerais:\n"
	.string "niveau 50 ou niveau libre?$"

gText_082B8ED5:: @ 82B8ED5
	.string "Oh, {STR_VAR_1}!\n"
	.string "Je prends!\l"
	.string "Je vais faire des progrès avec toi!\p"
	.string "Tu seras mon mentor, OK?\n"
	.string "Hasta la vista!$"

gText_082B8F45:: @ 82B8F45
	.string "Tu es, {PLAYER}{KUN}, non?\n"
	.string "La police te cherche partout!\p"
	.string "… … …\n"
	.string "Mais non, je rigole!\p"
	.string "Je m'appelle {STR_VAR_1}. Je suis le\n"
	.string "MAITRE POKéMON. Je suis ici\l"
	.string "incognito… Mais non, je rigole!\p"
	.string "Je suis plus doué pour les blagues que\n"
	.string "pour les combats…\p"
	.string "Tu voudrais être le professeur d'un\n"
	.string "petit boute-en-train comme moi?$"

gText_082B905F:: @ 82B905F
	.string "Tu ne veux pas? Oh, tout le monde me\n"
	.string "rejette, c'est l'histoire de ma vie…\p"
	.string "Je fais des blagues pour masquer ma\n"
	.string "tristesse, mais… je suis très seul…\p"
	.string "Ha, ha, ha, je rigole!!!\p"
	.string "Allez, vas-y! Sois mon prof!\n"
	.string "Tu verras, on va bien rigoler!$"

gText_082B910E:: @ 82B910E
	.string "Youpi! Pour te remercier, je vais\n"
	.string "t'offrir un bateau!\p"
	.string "Bien sûr, je rigole!\n"
	.string "Je te remercie, en tout cas…\p"
	.string "Tu sais, il y a niveau 50 et niveau\n"
	.string "libre dans la TOUR DE COMBAT.\p"
	.string "Entre les deux, mon cœur balance…\n"
	.string "Lequel tu me recommandes?\p"
	.string "Je suivrai ton conseil.$"

gText_082B9204:: @ 82B9204
	.string "{STR_VAR_1}? Merci, je vais choisir\n"
	.string "l'autre, alors!\p"
	.string "Mais non, je rigole…\n"
	.string "Je vais suivre ton conseil!\p"
	.string "Merci! J'espère que tu m'apprendras\n"
	.string "encore plein d'autres choses!$"

gText_082B929C:: @ 82B929C
	.string "Ohé, matelot!\n"
	.string "C'est le salut des marins, moussaillon!\p"
	.string "Je m'appelle {STR_VAR_1}, le MARIN\n"
	.string "chantant!\p"
	.string "Je sais tout sur toi,\n"
	.string "mais cela va de soi!\p"
	.string "Voyons voir…\n"
	.string "{PLAYER}{KUN}, tu te prénommes,\l"
	.string "pour les POKéMON, tu te passionnes!\p"
	.string "Tu es encore bien jeune, mon petit!\n"
	.string "A ton âge, tout est permis!\p"
	.string "Tu sais, aujourd'hui…\n"
	.string "tu es le dixième DRESSEUR avec qui\l"
	.string "je parle, pardi!\p"
	.string "Solennellement, je te le demande…\n"
	.string "Sois mon mentor, j'ai tant à apprendre!$"

gText_082B9438:: @ 82B9438
	.string "Mais!\n"
	.string "J'ai besoin de toi!\p"
	.string "Je suis sûr que tu me fais marcher!\n"
	.string "Accepte, s'il te plaît!$"

gText_082B9488:: @ 82B9488
	.string "Oui!\n"
	.string "{PLAYER} a dit oui!\p"
	.string "Voici une question. Je suis ouvert\n"
	.string "à toute suggestion!\p"
	.string "C'est à propos de la TOUR DE COMBAT.\n"
	.string "Disons que j'ai l'embarras du choix!\p"
	.string "Niveau 50 et niveau libre?\n"
	.string "Que me conseilles-tu de choisir?$"

gText_082B9564:: @ 82B9564
	.string "{STR_VAR_1}, tu dis?\n"
	.string "C'est un bon conseil, pardi!\p"
	.string "Tes conseils me sont précieux,\n"
	.string "{PLAYER}! Toi, tu as l'esprit belliqueux!$"

gText_082B95D8:: @ 82B95D8
	.string "Qui va là? Mais c'est {PLAYER}!\n"
	.string "Que faire? Te parler, au risque\l"
	.string "de t'importuner? Mon choix est fait!\p"
	.string "{PLAYER}, pourquoi ce regard surpris?\n"
	.string "Tu te demandes qui je suis?\p"
	.string "{STR_VAR_1}, c'est mon nom.\n"
	.string "Et la guitare, c'est ma passion!\p"
	.string "Tu m'as compris?\n"
	.string "Oui, tu m'as compris!\p"
	.string "C'est mon jour de chance,\n"
	.string "alors je me lance!\p"
	.string "{PLAYER}, laisse-moi être ton apprenti!\n"
	.string "Je n'ai pas encore assez appris!$"

gText_082B9763:: @ 82B9763
	.string "Si ta réponse est non,\n"
	.string "je repose ma question!\p"
	.string "{PLAYER}, laisse-moi être ton apprenti!\n"
	.string "Je n'ai pas encore assez appris!$"

gText_082B97E5:: @ 82B97E5
	.string "Ça, c'est bon!\n"
	.string "Je peux te poser une autre question?\p"
	.string "Ma question portera…\n"
	.string "sur la TOUR DE COMBAT!\p"
	.string "Des deux choix proposés,\n"
	.string "lequel dois-je accepter?$"

gText_082B989A:: @ 82B989A
	.string "Tu dis {STR_VAR_1}?\n"
	.string "C'est ça que je choisirai!\p"
	.string "{PLAYER}, je dois y aller!\n"
	.string "Pense à moi!\p"
	.string "A bientôt, j'espère!$"

gText_082B992D:: @ 82B992D
	.string "Hé, toi! Tu me fais un massage?\n"
	.string "J'ai les épaules contractées.\p"
	.string "Oui, toi! J'adore les massages!\n"
	.string "Ça me détend!\p"
	.string "Je m'appelle {STR_VAR_1}.\n"
	.string "Je fais du karaté, mais je ne suis pas\l"
	.string "en grande forme…\p"
	.string "J'ai donc décidé de me mettre aux\n"
	.string "combats de POKéMON.\p"
	.string "Tu es {PLAYER}{KUN}, non?\n"
	.string "Le MAITRE de la LIGUE POKéMON?\p"
	.string "Dis, tu veux bien me donner un\n"
	.string "conseil?$"

gText_082B9A84:: @ 82B9A84
	.string "Pourquoi?\p"
	.string "Ce ne sera pas long, juste un petit\n"
	.string "conseil… S'il te plaît!$"

gText_082B9AB9:: @ 82B9AB9
	.string "Merci!\n"
	.string "Oh là là, je tousse…\p"
	.string "Il faut vite que je retrouve la\n"
	.string "forme…\p"
	.string "Je vais relever le défi de la TOUR DE\n"
	.string "COMBAT. Tu penses que je devrais\l"
	.string "choisir niveau 50 ou niveau libre?$"

gText_082B9B76:: @ 82B9B76
	.string "D'accord, je vais choisir {STR_VAR_1}.\n"
	.string "Bon, j'y vais.\p"
	.string "Ça fait plaisir de pouvoir compter sur\n"
	.string "son mentor. Merci!$"

gText_082B9BF2:: @ 82B9BF2
	.string "Euh… Hum…\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Ne me fixe pas comme ça,\n"
	.string "tu me rends nerveux…\p"
	.string "Je m'appelle {STR_VAR_1}.\p"
	.string "J'ai un peu honte de le dire, mais les\n"
	.string "ruines… l'archéologie… c'est mon dada!\p"
	.string "J'ai aussi un peu honte d'avouer que\n"
	.string "je m'intéresse à la ZONE DE COMBAT.\p"
	.string "{PLAYER}{KUN}, tu as la réputation d'être\n"
	.string "un très bon DRESSEUR…\p"
	.string "Ce n'est pas mon habitude, mais je\n"
	.string "voudrais te poser une question.\p"
	.string "Allez, je me jette à l'eau.\n"
	.string "Tu veux bien devenir mon professeur?$"

gText_082B9D83:: @ 82B9D83
	.string "Je m'y attendais…\n"
	.string "Je ne supporte pas d'être humilié!\p"
	.string "Pardonne-moi d'insister. S'il te\n"
	.string "plaît, sois mon professeur!$"

gText_082B9DF9:: @ 82B9DF9
	.string "Je te remercie…\p"
	.string "Ne me regarde pas droit dans les yeux,\n"
	.string "ça me met mal à l'aise.\p"
	.string "Je vais te poser une question, mais ne\n"
	.string "me regarde pas, d'accord?\p"
	.string "Dans la TOUR DE COMBAT, quel niveau tu\n"
	.string "me conseilles de choisir?$"

gText_082B9EAA:: @ 82B9EAA
	.string "Oh… C'est compris!\n"
	.string "Je vais essayer ça.\p"
	.string "J'espère que je vais y arriver! J'ai le\n"
	.string "trac rien que d'en parler…\p"
	.string "Merci, {PLAYER}{KUN}.\n"
	.string "J'espère qu'on va se revoir, tu es\l"
	.string "vraiment de bon conseil.$"

gText_082B9F55:: @ 82B9F55
	.string "Tiens donc? Tu es {PLAYER}{KUN},\n"
	.string "n'est-ce pas?\p"
	.string "Je me présente, mon nom est\n"
	.string "{STR_VAR_1}.\p"
	.string "Je me disais justement que j'aimerais\n"
	.string "apprendre avec un bon DRESSEUR. \p"
	.string "Alors, quelle chance de te voir!\n"
	.string "Tu es vraiment {PLAYER}{KUN}, non?\p"
	.string "Très bien. Permets-moi de te\n"
	.string "présenter mon souhait le plus cher.\l"
	.string "Puis-je être ton apprenti?$"

gText_082BA084:: @ 82BA084
	.string "Comment?\n"
	.string "Pourquoi refuses-tu?\p"
	.string "Je suis désolé d'avoir émis des doutes\n"
	.string "sur ton identité.\p"
	.string "Je te prie d'accepter mes excuses.\n"
	.string "Puis-je être ton apprenti?$"

gText_082BA11D:: @ 82BA11D
	.string "C'est vrai? J'en suis tout à fait\n"
	.string "ravi!\p"
	.string "Tu ne sais pas ce que ça représente\n"
	.string "pour moi… J'ai besoin d'un conseil.\p"
	.string "Dans la TOUR DE COMBAT, que me\n"
	.string "conseilles-tu de choisir?\l"
	.string "Niveau 50 ou niveau libre?$"

gText_082BA1F3:: @ 82BA1F3
	.string "{STR_VAR_1}?\n"
	.string "Cela me surprend un peu.\p"
	.string "Je te remercie, c'est très aimable\n"
	.string "de ta part.\p"
	.string "J'espère ne pas avoir abusé de ton\n"
	.string "temps, surtout.\p"
	.string "Au revoir!$"

gText_082BA2A3:: @ 82BA2A3
	.string "Sniff…\n"
	.string "Oh, {PLAYER}!\p"
	.string "C'est horrible, je n'arrive pas à me\n"
	.string "décider.\p"
	.string "Je ne sais pas quel objet je devrais\n"
	.string "faire porter à mon {STR_VAR_1}.\p"
	.string "Tu en penses quoi, {PLAYER}? Qu'est-ce\n"
	.string "que je devrais lui faire porter?$"

gText_082BA34E:: @ 82BA34E
	.string "Vraiment? Tu penses que mon\n"
	.string "{STR_VAR_1} ne devrait rien porter?$"

gText_082BA380:: @ 82BA380
	.string "Oh, d'accord.\n"
	.string "Je suis soulagé.\p"
	.string "Merci du conseil!$"

gText_082BA3D2:: @ 82BA3D2
	.string "{STR_VAR_1}? J'ai cet objet,\n"
	.string "justement! Merci beaucoup!\p"
	.string "Allez, c'est décidé!\n"
	.string "Très bon choix!\p"
	.string "Je te remercie!$"

gText_082BA448:: @ 82BA448
	.string "Comment? Tu te moques de moi…\p"
	.string "On m'a déjà recommandé {STR_VAR_1},\n"
	.string "sniff…\p"
	.string "Tu veux peut-être dire que mon\n"
	.string "{STR_VAR_2} ne devrait rien porter?$"

gText_082BA4D3:: @ 82BA4D3
	.string "Hé, mais c'est {PLAYER}! Justement,\n"
	.string "j'avais une question pour toi!\p"
	.string "Tu fais porter des objets à tes\n"
	.string "POKéMON? Moi, je voudrais mais…\p"
	.string "Quel objet serait bon pour\n"
	.string "{STR_VAR_1}?\p"
	.string "Tu as une idée?$"

gText_082BA58C:: @ 82BA58C
	.string "Hein? Tu veux dire que mon {STR_VAR_1}\n"
	.string "ne devrait rien porter?$"

gText_082BA5BF:: @ 82BA5BF
	.string "D'accord, j'ai compris!\n"
	.string "Merci du conseil!$"

gText_082BA5F3:: @ 82BA5F3
	.string "{STR_VAR_1}, tu dis?\n"
	.string "Je suis bien d'accord!\p"
	.string "Merci du conseil!$"

gText_082BA635:: @ 82BA635
	.string "Oui, mais je sais déjà pour cet objet.\n"
	.string "Je voulais en connaître un autre.\p"
	.string "Ou tu veux dire que mon POKéMON ne\n"
	.string "devrait rien porter, cette fois?$"

gText_082BA6E6:: @ 82BA6E6
	.string "{PLAYER}, bonjour!\n"
	.string "Je voulais te parler de mon {STR_VAR_1}…\p"
	.string "Je veux lui faire porter un objet.\n"
	.string "Lequel tu me conseilles?$"

gText_082BA742:: @ 82BA742
	.string "Mon {STR_VAR_1} ne doit rien porter,\n"
	.string "c'est ça?$"

gText_082BA770:: @ 82BA770
	.string "Compris!\n"
	.string "A plus!$"

gText_082BA78F:: @ 82BA78F
	.string "{STR_VAR_1}?\n"
	.string "Compris!\p"
	.string "Je vais essayer de trouver cet objet!\n"
	.string "A plus!$"

gText_082BA7D8:: @ 82BA7D8
	.string "{STR_VAR_1}? Mais on m'en a déjà\n"
	.string "parlé, tu sais.\p"
	.string "Je voudrais que mon POKéMON porte un\n"
	.string "autre objet.\p"
	.string "Ou est-ce que tu veux dire que mon\n"
	.string "{STR_VAR_2} ne devrait rien porter?$"

gText_082BA867:: @ 82BA867
	.string "Salut, {PLAYER}!\n"
	.string "Je suis désolée de te déranger…\l"
	.string "Je voudrais te poser une question.\p"
	.string "Je ne suis pas assez forte pour gagner\n"
	.string "les combats sans aide, alors je voudrais\l"
	.string "faire porter un objet à mon {STR_VAR_1}.\p"
	.string "Mais je ne sais pas quoi choisir.\p"
	.string "Dis, {PLAYER}… Tu pourrais me conseiller\n"
	.string "un objet?$"

gText_082BA96B:: @ 82BA96B
	.string "Tu veux dire qu'il vaut mieux que je ne\n"
	.string "lui donne pas d'objet à porter?$"

gText_082BA9B7:: @ 82BA9B7
	.string "Je vois… Tu penses qu'il vaut mieux\n"
	.string "que je ne compte que sur moi.\l"
	.string "Je vais essayer!\p"
	.string "Merci beaucoup!$"

gText_082BAA1B:: @ 82BAA1B
	.string "{STR_VAR_1}… D'accord.\n"
	.string "Je ne sais pas comment je vais trouver\l"
	.string "cet objet… Mais je le trouverai.\p"
	.string "Merci beaucoup!$"

gText_082BAA81:: @ 82BAA81
	.string "{STR_VAR_1}? Oh, mais…\n"
	.string "On m'a déjà parlé de ça…\p"
	.string "Peut-être que je ne l'ai pas utilisé\n"
	.string "correctement?\p"
	.string "Ou est-ce que tu veux dire que mon\n"
	.string "{STR_VAR_2} ne devrait rien porter?$"

gText_082BAB22:: @ 82BAB22
	.string "Oh, {PLAYER}{KUN}.\n"
	.string "J'ai quelque chose à te demander.\p"
	.string "Tu te souviens que tu m'avais\n"
	.string "dit quel POKéMON je devrais avoir?\p"
	.string "Maintenant, je voudrais savoir quel\n"
	.string "objet je devrais lui faire porter.\p"
	.string "Comme tu m'as bien conseillée la\n"
	.string "dernière fois, j'ai pensé que tu saurais!\p"
	.string "Quel objet tu me conseilles pour mon\n"
	.string "{STR_VAR_1}?$"

gText_082BAC43:: @ 82BAC43
	.string "Ah, bon? Mon {STR_VAR_1} ne devrait\n"
	.string "porter aucun objet?$"

gText_082BAC78:: @ 82BAC78
	.string "Si tu penses que c'est la meilleure\n"
	.string "solution, je te fais confiance.\p"
	.string "Comme c'est ta décision, ce sera\n"
	.string "ta faute si je perds, {PLAYER}{KUN}!\p"
	.string "Non, sérieusement. Je te fais\n"
	.string "entièrement confiance. Salut!$"

gText_082BAD17:: @ 82BAD17
	.string "{STR_VAR_1}, hein?\n"
	.string "Pas mal. Je vais l'utiliser!\p"
	.string "Comme c'est ta décision, ce sera\n"
	.string "ta faute si je perds, {PLAYER}{KUN}!\p"
	.string "Non, sérieusement. Je te fais\n"
	.string "entièrement confiance. Salut!$"

gText_082BADB6:: @ 82BADB6
	.string "{STR_VAR_1}? Mais tu m'as déjà parlé\n"
	.string "de cet objet.\l"
	.string "Tu as oublié?\p"
	.string "A moins que tu ne veuilles dire que mon\n"
	.string "{STR_VAR_2} ne devrait rien porter?$"

gText_082BAE36:: @ 82BAE36
	.string "Salut, {PLAYER}{KUN}!\p"
	.string "On a tous les deux beaucoup à faire,\n"
	.string "mais on n'arrête pas de se croiser!\p"
	.string "Le programme, aujourd'hui, c'est\n"
	.string "footing, ménage et repassage.\p"
	.string "Je n'ai pas eu le temps d'acheter\n"
	.string "quelque chose pour mon {STR_VAR_1}.\p"
	.string "Tu pourrais me conseiller un objet à\n"
	.string "faire porter à mon {STR_VAR_1}?\l"
	.string "Ça me ferait gagner du temps.$"

gText_082BAF4E:: @ 82BAF4E
	.string "Tu crois qu'il vaut mieux que mon\n"
	.string "{STR_VAR_1} ne porte rien?$"

gText_082BAF8F:: @ 82BAF8F
	.string "C'est compris. Tant mieux, ça me fera\n"
	.string "gagner du temps.\p"
	.string "Merci du conseil!\n"
	.string "A la prochaine!$"

gText_082BAFDB:: @ 82BAFDB
	.string "{STR_VAR_1}? C'est compris.\n"
	.string "Dès que j'aurai cinq minutes à moi,\l"
	.string "j'irai chercher cet objet.\p"
	.string "Je peux toujours compter sur toi.\n"
	.string "Merci! Et à la prochaine!$"

gText_082BB05F:: @ 82BB05F
	.string "{STR_VAR_1}? Mais je connais déjà, je\n"
	.string "voulais un autre objet.\p"
	.string "Tu crois qu'il vaut mieux que mon\n"
	.string "{STR_VAR_2} ne porte rien, c'est ça?$"

gText_082BB0D4:: @ 82BB0D4
	.string "Salut, {PLAYER}! C'est moi!\n"
	.string "J'ai de nouveau besoin de tes lumières!\l"
	.string "Eclaire ma lanterne…\p"
	.string "Allez, je me dépêche!\n"
	.string "Voici ma question…\p"
	.string "Je veux faire porter un objet à mon\n"
	.string "{STR_VAR_1}. Que me conseilles-tu?$"

gText_082BB18C:: @ 82BB18C
	.string "Vraiment? Mon {STR_VAR_1} n'a pas\n"
	.string "besoin de porter d'objet, tu dis?$"

gText_082BB1CE:: @ 82BB1CE
	.string "D'accord, je vais suivre ton conseil.\p"
	.string "C'est tout ce que je voulais savoir.\n"
	.string "Rien d'autre pour aujourd'hui!\p"
	.string "On se reverra ici, d'accord?\n"
	.string "Merci!$"

gText_082BB242:: @ 82BB242
	.string "{STR_VAR_1}?\n"
	.string "C'est une super idée!\l"
	.string "Je vais essayer!\p"
	.string "C'est tout ce que je voulais savoir.\n"
	.string "Rien d'autre pour aujourd'hui!\p"
	.string "On se reverra ici, d'accord?\n"
	.string "Merci!$"

gText_082BB2D9:: @ 82BB2D9
	.string "{STR_VAR_1}? Mais tu m'as déjà parlé\n"
	.string "de cet objet!\l"
	.string "Tu as oublié?\p"
	.string "Tu te sens bien, {PLAYER}?\p"
	.string "Ah, tu veux dire que mon {STR_VAR_2} n'a\n"
	.string "pas besoin de porter un objet.$"

gText_082BB370:: @ 82BB370
	.string "Bonjour, {PLAYER}. J'espère que tu vas\n"
	.string "bien.\p"
	.string "Je peux te demander un conseil?\p"
	.string "J'ai remarqué que certains de mes\n"
	.string "adversaires font porter des objets\l"
	.string "à leurs POKéMON.\p"
	.string "Et ils m'ont tous battu…\p"
	.string "Alors, moi aussi, je voudrais que mon\n"
	.string "{STR_VAR_1} porte un objet.\l"
	.string "Tu me comprends, non?\p"
	.string "J'aimerais bien que tu choisisses un\n"
	.string "objet pour moi…$"

gText_082BB4C3:: @ 82BB4C3
	.string "En d'autres termes… je n'ai\n"
	.string "pas besoin d'objet?$"

gText_082BB4FB:: @ 82BB4FB
	.string "C'est compris!\n"
	.string "Je vais continuer sans objet, alors.\p"
	.string "Merci, {PLAYER}.\n"
	.string "Je savais bien que je pouvais compter\l"
	.string "sur toi. A bientôt!$"

gText_082BB575:: @ 82BB575
	.string "{STR_VAR_1}, vraiment?\n"
	.string "Je vais suivre ce conseil!\p"
	.string "Merci, {PLAYER}.\n"
	.string "Je savais bien que je pouvais compter\l"
	.string "sur toi. A bientôt!$"

gText_082BB5E1:: @ 82BB5E1
	.string "Tu m'as déjà parlé de cet objet et je\n"
	.string "l'ai déjà.\p"
	.string "Tu veux dire que… mon POKéMON\n"
	.string "n'a pas besoin d'objet?$"

gText_082BB656:: @ 82BB656
	.string "Hé, {PLAYER}!\n"
	.string "Quel plaisir de te voir!\p"
	.string "Justement, j'avais une petite question\n"
	.string "à te poser, {PLAYER}!\p"
	.string "Dis-moi quel objet mon {STR_VAR_1}\n"
	.string "devrait porter!$"

gText_082BB6E5:: @ 82BB6E5
	.string "Comme c'est surprenant!\n"
	.string "Il ne devrait rien porter?$"

gText_082BB72C:: @ 82BB72C
	.string "C'est compris!\n"
	.string "Je vais continuer sans objet!\p"
	.string "J'espère que tu me donneras encore\n"
	.string "plein de conseils!$"

gText_082BB7A2:: @ 82BB7A2
	.string "{STR_VAR_1}? C'est d'accord!\p"
	.string "Toi aussi, {PLAYER}, tu utilises cet\n"
	.string "objet?\p"
	.string "Je vais me le procurer le plus vite\n"
	.string "possible! J'espère que tu me donneras\l"
	.string "encore plein de conseils!$"

gText_082BB84A:: @ 82BB84A
	.string "{STR_VAR_1}? Tu me l'as déjà\n"
	.string "recommandé.\p"
	.string "C'est le meilleur objet?\n"
	.string "Ou tu veux dire que mon {STR_VAR_2}\l"
	.string "ne devrait rien porter?$"

gText_082BB8CD:: @ 82BB8CD
	.string "Bonjour, {PLAYER}{KUN}!\p"
	.string "J'ai un petit conseil à te demander\n"
	.string "en matière de POKéMON.\p"
	.string "Qu'est-ce que je dois faire porter à\n"
	.string "mon {STR_VAR_1}, d'après toi?\p"
	.string "Dis-le-moi, je te fais une confiance\n"
	.string "aveugle!$"

gText_082BB970:: @ 82BB970
	.string "Ah, bon? Mon {STR_VAR_1} peut gagner\n"
	.string "sans objet?$"

gText_082BB9AE:: @ 82BB9AE
	.string "Bueno! Je vais faire de mon mieux\n"
	.string "sans objet!\p"
	.string "Merci!\n"
	.string "Hasta la vista!$"

gText_082BBA05:: @ 82BBA05
	.string "{STR_VAR_1}?\n"
	.string "Bueno!\l"
	.string "Je vais me servir de ça!\p"
	.string "Merci!\n"
	.string "Hasta la vista!$"

gText_082BBA6C:: @ 82BBA6C
	.string "{STR_VAR_1}? Tu m'en as déjà parlé,\n"
	.string "tu as oublié?\p"
	.string "Attends…\n"
	.string "Tu veux dire que mon {STR_VAR_2}\l"
	.string "peut gagner sans objet?$"

gText_082BBB01:: @ 82BBB01
	.string "{PLAYER}{KUN}, il m'est arrivé un truc\n"
	.string "incroyable!\p"
	.string "Quand je me suis réveillé ce matin,\n"
	.string "mon POKéMON avait 10 PEPITES!\p"
	.string "Non, je rigole!\n"
	.string "Ha, ha, ha!\p"
	.string "Bon, le fait est que je ne connais rien\n"
	.string "aux objets. Je ne sais pas lesquels\l"
	.string "il faut faire porter aux POKéMON.\p"
	.string "Tu pourrais me dire ce que mon\n"
	.string "{STR_VAR_1} devrait porter?$"

gText_082BBC1C:: @ 82BBC1C
	.string "Comment? Il ne doit rien porter?\n"
	.string "C'est ce que tu me dis?$"

gText_082BBC4B:: @ 82BBC4B
	.string "Pas d'objet, d'après toi…\n"
	.string "Je vais lui en trouver un, alors!\p"
	.string "Je rigole, bien sûr que je vais suivre\n"
	.string "ton conseil!\p"
	.string "Merci! J'espère que tu m'apprendras\n"
	.string "encore plein d'autres choses!$"

gText_082BBCF6:: @ 82BBCF6
	.string "{STR_VAR_1}? Je vais lui faire porter\n"
	.string "autre chose, alors!\p"
	.string "Je rigole, bien sûr que je vais suivre\n"
	.string "ton conseil!\p"
	.string "Merci! J'espère que tu m'apprendras\n"
	.string "encore plein d'autres choses!$"

gText_082BBD90:: @ 82BBD90
	.string "Tu m'as déjà parlé de ça, non?\n"
	.string "Si, je me souviens…\p"
	.string "Tu n'as pas une autre idée?\p"
	.string "Ou alors, tu veux dire que mon\n"
	.string "{STR_VAR_2} ne doit rien porter?$"

gText_082BBE0B:: @ 82BBE0B
	.string "Ohé, matelot!\n"
	.string "C'est le salut des marins, matelot!\p"
	.string "C'est moi, le MARIN chantant!\n"
	.string "C'est toujours un plaisir de te voir,\l"
	.string "soit dit en passant!\p"
	.string "J'ai une question sur les objets.\n"
	.string "Je compte sur toi, mon rouget!\p"
	.string "Mon {STR_VAR_1} doit porter un objet.\n"
	.string "Lequel peux-tu me conseiller?$"

gText_082BBEE5:: @ 82BBEE5
	.string "Vraiment?\n"
	.string "Mon {STR_VAR_1} n'a pas besoin de\l"
	.string "porter un objet?$"

gText_082BBF25:: @ 82BBF25
	.string "Je vais suivre ton conseil!\n"
	.string "Car ton intelligence est sans pareille!\p"
	.string "Tes conseils me sont précieux,\n"
	.string "{PLAYER}! Toi, tu as l'esprit belliqueux!$"

gText_082BBFA4:: @ 82BBFA4
	.string "{STR_VAR_1}? Je vais l'utiliser!\n"
	.string "Te demander conseil était une\l"
	.string "bonne idée!\p"
	.string "Ton avis m'est précieux,\n"
	.string "{PLAYER}! Toi, tu as l'esprit belliqueux!$"

gText_082BC024:: @ 82BC024
	.string "{STR_VAR_1}, tu dis?\n"
	.string "Mais tu m'en as déjà parlé.\l"
	.string "Je veux quelque chose de nouveau.\p"
	.string "Ou est-ce qu'il se pourrait… que mon\n"
	.string "POKéMON n'ait pas besoin d'objet?$"

gText_082BC0C8:: @ 82BC0C8
	.string "Bonjour, {PLAYER}!\n"
	.string "Comme on se retrouve!\p"
	.string "Que faire? Te parler, au risque\n"
	.string "de t'importuner? Mon choix est fait!\p"
	.string "{PLAYER}, j'espère que tu ne te lasses\n"
	.string "pas de moi!\p"
	.string "En tout cas, moi, je ne me lasse pas\n"
	.string "de toi!\p"
	.string "Tu as une minute à m'accorder?\n"
	.string "J'aurais besoin d'un conseil.\p"
	.string "Je veux faire porter un objet à mon\n"
	.string "{STR_VAR_1}, mais je ne sais pas lequel\l"
	.string "choisir! Tu veux bien m'aider?$"

gText_082BC213:: @ 82BC213
	.string "Mon {STR_VAR_1} n'a besoin de rien?\n"
	.string "Rien de rien?$"

gText_082BC247:: @ 82BC247
	.string "Tu as un grand savoir-faire,\n"
	.string "alors c'est ce que je vais faire!\p"
	.string "{PLAYER}, je dois y aller!\n"
	.string "Pense à moi!\p"
	.string "A bientôt, j'espère!$"

gText_082BC2DD:: @ 82BC2DD
	.string "{STR_VAR_1}? Quel précieux conseil…\n"
	.string "A chaque fois, je m'émerveille!\p"
	.string "{PLAYER}, je dois y aller!\n"
	.string "Pense à moi!\p"
	.string "A bientôt, j'espère!$"

gText_082BC373:: @ 82BC373
	.string "{STR_VAR_1}? Ce nom ne m'est pas\n"
	.string "inconnu. Ce conseil, je l'ai déjà reçu!\p"
	.string "Mais se pourrait-il…\n"
	.string "que mon {STR_VAR_2} n'ait besoin de\l"
	.string "rien? Vraiment, rien de rien?$"

gText_082BC40E:: @ 82BC40E
	.string "Aïe! Ouille! Je me suis cassé le bras,\n"
	.string "{PLAYER}{KUN}! Ne t'approche pas!\p"
	.string "J'essayais de faire porter des objets\n"
	.string "à mes POKéMON et je me suis fait mal\l"
	.string "au bras. Je pense qu'il est cassé.\p"
	.string "Je crois que j'ai besoin de ton aide\n"
	.string "en ce qui concerne les objets.\p"
	.string "{PLAYER}{KUN}, qu'est-ce que je devrais faire\n"
	.string "porter à mon {STR_VAR_1}?$"

gText_082BC514:: @ 82BC514
	.string "Ouille…\p"
	.string "Tu penses que mon {STR_VAR_1} ne\n"
	.string "devrait rien porter?$"

gText_082BC555:: @ 82BC555
	.string "Hum! Très bien. Etant donné que j'ai\n"
	.string "le bras cassé, ça m'arrange.\p"
	.string "Ça fait plaisir de pouvoir compter sur\n"
	.string "quelqu'un. Merci!$"

gText_082BC5CE:: @ 82BC5CE
	.string "{STR_VAR_1}? Très bien. Mon bras va\n"
	.string "déjà mieux. Je vais donner cet objet\l"
	.string "à mon POKéMON.\p"
	.string "Ça fait plaisir de pouvoir compter sur\n"
	.string "quelqu'un. Merci!$"

gText_082BC666:: @ 82BC666
	.string "{STR_VAR_1}? Non, non, tu m'en as déjà\n"
	.string "parlé… Tu te souviens?\p"
	.string "Tu n'as pas une meilleure idée?\p"
	.string "Oh, attends…\n"
	.string "Tu veux dire que mon {STR_VAR_2} ne\l"
	.string "devrait rien porter?$"

gText_082BC714:: @ 82BC714
	.string "Hum… Euh…\n"
	.string "{PLAYER}{KUN}…\p"
	.string "Ne me regarde pas comme ça…\n"
	.string "Mes POKéMON ne portent aucun objet.\p"
	.string "Euh… Ça me gêne un peu…\n"
	.string "J'aurais besoin de ton aide.\p"
	.string "Je n'arrive pas à décider quel est le\n"
	.string "meilleur objet pour mon {STR_VAR_1}.\p"
	.string "{PLAYER}{KUN}, qu'est-ce que tu en penses?\n"
	.string "Quel objet je dois lui faire porter?$"

gText_082BC808:: @ 82BC808
	.string "Oh… Tu penses que c'est mieux que mon\n"
	.string "{STR_VAR_1} ne porte rien?$"

gText_082BC84D:: @ 82BC84D
	.string "Oh… C'est entendu!\n"
	.string "J'oublie les objets, alors.\p"
	.string "Je n'arrive pas à le croire…\n"
	.string "Quel bonheur de parler avec toi!\p"
	.string "Merci, {PLAYER}{KUN}.\n"
	.string "J'espère qu'on va se revoir, tu es\l"
	.string "vraiment de bon conseil.$"

gText_082BC8EA:: @ 82BC8EA
	.string "Oh… {STR_VAR_1}? C'est entendu!\n"
	.string "Je vais essayer ça.\p"
	.string "Je n'arrive pas à le croire…\n"
	.string "Quel bonheur de parler avec toi!\p"
	.string "Merci, {PLAYER}{KUN}.\n"
	.string "J'espère qu'on va se revoir, tu es\l"
	.string "vraiment de bon conseil.$"

gText_082BC984:: @ 82BC984
	.string "Mais je le sais déjà, ça. Tu ne veux pas\n"
	.string "m'aider… Je vois.\p"
	.string "Je m'y attendais…\n"
	.string "Je ne supporte pas d'être humilié!\p"
	.string "Oh… Mais je me trompe peut-être.\n"
	.string "Tu veux dire qu'il vaut mieux que mon\l"
	.string "{STR_VAR_2} ne porte pas d'objet?$"

gText_082BCA4D:: @ 82BCA4D
	.string "Tiens… {PLAYER}{KUN},\n"
	.string "n'est-ce pas?\l"
	.string "A moins que tu ne sois son sosie?\p"
	.string "Mais, si tu es vraiment {PLAYER}, je te\n"
	.string "présente mes excuses. Je ne voulais\l"
	.string "pas te mettre dans l'embarras.\p"
	.string "J'ai de nouveau besoin de tes conseils\n"
	.string "avisés.\p"
	.string "J'ai avec moi mon {STR_VAR_1} et je\n"
	.string "souhaite lui faire porter un objet.\p"
	.string "Lequel me conseilles-tu?$"

gText_082BCB75:: @ 82BCB75
	.string "Tu me conseilles de ne rien lui donner?\n"
	.string "Vraiment?$"

gText_082BCBA6:: @ 82BCBA6
	.string "Je te remercie, c'est très aimable\n"
	.string "de ta part.\p"
	.string "Au revoir!$"

gText_082BCBFC:: @ 82BCBFC
	.string "{STR_VAR_1}?\n"
	.string "Vraiment?\p"
	.string "Je te remercie, c'est très aimable\n"
	.string "de ta part.\p"
	.string "Je suis sûr que cela me sera très utile.\p"
	.string "Au revoir!$"

gText_082BCCA4:: @ 82BCCA4
	.string "Mais, dis-moi…\n"
	.string "Ne m'aurais-tu pas déjà parlé de ça?\p"
	.string "N'aurais-tu pas un autre objet à me\n"
	.string "proposer?\p"
	.string "Ou peut-être veux-tu dire que mon\n"
	.string "{STR_VAR_2} ne doit rien porter?\l"
	.string "C'est cela?$"

gText_082BCD68:: @ 82BCD68
	.string "Ah, {PLAYER}!\n"
	.string "J'ai un problème…\p"
	.string "Je veux commencer à faire des combats,\n"
	.string "mais je ne sais pas comment m'y prendre.\p"
	.string "Dans quel ordre dois-je placer mes\n"
	.string "POKéMON?\p"
	.string "Dis-moi, {PLAYER}.\n"
	.string "A ma place, quel POKéMON enverrais-tu\l"
	.string "en premier?$"

gText_082BCE64:: @ 82BCE64
	.string "C'est mon {STR_VAR_1} qui doit aller au\n"
	.string "combat en premier? Aaah!\p"
	.string "Oh, je suis désolé!\n"
	.string "Ton aide me fait tellement chaud au\l"
	.string "cœur que ça me fait pleurer…\p"
	.string "Merci infiniment!$"

gText_082BCEF2:: @ 82BCEF2
	.string "Super, {PLAYER}! Tu tombes bien,\n"
	.string "j'ai une question pour toi!\p"
	.string "D'après toi, lequel de mes POKéMON\n"
	.string "je dois envoyer au combat en premier?$"

gText_082BCF61:: @ 82BCF61
	.string "Mon {STR_VAR_1}? Tu as raison.\n"
	.string "Je vais suivre ton conseil!\p"
	.string "Merci!$"

gText_082BCFA1:: @ 82BCFA1
	.string "Salut, {PLAYER}!\p"
	.string "Il paraît qu'il faut bien choisir le\n"
	.string "POKéMON qu'on envoie en premier.\p"
	.string "Lequel de mes POKéMON je devrais\n"
	.string "envoyer en premier, d'après toi?$"

gText_082BD03C:: @ 82BD03C
	.string "Mon {STR_VAR_1} devrait être le\n"
	.string "premier? D'acc!\p"
	.string "A plus!$"

gText_082BD06D:: @ 82BD06D
	.string "Bonjour, {PLAYER}…\n"
	.string "Je suis désolée de te déranger, mais\l"
	.string "j'aimerais te poser une autre question.\p"
	.string "Je n'ai pas assez confiance en moi\n"
	.string "pour gagner, je le sais…\p"
	.string "J'essaie de m'améliorer, d'établir\n"
	.string "une stratégie, mais je doute de moi…\p"
	.string "Dis, quel POKéMON devrais-je envoyer\n"
	.string "au combat en premier, d'après toi?$"

gText_082BD18A:: @ 82BD18A
	.string "Mon {STR_VAR_1}?\n"
	.string "C'est compris!\p"
	.string "C'est vraiment gentil de ta part de me\n"
	.string "conseiller comme ça!\p"
	.string "J'ai toujours peur que tu refuses de me\n"
	.string "parler, mais tu es super… Merci!$"

gText_082BD222:: @ 82BD222
	.string "Oh, {PLAYER}{KUN}! C'est moi, tu me\n"
	.string "reconnais?\l"
	.string "Je suis contente de te voir!\p"
	.string "Je ne sais pas dans quel ordre placer\n"
	.string "mes POKéMON. Tu peux m'aider?\p"
	.string "Je ne te demande pas d'ordonner toute\n"
	.string "l'équipe, ce serait trop…\p"
	.string "Mais tu pourrais au moins me dire quel \n"
	.string "POKéMON je dois envoyer en premier?$"

gText_082BD325:: @ 82BD325
	.string "Mon {STR_VAR_1}? Super!\p"
	.string "Comme c'est ta décision, ce sera\n"
	.string "ta faute si je perds, {PLAYER}{KUN}!\p"
	.string "Non, sérieusement. Je te fais\n"
	.string "entièrement confiance. Salut!$"

gText_082BD3B1:: @ 82BD3B1
	.string "C'est {PLAYER}{KUN}!\n"
	.string "C'est encore la course aujourd'hui!\p"
	.string "Au programme: vélo, shopping et\n"
	.string "chorale.\p"
	.string "Je n'ai même pas encore eu le temps\n"
	.string "d'ordonner mon équipe POKéMON!\p"
	.string "Si on le faisait ensemble?\n"
	.string "Lequel je dois envoyer en premier?$"

gText_082BD493:: @ 82BD493
	.string "D'accord, je m'en remets à ton jugement.\n"
	.string "Placer mon {STR_VAR_1} en premier ne\l"
	.string "devrait pas me prendre trop de temps!\p"
	.string "Ma copine m'attend, je dois y aller!\n"
	.string "Merci. A plus!$"

gText_082BD51C:: @ 82BD51C
	.string "Bonjour, {PLAYER}! Tu es partout,\n"
	.string "toi!\p"
	.string "Comme d'habitude, j'ai besoin de ton\n"
	.string "aide!\p"
	.string "Cette fois-ci, ma question est sur mon\n"
	.string "équipe POKéMON.\p"
	.string "Quel POKéMON tu me conseilles d'envoyer\n"
	.string "en premier au combat?$"

gText_082BD609:: @ 82BD609
	.string "Mon {STR_VAR_1}? Super!\n"
	.string "Je vais suivre ton conseil, comme\l"
	.string "d'habitude!\p"
	.string "Bon, c'est tout ce que j'avais à te\n"
	.string "demander, je crois.\p"
	.string "Mais on se reverra sûrement!\n"
	.string "Merci!$"

gText_082BD697:: @ 82BD697
	.string "C'est gentil de t'arrêter pour discuter\n"
	.string "avec moi, {PLAYER}.\p"
	.string "Puisque tu es là…\n"
	.string "Je peux te poser une petite question?\p"
	.string "J'aimerais déterminer l'ordre de mes\n"
	.string "POKéMON.\p"
	.string "J'aimerais que tu me dises quel POKéMON\n"
	.string "je dois placer en premier.$"

gText_082BD797:: @ 82BD797
	.string "{STR_VAR_1}? Parfait!\n"
	.string "C'est ce que je vais faire!\p"
	.string "Merci, {PLAYER}.\n"
	.string "Je savais que je pouvais compter sur\l"
	.string "toi. A bientôt!$"

gText_082BD806:: @ 82BD806
	.string "Oh, {PLAYER}!\n"
	.string "Quel plaisir de te revoir!\p"
	.string "Je m'améliore aux combats POKéMON,\n"
	.string "tu sais!?!\p"
	.string "Je ne gagne pas toujours, car je ne sais\n"
	.string "jamais quel POKéMON envoyer en premier.\p"
	.string "{PLAYER}, tu dois m'aider!\p"
	.string "Dis-moi quel POKéMON je dois envoyer\n"
	.string "au combat en premier!$"

gText_082BD8F5:: @ 82BD8F5
	.string "Je suis si heureuse…\n"
	.string "Sniff…\p"
	.string "Quel honneur, tu me fais {PLAYER}.\p"
	.string "C'est entendu, je vais envoyer\n"
	.string "{STR_VAR_1} en premier!\p"
	.string "J'espère que tu me donneras encore\n"
	.string "plein de conseils!$"

gText_082BD9BE:: @ 82BD9BE
	.string "Bonjour, bonjour!\n"
	.string "{PLAYER}{KUN}, mon mentor!\l"
	.string "J'ai besoin de tes lumières.\p"
	.string "Voilà. J'ai trois POKéMON dans mon\n"
	.string "équipe. Jusque-là, ça va.\p"
	.string "Mais je voudrais les placer dans un\n"
	.string "certain ordre.\p"
	.string "C'est là que tu interviens, {PLAYER}{KUN}.\n"
	.string "A toi de choisir le premier POKéMON!\p"
	.string "Dis-le-moi, je te fais une confiance\n"
	.string "aveugle!$"

gText_082BDAE1:: @ 82BDAE1
	.string "Mon {STR_VAR_1} doit être le premier?\n"
	.string "Compris, je vais de ce pas ordonner mes\l"
	.string "POKéMON!\p"
	.string "Merci!\n"
	.string "Hasta la vista!$"

gText_082BDB4E:: @ 82BDB4E
	.string "{PLAYER}{KUN}, tu tombes bien!\n"
	.string "C'est une catastrophe… \p"
	.string "Mes trois POKéMON se battent en même\n"
	.string "temps!\p"
	.string "Non, je rigole! Ha, ha, ha!\n"
	.string "Tu sais bien que c'est impossible!\p"
	.string "Par contre, ce qui est vrai, c'est que\n"
	.string "j'aimerais savoir dans quel ordre placer\l"
	.string "mes POKéMON.\p"
	.string "Tu ne voudrais pas décider pour moi\n"
	.string "quel POKéMON je dois placer en premier?$"

gText_082BDC6B:: @ 82BDC6B
	.string "Tu choisis mon {STR_VAR_1}?\n"
	.string "Mais tu es bête ou quoi?\p"
	.string "Je rigole, bien sûr que je vais suivre\n"
	.string "ton conseil!\p"
	.string "Merci! J'espère que tu me donneras\n"
	.string "encore plein de bons conseils!$"

gText_082BDD0D:: @ 82BDD0D
	.string "Ohé, matelot!\n"
	.string "C'est le salut des marins, moussaillon!\p"
	.string "C'est moi, le MARIN chantant!\n"
	.string "J'ai une question pour toi, mon merlan!\p"
	.string "L'ordre des POKéMON en est le sujet.\n"
	.string "Je compte sur toi, mon rouget!\p"
	.string "Lequel de mes POKéMON doit se\n"
	.string "battre en premier?$"

gText_082BDDEC:: @ 82BDDEC
	.string "Tant de sagesse!\n"
	.string "La foule est en liesse!\p"
	.string "Tes conseils me sont précieux,\n"
	.string "{PLAYER}! Toi, tu as l'esprit belliqueux!$"

gText_082BDE68:: @ 82BDE68
	.string "{PLAYER}, c'est bien toi?\n"
	.string "{PLAYER}, comment ça va?\p"
	.string "Que faire? Te demander, au risque\n"
	.string "de t'importuner? Mon choix est fait!\l"
	.string "Tu m'as compris? Oui, tu m'as compris!\p"
	.string "Tu dois décider lequel de mes POKéMON\n"
	.string "doit entrer en scène le premier!\l"
	.string "Il n'y a que toi qui puisses m'aider!$"

gText_082BDF4D:: @ 82BDF4D
	.string "{STR_VAR_1}? Oui, très bonne idée!\n"
	.string "Je vais le faire sans hésiter!\p"
	.string "{PLAYER}, je dois y aller!\n"
	.string "Pense à moi!\p"
	.string "A bientôt, j'espère!$"

gText_082BDFD8:: @ 82BDFD8
	.string "Aïe… Ouille…\n"
	.string "J'ai des crampes d'estomac,\l"
	.string "{PLAYER}{KUN}! C'est horrible!\p"
	.string "Ah… Ça a l'air de se calmer…\p"
	.string "Ça m'arrive quand je suis nerveux.\n"
	.string "Depuis des heures, j'essaie de décider\l"
	.string "d'un ordre pour mon équipe POKéMON…\p"
	.string "Je n'y arrive pas.\n"
	.string "Tu dois m'aider.\p"
	.string "{PLAYER}{KUN}, quel POKéMON je dois\n"
	.string "envoyer le premier au combat?$"

gText_082BE0FD:: @ 82BE0FD
	.string "Hum, très bien.\n"
	.string "Mon {STR_VAR_1} sera le premier.\p"
	.string "Je vais le faire tout de suite et après\n"
	.string "j'irai manger.\p"
	.string "Ça fait plaisir de pouvoir compter sur\n"
	.string "quelqu'un. Merci!$"

gText_082BE189:: @ 82BE189
	.string "Euh… Hum…\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Ne me fixe pas comme ça,\n"
	.string "tu me rends nerveux…\p"
	.string "Hum…\n"
	.string "J'ai besoin de ton aide.\p"
	.string "Ça me gêne de te parler de ça, mais j'ai\n"
	.string "trois POKéMON et je ne sais pas\l"
	.string "comment les placer dans l'équipe.\p"
	.string "Quel POKéMON est-ce que je devrais\n"
	.string "envoyer au combat en premier?$"

gText_082BE2A5:: @ 82BE2A5
	.string "Oh… C'est d'accord!\n"
	.string "Je vais placer {STR_VAR_1} en premier.\p"
	.string "Ça devrait me permettre d'être plus\n"
	.string "serein lors des combats.\p"
	.string "Merci, {PLAYER}{KUN}.\n"
	.string "J'espère qu'on va se revoir, tu es\l"
	.string "vraiment de bon conseil.$"

gText_082BE33E:: @ 82BE33E
	.string "Tiens… Es-tu vraiment\n"
	.string "{PLAYER}{KUN}?\l"
	.string "A moins que tu ne sois son sosie?\p"
	.string "Mais, si tu es vraiment {PLAYER}, je te\n"
	.string "présente mes excuses. Je ne voulais\l"
	.string "pas te vexer.\p"
	.string "J'ai de nouveau besoin de tes conseils\n"
	.string "avisés.\p"
	.string "J'aimerais savoir lequel de mes\n"
	.string "POKéMON je devrais envoyer au\l"
	.string "combat en premier.$"

gText_082BE46C:: @ 82BE46C
	.string "Mon {STR_VAR_1}…\n"
	.string "Tu ne te moques pas de moi?\p"
	.string "Je te remercie, c'est très aimable\n"
	.string "de ta part.\p"
	.string "Je vais suivre ton conseil et faire de\n"
	.string "mon mieux.\p"
	.string "Au revoir!$"

gText_082BE50D:: @ 82BE50D
	.string "Sniff…\n"
	.string "Oh, {PLAYER}!\p"
	.string "Tu tombes bien, je suis devant un\n"
	.string "vrai dilemme…\p"
	.string "Je ne sais pas quel POKéMON je devrais\n"
	.string "utiliser.\p"
	.string "Je n'arrive pas à choisir entre les\n"
	.string "POKéMON {STR_VAR_1} et {STR_VAR_2}…\p"
	.string "{PLAYER}, avec lequel tu penses que j'ai\n"
	.string "le plus de chances de gagner?$"

gText_082BE5F5:: @ 82BE5F5
	.string "Sniff… … Tu as raison!\n"
	.string "C'est tellement gentil de ta part de\l"
	.string "m'aider que ça me fait pleurer…\p"
	.string "Je vais de ce pas attraper un\n"
	.string "{STR_VAR_1}!\p"
	.string "Merci beaucoup!$"

gText_082BE679:: @ 82BE679
	.string "Super, {PLAYER}! Je suis content de\n"
	.string "te revoir, j'ai besoin de tes conseils!\p"
	.string "Je ne sais pas je si dois dresser\n"
	.string "mon {STR_VAR_1} ou mon {STR_VAR_2}…\p"
	.string "Lequel je devrais dresser,\n"
	.string "{PLAYER}?$"

gText_082BE71E:: @ 82BE71E
	.string "Mon {STR_VAR_1}, tu penses?\n"
	.string "C'est lui que je vais dresser, alors!\p"
	.string "Merci du conseil!$"

gText_082BE762:: @ 82BE762
	.string "Salut, {PLAYER}!\n"
	.string "J'ai une question à te poser.\p"
	.string "Je me demande si je devrais dresser\n"
	.string "un {STR_VAR_1} ou un {STR_VAR_2}.\p"
	.string "Lequel est le plus fort, à ton avis?$"

gText_082BE7F8:: @ 82BE7F8
	.string "{STR_VAR_1}?\n"
	.string "Allez, je te fais confiance!\p"
	.string "Je vais aller capturer un {STR_VAR_1},\n"
	.string "alors!\p"
	.string "A plus tard!$"

gText_082BE850:: @ 82BE850
	.string "Bonjour, {PLAYER}…\p"
	.string "Je suis sûre que tu m'as déjà oubliée,\n"
	.string "mais on se connaît…\p"
	.string "Mais bon, même si tu m'as oubliée…\n"
	.string "j'aimerais te poser une question.\p"
	.string "Je ne sais pas quel POKéMON\n"
	.string "dresser…\p"
	.string "J'hésite entre {STR_VAR_1} et\n"
	.string "{STR_VAR_2}. Je n'arrive pas à faire un\l"
	.string "choix… Je les aime tous les deux…\p"
	.string "{PLAYER}, dis-moi lequel des deux je\n"
	.string "dois dresser, s'il te plaît.$"

gText_082BE99C:: @ 82BE99C
	.string "Tu crois que j'arriverais à dresser\n"
	.string "un {STR_VAR_1} sauvage?\p"
	.string "Bon, je vais essayer!\p"
	.string "Enfin, il faut d'abord que j'en attrape\n"
	.string "un…\p"
	.string "Merci!$"

gText_082BEA1B:: @ 82BEA1B
	.string "Oh, {PLAYER}{KUN}! Je suis contente de te\n"
	.string "voir! Je voulais te parler, justement!\p"
	.string "Il faut que tu me dises quel POKéMON\n"
	.string "je dois dresser.\p"
	.string "Par exemple…\n"
	.string "Que penses-tu des POKéMON {STR_VAR_1}\l"
	.string "et {STR_VAR_2}?\p"
	.string "Lequel des deux tu préfères?$"

gText_082BEAE9:: @ 82BEAE9
	.string "{STR_VAR_1}? Super!\p"
	.string "Comme c'est ta décision, ce sera\n"
	.string "ta faute si je perds, {PLAYER}{KUN}!\p"
	.string "Non, sérieusement. Je te fais\n"
	.string "entièrement confiance. Salut!$"

gText_082BEB72:: @ 82BEB72
	.string "Mais, c'est {PLAYER}{KUN}!\n"
	.string "Quel bon vent t'amène?\p"
	.string "Je veux me mettre sérieusement aux\n"
	.string "combats POKéMON, mais je ne sais pas\l"
	.string "encore quel POKéMON je vais dresser.\p"
	.string "Il paraît que {STR_VAR_1} est très fort.\n"
	.string "Mais {STR_VAR_2} me plaît bien aussi…\p"
	.string "Il faut que tu décides pour moi,\n"
	.string "{PLAYER}{KUN}. Lequel je dois dresser?$"

gText_082BEC8E:: @ 82BEC8E
	.string "D'accord.\n"
	.string "Je vais essayer de me libérer quelques\l"
	.string "heures pour capturer un {STR_VAR_1}.\p"
	.string "Dès que j'ai un souci, tu es là!\n"
	.string "Merci! A plus tard!$"

gText_082BED16:: @ 82BED16
	.string "Oh!\n"
	.string "Super, {PLAYER}!\p"
	.string "J'ai parlé de toi à toutes mes amies!\n"
	.string "Elles n'en revenaient pas…\p"
	.string "J'ai de nouveau besoin de ton aide.\n"
	.string "Ça ne prendra qu'une minute!\p"
	.string "Il me faut ton avis.\n"
	.string "Voici ma question…\p"
	.string "Si tu devais dresser un POKéMON,\n"
	.string "tu choisirais un {STR_VAR_1} ou un\l"
	.string "{STR_VAR_2}?$"

gText_082BEE29:: @ 82BEE29
	.string "Tu choisirais un {STR_VAR_1}?\n"
	.string "Super!\l"
	.string "Je vais suivre ton conseil!\p"
	.string "Bon, c'est tout ce que j'avais à te\n"
	.string "demander, je crois.\p"
	.string "Mais on se reverra sûrement!\n"
	.string "Merci encore!$"

gText_082BEEB4:: @ 82BEEB4
	.string "Oh! {PLAYER}?\n"
	.string "Quel plaisir de te rencontrer!\p"
	.string "Depuis que je suis ton apprentie,\n"
	.string "j'ai repris confiance en moi.\p"
	.string "Je crois même que je suis prête à élever\n"
	.string "mon propre POKéMON!\p"
	.string "{PLAYER}, j'aimerais que tu choisisses\n"
	.string "un POKéMON pour moi.\p"
	.string "J'ai le choix entre {STR_VAR_1} et\n"
	.string "{STR_VAR_2}…\l"
	.string "Lequel m'irait le mieux?$"

gText_082BEFE2:: @ 82BEFE2
	.string "Le {STR_VAR_1}?\n"
	.string "Parfait!\p"
	.string "Merci, {PLAYER}.\n"
	.string "Je savais que je pouvais compter sur\l"
	.string "toi. A bientôt!$"

gText_082BF04E:: @ 82BF04E
	.string "{PLAYER}? Décidément, comme\n"
	.string "on se retrouve!\p"
	.string "Tiens, puisque tu es là, je vais en\n"
	.string "profiter.\p"
	.string "Tu peux me rendre un service, {PLAYER}?\n"
	.string "Choisis un POKéMON pour moi!\p"
	.string "J'hésite entre {STR_VAR_1} et\n"
	.string "{STR_VAR_2}.$"

gText_082BF11D:: @ 82BF11D
	.string "Waouh! Ça me fait plaisir, tu sais.\n"
	.string "C'est d'accord, je vais élever un\l"
	.string "{STR_VAR_1}.\p"
	.string "J'espère que tu me donneras encore\n"
	.string "plein de conseils!$"

gText_082BF1A8:: @ 82BF1A8
	.string "Hé, hé!\n"
	.string "{PLAYER}{KUN}, mon mentor!\p"
	.string "Je te cherchais, j'ai besoin de tes\n"
	.string "conseils éclairés!\p"
	.string "Quel POKéMON je devrais dresser,\n"
	.string "un {STR_VAR_1} ou un {STR_VAR_2}?\p"
	.string "Dis-moi, je te fais une confiance\n"
	.string "aveugle!$"

gText_082BF268:: @ 82BF268
	.string "Un {STR_VAR_1}!\n"
	.string "Je vais en capturer un en un tour\l"
	.string "de main!\p"
	.string "Merci!\n"
	.string "Hasta la vista!$"

gText_082BF2D1:: @ 82BF2D1
	.string "{PLAYER}{KUN}, tu ne devineras jamais!\n"
	.string "J'ai capturé un POKéMON mirage!\p"
	.string "Mais non, ce n'est pas vrai!\n"
	.string "Ha, ha, ha!\p"
	.string "Tu as cinq minutes?\n"
	.string "J'aimerais te demander ton avis.\l"
	.string "Je ne sais pas quel POKéMON capturer.\p"
	.string "Si tu pouvais décider pour moi, ça\n"
	.string "m'arrangerait!\l"
	.string "J'hésite entre deux POKéMON.\p"
	.string "Lequel je dois choisir, {STR_VAR_1}\n"
	.string "ou {STR_VAR_2}?$"

gText_082BF3CF:: @ 82BF3CF
	.string "{STR_VAR_1}, tu dis?\n"
	.string "Je vais capturer l'autre, alors!\p"
	.string "Je rigole, bien sûr que je vais suivre\n"
	.string "ton conseil!\p"
	.string "Merci! J'espère que tu m'apprendras\n"
	.string "encore plein d'autres choses!$"

gText_082BF46A:: @ 82BF46A
	.string "Ohé, matelot!\n"
	.string "C'est le salut des marins, moussaillon!\p"
	.string "C'est moi, le MARIN chantant!\n"
	.string "J'ai une question pour toi, mon enfant.\p"
	.string "Les POKéMON en sont le sujet.\n"
	.string "Je compte sur toi, mon rouget!\p"
	.string "Je veux en capturer un, mais entre\n"
	.string "{STR_VAR_1} et {STR_VAR_2}, je ne sais\l"
	.string "lequel choisir! Qu'en penses-tu?$"

gText_082BF551:: @ 82BF551
	.string "{STR_VAR_1}? C'est décidé!\n"
	.string "C'est lui que je vais capturer!\p"
	.string "Tes conseils me sont précieux,\n"
	.string "{PLAYER}! Toi, tu as l'esprit belliqueux!$"

gText_082BF5C3:: @ 82BF5C3
	.string "Attention… Voici {PLAYER}!\p"
	.string "Mais que faire? Te parler, au risque\n"
	.string "de t'importuner? Mon choix est fait!\p"
	.string "Ça faisait longtemps, tu sais,\n"
	.string "que je te cherchais!\l"
	.string "Tu m'as compris? Oui, tu m'as compris!\p"
	.string "{STR_VAR_1}? {STR_VAR_2}? Quel dilemme!\n"
	.string "Lequel dois-je choisir?$"

gText_082BF6E5:: @ 82BF6E5
	.string "{STR_VAR_1}, tu dis?\n"
	.string "J'en suis ravi!\p"
	.string "{PLAYER}, je dois y aller!\n"
	.string "Pense à moi!\p"
	.string "A bientôt, j'espère!$"

gText_082BF773:: @ 82BF773
	.string "Oh, bonjour, {PLAYER}{KUN}…\n"
	.string "J'ai un mal de tête atroce…\p"
	.string "Il faut dire que je réfléchis depuis des\n"
	.string "heures mais je n'aboutis à rien.\p"
	.string "Je veux capturer un POKéMON,\n"
	.string "mais je n'arrive pas à décider lequel.\p"
	.string "J'ai réduit le choix à {STR_VAR_1} et\n"
	.string "{STR_VAR_2}. Lequel des deux\l"
	.string "tu choisirais, {PLAYER}{KUN}?$"

gText_082BF869:: @ 82BF869
	.string "{STR_VAR_1}? J'irai en capturer un dès\n"
	.string "que je me sentirai un peu mieux.\p"
	.string "Ça fait plaisir de pouvoir compter sur\n"
	.string "quelqu'un. Merci!$"

gText_082BF8DD:: @ 82BF8DD
	.string "Euh… Hum…\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Ne me fixe pas comme ça,\n"
	.string "tu me rends nerveux…\l"
	.string "J'ai besoin d'un conseil.\p"
	.string "Ça me gêne de t'ennuyer avec ça, mais\n"
	.string "je ne sais pas quel POKéMON capturer.\p"
	.string "Lequel est le plus fort, {STR_VAR_1}\n"
	.string "ou {STR_VAR_2}?$"

gText_082BF9BA:: @ 82BF9BA
	.string "D'accord!\n"
	.string "Je vais capturer un {STR_VAR_1}.\p"
	.string "Avoir un POKéMON fort, choisi par toi,\n"
	.string "me donnera confiance lors des combats.\p"
	.string "Merci, {PLAYER}{KUN}.\n"
	.string "J'espère qu'on va se revoir, tu es\l"
	.string "vraiment de bon conseil.$"

gText_082BFA5A:: @ 82BFA5A
	.string "Tu ressembles beaucoup à {PLAYER}{KUN}…\n"
	.string "Mais… est-ce toi?\p"
	.string "Oh, désolé si je n'ai pas vu qui tu es\n"
	.string "tout de suite. J'ai justement un conseil\l"
	.string "à te demander.\p"
	.string "C'est au sujet du POKéMON que je veux\n"
	.string "utiliser.\p"
	.string "Des POKéMON {STR_VAR_1} et\n"
	.string "{STR_VAR_2}, lequel choisirais-tu?$"

gText_082BFB4E:: @ 82BFB4E
	.string "{STR_VAR_1}?\n"
	.string "Vraiment?\p"
	.string "Je te remercie, c'est très aimable\n"
	.string "de ta part.\p"
	.string "Je pense que tu as raison. C'est celui\n"
	.string "qui me convient le mieux.\p"
	.string "Au revoir!$"

gText_082BFBF2:: @ 82BFBF2
	.string "Oh, {PLAYER}!\n"
	.string "Sniff… \p"
	.string "Quel dilemme!\n"
	.string "Je n'arrive pas à choisir une capacité\l"
	.string "pour mon {STR_VAR_1}…\p"
	.string "S'il te plaît, {PLAYER}…\n"
	.string "Est-ce que tu peux décider pour moi?\p"
	.string "Pour mon {STR_VAR_1}, je dois choisir\n"
	.string "{STR_VAR_2} ou {STR_VAR_3}?$"

gText_082BFCAE:: @ 82BFCAE
	.string "{STR_VAR_1}?\n"
	.string "Sniff…\p"
	.string "Oh, je suis désolé, {PLAYER}!\n"
	.string "Je suis tellement ému que tu m'aies aidé\l"
	.string "à faire ce choix que je pleure…\p"
	.string "Sniff…\n"
	.string "Merci!$"

gText_082BFD26:: @ 82BFD26
	.string "Hé, {PLAYER}!\n"
	.string "J'ai de nouveau besoin de toi!\p"
	.string "Je veux apprendre une capacité sympa à\n"
	.string "mon {STR_VAR_1}.\p"
	.string "J'aime autant {STR_VAR_2} que\n"
	.string "{STR_VAR_3}. Laquelle tu choisirais?$"

gText_082BFDB1:: @ 82BFDB1
	.string "Tu préfères {STR_VAR_1}?\n"
	.string "Je vais lui enseigner cette capacité!\p"
	.string "J'espère qu'on se reverra, j'ai encore\n"
	.string "plein de trucs à apprendre!$"

gText_082BFE24:: @ 82BFE24
	.string "Bonjour, {PLAYER}!\n"
	.string "Je ne sais pas quelle capacité mon\l"
	.string "{STR_VAR_1} devrait apprendre.\p"
	.string "Tu vois, j'hésite entre {STR_VAR_2}\n"
	.string "et {STR_VAR_3}.\p"
	.string "Laquelle de ces deux capacités\n"
	.string "convient mieux à mon {STR_VAR_1}?$"

gText_082BFEAD:: @ 82BFEAD
	.string "{STR_VAR_1}, tu crois?\n"
	.string "Je vais lui enseigner celle-là, alors!\p"
	.string "Maintenant que c'est décidé, il n'y a pas\n"
	.string "une minute à perdre!\p"
	.string "A plus!$"

gText_082BFF0A:: @ 82BFF0A
	.string "Oh, {PLAYER}…\n"
	.string "Je suis désespérée!\p"
	.string "J'ai décidé de dresser un POKéMON,\n"
	.string "mais je ne sais pas quelle capacité\l"
	.string "lui apprendre…\p"
	.string "Je suis sûre que tu dois me trouver\n"
	.string "bête, {PLAYER}.\p"
	.string "Mais pour moi, c'est important…\p"
	.string "Dis, {PLAYER}. Tu pourrais choisir une\n"
	.string "capacité pour mon {STR_VAR_1}?\p"
	.string "En fait, j'hésite entre {STR_VAR_2} et\n"
	.string "{STR_VAR_3}…$"

gText_082C0032:: @ 82C0032
	.string "D'accord!\p"
	.string "J'espère qu'il acceptera d'apprendre\n"
	.string "cette capacité…\l"
	.string "Je vais essayer, en tout cas!\p"
	.string "Merci!$"

gText_082C0090:: @ 82C0090
	.string "Oh, {PLAYER}{KUN}!\p"
	.string "Je me demandais quelle capacité je\n"
	.string "devrais enseigner à mon {STR_VAR_1}.\p"
	.string "Je n'arrive pas à me décider.\n"
	.string "Tu décides pour moi?\p"
	.string "{STR_VAR_2} ou {STR_VAR_3}?$"

gText_082C016E:: @ 82C016E
	.string "{STR_VAR_1}? Super!\p"
	.string "Comme c'est ta décision, ce sera\n"
	.string "ta faute si ça rate, {PLAYER}{KUN}!\p"
	.string "Non, sérieusement. Je te fais\n"
	.string "entièrement confiance. Salut!$"

gText_082C01F7:: @ 82C01F7
	.string "Comment ça se fait que j'ai toujours un\n"
	.string "millier de choses à faire?\l"
	.string "Hé, {PLAYER}{KUN}! Ça va?\p"
	.string "J'ai déjà fait mon footing, nagé et fait\n"
	.string "à manger! La journée n'est pas finie!\p"
	.string "Si tu savais tout ce que j'ai encore à\n"
	.string "faire!\p"
	.string "Je n'ai même pas le temps de choisir\n"
	.string "une capacité pour mon {STR_VAR_1}!\p"
	.string "{STR_VAR_2} est pas mal, mais j'aime\n"
	.string "aussi {STR_VAR_3}.\p"
	.string "{PLAYER}{KUN}, choisis une de ces\n"
	.string "deux capacités pour moi, s'il te plaît!$"

gText_082C034C:: @ 82C034C
	.string "D'accord.\n"
	.string "Je pense que j'arriverai à trouver un\l"
	.string "moment pour la lui enseigner.\p"
	.string "Je peux toujours compter sur toi.\n"
	.string "Merci! A la prochaine!$"

gText_082C03CA:: @ 82C03CA
	.string "Oh! Encore toi!\n"
	.string "Je suis contente de te revoir, {PLAYER}!\l"
	.string "Tu vas pouvoir m'aider!\p"
	.string "J'aimerais te poser une question.\n"
	.string "La voici…\p"
	.string "Quelle capacité convient le mieux à mon\n"
	.string "{STR_VAR_1}? {STR_VAR_2} ou\l"
	.string "{STR_VAR_3}?$"

gText_082C046E:: @ 82C046E
	.string "Ah!\n"
	.string "{STR_VAR_1}, tu dis?\l"
	.string "Je vais suivre ton conseil!\p"
	.string "Bon, c'est tout ce que j'avais à te\n"
	.string "demander, je crois.\p"
	.string "Mais on se reverra sûrement!\n"
	.string "Merci encore!$"

gText_082C04F9:: @ 82C04F9
	.string "Salut, {PLAYER}.\n"
	.string "Tu as l'air en pleine forme!\p"
	.string "J'aimerais te poser une question.\n"
	.string "C'est au sujet de mon {STR_VAR_1} adoré.\p"
	.string "Quelle est la capacité idéale pour\n"
	.string "mon petit {STR_VAR_1}, {STR_VAR_2}\l"
	.string "ou {STR_VAR_3}?$"

gText_082C0598:: @ 82C0598
	.string "{STR_VAR_1}? D'accord!\n"
	.string "Je vais la lui apprendre tout de suite!\p"
	.string "Merci, {PLAYER}.\n"
	.string "Je savais que je pouvais compter sur\l"
	.string "toi. A bientôt!$"

gText_082C0602:: @ 82C0602
	.string "{PLAYER}!\n"
	.string "Quelle joie de te revoir!\p"
	.string "Dès que j'ai besoin de toi, tu arrives!\n"
	.string "On dirait que tu lis dans mes pensées!\p"
	.string "J'aimerais bien que tu me conseilles\n"
	.string "au sujet des capacités!\p"
	.string "Je ne sais pas laquelle je devrais\n"
	.string "enseigner à mon {STR_VAR_1}!\p"
	.string "J'hésite entre {STR_VAR_2} et\n"
	.string "{STR_VAR_3}. Peux-tu en choisir une?$"

gText_082C06D8:: @ 82C06D8
	.string "Oh! Merci!\n"
	.string "Je vais lui enseigner {STR_VAR_1}!\l"
	.string "C'est un très bon choix!\p"
	.string "J'espère que tu me donneras encore\n"
	.string "plein de conseils!$"

gText_082C074A:: @ 82C074A
	.string "Bonjour, {PLAYER}{KUN}!\n"
	.string "Je vais encore te voler un conseil,\l"
	.string "aujourd'hui!\p"
	.string "Quelle capacité je dois enseigner à mon\n"
	.string "{STR_VAR_1}, d'après toi?\p"
	.string "Il me faut une capacité qui me permette\n"
	.string "de gagner à tous les coups!\p"
	.string "Je devrais choisir {STR_VAR_2} ou\n"
	.string "{STR_VAR_3}, d'après toi?$"

gText_082C0809:: @ 82C0809
	.string "Va pour {STR_VAR_1}!\n"
	.string "Je vais lui enseigner ça en moins de\l"
	.string "temps qu'il ne faut pour le dire!\p"
	.string "Merci!\n"
	.string "Hasta la vista!$"

gText_082C086E:: @ 82C086E
	.string "Hé, {PLAYER}{KUN}, tu ne vas pas me croire!\p"
	.string "Mon POKéMON a appris six capacités\n"
	.string "d'un coup!\p"
	.string "Mais non, je rigole!\n"
	.string "Ha, ha, ha!\p"
	.string "En fait, je ne sais même pas quelle\n"
	.string "capacité je dois lui enseigner.\p"
	.string "Ce serait sympa si tu pouvais m'aider\n"
	.string "un peu.\p"
	.string "Je dois choisir {STR_VAR_2} ou\n"
	.string "{STR_VAR_3} pour mon {STR_VAR_1}?$"

gText_082C0982:: @ 82C0982
	.string "D'accord, tu dis {STR_VAR_1}?\n"
	.string "Je vais lui enseigner l'autre, alors!\p"
	.string "Je rigole, bien sûr que je vais suivre\n"
	.string "ton conseil!\p"
	.string "Merci! J'espère que tu m'apprendras\n"
	.string "encore plein d'autres choses!$"

gText_082C0A1D:: @ 82C0A1D
	.string "Ohé, matelot!\n"
	.string "C'est le salut des marins, moussaillon!\p"
	.string "C'est moi, le MARIN chantant!\n"
	.string "Parce que chanter, c'est bien tentant!\p"
	.string "J'ai une question sur les capacités.\n"
	.string "Je compte sur toi, mon rouget!\p"
	.string "A ton avis, il vaut mieux que j'enseigne\n"
	.string "{STR_VAR_2} ou {STR_VAR_3}\l"
	.string "à mon {STR_VAR_1}?$"

gText_082C0AFD:: @ 82C0AFD
	.string "{STR_VAR_1}, tu dis?\n"
	.string "Je vais lui enseigner ça, pardi!\p"
	.string "Tes conseils me sont précieux,\n"
	.string "{PLAYER}! Toi, tu as l'esprit belliqueux!$"

gText_082C0B6F:: @ 82C0B6F
	.string "Mais, c'est {PLAYER}!\p"
	.string "Que faire? Te parler, au risque\n"
	.string "de t'importuner? Mon choix est fait!\p"
	.string "{PLAYER}, j'ai de nouveau besoin\n"
	.string "de ton avis!\p"
	.string "Tu m'as compris?\n"
	.string "Oui, tu m'as compris!\p"
	.string "Mon {STR_VAR_1}… Doit-il plutôt\n"
	.string "apprendre {STR_VAR_2} ou\l"
	.string "{STR_VAR_3}?$"

gText_082C0C7D:: @ 82C0C7D
	.string "{STR_VAR_1}, tu dis?\n"
	.string "J'en suis ravi!\p"
	.string "{PLAYER}, je dois y aller!\n"
	.string "Pense à moi!\p"
	.string "A bientôt, j'espère!$"

gText_082C0D0B:: @ 82C0D0B
	.string "Cof, cof! Oh, {PLAYER}{KUN}…\n"
	.string "J'ai attrapé froid…\p"
	.string "La fièvre m'empêche de choisir une\n"
	.string "capacité pour mon POKéMON…\p"
	.string "Je crois bien que j'ai besoin de ton\n"
	.string "aide.\p"
	.string "{PLAYER}{KUN}, me conseilles-tu\n"
	.string "{STR_VAR_2} ou {STR_VAR_3}\l"
	.string "pour mon {STR_VAR_1}?$"

gText_082C0DFE:: @ 82C0DFE
	.string "Cof! D'accord, {STR_VAR_1}. Dès que je\n"
	.string "serai guéri, je lui enseignerai.\p"
	.string "Ça fait plaisir de pouvoir compter sur\n"
	.string "quelqu'un. Merci!$"

gText_082C0E71:: @ 82C0E71
	.string "Euh… Hum…\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Ne me fixe pas comme ça,\n"
	.string "tu me rends nerveux…\l"
	.string "J'ai besoin de toi, je crois…\p"
	.string "Ça me gêne… J'aimerais que tu m'aides\n"
	.string "à choisir une capacité.\p"
	.string "C'est pour mon {STR_VAR_1}.\n"
	.string "Tu choisirais {STR_VAR_2} ou\l"
	.string "{STR_VAR_3}?$"

gText_082C0F6D:: @ 82C0F6D
	.string "Oh… D'accord!\n"
	.string "Je vais essayer {STR_VAR_1}.\p"
	.string "J'espère que ça va marcher…\n"
	.string "Quel bonheur de parler avec toi!\p"
	.string "Merci, {PLAYER}{KUN}.\n"
	.string "J'espère qu'on va se revoir, tu es\l"
	.string "vraiment de bon conseil.$"

gText_082C1003:: @ 82C1003
	.string "Tiens? Tu ressembles à {PLAYER}{KUN}…\n"
	.string "La ressemblance est frappante.\p"
	.string "Serais-tu par hasard un sosie? \p"
	.string "Je suis confus, bien sûr que c'est\n"
	.string "toi. Je suis désolé d'avoir douté!\p"
	.string "J'ai justement un conseil à te demander.\p"
	.string "C'est au sujet de mon {STR_VAR_1}.\p"
	.string "Dois-je lui enseigner {STR_VAR_2} ou\n"
	.string "{STR_VAR_3}? Qu'en penses-tu?$"

gText_082C1122:: @ 82C1122
	.string "{STR_VAR_1}?\n"
	.string "C'est sûr?\p"
	.string "Je te remercie, c'est très aimable\n"
	.string "de ta part.\p"
	.string "Cela ne devrait pas poser de problème.\p"
	.string "Au revoir!$"

gText_082C11D1:: @ 82C11D1
	.string "Oh… {PLAYER}?\n"
	.string "C'est {PLAYER}!\l"
	.string "Oh! Sniff… Ecoute…\p"
	.string "Dès que je me bats, je pleure…\n"
	.string "Je suis trop nerveux!\p"
	.string "Quand je gagne, j'aimerais arrêter de\n"
	.string "pleurer! Je devrais me détendre.\p"
	.string "Je sais, {PLAYER}! Si tu m'apprenais une\n"
	.string "phrase cool à dire quand je gagne?$"

gText_082C12D5:: @ 82C12D5
	.string "{STR_VAR_1}\p"
	.string "Super, j'aime bien!\n"
	.string "Je suis sûr que ça va marcher!\p"
	.string "Oh… Je suis désolé…\n"
	.string "Je pleure de joie…\p"
	.string "Sniff…\n"
	.string "Merci infiniment, {PLAYER}!\p"
	.string "Je vais faire de mon mieux…\n"
	.string "En ton honneur, {PLAYER}!\p"
	.string "{PLAYER}…\n"
	.string "La prochaine fois… nous nous battrons!$"

gText_082C13AB:: @ 82C13AB
	.string "Salut, {PLAYER}! Justement, je voulais\n"
	.string "te poser une question!\p"
	.string "Quand je gagne un match, je ne sais\n"
	.string "jamais quoi dire.\p"
	.string "Tu n'aurais pas une expression ou une\n"
	.string "phrase que je pourrais dire?$"

gText_082C1444:: @ 82C1444
	.string "{STR_VAR_1}\p"
	.string "C'est une super idée!\n"
	.string "La prochaine fois, je dirai ça!\p"
	.string "C'est gentil de m'aider!\n"
	.string "Je vais m'entraîner dur!\l"
	.string "Je veux te surprendre!\p"
	.string "La prochaine fois, on fera un combat,\n"
	.string "tu verras!$"

gText_082C1501:: @ 82C1501
	.string "Salut, {PLAYER}!\p"
	.string "Mes POKéMON et moi, on est gonflés\n"
	.string "à bloc!\p"
	.string "Mais il me manque une expression sympa\n"
	.string "à crier quand je gagne.\p"
	.string "Tu as une idée de ce que je pourrais\n"
	.string "dire?$"

gText_082C15B6:: @ 82C15B6
	.string "{STR_VAR_1}\p"
	.string "Cool!\n"
	.string "Je prends!\p"
	.string "Je vais me battre et gagner!\n"
	.string "J'ai hâte d'utiliser ton expression!\p"
	.string "Qui sait, peut-être qu'un jour on se\n"
	.string "battra, {PLAYER}?\p"
	.string "Il faudra qu'on se rencontre dans un\n"
	.string "lieu de combat!$"

gText_082C165E:: @ 82C165E
	.string "Salut, {PLAYER}…\n"
	.string "Je suis désolée de te déranger, mais\l"
	.string "je suis désespérée…\p"
	.string "Même quand je gagne…\n"
	.string "Même quand je gagne, je ne sais\l"
	.string "pas quoi dire…\p"
	.string "Tu ne peux pas comprendre ce que\n"
	.string "je ressens, {PLAYER}.\p"
	.string "Mais c'est important pour moi…\p"
	.string "Qu'est-ce que je pourrais bien dire\n"
	.string "quand je gagne, {PLAYER}?$"

gText_082C174F:: @ 82C174F
	.string "{STR_VAR_1}\p"
	.string "C'est bien trouvé!\p"
	.string "Euh… Je ne suis pas sûre d'oser\n"
	.string "dire ça. Je suis trop timide…\p"
	.string "Je te promets d'essayer!\p"
	.string "Merci de m'avoir consacré un peu de\n"
	.string "ton temps, {PLAYER}…\p"
	.string "Je vais faire de mon mieux.\p"
	.string "Tu m'auras certainement oubliée\n"
	.string "dans quelques minutes, mais moi\l"
	.string "je ne t'oublierai pas!$"

gText_082C1862:: @ 82C1862
	.string "Oh, {PLAYER}{KUN}!\n"
	.string "J'ai quelque chose à te dire.\p"
	.string "Je sais très bien que je ne suis pas\n"
	.string "toujours très polie ni très gentille…\p"
	.string "Alors quand je gagne un combat, j'ai\n"
	.string "peur qu'on me trouve arrogante.\p"
	.string "J'aimerais bien dire quelque chose\n"
	.string "de gentil à mon adversaire quand\l"
	.string "je gagne, mais je ne sais pas quoi!\p"
	.string "Je n'ai pas l'habitude de dire des\n"
	.string "choses gentilles, moi! Tu as une idée?$"

gText_082C19A0:: @ 82C19A0
	.string "{STR_VAR_1}\p"
	.string "Pas mal!\n"
	.string "C'est ce que je dirai dorénavant!\p"
	.string "Grâce à toi, je suis sûre de devenir\n"
	.string "super forte!\l"
	.string "Oh, j'ai dit une chose gentille!\p"
	.string "Je suis désolée pour toutes les fois\n"
	.string "où j'ai été un peu grossière avec toi.\p"
	.string "La prochaine fois, j'aimerais qu'on\n"
	.string "fasse un combat. A plus!$"

gText_082C1A76:: @ 82C1A76
	.string "J'ai toujours un millier de choses à\n"
	.string "faire! Je te cherchais, {PLAYER}{KUN}.\p"
	.string "Tu as l'air en forme. Je suis toujours\n"
	.string "en vadrouille, je tiens la forme aussi.\p"
	.string "Au programme d'aujourd'hui: combats,\n"
	.string "cartographie et pêche. Je n'arrête pas!\p"
	.string "Malgré tout, j'aimerais prendre le temps\n"
	.string "de saluer mon adversaire quand je\l"
	.string "gagne un combat.\p"
	.string "Tu as une idée de ce que je pourrais\n"
	.string "dire? Quelque chose de cool et concis…\l"
	.string "Aide-moi, {PLAYER}{KUN}!$"

gText_082C1C16:: @ 82C1C16
	.string "{STR_VAR_1}\p"
	.string "Merci, je peux bien prendre une\n"
	.string "seconde pour dire ça!\p"
	.string "Tu m'as beaucoup appris, je te\n"
	.string "remercie.\p"
	.string "Maintenant, il faut que je me concentre\n"
	.string "sur les combats.\p"
	.string "Merci pour tout, {PLAYER}{KUN}!\n"
	.string "Il faudra qu'on se batte, tous les deux!$"

gText_082C1CF5:: @ 82C1CF5
	.string "J'ai de la chance, en ce moment!\n"
	.string "Je suis contente de te voir, {PLAYER}!\l"
	.string "Bien sûr, j'ai une question à te poser…\p"
	.string "Alors voilà!\n"
	.string "Ma question est…\p"
	.string "Quand je gagne un combat, j'aimerais\n"
	.string "finir en beauté, genre star de cinéma!\l"
	.string "Tu as une phrase accrocheuse?$"

gText_082C1DC1:: @ 82C1DC1
	.string "{STR_VAR_1}\p"
	.string "C'est… tout simplement magnifique!\n"
	.string "Tout à fait ce qu'il me faut!\p"
	.string "Ecoute, je pense que je fais des\n"
	.string "progrès.\p"
	.string "J'ai décidé de me consacrer à ma\n"
	.string "carrière de DRESSEUR.\p"
	.string "C'est grâce à toi, {PLAYER}.\p"
	.string "Peut-être qu'un jour nous aurons\n"
	.string "l'occasion de nous battre, toi et moi?\p"
	.string "Merci pour tout!$"

gText_082C1EDC:: @ 82C1EDC
	.string "Oh, {PLAYER}.\n"
	.string "Je suis si contente de te connaître!\p"
	.string "Grâce à toi, j'ai pleinement confiance\n"
	.string "en mes POKéMON.\p"
	.string "Mais j'ai un petit souci…\p"
	.string "Les DRESSEURS disent toujours quelque\n"
	.string "chose quand ils gagnent un combat.\p"
	.string "Moi aussi, j'aimerais faire ça, mais je\n"
	.string "ne sais pas quoi dire!\p"
	.string "Est-ce que tu as quelque chose à me\n"
	.string "suggérer?$"

gText_082C1FEC:: @ 82C1FEC
	.string "{STR_VAR_1}\p"
	.string "J'aime beaucoup, merci!\n"
	.string "Ça m'a mise de bonne humeur!\p"
	.string "Je brûle d'impatience de dire ça!\p"
	.string "Malheureusement, je dois m'en aller,\n"
	.string "{PLAYER}… J'ai à faire!\p"
	.string "Je vais me battre sans relâche, mais\n"
	.string "jamais je ne t'oublierai.\p"
	.string "On se reverra peut être…\n"
	.string "Au revoir!$"

gText_082C20D1:: @ 82C20D1
	.string "Bonjour, {PLAYER}!\n"
	.string "Je suis toujours ravie de te voir!\p"
	.string "J'aimerais te poser une question,\n"
	.string "puisque tu es là!\p"
	.string "L'autre fois, j'ai gagné un combat.\n"
	.string "C'était grisant!\p"
	.string "J'étais tellement surprise que je\n"
	.string "n'ai pas su quoi dire!\p"
	.string "Tu as une réplique à me suggérer pour\n"
	.string "mes prochaines victoires, {PLAYER}?$"

gText_082C21FF:: @ 82C21FF
	.string "{STR_VAR_1}\p"
	.string "Superbe!\n"
	.string "Je vais dire ça!\l"
	.string "Je suis tellement heureuse!\p"
	.string "Merci!\n"
	.string "Tu as changé ma vie!\p"
	.string "A partir d'aujourd'hui, je consacrerai\n"
	.string "ma vie aux combats de POKéMON.\p"
	.string "Je te dois tout, {PLAYER}.\n"
	.string "Je ne te remercierai jamais assez!\p"
	.string "Il faut que je me sauve. Peut-être\n"
	.string "aurons-nous l'occasion de nous battre!$"

gText_082C231C:: @ 82C231C
	.string "Bonjour, {PLAYER}{KUN}!\p"
	.string "Tu sais, je vais bientôt me consacrer\n"
	.string "entièrement aux combats.\p"
	.string "Mais j'ai encore besoin d'un dernier\n"
	.string "petit conseil!\p"
	.string "Si jamais je gagne un combat, je\n"
	.string "ne saurai pas quoi dire à mon\l"
	.string "adversaire… Tu as une suggestion?$"

gText_082C2407:: @ 82C2407
	.string "{STR_VAR_1}\p"
	.string "Ça me plaît, ça!\n"
	.string "J'ai hâte de gagner, maintenant!\l"
	.string "Juste pour pouvoir dire ça!\p"
	.string "Il est temps de se dire au revoir…\n"
	.string "Merci pour tout!\p"
	.string "On se battra un jour, d'accord?\n"
	.string "Hasta la vista!$"

gText_082C24B5:: @ 82C24B5
	.string "{PLAYER}{KUN}, écoute ça!\p"
	.string "A chaque fois que je gagne un combat,\n"
	.string "je fais un long discours!\p"
	.string "Mais non, je rigole!\n"
	.string "Ha, ha, ha!\p"
	.string "En fait, c'est l'inverse. Je ne sais\n"
	.string "jamais quoi dire.\p"
	.string "Tu ne voudrais pas me trouver quelque\n"
	.string "chose à dire à chaque victoire?$"

gText_082C25B1:: @ 82C25B1
	.string "{STR_VAR_1}\p"
	.string "Ça ne va pas?\n"
	.string "Tu veux vraiment que je dise ça?!?\p"
	.string "Non, je plaisante!\n"
	.string "Je dirai ça à chaque victoire!\p"
	.string "Merci pour tout, tu m'as beaucoup\n"
	.string "appris depuis qu'on se connaît!\p"
	.string "Grâce à toi, j'ai compris ce qu'était un\n"
	.string "DRESSEUR.\p"
	.string "Je vais défier tous les DRESSEURS\n"
	.string "que je rencontrerai.\p"
	.string "Peut-être en feras-tu partie, qui sait?\p"
	.string "C'est ici que nos chemins se séparent.\n"
	.string "Adieu!$"

gText_082C2707:: @ 82C2707
	.string "Ohé, matelot!\n"
	.string "C'est le salut des marins, moussaillon!\p"
	.string "C'est moi, le MARIN chantant!\n"
	.string "J'ai une dernière question.\l"
	.string "Fais bien attention!\p"
	.string "Les victoires en sont le sujet.\n"
	.string "Je compte sur toi, mon rouget!\p"
	.string "Quand je gagne un combat,\n"
	.string "que dois-je dire, d'après toi?$"

gText_082C27D4:: @ 82C27D4
	.string "{STR_VAR_1}\p"
	.string "Crois-moi, je vais le dire,\n"
	.string "cela va sans dire!\p"
	.string "Tu sais, j'ai bien réfléchi…\n"
	.string "Aux POKéMON, je veux consacrer ma vie!!!\p"
	.string "Merci pour tous tes enseignements.\n"
	.string "Te connaître fut si enrichissant!\p"
	.string "Il est temps pour moi de lever l'ancre!\n"
	.string "Souhaite-moi “bon voyage”,\l"
	.string "je me battrai pour toi, en hommage!$"

gText_082C28D6:: @ 82C28D6
	.string "Bonjour, {PLAYER}!\n"
	.string "Comme on se retrouve!\p"
	.string "Que faire? Te parler, au risque\n"
	.string "de t'importuner? Mon choix est fait!\p"
	.string "{PLAYER}, tu m'as compris?\n"
	.string "Oui, tu m'as compris! Je veux ton avis!\p"
	.string "C'est à propos de mon cri de victoire.\n"
	.string "Que pourrais-je bien dire?\l"
	.string "Dans ma tête, c'est le brouillard.\p"
	.string "Propose-moi quelque chose!$"

gText_082C2A0B:: @ 82C2A0B
	.string "{STR_VAR_1}\p"
	.string "Parce que tu me l'as suggéré, c'est ce\n"
	.string "cri de victoire que je vais utiliser!\p"
	.string "Je n'ai rien à te demander.\n"
	.string "Pour moi, tu en as déjà tellement fait.\p"
	.string "Peut-être que nous nous reverrons…\n"
	.string "Et alors, nous combattrons!\p"
	.string "A présent, je te prie de m'excuser.\p"
	.string "{PLAYER}, je dois y aller!\n"
	.string "Pense à moi!\p"
	.string "Prends bien soin de toi, {PLAYER}!\n"
	.string "Nous sommes amis pour la vie!$"

gText_082C2B50:: @ 82C2B50
	.string "{PLAYER}{KUN}, c'est horrible…\n"
	.string "Mon nez n'arrête pas de couler…\p"
	.string "J'essayais de trouver une belle phrase\n"
	.string "à proclamer en cas de victoire.\p"
	.string "Ça m'a tellement ému que je me suis mis à\n"
	.string "pleurer… Les vannes sont ouvertes!\p"
	.string "Je ne peux pas continuer comme ça.\n"
	.string "Je n'y arriverai pas sans toi, {PLAYER}{KUN}.\p"
	.string "Si je gagne un combat, qu'est-ce que\n"
	.string "tu me conseilles de dire?$"

gText_082C2C77:: @ 82C2C77
	.string "{STR_VAR_1}\p"
	.string "Que c'est beau… J'aime beaucoup!\n"
	.string "J'en ai les larmes aux yeux!\p"
	.string "Même si je pleure, que j'ai le nez qui\n"
	.string "coule, je dirai ça!\p"
	.string "Je n'ai plus rien à te demander,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Désormais, nous sommes rivaux!\n"
	.string "Ma vie a changé, grâce à toi… Merci!$"

gText_082C2D67:: @ 82C2D67
	.string "Euh… Hum…\n"
	.string "{PLAYER}{KUN}…\p"
	.string "Ne me fixe pas comme ça,\n"
	.string "tu me rends nerveux…\p"
	.string "J'ai besoin de toi…\n"
	.string "Pour la dernière fois!\p"
	.string "Ça me gêne de t'en parler…\n"
	.string "Je ne sais pas quoi dire quand je gagne.\l"
	.string "Tu n'aurais pas une idée?$"

gText_082C2E41:: @ 82C2E41
	.string "{STR_VAR_1}\p"
	.string "Oh… D'accord!\n"
	.string "Je dirai ça quand je gagnerai!\l"
	.string "Enfin, si je ne suis pas trop nerveux…\p"
	.string "Merci, {PLAYER}{KUN}.\n"
	.string "Je dois te faire mes adieux.\p"
	.string "Ma vie de DRESSEUR commence.\n"
	.string "Et c'est grâce à toi, {PLAYER}{KUN}.$"

gText_082C2EF5:: @ 82C2EF5
	.string "Tiens… {PLAYER}{KUN},\n"
	.string "n'est-ce pas?\l"
	.string "Serais-tu une POUPEE {PLAYER}?\p"
	.string "Mais, si tu es vraiment {PLAYER}, je te\n"
	.string "présente mes excuses. Je ne voulais\l"
	.string "pas te vexer.\p"
	.string "J'ai de nouveau besoin de tes conseils\n"
	.string "avisés.\p"
	.string "C'est une question assez personnelle.\p"
	.string "Pourrais-tu me suggérer quelque chose\n"
	.string "d'élégant à dire en cas de victoire?$"

gText_082C3023:: @ 82C3023
	.string "{STR_VAR_1}\p"
	.string "… … … … … …\n"
	.string "En cas de victoire…\p"
	.string "{STR_VAR_1}\p"
	.string "Sérieusement?\p"
	.string "Je te remercie, c'est très aimable\n"
	.string "de ta part.\p"
	.string "J'en ferai bon usage.\n"
	.string "C'est promis!\p"
	.string "Il me semble que je n'ai plus rien à te\n"
	.string "demander.\p"
	.string "Je dois voler de mes propres ailes,\n"
	.string "à présent!\p"
	.string "Merci pour tout!\n"
	.string "Je regrette d'avoir douté de toi.$"
