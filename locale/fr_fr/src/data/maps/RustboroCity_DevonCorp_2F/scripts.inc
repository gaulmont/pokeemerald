RustboroCity_DevonCorp_2F_MapScripts:: @ 8211857
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition: @ 821185D
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_211869
	end

RustboroCity_DevonCorp_2F_EventScript_211869:: @ 8211869
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_21186F:: @ 821186F
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_211869
	msgbox RustboroCity_DevonCorp_2F_Text_211BFB, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_211886:: @ 8211886
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_211869
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_2118A6
	msgbox RustboroCity_DevonCorp_2F_Text_211C50, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_2118A6:: @ 82118A6
	msgbox RustboroCity_DevonCorp_2F_Text_211C99, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_2118B0:: @ 82118B0
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_211869
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_2118D0
	msgbox RustboroCity_DevonCorp_2F_Text_211D9F, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_2118D0:: @ 82118D0
	msgbox RustboroCity_DevonCorp_2F_Text_211DF3, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_2118DA:: @ 82118DA
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_211869
	msgbox RustboroCity_DevonCorp_2F_Text_211EE0, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_2118F1:: @ 82118F1
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211A03
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_2119F9
	msgbox RustboroCity_DevonCorp_2F_Text_211F48, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211933
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211991
	release
	end

RustboroCity_DevonCorp_2F_EventScript_211933:: @ 8211933
	closemessage
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_211FA6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_2119EF
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211B84
	goto RustboroCity_DevonCorp_2F_EventScript_211974
	end

RustboroCity_DevonCorp_2F_EventScript_211974:: @ 8211974
	bufferitemname 0, ITEM_ROOT_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_212153, MSGBOX_DEFAULT
	takeitem ITEM_ROOT_FOSSIL, 1
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RustboroCity_DevonCorp_2F_EventScript_211991:: @ 8211991
	closemessage
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_211FA6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_2119EF
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211B84
	goto RustboroCity_DevonCorp_2F_EventScript_2119D2
	end

RustboroCity_DevonCorp_2F_EventScript_2119D2:: @ 82119D2
	bufferitemname 0, ITEM_CLAW_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_212153, MSGBOX_DEFAULT
	takeitem ITEM_CLAW_FOSSIL, 1
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RustboroCity_DevonCorp_2F_EventScript_2119EF:: @ 82119EF
	msgbox RustboroCity_DevonCorp_2F_Text_212046, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_2119F9:: @ 82119F9
	msgbox RustboroCity_DevonCorp_2F_Text_2121A2, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_211A03:: @ 8211A03
	compare VAR_WHICH_FOSSIL_REVIVED, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211A1A
	compare VAR_WHICH_FOSSIL_REVIVED, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211A2C
	end

RustboroCity_DevonCorp_2F_EventScript_211A1A:: @ 8211A1A
	bufferspeciesname 1, SPECIES_LILEEP
	msgbox RustboroCity_DevonCorp_2F_Text_212251, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_211A3E
	end

RustboroCity_DevonCorp_2F_EventScript_211A2C:: @ 8211A2C
	bufferspeciesname 1, SPECIES_ANORITH
	msgbox RustboroCity_DevonCorp_2F_Text_212251, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_211AE1
	end

RustboroCity_DevonCorp_2F_EventScript_211A3E:: @ 8211A3E
	setvar VAR_TEMP_1, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211A6E
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211A96
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_211A6E:: @ 8211A6E
	call RustboroCity_DevonCorp_2F_EventScript_211AC4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211AD7
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_211AD7
	end

RustboroCity_DevonCorp_2F_EventScript_211A96:: @ 8211A96
	call RustboroCity_DevonCorp_2F_EventScript_211AC4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211AB9
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_211AB9
	end

RustboroCity_DevonCorp_2F_EventScript_211AB9:: @ 8211AB9
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_211AD7
	end

RustboroCity_DevonCorp_2F_EventScript_211AC4:: @ 8211AC4
	bufferspeciesname 1, SPECIES_LILEEP
	playfanfare MUS_FANFA4
	message RustboroCity_DevonCorp_2F_Text_2122CB
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_LILEEP
	return

