//find;

void CGuild::GuildWarPacket(DWORD dwOppGID, BYTE bWarType, BYTE bWarState)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuild::GuildWarPacket(DWORD dwOppGID, BYTE bWarType, BYTE bWarState, int iMaxPlayer, int iMaxScore)
#else
void CGuild::GuildWarPacket(DWORD dwOppGID, BYTE bWarType, BYTE bWarState)
#endif

//find again;

	pack2.bType = bWarType;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	pack2.iMaxPlayer = iMaxPlayer;
	pack2.iMaxScore = iMaxScore;
#endif

//find again;

void CGuild::RequestDeclareWar(DWORD dwOppGID, BYTE type)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuild::RequestDeclareWar(DWORD dwOppGID, BYTE type, int iMaxPlayer, int iMaxScore)
#else
void CGuild::RequestDeclareWar(DWORD dwOppGID, BYTE type)
#endif

//find again;

		sys_log(0, "GuildWar.DeclareWar.DECLARE_WAR_SELF id(%d -> %d), type(%d)", GetID(), dwOppGID, type);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.DeclareWar.DECLARE_WAR_SELF id(%d -> %d), type(%d) max_player(%d) max_score(%d)", GetID(), dwOppGID, type, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.DeclareWar.DECLARE_WAR_SELF id(%d -> %d), type(%d)", GetID(), dwOppGID, type);
#endif

//find again;

		sys_log(0, "GuildWar.DeclareWar.UNKNOWN_WAR_TYPE id(%d -> %d), type(%d)", GetID(), dwOppGID, type);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.DeclareWar.UNKNOWN_WAR_TYPE id(%d -> %d), type(%d) max_player(%d) max_score(%d)", GetID(), dwOppGID, type, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.DeclareWar.UNKNOWN_WAR_TYPE id(%d -> %d), type(%d)", GetID(), dwOppGID, type);
#endif

//find again;

			sys_err("GuildWar.DeclareWar.NOT_EXIST_MAP id(%d -> %d), type(%d), map(%d)",
				GetID(), dwOppGID, type, GuildWar_GetTypeMapIndex(type));

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			sys_err("GuildWar.DeclareWar.NOT_EXIST_MAP id(%d -> %d), type(%d), map(%d) max_player(%d) max_score(%d)",
				GetID(), dwOppGID, type, GuildWar_GetTypeMapIndex(type), iMaxPlayer, iMaxScore);
#else
			sys_err("GuildWar.DeclareWar.NOT_EXIST_MAP id(%d -> %d), type(%d), map(%d)",
				GetID(), dwOppGID, type, GuildWar_GetTypeMapIndex(type));
#endif

//find again;

		p.dwGuildTo = dwOppGID;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		p.iMaxPlayer = iMaxPlayer;
		p.iMaxScore = iMaxScore;
#endif

//find again;

		sys_log(0, "GuildWar.DeclareWar id(%d -> %d), type(%d)", GetID(), dwOppGID, type);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.DeclareWar id(%d -> %d), type(%d) max_player(%d) max_score(%d)", GetID(), dwOppGID, type, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.DeclareWar id(%d -> %d), type(%d)", GetID(), dwOppGID, type);
#endif

//find again;

		const unsigned saved_type = it->second.type;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		int saved_maxplayer = it->second.max_player;
		int saved_maxscore = it->second.max_score;

		sys_log(0, "GuildWar.AcceptWar id(%d -> %d) type(%d) saved_type(%d) max_player(%d) saved_max_player(%d) max_score(%d) saved_max_score(%d)",
			GetID(), dwOppGID, type, saved_type, iMaxPlayer, saved_maxplayer, iMaxScore, saved_maxscore);
#endif

//find again;

			p.dwGuildTo = dwOppGID;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			p.iMaxPlayer = saved_maxplayer;
			p.iMaxScore = saved_maxscore;
#endif

//find again;

			sys_log(0, "GuildWar.AcceptWar id(%d -> %d), type(%d)", GetID(), dwOppGID, saved_type);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			sys_log(0, "GuildWar.AcceptWar id(%d -> %d), type(%d) max_player(%d) max_score(%d)", GetID(), dwOppGID, saved_type, saved_maxplayer, saved_maxscore);
#else
			sys_log(0, "GuildWar.AcceptWar id(%d -> %d), type(%d)", GetID(), dwOppGID, saved_type);
