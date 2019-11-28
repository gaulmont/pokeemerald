FortreeCity_Gym_MapScripts:: @ 82165AB
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition: @ 82165B6
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp: @ 82165BA
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

FortreeCity_Gym_EventScript_InitRotatingGates:: @ 82165C4
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona:: @ 82165C8
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreBattle, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM40, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated:: @ 82165FD
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_WINONA_CALL_STEP_COUNTER, 0
	setflag FLAG_REGISTER_WINONA_POKENAV
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2:: @ 8216646
	giveitem_std ITEM_TM40
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce:: @ 821666A
	giveitem_std ITEM_TM40
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	return

FortreeCity_Gym_EventScript_WinonaRematch:: @ 821668D
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared:: @ 82166A8
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredPreBattle, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo:: @ 82166BF
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoPreBattle, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint:: @ 82166D6
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintPreBattle, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley:: @ 82166ED
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyPreBattle, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto:: @ 8216704
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoPreBattle, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius:: @ 821671B
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusPreBattle, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide:: @ 8216732
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory:: @ 8216747
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue:: @ 8216751
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue:: @ 8216761
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified:: @ 8216771
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue:: @ 821677B
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice: @ 8216785
	.string "Yo, ça baigne pour toi, futur\n"
	.string "MAITRE {PLAYER}?\p"
	.string "ALIZEE, CHAMPION D'ARENE de\n"
	.string "CIMETRONELLE est une spécialiste\l"
	.string "des POKéMON du type VOL.\p"
	.string "Elle attend au fond de cette ARENE,\n"
	.string "derrière les tourniquets.\p"
	.string "Elle attend de nouveaux challengeurs\n"
	.string "qui essaient de prendre leur envol!\p"
	.string "OK, vas-y!$"

FortreeCity_Gym_Text_GymGuidePostVictory: @ 821687D
	.string "Tu as gagné!\n"
	.string "Décollage réussi!$"

FortreeCity_Gym_Text_JaredPreBattle: @ 82168A2
	.string "Regarde l'élégance des POKéMON\n"
	.string "OISEAU au combat!$"

FortreeCity_Gym_Text_JaredDefeat: @ 82168D3
	.string "Toi…\n"
	.string "Tu as une telle puissance…$"

FortreeCity_Gym_Text_JaredPostBattle: @ 82168E7
	.string "Un DRESSEUR doit être rusé pour faire\n"
	.string "face aux retournements inattendus.\p"
	.string "Voyons si tu as assez de jugeote pour\n"
	.string "arriver jusqu'à notre CHAMPION?$"

FortreeCity_Gym_Text_EdwardoPreBattle: @ 821695A
	.string "Tous les amoureux des POKéMON OISEAU\n"
	.string "veulent rejoindre cette ARENE.\p"
	.string "En tant que membre de l'ARENE de\n"
	.string "CIMETRONELLE, je ne peux pas perdre!$"

FortreeCity_Gym_Text_EdwardoDefeat: @ 82169C7
	.string "C'était un poids trop lourd à\n"
	.string "porter pour moi…$"

FortreeCity_Gym_Text_EdwardoPostBattle: @ 82169F1
	.string "Le monde est grand et des tas de\n"
	.string "DRESSEURS très puissants le peuplent.\p"
	.string "Je vais continuer à m'entraîner pour\n"
	.string "devenir encore plus fort.$"

FortreeCity_Gym_Text_FlintPreBattle: @ 8216A66
	.string "Pas la peine pour ALIZEE, notre\n"
	.string "CHAMPION, de s'attarder sur ton cas!\p"
	.string "Je suis bien assez fort pour toi!$"

FortreeCity_Gym_Text_FlintDefeat: @ 8216AC4
	.string "ALIZEE, je…\n"
	.string "J'ai perdu!$"

FortreeCity_Gym_Text_FlintPostBattle: @ 8216AD7
	.string "ALIZEE est maligne et très forte.\n"
	.string "Elle représente le CHAMPION absolu!\p"
	.string "Oh, je rougis…$"

FortreeCity_Gym_Text_AshleyPreBattle: @ 8216B1A
	.string "ALIZEE m'a tout appris!\n"
	.string "Tu vas avoir du mal à me battre!$"

FortreeCity_Gym_Text_AshleyDefeat: @ 8216B51
	.string "Je me suis fait battre…$"

FortreeCity_Gym_Text_AshleyPostBattle: @ 8216B5F
	.string "Grâce à ALIZEE, les habitants de\n"
	.string "CIMETRONELLE peuvent vivre sans peur.$"

FortreeCity_Gym_Text_HumbertoPreBattle: @ 8216B9E
	.string "Quand ALIZEE se lance dans un combat,\n"
	.string "son visage s'illumine…\p"
	.string "Mais je ne te laisserai pas voir ça\n"
	.string "de tes petits yeux!$"

FortreeCity_Gym_Text_HumbertoDefeat: @ 8216C18
	.string "Aïe!\n"
	.string "Je n'ai pas pu t'arrêter.$"

