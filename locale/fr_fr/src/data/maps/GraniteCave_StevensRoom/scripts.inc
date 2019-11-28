GraniteCave_StevensRoom_MapScripts:: @ 822DC7A
	.byte 0

GraniteCave_StevensRoom_EventScript_22DC7B:: @ 822DC7B
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_22DD5A, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_22DDBD, MSGBOX_DEFAULT
	giveitem_std ITEM_TM47
	compare VAR_RESULT, 0
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD3C
	msgbox GraniteCave_StevensRoom_Text_22DE6B, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox GraniteCave_StevensRoom_Text_22DF6A, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_22DF8C, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD0D
	compare VAR_FACING, DIR_SOUTH
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD2A
	compare VAR_FACING, DIR_WEST
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD18
	compare VAR_FACING, DIR_EAST
	call_if_eq GraniteCave_StevensRoom_EventScript_22DD18
	playse SE_KAIDAN
	removeobject 1
	release
	end

GraniteCave_StevensRoom_EventScript_22DD0D:: @ 822DD0D
	applymovement 1, GraniteCave_StevensRoom_Movement_22DD45
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_22DD18:: @ 822DD18
	applymovement EVENT_OBJ_ID_PLAYER, GraniteCave_StevensRoom_Movement_22DD4C
	applymovement 1, GraniteCave_StevensRoom_Movement_22DD45
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_22DD2A:: @ 822DD2A
	applymovement EVENT_OBJ_ID_PLAYER, GraniteCave_StevensRoom_Movement_22DD4C
	applymovement 1, GraniteCave_StevensRoom_Movement_22DD51
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_22DD3C:: @ 822DD3C
	msgbox GraniteCave_StevensRoom_Text_22DFAA, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_22DD45: @ 822DD45
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_22DD4C: @ 822DD4C
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

GraniteCave_StevensRoom_Movement_22DD51: @ 822DD51
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_22DD5A: @ 822DD5A
	.string "Je suis PIERRE.\p"
	.string "Je m'intéresse aux pierres rares, alors\n"
	.string "je vais ici et là.\p"
	.string "Oh?\n"
	.string "C'est une LETTRE pour moi?$"

GraniteCave_StevensRoom_Text_22DDBD: @ 822DDBD
	.string "PIERRE: OK, merci.\p"
	.string "Tu as fait tout ça rien que pour me la \n"
	.string "remettre? Il faut que je te remercie.\p"
	.string "Laisse-moi voir…\n"
	.string "Je vais te donner cette CT.\p"
	.string "Elle contient ma capacité préférée,\n"
	.string "AILE D'ACIER.$"

GraniteCave_StevensRoom_Text_22DE6B: @ 822DE6B
	.string "PIERRE: Tes POKéMON semblent être\n"
	.string "tout à fait compétents.\p"
	.string "En continuant à t'entraîner, un jour,\n"
	.string "tu pourrais même devenir le MAITRE de la\l"
	.string "LIGUE POKéMON. Je le pense vraiment.\p"
	.string "Je sais, puisqu'on se connaît\n"
	.string ", enregistrons nos numéros\l"
	.string "dans nos POKéNAVS.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_22DF6A: @ 822DF6A
	.string "Vous avez enregistré PIERRE\n"
	.string "dans le POKéNAV.$"

GraniteCave_StevensRoom_Text_22DF8C: @ 822DF8C
	.string "Maintenant, il faut que je me dépêche.$"

GraniteCave_StevensRoom_Text_22DFAA: @ 822DFAA
	.string "Oh, ton SAC est plein…\n"
	.string "C'est dommage.$"

