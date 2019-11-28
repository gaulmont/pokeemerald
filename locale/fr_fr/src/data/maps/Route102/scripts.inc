Route102_MapScripts:: @ 81EC0E0
	.byte 0

Route102_EventScript_LittleBoy:: @ 81EC0E1
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale:: @ 81EC0EA
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg:: @ 81EC0F3
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy:: @ 81EC0FC
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin:: @ 81EC105
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle:: @ 81EC146
	special sub_80B4808
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall:: @ 81EC157
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister:: @ 81EC170
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister:: @ 81EC183
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch:: @ 81EC19C
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick:: @ 81EC1B3
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana:: @ 81EC1CA
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen:: @ 81EC1E1
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon: @ 81EC1F8
	.string "TIMMY: {PLAYER}…\n"
	.string "Les POKéMON se cachent dans les hautes\l"
	.string "herbes comme celles-là, pas vrai?\p"
	.string "Observe-moi et regarde si j'arrive à en\n"
	.string "attraper un correctement.\p"
	.string "…Waouh!$"

Route102_Text_WallyIDidIt: @ 81EC271
	.string "TIMMY: J'ai réussi… C'est mon…\n"
	.string "Mon POKéMON!$"

Route102_Text_LetsGoBack: @ 81EC297
	.string "Merci, {PLAYER}!\n"
	.string "Retournons à l'ARENE!$"

Route102_Text_ImNotVeryTall: @ 81EC2C0
	.string "Je… ne suis pas très grand, alors je\n"
	.string "m'enfonce dans les hautes herbes.\p"
	.string "L'herbe chatouille mes narines…\n"
	.string "Aaaaaaaaaaaaaa…\p"
	.string "Atchoum!$"

Route102_Text_CatchWholeBunchOfPokemon: @ 81EC32E
	.string "Je vais attraper tout un tas de\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale: @ 81EC35B
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} ROSYERES$"

Route102_Text_RouteSignPetalburg: @ 81EC373
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} CLEMENTI-VILLE$"
