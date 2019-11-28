MtPyre_4F_MapScripts:: @ 8231BC8
	.byte 0

MtPyre_5F_EventScript_231BC9:: @ 8231BC9
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_231BE0, MtPyre_5F_Text_231C08
	msgbox MtPyre_5F_Text_231C24, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_231BE0: @ 8231BE0
	.string "Professeur…\n"
	.string Regardez les progrès que j'ai faits!$"

MtPyre_5F_Text_231C08: @ 8231C08
	.string "Professeur…\n"
	.string "Pardonnez-moi!$"

MtPyre_5F_Text_231C24: @ 8231C24
	.string "Mon prof, qui repose ici, ne trouvera\n"
	.string "la paix que lorsque j'aurai progressé…$"