RustboroCity_DevonCorp_2F_EventScript_211AD7:: @ 8211AD7
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_211AE1:: @ 8211AE1
	setvar VAR_TEMP_1, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211B11
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211B39
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_211B11:: @ 8211B11
	call RustboroCity_DevonCorp_2F_EventScript_211B67
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211B7A
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_211B7A
	end

RustboroCity_DevonCorp_2F_EventScript_211B39:: @ 8211B39
	call RustboroCity_DevonCorp_2F_EventScript_211B67
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_211B5C
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_211B5C
	end

RustboroCity_DevonCorp_2F_EventScript_211B5C:: @ 8211B5C
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_211B7A
	end

RustboroCity_DevonCorp_2F_EventScript_211B67:: @ 8211B67
	bufferspeciesname 1, SPECIES_ANORITH
	playfanfare MUS_FANFA4
	message RustboroCity_DevonCorp_2F_Text_2122CB
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_ANORITH
	return

RustboroCity_DevonCorp_2F_EventScript_211B7A:: @ 8211B7A
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_211B84:: @ 8211B84
	message RustboroCity_DevonCorp_2F_Text_212092
	waitmessage
	multichoice 17, 6, MULTI_FOSSIL, 0
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_211BC1
	case 1, RustboroCity_DevonCorp_2F_EventScript_211BC7
	case 2, RustboroCity_DevonCorp_2F_EventScript_211BCD
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_211BCD
	end

RustboroCity_DevonCorp_2F_EventScript_211BC1:: @ 8211BC1
	goto RustboroCity_DevonCorp_2F_EventScript_2119D2
	end

RustboroCity_DevonCorp_2F_EventScript_211BC7:: @ 8211BC7
	goto RustboroCity_DevonCorp_2F_EventScript_211974
	end

RustboroCity_DevonCorp_2F_EventScript_211BCD:: @ 8211BCD
	release
	end

RustboroCity_DevonCorp_2F_EventScript_211BCF:: @ 8211BCF
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_211869
	compare VAR_RUSTBORO_CITY_STATE, 6
	goto_if_ge RustboroCity_DevonCorp_2F_EventScript_211BF1
	msgbox RustboroCity_DevonCorp_2F_Text_212338, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_211BF1:: @ 8211BF1
	msgbox RustboroCity_DevonCorp_2F_Text_212386, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_211BFB: @ 8211BFB
	.string "Nous développons un appareil\n"
	.string "permettant de communiquer avec\l"
	.string "les POKéMON.\p"
	.string "Mais ce n'est pas encore au point…$"

RustboroCity_DevonCorp_2F_Text_211C50: @ 8211C50
	.string "Je mets au point de nouvelles sortes de\n"
	.string "POKé BALLS…\p"
	.string "Mais je n'ai pas trop progressé…$"

RustboroCity_DevonCorp_2F_Text_211C99: @ 8211C99
	.string "Nous avons élaboré de nouvelles\n"
	.string "POKé BALLS!\p"
	.string "La BIS BALL permet d'attraper plus\n"
	.string "facilement un type de POKéMON que\l"
	.string "tu as déjà capturé.\p"
	.string "La CHRONO BALL est plus efficace\n"
	.string "si le combat dure longtemps.\p"
	.string "Toutes deux sont fièrement produites\n"
	.string "par DEVON.\p"
	.string "Il faut les essayer!$"

RustboroCity_DevonCorp_2F_Text_211D9F: @ 8211D9F
	.string "J'ai inventé le POKéNAV!\p"
	.string "En tant qu'ingénieur, je suis enchanté\n"
	.string "d'avoir créé un appareil si génial!$"

