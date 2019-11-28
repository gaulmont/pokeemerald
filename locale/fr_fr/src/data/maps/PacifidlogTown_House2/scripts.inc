PacifidlogTown_House2_MapScripts:: @ 8203791
	.byte 0

PacifidlogTown_House2_EventScript_203792:: @ 8203792
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_2037DE
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_20387E
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_2037F8
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_203801
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 4
	goto_if_ge PacifidlogTown_House2_EventScript_203816
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 2
	goto_if_ge PacifidlogTown_House2_EventScript_203845
	goto PacifidlogTown_House2_EventScript_20384F
	end

PacifidlogTown_House2_EventScript_2037DE:: @ 82037DE
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	compare VAR_RESULT, 0
	call_if_eq PacifidlogTown_House2_EventScript_203812
	return

PacifidlogTown_House2_EventScript_2037F8:: @ 82037F8
	msgbox PacifidlogTown_House2_Text_20395B, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_203801:: @ 8203801
	msgbox PacifidlogTown_House2_Text_2038C7, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_20395B, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_203812:: @ 8203812
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_203816:: @ 8203816
	msgbox PacifidlogTown_House2_Text_20396D, MSGBOX_DEFAULT
	giveitem_std ITEM_TM27
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_203A85, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_203845:: @ 8203845
	msgbox PacifidlogTown_House2_Text_2039CE, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_20384F:: @ 820384F
	msgbox PacifidlogTown_House2_Text_203A2F, MSGBOX_DEFAULT
	giveitem_std ITEM_TM21
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_203A85, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_20387E:: @ 820387E
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring 0, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_203AF4, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_203891:: @ 8203891
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	msgbox PacifidlogTown_House2_Text_203B8D, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_203B9D, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_2038AC:: @ 82038AC
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 2
	msgbox PacifidlogTown_House2_Text_203BCE, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_203BDF, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_2038C7: @ 82038C7
	.string "Hum-hum!\p"
	.string "Je suis la personne la plus influente\n"
	.string "du FAN CLUB POKéMON. Je suis\l"
	.string "le petit frère du PRESIDENT.\p"
	.string "Je suis ici en vacances, avec mes\n"
	.string "POKéMON, bien entendu.$"

PacifidlogTown_House2_Text_20395B: @ 820395B
	.string "Ah!\n"
	.string "Ton POKéMON…$"

PacifidlogTown_House2_Text_20396D: @ 820396D
	.string "Il t'aime énormément, pas de doute.\p"
	.string "Un POKéMON aussi adorable et adoré\n"
	.string "mérite bien une CT comme ça, non?$"

PacifidlogTown_House2_Text_2039CE: @ 82039CE
	.string "Hmm… Ce n'est pas mal, mais ce n'est\n"
	.string "pas génial non plus.\p"
	.string "Toi, en tant que DRESSEUR, tu dois faire\n"
	.string "plus d'efforts.$"

PacifidlogTown_House2_Text_203A2F: @ 8203A2F
	.string "Il a un regard mauvais.\p"
	.string "Un POKéMON aussi effrayant mérite\n"
	.string "une CT comme ça.$"

PacifidlogTown_House2_Text_203A85: @ 8203A85
	.string "Lorsqu'un POKéMON t'aime beaucoup,\n"
	.string "la puissance de RETOUR est augmentée.\p"
	.string "S'il ne t'aime pas, la puissance de\n"
	.string "FRUSTRATION est augmentée.$"

PacifidlogTown_House2_Text_203AF4: @ 8203AF4
	.string "Je devrais bientôt recevoir une ou deux\n"
	.string "bonnes CT. Tu veux savoir dans combien\l"
	.string "de jours? {STR_VAR_1}, je pense…\p"
	.string "Reviens me voir à ce moment-là.\n"
	.string "Je te donnerai une CT qui correspond\l"
	.string "à ton POKéMON.$"

PacifidlogTown_House2_Text_203B8D: @ 8203B8D
	.string "AZURILL: Uriii.$"

PacifidlogTown_House2_Text_203B9D: @ 8203B9D
	.string "Il a l'air d'être très ami avec le\n"
	.string "DRESSEUR.$"

PacifidlogTown_House2_Text_203BCE: @ 8203BCE
	.string "AZURILL: Uuuurill!$"

PacifidlogTown_House2_Text_203BDF: @ 8203BDF
	.string "Il n'a pas l'air d'aimer beaucoup le\n"
	.string "DRESSEUR.$"

