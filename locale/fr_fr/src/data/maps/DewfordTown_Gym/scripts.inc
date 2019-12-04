DewfordTown_Gym_MapScripts:: @ 81FC63C
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition: @ 81FC642
	call DewfordTown_Gym_EventScript_SetFlashRadius
	end

DewfordTown_Gym_EventScript_SetFlashRadius:: @ 81FC648
	checktrainerflag TRAINER_BRAWLY_1
	goto_if_eq DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	compare VAR_0x8000, 0
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius7
	compare VAR_0x8000, 1
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius6
	compare VAR_0x8000, 2
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius5
	compare VAR_0x8000, 3
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius4
	compare VAR_0x8000, 4
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius3
	compare VAR_0x8000, 5
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius2
	goto DewfordTown_Gym_EventScript_SetFlashRadius1

DewfordTown_Gym_EventScript_SetLightsOn:: @ 81FC6A2
	setflashradius 0
	return

DewfordTown_Gym_EventScript_SetFlashRadius1:: @ 81FC6A6
	setflashradius 1
	return

DewfordTown_Gym_EventScript_SetFlashRadius2:: @ 81FC6AA
	setflashradius 2
	return

DewfordTown_Gym_EventScript_SetFlashRadius3:: @ 81FC6AE
	setflashradius 3
	return

DewfordTown_Gym_EventScript_SetFlashRadius4:: @ 81FC6B2
	setflashradius 4
	return

DewfordTown_Gym_EventScript_SetFlashRadius5:: @ 81FC6B6
	setflashradius 5
	return

DewfordTown_Gym_EventScript_SetFlashRadius6:: @ 81FC6BA
	setflashradius 6
	return

DewfordTown_Gym_EventScript_SetFlashRadius7:: @ 81FC6BE
	setflashradius 7
	return

DewfordTown_Gym_EventScript_BrightenRoom:: @ 81FC6C2
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	compare VAR_0x8000, VAR_0x8001
	goto_if_eq DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	compare VAR_0x8000, 1
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	compare VAR_0x8000, 2
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	compare VAR_0x8000, 3
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	compare VAR_0x8000, 4
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	compare VAR_0x8000, 5
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	compare VAR_0x8000, 6
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange:: @ 81FC71A
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer:: @ 81FC71B
	playse SE_MU_PACHI
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers:: @ 81FC726
	playse SE_MU_PACHI
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers:: @ 81FC731
	playse SE_MU_PACHI
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers:: @ 81FC73C
	playse SE_MU_PACHI
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers:: @ 81FC747
	playse SE_MU_PACHI
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers:: @ 81FC752
	playse SE_MU_PACHI
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness:: @ 81FC75D
	playse SE_MU_PACHI
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated:: @ 81FC768
	setvar VAR_0x8000, 0
	checktrainerflag TRAINER_TAKAO
	goto_if_lt DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn:: @ 81FC77B
	checktrainerflag TRAINER_JOCELYN
	goto_if_lt DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura:: @ 81FC789
	checktrainerflag TRAINER_LAURA
	goto_if_lt DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden:: @ 81FC797
	checktrainerflag TRAINER_BRENDEN
	goto_if_lt DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian:: @ 81FC7A5
	checktrainerflag TRAINER_CRISTIAN
	goto_if_lt DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith:: @ 81FC7B3
	checktrainerflag TRAINER_LILITH
	goto_if_lt DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers:: @ 81FC7C1
	return

DewfordTown_Gym_EventScript_Brawly:: @ 81FC7C2
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreBattle, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM08, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated:: @ 81FC7F7
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp:: @ 81FC855
	giveitem_std ITEM_TM08
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	return

