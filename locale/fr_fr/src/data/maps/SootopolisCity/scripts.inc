SootopolisCity_MapScripts:: @ 81E565C
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_MapScript1_1E5676
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_MapScript1_1E590B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MapScript2_1E5914
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_MapScript2_1E58DB
	.byte 0

SootopolisCity_MapScript1_1E5676: @ 81E5676
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E56E5
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_1E5692
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E5693
	end

SootopolisCity_EventScript_1E5692:: @ 81E5692
	end

SootopolisCity_EventScript_1E5693:: @ 81E5693
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, 1
	return

SootopolisCity_EventScript_1E56E5:: @ 81E56E5
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, 1
	return

SootopolisCity_OnTransition: @ 81E56EF
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E5781
	compare VAR_SKY_PILLAR_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E5781
	call SootopolisCity_EventScript_1E5805
	call SootopolisCity_EventScript_1E57B2
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E5842
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	call_if_eq SootopolisCity_EventScript_1E5842
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_eq SootopolisCity_EventScript_1E585B
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	call_if_eq SootopolisCity_EventScript_1E5871
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	call_if_eq SootopolisCity_EventScript_1E58D3
	end

SootopolisCity_EventScript_1E5781:: @ 81E5781
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SootopolisCity_EventScript_1E5785:: @ 81E5785
	setobjectxyperm 3, 13, 48
	setobjectxyperm 5, 46, 32
	setobjectxyperm 4, 48, 41
	setobjectxyperm 8, 45, 43
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_LEFT
	return

SootopolisCity_EventScript_1E57B2:: @ 81E57B2
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
	goto_if_eq SootopolisCity_EventScript_1E5800
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E5800
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E5801
	return

SootopolisCity_EventScript_1E5800:: @ 81E5800
	return

SootopolisCity_EventScript_1E5801:: @ 81E5801
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
	return

SootopolisCity_EventScript_1E5805:: @ 81E5805
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
	goto_if_eq SootopolisCity_EventScript_1E583D
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E583D
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E583E
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E583E
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_le Common_EventScript_SetWeather15
	return

SootopolisCity_EventScript_1E583D:: @ 81E583D
	return

SootopolisCity_EventScript_1E583E:: @ 81E583E
	setweather WEATHER_RAIN_HEAVY
	return

SootopolisCity_EventScript_1E5842:: @ 81E5842
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_1E584C
	return

SootopolisCity_EventScript_1E584C:: @ 81E584C
	setobjectxyperm 1, 30, 18
	setobjectxyperm 7, 32, 18
	return

SootopolisCity_EventScript_1E585B:: @ 81E585B
	setobjectxyperm 1, 30, 18
	setobjectxyperm 18, 31, 18
	setobjectxyperm 7, 32, 18
	end

SootopolisCity_EventScript_1E5871:: @ 81E5871
	setobjectxyperm 1, 31, 18
	setobjectxyperm 7, 29, 33
	setobjectxyperm 16, 33, 35
	setobjectxyperm 17, 34, 35
	compare VAR_SOOTOPOLIS_WALLACE_STATE, 0
	call_if_eq SootopolisCity_EventScript_1E58AF
	compare VAR_SOOTOPOLIS_WALLACE_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E58BB
	compare VAR_SOOTOPOLIS_WALLACE_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E58C7
	return

SootopolisCity_EventScript_1E58AF:: @ 81E58AF
	setobjectxyperm 18, 31, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_1E58BB:: @ 81E58BB
	setobjectxyperm 18, 32, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_1E58C7:: @ 81E58C7
	setobjectxyperm 18, 30, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_1E58D3:: @ 81E58D3
	setobjectxyperm 1, 31, 18
	return

SootopolisCity_MapScript2_1E58DB: @ 81E58DB
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_1E58E5
	.2byte 0

SootopolisCity_EventScript_1E58E5:: @ 81E58E5
	compare VAR_SKY_PILLAR_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E58FC
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E5901
	end

SootopolisCity_EventScript_1E58FC:: @ 81E58FC
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	return

SootopolisCity_EventScript_1E5901:: @ 81E5901
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	setvar VAR_SKY_PILLAR_STATE, 3
	return

SootopolisCity_MapScript1_1E590B: @ 81E590B
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 255, 9, 6
	end

