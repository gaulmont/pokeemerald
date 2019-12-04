Roulette_EventScript_Table1:: @ 82A5AB1
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpricereduction POKENEWS_GAME_CORNER
	compare VAR_RESULT, 0
	goto_if_eq Roulette_EventScript_Play
	addvar VAR_0x8004, 128
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2:: @ 82A5ADF
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpricereduction POKENEWS_GAME_CORNER
	compare VAR_RESULT, 0
	goto_if_eq Roulette_EventScript_Play
	addvar VAR_0x8004, 128
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play:: @ 82A5B0D
	special PlayRoulette
	waitstate
	end
	
Roulette_Text_PlayMinimumWagerIsX:: @ 82A5B12
	.string "A cette table, la mise minimum est\n"
	.string "de {STR_VAR_1}. Voulez-vous jouer?$"

Roulette_Text_NotEnoughCoins:: @ 82A5B4E
	.string "Vous n'avez pas assez de JETONS.$"

Roulette_Text_SpecialRateTable:: @ 82A5B6B
	.string "En ce moment, table à tarif spécial!$"

Roulette_Text_ControlsInstruction:: @ 82A5B89
	.string "Placez votre mise avec la manette +\n"
	.string "et appuyez sur le bouton A.$"

Roulette_Text_ItsAHit:: @ 82A5BCB
	.string "Vous avez gagné!$"

Roulette_Text_Jackpot:: @ 82A5BD7
	.string "Jackpot!$"

Roulette_Text_NothingDoing:: @ 82A5BE0
	.string "Vous avez perdu!$"

Roulette_Text_YouveWonXCoins:: @ 82A5BEF
	.string "Vous avez gagné {STR_VAR_1} JETONS!$"

Roulette_Text_NoCoinsLeft:: @ 82A5C04
	.string "Plus assez de JETONS…$"

Roulette_Text_KeepPlaying:: @ 82A5C13
	.string "Continuer à jouer?$"

Roulette_Text_BoardWillBeCleared:: @ 82A5C21
	.string "La ROULETTE va être relancée.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase:: @ 82A5C45
	.string "You don't have a COIN CASE.$"

Roulette_Text_CoinCaseIsFull:: @ 82A5C61
	.string "Votre BOITE JETONS est pleine! On peut\n"
	.string "échanger vos JETONS contre des lots.$"
