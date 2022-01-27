#ifndef IN_GAME_GAME_0F09F0_H
#define IN_GAME_GAME_0F09F0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern const struct menucolourpalette g_MenuColourPalettes[];
extern const struct menucolourpalette g_MenuColourPalettes2[];
extern const struct menucolourpalette g_MenuColourPalettes3[];

void menuPlaySound(s32 menusound);
bool menuIsSoloMissionOrMp(void);
bool currentPlayerIsMenuOpenInSoloOrMp(void);
bool func0f0f0c68(void);
void menuSetBanner(s32 bannernum, bool allplayers);

#if VERSION >= VERSION_NTSC_1_0
Gfx *menuRenderBanner(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, bool big, s32 msgnum, s32 arg7, s32 arg8);
#else
Gfx *menuRenderBanner(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, bool big, s32 msgnum);
#endif

struct menudfc *func0f0f1338(struct menuitem *item);
void func0f0f139c(struct menuitem *item, f32 arg1);
void func0f0f13ec(struct menuitem *item);
void func0f0f1418(void);
void func0f0f1494(void);
char *menuResolveText(u32 thing, void *dialogoritem);
char *menuResolveParam2Text(struct menuitem *item);
char *menuResolveDialogTitle(struct menudialogdef *dialogdef);
void func0f0f15a4(struct menuitem *item, s32 *arg1);
void menuCalculateItemSize(struct menuitem *item, s16 *width, s16 *height, struct menudialog *dialog);
void func0f0f1d6c(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu);
u32 func0f0f1ef4(void);
void dialogCalculateContentSize(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu);
s32 dialogFindItem(struct menudialog *dialog, struct menuitem *item, s32 *rowindex, s32 *colindex);
bool menuIsScrollableUnscrollable(struct menuitem *item);
bool menuIsItemDisabled(struct menuitem *item, struct menudialog *dialog);
bool func0f0f2674(struct menuitem *item, struct menudialog *dialog, u32 arg2);
struct menuitem *dialogFindItemAtColY(s32 targety, s32 colindex, struct menudialogdef *dialogdef, s32 *rowindexptr, struct menudialog *dialog);
struct menuitem *dialogFindFirstItem(struct menudialog *dialog);
u32 func0f0f2928(void);
u32 func0f0f29cc(void);
u32 func0f0f2b2c(void);
u32 func0f0f2c44(void);
void menuOpenDialog(struct menudialogdef *dialogdef, struct menudialog *arg1, struct menu *menu);
void menuPushDialog(struct menudialogdef *dialogdef);

#if VERSION >= VERSION_NTSC_1_0
bool func0f0f3220(s32 arg0);
#else
void func0f0f3220(s32 arg0);
#endif

void menuCloseDialog(void);
void menuUpdateCurFrame(void);
void menuPopDialog(void);
void func0f0f3704(struct menudialogdef *dialogdef);
void func0f0f372c(u8 *arg0, f32 x, f32 y, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8);
void func0f0f37a4(u8 *arg0);
Gfx *menuRenderHudPiece(Gfx *gdl, u8 *arg1, u32 arg2);
u32 func0f0f5004(void);
Gfx *menuApplyScissor(Gfx *gdl);
Gfx *dialogRender(Gfx *gdl, struct menudialog *dialog, struct menu *menu, s32 arg3);
void func0f0f74a8(s8 *contpadnum1, s8 *contpadnum2);
void func0f0f7594(s32 arg0, s32 *vdir, s32 *hdir);
void menuFindAvailableSize(s32 *xmin, s32 *ymin, s32 *xmax, s32 *ymax);
void dialogCalculatePosition(struct menudialog *dialog);
void menuClose(void);
void func0f0f8120(void);
void func0f0f820c(struct menudialogdef *dialogdef, s32 root);
bool menuSetBackground(s32 bg);
void func0f0f8300(void);
void menuPushRootDialog(struct menudialogdef *dialogdef, s32 arg1);
void func0f0f85e0(struct menudialogdef *dialogdef, s32 root);
Gfx *menuRenderDialog(Gfx *gdl, struct menudialog *dialog, struct menu *menu, s32 arg3);
Gfx *menuRenderDialogs(Gfx *gdl);
void func0f0f8bb4(u8 *arg0, u32 arg1, u32 arg2);
void menuInit(void);
u32 func0f0f9030(void);
void dialogProcessInput(struct menudialog *dialog, struct menuinputs *inputs, bool iscurrent);
void dialogInitItems(struct menudialog *dialog);
void func0f0fa6ac(void);
void menuProcessInput(void);
Gfx *menuRenderBackgroundLayer1(Gfx *gdl, u8 bg, f32 frac);
Gfx *menuRenderBackgroundLayer2(Gfx *gdl, u8 bg, f32 frac);
Gfx *menuRender(Gfx *gdl);
u32 menuChooseMusic(void);
u32 menuGetRoot(void);
void func0f0fce8c(struct menudialogdef *dialogdef, s32 playernum, s32 arg2);
char *menuTextSaveDeviceName(struct menuitem *item);
u32 func0f0fd118(u32 arg0);
bool func0f0fd1f4(s32 device, s32 arg1);
void func0f0fd320(s32 arg0, s32 arg1);
void func0f0fd494(struct coord *pos);
void func0f0fd548(s32 arg0);
struct menudialog *menuIsDialogOpen(struct menudialogdef *dialogdef);
struct chrdata *currentPlayerGetCommandingAibot(void);

s32 menuhandler000fcc34(s32 operation, struct menuitem *item, union handlerdata *data);
s32 amPickTargetMenuList(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerRepairPak(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerRetrySavePak(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerWarnRepairPak(s32 operation, struct menuitem *item, union handlerdata *data);

extern const char var7f1b2658[];
extern const char var7f1b265c[];
extern const char var7f1b2660[];
extern const char var7f1b2664[];

#endif
