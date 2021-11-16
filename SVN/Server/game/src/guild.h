//find;

	DWORD map_index;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	int max_score;
	int max_player;
#endif

//find again;

		map_index(0)

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		, max_score(0),
		max_player(0)
#endif

//find again;

	void		GuildWarPacket(DWORD guild_id, BYTE bWarType, BYTE bWarState);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	void		GuildWarPacket(DWORD guild_id, BYTE bWarType, BYTE bWarState, int iMaxPlayer, int iMaxScore);
#else
	void		GuildWarPacket(DWORD guild_id, BYTE bWarType, BYTE bWarState);
#endif

//find again;

	void		RequestDeclareWar(DWORD guild_id, BYTE type);
	void		RequestRefuseWar(DWORD guild_id);

	bool		DeclareWar(DWORD guild_id, BYTE type, BYTE state);
	void		RefuseWar(DWORD guild_id);
	bool		WaitStartWar(DWORD guild_id);
	bool		CheckStartWar(DWORD guild_id);
	void		StartWar(DWORD guild_id);
	void		EndWar(DWORD guild_id);
	void		ReserveWar(DWORD guild_id, BYTE type);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	void		RequestDeclareWar(DWORD guild_id, BYTE type, int iMaxPlayer, int iMaxScore);
	void		RequestRefuseWar(DWORD guild_id, int iMaxPlayer, int iMaxScore);
	bool		DeclareWar(DWORD guild_id, BYTE type, BYTE state, int iMaxPlayer, int iMaxScore);
	void		RefuseWar(DWORD guild_id, int iMaxPlayer, int iMaxScore);
	bool		WaitStartWar(DWORD guild_id, int iMaxPlayer, int iMaxScore);
	bool		CheckStartWar(DWORD guild_id);
	void		StartWar(DWORD guild_id, int iMaxPlayer, int iMaxScore);
	void		EndWar(DWORD guild_id);
	void		ReserveWar(DWORD guild_id, BYTE type, int iMaxPlayer, int iMaxScore);
#else
	void		RequestDeclareWar(DWORD guild_id, BYTE type);
	void		RequestRefuseWar(DWORD guild_id);

	bool		DeclareWar(DWORD guild_id, BYTE type, BYTE state);
	void		RefuseWar(DWORD guild_id);
	bool		WaitStartWar(DWORD guild_id);
	bool		CheckStartWar(DWORD guild_id);
	void		StartWar(DWORD guild_id);
	void		EndWar(DWORD guild_id);
	void		ReserveWar(DWORD guild_id, BYTE type);
#endif