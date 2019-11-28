SeafloorCavern_Entrance_MapScripts:: @ 823446E
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_MapScript1_234474
	.byte 0

SeafloorCavern_Entrance_MapScript1_234474: @ 8234474
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	end

SeafloorCavern_Entrance_EventScript_234485:: @ 8234485
	lockall
	compare VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	goto_if_eq SeafloorCavern_Entrance_EventScript_2344ED
	waitse
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	delay 20
	compare VAR_FACING, DIR_WEST
	call_if_eq SeafloorCavern_Entrance_EventScript_23452E
	compare VAR_FACING, DIR_EAST
	call_if_eq SeafloorCavern_Entrance_EventScript_234523
	compare VAR_FACING, DIR_NORTH
	call_if_eq SeafloorCavern_Entrance_EventScript_234539
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm 1
	msgbox SeafloorCavern_Entrance_Text_234544, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_2344ED:: @ 82344ED
	compare VAR_FACING, DIR_WEST
	call_if_eq SeafloorCavern_Entrance_EventScript_23452E
	compare VAR_FACING, DIR_EAST
	call_if_eq SeafloorCavern_Entrance_EventScript_234523
	compare VAR_FACING, DIR_NORTH
	call_if_eq SeafloorCavern_Entrance_EventScript_234539
	msgbox SeafloorCavern_Entrance_Text_2346C8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_234523:: @ 8234523
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_23452E:: @ 823452E
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_234539:: @ 8234539
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_234544: @ 8234544
	.string "Hé!\n"
	.string "Je me souviens de toi!\p"
	.string "Si tu es là, ça veut dire que tu veux\n"
	.string "encore te mêler de nos affaires!\p"
	.string "Tu penses vraiment qu'une demi-portion\n"
	.string "comme toi peut gêner la TEAM AQUA?\p"
	.string "Mais tu rêves complètement, ma parole.\p"
	.string "Tu arriverais à peine à entrer dans\n"
	.string "la TEAM MAGMA, c'est dire!\p"
	.string "En parlant d'eux, il paraît qu'on les a\n"
	.string "repérés près d'ALGATIA.\p"
	.string "Ils ne doivent pas faire les fiers\n"
	.string "si près de la mer!$"

SeafloorCavern_Entrance_Text_2346C8: @ 82346C8
	.string "Tu penses vraiment qu'une demi-portion\n"
	.string "comme toi peut gêner la TEAM AQUA?\p"
	.string "Mais tu rêves complètement, ma parole.\p"
	.string "Tu arriverais à peine à entrer dans\n"
	.string "la TEAM MAGMA, c'est dire!\p"
	.string "En parlant d'eux, il paraît qu'on les a\n"
	.string "repérés près d'ALGATIA.\p"
	.string "Ils ne doivent pas faire les fiers\n"
	.string "si près de la mer!$"

