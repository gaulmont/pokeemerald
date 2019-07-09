#ifdef FRENCH
const u8 gTrainerClassNames[][13] = {
    [TRAINER_CLASS_PKMN_TRAINER_1] = _("DRESSEUR"),
    [TRAINER_CLASS_PKMN_TRAINER_2] = _("DRESSEUR"),
    [TRAINER_CLASS_HIKER] = _("MONTAGNARD"),
    [TRAINER_CLASS_TEAM_AQUA] = _("TEAM AQUA"),
    [TRAINER_CLASS_PKMN_BREEDER] = _("ELEVEUR"),
    [TRAINER_CLASS_COOLTRAINER] = _("TOPDRESSEUR"),
    [TRAINER_CLASS_BIRD_KEEPER] = _("ORNITHOLOGUE"),
    [TRAINER_CLASS_COLLECTOR] = _("COLLEC"),
    [TRAINER_CLASS_SWIMMER_M] = _("NAGEUR"),
    [TRAINER_CLASS_TEAM_MAGMA] = _("TEAM MAGMA"),
    [TRAINER_CLASS_EXPERT] = _("EXPERT"),
    [TRAINER_CLASS_AQUA_ADMIN] = _("ADMIN AQUA"),
    [TRAINER_CLASS_BLACK_BELT] = _("KARATEKA"),
    [TRAINER_CLASS_AQUA_LEADER] = _("LEADER AQUA"),
    [TRAINER_CLASS_HEX_MANIAC] = _("MYSTIMANIAC"),
    [TRAINER_CLASS_AROMA_LADY] = _("AROMA"),
    [TRAINER_CLASS_RUIN_MANIAC] = _("RUINEMANIAC"),
    [TRAINER_CLASS_INTERVIEWER] = _("JOURNALISTES"),
    [TRAINER_CLASS_TUBER_F] = _("FLOTTEUR"),
    [TRAINER_CLASS_TUBER_M] = _("FLOTTEUR"),
    [TRAINER_CLASS_LADY] = _("MADEMOISELLE"),
    [TRAINER_CLASS_BEAUTY] = _("CANON"),
    [TRAINER_CLASS_RICH_BOY] = _("RICHARD"),
    [TRAINER_CLASS_POKEMANIAC] = _("POKéMANIAC"),
    [TRAINER_CLASS_GUITARIST] = _("GUITARISTE"),
    [TRAINER_CLASS_KINDLER] = _("SALTIMBANQUE"),
    [TRAINER_CLASS_CAMPER] = _("CAMPEUR"),
    [TRAINER_CLASS_PICNICKER] = _("PIQUE-NIQUE"),
    [TRAINER_CLASS_BUG_MANIAC] = _("ENTOMOMANIAC"),
    [TRAINER_CLASS_PSYCHIC] = _("KINESISTE"),
    [TRAINER_CLASS_GENTLEMAN] = _("GENTLEMAN"),
    [TRAINER_CLASS_ELITE_FOUR] = _("CONSEIL 4"),
    [TRAINER_CLASS_LEADER] = _("CHAMPION"),
    [TRAINER_CLASS_SCHOOL_KID] = _("ELEVE"),
    [TRAINER_CLASS_SR_AND_JR] = _("SR. ET JR."),
    [TRAINER_CLASS_WINSTRATE] = _("STRATEGE"),
    [TRAINER_CLASS_POKEFAN] = _("POKéFAN"),
    [TRAINER_CLASS_YOUNGSTER] = _("GAMIN"),
    [TRAINER_CLASS_CHAMPION] = _("MAITRE"),
    [TRAINER_CLASS_FISHERMAN] = _("PECHEUR"),
    [TRAINER_CLASS_TRIATHLETE] = _("TRIATHLETE"),
    [TRAINER_CLASS_DRAGON_TAMER] = _("DRACOLOGUE"),
    [TRAINER_CLASS_NINJA_BOY] = _("NINJA FAN"),
    [TRAINER_CLASS_BATTLE_GIRL] = _("COMBATTANTE"),
    [TRAINER_CLASS_PARASOL_LADY] = _("SŒUR PARASOL"),
    [TRAINER_CLASS_SWIMMER_F] = _("NAGEUSE"),
    [TRAINER_CLASS_TWINS] = _("JUMELLES"),
    [TRAINER_CLASS_SAILOR] = _("MARIN"),
    [TRAINER_CLASS_COOLTRAINER_UNUSED] = _("TOPDRESSEUR"),
    [TRAINER_CLASS_MAGMA_ADMIN] = _("ADMIN MAGMA"),
    [TRAINER_CLASS_PKMN_TRAINER_3] = _("DRESSEUR"),
    [TRAINER_CLASS_BUG_CATCHER] = _("SCOUT"),
    [TRAINER_CLASS_PKMN_RANGER] = _("{PKMN} RANGER"),
    [TRAINER_CLASS_MAGMA_LEADER] = _("LEADER MAGMA"),
    [TRAINER_CLASS_LASS] = _("FILLETTE"),
    [TRAINER_CLASS_YOUNG_COUPLE] = _("JEUNE COUPLE"),
    [TRAINER_CLASS_OLD_COUPLE] = _("VIEUX COUPLE"),
    [TRAINER_CLASS_SIS_AND_BRO] = _("FRERE & SŒUR"),
    [TRAINER_CLASS_SALON_MAIDEN] = _("AS DU SALON"),
    [TRAINER_CLASS_DOME_ACE] = _("STAR DU DOME"),
    [TRAINER_CLASS_PALACE_MAVEN] = _("CAPT. PALACE"),
    [TRAINER_CLASS_ARENA_TYCOON] = _("PRO DU DOJO"),
    [TRAINER_CLASS_FACTORY_HEAD] = _("CHEF D'USINE"),
    [TRAINER_CLASS_PIKE_QUEEN] = _("REINE VENIN"),
    [TRAINER_CLASS_PYRAMID_KING] = _("ROI PYRAMIDE"),
    [TRAINER_CLASS_PKMN_TRAINER_4] = _("DRESSEUR"),
};