SootopolisCity_MapScript2_1E5914: @ 81E5914
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_1E5926
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_1E5BFE
	.2byte 0

SootopolisCity_EventScript_1E5926:: @ 81E5926
	lockall
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 43
	goto_if_ne SootopolisCity_EventScript_1E5A82
	compare VAR_0x8005, 32
	goto_if_ne SootopolisCity_EventScript_1E5A82
	goto SootopolisCity_EventScript_1E5946
	end

SootopolisCity_EventScript_1E5946:: @ 81E5946
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A68
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	setweather WEATHER_ALTERNATING
	doweather
	setvar VAR_0x8004, 0
	special Script_DoRayquazaScene
	waitstate
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement 10, SootopolisCity_Movement_1E5BC2
	applymovement 9, SootopolisCity_Movement_1E5BDD
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	special SpawnCameraObject
	applymovement 10, SootopolisCity_Movement_1E5BD6
	applymovement 9, SootopolisCity_Movement_1E5BF7
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A75
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_1E5A68: @ 81E5A68
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_1E5A75: @ 81E5A75
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	step_end

SootopolisCity_EventScript_1E5A82:: @ 81E5A82
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BA4
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	setweather WEATHER_ALTERNATING
	doweather
	setvar VAR_0x8004, 0
	special Script_DoRayquazaScene
	waitstate
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement 10, SootopolisCity_Movement_1E5BC2
	applymovement 9, SootopolisCity_Movement_1E5BDD
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	special SpawnCameraObject
	applymovement 10, SootopolisCity_Movement_1E5BD6
	applymovement 9, SootopolisCity_Movement_1E5BF7
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BAE
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_1E5BA4: @ 81E5BA4
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E5BAE: @ 81E5BAE
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_1E5BB8: @ 81E5BB8
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_1E5BC2: @ 81E5BC2
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_1E5BCF: @ 81E5BCF
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_1E5BD6: @ 81E5BD6
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	step_end

SootopolisCity_Movement_1E5BDD: @ 81E5BDD
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_1E5BE5: @ 81E5BE5
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_1E5BF0: @ 81E5BF0
	lock_facing_direction
	walk_left
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_1E5BF7: @ 81E5BF7
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

SootopolisCity_EventScript_1E5BFE:: @ 81E5BFE
	lockall
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 43
	goto_if_ne SootopolisCity_EventScript_1E5CCE
	compare VAR_0x8005, 32
	goto_if_ne SootopolisCity_EventScript_1E5CCE
	goto SootopolisCity_EventScript_1E5C1E
	end

SootopolisCity_EventScript_1E5C1E:: @ 81E5C1E
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A68
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	call SootopolisCity_EventScript_1E5D82
	removeobject 9
	removeobject 10
	addobject 11
	setvar VAR_0x8004, 1
	special Script_DoRayquazaScene
	waitstate
	playse SE_T_KAMI
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5E63
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement 11, SootopolisCity_Movement_1E5E5B
	waitmovement 0
	removeobject 11
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_RUNECITY
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp8 MAP_SOOTOPOLIS_CITY, 255, 43, 32
	waitstate
	end

SootopolisCity_EventScript_1E5CCE:: @ 81E5CCE
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BA4
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	call SootopolisCity_EventScript_1E5D82
	removeobject 9
	removeobject 10
	addobject 11
	setvar VAR_0x8004, 1
	special Script_DoRayquazaScene
	waitstate
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5E63
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E5E68
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement 11, SootopolisCity_Movement_1E5E5B
	waitmovement 0
	removeobject 11
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 2
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_NAMINORI
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp8 MAP_SOOTOPOLIS_CITY, 255, 29, 53
	waitstate
	end

SootopolisCity_EventScript_1E5D82:: @ 81E5D82
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, 0
	return

SootopolisCity_Movement_1E5E5B: @ 81E5E5B
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

