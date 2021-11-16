//find;

			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME],
				"BINARY_GuildWar_OnRecvDeclare",
				Py_BuildValue("(ii)", kGuildWar.dwGuildOpp, kGuildWar.bType)
			);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME],
				"BINARY_GuildWar_OnRecvDeclare",
				Py_BuildValue("(iiii)", kGuildWar.dwGuildOpp, kGuildWar.bType, kGuildWar.iMaxPlayer, kGuildWar.iMaxScore)
			);
#else
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME],
				"BINARY_GuildWar_OnRecvDeclare",
				Py_BuildValue("(ii)", kGuildWar.dwGuildOpp, kGuildWar.bType)
			);
#endif