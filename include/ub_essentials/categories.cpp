#include "categories.hpp"

std::string essentials::category::system::get_mod_unlocalized_name()
{
	return ESSENTIALS_UNLOCALIZED;
}

std::string essentials::category::system::get_mod_display_name()
{
	return ESSENTIALS_DISPLAY;
}

espresso::color essentials::category::system::get_color()
{
	return espresso::color().from_u8({ 33, 65, 84, 255 });
}

std::string essentials::category::system::get_unlocalized_name()
{
	return essentials::category::SYSTEM;
}

std::string essentials::category::system::get_display_name()
{
	return "system";
}

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