SootopolisCity_Movement_1E5E63: @ 81E5E63
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E5E68: @ 81E5E68
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E5E6D: @ 81E5E6D
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SootopolisCity_Movement_1E5E72: @ 81E5E72
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_1E5E7F: @ 81E5E7F
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_EventScript_1E5E8D:: @ 81E5E8D
	lock
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E5EC4
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E5ECE
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	goto_if_ge SootopolisCity_EventScript_1E5EBA
	msgbox SootopolisCity_Text_1E6D77, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5EBA:: @ 81E5EBA
	msgbox SootopolisCity_Text_1E6DFE, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5EC4:: @ 81E5EC4
	msgbox SootopolisCity_Text_1E6F38, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5ECE:: @ 81E5ECE
	msgbox SootopolisCity_Text_1E6ED4, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5ED8:: @ 81E5ED8
	lock
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E5F1B
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E5F1B
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E5F10
	msgbox SootopolisCity_Text_1E6BFF, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E5F10:: @ 81E5F10
	msgbox SootopolisCity_Text_1E6C53, MSGBOX_DEFAULT
	closemessage
	release
	end

SootopolisCity_EventScript_1E5F1B:: @ 81E5F1B
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_1E5FBB
	msgbox SootopolisCity_Text_2A7BB0, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_2A7C7C, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_EventScript_1E5F79
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_EventScript_1E5F9A
	end

SootopolisCity_EventScript_1E5F79:: @ 81E5F79
	giveitem_std ITEM_FIGY_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_2A7CB7, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5F9A:: @ 81E5F9A
	giveitem_std ITEM_IAPAPA_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_2A7CB7, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5FBB:: @ 81E5FBB
	msgbox SootopolisCity_Text_2A7CEC, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_EventScript_1E5FD8
	msgbox SootopolisCity_Text_2A7DD2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5FD8:: @ 81E5FD8
	msgbox SootopolisCity_Text_2A7D80, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5FE2:: @ 81E5FE2
	lockall
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E600D
	msgbox SootopolisCity_Text_1E71A1, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E600D:: @ 81E600D
	msgbox SootopolisCity_Text_1E728C, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E6017:: @ 81E6017
	lock
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E602E
	msgbox SootopolisCity_Text_1E6CCA, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E602E:: @ 81E602E
	msgbox SootopolisCity_Text_1E6D57, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6038:: @ 81E6038
	lock
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E607A
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6084
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	goto_if_ge SootopolisCity_EventScript_1E6065
	msgbox SootopolisCity_Text_1E6F90, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6065:: @ 81E6065
	msgbox SootopolisCity_Text_1E7078, MSGBOX_DEFAULT
	closemessage
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E607A:: @ 81E607A
	msgbox SootopolisCity_Text_1E710B, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6084:: @ 81E6084
	msgbox SootopolisCity_Text_1E70D4, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E608E:: @ 81E608E
	lockall
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E60D9
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E60CF
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E60CF
	msgbox SootopolisCity_Text_1E690B, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E60CF:: @ 81E60CF
	msgbox SootopolisCity_Text_1E68A1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E60D9:: @ 81E60D9
	msgbox SootopolisCity_Text_1E6920, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E60E3:: @ 81E60E3
	lockall
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E612D
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_1E6137
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E6141
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E6141
	msgbox SootopolisCity_Text_1E6692, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E612D:: @ 81E612D
	msgbox SootopolisCity_Text_1E6750, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6137:: @ 81E6137
	msgbox SootopolisCity_Text_1E677F, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6141:: @ 81E6141
	msgbox SootopolisCity_Text_1E6618, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E614B:: @ 81E614B
	msgbox SootopolisCity_Text_1E656F, MSGBOX_SIGN
	end

SootopolisCity_EventScript_1E6154:: @ 81E6154
	msgbox SootopolisCity_Text_1E65C8, MSGBOX_SIGN
	end

EventScript_ClosedSootopolisDoor:: @ 81E615D
	msgbox SootopolisCity_Text_1E6604, MSGBOX_SIGN
	end

