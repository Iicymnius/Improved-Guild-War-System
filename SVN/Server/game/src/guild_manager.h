//find;

	void		RequestWarOver(DWORD dwGuild1, DWORD dwGuild2, DWORD dwGuildWinner, long lReward);

	void		DeclareWar(DWORD guild_id1, DWORD guild_id2, BYTE bType);
	void		RefuseWar(DWORD guild_id1, DWORD guild_id2);
	void		StartWar(DWORD guild_id1, DWORD guild_id2);
	void		WaitStartWar(DWORD guild_id1, DWORD guild_id2);
	void		WarOver(DWORD guild_id1, DWORD guild_id2, bool bDraw);
	void		CancelWar(DWORD guild_id1, DWORD guild_id2);
	bool		EndWar(DWORD guild_id1, DWORD guild_id2);
	void		ReserveWar(DWORD dwGuild1, DWORD dwGuild2, BYTE bType);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	void		RequestWarOver(DWORD dwGuild1, DWORD dwGuild2, DWORD dwGuildWinner, long lReward, int iMaxPlayer, int iMaxScore);

	void		DeclareWar(DWORD guild_id1, DWORD guild_id2, BYTE bType, int iMaxPlayer, int iMaxScore);
	void		RefuseWar(DWORD guild_id1, DWORD guild_id2, int iMaxPlayer, int iMaxScore);
	void		StartWar(DWORD guild_id1, DWORD guild_id2, int iMaxPlayer, int iMaxScore);
	void		WaitStartWar(DWORD guild_id1, DWORD guild_id2, int iMaxPlayer, int iMaxScore);
	void		WarOver(DWORD guild_id1, DWORD guild_id2, bool bDraw);
	void		CancelWar(DWORD guild_id1, DWORD guild_id2, int iMaxPlayer, int iMaxScore);
	bool		EndWar(DWORD guild_id1, DWORD guild_id2);
	void		ReserveWar(DWORD dwGuild1, DWORD dwGuild2, BYTE bType, int iMaxPlayer, int iMaxScore);
#else
	void		RequestWarOver(DWORD dwGuild1, DWORD dwGuild2, DWORD dwGuildWinner, long lReward);

	void		DeclareWar(DWORD guild_id1, DWORD guild_id2, BYTE bType);
	void		RefuseWar(DWORD guild_id1, DWORD guild_id2);
	void		StartWar(DWORD guild_id1, DWORD guild_id2);
	void		WaitStartWar(DWORD guild_id1, DWORD guild_id2);
	void		WarOver(DWORD guild_id1, DWORD guild_id2, bool bDraw);
	void		CancelWar(DWORD guild_id1, DWORD guild_id2);
	bool		EndWar(DWORD guild_id1, DWORD guild_id2);
	void		ReserveWar(DWORD dwGuild1, DWORD dwGuild2, BYTE bType);
#endif