DewfordTown_Gym_EventScript_GiveBulkUp2: @ 81FC878
	giveitem_std ITEM_TM08
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch:: @ 81FC89C
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao:: @ 81FC8B7
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoPreBattle, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom:: @ 81FC8D2
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn:: @ 81FC8D9
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynPreBattle, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom:: @ 81FC8F4
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura:: @ 81FC8FB
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraPreBattle, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom:: @ 81FC916
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden:: @ 81FC91D
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenPreBattle, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom:: @ 81FC938
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian:: @ 81FC93F
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianPreBattle, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom:: @ 81FC95A
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith:: @ 81FC961
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithPreBattle, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom:: @ 81FC97C
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide:: @ 81FC983
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory:: @ 81FC998
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue:: @ 81FC9A2
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue:: @ 81FC9B2
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified:: @ 81FC9C2
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue:: @ 81FC9CC
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice: @ 81FC9D6
	.string "Hé, comment ça va, futur MAITRE\n"
	.string "{PLAYER}?\p"
	.string "BASTIEN, le CHAMPION D'ARENE\n"
	.string "de MYOKARA a des POKéMON de\l"
	.string "type COMBAT.\p"
	.string "Si tu comptes te battre contre lui avec\n"
	.string "des POKéMON de type NORMAL, tu\l"
	.string "risques la déception.\p"
	.string "Les POKéMON COMBAT infligent de\n"
	.string "sérieux dégâts aux POKéMON de type\l"
	.string "NORMAL. Sois prudent!\p"
	.string "En plus, l'ARENE est plongée dans\n"
	.string "l'obscurité la plus totale.\p"
	.string "Mais elle s'illuminera quand tu auras\n"
	.string "vaincu les DRESSEURS sur ton chemin.\p"
	.string "Bon, allez, c'est parti!$"

DewfordTown_Gym_Text_GymGuidePostVictory: @ 81FCB5C
	.string "Ouah! Il y a trop de lumière, ici!\p"
	.string "Toi aussi, tu as l'air d'être une lumière!$"

DewfordTown_Gym_Text_TakaoPreBattle: @ 81FCB9F
	.string "La puissance est ma raison d'être!\n"
	.string "Allez, bats-toi!$"

DewfordTown_Gym_Text_TakaoDefeat: @ 81FCBB8
	.string "Pas assez de puissance…$"

DewfordTown_Gym_Text_TakaoPostBattle: @ 81FCBCA
	.string "Ta compétence a surpassé ma force!\n"
	.string "Ta technique est impressionnante!$"

DewfordTown_Gym_Text_JocelynPreBattle: @ 81FCC0A
	.string "Inutile de déranger BASTIEN!\p"
	.string "Je vais t'écraser moi-même!$"

DewfordTown_Gym_Text_JocelynDefeat: @ 81FCC45
	.string "Mais… Comment?\n"
	.string "Comment as-tu pu gagner si facilement?$"

DewfordTown_Gym_Text_JocelynPostBattle: @ 81FCC6B
	.string "Je ne vais pas rester sur une défaite.\n"
	.string "Je vais me motiver pour l'entraînement!\p"
	.string "Un jour, je deviendrai CHAMPION\n"
	.string "D'ARENE…\p"
	.string "Non, je deviendrai MAITRE de la\n"
	.string "LIGUE POKéMON!$"

DewfordTown_Gym_Text_LauraPreBattle: @ 81FCD01
	.string "Comment oses-tu me provoquer?\n"
	.string "Bon, tu ne viendras pas pleurer!$"

DewfordTown_Gym_Text_LauraDefeat: @ 81FCD3C
	.string "Ouiiiiiiiiiin!\n"
	.string "J'ai perdu!$"

DewfordTown_Gym_Text_LauraPostBattle: @ 81FCD4F
	.string "J'ai l'habitude de me battre dans le noir\n"
	.string "pour endurcir mon cœur.\p"
	.string "Mais il fait toujours si noir que je n'ai\n"
	.string "jamais vu le visage de BASTIEN…$"

DewfordTown_Gym_Text_LilithPreBattle: @ 81FCDB8
	.string "Ouh…\n"
	.string "Fais attention, tu vas tomber!$"

DewfordTown_Gym_Text_LilithDefeat: @ 81FCDE5
	.string "Oh, toi…\n"
	.string "Je n'ai pas envie de te connaître!$"

DewfordTown_Gym_Text_LilithPostBattle: @ 81FCE08
	.string "Je te souhaite de te perdre et de\n"
	.string "te retrouver à l'entrée!$"

DewfordTown_Gym_Text_BrendenPreBattle: @ 81FCE48
	.string "Tu vas voir! On ne la fait pas à un vieux\n"
	.string "loup de mer comme moi!$"

