RustboroCity_Gym_MapScripts:: @ 8212F30
	.byte 0

RustboroCity_Gym_EventScript_Roxanne:: @ 8212F31
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreBattle, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated:: @ 8212F66
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb:: @ 8212FA4
	giveitem_std ITEM_TM39
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch:: @ 8212FC8
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh:: @ 8212FE3
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshPreBattle, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy:: @ 8212FFA
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyPreBattle, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc:: @ 8213011
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcPreBattle, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide:: @ 8213028
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory:: @ 821303D
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue:: @ 8213047
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue:: @ 8213057
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified:: @ 8213067
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue:: @ 8213071
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne:: @ 821307B
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice: @ 821309D
	.string "Hé, ça va?\p"
	.string "Ecoute!\n"
	.string "Tu veux devenir le MAITRE?\p"
	.string "Je n'suis pas DRESSEUR moi, mais je peux\n"
	.string "te donner des conseils pour gagner.\p"
	.string "Marché conclu! Nous viserons donc le\n"
	.string "titre de MAITRE POKéMON!\p"
	.string "Ton devoir en tant que DRESSEUR est\n"
	.string "de rassembler des BADGES, c'est ça?\p"
	.string "Il s'agit d'une tâche difficile car les\n"
	.string "CHAMPIONS sont très fort!\p"
	.string "Alors c'est là que j'interviens! Je suis\n"
	.string "là pour te donner de bons conseils!\p"
	.string "ROXANNE, CHAMPION D'ARENE\n"
	.string "de cette ville, utilise des POKéMON\l"
	.string "du type ROCHE.\p"
	.string "Le type ROCHE se caractérise par sa\n"
	.string "résistance, mais il supporte mal les\l"
	.string "capacités des types EAU et PLANTE.\p"
	.string "Reviens me voir si tu arrives à battre\n"
	.string "le CHAMPION D'ARENE.\p"
	.string "Allez, vas-y!$"

RustboroCity_Gym_Text_GymGuidePostVictory: @ 82132E2
	.string "Waouh! Quelle victoire époustouflante!\n"
	.string "Mes encouragements ont servi!\p"
	.string "Génial!\n"
	.string "Vérifie ta CARTE DRESSEUR.\p"
	.string "Le BADGE ROCHE, que tu as obtenu,\n"
	.string "doit y être enregistré correctement.\p"
	.string "Autrement dit…\p"
	.string "Tu as fait le premier pas vers le\n"
	.string "titre de MAITRE POKéMON!\p"
	.string "Tu peux en tirer de la satisfaction!$"

RustboroCity_Gym_Text_JoshPreBattle: @ 82133E9
	.string "Ne prends pas les DRESSEURS!\n"
	.string "D'ARENE à la légère!\l"
	.string "Tu vas voir pourquoi on est meilleurs!$"

RustboroCity_Gym_Text_JoshDefeat: @ 821342D
	.string "Tu as trop de force pour moi…$"

RustboroCity_Gym_Text_JoshPostBattle: @ 8213447
	.string "Tu n'as encore rien vu de l'étonnante\n"
	.string "puissance du type ROCHE!$"

RustboroCity_Gym_Text_TommyPreBattle: @ 8213486
	.string "Si tu ne réussis pas à me battre, tu\n"
	.string "n'auras aucune chance face à ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat: @ 82134C6
	.string "Waouh! Tu as un certain potentiel!$"

RustboroCity_Gym_Text_TommyPostBattle: @ 82134E6
	.string "ROXANNE est plus forte que moi\n"
	.string "à plusieurs égards.\p"
	.string "Tu ferais bien de te méfier!$"

RustboroCity_Gym_Text_MarcPreBattle: @ 8213533
	.string "Je sais qu'on est au milieu de la ville.\n"
	.string "Et alors?\p"
	.string "Mes POKéMON ROCHE ont besoin\n"
	.string "de place pour s'exprimer!$"

RustboroCity_Gym_Text_MarcDefeat: @ 8213589
	.string "Oh non, non!\n"
	.string "Tu sais te battre toi!$"

RustboroCity_Gym_Text_MarcPostBattle: @ 82135C0
	.string "Je dois laisser la main à notre\n"
	.string "CHAMPION.\p"
	.string "Malgré son jeune âge, elle a su choisir\n"
	.string "intelligemment les POKéMON ROCHE.$"