SootopolisCity_EventScript_1E6166:: @ 81E6166
	lockall
	applymovement 7, Common_Movement_FacePlayer
	waitmovement 0
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_1E61CC
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	goto_if_eq SootopolisCity_EventScript_1E61AE
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	goto_if_eq SootopolisCity_EventScript_1E61C2
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E61C2
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E61B8
	msgbox SootopolisCity_Text_1E78E5, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E61AE:: @ 81E61AE
	msgbox SootopolisCity_Text_1E7866, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E61B8:: @ 81E61B8
	msgbox SootopolisCity_Text_1E794B, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E61C2:: @ 81E61C2
	msgbox SootopolisCity_Text_1E789A, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E61CC:: @ 81E61CC
	msgbox SootopolisCity_Text_1E75CB, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_WEST
	call_if_eq SootopolisCity_EventScript_1E6243
	compare VAR_FACING, DIR_NORTH
	call_if_eq SootopolisCity_EventScript_1E6255
	msgbox SootopolisCity_Text_1E7737, MSGBOX_DEFAULT
	closemessage
	applymovement 7, SootopolisCity_Movement_1E62D4
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E630E
	waitmovement 0
	delay 120
	applymovement 1, SootopolisCity_Movement_1E6341
	waitmovement 0
	applymovement 7, SootopolisCity_Movement_1E6344
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E634F
	waitmovement 0
	msgbox SootopolisCity_Text_1E77F0, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E635A
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 255, 9, 20
	waitstate
	end

SootopolisCity_EventScript_1E6243:: @ 81E6243
	applymovement 7, SootopolisCity_Movement_1E6267
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E628C
	waitmovement 0
	return

SootopolisCity_EventScript_1E6255:: @ 81E6255
	applymovement 7, SootopolisCity_Movement_1E6267
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E62B0
	waitmovement 0
	return

SootopolisCity_Movement_1E6267: @ 81E6267
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

SootopolisCity_Movement_1E628C: @ 81E628C
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E62B0: @ 81E62B0
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E62D4: @ 81E62D4
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	delay_4
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E630E: @ 81E630E
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_1E6341: @ 81E6341
	walk_slow_left
	walk_in_place_fastest_right
	step_end

SootopolisCity_Movement_1E6344: @ 81E6344
	walk_down
	walk_down
	walk_left
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_left
	step_end

SootopolisCity_Movement_1E634F: @ 81E634F
	delay_16
	delay_16
	delay_16
	delay_8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

SootopolisCity_Movement_1E635A: @ 81E635A
	walk_up
	walk_up
	step_end

SootopolisCity_EventScript_1E635D:: @ 81E635D
	lockall
	applymovement 15, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6388
	msgbox SootopolisCity_Text_1E67DC, MSGBOX_DEFAULT
	closemessage
	applymovement 15, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E6388:: @ 81E6388
	msgbox SootopolisCity_Text_1E6853, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_1E6393:: @ 81E6393
	lockall
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E63C7
	msgbox SootopolisCity_Text_1E6936, MSGBOX_DEFAULT
	closemessage
	applymovement 14, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_1E696C, MSGBOX_DEFAULT
	closemessage
	applymovement 14, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E63C7:: @ 81E63C7
	applymovement 14, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_1E69B8, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E63DB:: @ 81E63DB
	lockall
	applymovement 13, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6406
	msgbox SootopolisCity_Text_1E6C7C, MSGBOX_DEFAULT
	closemessage
	applymovement 13, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E6406:: @ 81E6406
	msgbox SootopolisCity_Text_1E6CA6, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_1E6411:: @ 81E6411
	lockall
	applymovement 12, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E643C
	msgbox SootopolisCity_Text_1E6A50, MSGBOX_DEFAULT
	closemessage
	applymovement 12, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E643C:: @ 81E643C
	msgbox SootopolisCity_Text_1E6B2A, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E6446:: @ 81E6446
	lock
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E64D8
	goto_if_set FLAG_RECEIVED_HM07, SootopolisCity_EventScript_1E64E2
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E646F
	msgbox SootopolisCity_Text_1E7A3E, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E646F:: @ 81E646F
	msgbox SootopolisCity_Text_1E7ACF, MSGBOX_DEFAULT
	giveitem_std ITEM_HM07
	setflag FLAG_RECEIVED_HM07
	msgbox SootopolisCity_Text_1E7B86, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq SootopolisCity_EventScript_1E64B2
	compare VAR_FACING, DIR_EAST
	call_if_eq SootopolisCity_EventScript_1E64B2
	compare VAR_FACING, DIR_WEST
	call_if_eq SootopolisCity_EventScript_1E64C5
	release
	end

SootopolisCity_EventScript_1E64B2:: @ 81E64B2
	applymovement 18, SootopolisCity_Movement_1E64EC
	waitmovement 0
	copyobjectxytoperm 18
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
	return

