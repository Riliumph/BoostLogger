#include "System.h"
/* Original */
#include "ConsoleSink.h"

namespace Log{
	void BootLogSystem()
	{
		Console::ConfigureSink();
	}
}// namespace Log