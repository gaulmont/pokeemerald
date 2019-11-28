PetalburgCity_House2_MapScripts:: @ 82078F2
	.byte 0

PetalburgCity_House2_EventScript_Woman:: @ 82078F3
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid:: @ 82078FC
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader: @ 8207905
	.string "NORMAN est le nouveau CHAMPION\n"
	.string "D'ARENE de notre ville.\p"
	.string "Je crois qu'il a fait venir sa famille\n"
	.string "d'une région lointaine.$"

PetalburgCity_House2_Text_BattledNormanOnce: @ 8207969
	.string "J'ai affronté NORMAN une fois.\n"
	.string "Mais il était bien trop fort.\p"
	.string "Comment dire…\p"
	.string "J'ai le sentiment qu'il ne vit\n"
	.string "que pour les POKéMON.$"

