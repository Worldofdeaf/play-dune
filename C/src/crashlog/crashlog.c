/* $Id: crashlog.c 2466 2011-08-30 20:20:34Z truebrain $ */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "types.h"
#include "crashlog.h"

static void CrashLog_LogCompiler(char *buffer)
{
			sprintf(buffer + strlen(buffer), " Compiler: "
#if defined(_MSC_VER)
			"MSVC %d", _MSC_VER
#elif defined(__ICC) && defined(__GNUC__)
			"ICC %d (GCC %d.%d.%d mode)", __ICC,  __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__
#elif defined(__ICC)
			"ICC %d", __ICC
#elif defined(__GNUC__)
			"GCC %d.%d.%d", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__
#elif defined(__WATCOMC__)
			"WatcomC %d", __WATCOMC__
#else
			"<unknown>"
#endif
			);
#if defined(__VERSION__)
			strcat(buffer, " \"" __VERSION__ "\"\n\n");
#else
			strcat(buffer, "\n\n");
#endif
}

void CrashLog_Fill(char *buffer)
{
	time_t cur_time = time(NULL);
	strcat(buffer, "*** OpenDUNE Crash Report ***\n\n");
	sprintf(buffer + strlen(buffer), "Crash at: %s", asctime(gmtime(&cur_time)));

	CrashLog_LogError(buffer);
	CrashLog_LogRegisters(buffer);
	CrashLog_LogStacktrace(buffer);
	CrashLog_LogOSVersion(buffer);
	CrashLog_LogCompiler(buffer);

	strcat(buffer, "*** End of OpenDUNE Crash Report ***\n");
}

bool CrashLog_WriteCrashLog(char *buffer)
{
	FILE *file = fopen("crash.log", "w");
	if (file == NULL) return false;

	if (fwrite(buffer, 1, strlen(buffer), file) == 0) {}

	fclose(file);
	return true;
}
