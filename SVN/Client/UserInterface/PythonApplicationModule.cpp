//find;

#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 0);
#endif

//add below;

#ifdef ENABLE_IMPROVED_GUILD_WAR_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_IMPROVED_GUILD_WAR_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_IMPROVED_GUILD_WAR_SYSTEM", 0);
#endif