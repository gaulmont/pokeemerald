LilycoveCity_CoveLilyMotel_1F_MapScripts:: @ 8218188
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_218189:: @ 8218189
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_2181EA
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_2181C3
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_218264, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_21831E, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_2181C3:: @ 82181C3
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_2183C3, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_218470, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_2181EA:: @ 82181EA
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_218544, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_2185F4, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_218211:: @ 8218211
	lockall
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_21839B, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_218259
	applymovement 1, LilycoveCity_CoveLilyMotel_1F_Movement_21825E
	waitmovement 0
	applymovement 1, LilycoveCity_CoveLilyMotel_1F_Movement_218260
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_218259: @ 8218259
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_21825E: @ 821825E
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_218260: @ 8218260
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_218264: @ 8218264
	.string "Hum… Ils ont doublé leur clientèle en\n"
	.string "faisant des POKéMON une attraction?\p"
	.string "Je devrais peut-être prendre un\n"
	.string "POKéMON gracieux comme mascotte\l"
	.string "pour notre auberge.\p"
	.string "Je me demande si ça attirera plus\n"
	.string "de monde chez nous.$"

LilycoveCity_CoveLilyMotel_1F_Text_21831E: @ 821831E
	.string "Oh, pardon! Désolé!\n"
	.string "J'étais trop absorbé par la télé!\p"
	.string "Depuis que la TEAM AQUA a débarqué en\n"
	.string "ville, les touristes n'approchent plus.$"

LilycoveCity_CoveLilyMotel_1F_Text_21839B: @ 821839B
	.string "Hé, faut pas rester là!\n"
	.string "J'vois pas la télé!$"

LilycoveCity_CoveLilyMotel_1F_Text_2183C3: @ 82183C3
	.string "Etonnant! Tu veux dire qu'un POKéMON\n"
	.string "a trouvé un objet perdu par quelqu'un?\p"
	.string "Ça par exemple! Si on avait un POKéMON\n"
	.string "aussi intelligent que ça…\p"
	.string "On pourrait retrouver tout ce que nos\n"
	.string "clients perdent…$"

LilycoveCity_CoveLilyMotel_1F_Text_218470: @ 8218470
	.string "Oh, pardon! Désolé!\n"
	.string "J'étais absorbé par la télé!\p"
	.string "J'ai entendu dire que quelqu'un avait\n"
	.string "débusqué la PLANQUE AQUA.\p"
	.string "Grâce à ça, on vient juste de faire une\n"
	.string "réservation pour tout un groupe.\p"
	.string "C'était une entreprise nommée… Hum…\n"
	.string "GAME quelque chose…$"

LilycoveCity_CoveLilyMotel_1F_Text_218544: @ 8218544
	.string "Etonnant! Un POKéMON de garde a\n"
	.string "attrapé un voleur?\p"
	.string "Ça alors! Si on avait un POKéMON aussi\n"
	.string "robuste pour monter la garde…\p"
	.string "On aimerait pouvoir garantir une\n"
	.string "totale sécurité à notre clientèle.$"

LilycoveCity_CoveLilyMotel_1F_Text_2185F4: @ 82185F4
	.string "Oh, pardon! Désolé!\n"
	.string "J'étais absorbé par la télé.\p"
	.string "Oh, oui. Un grand groupe de clients\n"
	.string "est arrivé il y a peu.\p"
	.string "Ils ont réservé sous le nom de GAME\n"
	.string "FREAK. Je suppose qu'ils font des jeux.\p"
	.string "Oh, je ferais mieux de m'occuper\n"
	.string "de leur dîner!$"