RustboroCity_Gym_Text_RoxannePreBattle: @ 821362A
	.string "Salut! Je suis ROXANNE, CHAMPION\n"
	.string "de l'ARENE POKéMON de MEROUVILLE.\p"
	.string "Je suis devenue CHAMPION pour\n"
	.string "appliquer dans les combats ce que\l"
	.string "j'ai appris à l'ECOLE DE DRESSEURS.\p"
	.string "Tu voudrais bien me montrer comment\n"
	.string "tu te bats, et avec quels POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat: @ 821370B
	.string "Bon…\n"
	.string "J'ai perdu…\p"
	.string "Apparemment, j'ai encore bien\n"
	.string "des choses à apprendre…\p"
	.string "Je comprends.\p"
	.string "Les règles de la LIGUE POKéMON\n"
	.string "stipulent que le CHAMPION doit re-\l"
	.string "mettre ceci au DRESSEUR qui l'a battu.\p"
	.string "Alors accepte ce BADGE ROCHE officiel\n"
	.string "de la LIGUE POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge: @ 82137EC
	.string "{PLAYER} reçoit le BADGE ROCHE\n"
	.string "de la part de ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis: @ 8213816
	.string "Le BADGE ROCHE augmente la puissance\n"
	.string "d'ATTAQUE de tes POKéMON.\p"
	.string "Il leur permet d'utiliser l'attaque\n"
	.string "de la CS COUPE en dehors des combats.\p"
	.string "Accepte également ça.$"

RustboroCity_Gym_Text_ExplainRockTomb: @ 82138B1
	.string "Cette CT39 contient TOMBEROCHE.\p"
	.string "La chute de pierres inflige des\n"
	.string "dommages et la VITESSE diminue.\p"
	.string "Si tu utilises une CT, l'attaque est\n"
	.string "immédiatement enseignée à un POKéMON.\p"
	.string "Sache qu'une CT ne s'utilise qu'une fois.\n"
	.string "Réfléchis bien avant de t'en servir!$"

RustboroCity_Gym_Text_RoxannePostBattle: @ 82139A7
	.string "Puisque tu as tant de force, tu ferais\n"
	.string "bien de combattre d'autres CHAMPIONS.\p"
	.string "En affrontant plein de DRESSEURS, tu\n"
	.string "devrais apprendre beaucoup de choses.$"

RustboroCity_Gym_Text_GymStatue: @ 8213A21
	.string "ARENE POKéMON de MEROUVILLE$"

RustboroCity_Gym_Text_GymStatueCertified: @ 8213A3B
	.string "ARENE POKéMON de MEROUVILLE\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR ROXANNE:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall: @ 8213A76
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "ROXANNE: C'est bien {PLAYER}?\n"
	.string "Ici ROXANNE de MEROUVILLE.\p"
	.string "J'ai appris de BASTIEN que tu\n"
	.string "progresses très rapidement en\l"
	.string "tant que DRESSEUR.\p"
	.string "Bon, je ferais mieux d'oublier que\n"
	.string "tu m'as battue.\p"
	.string "Mais je te promets d'améliorer\n"
	.string "mon ARENE pour que tu puisses\l"
	.string "nous affronter de nouveau.\p"
	.string "J'espère t'y revoir très bientôt!\p"
	.string "… … … … … …\n"
	.string "… … … … … Clic!$"

RustboroCity_Gym_Text_RegisteredRoxanne: @ 8213C01
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D'ARENE ROXANNE dans le POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch: @ 8213C2F
	.string "ROXANNE: Je suis ravie de te revoir!\p"
	.string "Je suis sûre que nous avons énormément\n"
	.string "progressé depuis notre dernière\l"
	.string "rencontre.\p"
	.string "Voyons voir à quel point!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat: @ 8213CF9
	.string "Grr…\n"
	.string "Encore perdu…$"

RustboroCity_Gym_Text_RoxannePostRematch: @ 8213D12
	.string "ROXANNE: J'ai encore beaucoup à\n"
	.string "apprendre au sujet des POKéMON.\p"
	.string "Cette prise de conscience ne fait\n"
	.string "qu'attiser mon amour pour les combats!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons: @ 8213D93
	.string "ROXANNE: Je suis ravie de te revoir!\n"
	.string "Je suis sûre que nous avons énormément\n"
	.string "progressé depuis notre dernière\l"
	.string "rencontre.\p"
	.string "Voyons voir à quel point!\n"
	.string "we've become…\p"
	.string "Oh, mais…\n"
	.string "Tu n'as qu'un POKéMON avec toi?\p"
	.string "Reviens me voir avec au moins\n"
	.string "deux POKéMON, s'il te plaît.$"