FortreeCity_Gym_Text_HumbertoPostBattle: @ 8216C32
	.string "Tu ferais bien de te méfier!\n"
	.string "Ne te laisse pas distraire par le visage\l"
	.string "d'ALIZEE ou tu risques de le regretter!$"

FortreeCity_Gym_Text_DariusPreBattle: @ 8216C96
	.string "Tu ferais bien de savoir qu'il y a\n"
	.string "plusieurs sortes de POKéMON de\l"
	.string "type VOL.\p"
	.string "Tu le sais, hein?$"

FortreeCity_Gym_Text_DariusDefeat: @ 8216CF2
	.string "Tu plaisantes pas toi!$"

FortreeCity_Gym_Text_DariusPostBattle: @ 8216D0F
	.string "OK, tu m'as battu.\n"
	.string "Mais tu ferais bien de faire attention!\p"
	.string "Les POKéMON de notre CHAMPION\n"
	.string "vont te ramener sur terre!$"

FortreeCity_Gym_Text_WinonaPreBattle: @ 8216D75
	.string "Je suis ALIZEE, CHAMPION\n"
	.string "D'ARENE de CIMETRONELLE.\p"
	.string "Je me suis unie avec les POKéMON\n"
	.string "OISEAU et envolée dans les airs…\p"
	.string "Même si le combat a été exténuant,\n"
	.string "on l'a emporté avec grâce…\p"
	.string "Admire l'élégante chorégraphie que mes\n"
	.string "POKéMON OISEAU et moi avons préparée!$"

FortreeCity_Gym_Text_WinonaDefeat: @ 8216E60
	.string "Je n'avais encore jamais vu de DRESSEUR\n"
	.string "commander ses POKéMON avec autant de\l"
	.string "grâce que moi. Tu es le premier…\p"
	.string "En récompense de ta prouesse, je\n"
	.string "t'offre ce BADGE.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge: @ 8216EEC
	.string "{PLAYER} reçoit le BADGE PLUME\n"
	.string "la part d'ALIZEE.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis: @ 8216F17
	.string "Avec le BADGE PLUME, tous les POKéMON\n"
	.string "jusqu'au niveau 70, même ceux échangés,\l"
	.string "obéiront à tous tes ordres.\p"
	.string "Tu pourras aussi utiliser l'attaque CS\n"
	.string "VOL en dehors des combats.\p"
	.string "Et ça…\n"
	.string "C'est un cadeau que je te fais.$"

FortreeCity_Gym_Text_ExplainAerialAce: @ 8216FEC
	.string "La CT40 contient AEROPIQUE.\p"
	.string "Sa vitesse…\n"
	.string "Aucun POKéMON ne pourra l'éviter.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona: @ 8217044
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D'ARENE ALIZEE dans le POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle: @ 8217071
	.string "Même après ma défaite, je reste dévouée\n"
	.string "aux POKéMON OISEAU.$"

FortreeCity_Gym_Text_GymStatue: @ 82170AE
	.string "ARENE POKéMON de CIMETRONELLE$"

FortreeCity_Gym_Text_GymStatueCertified: @ 82170C7
	.string "ARENE POKéMON de CIMETRONELLE\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR ALIZEE:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch: @ 8217100
	.string "ALIZEE: Nous autres humains,\n"
	.string "nous ne pouvons pas échapper à la\l"
	.string "force de la gravité.\p"
	.string "Mais dans notre quête d'excellence,\n"
	.string "nous parvenons à nous élever!\p"
	.string "Tu as atteint les sommets en\n"
	.string "devenant le MAITRE.\p"
	.string "S'il te plaît, laisse-moi voir\n"
	.string "l'étendue de ta puissance!$"

FortreeCity_Gym_Text_WinonaRematchDefeat: @ 82171E6
	.string "J'ai encore échoué… Je n'ai pas\n"
	.string "pu atteindre ton niveau…$"

FortreeCity_Gym_Text_WinonaPostRematch: @ 821720B
	.string "ALIZEE: Même dans la défaite, les ailes\n"
	.string "de mon cœur restent déployées.\p"
	.string "Je pourrai m'élever encore et toujours.\p"
	.string "J'en suis convaincue!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons: @ 8217292
	.string "ALIZEE: Nous autres humains,\n"
	.string "nous ne pouvons pas échapper à la\n"
	.string "force de la gravité.\p"
	.string "Mais dans notre quête d'excellence,\n"
	.string "nous parvenons à nous élever!\p"
	.string "Tu as atteint les sommets en\n"
	.string "devenant le MAITRE.\p"
	.string "S'il te plaît, laisse-moi voir l'étendue\n"
	.string "de ta puissance!\p"
	.string "Oh, non, tu n'as qu'un POKéMON\n"
	.string "avec toi?\p"
	.string "S'il te plaît, reviens me voir avec au\n"
	.string "moins deux POKéMON.$"