#endif

//find again;

			sys_err("GuildWar.AcceptWar.NOT_EXIST_MAP id(%d -> %d), type(%d), map(%d)",
				GetID(), dwOppGID, type, GuildWar_GetTypeMapIndex(type));

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			sys_err("GuildWar.AcceptWar.NOT_EXIST_MAP id(%d -> %d), type(%d), map(%d) max_player(%d) max_score(%d)",
				GetID(), dwOppGID, type, GuildWar_GetTypeMapIndex(type), saved_maxplayer, saved_maxscore);
#else
			sys_err("GuildWar.AcceptWar.NOT_EXIST_MAP id(%d -> %d), type(%d), map(%d)",
				GetID(), dwOppGID, type, GuildWar_GetTypeMapIndex(type));
#endif

//find again;

		const TGuildWarInfo& guildWarInfo = GuildWar_GetTypeInfo(saved_type);

//add above;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		if (saved_type != type)
		{
			sys_err("GuildWar.AcceptWar.NOT_SAME_TYPE id(%d -> %d), type(%d), saved_type(%d)",
				GetID(), dwOppGID, type, saved_type);
			return;
		}
		if (saved_maxplayer != iMaxPlayer)
		{
			sys_err("GuildWar.AcceptWar.NOT_SAME_MAXPLAYER id(%d -> %d), type(%d), map(%d) max_player(%d) target_max_player(%d)",
				GetID(), dwOppGID, type, GuildWar_GetTypeMapIndex(type), iMaxPlayer, saved_maxplayer);
			return;
		}
		if (saved_maxscore != iMaxScore)
		{
			sys_err("GuildWar.AcceptWar.NOT_SAME_MAXSCORE id(%d -> %d), type(%d), map(%d) max_score(%d) target_max_score(%d)",
				GetID(), dwOppGID, type, GuildWar_GetTypeMapIndex(type), iMaxScore, saved_maxscore);
			return;
		}
#endif

//find again;

		p.lInitialScore = guildWarInfo.iInitialScore;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		p.iMaxPlayer = saved_maxplayer;
		p.iMaxScore = saved_maxscore;
#endif

//find again;

		sys_log(0, "GuildWar.WaitStartSendToDB id(%d vs %d), type(%d), bet(%d), map_index(%d)",
			GetID(), dwOppGID, saved_type, guildWarInfo.iWarPrice, guildWarInfo.lMapIndex);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.WaitStartSendToDB id(%d vs %d), type(%d), bet(%d), map_index(%d) max_player(%d) max_score(%d)",
			GetID(), dwOppGID, saved_type, guildWarInfo.iWarPrice, guildWarInfo.lMapIndex, saved_maxplayer, saved_maxscore);
#else
		sys_log(0, "GuildWar.WaitStartSendToDB id(%d vs %d), type(%d), bet(%d), map_index(%d)",
			GetID(), dwOppGID, saved_type, guildWarInfo.iWarPrice, guildWarInfo.lMapIndex);
#endif

//find again;

		sys_err("GuildWar.DeclareWar.UNKNOWN_STATE[%d]: id(%d vs %d), type(%d), guild(%s:%u)",
			it->second.state, GetID(), dwOppGID, type, GetName(), GetID());

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_err("GuildWar.DeclareWar.UNKNOWN_STATE[%d]: id(%d vs %d), type(%d), guild(%s:%u) max_player(%d) max_score(%d)",
			it->second.state, GetID(), dwOppGID, type, GetName(), GetID(), iMaxPlayer, iMaxScore);
#else
		sys_err("GuildWar.DeclareWar.UNKNOWN_STATE[%d]: id(%d vs %d), type(%d), guild(%s:%u)",
			it->second.state, GetID(), dwOppGID, type, GetName(), GetID());
#endif

//find again;

bool CGuild::DeclareWar(DWORD dwOppGID, BYTE type, BYTE state)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
bool CGuild::DeclareWar(DWORD dwOppGID, BYTE type, BYTE state, int iMaxPlayer, int iMaxScore)
#else
bool CGuild::DeclareWar(DWORD dwOppGID, BYTE type, BYTE state)
#endif

//find again;

	gw.state = state;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	gw.max_player = iMaxPlayer;
	gw.max_score = iMaxScore;
