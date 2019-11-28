MossdeepCity_SpaceCenter_1F_MapScripts:: @ 8222F41
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_MapScript1_222FC2
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition: @ 8222F4C
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_222F58
	end

MossdeepCity_SpaceCenter_1F_EventScript_222F58:: @ 8222F58
	setobjectxyperm 3, 1, 9
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 5, 0, 8
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 4, 1, 6
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 1, 3, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 1
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_222FAA
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_222FB2
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 3
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_222FBA
	end

MossdeepCity_SpaceCenter_1F_EventScript_222FAA:: @ 8222FAA
	setobjectxyperm 9, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_222FB2:: @ 8222FB2
	setobjectxyperm 9, 13, 3
	end

MossdeepCity_SpaceCenter_1F_EventScript_222FBA:: @ 8222FBA
	setobjectxyperm 9, 14, 2
	end

MossdeepCity_SpaceCenter_1F_MapScript1_222FC2: @ 8222FC2
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_le MossdeepCity_SpaceCenter_1F_EventScript_222FCE
	end

MossdeepCity_SpaceCenter_1F_EventScript_222FCE:: @ 8222FCE
	setmetatile 2, 5, METATILE_Facility_DataPad, 1
	return

MossdeepCity_SpaceCenter_1F_EventScript_222FD8:: @ 8222FD8
	lock
	faceplayer
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_223024
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring 0, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_223012
	compare VAR_RESULT, 1
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_22301B
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223012:: @ 8223012
	msgbox MossdeepCity_SpaceCenter_1F_Text_2232A7, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_22301B:: @ 822301B
	msgbox MossdeepCity_SpaceCenter_1F_Text_2232C8, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_223024:: @ 8223024
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring 0, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_223051
	compare VAR_RESULT, 1
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_22305A
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223051:: @ 8223051
	msgbox MossdeepCity_SpaceCenter_1F_Text_223305, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_22305A:: @ 822305A
	msgbox MossdeepCity_SpaceCenter_1F_Text_22335E, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_223063:: @ 8223063
	lock
	faceplayer
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_22307A
	msgbox MossdeepCity_SpaceCenter_1F_Text_2233D3, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22307A:: @ 822307A
	msgbox MossdeepCity_SpaceCenter_1F_Text_2234B7, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22308E:: @ 822308E
	lock
	faceplayer
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_2230DA
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_2230D0
	msgbox MossdeepCity_SpaceCenter_1F_Text_223540, MSGBOX_DEFAULT
	giveitem_std ITEM_SUN_STONE
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_2235A6, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2230D0:: @ 82230D0
	msgbox MossdeepCity_SpaceCenter_1F_Text_2235A6, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2230DA:: @ 82230DA
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_223119
	msgbox MossdeepCity_SpaceCenter_1F_Text_2235F0, MSGBOX_DEFAULT
	giveitem_std ITEM_SUN_STONE
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_223664, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223119:: @ 8223119
	msgbox MossdeepCity_SpaceCenter_1F_Text_223664, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22312D:: @ 822312D
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_223154
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_22315E
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_1F_EventScript_223154
	goto MossdeepCity_SpaceCenter_1F_EventScript_22315E
	end

MossdeepCity_SpaceCenter_1F_EventScript_223154:: @ 8223154
	msgbox MossdeepCity_SpaceCenter_1F_Text_2236A6, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22315E:: @ 822315E
	msgbox MossdeepCity_SpaceCenter_1F_Text_2236E8, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223168:: @ 8223168
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_22318F
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_2231A4
	compare VAR_MOSSDEEP_CITY_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_1F_EventScript_22318F
	goto MossdeepCity_SpaceCenter_1F_EventScript_2231A4
	end

