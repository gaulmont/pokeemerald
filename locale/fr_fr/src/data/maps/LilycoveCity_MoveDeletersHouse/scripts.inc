LilycoveCity_MoveDeletersHouse_MapScripts:: @ 821EA0A
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter:: @ 821EA0B
	lockall
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case 1, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case 0, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget:: @ 821EA3B
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen 1
	special MoveDeleterChooseMoveToForget
	fadescreen 0
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case 1, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case 0, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove:: @ 821EAB0
	special IsLastMonThatKnowsSurf
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_ME_WASURE
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove:: @ 821EACF
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves:: @ 821EADC
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain:: @ 821EAE6
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf:: @ 821EAF0
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove: @ 821EAFD
	.string "Hum… Ah, oui,\n"
	.string "je suis l'EFFACEUR DE CAPACITES.\p"
	.string "Je fais oublier leurs capacités\n"
	.string "aux POKéMON.\p"
	.string "Tu veux que je le fasse?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget: @ 821EB65
	.string "Quel POKéMON doit oublier une capacité?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten: @ 821EB89
	.string "Quelle capacité doit être oubliée?$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove: @ 821EBA9
	.string "Apparemment, {STR_VAR_1} ne connaît\n"
	.string "qu'une seule capacité…$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten: @ 821EBDA
	.string "Hum! {STR_VAR_1} de {STR_VAR_2}?\n"
	.string "Cette capacité doit être oubliée?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove: @ 821EC06
	.string "Ça a marché à la perfection!\p"
	.string "{STR_VAR_1} a complètement oublié\n"
	.string "{STR_VAR_2}.$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain: @ 821EC3F
	.string "Reviens me voir si tu veux que tes\n"
	.string "POKéMON oublient des capacités.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves: @ 821EC78
	.string "Quoi? Les OEUFS ne connaissent\n"
	.string "aucune capacité?!$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf: @ 821EC9C
	.string "Hum…\p"
	.string "On dirait que ton {STR_VAR_1} ne veut\n"
	.string "pas oublier SURF.$"