SootopolisCity_EventScript_1E64C5:: @ 81E64C5
	applymovement 18, SootopolisCity_Movement_1E64EF
	waitmovement 0
	copyobjectxytoperm 18
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
	return

SootopolisCity_EventScript_1E64D8:: @ 81E64D8
	msgbox SootopolisCity_Text_1E79C8, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E64E2:: @ 81E64E2
	msgbox SootopolisCity_Text_1E7CBC, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Movement_1E64EC: @ 81E64EC
	walk_right
	walk_in_place_fastest_down
	step_end

SootopolisCity_Movement_1E64EF: @ 81E64EF
	walk_left
	walk_in_place_fastest_down
	step_end

SootopolisCity_EventScript_1E64F2:: @ 81E64F2
	lockall
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6509
	msgbox SootopolisCity_Text_1E72DB, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_1E6509:: @ 81E6509
	msgbox SootopolisCity_Text_1E737E, MSGBOX_DEFAULT
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_1E654C
	releaseall
	end

SootopolisCity_EventScript_1E651F:: @ 81E651F
	lockall
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6536
	msgbox SootopolisCity_Text_1E7460, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_1E6536:: @ 81E6536
	msgbox SootopolisCity_Text_1E74F6, MSGBOX_DEFAULT
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_1E654C
	releaseall
	end

SootopolisCity_EventScript_1E654C:: @ 81E654C
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setvar VAR_MT_PYRE_STATE, 2
	warpsilent MAP_SOOTOPOLIS_CITY, 255, 31, 34
	waitstate
	releaseall
	end

SootopolisCity_Movement_1E656B:: @ 81E656B
	levitate
	step_end

SootopolisCity_Movement_1E656D:: @ 81E656D
	destroy_extra_task
	step_end

SootopolisCity_Text_1E656F: @ 81E656F
	.string "ARENE POKéMON d'ATALANOPOLIS\n"
	.string "CHAMPION: JUAN\p"
	.string "“Le DRESSEUR à la beauté pure”$"

SootopolisCity_Text_1E65C8: @ 81E65C8
	.string "ATALANOPOLIS\p"
	.string "“La ville mystique où sommeille\n"
	.string "l'histoire.”$"


SootopolisCity_Text_1E6604: @ 81E6604
	.string "La porte est fermée.$"

SootopolisCity_Text_1E6618: @ 81E6618
	.string "Plonger dans la mer. Toujours monter et\n"
	.string "descendre les escaliers…\p"
	.string "Quand tu habites dans cette ville,\n"
	.string "tu finis par être musclé.$"

SootopolisCity_Text_1E6692: @ 81E6692
	.string "Ces POKéMON géants sont apparus d'un\n"
	.string "coup au milieu de la ville!\p"
	.string "J'les avais jamais vus!\p"
	.string "Mais pourquoi ils se battent comme ça?\p"
	.string "Ils pourraient essayer d'être copains!$"

SootopolisCity_Text_1E6750: @ 81E6750
	.string "QUOI? Quoi?\n"
	.string "C'est quoi ce POKéMON vert?!$"

SootopolisCity_Text_1E677F: @ 81E677F
	.string "GROUDON and KYOGRE…\n"
	.string "Où sont-ils partis?\p"
	.string "Est-ce qu'ils sont allés provoquer\n"
	.string "des sécheresses ou des pluies\n"
	.string "torrentielles ailleurs?$"

SootopolisCity_Text_1E67DC: @ 81E67DC
	.string "J'ai l'impression que ces POKéMON\n"
	.string "ne sont pas vraiment fâchés.\p"
	.string "Je pense juste qu'ils ne peuvent pas\n"
	.string "contrôler leur puissance…$"

SootopolisCity_Text_1E6853: @ 81E6853
	.string "Ce POKéMON volant est descendu\n"
	.string "du ciel et a calmé les deux autres…$"

SootopolisCity_Text_1E68A1: @ 81E68A1
	.string "Je… Je ne suis jamais sorti de la ville.\p"
	.string "Je me demande à quoi ressemble le monde\n"
	.string "de l'autre côté de ce ciel rond?$"

SootopolisCity_Text_1E690B: @ 81E690B
	.string "Waouh!\n"
	.string "C'est incroyable!$"

SootopolisCity_Text_1E6920: @ 81E6920
	.string "Waouh!\n"
	.string "C'était incroyable!$"

