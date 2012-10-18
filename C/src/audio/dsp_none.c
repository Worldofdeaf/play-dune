/* $Id: dsp_none.c 2519 2011-09-01 09:06:03Z truebrain $ */

/** @file src/dsp_none.c In case no DSP is selected, create an empty one,
 *  which ignores all input */

#include "types.h"

#include "dsp.h"

void DSP_Stop()
{
}

void DSP_Uninit()
{
}

bool DSP_Init()
{
	return false;
}

void DSP_Play(const uint8 *data)
{
	VARIABLE_NOT_USED(data);
}

uint8 DSP_GetStatus()
{
	return 0;
}
