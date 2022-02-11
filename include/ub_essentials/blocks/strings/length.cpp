#include "length.hpp"

static void execute_release(cap::mod::block::pass* pass)
{
	pass->get_real(1) = static_cast<f64>(pass->get_string(0).length());
}

static void execute_debug(cap::mod::block::pass* pass)
{
	execute_release(pass);
}

const char* ub_essentials::block::string::length::get_unlocalized_name() const
{
	return "essentials_string_length";
}

const char* ub_essentials::block::string::length::get_category() const
{
	return CATEGORY_STRINGS;
}

cap::mod::block::block::execution ub_essentials::block::string::length::pull_execute_release() const
{
	return execute_release;
}

cap::mod::block::block::execution ub_essentials::block::string::length::pull_execute_debug() const
{
	return execute_debug;
}

std::vector<cap::mod::block::block::argument::initializer> ub_essentials::block::string::length::get_arguments() const
{
	return {
		{cap::mod::block::block::argument::type::TEXT,
		 cap::mod::block::block::argument::variable_mode_restriction::NONE,
		 cap::mod::block::block::argument::variable_mode::RAW,
		 "length"	 },
		{cap::mod::block::block::argument::type::STRING,
		 cap::mod::block::block::argument::variable_mode_restriction::NONE,
		 cap::mod::block::block::argument::variable_mode::VAR,
		 "variable"},
		{cap::mod::block::block::argument::type::TEXT,
		 cap::mod::block::block::argument::variable_mode_restriction::NONE,
		 cap::mod::block::block::argument::variable_mode::RAW,
		 "for"	  },
		{cap::mod::block::block::argument::type::REAL,
		 cap::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 cap::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}