SootopolisCity_Text_1E6936: @ 81E6936
	.string "Allez le POKéMON rouge!\n"
	.string "Ne te laisse pas faire POKéMON bleu!$"

SootopolisCity_Text_1E696C: @ 81E696C
	.string "… … … … … …\p"
	.string "Salut, tu connais le nom des POKéMON\n"
	.string "en train de se battre là-bas?$"

SootopolisCity_Text_1E69B8: @ 81E69B8
	.string "Je me demandais qui gagnerait ce\n"
	.string "combat, le bleu ou le rouge…\p"
	.string "Mais c'est le vert qui a tout arrangé!\p"
	.string "Tu parles d'un retournement de\n"
	.string "situation!$"

SootopolisCity_Text_1E6A50: @ 81E6A50
	.string "Une ancienne légende raconte que la\n"
	.string "terre et la mer auraient été formées\p"
	.string "par un combat colossal entre\n"
	.string "deux POKéMON.\p"
	.string "J'ai l'impression que c'est ce qui est\n"
	.string "en train de se passer sous mes yeux!\p"
	.string "Waouh, je n'aurais jamais pensé pouvoir\n"
	.string "assister à quelque chose comme ça!$"

SootopolisCity_Text_1E6B2A: @ 81E6B2A
	.string "Une ancienne légende raconte que la\n"
	.string "terre et la mer auraient été formées\p"
	.string "par un combat colossal entre\n"
	.string "deux POKéMON.\p"
	.string "Eh bien, j'ai pu assister à cette scène\n"
	.string "de mes propres yeux!\p"
	.string "Waouh, je n'aurais jamais pensé pouvoir\n"
	.string "assister à quelque chose comme ça!$"

SootopolisCity_Text_1E6BFF: @ 81E6BFF
	.string "Un gros POKéMON se bat contre\n"
	.string "un autre gros POKéMON!\p"
	.string "Il faut que quelqu'un fasse\n"
	.string "quelque chose!$"

SootopolisCity_Text_1E6C53: @ 81E6C53
	.string "Un joli POKéMON est descendu du ciel.$"

SootopolisCity_Text_1E6C7C: @ 81E6C7C
	.string "Oh, non!\n"
	.string "ATALANOPOLIS va être détruite!$"

SootopolisCity_Text_1E6CA6: @ 81E6CA6
	.string "ATALANOPOLIS n'a pas été détruite!$"

SootopolisCity_Text_1E6CCA: @ 81E6CCA
	.string "Hum! Tu as fait tout le trajet jusqu'à\n"
	.string "ATALANOPOLIS?\p"
	.string "Tu n'es pas un touriste ordinaire.\p"
	.string "Mais je suppose que ça ne fait pas de\n"
	.string "toi un touriste d'exception non plus.$"

SootopolisCity_Text_1E6D57: @ 81E6D57
	.string "La ville a retrouvé son calme…$"

SootopolisCity_Text_1E6D77: @ 81E6D77
	.string "Qui peux-tu bien être?\p"
	.string "C'est la GROTTE ORIGINE.\p"
	.string "Les esprits de POKéMON, qui reposent\n"
	.string "au MONT MEMORIA, reprendraient vie ici.\p"
	.string "Il faudrait que tu partes.$"

SootopolisCity_Text_1E6DFE: @ 81E6DFE
	.string "Une personne d'une grande volonté et\n"
	.string "aux capacités supérieures…\p"
	.string "Un DRESSEUR d'expérience et\n"
	.string "connaissant de nombreuses espèces\n"
	.string "de POKéMON…\p"
	.string "Si une telle personne devait se\n"
	.string "présenter, MARC m'a demandé de\l"
	.string "la conduire dans cette GROTTE.$"

SootopolisCity_Text_1E6ED4: @ 81E6ED4
	.string "Incroyable…\p"
	.string "Le combat entre les deux POKéMON\n"
	.string "a été stoppé par l'arrivée d'un\l"
	.string "troisième POKéMON…$"

SootopolisCity_Text_1E6F38: @ 81E6F38
	.string "C'est la GROTTE ORIGINE…\p"
	.string "Une fois la crise passée, la GROTTE\n"
	.string "aussi devrait retrouver son calme…$"

