/* $Id: dsp.h 2412 2011-08-29 13:10:53Z truebrain $ */

/** @file src/dsp.h DSP definitions. */

#ifndef DSP_H
#define DSP_H

extern void DSP_Play(const uint8 *data);
extern void DSP_Stop();
extern uint8 DSP_GetStatus();
extern bool DSP_Init();
extern void DSP_Uninit();

#endif /* DSP_H */