MossdeepCity_SpaceCenter_1F_EventScript_22318F:: @ 822318F
	msgbox MossdeepCity_SpaceCenter_1F_Text_22375B, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231A4:: @ 82231A4
	msgbox MossdeepCity_SpaceCenter_1F_Text_2237B5, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231B9:: @ 82231B9
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_223849, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231CF:: @ 82231CF
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_223C2C, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231DA:: @ 82231DA
	trainerbattle_single TRAINER_GRUNT_32, MossdeepCity_SpaceCenter_1F_Text_22396C, MossdeepCity_SpaceCenter_1F_Text_223999
	msgbox MossdeepCity_SpaceCenter_1F_Text_2239AA, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_2231F1:: @ 82231F1
	trainerbattle_single TRAINER_GRUNT_16, MossdeepCity_SpaceCenter_1F_Text_2239E6, MossdeepCity_SpaceCenter_1F_Text_223A21
	msgbox MossdeepCity_SpaceCenter_1F_Text_223A4B, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_223208:: @ 8223208
	trainerbattle_single TRAINER_GRUNT_33, MossdeepCity_SpaceCenter_1F_Text_223A8A, MossdeepCity_SpaceCenter_1F_Text_223AFA
	msgbox MossdeepCity_SpaceCenter_1F_Text_223B37, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_22321F:: @ 822321F
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_22326E
	msgbox MossdeepCity_SpaceCenter_1F_Text_223B90, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_23, MossdeepCity_SpaceCenter_1F_Text_223BC2
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm 9
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_223278
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_223289
	applymovement 9, MossdeepCity_SpaceCenter_1F_Movement_2232A2
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_22326E:: @ 822326E
	msgbox MossdeepCity_SpaceCenter_1F_Text_223BD3, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223278:: @ 8223278
	applymovement 9, MossdeepCity_SpaceCenter_1F_Movement_22329A
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 1
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_223289:: @ 8223289
	applymovement 9, MossdeepCity_SpaceCenter_1F_Movement_22329E
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_1, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_22329A: @ 822329A
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Movement_22329E: @ 822329E
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Movement_2232A2: @ 82232A2
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_2232A7: @ 82232A7
	.string "Le lancement de la fusée est imminent!$"

MossdeepCity_SpaceCenter_1F_Text_2232C8: @ 82232C8
	.string "La fusée a décollé en toute sécurité!\n"
	.string "Lancement nº {STR_VAR_1} réussi!$"

MossdeepCity_SpaceCenter_1F_Text_223305: @ 8223305
	.string "Je sais que tout est un peu sens\n"
	.string "dessus dessous en ce moment…\p"
	.string "Le lancement de la fusée est imminent!$"

MossdeepCity_SpaceCenter_1F_Text_22335E: @ 822335E
	.string "Je sais que tout est un peu sens\n"
	.string "dessus dessous en ce moment…\p"
	.string "La fusée a décollé en toute sécurité!\n"
	.string "Lancement nº {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_2233D3: @ 82233D3
	.string "Lancer une fusée exige la perfection.\n"
	.string "L'erreur n'est pas permise.\p"
	.string "Même si tout est juste à 99%,\n"
	.string "ça ne sert à rien si le dernier 1%\l"
	.string "n'est pas correct.\p"
	.string "Malgré ça, on essaie toujours..\n"
	.string "Pourquoi? C'est un rêve sans fin.$"

MossdeepCity_SpaceCenter_1F_Text_2234B7: @ 82234B7
	.string "Ces types sont intéressés par le\n"
	.string "CENTRE SPATIAL.\p"
	.string "Mais on ne peut pas se permettre\n"
	.string "de les laisser gêner le lancement\l"
	.string "de notre fusée!$"

MossdeepCity_SpaceCenter_1F_Text_223540: @ 8223540
	.string "Je faisais un petit tour sur la plage,\n"
	.string "quand j'ai trouvé ça.\p"
	.string "Ça ne me servira pas, alors autant\n"
	.string "que ce soit toi qui l'aies.$"

MossdeepCity_SpaceCenter_1F_Text_2235A6: @ 82235A6
	.string "La région de HOENN a longtemps été\n"
	.string "réputée pour ses pluies de météorites.$"

MossdeepCity_SpaceCenter_1F_Text_2235F0: @ 82235F0
	.string "On ne peut pas laisser la TEAM MAGMA\n"
	.string "voler le carburant pour la fusée.\p"
	.string "Oh, au fait, j'ai trouvé cette pierre sur\n"
	.string "la plage. Je te la donne si tu veux.$"

MossdeepCity_SpaceCenter_1F_Text_223664: @ 8223664
	.string "Avec la TEAM MAGMA dans le coin,\n"
	.string "les promenades sur la plage ne sont\l"
	.string "plus vraiment sûres.$"

MossdeepCity_SpaceCenter_1F_Text_2236A6: @ 82236A6
	.string "Certains prétendent que les POKéMON\n"
	.string "viennent de l'espace. Est-ce possible?$"

MossdeepCity_SpaceCenter_1F_Text_2236E8: @ 82236E8
	.string "La TEAM AQUA devrait s'occuper de\n"
	.string "la TEAM MAGMA!\p"
	.string "Mais s'ils font ça, ils risquent de\n"
	.string "croire qu'ils ont tous les droits, non?$"

