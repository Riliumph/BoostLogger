#ifndef INCLUDE_ENUM_CAST_H
#define INCLUDE_ENUM_CAST_H
/* STL */
#include <type_traits>

template<class enum_t>
typename /*const*/ std::underlying_type<enum_t>::type static_enum_cast( enum_t value )
{
	return static_cast<typename std::underlying_type<enum_t>::type>( value );
}

template<class enum_t>
typename constexpr std::underlying_type<enum_t>::type enum_cast( enum_t value )
{
	return static_cast<typename std::underlying_type<enum_t>::type>( value );
}

#endif // INCLUDE_ENUM_CAST_H