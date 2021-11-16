//find;

		if (CWarMapManager::instance().IsWarMap(ch->GetMapIndex()))
			ch->SetWarMap(CWarMapManager::instance().Find(ch->GetMapIndex()));

//change;

		if (CWarMapManager::instance().IsWarMap(ch->GetMapIndex()))
		{
#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			CWarMap* pMap = CWarMapManager::instance().Find(ch->GetMapIndex());
			if (pMap)
			{
				BYTE bIdx;
				if (ch->GetGuild() && pMap->GetTeamIndex(ch->GetGuild()->GetID(), bIdx))
				{
					if (pMap->GetCurrentPlayer(bIdx) + 1 > pMap->GetMaxPlayer(bIdx))
					{
						ch->ChatPacket(CHAT_TYPE_BIG_NOTICE, LC_TEXT("oyuncu_limiti_dolu"));
						ch->GoHome();
						return;
					}
				}
			}
			ch->SetWarMap(pMap);
#else
			ch->SetWarMap(CWarMapManager::instance().Find(ch->GetMapIndex()));
#endif
		}