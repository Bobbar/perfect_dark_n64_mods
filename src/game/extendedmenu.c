#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <PR/ultratypes.h>
#include "platform.h"
#include "data.h"
#include "types.h"
#include "game/mainmenu.h"
#include "game/menu.h"
#include "game/gamefile.h"
#include "video.h"
#include "input.h"
#include "config.h"

static s32 g_ExtMenuPlayer = 0;
static struct menudialogdef* g_ExtNextDialog = NULL;

static s32 g_BindIndex = 0;
static u32 g_BindContKey = 0;

static MenuItemHandlerResult menuhandlerSelectPlayer(s32 operation, struct menuitem* item, union handlerdata* data);

struct menuitem g_ExtendedSelectPlayerMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LITERAL_TEXT,
		(uintptr_t)"Player 1\n",
		0,
		menuhandlerSelectPlayer,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LITERAL_TEXT,
		(uintptr_t)"Player 2\n",
		0,
		menuhandlerSelectPlayer,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LITERAL_TEXT,
		(uintptr_t)"Player 3\n",
		0,
		menuhandlerSelectPlayer,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LITERAL_TEXT,
		(uintptr_t)"Player 4\n",
		0,
		menuhandlerSelectPlayer,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_OPTIONS_213, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_ExtendedSelectPlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)"Select Player",
	g_ExtendedSelectPlayerMenuItems,
	NULL,
	MENUDIALOGFLAG_LITERAL_TEXT,
	NULL,
};

static MenuItemHandlerResult menuhandlerSelectPlayer(s32 operation, struct menuitem* item, union handlerdata* data)
{
	if (operation == MENUOP_SET) {
		g_ExtMenuPlayer = item - g_ExtendedSelectPlayerMenuItems;
		((char*)g_ExtNextDialog->title)[7] = g_ExtMenuPlayer + '1';
		menuPushDialog(g_ExtNextDialog);
	}

	return 0;
}


static MenuItemHandlerResult menuhandlerDisableMpDeathMusic(s32 operation, struct menuitem* item, union handlerdata* data)
{
	switch (operation) {
	case MENUOP_GET:
		return g_MusicDisableMpDeath;
	case MENUOP_SET:
		g_MusicDisableMpDeath = data->checkbox.value;
		break;
	}

	return 0;
}

struct menuitem g_ExtendedAudioMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LITERAL_TEXT,
		(uintptr_t)"Disable MP Death Music",
		0,
		menuhandlerDisableMpDeathMusic,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_OPTIONS_213, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_ExtendedAudioMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)"Extended Audio Options",
	g_ExtendedAudioMenuItems,
	NULL,
	MENUDIALOGFLAG_LITERAL_TEXT,
	NULL,
};

static MenuItemHandlerResult menuhandlerCrosshairR(s32 operation, struct menuitem* item, union handlerdata* data)
{
	u32 newColor;

	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = (g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour >> 24) & 0xFF;
		break;

	case MENUOP_SET:
		newColor = (g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour & 0xFFFFFF) | data->slider.value << 24;
		g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour = newColor;
		break;
	}

	return 0;
}

static MenuItemHandlerResult menuhandlerCrosshairG(s32 operation, struct menuitem* item, union handlerdata* data)
{
	u32 newColor;

	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = (g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour >> 16) & 0xFF;
		break;

	case MENUOP_SET:
		newColor = (g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour & 0xFF00FFFF) | data->slider.value << 16;
		g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour = newColor;
		break;
	}

	return 0;
}

static MenuItemHandlerResult menuhandlerCrosshairB(s32 operation, struct menuitem* item, union handlerdata* data)
{
	u32 newColor;

	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = (g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour >> 8) & 0xFF;
		break;

	case MENUOP_SET:
		newColor = (g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour & 0xFFFF00FF) | data->slider.value << 8;
		g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour = newColor;
		break;
	}

	return 0;
}

static MenuItemHandlerResult menuhandlerCrosshairA(s32 operation, struct menuitem* item, union handlerdata* data)
{
	u32 newColor;

	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour & 0xFF;
		break;

	case MENUOP_SET:
		newColor = (g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour & 0xFFFFFF00) | data->slider.value;
		g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour = newColor;
		break;
	}

	return 0;
}

static MenuItemHandlerResult menuhandlerCrosshairColorPreview(s32 operation, struct menuitem* item, union handlerdata* data)
{
	if (operation == MENUOP_GETCOLOUR) {
		data->label.colour1 = g_PlayerExtCfg[g_ExtMenuPlayer].crosshaircolour;
	}

	return 0;
}

struct menuitem g_ExtendedGameCrosshairColourMenuItems[] = {
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LITERAL_TEXT | MENUITEMFLAG_SLIDER_WIDE,
		(uintptr_t)"Red",
		255,
		menuhandlerCrosshairR,
	},
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LITERAL_TEXT | MENUITEMFLAG_SLIDER_WIDE,
		(uintptr_t)"Green",
		255,
		menuhandlerCrosshairG,
	},
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LITERAL_TEXT | MENUITEMFLAG_SLIDER_WIDE,
		(uintptr_t)"Blue",
		255,
		menuhandlerCrosshairB,
	},
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LITERAL_TEXT | MENUITEMFLAG_SLIDER_WIDE,
		(uintptr_t)"Alpha",
		255,
		menuhandlerCrosshairA,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_COLORBOX,
		0,
		0,
		0,
		0,
		menuhandlerCrosshairColorPreview,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_OPTIONS_213, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_ExtendedGameCrosshairColourMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)"Crosshair Colour",
	g_ExtendedGameCrosshairColourMenuItems,
	NULL,
	MENUDIALOGFLAG_LITERAL_TEXT,
	NULL,
};

struct menuitem g_ExtendedGameMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LITERAL_TEXT | MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		(uintptr_t)"Crosshair Colour\n",
		0,
		(void*)&g_ExtendedGameCrosshairColourMenuDialog,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_OPTIONS_213, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

static char g_ExtendedGameMenuTitle[] = "Player 1 Game Options";
struct menudialogdef g_ExtendedGameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)g_ExtendedGameMenuTitle,
	g_ExtendedGameMenuItems,
	NULL,
	MENUDIALOGFLAG_LITERAL_TEXT,
	NULL,
};

static MenuItemHandlerResult menuhandlerOpenGameMenu(s32 operation, struct menuitem* item, union handlerdata* data)
{
	if (operation == MENUOP_SET) {
		g_ExtNextDialog = &g_ExtendedGameMenuDialog;
		menuPushDialog(&g_ExtendedSelectPlayerMenuDialog);
	}
	return 0;
}

struct menuitem g_ExtendedMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG | MENUITEMFLAG_LITERAL_TEXT,
		(uintptr_t)"Audio\n",
		0,
		(void*)&g_ExtendedAudioMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_LITERAL_TEXT,
		(uintptr_t)"Game\n",
		0,
		menuhandlerOpenGameMenu,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_OPTIONS_213, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_ExtendedMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(uintptr_t)"Extended Options",
	g_ExtendedMenuItems,
	NULL,
	MENUDIALOGFLAG_LITERAL_TEXT,
	NULL,
};
