//find;

	DWORD dwGuildID[2];

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	int iMaxPlayer;
	int iMaxScore;
#endif

//find again;

	TGuildDeclareInfo(BYTE _bType, DWORD _dwGuildID1, DWORD _dwGuildID2)
		: bType(_bType)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	TGuildDeclareInfo(BYTE _bType, DWORD _dwGuildID1, DWORD _dwGuildID2, int _iMaxPlayer, int _iMaxScore)
		: bType(_bType), iMaxPlayer(_iMaxPlayer), iMaxScore(_iMaxScore)
#else
	TGuildDeclareInfo(BYTE _bType, DWORD _dwGuildID1, DWORD _dwGuildID2)
		: bType(_bType)
#endif

//find again;

		dwGuildID[1] = _dwGuildID2;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		iMaxPlayer = _iMaxPlayer;
		iMaxScore = _iMaxScore;
#endif

//find again;

	CGuildWarReserve* pkReserve;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	int					iMaxPlayer;
	int					iMaxScore;
#endif

//find again;

	TGuildWaitStartInfo(BYTE _bType, DWORD _g1, DWORD _g2, long _lWarPrice, long _lInitialScore, CGuildWarReserve* _pkReserve)
		: bType(_bType), lWarPrice(_lWarPrice), lInitialScore(_lInitialScore), pkReserve(_pkReserve)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	TGuildWaitStartInfo(BYTE _bType, DWORD _g1, DWORD _g2, long _lWarPrice, long _lInitialScore, CGuildWarReserve* _pkReserve, int _iMaxPlayer, int _iMaxScore)
		: bType(_bType), lWarPrice(_lWarPrice), lInitialScore(_lInitialScore), pkReserve(_pkReserve), iMaxPlayer(_iMaxPlayer), iMaxScore(_iMaxScore)
#else
	TGuildWaitStartInfo(BYTE _bType, DWORD _g1, DWORD _g2, long _lWarPrice, long _lInitialScore, CGuildWarReserve* _pkReserve)
		: bType(_bType), lWarPrice(_lWarPrice), lInitialScore(_lInitialScore), pkReserve(_pkReserve)
#endif

//find again;

	DWORD	iBetScore[2];

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	int		iMaxPlayer;
	int		iMaxScore;
#endif

//find again;

	TGuildWarPQElement(BYTE _bType, DWORD GID1, DWORD GID2)
		: bEnd(false), bType(_bType)

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	TGuildWarPQElement(BYTE _bType, DWORD GID1, DWORD GID2, int _iMaxPlayer, int _iMaxScore)
		: bEnd(false), bType(_bType), iMaxPlayer(_iMaxPlayer), iMaxScore(_iMaxScore)
#else
	TGuildWarPQElement(BYTE _bType, DWORD GID1, DWORD GID2)
		: bEnd(false), bType(_bType)
#endif

//find again;

				iBetScore[0] = iBetScore[1] = 0;

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
				iMaxPlayer = _iMaxPlayer;
				iMaxScore = _iMaxScore;
#endif

//find again;

	void	StartWar(BYTE bType, DWORD GID1, DWORD GID2, CGuildWarReserve* pkReserve = NULL);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	void	StartWar(BYTE bType, DWORD GID1, DWORD GID2, CGuildWarReserve* pkReserve, int iMaxPlayer, int iMaxScore);
#else
	void	StartWar(BYTE bType, DWORD GID1, DWORD GID2, CGuildWarReserve* pkReserve = NULL);
#endif

//find again;

	void	AddDeclare(BYTE bType, DWORD guild_from, DWORD guild_to);
	void	RemoveDeclare(DWORD guild_from, DWORD guild_to);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	void	AddDeclare(BYTE bType, DWORD guild_from, DWORD guild_to, int iMaxPlayer, int iMaxScore);
	void	RemoveDeclare(DWORD guild_from, DWORD guild_to, int iMaxPlayer, int iMaxScore);
#else
	void	AddDeclare(BYTE bType, DWORD guild_from, DWORD guild_to);
	void	RemoveDeclare(DWORD guild_from, DWORD guild_to);
#endif

//find again;

	void	RecvWarEnd(DWORD GID1, DWORD GID2);
	void	RecvWarOver(DWORD dwGuildWinner, DWORD dwGuildLoser, bool bDraw, long lWarPrice);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	void	RecvWarEnd(DWORD GID1, DWORD GID2, int iMaxPlayer, int iMaxScore);
	void	RecvWarOver(DWORD dwGuildWinner, DWORD dwGuildLoser, bool bDraw, long lWarPrice, int iMaxPlayer, int iMaxScore);
#else
	void	RecvWarEnd(DWORD GID1, DWORD GID2);
	void	RecvWarOver(DWORD dwGuildWinner, DWORD dwGuildLoser, bool bDraw, long lWarPrice);
#endif

//find again;

	void	CancelWar(DWORD GID1, DWORD GID2);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	void	CancelWar(DWORD GID1, DWORD GID2, int iMaxPlayer, int iMaxScore);
#else
	void	CancelWar(DWORD GID1, DWORD GID2);
#endif