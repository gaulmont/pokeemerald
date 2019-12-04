MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan:: @ 828E066
	special ScrSpecial_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard:: @ 828E0A6
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong:: @ 828E0C7
	setvar VAR_0x8004, 0
	special ScrSpecial_PlayBardSong
	delay 60
	special ScrSpecial_HasBardSongBeenChanged
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong:: @ 828E0EA
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics:: @ 828E0F4
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics:: @ 828E113
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special ScrSpecial_PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special ScrSpecial_SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics:: @ 828E15D
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster:: @ 828E167
	lock
	faceplayer
	setflag FLAG_SYS_HIPSTER_MEET
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special ScrSpecial_GetHipsterSpokenFlag
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord:: @ 828E18C
	special ScrSpecial_HipsterTeachWord
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord:: @ 828E1A4
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
	special ScrSpecial_SetHipsterSpokenFlag
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor: @ 828E1B1
	.string "Salut, je suis le BROCANTEUR. Tu veux\n"
	.string "échanger des décorations avec moi?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues: @ 828E1E8
	.string "Oh…\n"
	.string "Je me sens rejeté…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded: @ 828E20E
	.string "Mais, nous avons déjà échangé des\n"
	.string "décorations, toi et moi.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem: @ 828E23F
	.string "Si tu veux un objet décoratif que j'ai,\n"
	.string "n'hésite pas à me le demander.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything: @ 828E27F
	.string "Tu ne veux rien?\n"
	.string "Bouh, je n'intéresse personne…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt: @ 828E2A9
	.string "A l'époque, cette décoration\n"
	.string "appartenait à {STR_VAR_1}.\p"
	.string "Tu la veux?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor: @ 828E2E3
	.string "Hé… Une minute! Tu ne possèdes aucune\n"
	.string "décoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade: @ 828E323
	.string "Très bien, choisis la décoration que tu\n"
	.string "veux échanger avec moi.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade: @ 828E356
	.string "Tu ne veux rien échanger avec moi?\n"
	.string "Bouh, je me sens rejeté…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis: @ 828E380
	.string "Tu as déjà tous les objets de cette\n"
	.string "catégorie. Tu n'as plus de place.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor: @ 828E3C4
	.string "Alors, on échange {STR_VAR_3}\n"
	.string "contre {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse: @ 828E3EC
	.string "Tu utilises déjà cette décoration.\n"
	.string "Tu ne peux pas l'échanger.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC: @ 828E424
	.string "Dans ce cas, faisons l'échange!\n"
	.string "J'enverrai ma décoration dans ton PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne: @ 828E45A
	.string "Ah non, pas cet objet!\p"
	.string "C'est une décoration vraiment rare.\n"
	.string "Je ne peux pas te l'échanger!\p"
	.string "Il n'y a rien d'autre qui t'intéresse?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader:: @ 828E4D4
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special ScrSpecial_GetTraderTradedFlag
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade:: @ 828E503
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded:: @ 828E50D
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive:: @ 828E517
	special ScrSpecial_TraderMenuGetDecoration
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	compare VAR_0x8004, 0xFFFF
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special ScrSpecial_DoesPlayerHaveNoDecorations
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor:: @ 828E558
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor:: @ 828E562
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor:: @ 828E56E
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor:: @ 828E57A
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive:: @ 828E584
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special ScrSpecial_TraderMenuGiveDecoration
	waitstate
	compare VAR_0x8006, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	compare VAR_0x8006, 0xFFFF
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special ScrSpecial_IsDecorationFull
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special ScrSpecial_TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor:: @ 828E5D4
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse:: @ 828E5DE
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor:: @ 828E5EC
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale: @ 828E5F6
	.string "Je suis le CONTEUR.\n"
	.string "Je peux te raconter l'histoire de\l"
	.string "DRESSEURS légendaires.\p"
	.string "Alors, tu veux écouter mon histoire?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues: @ 828E64D
	.string "Oh…\n"
	.string "Je me sens frustré…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell: @ 828E673
	.string "J'en connais, des légendes.\n"
	.string "Quelle histoire veux-tu que je raconte?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales: @ 828E6AE
	.string "Mais je ne connais aucun DRESSEUR\n"
	.string "légendaire. Donc, pas d'histoire.\p"
	.string "Où peut-on trouver un DRESSEUR digne\n"
	.string "d'entrer dans la légende?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes: @ 828E726
	.string "De quoi?!?\n"
	.string "Toi… Tu as…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} fois?!?\p"
	.string "Mais c'est formidable! C'est la\n"
	.string "naissance d'une nouvelle légende!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends: @ 828E78A
	.string "Mais j'y pense, il y a peut-être encore\n"
	.string "d'autres DRESSEURS à découvrir, avec\l"
	.string "des légendes plus impressionnantes?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales: @ 828E7EE
	.string "Et toi, tu es DRESSEUR?\p"
	.string "Alors dis-moi, as-tu des histoires à me\n"
	.string "raconter, même vaguement légendaires?$"

