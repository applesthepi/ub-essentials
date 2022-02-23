#include "and.hpp"

static void execute_release(espresso::mod::block::pass* pass)
{
	pass->get_bool(2) = pass->get_bool(0) && pass->get_bool(1);
}

static void execute_debug(espresso::mod::block::pass* pass)
{
	execute_release(pass);
}

const char* ub_essentials::block::boolean::and_::get_unlocalized_name() const
{
	return "essentials_boolean_and";
}

const char* ub_essentials::block::boolean::and_::get_category() const
{
	return CATEGORY_BOOLEANS;
}

espresso::mod::block::block::execution ub_essentials::block::boolean::and_::pull_execute_release() const
{
	return execute_release;
}

espresso::mod::block::block::execution ub_essentials::block::boolean::and_::pull_execute_debug() const
{
	return execute_debug;
}

std::vector<espresso::mod::block::block::argument::initializer> ub_essentials::block::boolean::and_::get_arguments() const
{
	return {
		{espresso::mod::block::block::argument::type::BOOL,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"},
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "and"	  },
		{espresso::mod::block::block::argument::type::BOOL,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"},
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "for"	  },
		{espresso::mod::block::block::argument::type::BOOL,
		 espresso::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}
