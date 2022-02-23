#include "from_real_int.hpp"

static void execute_release(espresso::mod::block::pass* pass)
{
	pass->get_string(0) = std::to_string(static_cast<i64>(pass->get_real(1)));
}

static void execute_debug(espresso::mod::block::pass* pass)
{
	execute_release(pass);
}

const char* ub_essentials::block::string::from_real_int::get_unlocalized_name() const
{
	return "essentials_string_from_real_int";
}

const char* ub_essentials::block::string::from_real_int::get_category() const
{
	return CATEGORY_STRINGS;
}

espresso::mod::block::block::execution ub_essentials::block::string::from_real_int::pull_execute_release() const
{
	return execute_release;
}

espresso::mod::block::block::execution ub_essentials::block::string::from_real_int::pull_execute_debug() const
{
	return execute_debug;
}

std::vector<espresso::mod::block::block::argument::initializer>
ub_essentials::block::string::from_real_int::get_arguments() const
{
	return {
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "set"	  },
		{espresso::mod::block::block::argument::type::STRING,
		 espresso::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"},
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "to int"	 },
		{espresso::mod::block::block::argument::type::REAL,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}