DewfordTown_Gym_Text_BrendenDefeat: @ 81FCE75
	.string "Je t'assure, ce n'est pas mon genre\n"
	.string "de perdre comme ça!$"

DewfordTown_Gym_Text_BrendenPostBattle: @ 81FCEAB
	.string "Je crois que tu as bien mérité de\n"
	.string "voir notre CHAMPION D'ARENE.$"

DewfordTown_Gym_Text_CristianPreBattle: @ 81FCEDC
	.string "Si tu veux aller plus loin, tu devras\n"
	.string "d'abord me passer sur le corps!$"

DewfordTown_Gym_Text_CristianDefeat: @ 81FCF0A
	.string "Grrrrr!\n"
	.string "Sans commentaire…$"

DewfordTown_Gym_Text_CristianPostBattle: @ 81FCF26
	.string "Tu as gagné!\n"
	.string "Va chercher ce BADGE!$"

DewfordTown_Gym_Text_BrawlyPreBattle: @ 81FCF44
	.string "Je suis BASTIEN!\n"
	.string "Le CHAMPION D'ARENE de MYOKARA!\p"
	.string "J'ai résisté aux vagues déchaînées\n"
	.string "de la région et je me suis endurci dans\l"
	.string "les cavernes obscures!\p"
	.string "Alors, comme ça, tu viens me défier?\n"
	.string "Voyons donc de quoi tu es capable!$"

DewfordTown_Gym_Text_BrawlyDefeat: @ 81FD008
	.string "Pfffou, bon sang! Tu as fait plus de\n"
	.string "vagues que je ne l'aurais imaginé!\p"
	.string "Tu m'as submergé!\p"
	.string "Je l'admets, tu m'as vaincu.\n"
	.string "Prends ce BADGE!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge: @ 81FD07D
	.string "{PLAYER} reçoit le BADGE POING\n"
	.string "de la part de BASTIEN.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis: @ 81FD0A8
	.string "Le BADGE POING oblige tous les POKéMON\n"
	.string "jusqu'au niveau 30, même ceux échangés,\l"
	.string "à obéir sans poser de question.\p"
	.string "Et tu pourras aussi utiliser la CS FLASH\n"
	.string "en dehors des combats.\p"
	.string "Si tu veux, tu peux aussi utiliser cette\n"
	.string "CAPSULE TECHNIQUE.$"

DewfordTown_Gym_Text_ExplainBulkUp: @ 81FD181
	.string "Cette CT08 contient GONFLETTE.\p"
	.string "C'est une technique qui permet de\n"
	.string "booster l'ATTAQUE et la DEFENSE.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly: @ 81FD1E0
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D'ARENE BASTIEN dans le POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle: @ 81FD20D
	.string "Je vois que tes talents ont causé un\n"
	.string "raz-de-marée d'admiration parmi les\l"
	.string "DRESSEURS, l'autre jour!$"

DewfordTown_Gym_Text_GymStatue: @ 81FD272
	.string "ARENE POKéMON du VILLAGE MYOKARA$"

DewfordTown_Gym_Text_GymStatueCertified: @ 81FD28B
	.string "POKéMON du VILLAGE MYOKARA\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR BASTIEN:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch: @ 81FD2C4
	.string "BASTIEN: La vague se retire, mais elle\n"
	.string "revient toujours sur le rivage.\p"
	.string "Toi… Une telle vague de talent…\n"
	.string "Je savais que tu reviendrais!\p"
	.string "Montre-moi tes progrès!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat: @ 81FD367
	.string "Waouh!\n"
	.string "Je me suis de nouveau fait submerger!$"

DewfordTown_Gym_Text_BrawlyPostRematch: @ 81FD37B
	.string "BASTIEN: Les combats sont vastes et\n"
	.string "profonds. On n'en voit pas le fond!\l"
	.string "Exactement comme la mer de HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons: @ 81FD3DE
	.string "BASTIEN: La vague se replie, mais elle\n"
	.string "revient toujours sur le rivage.\p"
	.string "Une telle vague de talent comme toi…\n"
	.string "Je savais que tu reviendrais!\p"
	.string "Oh? Tu n'as qu'un POKéMON apte\n"
	.string "au combat?\p"
	.string "Je suis désolé, mais je préfère que tu\n"
	.string "reviennes avec au moins deux POKéMON.$"