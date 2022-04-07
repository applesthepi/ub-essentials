#include "categories.hpp"

/*espresso::color essentials::category::system::get_color() const
{
	return espresso::color().from_u8({88, 95, 179, 255});
}

std::string essentials::category::system::get_unlocalized_name() const
{
	return essentials::category::REALS;
}

std::string essentials::category::system::get_display_name() const
{
	return "system";
}

espresso::color essentials::category::booleans::get_color() const
{
	return espresso::color().from_u8({230, 103, 67, 255});
}

std::string essentials::category::booleans::get_unlocalized_name() const
{
	return CATEGORY_BOOLEANS;
}

std::string essentials::category::booleans::get_display_name() const
{
	return "booleans";
}
*/

std::string essentials::category::reals::get_mod_unlocalized_name()
{
	return ESSENTIALS_UNLOCALIZED;
}

std::string essentials::category::reals::get_mod_display_name()
{
	return ESSENTIALS_DISPLAY;
}

espresso::color essentials::category::reals::get_color()
{
	return espresso::color().from_u8({ 79, 154, 62, 255 });
}

std::string essentials::category::reals::get_unlocalized_name()
{
	return essentials::category::REALS;
}

std::string essentials::category::reals::get_display_name()
{
	return "reals";
}
/*
espresso::color essentials::category::strings::get_color() const
{
	return espresso::color().from_u8({16, 167, 167, 255});
}

std::string essentials::category::strings::get_unlocalized_name() const
{
	return CATEGORY_STRINGS;
}

std::string essentials::category::strings::get_display_name() const
{
	return "strings";
}
*/