SootopolisCity_Text_1E6F90: @ 81E6F90
	.string "ATALANOPOLIS s'élève telle une ville\n"
	.string "dans le cratère d'un volcan.\p"
	.string "Quand tu lèves les yeux au ciel, tu\n"
	.string "distingues aussi le bord du cratère.\l"
	.string "Alors tout ce que tu vois, c'est le ciel\n"
	.string "dans un cercle.\p"
	.string "Mais c'est ce qui rend le ciel au-dessus\n"
	.string "d'ATALANOPOLIS plus beau qu'ailleurs.$"

SootopolisCity_Text_1E7078: @ 81E7078
	.string "Quand deux POKéMON si gigantesques\n"
	.string "s'affrontent sauvagement, nous ne\l"
	.string "pouvons pas faire grand chose.$"

SootopolisCity_Text_1E70D4: @ 81E70D4
	.string "J'ai craint le pire en voyant arriver ce\n"
	.string "troisième POKéMON.$"

SootopolisCity_Text_1E710B: @ 81E710B
	.string "Un cercle de ciel, la nuit, entre les\n"
	.string "bords du cratère d'un volcan…\p"
	.string "Dans ce cercle les étoiles scintillent\n"
	.string "et clignotent comme si elles étaient\l"
	.string "en vie.\p"
	.string "C'est mon panorama préféré.$"

SootopolisCity_Text_1E71A1: @ 81E71A1
	.string "Le ciel était clair ce matin,\n"
	.string "mais…\p"
	.string "Soudainement, des nuages noirs sont\n"
	.string "apparus et des orages ont éclaté\l"
	.string "Le temps est complètement détraqué!\p"
	.string "Serait-ce à cause de ces POKéMON?$"

SootopolisCity_Text_1E728C: @ 81E728C
	.string "Oh?\p"
	.string "C'est toi qui as ramené ce POKéMON\n"
	.string "volant ici?\p"
	.string "J'en reste bouche bée!$"

SootopolisCity_Text_1E72DB: @ 81E72DB
	.string "MAX: G… GROUDON…\n"
	.string "Arrête! Je t'en prie arrête!\p"
	.string "Je connais l'étendue de ton pouvoir\n"
	.string "maintenant!\p"
	.string "Si tu continues, non seulement\n"
	.string "ATALANOPOLIS, mais aussi HOENN\l"
	.string "sera complètement détruit!$"

SootopolisCity_Text_1E737E: @ 81E737E
	.string "MAX: Alors GROUDON et KYOGRE\n"
	.string "ne sont pas les seuls POKéMON\l"
	.string "ancestraux…\p"
	.string "Après tous nos plans inutiles et nos\n"
	.string "efforts désespérés, il a suffi d'un\p"
	.string "seul geste de ce POKéMON pour que\n"
	.string "tout redevienne normal…\p"
	.string "Ha ha…\n"
	.string "Ouah ha ha…$"

SootopolisCity_Text_1E7460: @ 81E7460
	.string "ARTHUR: KYOGRE! Que se passe-t-il?!\n"
	.string "Regarde par ici! C'est l'ORBE ROUGE!\l"
	.string "Calme-toi! KYOGRE!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ça ne va pas!\n"
	.string "Il ne m'écoute même pas!$"

SootopolisCity_Text_1E74F6: @ 81E74F6
	.string "ARTHUR: KYOGRE et GROUDON\n"
	.string "Ils se sont tous les deux envolés\n"
	.string "on ne sait où.\p"
	.string "Le climat d'HOENN est revenu à\n"
	.string "la normale…\p"
	.string "Haha…\n"
	.string "Hahahaha…\p"
	.string "Ce que nous avons essayé d'accomplir\n"
	.string "semble bien insignifiant comparé à\l"
	.string "la puissance de ces POKéMON…$"

SootopolisCity_Text_1E75CB: @ 81E75CB
	.string "PIERRE: Ces deux POKéMON…\n"
	.string "GROUDON… Et KYOGRE…\p"
	.string "Ces deux POKéMON ancestraux ont été\n"
	.string "tirés de leur long sommeil…\p"
	.string "Et maintenant, ils sont en train de\n"
	.string "s'affronter en utilisant leurs\l"
	.string "pouvoirs incontrôlables…\p"
	.string "…{PLAYER}{KUN}.\p"
	.string "A te voir là, j'imagine que tu as prévu\n"
	.string "de tenter quelque chose, non?\p"
	.string "Bien, dans ce cas, il y a quelqu'un que\n"
	.string "j'aimerais te faire rencontrer.\p"
	.string "Viens avec moi, s'il te plaît.$"

