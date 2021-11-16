//find;

		FSendPeerWar(BYTE bType, BYTE bWar, DWORD GID1, DWORD GID2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		FSendPeerWar(BYTE bType, BYTE bWar, DWORD GID1, DWORD GID2, int iMaxPlayer, int iMaxScore)
#else
		FSendPeerWar(BYTE bType, BYTE bWar, DWORD GID1, DWORD GID2)
#endif

//find again;

			p.dwGuildTo = GID2;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			p.iMaxPlayer = iMaxPlayer;
			p.iMaxScore = iMaxScore;
#endif

//find again;

		StartWar(ws.bType, ws.GID[0], ws.GID[1], ws.pkReserve);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		StartWar(ws.bType, ws.GID[0], ws.GID[1], ws.pkReserve, ws.iMaxPlayer, ws.iMaxScore);
#else
		StartWar(ws.bType, ws.GID[0], ws.GID[1], ws.pkReserve);
#endif

//find again;

		p.dwGuildTo = ws.GID[1];

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		p.iMaxPlayer = ws.iMaxPlayer;
		p.iMaxScore = ws.iMaxScore;
#endif

//find again;

		FSendPeerWar(p->bType, GUILD_WAR_ON_WAR, g1, g2) (peer);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		FSendPeerWar(p->bType, GUILD_WAR_ON_WAR, g1, g2, p->iMaxPlayer, p->iMaxScore) (peer);
#else
		FSendPeerWar(p->bType, GUILD_WAR_ON_WAR, g1, g2) (peer);
#endif

//find again;

		FSendPeerWar(it->bType, GUILD_WAR_SEND_DECLARE, it->dwGuildID[0], it->dwGuildID[1]) (peer);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		FSendPeerWar(it->bType, GUILD_WAR_SEND_DECLARE, it->dwGuildID[0], it->dwGuildID[1], it->iMaxPlayer, it->iMaxScore) (peer);
#else
		FSendPeerWar(it->bType, GUILD_WAR_SEND_DECLARE, it->dwGuildID[0], it->dwGuildID[1]) (peer);
#endif

//find again;

	CClientManager::instance().for_each_peer(FSendPeerWar(0, GUILD_WAR_END, GID1, GID2));

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	CClientManager::instance().for_each_peer(FSendPeerWar(0, GUILD_WAR_END, GID1, GID2, pData->iMaxPlayer, pData->iMaxScore));
#else
	CClientManager::instance().for_each_peer(FSendPeerWar(0, GUILD_WAR_END, GID1, GID2));
#endif

//find again;

void CGuildManager::RecvWarOver(DWORD dwGuildWinner, DWORD dwGuildLoser, bool bDraw, long lWarPrice)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::RecvWarOver(DWORD dwGuildWinner, DWORD dwGuildLoser, bool bDraw, long lWarPrice, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::RecvWarOver(DWORD dwGuildWinner, DWORD dwGuildLoser, bool bDraw, long lWarPrice)
#endif

//find again;

	sys_log(0, "GuildWar: RecvWarOver : winner %u vs %u draw? %d war_price %d", dwGuildWinner, dwGuildLoser, bDraw ? 1 : 0, lWarPrice);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	sys_log(0, "GuildWar: RecvWarOver : winner %u vs %u draw? %d war_price %d MaxPlayer %d MaxScore %d", dwGuildWinner, dwGuildLoser, bDraw ? 1 : 0, lWarPrice, iMaxPlayer, iMaxScore);
#else
	sys_log(0, "GuildWar: RecvWarOver : winner %u vs %u draw? %d war_price %d", dwGuildWinner, dwGuildLoser, bDraw ? 1 : 0, lWarPrice);
#endif

//find again;

void CGuildManager::RecvWarEnd(DWORD GID1, DWORD GID2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::RecvWarEnd(DWORD GID1, DWORD GID2, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::RecvWarEnd(DWORD GID1, DWORD GID2)
#endif

//find again;

	sys_log(0, "GuildWar: RecvWarEnded : %u vs %u", GID1, GID2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	sys_log(0, "GuildWar: RecvWarEnded : %u vs %u with MaxPlayer %d MaxScore %d", GID1, GID2, iMaxPlayer, iMaxScore);
#else
	sys_log(0, "GuildWar: RecvWarEnded : %u vs %u", GID1, GID2);
#endif

//find again;

void CGuildManager::StartWar(BYTE bType, DWORD GID1, DWORD GID2, CGuildWarReserve* pkReserve)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::StartWar(BYTE bType, DWORD GID1, DWORD GID2, CGuildWarReserve* pkReserve, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::StartWar(BYTE bType, DWORD GID1, DWORD GID2, CGuildWarReserve* pkReserve)
#endif

//find again;

	sys_log(0, "GuildWar: StartWar(%d,%d,%d)", bType, GID1, GID2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	sys_log(0, "GuildWar: StartWar(%d,%d,%d,%d,%d)", bType, GID1, GID2, iMaxPlayer, iMaxScore);
#else
	sys_log(0, "GuildWar: StartWar(%d,%d,%d)", bType, GID1, GID2);
#endif

//find again;

	gw.pElement = new TGuildWarPQElement(bType, GID1, GID2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	gw.pElement = new TGuildWarPQElement(bType, GID1, GID2, iMaxPlayer, iMaxScore);
#else
	gw.pElement = new TGuildWarPQElement(bType, GID1, GID2);
#endif

//find again;

		sys_log(0, "GuildWar: SendGuildWarScore guild %u wartype %u score_delta %d betscore_delta %d result %u, %u",
			dwGainGID, p->bType, iScoreDelta, iBetScoreDelta, iNewScore, iNewBetScore);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar: SendGuildWarScore guild %u wartype %u score_delta %d betscore_delta %d result %u, %u max score: %u",
			dwGainGID, p->bType, iScoreDelta, iBetScoreDelta, iNewScore, iNewBetScore, p->iMaxScore);
#else
		sys_log(0, "GuildWar: SendGuildWarScore guild %u wartype %u score_delta %d betscore_delta %d result %u, %u",
			dwGainGID, p->bType, iScoreDelta, iBetScoreDelta, iNewScore, iNewBetScore);
#endif

//find again;

void CGuildManager::AddDeclare(BYTE bType, DWORD guild_from, DWORD guild_to)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::AddDeclare(BYTE bType, DWORD guild_from, DWORD guild_to, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::AddDeclare(BYTE bType, DWORD guild_from, DWORD guild_to)
#endif

//find again;

	TGuildDeclareInfo di(bType, guild_from, guild_to);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	TGuildDeclareInfo di(bType, guild_from, guild_to, iMaxPlayer, iMaxScore);
#else
	TGuildDeclareInfo di(bType, guild_from, guild_to);
#endif

//find again;

	sys_log(0, "GuildWar: AddDeclare(Type:%d,from:%d,to:%d)", bType, guild_from, guild_to);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	sys_log(0, "GuildWar: AddDeclare(Type:%d,from:%d,to:%d,maxplayer:%d,maxscore:%d)", bType, guild_from, guild_to, iMaxPlayer, iMaxScore);
#else
	sys_log(0, "GuildWar: AddDeclare(Type:%d,from:%d,to:%d)", bType, guild_from, guild_to);
#endif

//find again;

void CGuildManager::RemoveDeclare(DWORD guild_from, DWORD guild_to)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::RemoveDeclare(DWORD guild_from, DWORD guild_to, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::RemoveDeclare(DWORD guild_from, DWORD guild_to)
#endif

//find again;

	typeof(m_DeclareMap.begin()) it = m_DeclareMap.find(TGuildDeclareInfo(0, guild_from, guild_to));

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	typeof(m_DeclareMap.begin()) it = m_DeclareMap.find(TGuildDeclareInfo(0, guild_from, guild_to, iMaxPlayer, iMaxScore));
#else
	typeof(m_DeclareMap.begin()) it = m_DeclareMap.find(TGuildDeclareInfo(0, guild_from, guild_to));
#endif

//find again;

	it = m_DeclareMap.find(TGuildDeclareInfo(0, guild_to, guild_from));

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	it = m_DeclareMap.find(TGuildDeclareInfo(0, guild_to, guild_from, iMaxPlayer, iMaxScore));
#else
	it = m_DeclareMap.find(TGuildDeclareInfo(0, guild_to, guild_from));
#endif

//find again;

	sys_log(0, "GuildWar: RemoveDeclare(from:%d,to:%d)", guild_from, guild_to);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	sys_log(0, "GuildWar: RemoveDeclare(from:%d,to:%d,maxplayer:%d,maxscore:%d)", guild_from, guild_to, iMaxPlayer, iMaxScore);
#else
	sys_log(0, "GuildWar: RemoveDeclare(from:%d,to:%d)", guild_from, guild_to);
#endif

//find again;

	TGuildWaitStartInfo info(p->bType, p->dwGuildFrom, p->dwGuildTo, p->lWarPrice, p->lInitialScore, NULL);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	TGuildWaitStartInfo info(p->bType, p->dwGuildFrom, p->dwGuildTo, p->lWarPrice, p->lInitialScore, NULL, p->iMaxPlayer, p->iMaxScore);
#else
	TGuildWaitStartInfo info(p->bType, p->dwGuildFrom, p->dwGuildTo, p->lWarPrice, p->lInitialScore, NULL);
#endif

//find again;

		"GuildWar: WaitStart g1 %d g2 %d price %d start at %u",

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		"GuildWar: WaitStart g1 %d g2 %d price %d start at %u max player %d max score %d",
#else
		"GuildWar: WaitStart g1 %d g2 %d price %d start at %u",
#endif

//find again;

		dwCurTime + GetGuildWarWaitStartDuration());

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		dwCurTime + GetGuildWarWaitStartDuration(),
		p->iMaxPlayer,
		p->iMaxScore);
#else
		dwCurTime + GetGuildWarWaitStartDuration());
#endif

//find again;

		"SELECT id, guild1, guild2, UNIX_TIMESTAMP(time), type, warprice, initscore, bet_from, bet_to, power1, power2, handicap FROM guild_war_reservation WHERE started=1 AND winner=-1",
		"SELECT id, guild1, guild2, UNIX_TIMESTAMP(time), type, warprice, initscore, bet_from, bet_to, power1, power2, handicap FROM guild_war_reservation WHERE started=0"

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		"SELECT id, guild1, guild2, UNIX_TIMESTAMP(time), type, warprice, initscore, bet_from, bet_to, power1, power2, handicap, max_player, max_score FROM guild_war_reservation WHERE started=1 AND winner=-1",
		"SELECT id, guild1, guild2, UNIX_TIMESTAMP(time), type, warprice, initscore, bet_from, bet_to, power1, power2, handicap, max_player, max_score FROM guild_war_reservation WHERE started=0"
#else
		"SELECT id, guild1, guild2, UNIX_TIMESTAMP(time), type, warprice, initscore, bet_from, bet_to, power1, power2, handicap FROM guild_war_reservation WHERE started=1 AND winner=-1",
		"SELECT id, guild1, guild2, UNIX_TIMESTAMP(time), type, warprice, initscore, bet_from, bet_to, power1, power2, handicap FROM guild_war_reservation WHERE started=0"
#endif

//find again;

			str_to_number(t.lHandicap, row[col++]);

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			str_to_number(t.iMaxPlayer, row[col++]);
			str_to_number(t.iMaxScore, row[col++]);
#endif

//find again;

			snprintf(buf, sizeof(buf), "GuildWar: BootReserveWar : step %d id %u GID1 %u GID2 %u", i, t.dwID, t.dwGuildFrom, t.dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			snprintf(buf, sizeof(buf), "GuildWar: BootReserveWar : step %d id %u GID1 %u GID2 %u max player %d max score %d", i, t.dwID, t.dwGuildFrom, t.dwGuildTo, t.iMaxPlayer, t.iMaxScore);
#else
			snprintf(buf, sizeof(buf), "GuildWar: BootReserveWar : step %d id %u GID1 %u GID2 %u", i, t.dwID, t.dwGuildFrom, t.dwGuildTo);
#endif

//find again;

	t.lInitialScore = p->lInitialScore;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	t.iMaxPlayer = p->iMaxPlayer;
	t.iMaxScore = p->iMaxScore;
#endif

//find again;

	snprintf(szQuery, sizeof(szQuery),
		"INSERT INTO guild_war_reservation (guild1, guild2, time, type, warprice, initscore, power1, power2, handicap) "
		"VALUES(%u, %u, DATE_ADD(NOW(), INTERVAL 180 SECOND), %u, %ld, %ld, %ld, %ld, %ld)",
		GID1, GID2, p->bType, p->lWarPrice, p->lInitialScore, t.lPowerFrom, t.lPowerTo, t.lHandicap);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	snprintf(szQuery, sizeof(szQuery),
		"INSERT INTO guild_war_reservation (guild1, guild2, time, type, warprice, initscore, power1, power2, handicap, max_player, max_score) "
		"VALUES(%u, %u, DATE_ADD(NOW(), INTERVAL 180 SECOND), %u, %ld, %ld, %ld, %ld, %ld, %d, %d)",
		GID1, GID2, p->bType, p->lWarPrice, p->lInitialScore, t.lPowerFrom, t.lPowerTo, t.lHandicap, t.iMaxPlayer, t.iMaxScore);
#else
	snprintf(szQuery, sizeof(szQuery),
		"INSERT INTO guild_war_reservation (guild1, guild2, time, type, warprice, initscore, power1, power2, handicap) "
		"VALUES(%u, %u, DATE_ADD(NOW(), INTERVAL 180 SECOND), %u, %ld, %ld, %ld, %ld, %ld)",
		GID1, GID2, p->bType, p->lWarPrice, p->lInitialScore, t.lPowerFrom, t.lPowerTo, t.lHandicap);
#endif

//find again;

			sys_log(0, "GuildWar: started GID1 %u GID2 %u %d time %d min %d", r.dwGuildFrom, r.dwGuildTo, r.bStarted, dwCurTime - r.dwTime, iMin);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			sys_log(0, "GuildWar: started GID1 %u GID2 %u %d time %d min %d maxplayer %d maxscore %d", r.dwGuildFrom, r.dwGuildTo, r.bStarted, dwCurTime - r.dwTime, iMin, r.iMaxPlayer, r.iMaxScore);
#else
			sys_log(0, "GuildWar: started GID1 %u GID2 %u %d time %d min %d", r.dwGuildFrom, r.dwGuildTo, r.bStarted, dwCurTime - r.dwTime, iMin);
#endif

//find again;

				TGuildWaitStartInfo info(r.bType, r.dwGuildFrom, r.dwGuildTo, r.lWarPrice, r.lInitialScore, pk);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
				TGuildWaitStartInfo info(r.bType, r.dwGuildFrom, r.dwGuildTo, r.lWarPrice, r.lInitialScore, pk, r.iMaxPlayer, r.iMaxScore);
#else
				TGuildWaitStartInfo info(r.bType, r.dwGuildFrom, r.dwGuildTo, r.lWarPrice, r.lInitialScore, pk);
#endif

//find again;

				pck.lInitialScore = r.lInitialScore;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
				pck.iMaxPlayer = r.iMaxPlayer;
				pck.iMaxScore = r.iMaxScore;
#endif

//find again;

void CGuildManager::CancelWar(DWORD GID1, DWORD GID2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
void CGuildManager::CancelWar(DWORD GID1, DWORD GID2, int iMaxPlayer, int iMaxScore)
#else
void CGuildManager::CancelWar(DWORD GID1, DWORD GID2)
#endif

//find again;

	RemoveDeclare(GID1, GID2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	RemoveDeclare(GID1, GID2, iMaxPlayer, iMaxScore);
#else
	RemoveDeclare(GID1, GID2);
#endif

//find again;

	FSendPeerWar(m_data.bType, GUILD_WAR_RESERVE, m_data.dwGuildFrom, m_data.dwGuildTo) (peer);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	FSendPeerWar(m_data.bType, GUILD_WAR_RESERVE, m_data.dwGuildFrom, m_data.dwGuildTo, m_data.iMaxPlayer, m_data.iMaxScore) (peer);
#else
	FSendPeerWar(m_data.bType, GUILD_WAR_RESERVE, m_data.dwGuildFrom, m_data.dwGuildTo) (peer);
#endif