#find;

	def BINARY_GuildWar_OnRecvDeclare(self, guildID, warType):
		mainCharacterName = player.GetMainCharacterName()
		masterName = guild.GetGuildMasterName()
		if mainCharacterName == masterName:
			self.__GuildWar_OpenAskDialog(guildID, warType)

#change;

	if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
		def BINARY_GuildWar_OnRecvDeclare(self, guildID, warType, maxPlayer, maxScore):
			mainCharacterName = player.GetMainCharacterName()
			masterName = guild.GetGuildMasterName()
			if mainCharacterName == masterName:
				self.__GuildWar_OpenAskDialog(guildID, warType, maxPlayer, maxScore)
	else:
		def BINARY_GuildWar_OnRecvDeclare(self, guildID, warType):
			mainCharacterName = player.GetMainCharacterName()
			masterName = guild.GetGuildMasterName()
			if mainCharacterName == masterName:
				self.__GuildWar_OpenAskDialog(guildID, warType)

#find again;

	def __GuildWar_OpenAskDialog(self, guildID, warType):

		guildName = guild.GetGuildName(guildID)

		# REMOVED_GUILD_BUG_FIX
		if "Noname" == guildName:
			return
		# END_OF_REMOVED_GUILD_BUG_FIX

		import uiGuild
		questionDialog = uiGuild.AcceptGuildWarDialog()
		questionDialog.SAFE_SetAcceptEvent(self.__GuildWar_OnAccept)
		questionDialog.SAFE_SetCancelEvent(self.__GuildWar_OnDecline)
		questionDialog.Open(guildName, warType)

		self.guildWarQuestionDialog = questionDialog

#change;

	if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
		def __GuildWar_OpenAskDialog(self, guildID, warType, maxPlayer, maxScore):
			guildName = guild.GetGuildName(guildID)

			if "Noname" == guildName:
				return

			import uiGuild
			questionDialog = uiGuild.AcceptGuildWarDialog()
			questionDialog.SAFE_SetAcceptEvent(self.__GuildWar_OnAccept)
			questionDialog.SAFE_SetCancelEvent(self.__GuildWar_OnDecline)
			questionDialog.Open(guildName, warType, maxPlayer, maxScore)

			self.guildWarQuestionDialog = questionDialog
	else:
		def __GuildWar_OpenAskDialog(self, guildID, warType):

			guildName = guild.GetGuildName(guildID)

			# REMOVED_GUILD_BUG_FIX
			if "Noname" == guildName:
				return
			# END_OF_REMOVED_GUILD_BUG_FIX

			import uiGuild
			questionDialog = uiGuild.AcceptGuildWarDialog()
			questionDialog.SAFE_SetAcceptEvent(self.__GuildWar_OnAccept)
			questionDialog.SAFE_SetCancelEvent(self.__GuildWar_OnDecline)
			questionDialog.Open(guildName, warType)

			self.guildWarQuestionDialog = questionDialog

#find again;

	def __GuildWar_OnAccept(self):

#find in function;

		guildName = self.guildWarQuestionDialog.GetGuildName()

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			warType = self.guildWarQuestionDialog.GetWarType()
			maxScore = self.guildWarQuestionDialog.GetMaxScore()
			maxPlayer = self.guildWarQuestionDialog.GetMaxPlayerCount()

#find again;

		net.SendChatPacket("/war " + guildName)

#change;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			net.SendChatPacket("/war %s %s %s %s" % (str(guildName), str(warType), str(maxPlayer), str(maxScore)))
		else:
			net.SendChatPacket("/war " + guildName)