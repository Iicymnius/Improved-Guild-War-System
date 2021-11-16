//find;

} TWarMapInfo;

//add above;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	int			iMaxPlayer;
	int			iMaxScore;
#endif

//find again;

	CWarMap(long lMapIndex, const TGuildWarInfo& r_info, TWarMapInfo* pkWarMapInfo, DWORD dwGuildID1, DWORD dwGuildID2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	CWarMap(long lMapIndex, const TGuildWarInfo& r_info, TWarMapInfo* pkWarMapInfo, DWORD dwGuildID1, DWORD dwGuildID2, int iMaxPlayer, int iMaxScore);
#else
	CWarMap(long lMapIndex, const TGuildWarInfo& r_info, TWarMapInfo* pkWarMapInfo, DWORD dwGuildID1, DWORD dwGuildID2);
#endif

//find again;

	DWORD	GetGuildID(BYTE bIdx);

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	int		GetCurrentPlayer(BYTE bIdx);
	int		GetMaxPlayer(BYTE bIdx);
	int		GetCurrentScore(BYTE bIdx);
	int		GetMaxScore(BYTE bIdx);
#endif

//find again;

		LPCHARACTER pkChrFlagBase;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		int		iMaxPlayer;
		int		iMaxScore;
#endif

//find again;

	long		CreateWarMap(const TGuildWarInfo& r_WarInfo, DWORD dwGuildID1, DWORD dwGuildID2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	long		CreateWarMap(const TGuildWarInfo& r_WarInfo, DWORD dwGuildID1, DWORD dwGuildID2, int iMaxPlayer, int iMaxScore);
#else
	long		CreateWarMap(const TGuildWarInfo& r_WarInfo, DWORD dwGuildID1, DWORD dwGuildID2);
#endif