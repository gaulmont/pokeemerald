MossdeepCity_Gym_MapScripts:: @ 8220800
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad: @ 8220806
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2:: @ 8220815
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3:: @ 8220824
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4:: @ 8220833
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles:: @ 822083D
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles:: @ 8220855
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles:: @ 822086D
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles:: @ 8220885
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, 1
	end

MossdeepCity_Gym_EventScript_TateAndLiza:: @ 8220898
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreBattle, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM04, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated:: @ 82208D1
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_2, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2:: @ 8220937
	giveitem_std ITEM_TM04
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind:: @ 822095B
	giveitem_std ITEM_TM04
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch:: @ 822097E
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1:: @ 8220999
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed:: @ 82209C8
	special DrawWholeMapView
	playse SE_TK_KASYA
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1:: @ 82209D0
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2:: @ 82209F5
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2:: @ 8220A24
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Down, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3:: @ 8220A49
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3:: @ 8220A78
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4:: @ 8220A9D
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4:: @ 8220ACC
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance:: @ 8220AF1
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 255, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston:: @ 8220AFD
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonPreBattle, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil:: @ 8220B14
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilPreBattle, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake:: @ 8220B2B
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakePreBattle, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah:: @ 8220B42
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahPreBattle, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha:: @ 8220B59
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaPreBattle, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura:: @ 8220B70
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraPreBattle, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia:: @ 8220B87
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaPreBattle, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate:: @ 8220B9E
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NatePreBattle, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey:: @ 8220BB5
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyPreBattle, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford:: @ 8220BCC
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordPreBattle, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas:: @ 8220BE3
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasPreBattle, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen:: @ 8220BFA
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenPreBattle, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide:: @ 8220C11
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory:: @ 8220C26
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse: @ 8220C30
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue:: @ 8220C33
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue:: @ 8220C43
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified:: @ 8220C53
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue:: @ 8220C5D
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch:: @ 8220C67
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch:: @ 8220C7D
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch:: @ 8220C93
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch:: @ 8220CA9
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch:: @ 8220CBF
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice: @ 8220CD5
	.string "Yo, ça baigne pour toi, futur\n"
	.string "MAITRE {PLAYER}?\p"
	.string "Les CHAMPIONS D'ARENE de cette ville\n"
	.string "utilisent des POKéMON du type PSY.\p"
	.string "Si tu te bats contre eux avec des\n"
	.string "POKéMON du type COMBAT ou POISON,\l"
	.string "ils vont t'infliger de sérieux dommages.\p"
	.string "En plus, ils t'affronteront avec de\n"
	.string "remarquables attaques combinées.\p"
	.string "Si tu veux gagner, il faudra que tu\n"
	.string "démontres combien tu es proche \l"
	.string "de tes POKéMON. En avant!$"

MossdeepCity_Gym_Text_GymGuidePostVictory: @ 8220E2A
	.string "Waouh, renversant!\n"
	.string "Tu es un grand DRESSEUR!$"

MossdeepCity_Gym_Text_PrestonPreBattle: @ 8220E5C
	.string "L'issue du combat dépend du mental\n"
	.string "Les faibles d'esprit ne gagnent jamais!$"

MossdeepCity_Gym_Text_PrestonDefeat: @ 8220EAC
	.string "J'ai perdu!\n"
	.string "Je dois renforcer mon mental!$"

MossdeepCity_Gym_Text_PrestonPostBattle: @ 8220ED3
	.string "Les indécis perdent toujours.\n"
	.string "C'est mon avertissement.$"

MossdeepCity_Gym_Text_VirgilPreBattle: @ 8220F02
	.string "Montre-moi ton talent!$"

MossdeepCity_Gym_Text_VirgilDefeat: @ 8220F1A
	.string "Tu as un talent spectaculaire!$"