MauvilleCity_PokemonCenter_1F_Text_28E844: @ 828E844
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend: @ 828E881
	.string "Hum…\n"
	.string "Je suis un peu déçu…\p"
	.string "J'aurais aimé que tu me racontes une\n"
	.string "histoire digne d'être appelée légende.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested: @ 828E8D9
	.string "J'aimerais bien que plus de gens\n"
	.string "s'intéressent à mes épiques sagas de\l"
	.string "DRESSEURS légendaires.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle:: @ 828E930
	.string "Le DRESSEUR à la sauvegarde facile$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction:: @ 828E947
	.string "sauvegardé la partie$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory:: @ 828E956
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a sauvegardé sa partie\n"
	.string "{STR_VAR_1} fois!\p"
	.string "Impossible de trouver un DRESSEUR plus\n"
	.string "prudent que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle:: @ 828E9D7
	.string "Le DRESSEUR qui lançait des modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction:: @ 828E9EF
	.string "lancé des modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory:: @ 828E9FE
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a lancé de nouvelles modes\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} lance des modes dans toute\n"
	.string "la région de HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle:: @ 828EA7D
	.string "Le DRESSEUR qui plantait des BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction:: @ 828EA98
	.string "planté des BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory:: @ 828EAA8
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a planté\n"
	.string "{STR_VAR_1} BAIES!\p"
	.string "{STR_VAR_3} est connu pour être un\n"
	.string "grand amateur de BAIES!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle:: @ 828EB19
	.string "Le DRESSEUR fan de VELOS$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction:: @ 828EB31
	.string "changé de VELO$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory:: @ 828EB3E
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a changé de VELO\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit aimer les VELOS à\n"
	.string "la folie!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle:: @ 828EBB5
	.string "Le DRESSEUR interviewé$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction:: @ 828EBCD
	.string "répondu à une interview$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory:: @ 828EBDD
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a été interviewé\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est vraiment un DRESSEUR\n"
	.string "très médiatisé!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle:: @ 828EC60
	.string "Le DRESSEUR combattant$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction:: @ 828EC79
	.string "combattu$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory:: @ 828EC81
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a combattu {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui ne rate\n"
	.string "pas une occasion de se battre!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle:: @ 828ED04
	.string "Le DRESSEUR chasseur de POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction:: @ 828ED21
	.string "attrapé des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory:: @ 828ED30
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a attrapé\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} est un chasseur de POKéMON\n"
	.string "sauvages légendaire!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle:: @ 828EDA1
	.string "Le DRESSEUR pêcheur$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction:: @ 828EDB5
	.string "attrapé des POKéMON avec une CANNE$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory:: @ 828EDCF
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a attrapé\n"
	.string "{STR_VAR_1} POKéMON en les pêchant!\p"
	.string "{STR_VAR_3} est un pêcheur légendaire!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle:: @ 828EE45
	.string "Le DRESSEUR qui couvait des OEUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction:: @ 828EE5D
	.string "fait éclore des OEUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory:: @ 828EE6A
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait éclore {STR_VAR_1}\n"
	.string "OEUF(S) de POKéMON!\p"
	.string "{STR_VAR_3} s'occupe formidablement\n"
	.string "bien des OEUFS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle:: @ 828EEDD
	.string "Le DRESSEUR aux POKéMON évolués$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction:: @ 828EEF1
	.string "fait évoluer des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory:: @ 828EF01
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait évoluer {STR_VAR_1}\n"
	.string "POKéMON!\p"
	.string "{STR_VAR_3} est un pro de l'évolution\n"
	.string "des POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle:: @ 828EF73
	.string "Le DRESSEUR fan de CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction:: @ 828EF95
	.string "utilisé des CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory:: @ 828EFAA
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a soigné des\n"
	.string "POKéMON {STR_VAR_1} fois dans des\l"
	.string "CENTRES POKéMON!\p"
	.string "Il n'existe pas de plus grand fan de\n"
	.string "CENTRES POKéMON que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle:: @ 828F045
	.string "Le DRESSEUR casanier$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction:: @ 828F05A
	.string "soigné des POKéMON à la maison$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory:: @ 828F071
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a soigné ses POKéMON\n"
	.string "à la maison {STR_VAR_1} fois!\p"
	.string "Il n'existe pas de DRESSEUR plus\n"
	.string "casanier que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle:: @ 828F0F3
	.string "Le DRESSEUR fan de SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction:: @ 828F10D
	.string "pénétré dans le PARC SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory:: @ 828F125
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR est entré dans le\n"
	.string "PARC SAFARI {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui exprime\n"
	.string "son côté sauvage au PARC SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle:: @ 828F1BE
	.string "Le DRESSEUR à la COUPE facile$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction:: @ 828F1D5
	.string "utilisé COUPE$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory:: @ 828F1DE
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé COUPE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui adore\n"
	.string "utiliser COUPE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle:: @ 828F24F
	.string "Le DRESSEUR ECLATE-ROC$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction:: @ 828F269
	.string "éclaté des rochers$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory:: @ 828F277
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé ECLATE-ROC\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui ne peut\n"
	.string "pas laisser un rocher entier!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle:: @ 828F2FC
	.string "Le DRESSEUR qui aime déménager$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction:: @ 828F314
	.string "déplacé ta BASE SECRETE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory:: @ 828F32A
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a déplacé sa BASE\n"
	.string "SECRETE {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui adore\n"
	.string "déménager!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle:: @ 828F3AD
	.string "Le DRESSEUR fou de TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction:: @ 828F3C6
	.string "utilisé TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory:: @ 828F3D2
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé TREMPETTE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui adore\n"
	.string "faire TREMPETTE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle:: @ 828F44B
	.string "Le DRESSEUR tenace$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction:: @ 828F461
	.string "fini par utiliser LUTTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory:: @ 828F47C
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a dû utiliser LUTTE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR tenace qui\n"
	.string "n'abandonne jamais face à l'adversité!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle:: @ 828F50C
	.string "Le champion des MACHINES A SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction:: @ 828F51B
	.string "eu le jackpot aux MACHINES A SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory:: @ 828F538
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné le jackpot aux\n"
	.string "MACHINES A SOUS {STR_VAR_1} fois.\p"
	.string "{STR_VAR_3} est un DRESSEUR qui a eu de\n"
	.string "la chance aux MACHINES A SOUS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle:: @ 828F5BE
	.string "Le champion de la ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction:: @ 828F5D1
	.string "gagné consécutivement à la ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory:: @ 828F5F2
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné à la ROULETTE\n"
	.string "{STR_VAR_1} fois de suite.\p"
	.string "{STR_VAR_3} a eu beaucoup de chance\n"
	.string "à la ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle:: @ 828F678
	.string "Le candidat à la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction:: @ 828F694
	.string "relevé les défis de la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory:: @ 828F6B4
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a relevé les défis de la\n"
	.string "TOUR DE COMBAT {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR cherchant\n"
	.string "à être premier dans la TOUR DE COMBAT!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle:: @ 828F751
	.string "Le DRESSEUR qui aime mixer$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction:: @ 828F76A
	.string "fait des {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory:: @ 828F776
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait des {POKEBLOCK}S\n"
	.string "{STR_VAR_1} fois!\p"
	.string "Personne n'utilise un MIXEUR mieux\n"
	.string "que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle:: @ 828F7F6
	.string "Le DRESSEUR fan de CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction:: @ 828F811
	.string "participé à des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory:: @ 828F822
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a participé à des\n"
	.string "CONCOURS {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} adore exhiber ses\n"
	.string "POKéMON devant un public!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle:: @ 828F89C
	.string "Le maître des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction:: @ 828F8AF
	.string "gagné des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory:: @ 828F8BC
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné des CONCOURS\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être incroyablement\n"
	.string "doué pour les CONCOURS!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle:: @ 828F92F
	.string "Le joyeux consommateur$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction:: @ 828F941
	.string "acheté des objets$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory:: @ 828F949
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a acheté des objets\n"
	.string "dans un magasin {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être l'un de ces\n"
	.string "DRESSEURS nés pour faire des achats.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle:: @ 828F9D1
	.string "Le DRESSEUR chercheur d'objets$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction:: @ 828F9EA
	.string "utilisé un CHERCH'OBJET$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory:: @ 828F9FD
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé un CHERCH'OBJET\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit aimer sonder le sol\n"
	.string "pour trouver des objets cachés!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle:: @ 828FA81
	.string "Le DRESSEUR trempé jusqu'aux os$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction:: @ 828FA99
	.string "pris une averse$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory:: @ 828FAA7
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a été trempé jusqu'aux\n"
	.string "os par la pluie {STR_VAR_1} fois!\p"
	.string "Le charisme de {STR_VAR_3} doit même\n"
	.string "attirer la pluie!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle:: @ 828FB1D
	.string "Le lecteur de POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction:: @ 828FB35
	.string "vérifié ton POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory:: @ 828FB47
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a vérifié son POKéDEX\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit adorer en apprendre\n"
	.string "plus sur les POKéMON dans son POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle:: @ 828FBC4
	.string "Le collectionneur de RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction:: @ 828FBD9
	.string "reçu des RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory:: @ 828FBEA
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a reçu des RUBANS\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un DRESSEUR qui\n"
	.string "adore collectionner les RUBANS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle:: @ 828FC6B
	.string "Le DRESSEUR qui saute des talus$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction:: @ 828FC85
	.string "sauté des talus$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory:: @ 828FC98
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a sauté des talus\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} ne peut pas s'empêcher de\n"
	.string "sauter d'un talus!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle:: @ 828FD1D
	.string "Le téléspectateur légendaire$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction:: @ 828FD35
	.string "regardé la télé$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory:: @ 828FD40
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a regardé la télé\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit adorer regarder\n"
	.string "la télé!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle:: @ 828FDA2
	.string "Le DRESSEUR conscient du temps$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction:: @ 828FDBD
	.string "regardé l'heure$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory:: @ 828FDCE
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a regardé l'heure\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un DRESSEUR\n"
	.string "ponctuel, toujours conscient du temps.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle:: @ 828FE57
	.string "Le magicien de la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction:: @ 828FE72
	.string "gagné à la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory:: @ 828FE88
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné à la LOTERIE\n"
	.string "POKéMON {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit avoir de nombreux amis\n"
	.string "avec qui échanger des POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle:: @ 828FF0C
	.string "Le DRESSEUR client de la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction:: @ 828FF27
	.string "laissé des POKéMON à la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory:: @ 828FF44
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a laissé des POKéMON à\n"
	.string "la PENSION {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un vrai battant\n"
	.string "qui élève ses POKéMON avec énergie!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle:: @ 828FFDD
	.string "Le DRESSEUR fan du TELEPHERIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction:: @ 828FFFA
	.string "fait le trajet en TELEPHERIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory:: @ 829000D
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a pris le TELEPHERIQUE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un DRESSEUR\n"
	.string "surmené qui passe son temps à voyager!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle:: @ 8290097
	.string "Le DRESSEUR fan de sources chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction:: @ 82900B5
	.string "pris un bain dans les sources chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory:: @ 82900CB
	.string "Il était une fois un DRESSEUR du nom\n"
	.string "de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR s'est baigné dans les\n"
	.string "sources chaudes {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un DRESSEUR avec\n"
	.string "une peau de bébé!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller:: @ 829014A
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, ScrSpecial_StorytellerGetFreeStorySlot
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special ScrSpecial_StorytellerStoryListMenu
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special ScrSpecial_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, ScrSpecial_StorytellerUpdateStat
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection:: @ 82901B7
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales:: @ 82901BD
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, ScrSpecial_HasStorytellerAlreadyRecorded
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales:: @ 82901DA
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales:: @ 82901E2
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, ScrSpecial_StorytellerInitializeRandomStat
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale:: @ 829020F
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller:: @ 8290219
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix:: @ 8290223
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd:: @ 829022D
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory: @ 829022F
	.string "Je m'appelle PAPOTEUR!\n"
	.string "J'ai une super histoire à te raconter!\p"
	.string "Tu veux l'écouter?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues: @ 8290281
	.string "Oh…\n"
	.string "Tu m'as déprimé…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking: @ 82902A7
	.string "Et puis aussi, je me disais…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain: @ 82902BD
	.string "Eh bien, c'est tout, je pense…\p"
	.string "On discutera plus tard!\n"
	.string "Ciao!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy:: @ 82902F6
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale:: @ 8290317
	special ScrSpecial_GiddyShouldTellAnotherTale
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale:: @ 8290331
	special ScrSpecial_GiddyShouldTellAnotherTale
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale:: @ 829034B
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Regardless of whether yes or no is selected below, Giddy will continue to tell stories until he's told 10
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale:: @ 8290359
	special ScrSpecial_GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy:: @ 829037A
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales:: @ 8290384
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong: @ 829038E
	.string "Bonjour, je suis CAPELO.\n"
	.string "Tu veux entendre ma chanson?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1: @ 82903C0
	.string "Oh…\n"
	.string "Tu me files le blues…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers: @ 82903E6
	.string "Oh, quelle chanson émouvante… Je\n"
	.string "voudrais pouvoir la chanter aux autres.$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics: @ 8290421
	.string "Alors?\n"
	.string "Qu'est-ce que tu penses de ma chanson?\p"
	.string "Mais je ne suis pas très content des\n"
	.string "paroles.\p"
	.string "Ça te plairait d'écrire de nouvelles\n"
	.string "paroles pour moi?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2: @ 829049B
	.string "Oh…\n"
	.string "Tu me files le blues…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou: @ 82904C1
	.string "Merci beaucoup!\n"
	.string "Je vais la chanter pour toi.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo: @ 82904EB
	.string "Tu la voulais bien comme ça, ta chanson?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile: @ 8290514
	.string "Super! La chanson est finie, alors. Je\n"
	.string "vais la chanter pendant longtemps.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening: @ 829054C
	.string "Yo, toi! On m'appelle MINET.\n"
	.string "Je vais te montrer ce qui est à la mode.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou: @ 8290598
	.string "Hé, mais je t'ai déjà montré ce qui est\n"
	.string "à la mode en ce moment.\p"
	.string "Maintenant, j'aimerais prêcher la bonne\n"
	.string "parole aux autres.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach: @ 8290602
	.string "Mais, tu sais déjà ce qui est à la mode\n"
	.string "en ce moment.\p"
	.string "Je n'ai rien de nouveau à t'apprendre!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase: @ 8290666
	.string "Hé, t'as entendu parler de\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Qu'est-ce que ça veut dire? Heu…\n"
	.string "T'as qu'à demander à ta maman, OK?$"
