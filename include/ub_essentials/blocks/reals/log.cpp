#include "log.hpp"

#include "ub_essentials/arguments/text.hpp"
#include "ub_essentials/arguments/real.hpp"

const char* essentials::block::real::log::get_unlocalized_name()
{
	return essentials::block::REAL_LOG;
}

const char* essentials::block::real::log::get_category()
{
	return essentials::category::REALS;
}

const char* essentials::block::real::log::get_ubbs_instance()
{
	return "println!(\"{}\", <<<0>>>);";
}

bool essentials::block::real::log::is_topical()
{
	return false;
}

std::vector<esp::argument::initializer> essentials::block::real::log::get_arguments()
{
	return {
		essentials::argument::text::get_initializer(esp::argument::mode::RAW, esp::argument::mode_restriction::NONE, "log"),
		essentials::argument::real::get_initializer(esp::argument::mode::RAW, esp::argument::mode_restriction::NONE, 3.1415)
	};
}
