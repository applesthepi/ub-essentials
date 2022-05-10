#include "main.hpp"

#include "ub_essentials/arguments/text.hpp"

const char* essentials::block::system::main::get_unlocalized_name()
{
	return essentials::block::SYSTEM_MAIN;
}

const char* essentials::block::system::main::get_category()
{
	return essentials::category::SYSTEM;
}

const char* essentials::block::system::main::get_ubbs_instance()
{
	return "println!(\"{}\", essentials_main_print.value);";
}

bool essentials::block::system::main::is_topical()
{
	return false;
}

std::vector<esp::argument::initializer> essentials::block::system::main::get_arguments()
{
	return {
		essentials::argument::text::get_initializer(esp::argument::mode::RAW, esp::argument::mode_restriction::RESTRICTED, "main")
	};
}
