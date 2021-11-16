//find;

CWarMap::CWarMap(long lMapIndex, const TGuildWarInfo& r_info, TWarMapInfo* pkWarMapInfo, DWORD dwGuildID1, DWORD dwGuildID2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
CWarMap::CWarMap(long lMapIndex, const TGuildWarInfo& r_info, TWarMapInfo* pkWarMapInfo, DWORD dwGuildID1, DWORD dwGuildID2, int iMaxPlayer, int iMaxScore)
#else
CWarMap::CWarMap(long lMapIndex, const TGuildWarInfo& r_info, TWarMapInfo* pkWarMapInfo, DWORD dwGuildID1, DWORD dwGuildID2)
#endif

//find again;

	m_TeamData[0].pkGuild = CGuildManager::instance().TouchGuild(dwGuildID1);

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	m_TeamData[0].iMaxPlayer = iMaxPlayer;
	m_TeamData[0].iMaxScore = iMaxScore;
#endif

//find again;

	m_TeamData[1].pkGuild = CGuildManager::instance().TouchGuild(dwGuildID2);

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	m_TeamData[1].iMaxPlayer = iMaxPlayer;
	m_TeamData[1].iMaxScore = iMaxScore;
#endif

//find again;

CGuild* CWarMap::GetGuild(BYTE bIdx)

//add above;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
int CWarMap::GetCurrentPlayer(BYTE bIdx)
{
	assert(bIdx < 2);
	return m_TeamData[bIdx].iMemberCount;
}

int CWarMap::GetMaxPlayer(BYTE bIdx)
{
	assert(bIdx < 2);
	return m_TeamData[bIdx].iMaxPlayer;
}

int CWarMap::GetCurrentScore(BYTE bIdx)
{
	assert(bIdx < 2);
	return m_TeamData[bIdx].iScore;
}

int CWarMap::GetMaxScore(BYTE bIdx)
{
	assert(bIdx < 2);
	return m_TeamData[bIdx].iMaxScore;
}
#endif

//find again;

	CGuildManager::instance().RequestWarOver(m_TeamData[0].dwID, m_TeamData[1].dwID, 0, 0);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	CGuildManager::instance().RequestWarOver(m_TeamData[0].dwID, m_TeamData[1].dwID, 0, 0, 0, 0);
#else
	CGuildManager::instance().RequestWarOver(m_TeamData[0].dwID, m_TeamData[1].dwID, 0, 0);
#endif

//find again;

		CGuildManager::instance().RequestWarOver(dwWinner, dwLoser, dwWinner, iRewardGold);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().RequestWarOver(dwWinner, dwLoser, dwWinner, iRewardGold, m_TeamData[0].iMaxPlayer, m_TeamData[0].iMaxScore);
#else
		CGuildManager::instance().RequestWarOver(dwWinner, dwLoser, dwWinner, iRewardGold);
#endif

//find again;

		CGuildManager::instance().RequestWarOver(m_TeamData[0].dwID, m_TeamData[1].dwID, dwWinner, iRewardGold);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().RequestWarOver(m_TeamData[0].dwID, m_TeamData[1].dwID, dwWinner, iRewardGold, m_TeamData[0].iMaxPlayer, m_TeamData[0].iMaxScore);
#else
		CGuildManager::instance().RequestWarOver(m_TeamData[0].dwID, m_TeamData[1].dwID, dwWinner, iRewardGold);
#endif

//find again;

	int iEndScore = m_WarInfo.iEndScore;

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	int iEndScore = m_TeamData[0].iMaxScore;
#else
	int iEndScore = m_WarInfo.iEndScore;
#endif

//find again;

	CGuildManager::instance().RequestWarOver(dwWinner, dwLoser, dwWinner, iRewardGold);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	CGuildManager::instance().RequestWarOver(dwWinner, dwLoser, dwWinner, iRewardGold, m_TeamData[0].iMaxPlayer, m_TeamData[0].iMaxScore);
#else
	CGuildManager::instance().RequestWarOver(dwWinner, dwLoser, dwWinner, iRewardGold);
#endif

//find again;

long CWarMapManager::CreateWarMap(const TGuildWarInfo& guildWarInfo, DWORD dwGuildID1, DWORD dwGuildID2)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
long CWarMapManager::CreateWarMap(const TGuildWarInfo& guildWarInfo, DWORD dwGuildID1, DWORD dwGuildID2, int iMaxPlayer, int iMaxScore)
#else
long CWarMapManager::CreateWarMap(const TGuildWarInfo& guildWarInfo, DWORD dwGuildID1, DWORD dwGuildID2)
#endif

//find again;

		m_mapWarMap.insert(std::make_pair(lMapIndex, M2_NEW CWarMap(lMapIndex, guildWarInfo, pkInfo, dwGuildID1, dwGuildID2)));

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		m_mapWarMap.insert(std::make_pair(lMapIndex, M2_NEW CWarMap(lMapIndex, guildWarInfo, pkInfo, dwGuildID1, dwGuildID2, iMaxPlayer, iMaxScore)));
#else
		m_mapWarMap.insert(std::make_pair(lMapIndex, M2_NEW CWarMap(lMapIndex, guildWarInfo, pkInfo, dwGuildID1, dwGuildID2)));
#endif