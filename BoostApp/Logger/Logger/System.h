#ifndef INCLUDE_LOGGER_SYSTEM_H
#define INCLUDE_LOGGER_SYSTEM_H
/* Boost */
#include <boost/log/sources/severity_feature.hpp>        // for BOOST_LOG_SEV
#include <boost/log/utility/manipulators/add_value.hpp>  // for add_value
/* Original */
#include "GlobalLogger.h"

#if (_MSC_VER)
#define __FUNC__ __func__
#endif
#define LOG(sv) BOOST_LOG_SEV( Log::g_logger::get(), sv) \
  << boost::log::add_value("Line", __LINE__) \
  << boost::log::add_value("File", __FILE__) \
  << boost::log::add_value("Func", __FUNC__)

namespace Log{
	/**
	 * Boot up log system
	 * reflect log config after this method execution
	 */
	void BootLogSystem();
}// namespace Log
#endif// INCLUDE_LOGGER_SYSTEM_H