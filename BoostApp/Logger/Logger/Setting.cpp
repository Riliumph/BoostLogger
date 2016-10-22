#include "Setting.h"
/* STL */
#include <ostream>
#include <string>
/* Boost */
#include <boost/log/sources/global_logger_storage.hpp> //BOOST_LOG_GLOBAL_LOGGER‚Ì’è‹`
#include <boost/log/core.hpp>	// sink
#include <boost/log/utility/setup/common_attributes.hpp>   

#include <boost/log/attributes/current_process_name.hpp>
#include <boost/log/sources/severity_logger.hpp>
//ORIGINAL
#include "Utility/e_cast.hpp"
#include "ConsoleSink.h"

namespace Log{
	namespace src = boost::log::sources;
	namespace attr = boost::log::attributes;
	namespace{
		const std::string LV_NAME[enum_cast( Log::Lv::NUM )] = { "Debug","Info","Warn","Error","Fatal" };
	}
	/**
	 * Initialize logger
	 *
	 */
	BOOST_LOG_GLOBAL_LOGGER_INIT( g_logger, src::severity_logger_mt<Log::Lv> )
	{
		auto r = src::severity_logger_mt<Log::Lv>();
	#ifdef DEFAULT_SETTING
		boost::log::add_common_attributes();
	#else
		r.add_attribute( "TimeStamp", attr::local_clock() );
		r.add_attribute( "ProcessID", attr::current_process_id() );
		r.add_attribute( "Process", attr::current_process_name() );
		r.add_attribute( "ThreadID", attr::current_thread_id() );
	#endif
		return std::move( r );
	}

	void BootLogSystem()
	{
		Console::ConfigureSink();
	}

	std::ostream& operator<< ( std::ostream& os, const Log::Lv& level )
	{
		assert( level != Log::Lv::NUM && "Detect illegal log level" );
		os << LV_NAME[static_enum_cast( level )];
		return os;
	}
}