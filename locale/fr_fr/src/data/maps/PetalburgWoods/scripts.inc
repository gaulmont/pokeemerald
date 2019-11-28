PetalburgWoods_MapScripts:: @ 822DFD6
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft:: @ 822DFD7
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement 4, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_AQA_0, 0
	applymovement 3, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement 3, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement 4, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement 3, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_8, PetalburgWoods_Text_YoureKiddingMe
	applymovement 3, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement 4, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight:: @ 822E079
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement 4, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_AQA_0, 0
	applymovement 3, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement 3, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement 4, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_8, PetalburgWoods_Text_YoureKiddingMe
	applymovement 3, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement 4, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro:: @ 822E124
	applymovement 4, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle:: @ 822E138
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement 3, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject 3
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem_std ITEM_GREAT_BALL
	compare VAR_RESULT, 0
	goto_if_eq PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull:: @ 822E17D
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish:: @ 822E18B
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement 4, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher:: @ 822E1A7
	removeobject 4
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround: @ 822E1B1
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft: @ 822E1C2
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft: @ 822E1CB
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight: @ 822E1D0
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight: @ 822E1D7
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave: @ 822E1E0
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft: @ 822E1E4
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight: @ 822E1EA
	walk_fast_down
	walk_fast_right
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit: @ 822E1EE
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft: @ 822E1F6
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff: @ 822E1F9
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway: @ 822E1FD
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight: @ 822E205
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance: @ 822E209
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer: @ 822E20E
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1:: @ 822E210
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2:: @ 822E219
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl:: @ 822E222
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem_std ITEM_MIRACLE_SEED
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed:: @ 822E251
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1:: @ 822E25B
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2:: @ 822E264
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle:: @ 822E26D
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James:: @ 822E284
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames:: @ 822E2C5
	special sub_80B4808
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames:: @ 822E2D6
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2:: @ 822E2EF
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2:: @ 822E302
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch:: @ 822E31B
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound: @ 822E332
	.string "Humm…\n"
	.string "Rien du tout…$"

PetalburgWoods_Text_HaveYouSeenShroomish: @ 822E34F
	.string "Salut! T'aurais pas vu un POKéMON\n"
	.string "appelé BALIGNON dans le coin?\p"
	.string "J'aime beaucoup ce POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou: @ 822E3AA
	.string "Je voulais te piéger, mais ça fait\n"
	.string "une éternité que tu traînes dans le\l"
	.string "BOIS CLEMENTI?\p"
	.string "Ras l'bol d'attendre! Alors me voilà!$"

PetalburgWoods_Text_HandOverThosePapers: @ 822E428
	.string "Toi! Le CHERCHEUR DE DEVON!\p"
	.string "Donne-moi ces papiers!$"

PetalburgWoods_Text_YouHaveToHelpMe: @ 822E457
	.string "Oh, hé!\p"
	.string "Tu es un DRESSEUR de POKéMON, non?\n"
	.string "Il faut que tu m'aides. S'il te plaît!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua: @ 822E4A5
	.string "Hum? Tu penses faire quoi?\n"
	.string "Comment! Tu vas le défendre?\p"
	.string "La TEAM AQUA n'a jamais de pitié pour\n"
	.string "ses ennemis. Pas même pour un enfant!\p"
	.string "Viens te battre!$"

PetalburgWoods_Text_YoureKiddingMe: @ 822E542
	.string "Tu m'as bluffé! Quelle force!$"

PetalburgWoods_Text_YouveGotSomeNerve: @ 822E563
	.string "Grrr… Tu as eu le culot de t'opposer\n"
	.string "à la TEAM AQUA!\l"
	.string "Viens et affronte-moi de nouveau!\p"
	.string "C'est ce que j'aurais aimé te dire,\n"
	.string "mais je suis à court de POKéMON…\p"
	.string "Et en plus, nous, la TEAM AQUA, on a\n"
	.string "quelque chose à faire à MEROUVILLE.\p"
	.string "Ça va pour aujourd'hui. J'te laisse\n"
	.string "filer!$"

PetalburgWoods_Text_ThatWasAwfullyClose: @ 822E63D
	.string "Ouf…\n"
	.string "Il s'en est fallu de peu!\p"
	.string "Grâce à toi, il ne m'a pas volé ces\n"
	.string "importants papiers.\p"
	.string "Je sais! Pour te remercier, je vais te\n"
	.string "donner cette SUPER BALL.$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro: @ 822E6C7
	.string "Cette brute de la TEAM AQUA n'a-t-elle\n"
	.string "pas dit qu'ils avaient quelque chose à\l"
	.string "faire à MEROUVILLE?$"