MossdeepCity_Gym_Text_VirgilPostBattle: @ 8220F3A
	.string "S'il existe au monde des prodiges,\n"
	.string "ce sont bien nos CHAMPIONS!\p"
	.string "Mais tu as peut-être encore plus\n"
	.string "de talent qu'eux…$"

MossdeepCity_Gym_Text_BlakePreBattle: @ 8220FB0
	.string "Hé, hé… Regarde-moi soulever une\n"
	.string "POKé BALL par télékinésie!\p"
	.string "Arrrrrrrrrrrrg!\n"
	.string "… … … … … … …\p"
	.string "Je suis parfois désynchronisé…$"

MossdeepCity_Gym_Text_BlakeDefeat: @ 8221024
	.string "Les aptitudes au combat de mon POKéMON\n"
	.string "sont parfois désynchronisées aussi!$"

MossdeepCity_Gym_Text_BlakePostBattle: @ 8221055
	.string "La POKé BALL, c'était trop lourd à\n"
	.string "soulever mentalement. Mais ce flocon\l"
	.string "de poussière…\p"
	.string "Waaaaaaaaaaaaaaaaaaouh!\n"
	.string "… … … … … …\p"
	.string "Non, je ne triche pas!\n"
	.string "Je n'ai pas soufflé dessus! Vraiment!$"

MossdeepCity_Gym_Text_HannahPreBattle: @ 82210EE
	.string "Si tu perds contre moi, ne sois pas\n"
	.string "trop sévère avec toi-même.\p"
	.string "Ce n'est pas que tu sois faible, c'est\n"
	.string "que je suis trop forte pour toi!$"

MossdeepCity_Gym_Text_HannahDefeat: @ 8221152
	.string "T'as tout simplement un meilleur niveau!$"

MossdeepCity_Gym_Text_HannahPostBattle: @ 822116A
	.string "Je ne vais pas m'apitoyer parce que j'ai\n"
	.string "perdu. Je vais m'entraîner davantage.\p"
	.string "L'optimisme, c'est mon point fort!$"

MossdeepCity_Gym_Text_SamanthaPreBattle: @ 82211E2
	.string "Je vois ton avenir…\n"
	.string "Je vois ton avenir…\p"
	.string "Si tu réussis à me battre, je te prédis\n"
	.string "ton avenir!$"

MossdeepCity_Gym_Text_SamanthaDefeat: @ 8221230
	.string "Je me rends!$"

MossdeepCity_Gym_Text_SamanthaPostBattle: @ 822123D
	.string "Tu vas livrer un combat d'une grande\n"
	.string "intensité avec nos CHAMPIONS…\p"
	.string "Résultat…\n"
	.string "Tu ne l'entendras pas de ma bouche!$"

MossdeepCity_Gym_Text_MauraPreBattle: @ 82212A6
	.string "Le chemin que tu as parcouru…\n"
	.string "Tout ce que tu as vécu…\p"
	.string "Fais-moi voir ce que tu as appris!$"

MossdeepCity_Gym_Text_MauraDefeat: @ 8221309
	.string "Tu t'es frayé une voie dans la grandeur!$"

MossdeepCity_Gym_Text_MauraPostBattle: @ 822132E
	.string "Tu t'es frayé une voie dans la grandeur\n"
	.string "travaillé assidûment.\p"
	.string "Ceux qui paressent ne connaîtront\n"
	.string "finalement que le désespoir.\p"
	.string "Tout finit toujours par se payer…$"

MossdeepCity_Gym_Text_SylviaPreBattle: @ 82213C2
	.string "Je gagnerai ce combat, même au\n"
	.string "péril de ma vie!$"

MossdeepCity_Gym_Text_SylviaDefeat: @ 82213F4
	.string "Qu'est-ce que tu as fait?\n"
	.string "Je suis horrifiée…$"

MossdeepCity_Gym_Text_SylviaPostBattle: @ 8221412
	.string "Comment as-tu osé me battre?\p"
	.string "Ne viens pas te plaindre si quelque\n"
	.string "chose t'arrive bientôt!$"

