#include "log.hpp"

#include "ub_essentials/arguments/real.hpp"

std::string essentials::block::real::log::get_mod_unlocalized_name()
{
	return ESSENTIALS_UNLOCALIZED;
}

const char* essentials::block::real::log::get_unlocalized_name()
{
	return essentials::block::REAL_LOG;
}

const char* essentials::block::real::log::get_category()
{
	return essentials::category::REALS;
}

bool essentials::block::real::log::is_topical()
{
	return false;
}

std::vector<esp::argument::initializer> essentials::block::real::log::get_arguments()
{
	return {
		essentials::argument::real::get_initializer(esp::argument::mode::RAW, esp::argument::mode_restriction::NONE, 3.14159)
	};
}