MossdeepCity_SpaceCenter_1F_Text_22375B: @ 822375B
	.string "Un gigantesque bloc de métal qui\n"
	.string "franchit l'atmosphère et flotte dans\l"
	.string "l'espace…\p"
	.string "Ça laisse rêveur!$"

MossdeepCity_SpaceCenter_1F_Text_2237B5: @ 82237B5
	.string "Un gigantesque bloc de métal qui\n"
	.string "franchit l'atmosphère et flotte dans\l"
	.string "l'espace…\p"
	.string "Mais la TEAM MAGMA veut gâcher mon\n"
	.string "rêve de voir la fusée décoller!\p"
	.string "Je ne les laisserai pas faire!$"

MossdeepCity_SpaceCenter_1F_Text_223849: @ 8223849
	.string "PIERRE: {PLAYER}{KUN}, as-tu déjà lu cette\n"
	.string "annonce?\p"
	.string "La TEAM MAGMA veut s'approprier le\n"
	.string "carburant destiné à la fusée.\p"
	.string "Je ne sais pas pourquoi ils en ont\n"
	.string "besoin, mais ils ne peuvent pas faire ça.\p"
	.string "Je vais rester ici et garder l'œil ouvert\n"
	.string "encore quelque temps.\p"
	.string "Tu devrais en profiter pour aller faire\n"
	.string "un tour en ville.$"

MossdeepCity_SpaceCenter_1F_Text_22396C: @ 822396C
	.string "Comme promis, nous sommes venus\n"
	.string "pour voler le carburant de la fusée.$"

MossdeepCity_SpaceCenter_1F_Text_223999: @ 8223999
	.string "J'ai dû manquer de carburant…$"

MossdeepCity_SpaceCenter_1F_Text_2239AA: @ 82239AA
	.string "Ne prends pas la grosse tête juste\n"
	.string "pour m'avoir battue.$"

MossdeepCity_SpaceCenter_1F_Text_2239E6: @ 82239E6
	.string "On t'avait dit de rester en dehors!\n"
	.string "Rien ne doit gêner nos plans.$"

MossdeepCity_SpaceCenter_1F_Text_223A21: @ 8223A21
	.string "Grrr… Je n'aurais pas dû me\n"
	.string "battre à la loyale!$"

MossdeepCity_SpaceCenter_1F_Text_223A4B: @ 8223A4B
	.string "OK, j'ai compris! La prochaine fois, on\n"
	.string "viendra sans prévenir personne.$"

MossdeepCity_SpaceCenter_1F_Text_223A8A: @ 8223A8A
	.string "Le carburant que le CENTRE SPATIAL\n"
	.string "garde pour la fusée…\p"
	.string "C'est ça qui nous intéresse, on n'en\n"
	.string "laissera une goutte.$"

MossdeepCity_SpaceCenter_1F_Text_223AFA: @ 8223AFA
	.string "Je retire ce que j'ai dit…\n"
	.string "Un jerrycan suffira…$"

MossdeepCity_SpaceCenter_1F_Text_223B37: @ 8223B37
	.string "Ce que nous voulons faire avec\n"
	.string "le carburant?\p"
	.string "Comment je le saurais?\n"
	.string "Je ne suis qu'un sbire!$"

MossdeepCity_SpaceCenter_1F_Text_223B90: @ 8223B90
	.string "Notre chef a dit que personne ne\n"
	.string "devait passer… PERSONNE!$"

MossdeepCity_SpaceCenter_1F_Text_223BC2: @ 8223BC2
	.string "Aille aïe aïe!$"

MossdeepCity_SpaceCenter_1F_Text_223BD3: @ 8223BD3
	.string "S'il te plaît, dis à mon chef que je n'ai\n"
	.string "pas abandonné mon poste.\p"
	.string "Dis-lui que je suis resté jusqu'au bout…$"

MossdeepCity_SpaceCenter_1F_Text_223C2C: @ 8223C2C
	.string "Ceci est une…\n"
	.string "déclaration d'intention de vol?\p"
	.string "“A l'intention du personnel du\n"
	.string "CENTRE SPATIAL: Comment ça va?\l"
	.string "Nous ça va plutôt pas mal.”\p"
	.string "“Nous passerons bientôt vous\n"
	.string "piquer le carburant pour la fusée.”\p"
	.string "“N'essayez pas de nous arrêter.\n"
	.string "On le prendra quand même!”\p"
	.string "“Pour l'expansion de la terre!\n"
	.string "TEAM MAGMA”$"
