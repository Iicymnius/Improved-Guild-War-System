#find;

		self.inputSlot = None

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			self.inputSlot1 = None
			self.inputSlot2 = None

#find again;

		self.inputValue = None

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			self.inputValue1 = None
			self.inputValue2 = None

#find again;

			self.inputSlot = getObject("InputSlot")

#add below;

			if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
				self.inputSlot1 = getObject("InputSlotScore")
				self.inputSlot2 = getObject("InputSlotUser")

#find again;

			self.inputValue = getObject("InputValue")

#add below;

			if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
				self.inputValue1 = getObject("InputValueScore")
				self.inputValue2 = getObject("InputValueUser")
				self.inputValue1.SetNumberMode()
				self.inputValue2.SetNumberMode()
				self.inputValue1.SetText(str(100))
				self.inputValue2.SetText(str(8))

#find again;

	def __OnOK(self):
		text = self.GetText()
		type = self.GetType()

		if ""==text:
			return

		net.SendChatPacket("/war %s %d" % (text, type))

#change;

	def __OnOK(self):
		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			guild_name = str(self.GetText(0))
			maxskor = int(self.GetText(1))
			maxplayer = int(self.GetText(2))
			type = int(self.GetType())
			if ""==guild_name:
				return
			elif not maxskor:
				return
			elif not maxplayer:
				return
			net.SendChatPacket("/war {0} {1} {2} {3}".format(str(guild_name), int(type), int(maxplayer), int(maxskor)))
		else:
			text = self.GetText()
			type = self.GetType()

			if ""==text:
				return

			net.SendChatPacket("/war %s %d" % (text, type))

#find again;

		self.inputValue.OnIMEReturn = event

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			self.inputValue1.OnIMEReturn = event
			self.inputValue2.OnIMEReturn = event

#find again;

		self.inputValue.OnPressEscapeKey = event

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			self.inputValue1.OnPressEscapeKey = event
			self.inputValue2.OnPressEscapeKey = event

#find again;

	def GetText(self):
		return self.inputValue.GetText()

#change;

	if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
		def GetText(self, value):
			if value == 0:
				return self.inputValue.GetText()
			if value == 1:
				return self.inputValue1.GetText()
			if value == 2:
				return self.inputValue2.GetText()
	else:
		def GetText(self):
			return self.inputValue.GetText()

#find again;

	def Open(self, guildName, warType):
		self.guildName=guildName
		self.warType=warType
		self.__ClickSelectedTypeRadioButton()
		self.inputValue.SetText(guildName)
		self.SetCenterPosition()
		self.SetTop()
		self.Show()

#change;

	if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
		def Open(self, guildName, warType, maxPlayer, maxScore):
			self.guildName=guildName
			self.warType=warType
			self.maxPlayer = maxPlayer
			self.maxScore = maxScore
			self.__ClickSelectedTypeRadioButton()
			self.inputValue.SetText(guildName)
			self.inputValue1.SetText(str(self.maxScore) + " Puan")
			self.inputValue2.SetText(str(self.maxPlayer) + " Oyuncu")
			self.SetCenterPosition()
			self.SetTop()
			self.Show()
	else:
		def Open(self, guildName, warType):
			self.guildName=guildName
			self.warType=warType
			self.__ClickSelectedTypeRadioButton()
			self.inputValue.SetText(guildName)
			self.SetCenterPosition()
			self.SetTop()
			self.Show()

#find again;

	def GetGuildName(self):
		return self.guildName

#add below;

	if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
		def GetWarType(self):
			return self.warType

		def GetMaxPlayerCount(self):
			return self.maxPlayer

		def GetMaxScore(self):
			return self.maxScore

		def GetWarFlags(self):
			return self.warFlag

		def GetCustomMapIdx(self):
			return 0

#find again;

		self.inputSlot = None

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			self.inputSlot1 = None
			self.inputSlot2 = None

#find again;

		self.inputValue = None

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			self.inputValue1 = None
			self.inputValue2 = None

#find again;

			self.inputSlot = getObject("InputSlot")

#add below;

			if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
				self.inputSlot1 = getObject("InputSlotScore")
				self.inputSlot2 = getObject("InputSlotUser")

#find again;

			self.inputValue = getObject("InputValue")

#add below;

			if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
				self.inputValue1 = getObject("InputValueScore")
				self.inputValue2 = getObject("InputValueUser")

#find again;

		self.inputValue.OnIMEReturn = event

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			self.inputValue1.OnIMEReturn = event
			self.inputValue2.OnIMEReturn = event

#find again;

		self.inputValue.OnPressEscapeKey = event

#add below;

		if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
			self.inputValue1.OnPressEscapeKey = event
			self.inputValue2.OnPressEscapeKey = event

#find again;

	def GetText(self):
		return self.inputValue.GetText()

#change;

	if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
		def GetText(self, value):
			if value == 0:
				return self.inputValue.GetText()
			if value == 1:
				return self.inputValue1.GetText()
			if value == 2:
				return self.inputValue2.GetText()
	else:
		def GetText(self):
			return self.inputValue.GetText()