MossdeepCity_Gym_Text_NatePreBattle: @ 8221460
	.string "Hohoho.\p"
	.string "Je vais te montrer comme le type PSY\n"
	.string "peut être dur à vaincre.$"

MossdeepCity_Gym_Text_NateDefeat: @ 82214A7
	.string "Je suis abasourdi!\n"
	.string "Ton style est fantastique!$"

MossdeepCity_Gym_Text_NatePostBattle: @ 82214D3
	.string "Je… Je ne me… laisse pas…\n"
	.string "abattre… par la… défaite!$"

MossdeepCity_Gym_Text_KathleenPreBattle: @ 8221507
	.string "Laisse-moi te montrer la noirceur\n"
	.string "de ton âme!$"

MossdeepCity_Gym_Text_KathleenDefeat: @ 822153B
	.string "N… Noooon!$"

MossdeepCity_Gym_Text_KathleenPostBattle: @ 8221545
	.string "Ta vitalité est contagieuse!\n"
	.string "Eloigne-toi vite de moi!$"

MossdeepCity_Gym_Text_CliffordPreBattle: @ 822157C
	.string "Je ne suis peut-être plus tout jeune,\n"
	.string "mais je te suggère de ne pas me\l"
	.string "sous-estimer.$"

MossdeepCity_Gym_Text_CliffordDefeat: @ 82215B8
	.string "La force de la jeunesse émane de toi!$"

MossdeepCity_Gym_Text_CliffordPostBattle: @ 82215E2
	.string "Je n'ai pas réussi à contrer la fougue\n"
	.string "de la jeunesse.$"

MossdeepCity_Gym_Text_MaceyPreBattle: @ 822161B
	.string "Tu n'arriveras pas au bout!\n"
	.string "Je t'en empêcherai!$"

MossdeepCity_Gym_Text_MaceyDefeat: @ 8221658
	.string "Comment un si petit corps peut-il\n"
	.string "cacher tant de force?$"

MossdeepCity_Gym_Text_MaceyPostBattle: @ 8221680
	.string "J'ai perdu mais c'est mieux ainsi!\p"
	.string "Ta façon brutale de combattre ne\n"
	.string "convient pas aux POKéMON PSY!$"

MossdeepCity_Gym_Text_NicholasPreBattle: @ 82216EE
	.string "Yahaaa! Goûte un peu à la puissance\n"
	.string "de mon POKéMON!$"

MossdeepCity_Gym_Text_NicholasDefeat: @ 822172D
	.string "Oh!\n"
	.string "Déjà!$"

MossdeepCity_Gym_Text_NicholasPostBattle: @ 822173A
	.string "Très bien, je n'ai plus qu'à développer\n"
	.string "un nouveau type de POKéMON invincible!$"

MossdeepCity_Gym_Text_TateAndLizaPreBattle: @ 8221783
	.string "LEVY: Hé, hé… Ça te surprend?\p"
	.string "TATIA: Ah, ah… Ça te surprend?\p"
	.string "LEVY: Qu'il y ait deux CHAMPIONS?\n"
	.string "TATIA: Qu'il y ait deux CHAMPIONS?\p"
	.string "LEVY: On est jumeaux!\n"
	.string "TATIA: On est jumeaux!\p"
	.string "LEVY: On n'a pas besoin de se parler…\n"
	.string "TATIA: On sait ce que…\p"
	.string "LEVY: l'autre pense…\n"
	.string "TATIA: Tout est dans nos esprits!\p"
	.string "LEVY: Cette osmose parfaite…\n"
	.string "TATIA: Pourras-tu la battre?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat: @ 82218EC
	.string "LEVY: Quoi? Notre osmose…\n"
	.string "TATIA: a été brisée!\p"
	.string "LEVY: Tant pis! Tu as gagné…\n"
	.string "TATIA: Prends ça en récompense.$"