#endif

//find again;

	GuildWarPacket(dwOppGID, type, state);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	GuildWarPacket(dwOppGID, type, state, iMaxPlayer, iMaxScore);
#else
	GuildWarPacket(dwOppGID, type, state);
#endif

//find again;

void CGuild::StartWar(DWORD dwOppGID)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuild::StartWar(DWORD dwOppGID, int iMaxPlayer, int iMaxScore)
#else
void CGuild::StartWar(DWORD dwOppGID)
#endif

//find again;

	GuildWarPacket(dwOppGID, gw.type, GUILD_WAR_ON_WAR);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	gw.max_player = iMaxPlayer;
	gw.max_score = iMaxScore;

	GuildWarPacket(dwOppGID, gw.type, GUILD_WAR_ON_WAR, gw.max_player, gw.max_score);
#else
	GuildWarPacket(dwOppGID, gw.type, GUILD_WAR_ON_WAR);
#endif

//find again;

bool CGuild::WaitStartWar(DWORD dwOppGID)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
bool CGuild::WaitStartWar(DWORD dwOppGID, int iMaxPlayer, int iMaxScore)
#else
bool CGuild::WaitStartWar(DWORD dwOppGID)
#endif

//find again;

		sys_log(0, "GuildWar.WaitStartWar.DECLARE_WAR_SELF id(%u -> %u)", GetID(), dwOppGID);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.WaitStartWar.DECLARE_WAR_SELF id(%u -> %u) max_player(%d) max_score(%d)", GetID(), dwOppGID, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.WaitStartWar.DECLARE_WAR_SELF id(%u -> %u)", GetID(), dwOppGID);
#endif

//find again;

		sys_log(0, "GuildWar.WaitStartWar.UNKNOWN_ENEMY id(%u -> %u)", GetID(), dwOppGID);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.WaitStartWar.UNKNOWN_ENEMY id(%u -> %u) max_player(%d) max_score(%d)", GetID(), dwOppGID, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.WaitStartWar.UNKNOWN_ENEMY id(%u -> %u)", GetID(), dwOppGID);
#endif

//find again;

		sys_log(0, "GuildWar.WaitStartWar.UNKNOWN_STATE id(%u -> %u), state(%d)", GetID(), dwOppGID, gw.state);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.WaitStartWar.UNKNOWN_STATE id(%u -> %u), state(%d) max_player(%d) max_score(%d)", GetID(), dwOppGID, gw.state, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.WaitStartWar.UNKNOWN_STATE id(%u -> %u), state(%d)", GetID(), dwOppGID, gw.state);
#endif

//find again;

		sys_log(0, "GuildWar.WaitStartWar.NOT_EXIST_GUILD id(%u -> %u)", GetID(), dwOppGID);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.WaitStartWar.NOT_EXIST_GUILD id(%u -> %u) max_player(%d) max_score(%d)", GetID(), dwOppGID, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.WaitStartWar.NOT_EXIST_GUILD id(%u -> %u)", GetID(), dwOppGID);
#endif

//find again;

	if (gw.type == GUILD_WAR_TYPE_FIELD)

//add above;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	gw.max_score = iMaxScore;
	gw.max_player = iMaxPlayer;
#endif

//find again;

		sys_log(0, "GuildWar.WaitStartWar.FIELD_TYPE id(%u -> %u)", GetID(), dwOppGID);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.WaitStartWar.FIELD_TYPE id(%u -> %u) max_player(%d) max_score(%d)", GetID(), dwOppGID, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.WaitStartWar.FIELD_TYPE id(%u -> %u)", GetID(), dwOppGID);
#endif

//find again;

	sys_log(0, "GuildWar.WaitStartWar.CheckWarServer id(%u -> %u), type(%d), map(%d)",
		GetID(), dwOppGID, gw.type, rkGuildWarInfo.lMapIndex);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	sys_log(0, "GuildWar.WaitStartWar.CheckWarServer id(%u -> %u), type(%d), map(%d) max_player(%d) max_score(%d)",
		GetID(), dwOppGID, gw.type, rkGuildWarInfo.lMapIndex, iMaxPlayer, iMaxScore);
#else
	sys_log(0, "GuildWar.WaitStartWar.CheckWarServer id(%u -> %u), type(%d), map(%d)",
		GetID(), dwOppGID, gw.type, rkGuildWarInfo.lMapIndex);