RustboroCity_DevonCorp_2F_Text_211DF3: @ 8211DF3
	.string "Oh, waouh!\n"
	.string "C'est un POKéNAV!\p"
	.string "Il a été conçu pour répondre au souhait\n"
	.string "de notre DIRECTEUR. Il voulait mieux\l"
	.string "connaître les POKéMON.\p"
	.string "Veux-tu que je te décrive précisément\n"
	.string "ses caractéristiques?\p"
	.string "Et puis non. Tu t'en rendras vite compte\n"
	.string "rien qu'en l'essayant, de toute façon.$"

RustboroCity_DevonCorp_2F_Text_211EE0: @ 8211EE0
	.string "J'essaie de mettre au point un appareil\n"
	.string "permettant de reproduire visuellement\l"
	.string "les rêves des POKéMON…\p"
	.string "Mais ça ne marche pas bien.$"

RustboroCity_DevonCorp_2F_Text_211F48: @ 8211F48
	.string "J'ai créé un appareil pour faire revivre\n"
	.string "des POKéMON à partir de fossiles…\p"
	.string "Et ça marche!$"

RustboroCity_DevonCorp_2F_Text_211FA6: @ 8211FA6
	.string "Attends! Ce que tu as là…\n"
	.string "C'est un fossile de POKéMON?\p"
	.string "Veux-tu ramener ce POKéMON\n"
	.string "à la vie?\p"
	.string "Je peux le faire avec mon tout nouveau\n"
	.string "REGENERATEUR DE FOSSILE.$"

RustboroCity_DevonCorp_2F_Text_212046: @ 8212046
	.string "Non, tu ne veux pas?\p"
	.string "Mais le savoir-faire technologique de\n"
	.string "DEVON est remarquable, je t'assure.$"

RustboroCity_DevonCorp_2F_Text_212092: @ 8212092
	.string "Oh, ça c'est une surprise!\n"
	.string "Tu n'as pas un, mais deux fossiles?\p"
	.string "Malheureusement, ma machine ne peut\n"
	.string "régénérer qu'un POKéMON à la fois.\p"
	.string "Veux-tu choisir un de tes fossiles\n"
	.string "pour la régénération?$"

RustboroCity_DevonCorp_2F_Text_212153: @ 8212153
	.string "Parfait!\n"
	.string "Faisons-le tout de suite!\p"
	.string "{PLAYER} donne {STR_VAR_1} au\n"
	.string "CHERCHEUR DE DEVON.$"

RustboroCity_DevonCorp_2F_Text_2121A2: @ 82121A2
	.string "Le REGENERATEUR DE FOSSILE que\n"
	.string "j'ai créé est incroyable!\p"
	.string "Mais il a un inconvénient: il est\n"
	.string "lent dans son fonctionnement.\p"
	.string "Alors, euh… et si tu te baladais un peu\n"
	.string "en attendant?$"

RustboroCity_DevonCorp_2F_Text_212251: @ 8212251
	.string "Merci d'avoir patienté!\p"
	.string "Ton POKéMON fossilisé a repris vie!\p"
	.string "Le fossile était un ancien POKéMON.\n"
	.string "C'était un {STR_VAR_2}!$"

RustboroCity_DevonCorp_2F_Text_2122CB: @ 82122CB
	.string "{PLAYER} reçoit  {STR_VAR_2} de la part\n"
	.string "du CHERCHEUR DE DEVON.$"

RustboroCity_DevonCorp_2F_Text_2122F5: @ 82122F5
	.string "Hum hum, tu as trop de POKéMON.\n"
	.string "Tu n'as plus de place pour celui-ci.$"

RustboroCity_DevonCorp_2F_Text_212338: @ 8212338
	.string "J'essaie de développer une nouvelle\n"
	.string "fonction pour le POKéNAV…\p"
	.string "Mais ce n'est pas très concluant.$"

RustboroCity_DevonCorp_2F_Text_212386: @ 8212386
	.string "Bon, sur quoi est-ce que je vais bien\n"
	.string "pouvoir travailler maintenant?\p"
	.string "Cette compagnie nous permet de\n"
	.string "travailler sur ce que l'on souhaite.\p"
	.string "Un ingénieur ne pourrait pas rêver\n"
	.string "de meilleur environnement.$"

