MossdeepCity_House4_MapScripts:: @ 8222DD7
	.byte 0

MossdeepCity_House4_EventScript_222DD8:: @ 8222DD8
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_222DED
	msgbox MossdeepCity_House4_Text_222E31, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_222DED:: @ 8222DED
	msgbox MossdeepCity_House4_Text_222E73, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_222DF7:: @ 8222DF7
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_House4_EventScript_222E14
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_222ECC, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_222E14:: @ 8222E14
	msgbox MossdeepCity_House4_Text_222EF7, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_222E1E:: @ 8222E1E
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox MossdeepCity_House4_Text_222F31, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_222E31: @ 8222E31
	.string "Mon petit frère dit qu'il aime bien\n"
	.string "chercher les BASES SECRETES\l"
	.string "des autres.$"

MossdeepCity_House4_Text_222E73: @ 8222E73
	.string "Mon petit frère dit qu'il aime bien voir\n"
	.string "les BASES SECRETES des autres\l"
	.string "et mener des combats de POKéMON.$"

MossdeepCity_House4_Text_222ECC: @ 8222ECC
	.string "C'est toi qui as aménagé une BASE\n"
	.string "SECRETE {STR_VAR_1}?$"

MossdeepCity_House4_Text_222EF7: @ 8222EF7
	.string "Tu devrais t'aménager une BASE SECRETE\n"
	.string "quelque part. J'irai la chercher!$"

MossdeepCity_House4_Text_222F31: @ 8222F31
	.string "DELCATTY: Delcaaah?$"

