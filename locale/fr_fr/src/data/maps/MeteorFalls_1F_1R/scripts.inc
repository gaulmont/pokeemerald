MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_MapScript1_22BD30
	.byte 0

MeteorFalls_1F_1R_MapScript1_22BD30: @ 822BD30
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_22BD3A
	end

MeteorFalls_1F_1R_EventScript_22BD3A:: @ 822BD3A
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, 1
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, 1
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, 0
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, 1
	return

MeteorFalls_1F_1R_EventScript_22BD5F:: @ 822BD5F
	lockall
	playbgm MUS_MGM0, 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement 5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22BF47, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	applymovement 6, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22BF84, MSGBOX_DEFAULT
	closemessage
	applymovement 5, MeteorFalls_1F_1R_Movement_22BEC0
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22BFE4, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	addobject 7
	addobject 8
	addobject 9
	playbgm MUS_AQA_0, 0
	applymovement 7, MeteorFalls_1F_1R_Movement_22BED9
	applymovement 8, MeteorFalls_1F_1R_Movement_22BEE0
	applymovement 9, MeteorFalls_1F_1R_Movement_22BEE8
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C04E, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, MeteorFalls_1F_1R_Movement_22BF1D
	applymovement 5, MeteorFalls_1F_1R_Movement_22BEC4
	applymovement 6, MeteorFalls_1F_1R_Movement_22BECE
	waitmovement 0
	removeobject 5
	removeobject 6
	applymovement 7, MeteorFalls_1F_1R_Movement_22BEF8
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C11C, MSGBOX_DEFAULT
	closemessage
	applymovement 8, MeteorFalls_1F_1R_Movement_22BF08
	applymovement 9, MeteorFalls_1F_1R_Movement_22BF18
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C268, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C292, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C2FC, MSGBOX_DEFAULT
	closemessage
	applymovement 7, MeteorFalls_1F_1R_Movement_22BEF0
	applymovement 8, MeteorFalls_1F_1R_Movement_22BEFE
	applymovement 9, MeteorFalls_1F_1R_Movement_22BF0D
	waitmovement 0
	fadedefaultbgm
	removeobject 7
	removeobject 8
	removeobject 9
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLORBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_22BEC0: @ 822BEC0
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_22BEC4: @ 822BEC4
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_22BECE: @ 822BECE
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_22BED9: @ 822BED9
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BEE0: @ 822BEE0
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BEE8: @ 822BEE8
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BEF0: @ 822BEF0
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BEF8: @ 822BEF8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

MeteorFalls_1F_1R_Movement_22BEFE: @ 822BEFE
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BF08: @ 822BF08
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_22BF0D: @ 822BF0D
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BF18: @ 822BF18
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_22BF1D: @ 822BF1D
	walk_in_place_fastest_down
	delay_4
	walk_in_place_fastest_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_22BF25:: @ 822BF25
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COSMO, MeteorFalls_1F_1R_EventScript_22BF3D
	setflag FLAG_MET_PROF_COSMO
	msgbox MeteorFalls_1F_1R_Text_22C342, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_22BF3D:: @ 822BF3D
	msgbox MeteorFalls_1F_1R_Text_22C47D, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_22BF47: @ 822BF47
	.string "Hé, hé, hé!\p"
	.string "Avec ce METEORITE, ce truc\n"
	.string "au MONT CHIMNEE va…$"

MeteorFalls_1F_1R_Text_22BF84: @ 822BF84
	.string "Hé?\p"
	.string "Je ne sais pas qui tu es, mais si tu\n"
	.string "croises la route de la TEAM MAGMA,\l"
	.string "ne t'attends à aucune pitié!$"

MeteorFalls_1F_1R_Text_22BFE4: @ 822BFE4
	.string "Laissez ça, TEAM MAGMA!\p"
	.string "Vous faites une grossière erreur si\n"
	.string "vous pensez pouvoir diriger le monde\l"
	.string "à votre manière!$"

MeteorFalls_1F_1R_Text_22C04E: @ 822C04E
	.string "Hé, hé, hé!\n"
	.string "Même la TEAM AQUA nous a rejoints!\p"
	.string "Ça ferait trop si on devait vous\n"
	.string "affronter un par un…\p"
	.string "Hé, c'est pas grave!\p"
	.string "On a le METEORITE, alors on va au\n"
	.string "MONT CHIMNEE!\p"
	.string "Hé, hé, hé! A plus, les crétins de\n"
	.string "la TEAM AQUA!$"

MeteorFalls_1F_1R_Text_22C11C: @ 822C11C
	.string "ARTHUR: Ne nous sommes-nous pas déjà\n"
	.string "rencontrés au MUSEE de POIVRESSEL?\p"
	.string "Ah, donc tu t'appelles {PLAYER}.\p"
	.string "Cette fois-là, j'avais pensé que tu\n"
	.string "appartenais à la TEAM MAGMA.\p"
	.string "Humph…\n"
	.string "Tu es vraiment une personne étrange.\p"
	.string "La TEAM MAGMA est un groupe de\n"
	.string "dangereux fanatiques.\p"
	.string "Ils commettent des actes destructeurs\n"
	.string "pour essayer d'étendre la terre.\p"
	.string "Ce sont nos rivaux, à nous les\n"
	.string "amoureux de la mer!$"

MeteorFalls_1F_1R_Text_22C268: @ 822C268
	.string "CHEF, on devrait poursuivre la \n"
	.string "TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_22C292: @ 822C292
	.string "ARTHUR: Oui, oui, il le faut!\n"
	.string "On a intérêt de se dépêcher!\p"
	.string "Pas besoin de se demander ce que la\n"
	.string "TEAM MAGMA va faire au MONT CHIMNEE!$"

MeteorFalls_1F_1R_Text_22C2FC: @ 822C2FC
	.string "ARTHUR: {PLAYER}, tu devrais aussi\n"
	.string "garder un œil sur la TEAM MAGMA.\p"
	.string "Adieu!$"

MeteorFalls_1F_1R_Text_22C342: @ 822C342
	.string "Je… Je suis KOSMO…\n"
	.string "Je suis un PROFESSEUR…\p"
	.string "Des membres de la TEAM MAGMA m'ont\n"
	.string "demandé la route pour aller au\l"
	.string "SITE METEORE.\p"
	.string "Mais ils m'ont piégé! Ils m'ont\n"
	.string "même volé mon METEORITE…\p"
	.string "Et un autre groupe est apparu, c'était\n"
	.string "la TEAM AQUA!\p"
	.string "Après ça…\n"
	.string "Je n'ai plus rien compris.\p"
	.string "Mais cette TEAM MAGMA…\p"
	.string "Que vont-ils faire avec ce METEORITE\n"
	.string "au MONT CHIMNEE?$"

MeteorFalls_1F_1R_Text_22C47D: @ 822C47D
	.string "PROF. KOSMO: Cette TEAM MAGMA…\p"
	.string "Que vont-ils faire avec ce METEORITE\n"
	.string "au MONT CHIMNEE?$"