#endif

//find again;

		sys_log(0, "GuildWar.WaitStartWar.SKIP_WAR_MAP id(%u -> %u)", GetID(), dwOppGID);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar.WaitStartWar.SKIP_WAR_MAP id(%u -> %u) max_player(%d) max_score(%d)", GetID(), dwOppGID, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar.WaitStartWar.SKIP_WAR_MAP id(%u -> %u)", GetID(), dwOppGID);
#endif

//find again;

	DWORD lMapIndex = CWarMapManager::instance().CreateWarMap(rkGuildWarInfo, id1, id2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	DWORD lMapIndex = CWarMapManager::instance().CreateWarMap(rkGuildWarInfo, id1, id2, iMaxPlayer, iMaxScore);
#else
	DWORD lMapIndex = CWarMapManager::instance().CreateWarMap(rkGuildWarInfo, id1, id2);
#endif

//find again;

		sys_err("GuildWar.WaitStartWar.CREATE_WARMAP_ERROR id(%u vs %u), type(%u), map(%d)", id1, id2, gw.type, rkGuildWarInfo.lMapIndex);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_err("GuildWar.WaitStartWar.CREATE_WARMAP_ERROR id(%u vs %u), type(%u), map(%d) max_player(%d) max_score(%d)", id1, id2, gw.type, rkGuildWarInfo.lMapIndex, iMaxPlayer, iMaxScore);
#else
		sys_err("GuildWar.WaitStartWar.CREATE_WARMAP_ERROR id(%u vs %u), type(%u), map(%d)", id1, id2, gw.type, rkGuildWarInfo.lMapIndex);
#endif

//find again;

	sys_log(0, "GuildWar.WaitStartWar.CreateMap id(%u vs %u), type(%u), map(%d) -> map_inst(%u)", id1, id2, gw.type, rkGuildWarInfo.lMapIndex, lMapIndex);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	sys_log(0, "GuildWar.WaitStartWar.CreateMap id(%u vs %u), type(%u), map(%d) -> map_inst(%u) max_player(%d) max_score(%d)", id1, id2, gw.type, rkGuildWarInfo.lMapIndex, lMapIndex, iMaxPlayer, iMaxScore);
#else
	sys_log(0, "GuildWar.WaitStartWar.CreateMap id(%u vs %u), type(%u), map(%d) -> map_inst(%u)", id1, id2, gw.type, rkGuildWarInfo.lMapIndex, lMapIndex);
#endif

//find again;

void CGuild::RequestRefuseWar(DWORD dwOppGID)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuild::RequestRefuseWar(DWORD dwOppGID, int iMaxPlayer, int iMaxScore)
#else
void CGuild::RequestRefuseWar(DWORD dwOppGID)
#endif

//find again;

		p.dwGuildTo = dwOppGID;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		p.iMaxPlayer = iMaxPlayer;
		p.iMaxScore = iMaxScore;
#endif

//find again;

void CGuild::RefuseWar(DWORD dwOppGID)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuild::RefuseWar(DWORD dwOppGID, int iMaxPlayer, int iMaxScore)
#else
void CGuild::RefuseWar(DWORD dwOppGID)
#endif

//find again;

		GuildWarPacket(dwOppGID, type, GUILD_WAR_END);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		GuildWarPacket(dwOppGID, type, GUILD_WAR_END, iMaxPlayer, iMaxScore);
#else
		GuildWarPacket(dwOppGID, type, GUILD_WAR_END);
#endif

//find again;

void CGuild::ReserveWar(DWORD dwOppGID, BYTE type)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuild::ReserveWar(DWORD dwOppGID, BYTE type, int iMaxPlayer, int iMaxScore)
#else
void CGuild::ReserveWar(DWORD dwOppGID, BYTE type)
#endif

//find again;

		gw.state = GUILD_WAR_RESERVE;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		gw.max_player = iMaxPlayer;
		gw.max_score = iMaxScore;
#endif

//find again;

		GuildWarPacket(dwOppGID, it->second.type, GUILD_WAR_END);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		GuildWarPacket(dwOppGID, it->second.type, GUILD_WAR_END, it->second.max_player, it->second.max_score);
#else
		GuildWarPacket(dwOppGID, it->second.type, GUILD_WAR_END);
#endif