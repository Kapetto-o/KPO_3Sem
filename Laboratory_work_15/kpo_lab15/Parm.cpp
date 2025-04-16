#include "stdafx.h"
#include "Parm.h"
#include "Error.h"
namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM parm;
		bool bIN = false, bOUT = false, bLOG = false;

		for (int i = 0; i < argc; i++)
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE)
				throw ERROR_THROW(104);

			if (wcsstr(argv[i], PARM_IN)) {
				wcscpy_s(parm.in, wcsstr(argv[i], L":") + 1);
				bIN = true;
			}

			if (wcsstr(argv[i], PARM_OUT)) {
				wcscpy_s(parm.out, wcsstr(argv[i], L":") + 1);
				bOUT = true;
			}

			if (wcsstr(argv[i], PARM_LOG)) {
				wcscpy_s(parm.log, wcsstr(argv[i], L":") + 1);
				bLOG = true;
			}

			
		}

		if (!bIN)
			throw ERROR_THROW(100)

			if (!bOUT)
			{
				wcscpy_s(parm.out, parm.in);
				wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
			}

		if (!bLOG)
		{
			wcscpy_s(parm.log, parm.in);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}

		return parm;
	}
};