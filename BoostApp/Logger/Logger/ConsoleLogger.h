#ifndef INCLUDE_CONSOLE_LOGGER_H
#define INCLUDE_CONSOLE_LOGGER_H
namespace Log{
	namespace Console{
		/**
		 * Concifgure Boost.Logger
		 *
		 * Create backsink & frontsink
		 * Add sink to boost log core
		 */
		void ConfigureLogger();
	}// namespace Console
}// namespace Log

#endif// INCLUDE_CONSOLE_LOGGER_H