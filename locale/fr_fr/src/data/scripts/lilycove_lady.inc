LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady:: @ 82A836B
    special Script_GetLilycoveLadyId
    switch VAR_RESULT
    case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
    case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
    case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
    end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLady:: @ 82A8395
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetFavorLadyState
    compare VAR_RESULT, LILYCOVE_LADY_STATE_READY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
    compare VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
    compare VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted:: @ 82A83C6
    msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady:: @ 82A83D0
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
    specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem:: @ 82A83F7
    special BufferFavorLadyItemName
    special BufferFavorLadyPlayerName
    specialvar VAR_RESULT, DidFavorLadyLikeItem
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
    end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing:: @ 82A8419
    msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing:: @ 82A8427
    msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_RequestItem:: @ 82A8435
    msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
    end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor:: @ 82A8454
    msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor:: @ 82A845E
    msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem:: @ 82A846C
    fadescreen 1
    setvar VAR_RESULT, 0
    special Script_FavorLadyOpenBagMenu
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem:: @ 82A848E
    msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem:: @ 82A84AD
    specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem:: @ 82A84C9
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem:: @ 82A84D6
    specialvar VAR_RESULT, IsFavorLadyThresholdMet
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
    end

LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem:: @ 82A84F2
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem:: @ 82A84FF
    special BufferFavorLadyRequest
    msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize:: @ 82A8510
    setvar VAR_0x8004, 0
    specialvar VAR_0x8004, FavorLadyGetPrize
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
    giveitem_std VAR_0x8004
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize:: @ 82A8545
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize:: @ 82A854F
    special SetFavorLadyState_Complete
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_QuizLady:: @ 82A8554
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetQuizLadyState
    compare VAR_RESULT, LILYCOVE_LADY_STATE_READY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
    compare VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
    compare VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz:: @ 82A8585
    specialvar VAR_RESULT, GetQuizAuthor
    compare VAR_RESULT, QUIZ_AUTHOR_PLAYER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
    compare VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
    compare VAR_RESULT, QUIZ_AUTHOR_LADY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
    end

LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz:: @ 82A85AC
    specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz:: @ 82A85C8
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady:: @ 82A85D2
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady:: @ 82A85E0
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz:: @ 82A85EE
    setvar VAR_0x8004, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz:: @ 82A8612
    msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz:: @ 82A861C
    special ClearQuizLadyPlayerAnswer
    compare VAR_0x8004, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
    compare VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer

LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState:: @ 82A8635
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
    end

LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion:: @ 82A864C
    special QuizLadyShowQuizQuestion
    waitstate
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
    end

LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer:: @ 82A8656
    special QuizLadyGetPlayerAnswer
    waitstate
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz:: @ 82A8660
    msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz:: @ 82A867F
    msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse:: @ 82A8689
    special SetQuizLadyState_Complete
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
    specialvar VAR_RESULT, IsQuizAnswerCorrect
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
    end

LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse:: @ 82A86B0
    playse SE_SEIKAI
    delay 10
    playse SE_SEIKAI
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse:: @ 82A86C7
    special BufferQuizCorrectAnswer
    special BufferQuizPrizeName
    playse SE_HAZURE
    delay 10
    playse SE_HAZURE
    msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
    msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
    end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize:: @ 82A86EC
    specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1:: @ 82A8708
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0:: @ 82A8716
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize:: @ 82A8724
    setvar VAR_0x8005, 0
    special BufferQuizPrizeItem
    special SetQuizLadyState_Complete
    giveitem_std VAR_0x8005
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize:: @ 82A874C
    msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
    special SetQuizLadyState_GivePrize
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz:: @ 82A8759
    msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz:: @ 82A8778
    special QuizLadyPickNewQuestion
    msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz:: @ 82A8785
    msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize:: @ 82A878D
    fadescreen 1
    setvar VAR_RESULT, 0
    special Script_QuizLadyOpenBagMenu
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize:: @ 82A87AF
    msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
    end

LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz:: @ 82A87CE
    msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
    special ClearQuizLadyQuestionAndAnswer
    special ClearQuizLadyPlayerAnswer
    setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion:: @ 82A87E1
    fadescreen 1
    special QuizLadySetCustomQuestion
    waitstate
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
    goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion:: @ 82A87F8
    msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
    end

LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz:: @ 82A8817
    special QuizLadyTakePrizeForCustomQuiz
    special QuizLadyRecordCustomQuizData
    special QuizLadySetWaitingForChallenger
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLady:: @ 82A882A
    lock
    faceplayer
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
    specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
    end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock:: @ 82A8850
    specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock:: @ 82A886C
    msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock:: @ 82A8876
    special Script_BufferContestLadyCategoryAndMonName
    msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
    checkitem ITEM_POKEBLOCK_CASE, 1
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
    msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock:: @ 82A88B0
    msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock:: @ 82A88BA
    fadescreen 1
    special OpenPokeblockCaseForContestLady
    waitstate
    compare VAR_RESULT, 0xFFFF
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
    compare VAR_RESULT, 0xFFFF
    goto_if_ne LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock:: @ 82A88D7
    msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
    compare VAR_RESULT, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock:: @ 82A88F6
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
    special SetContestLadyGivenPokeblock
    special GetContestLadyMonSpecies
    goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
    end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock:: @ 82A890A
    applymovement 4, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
    waitmovement 0
    delay 60
    applymovement 5, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
    waitmovement 0
    delay 60
    waitse
    playmoncry VAR_0x8005, 0
    delay 120
    waitmoncry
    compare VAR_0x8004, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
    goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
    end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock:: @ 82A893F
    applymovement 5, LilycoveCity_PokemonCenter_1F_Movement_MonJump
    waitmovement 0
    delay 60
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock:: @ 82A894C
    applymovement 4, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
    waitmovement 0
    delay 60
    compare VAR_0x8004, 0
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
    compare VAR_0x8004, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
    end

LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock:: @ 82A8970
    msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
    end

LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock:: @ 82A897E
    special Script_BufferContestLadyCategoryAndMonName
    msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
    end

LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow:: @ 82A898F
    specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
    compare VAR_RESULT, 1
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow:: @ 82A89A1
    msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
    special PutLilycoveContestLadyShowOnTheAir
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase:: @ 82A89AE
    msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
    release
    end

LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon: @ 82A89B8
    face_right
    delay_8
    step_end

LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady: @ 82A89BB
    face_left
    delay_8
    step_end

@ Unused
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown: @ 82A89BE
    face_down
    step_end

LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer: @ 82A89C0
    face_player
    step_end

LilycoveCity_PokemonCenter_1F_Movement_MonJump: @ 82A89C2
    disable_jump_landing_ground_effect
    jump_in_place_left
    disable_jump_landing_ground_effect
    jump_in_place_left
    step_end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon:: @ 82A89C7
    specialvar VAR_RESULT, GetContestLadyCategory
    special Script_BufferContestLadyCategoryAndMonName
    special GetContestLadyMonSpecies
    compare VAR_RESULT, CONTEST_CATEGORY_COOL
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
    compare VAR_RESULT, CONTEST_CATEGORY_BEAUTY
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Skitty
    compare VAR_RESULT, CONTEST_CATEGORY_CUTE
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
    compare VAR_RESULT, CONTEST_CATEGORY_SMART
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
    compare VAR_RESULT, CONTEST_CATEGORY_TOUGH
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
    end

LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon:: @ 82A8A0A
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_Skitty:: @ 82A8A1D
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_Poochyena:: @ 82A8A30
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_Kecleon:: @ 82A8A43
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_EventScript_Pikachu:: @ 82A8A56
    lock
    faceplayer
    waitse
    playmoncry VAR_0x8005, 0
    msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
    waitmoncry
    release
    end

LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady: @ 82A8A69
	.string "Je suis DAME FAVEUR…$"

LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing: @ 82A8A7D
	.string "Depuis quelque temps, je me passionne\n"
	.string "pour tout ce qui est {STR_VAR_1}…$"

LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime: @ 82A8AB1
	.string "Oh…\n"
	.string "Merci pour la dernière fois…$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing: @ 82A8ACE
	.string "Je crois que c'était {STR_VAR_3}…\p"
	.string "{STR_VAR_3} m'a donné l'objet\n"
	.string "{STR_VAR_2}, soi-disant {STR_VAR_1}…\p"
	.string "Mais ce n'était pas {STR_VAR_1}.\n"
	.string "Pas du tout.$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing: @ 82A8B36
	.string "Tout à l'heure, {STR_VAR_3} m'a donné\n"
	.string "l'objet {STR_VAR_2}, qui est\l"
	.string "{STR_VAR_1}.\p"
	.string "Je le garde précieusement.$"

LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing: @ 82A8B69
	.string "Dis, tu as un objet {STR_VAR_1}\n"
	.string "à me donner?$"

LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe: @ 82A8BAD
	.string "Ah, oui?\n"
	.string "C'est quoi?$"

LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye: @ 82A8BCD
	.string "Puisque tu le prends comme ça,\n"
	.string "je te dis au revoir.$"

LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare: @ 82A8BEE
	.string "Oh…\n"
	.string "Tu veux le garder?$"

LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt: @ 82A8C0F
	.string "{STR_VAR_2}?\n"
	.string "Est-ce que cet objet est {STR_VAR_1}?\p"
	.string "Oh… Vraiment?\p"
	.string "Quoi qu'il en soit, je te remercie de\n"
	.string "ce cadeau…$"

LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis: @ 82A8C6F
	.string "{STR_VAR_2}…\p"
	.string "Cet objet est plutôt\n"
	.string "{STR_VAR_1}…\p"
	.string "Il n'est pas mal du tout.\n"
	.string "Je l'aime bien…\p"
	.string "Merci…\n"
	.string "Je le garderai précieusement…$"

LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis: @ 82A8CC8
	.string "Oh… {STR_VAR_2}…\p"
	.string "C'est magnifique!\n"
	.string "C'est vraiment {STR_VAR_1}!\p"
	.string "Je ne savais pas que cet objet\n"
	.string "pouvait être si {STR_VAR_1}!\p"
	.string "Merci!\n"
	.string "Je ne m'en séparerai jamais!$"

LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn: @ 82A8D5D
	.string "Pour te remercier, je te donne\n"
	.string "ce fabuleux objet.\p"
	.string "J'espère qu'il te plaît…$"

LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt: @ 82A8DBD
	.string "Oh, tu n'as malheureusement pas de\n"
	.string "place pour cet objet.\p"
	.string "Reviens me voir quand tu auras fait de\n"
	.string "la place dans ton SAC…$"

LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady: @ 82A8E2B
	.string "Je suis DAME QUIZ!\n"
	.string "J'adore les quiz!$"

LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz: @ 82A8E4E
	.string "Oh?\p"
	.string "J'attends que quelqu'un vienne jouer\n"
	.string "au quiz que tu as fait.\p"
	.string "On discutera une autre fois, d'accord?$"

LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger: @ 82A8EAC
	.string "J'attends que quelqu'un vienne jouer\n"
	.string "au quiz réalisé par {STR_VAR_1}!$"

LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge: @ 82A8EEC
	.string "Pour le gagnant, il y a de fabuleux\n"
	.string "prix à la clé!\p"
	.string "Tu veux essayer de répondre aux\n"
	.string "questions du quiz?$"

LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer: @ 82A8F4D
    .string "… … … … … …\n"
    .string "… … … … … …$"

LilycoveCity_PokemonCenter_1F_Text_HowBoringBye: @ 82A8F65
	.string "Oh, que c'est ennuyeux!\n"
	.string "Au revoir!$"

LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit: @ 82A8F7E
	.string "Oh!\n"
	.string "Tu veux arrêter?$"

LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime: @ 82A8F9A
	.string "Tu essaieras de répondre aux questions\n"
	.string "du quiz une autre fois, d'accord!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRight: @ 82A8FC7
	.string "Incroyable, tu as répondu juste!\n"
	.string "Tu dois en savoir des choses!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize: @ 82A9007
	.string "Félicitations! Tu as répondu\n"
	.string "correctement au quiz.\p"
	.string "Tu as remporté le prix prévu par\n"
	.string "{STR_VAR_1}!$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY: @ 82A9056
    .string "{STR_VAR_1} received\n"
    .string "one {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp: @ 82A906A
	.string "Oh, ton SAC est plein.\p"
	.string "Fais de la place dans ton SAC et\n"
	.string "reviens me voir.$"

LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs: @ 82A90A5
	.string "Hum… Mauvaise réponse!\n"
	.string "Il fallait répondre “{STR_VAR_3}”!$"

LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize: @ 82A90CD
	.string "Quel dommage!\p"
	.string "Je vais devoir garder le prix\n"
	.string "{STR_VAR_1}!$"

LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz: @ 82A90FB
	.string "Ecoute, écoute!\n"
	.string "Ça te dirait, de créer ton propre quiz?$"

LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime: @ 82A9131
	.string "Je vois…\n"
	.string "Une prochaine fois, peut-être!$"

LilycoveCity_PokemonCenter_1F_Text_PickYourPrize: @ 82A9153
	.string "Bien. D'abord, tu dois choisir le prix\n"
	.string "à remettre au concurrent s'il répond\l"
	.string "correctement à toutes les questions.\p"
	.string "Mais, attention! Si le concurrent\n"
	.string "échoue, c'est moi qui garde\l"
	.string "le prix!$"

LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize: @ 82A9212
	.string "Si tu ne choisis pas de prix, tu ne\n"
	.string "peux pas créer de quiz.\p"
	.string "Tu veux arrêter la création de ton\n"
	.string "quiz?$"

LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz: @ 82A9270
	.string "Très joli!\n"
	.string "C'est un prix magnifique!\p"
	.string "Maintenant, tu dois choisir les\n"
	.string "questions et les réponses.$"

LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion: @ 82A92D3
	.string "Tu veux arrêter d'écrire les questions\n"
	.string "de ton quiz?$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer: @ 82A9305
    .string "Are you going to quit choosing\n"
    .string "your quiz answer?$"

LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger: @ 82A9336
	.string "Merci!\n"
	.string "Tu as fait un bon quiz.\p"
	.string "A moi de trouver une personne qui va\n"
	.string "essayer de répondre aux questions!$"

LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady: @ 82A93A7
	.string "Je suis DAME CONCOURS!\n"
	.string "J'adore les CONCOURS!$"

LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock: @ 82A93D6
	.string "Encore merci pour le {POKEBLOCK}!$"

LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality: @ 82A93F4
	.string "Voilà {STR_VAR_1}!\n"
	.string "On pourrait l'appeler {STR_VAR_2}!\p"
	.string "Mais je pense qu'il pourrait encore\n"
	.string "gagner en {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase: @ 82A9451
	.string "Pour cela, j'ai besoin de ton aide!\p"
	.string "Pourrais-je avoir un {POKEBLOCK}?\n"
	.string "Je ne t'en demande qu'un!\p"
	.string "… Oh, mais…\n"
	.string "Tu n'as pas de BOITE {POKEBLOCK}S?\l"
	.string "Tu devrais. A la prochaine, alors!$"

LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock: @ 82A94E8
	.string "J'ai besoin de ton aide!\p"
	.string "Pourrais-je avoir un {POKEBLOCK}?\n"
	.string "Rien qu'un seul!$"

LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock: @ 82A9537
	.string "Comment?\n"
	.string "Tu refuses de me donner un {POKEBLOCK}?$"

LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate: @ 82A9556
	.string "L'avarice est un vilain défaut,\n"
	.string "tu sais!?!$"

LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock: @ 82A9571
	.string "Super!\n"
	.string "Merci!\p"
	.string "Je vais donner ton {POKEBLOCK} à mon\n"
	.string "POKéMON immédiatement.$"

LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks: @ 82A95AD
	.string "On dirait que rien n'a changé…\p"
	.string "Hum…\p"
	.string "Bon!\n"
	.string "Merci quand même!$"

LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks: @ 82A9605
	.string "Oh!\n"
	.string "On dirait que ça lui plaît!\p"
	.string "Je pense que {STR_VAR_1} a gagné en\n"
	.string "{STR_VAR_2}.\p"
	.string "Merci beaucoup!$"

LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests: @ 82A9669
	.string "Hum…\p"
	.string "Je pense qu'on est prêts à faire des\n"
	.string "CONCOURS.\p"
	.string "Si tu nous vois en CONCOURS un jour,\n"
	.string "j'espère que tu nous encourageras.$"

LilycoveCity_PokemonCenter_1F_Text_Zigzagoon: @ 82A96DA
	.string "{STR_VAR_1}: Zaaaton!$"

LilycoveCity_PokemonCenter_1F_Text_Kecleon: @ 82A96E6
	.string "{STR_VAR_1}: Kecleeee!$"

LilycoveCity_PokemonCenter_1F_Text_Poochyena: @ 82A96F6
	.string "{STR_VAR_1}: Yenaaa…$"

LilycoveCity_PokemonCenter_1F_Text_Pikachu: @ 82A9703
	.string "{STR_VAR_1}: Pika!$"

LilycoveCity_PokemonCenter_1F_Text_Skitty: @ 82A970E
	.string "{STR_VAR_1}: Skiiittyyy!$"
