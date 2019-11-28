Route114_FossilManiacsTunnel_MapScripts:: @ 822AF28
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_MapScript1_22AF49
	.byte 0

Route114_FossilManiacsTunnel_OnTransition: @ 822AF33
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_22AF3D
	end

Route114_FossilManiacsTunnel_EventScript_22AF3D:: @ 822AF3D
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_MapScript1_22AF49: @ 822AF49
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_22AF53
	end

Route114_FossilManiacsTunnel_EventScript_22AF53:: @ 822AF53
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, 1
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, 1
	return

Route114_FossilManiacsTunnel_EventScript_22AF66:: @ 822AF66
	lockall
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_22B1F7, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_22AF87:: @ 822AF87
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_22AFC6
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_eq Route114_FossilManiacsTunnel_EventScript_22AFBC
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_eq Route114_FossilManiacsTunnel_EventScript_22AFBC
	msgbox Route114_FossilManiacsTunnel_Text_22AFD0, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_22AFBC:: @ 822AFBC
	msgbox Route114_FossilManiacsTunnel_Text_22B0D6, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_22AFC6:: @ 822AFC6
	msgbox Route114_FossilManiacsTunnel_Text_22B1CC, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_22AFD0: @ 822AFD0
	.string "Je suis le MANIAQUE DES FOSSILES…\n"
	.string "Je suis un bon garçon, passionné de\l"
	.string "FOSSILES…\p"
	.string "Tu veux un FOSSILE?\p"
	.string "Pas de chance, tous les FOSSILES du\n"
	.string "coin m'appartiennent. Tu n'en auras pas.\p"
	.string "Si tu veux absolument un FOSSILE, va\n"
	.string "dans le désert. Tu risques d'en trouver\l"
	.string "dans les rochers ou dans le sable…$"

Route114_FossilManiacsTunnel_Text_22B0D6: @ 822B0D6
	.string "Tu as trouvé un FOSSILE, n'est-ce pas?\n"
	.string "C'est génial… Ça laisse rêveur…\p"
	.string "Qu'est-ce que tu vas faire avec ce\n"
	.string "FOSSILE?\p"
	.string "J'ai entendu dire que DEVON faisait\n"
	.string "des recherches pour ranimer des\l"
	.string "POKéMON à partir de FOSSILES…\p"
	.string "J'aime tellement mes FOSSILES que je\n"
	.string "ne ferai jamais ça…$"

Route114_FossilManiacsTunnel_Text_22B1CC: @ 822B1CC
	.string "Les FOSSILES sont si… merveilleux…\n"
	.string "Ça laisse rêveur…$"

Route114_FossilManiacsTunnel_Text_22B1F7: @ 822B1F7
	.string "Oh…\n"
	.string "C'est dangereux par là…\p"
	.string "J'étais en train de creuser…\n"
	.string "Le mur entier s'est effondré…\p"
	.string "Il doit y avoir une grotte immense\n"
	.string "là-dessous…\p"
	.string "Mais ça ne m'intéresse pas, il n'y a\n"
	.string "sûrement pas de FOSSILES…$"

