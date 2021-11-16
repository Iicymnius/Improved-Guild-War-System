//find;

void CGuildManager::RequestWarOver(DWORD dwGuild1, DWORD dwGuild2, DWORD dwGuildWinner, long lReward)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::RequestWarOver(DWORD dwGuild1, DWORD dwGuild2, DWORD dwGuildWinner, long lReward, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::RequestWarOver(DWORD dwGuild1, DWORD dwGuild2, DWORD dwGuildWinner, long lReward)
#endif

//find again;

	db_clientdesc->DBPacket(HEADER_GD_GUILD_WAR, 0, &p, sizeof(p));
	sys_log(0, "RequestWarOver : winner %u loser %u draw %u betprice %d", p.dwGuildFrom, p.dwGuildTo, p.bType, p.lWarPrice);

//add above;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	p.iMaxPlayer = iMaxPlayer;
	p.iMaxScore = iMaxScore;
#endif

//find again;

void CGuildManager::DeclareWar(DWORD guild_id1, DWORD guild_id2, BYTE bType)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::DeclareWar(DWORD guild_id1, DWORD guild_id2, BYTE bType, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::DeclareWar(DWORD guild_id1, DWORD guild_id2, BYTE bType)
#endif

//find again;

	if (g1->DeclareWar(guild_id2, bType, GUILD_WAR_SEND_DECLARE) &&
		g2->DeclareWar(guild_id1, bType, GUILD_WAR_RECV_DECLARE))

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	if (g1->DeclareWar(guild_id2, bType, GUILD_WAR_SEND_DECLARE, iMaxPlayer, iMaxScore) &&
		g2->DeclareWar(guild_id1, bType, GUILD_WAR_RECV_DECLARE, iMaxPlayer, iMaxScore))
#else
	if (g1->DeclareWar(guild_id2, bType, GUILD_WAR_SEND_DECLARE) &&
		g2->DeclareWar(guild_id1, bType, GUILD_WAR_RECV_DECLARE))
#endif

//find again;

void CGuildManager::RefuseWar(DWORD guild_id1, DWORD guild_id2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::RefuseWar(DWORD guild_id1, DWORD guild_id2, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::RefuseWar(DWORD guild_id1, DWORD guild_id2)
#endif

//find again;

	if (g1 != NULL)
		g1->RefuseWar(guild_id2);

	if (g2 != NULL && g1 != NULL)
		g2->RefuseWar(g1->GetID());

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	if (g1)
		g1->RefuseWar(guild_id2, iMaxPlayer, iMaxScore);
	if (g2 && g1)
		g2->RefuseWar(g1->GetID(), iMaxPlayer, iMaxScore);
#else
	if (g1 != NULL)
		g1->RefuseWar(guild_id2);

	if (g2 != NULL && g1 != NULL)
		g2->RefuseWar(g1->GetID());
#endif

//find again;

void CGuildManager::WaitStartWar(DWORD guild_id1, DWORD guild_id2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::WaitStartWar(DWORD guild_id1, DWORD guild_id2, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::WaitStartWar(DWORD guild_id1, DWORD guild_id2)
#endif

//find again;

		sys_log(0, "GuildWar: CGuildManager::WaitStartWar(%d,%d) - something wrong in arg. there is no guild like that.", guild_id1, guild_id2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar: CGuildManager::WaitStartWar(%d,%d | %d,%d) - something wrong in arg. there is no guild like that.", guild_id1, guild_id2, iMaxPlayer, iMaxScore);
#else
		sys_log(0, "GuildWar: CGuildManager::WaitStartWar(%d,%d) - something wrong in arg. there is no guild like that.", guild_id1, guild_id2);
#endif

//find again;

	if (g1->WaitStartWar(guild_id2) || g2->WaitStartWar(guild_id1))

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	if (g1->WaitStartWar(guild_id2, iMaxPlayer, iMaxScore) || g2->WaitStartWar(guild_id1, iMaxPlayer, iMaxScore))
#else
	if (g1->WaitStartWar(guild_id2) || g2->WaitStartWar(guild_id1))
#endif

//find again;

void CGuildManager::StartWar(DWORD guild_id1, DWORD guild_id2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::StartWar(DWORD guild_id1, DWORD guild_id2, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::StartWar(DWORD guild_id1, DWORD guild_id2)
#endif

//find again;

	g1->StartWar(guild_id2);
	g2->StartWar(guild_id1);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	g1->StartWar(guild_id2, iMaxPlayer, iMaxScore);
	g2->StartWar(guild_id1, iMaxPlayer, iMaxScore);
#else
	g1->StartWar(guild_id2);
	g2->StartWar(guild_id1);
#endif

//find again;

void CGuildManager::CancelWar(DWORD guild_id1, DWORD guild_id2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::CancelWar(DWORD guild_id1, DWORD guild_id2, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::CancelWar(DWORD guild_id1, DWORD guild_id2)
#endif

//find again;

void CGuildManager::ReserveWar(DWORD dwGuild1, DWORD dwGuild2, BYTE bType)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::ReserveWar(DWORD dwGuild1, DWORD dwGuild2, BYTE bType, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::ReserveWar(DWORD dwGuild1, DWORD dwGuild2, BYTE bType) // from DB
#endif

//find again;

	g1->ReserveWar(dwGuild2, bType);
	g2->ReserveWar(dwGuild1, bType);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	g1->ReserveWar(dwGuild2, bType, iMaxPlayer, iMaxScore);
	g2->ReserveWar(dwGuild1, bType, iMaxPlayer, iMaxScore);
#else
	g1->ReserveWar(dwGuild2, bType);
	g2->ReserveWar(dwGuild1, bType);
#endif