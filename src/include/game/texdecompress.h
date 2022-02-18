#ifndef IN_GAME_TEXDECOMPRESS_H
#define IN_GAME_TEXDECOMPRESS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f16e810(u32 arg0);
s32 texInflateZlib(u8 *src, u8 *dst, s32 arg2, s32 forcenumimages, struct texturething *arg4, s32 arg5);
s32 texAlignIndices(u8 *arg0, s32 width, s32 height, s32 format, u8 *dst);
u32 func0f16ee58(void);
u32 func0f16eefc(void);
u32 func0f16efa0(void);
u32 func0f16f044(void);
s32 func0f16f0f4(u8 *start, u8 *end, s32 width, s32 height, s32 format, u16 *palette, s32 numcolours);
u32 func0f16fc8c(void);
s32 func0f16fd50(u16 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 texInflateNonZlib(u8 *src, u8 *dst, s32 arg2, s32 forcenumimages, struct texturething *arg4, s32 arg5);
s32 func0f1706ec(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 format);
void func0f1711b4(u8 *arg0, s32 arg1, s32 chansize);
void texInflateRle(u8 *arg0, s32 arg1);
s32 texBuildLookup(u8 *arg0, s32 bpp);
s32 func0f171828(s32 arg0);
void texReadAlphaBits(u8 *dst, s32 count);
s32 texInflateMethod1(u8 *arg0, s32 width, s32 height, s32 format);
s32 func0f171ba8(u8 *arg0, s32 width, s32 height, u8 *arg3, s32 format);
s32 func0f17218c(s32 width, s32 height, u8 *arg2, u8 *arg3, s32 arg4, s32 format);
s32 func0f172554(u8 *arg0, s32 width, s32 height, u8 *arg3, u8 *arg4, s32 arg5, s32 format);
void texSwapAltRowBytes(u8 *arg0, s32 width, s32 height, s32 format);
void func0f172b5c(u8 *arg0, s32 width, s32 arg2, s32 arg3, s32 chansize);
void func0f172e70(s32 *arg0, void *arg1, s32 arg2);
struct texloadthing *tex0f172e8c(s32 texturenum, struct texturething *arg1);
s32 func0f172f44(struct texturething *arg0);
s32 func0f172f54(s32 *arg0);
void texLoadFromDisplayList(Gfx *gdl, struct texturething *arg1, s32 arg2);
void texLoad(u32 *texturenum, struct texturething *arg1, s32 arg2);
void texLoadFromConfigs(struct textureconfig *configs, s32 numconfigs, struct texturething *arg2, s32 arg3);
void texLoadFromTextureNum(u32 arg0, struct texturething *arg1);
void texSetBitstring(u8 *arg0);
s32 texReadBits(s32 arg0);
void texturesLoadConfigs(void);

#endif