PetalburgWoods_Text_ICantBeWastingTime: @ 822E712
	.string "Oh là là! C'est une catastrophe!\n"
	.string "Je n'ai pas de temps à perdre!$"

PetalburgWoods_Text_YoureLoadedWithItems: @ 822E741
	.string "Tu croules sous les objets. Je ne peux\n"
	.string "pas te donner cette SUPER BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam: @ 822E77D
	.string "J'ai attrapé tout un tas de POKéMON!\p"
	.string "Allez, allez, allez!\n"
	.string "Mon équipe de POKéMON INSECTE!$"

PetalburgWoods_Text_ICouldntWin: @ 822E7C1
	.string "J'avais tous ces POKéMON et\n"
	.string "je n'ai même pas gagné…$"

PetalburgWoods_Text_ImOutOfPokeBalls: @ 822E7EF
	.string "J'ai attrapé tout un tas de POKéMON.\n"
	.string "Maintenant, je n'ai plus de POKé BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon: @ 822E827
	.string "Si t'emmènes des POKéMON INSECTE à\n"
	.string "l'école, t'es tout de suite populaire!$"

PetalburgWoods_Text_CantBePopularIfILose: @ 822E86B
	.string "Je n'peux pas être populaire\n"
	.string "si je perds.$"

PetalburgWoods_Text_PeopleRespectYou: @ 822E889
	.string "Quand tu as un gros POKéMON INSECTE,\n"
	.string "les gens te respectent.$"

PetalburgWoods_Text_IWantRematch1: @ 822E8C3
	.string "J'aurai ma revanche dès que mes\n"
	.string "POKéMON INSECTE auront grandi!\p"
	.string "Je vais t'enregistrer dans mon POKéNAV!$"

PetalburgWoods_Text_IWantRematch2: @ 822E914
	.string "J'aurai ma revanche dès que mes\n"
	.string "POKéMON INSECTE auront grandi!\p"
	.string "Je vais t'enregistrer dans mon POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown: @ 822E966
	.string "Mon POKéMON INSECTE a grandi.\n"
	.string "Je vais redevenir populaire.$"

PetalburgWoods_Text_CantBePopularIfLose: @ 822E998
	.string "Je n'peux pas être populaire\n"
	.string "si je perds.$"

PetalburgWoods_Text_IveBeenTrainingHard: @ 822E9B6
	.string "On devient populaire quand on a des\n"
	.string "POKéMON puissants, pas vrai?\p"
	.string "Alors je m'entraîne dur.$"

PetalburgWoods_Text_StayOutOfTallGrass: @ 822EA0C
	.string "Yo, là!\n"
	.string "Ça baigne pour tes POKéMON?\p"
	.string "Si tes POKéMON sont faibles et que tu\n"
	.string "ne veux pas te battre, il vaut mieux ne\l"
	.string "pas t'attarder dans les hautes herbes.$"

PetalburgWoods_Text_HiddenItemsExplanation: @ 822EA8B
	.string "Parfois, il y a des choses par terre\n"
	.string "qu'on ne peut même pas voir.\p"
	.string "C'est pour ça que je fais toujours\n"
	.string "attention où je marche.$"

PetalburgWoods_Text_TryUsingThisItem: @ 822EAFE
	.string "Oh, génial! C'est le BADGE de l'ARENE de\n"
	.string "MEROUVILLE!\p"
	.string "Tu dois être DRESSEUR.\n"
	.string "Tu devrais essayer d'utiliser cet objet.$"

PetalburgWoods_Text_MiracleSeedExplanation: @ 822EB63
	.string "C'est un GRAIN MIRACL.\n"
	.string "Lorsqu'un POKéMON tient cet objet, ses\l"
	.string "attaques PLANTE sont plus puissantes.\p"
	.string "Mais il existe d'autres objets tout\n"
	.string "aussi pratiques, que les POKéMON\l"
	.string "peuvent porter.$"

PetalburgWoods_Text_TrainerTipsExperience: @ 822EC10
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Tout POKéMON apparaissant au combat,\n"
	.string "même une fois, reçoit des points EXP.\p"
	.string "Pour augmenter le niveau d'un POKéMON,\n"
	.string "il faut le placer en tête de liste.\p"
	.string "Dès le début du combat, échangez-le.\n"
	.string "Il recevra ainsi des points EXP sans\l"
	.string "prendre le moindre risque.$"

PetalburgWoods_Text_TrainerTipsPP: @ 822ED07
	.string "CONSEILS AUX DRESSEURS\p"
	.string "En plus des POINTS DE VIE (PV), les\n"
	.string "POKéMON ont des POINTS DE POUVOIR (PP)\l"
	.string "pour utiliser les capacités au combat.\p"
	.string "Si un POKéMON n'a plus de PP, il faut\n"
	.string "l'emmener dans un CENTRE POKéMON.$"

