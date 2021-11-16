//find;

	sys_log(0, "InputDB::GuildWar %u %u state %d", p->dwGuildFrom, p->dwGuildTo, p->bWar);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	sys_log(0, "InputDB::GuildWar %u %u state %d maxplayer %d maxscore %d", p->dwGuildFrom, p->dwGuildTo, p->bWar, p->iMaxPlayer, p->iMaxScore);
#else
	sys_log(0, "InputDB::GuildWar %u %u state %d", p->dwGuildFrom, p->dwGuildTo, p->bWar);
#endif

//find again;

		CGuildManager::instance().DeclareWar(p->dwGuildFrom, p->dwGuildTo, p->bType);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().DeclareWar(p->dwGuildFrom, p->dwGuildTo, p->bType, p->iMaxPlayer, p->iMaxScore);
#else
		CGuildManager::instance().DeclareWar(p->dwGuildFrom, p->dwGuildTo, p->bType);
#endif

//find again;

		CGuildManager::instance().RefuseWar(p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().RefuseWar(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		CGuildManager::instance().RefuseWar(p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

		CGuildManager::instance().WaitStartWar(p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().WaitStartWar(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		CGuildManager::instance().WaitStartWar(p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

		CGuildManager::instance().CancelWar(p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().CancelWar(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		CGuildManager::instance().CancelWar(p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

		CGuildManager::instance().StartWar(p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().StartWar(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		CGuildManager::instance().StartWar(p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

		CGuildManager::instance().ReserveWar(p->dwGuildFrom, p->dwGuildTo, p->bType);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().ReserveWar(p->dwGuildFrom, p->dwGuildTo, p->bType, p->iMaxPlayer, p->iMaxScore);
#else
		CGuildManager::instance().ReserveWar(p->dwGuildFrom, p->dwGuildTo, p->bType);
#endif