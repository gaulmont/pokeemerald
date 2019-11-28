MossdeepCity_StevensHouse_MapScripts:: @ 8222784
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_MapScript1_222794
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_MapScript2_2227C0
	.byte 0

MossdeepCity_StevensHouse_MapScript1_222794: @ 8222794
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_22279E
	end

MossdeepCity_StevensHouse_EventScript_22279E:: @ 822279E
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, 1
	return

MossdeepCity_StevensHouse_OnTransition: @ 82227A8
	compare VAR_STEVENS_HOUSE_STATE, 2
	call_if_eq MossdeepCity_StevensHouse_EventScript_2227B4
	end

MossdeepCity_StevensHouse_EventScript_2227B4:: @ 82227B4
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_MapScript2_2227C0: @ 82227C0
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_2227CA
	.2byte 0

MossdeepCity_StevensHouse_EventScript_2227CA:: @ 82227CA
	lockall
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, MossdeepCity_StevensHouse_Movement_222833
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_222936, MSGBOX_DEFAULT
	giveitem_std ITEM_HM08
	setflag FLAG_RECEIVED_HM08
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_222A0E, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 1, MossdeepCity_StevensHouse_Movement_22283B
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_222833: @ 8222833
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

MossdeepCity_StevensHouse_Movement_22283B: @ 822283B
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MossdeepCity_StevensHouse_EventScript_222841:: @ 8222841
	lockall
	msgbox MossdeepCity_StevensHouse_Text_222B9E, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_22285B
	goto MossdeepCity_StevensHouse_EventScript_222865
	end

MossdeepCity_StevensHouse_EventScript_22285B:: @ 822285B
	msgbox MossdeepCity_StevensHouse_Text_222C2A, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222865:: @ 8222865
	setvar VAR_TEMP_1, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_222895
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_StevensHouse_EventScript_2228BD
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_222895:: @ 8222895
	call MossdeepCity_StevensHouse_EventScript_2228EB
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_222901
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_222901
	end

MossdeepCity_StevensHouse_EventScript_2228BD:: @ 82228BD
	call MossdeepCity_StevensHouse_EventScript_2228EB
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_2228E0
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_2228E0
	end

MossdeepCity_StevensHouse_EventScript_2228E0:: @ 82228E0
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_222901
	end

MossdeepCity_StevensHouse_EventScript_2228EB:: @ 82228EB
	bufferspeciesname 1, SPECIES_BELDUM
	removeobject 2
	playfanfare MUS_FANFA4
	message MossdeepCity_StevensHouse_Text_222BED
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_222901:: @ 8222901
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222909:: @ 8222909
	msgbox MossdeepCity_StevensHouse_Text_222D97, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_222912:: @ 8222912
	msgbox MossdeepCity_StevensHouse_Text_222B11, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_22291B:: @ 822291B
	lockall
	msgbox MossdeepCity_StevensHouse_Text_222C4E, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222926:: @ 8222926
	giveitem_std ITEM_HM08, 1, 1
	setflag FLAG_RECEIVED_HM08
	end

MossdeepCity_StevensHouse_Text_222936: @ 8222936
	.string "PIERRE: {PLAYER}{KUN}…\p"
	.string "Comme tu vois, il n'y a pas grand\n"
	.string "chose ici, mais je m'y sens bien.\p"
	.string "Merci pour tout ce que tu as fait.\p"
	.string "Pour te prouver ma gratitude, je\n"
	.string "voudrais te donner cette CS!\p"
	.string "Elle contient PLONGEE. Tu la mérites\n"
	.string "vraiment, tu ne peux pas refuser.$"

MossdeepCity_StevensHouse_Text_222A0E: @ 8222A0E
	.string "PIERRE: Quand tu utiliseras SURF,\n"
	.string "tu verras des zones d'eau plus sombres.\p"
	.string "Utilise PLONGEE si tu es au-dessus des\n"
	.string "profondeurs. Tu iras au fond de la mer.\p"
	.string "Si tu veux remonter à la surface,\n"
	.string "utilise PLONGEE à nouveau.\p"
	.string "Cependant, à certains endroits, il ne\n"
	.string "sera pas possible de remonter.$"

MossdeepCity_StevensHouse_Text_222B11: @ 8222B11
	.string "PIERRE: Apparemment, il y a une caverne\n"
	.string "sous l'eau entre ALGATIA et\l"
	.string "ATALANOPOLIS.\p"
	.string "Tu sais, celle que le CAPT. POUPE\n"
	.string "a découverte avec son sous-marin.$"

MossdeepCity_StevensHouse_Text_222B9E: @ 8222B9E
	.string "{PLAYER} examine la POKé BALL.\p"
	.string "Elle contient le POKéMON\n"
	.string "TERHAL.\p"
	.string "Prendre la POKé BALL?$"

MossdeepCity_StevensHouse_Text_222BED: @ 8222BED
	.string "{PLAYER} reçoit un TERHAL.$"

MossdeepCity_StevensHouse_Text_222C03: @ 8222C03
	.string "There is no space for another POKéMON.$"

MossdeepCity_StevensHouse_Text_222C2A: @ 8222C2A
	.string "{PLAYER} laisse la POKé BALL à sa place.$"

MossdeepCity_StevensHouse_Text_222C4E: @ 8222C4E
	.string "C'est une lettre.\p"
	.string "… … … … … …\p"
	.string "Pour {PLAYER}{KUN}…\p"
	.string "J'ai décidé de faire un petit examen de\n"
	.string "conscience et de m'entraîner en route.\p"
	.string "Je ne prévois pas de rentrer chez moi\n"
	.string "tout de suite.\p"
	.string "J'ai un service à te demander.\p"
	.string "Je veux que tu prennes la POKé BALL\n"
	.string "qui est sur le bureau.\p"
	.string "A l'intérieur, il y a un TERHAL, mon\n"
	.string "POKéMON préféré.\p"
	.string "Je compte sur toi.\p"
	.string "Nos chemins se croiseront peut-être\n"
	.string "à nouveau.\p"
	.string "PIERRE ROCHARD$"

MossdeepCity_StevensHouse_Text_222D97: @ 8222D97
	.string "C'est une collection de roches et de\n"
	.string "pierres rares réunies par PIERRE.$"

