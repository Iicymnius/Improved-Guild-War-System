#find;

	"height" : 130,

#change;

	"height" : 215, # default: 130

#find again;

			"height" : 130,

#change;

			"height" : 215, # default: 130

#find again;

				## Input Slot

#add above;

			# if app.ENABLE_IMPROVED_GUILD_WAR_SYSTEM:
				{
					"name" : "InputNameScore",
					"type" : "text",

					"x" : 15,
					"y" : 100,

					"text" : "Max. Skor",
				},
				{
					"name" : "InputSlotScore",
					"type" : "slotbar",

					"x" : 80,
					"y" : 97,

					"width" : 130,
					"height" : 18,

					"children" :
					(
						{
							"name" : "InputValueScore",
							"type" : "editline",

							"x" : 3,
							"y" : 3,

							"width" : 90,
							"height" : 18,

							"input_limit" : 12,
						},
					),
				},
				{
					"name" : "InputNameUser",
					"type" : "text",

					"x" : 15,
					"y" : 130,

					"text" : "Max. Oyuncu",
				},
				{
					"name" : "InputSlotUser",
					"type" : "slotbar",

					"x" : 80,
					"y" : 127,

					"width" : 130,
					"height" : 18,

					"children" :
					(
						{
							"name" : "InputValueUser",
							"type" : "editline",

							"x" : 3,
							"y" : 3,

							"width" : 90,
							"height" : 18,

							"input_limit" : 12,
						},
					),
				},

#find again;

					"y" : 95,

#change;

					"y" : 165, # default: 95

#find again;

					"y" : 95,

#change;

					"y" : 165, # default: 95