#ifndef INCLUDE_GLOBAL_LOGGER_H
#define INCLUDE_GLOBAL_LOGGER_H
/* Boost */
#include <boost/log/sources/global_logger_storage.hpp>	// for BOOST_LOG_GLOBAL_LOGGER
#include <boost/log/sources/severity_logger.hpp>		// for severity_logger
#include <boost/log/expressions/keyword.hpp>			// for BOOST_LOG_ATTRIBUTE_KEYWORD

namespace Log{
	/// Log level type
	typedef enum struct SEVERITY_TYPE
	{
		/*note,*/ Debug, Info, Warn, Error,	/*critical,*/ Fatal, NUM
	}Lv;

	/**
	 * Declare keyword
	 *
	 * define struct severity
	 * @param severity [i] declare struct name
	 * @param "severity" [i] struct attribute name
	 * @param Log::Lv [i] instance tag
	 */
	BOOST_LOG_ATTRIBUTE_KEYWORD( severity, "Severity", Log::Lv );

	/**
	 * Declare logger
	 *
	 * @param g_logger [i] struct name
	 * @param severity_logger_mt [i] logger type
	 */
	BOOST_LOG_GLOBAL_LOGGER( g_logger, boost::log::sources::severity_logger_mt<Log::Lv> )

	/**
	 * output operator
	 *
	 * @param os [i] logger stream
	 * @param level [i] log level
	 * @return os
	 */
	std::ostream& operator<< ( std::ostream& os, const Log::Lv &level );
}// namespace Log
#endif// INCLUDE_GLOBAL_LOGGER_H