#else

const u8 gTrainerClassNames[][13] = {
    [TRAINER_CLASS_PKMN_TRAINER_1] = _("{PKMN} TRAINER"),
    [TRAINER_CLASS_PKMN_TRAINER_2] = _("{PKMN} TRAINER"),
    [TRAINER_CLASS_HIKER] = _("HIKER"),
    [TRAINER_CLASS_TEAM_AQUA] = _("TEAM AQUA"),
    [TRAINER_CLASS_PKMN_BREEDER] = _("{PKMN} BREEDER"),
    [TRAINER_CLASS_COOLTRAINER] = _("COOLTRAINER"),
    [TRAINER_CLASS_BIRD_KEEPER] = _("BIRD KEEPER"),
    [TRAINER_CLASS_COLLECTOR] = _("COLLECTOR"),
    [TRAINER_CLASS_SWIMMER_M] = _("SWIMMER♂"),
    [TRAINER_CLASS_TEAM_MAGMA] = _("TEAM MAGMA"),
    [TRAINER_CLASS_EXPERT] = _("EXPERT"),
    [TRAINER_CLASS_AQUA_ADMIN] = _("AQUA ADMIN"),
    [TRAINER_CLASS_BLACK_BELT] = _("BLACK BELT"),
    [TRAINER_CLASS_AQUA_LEADER] = _("AQUA LEADER"),
    [TRAINER_CLASS_HEX_MANIAC] = _("HEX MANIAC"),
    [TRAINER_CLASS_AROMA_LADY] = _("AROMA LADY"),
    [TRAINER_CLASS_RUIN_MANIAC] = _("RUIN MANIAC"),
    [TRAINER_CLASS_INTERVIEWER] = _("INTERVIEWER"),
    [TRAINER_CLASS_TUBER_F] = _("TUBER"),
    [TRAINER_CLASS_TUBER_M] = _("TUBER"),
    [TRAINER_CLASS_LADY] = _("LADY"),
    [TRAINER_CLASS_BEAUTY] = _("BEAUTY"),
    [TRAINER_CLASS_RICH_BOY] = _("RICH BOY"),
    [TRAINER_CLASS_POKEMANIAC] = _("POKéMANIAC"),
    [TRAINER_CLASS_GUITARIST] = _("GUITARIST"),
    [TRAINER_CLASS_KINDLER] = _("KINDLER"),
    [TRAINER_CLASS_CAMPER] = _("CAMPER"),
    [TRAINER_CLASS_PICNICKER] = _("PICNICKER"),
    [TRAINER_CLASS_BUG_MANIAC] = _("BUG MANIAC"),
    [TRAINER_CLASS_PSYCHIC] = _("PSYCHIC"),
    [TRAINER_CLASS_GENTLEMAN] = _("GENTLEMAN"),
    [TRAINER_CLASS_ELITE_FOUR] = _("ELITE FOUR"),
    [TRAINER_CLASS_LEADER] = _("LEADER"),
    [TRAINER_CLASS_SCHOOL_KID] = _("SCHOOL KID"),
    [TRAINER_CLASS_SR_AND_JR] = _("SR. AND JR."),
    [TRAINER_CLASS_WINSTRATE] = _("WINSTRATE"),
    [TRAINER_CLASS_POKEFAN] = _("POKéFAN"),
    [TRAINER_CLASS_YOUNGSTER] = _("YOUNGSTER"),
    [TRAINER_CLASS_CHAMPION] = _("CHAMPION"),
    [TRAINER_CLASS_FISHERMAN] = _("FISHERMAN"),
    [TRAINER_CLASS_TRIATHLETE] = _("TRIATHLETE"),
    [TRAINER_CLASS_DRAGON_TAMER] = _("DRAGON TAMER"),
    [TRAINER_CLASS_NINJA_BOY] = _("NINJA BOY"),
    [TRAINER_CLASS_BATTLE_GIRL] = _("BATTLE GIRL"),
    [TRAINER_CLASS_PARASOL_LADY] = _("PARASOL LADY"),
    [TRAINER_CLASS_SWIMMER_F] = _("SWIMMER♀"),
    [TRAINER_CLASS_TWINS] = _("TWINS"),
    [TRAINER_CLASS_SAILOR] = _("SAILOR"),
    [TRAINER_CLASS_COOLTRAINER_2] = _("COOLTRAINER"),
    [TRAINER_CLASS_MAGMA_ADMIN] = _("MAGMA ADMIN"),
    [TRAINER_CLASS_PKMN_TRAINER_3] = _("{PKMN} TRAINER"),
    [TRAINER_CLASS_BUG_CATCHER] = _("BUG CATCHER"),
    [TRAINER_CLASS_PKMN_RANGER] = _("{PKMN} RANGER"),
    [TRAINER_CLASS_MAGMA_LEADER] = _("MAGMA LEADER"),
    [TRAINER_CLASS_LASS] = _("LASS"),
    [TRAINER_CLASS_YOUNG_COUPLE] = _("YOUNG COUPLE"),
    [TRAINER_CLASS_OLD_COUPLE] = _("OLD COUPLE"),
    [TRAINER_CLASS_SIS_AND_BRO] = _("SIS AND BRO"),
    [TRAINER_CLASS_SALON_MAIDEN] = _("SALON MAIDEN"),
    [TRAINER_CLASS_DOME_ACE] = _("DOME ACE"),
    [TRAINER_CLASS_PALACE_MAVEN] = _("PALACE MAVEN"),
    [TRAINER_CLASS_ARENA_TYCOON] = _("ARENA TYCOON"),
    [TRAINER_CLASS_FACTORY_HEAD] = _("FACTORY HEAD"),
    [TRAINER_CLASS_PIKE_QUEEN] = _("PIKE QUEEN"),
    [TRAINER_CLASS_PYRAMID_KING] = _("PYRAMID KING"),
    [TRAINER_CLASS_RS_PROTAG] = _("{PKMN} TRAINER"),
};
#endif