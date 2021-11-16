//find;

	char arg1[256], arg2[256];
	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	char arg1[256], arg2[256], arg3[256], arg4[256];
	one_argument(three_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2), arg3, sizeof(arg3)), arg4, sizeof(arg4));
#else
	char arg1[256], arg2[256];
	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));
#endif

//find again;

			g->RequestRefuseWar(opp_g->GetID());

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
			g->RequestRefuseWar(opp_g->GetID(), 0, 0);
#else
			g->RequestRefuseWar(opp_g->GetID());
#endif

//find again;

		g->RequestRefuseWar(opp_g->GetID());

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		g->RequestRefuseWar(opp_g->GetID(), 0, 0);
#else
		g->RequestRefuseWar(opp_g->GetID());
#endif

//find again;

		g->RequestRefuseWar(opp_g->GetID());

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		g->RequestRefuseWar(opp_g->GetID(), 0, 0);
#else
		g->RequestRefuseWar(opp_g->GetID());
#endif

//find again;

		g->RequestRefuseWar(opp_g->GetID());

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
		g->RequestRefuseWar(opp_g->GetID(), 0, 0);
#else
		g->RequestRefuseWar(opp_g->GetID());
#endif

//find again;

	g->RequestDeclareWar(opp_g->GetID(), type);

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	int iMaxPlayer = 0;
	if (!*arg3) iMaxPlayer = 1000;
	else str_to_number(iMaxPlayer, arg3);
	if (iMaxPlayer < 1) iMaxPlayer = 1000;
	int iMaxScore = 0;
	if (!*arg4) iMaxScore = KOR_aGuildWarInfo[type].iEndScore;
	else str_to_number(iMaxScore, arg4);
	if (iMaxScore < 1) iMaxScore = KOR_aGuildWarInfo[type].iEndScore;
	g->RequestDeclareWar(opp_g->GetID(), type, iMaxPlayer, iMaxScore);
#else
	g->RequestDeclareWar(opp_g->GetID(), type);
#endif

//find again;

	g->RequestRefuseWar(opp_g->GetID());

//change;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	g->RequestRefuseWar(opp_g->GetID(), 0, 0);
#else
	g->RequestRefuseWar(opp_g->GetID());
#endif