#ifndef _IN_LIB_LIB_317F0_H
#define _IN_LIB_LIB_317F0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func00033090(struct audiohandle *handle);
u32 func00033100(void);
s16 sndpCountStates(s16 *arg0, s16 *arg1);
void func00033378(void *fn);
u32 func00033390(void);
void func00033634(void *fn);
void func0003364c(struct audiohandle *handle);
bool audioIsPlaying(struct audiohandle *handle);
struct audiohandle *func00033820(s32 arg0, s16 soundnum, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6, struct audiohandle **handle);
void audioStop(struct audiohandle *handle);
void func00033bc0(struct audiohandle *handle);
void func00033db0(void);
void func00033dd8(void);
void audioPostEvent(struct audiohandle *handle, s16 type, s32 data);
u16 func00033ec4(u8 index);
struct var8005f120 *func00033f08(void);
ALMicroTime sndpGetCurTime(void);
void func00033f44(u8 index, u16 volume);

#endif