SootopolisCity_Text_1E7737: @ 81E7737
	.string "PIERRE: Ecoute, {PLAYER}{KUN}.\p"
	.string "Est-ce que voir GROUDON et KYOGRE\n"
	.string "se battre ainsi te fait penser que\l"
	.string "les POKéMON doivent être craints?\p"
	.string "Mais il ne faut pas! Les POKéMON.\n"
	.string "sont bien plus que ça…\p"
	.string "Mais pourquoi est-ce que je te\n"
	.string "dis ça? Tu le sais déjà!.$"

SootopolisCity_Text_1E77F0: @ 81E77F0
	.string "PIERRE: Très bien, nous sommes\n"
	.string "arrivés!\p"
	.string "A l'intérieur, tu trouveras quelqu'un\n"
	.string "MARC.\p"
	.string "Je crois que tu seras en mesure\n"
	.string "de l'aider…$"

SootopolisCity_Text_1E7866: @ 81E7866
	.string "PIERRE: Je crois que tu seras en mesure\n"
	.string "de l'aider…$"

SootopolisCity_Text_1E789A: @ 81E789A
	.string "PIERRE: Le PILIER CELESTE…\p"
	.string "Je n'y suis jamais allé.\n"
	.string "Où cela peut-il bien être?$"

SootopolisCity_Text_1E78E5: @ 81E78E5
	.string "PIERRE: Alors ce RAYQUAZA…\p"
	.string "C'est incroyable que ces immenses\n"
	.string "POKéMON aient eu peur de lui comme ça…$"

SootopolisCity_Text_1E794B: @ 81E794B
	.string "PIERRE: On dirait que MAX et ARTHUR\n"
	.string "sont partis quelque part.\p"
	.string "Peut-être sont-ils allés au MONT\n"
	.string "MEMORIA pour y déposer les ORBES…$"

SootopolisCity_Text_1E79C8: @ 81E79C8
	.string "MARC: Oh?\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Tu n'as pas encore gravi le\n"
	.string "PILIER CELESTE?\p"
	.string "suis sûr que ça ne devrait pas\n"
	.string "être un gros problème pour toi…$"

SootopolisCity_Text_1E7A3E: @ 81E7A3E
	.string "MARC: {PLAYER}{KUN}…\p"
	.string "Les leaders des TEAMS MAGMA et\n"
	.string "AQUA, je ne pense pas qu'ils veuillent\l"
	.string "vraiment faire le mal.\p"
	.string "Il faudrait les écouter pour savoir ce\n"
	.string "qu'ils ont vraiment en tête.$"

SootopolisCity_Text_1E7ACF: @ 81E7ACF
	.string "MARC: {PLAYER}{KUN}…\n"
	.string "Mon intuition était bonne.\p"
	.string "Grâce à toi, ATALANOPOLIS…\n"
	.string "Non, tout HOENN a été sauvé.\p"
	.string "Au nom de tous ses habitants,\n"
	.string "je te remercie.\p"
	.string "C'est un cadeau de ma part. Je t'en.\n"
	.string "prie, accepte-le.$"

SootopolisCity_Text_1E7B86: @ 81E7B86
	.string "Cette CS contient CASCADE.\p"
	.string "Si tu as le BADGE PLUIE, un POKéMON\n"
	.string "connaissant cette CS sera capable\l"
	.string "de remonter des cascades d'eau.\p"
	.string "Et où trouve-t-on le BADGE PLUIE?\n"
	.string "Tu le sais, n'est-ce pas?\p"
	.string "C'est bien ça! Tu dois battre le\n"
	.string "CHAMPION D'ARENE d'ATALANOPOLIS.\p"
	.string "Tu n'as plus qu'à franchir la porte\n"
	.string "se trouvant derrière moi pour cela.$"

SootopolisCity_Text_1E7CBC: @ 81E7CBC
	.string "MARC: Mais je tiens à te prévenir que\n"
	.string "l'élégant style de combat de mon mentor\l"
	.string "risque de te laisser le souffle coupé.$"
