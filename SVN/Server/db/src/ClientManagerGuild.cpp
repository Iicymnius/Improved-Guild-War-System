//find;

		sys_log(0, "GuildWar: GUILD_WAR_SEND_DECLARE type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().AddDeclare(p->bType, p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar: GUILD_WAR_SEND_DECLARE type(%s) guild(%d - %d) limits(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
		CGuildManager::instance().AddDeclare(p->bType, p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		sys_log(0, "GuildWar: GUILD_WAR_SEND_DECLARE type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().AddDeclare(p->bType, p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

		sys_log(0, "GuildWar: GUILD_WAR_REFUSE type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar: GUILD_WAR_REFUSE type(%s) guild(%d - %d) limits(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		sys_log(0, "GuildWar: GUILD_WAR_REFUSE type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

			sys_log(0, "GuildWar: GUILD_WAR_RESERVE type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo);

//change;

			sys_log(0, "GuildWar: GUILD_WAR_RESERVE type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

		sys_log(0, "GuildWar: GUILD_WAR_ON_WAR type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().StartWar(p->bType, p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar: GUILD_WAR_ON_WAR type(%s) guild(%d - %d) limits(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
		CGuildManager::instance().StartWar(p->bType, p->dwGuildFrom, p->dwGuildTo, NULL, p->iMaxPlayer, p->iMaxScore);
#else
		sys_log(0, "GuildWar: GUILD_WAR_ON_WAR type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RemoveDeclare(p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().StartWar(p->bType, p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

		sys_log(0, "GuildWar: GUILD_WAR_OVER type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RecvWarOver(p->dwGuildFrom, p->dwGuildTo, p->bType, p->lWarPrice);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar: GUILD_WAR_OVER type(%s) guild(%d - %d) limits(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
		CGuildManager::instance().RecvWarOver(p->dwGuildFrom, p->dwGuildTo, p->bType, p->lWarPrice, p->iMaxPlayer, p->iMaxScore);
#else
		sys_log(0, "GuildWar: GUILD_WAR_OVER type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RecvWarOver(p->dwGuildFrom, p->dwGuildTo, p->bType, p->lWarPrice);
#endif

//find again;

		sys_log(0, "GuildWar: GUILD_WAR_END type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RecvWarEnd(p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar: GUILD_WAR_END type(%s) guild(%d - %d) limits(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
		CGuildManager::instance().RecvWarEnd(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		sys_log(0, "GuildWar: GUILD_WAR_END type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().RecvWarEnd(p->dwGuildFrom, p->dwGuildTo);
#endif

//find again;

		sys_log(0, "GuildWar: GUILD_WAR_CANCEL type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().CancelWar(p->dwGuildFrom, p->dwGuildTo);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		sys_log(0, "GuildWar: GUILD_WAR_CANCEL type(%s) guild(%d - %d) limits(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
		CGuildManager::instance().CancelWar(p->dwGuildFrom, p->dwGuildTo, p->iMaxPlayer, p->iMaxScore);
#else
		sys_log(0, "GuildWar: GUILD_WAR_CANCEL type(%s) guild(%d - %d)", __GetWarType(p->bType), p->dwGuildFrom, p->dwGuildTo);
		CGuildManager::instance().CancelWar(p->dwGuildFrom, p->dwGuildTo);
#endif