MossdeepCity_Gym_Text_ReceivedMindBadge: @ 822196A
	.string "{PLAYER} reçoit le BADGE ESPRIT de\n"
	.string "la part de LEVY et TATIA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis: @ 8221999
	.string "LEVY: Le BADGE ESPRIT augmente\n"
	.string "l'ATQ. SPE. et la DEF. SPE. des POKéMON.\p"
	.string "TATIA: Il permet aussi d'utiliser la CS\n"
	.string "PLONGEE hors combat.\p"
	.string "LEVY: Tu devrais prendre ça, aussi.$"

MossdeepCity_Gym_Text_ExplainCalmMind: @ 8221A40
	.string "LEVY: Cette CT04 contient…\n"
	.string "TATIA: PLENITUDE!\p"
	.string "LEVY: Elle accroît l'ATQ. SPE. et…\n"
	.string "TATIA: elle accroît la DEF. SPE.!\p"
	.string "LEVY: C'est l'attaque parfaite…\n"
	.string "TATIA: pour les POKéMON du type PSY!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza: @ 8221AEA
	.string "CHAMPIONS D'ARENE LEVY & TATIA\n"
	.string "enregistrés dans le POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle: @ 8221B1D
	.string "LEVY: Le lien qui te lie à tes POKéMON\n"
	.string "semble bien plus fort que celui qui nous\l"
	.string "lie en tant que jumeaux.\p"
	.string "TATIA: Tu vas encore t'améliorer! On\n"
	.string "s'est battus contre toi. On sait de quoi\l"
	.string "on parle.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons: @ 8221BCE
	.string "LEVY: Hé, hé… Ça te surprend?\p"
	.string "TATIA: qu'il y ait deux CHAMPIONS?\p"
	.string "LEVY: Oups, tu n'as qu'un seul…\n"
	.string "TATIA: POKéMON pouvant combattre.\p"
	.string "LEVY: On ne peut pas s'affronter!\p"
	.string "TATIA: Si tu veux te mesurer à nous,\n"
	.string "reviens avec plus de POKéMON.$"

MossdeepCity_Gym_Text_GymStatue: @ 8221CB0
	.string "ARENE POKéMON d'ALGATIA$"

MossdeepCity_Gym_Text_GymStatueCertified: @ 8221CCA
	.string "MARENE POKéMON d'ALGATIA\p"
	.string "NOUVEAU DRESSEUR RECONNU\n"
	.string "PAR TATIA ET LEVY: {PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch: @ 8221D0B
	.string "LEVY: POKéMON…\n"
	.string "TATIA: POKéMON…\p"
	.string "LEVY: En changeant l'ordre de l'équipe…\n"
	.string "TATIA: le style du combat change.\p"
	.string "LEVY: But me…\n"
	.string "TATIA: But me…\p"
	.string "LEVY: Je serai toujours avec TATIA!\n"
	.string "TATIA: Je serai toujours avec LEVY!\p"
	.string "LEVY: Tu verras encore et encore…\n"
	.string "TATIA: notre combinaison!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat: @ 8221E05
	.string "LEVY: Tes POKéMON et toi…\n"
	.string "TATIA: vous êtes comme une seule\l"
	.string "personne!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch: @ 8221E45
	.string "LEVY: Tu peux nous battre mais\n"
	.string "nous nous relèverons toujours!\p"
	.string "TATIA: Parce que nous nous soutenons\n"
	.string "l'un l'autre!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons: @ 8221EB8
	.string "LEVY: Tu es de retour…\n"
	.string "TATIA: Tu es de retour…\p"
	.string "LEVY: pour une revanche.\n"
	.string "TATIA: pour une revanche.\p"
	.string "LEVY: Mais…\n"
	.string "TATIA: pour notre match…\p"
	.string "LEVY: tu n'as qu'un POKéMON!\n"
	.string "TATIA: tu n'as qu'un POKéMON!\p"
	.string "LEVY: La prochaine fois…\n"
	.string "TATIA: ramène au moins 2 POKéMON!$"