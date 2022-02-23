#include "log.hpp"

static void execute_release(espresso::mod::block::pass* pass)
{
	pass->log_info(pass->get_bool(0) ? "true" : "false");
}

static void execute_debug(espresso::mod::block::pass* pass)
{
	execute_release(pass);
}

const char* ub_essentials::block::boolean::log::get_unlocalized_name() const
{
	return "essentials_boolean_log";
}

const char* ub_essentials::block::boolean::log::get_category() const
{
	return CATEGORY_BOOLEANS;
}

espresso::mod::block::block::execution ub_essentials::block::boolean::log::pull_execute_release() const
{
	return execute_release;
}

espresso::mod::block::block::execution ub_essentials::block::boolean::log::pull_execute_debug() const
{
	return execute_debug;
}

std::vector<espresso::mod::block::block::argument::initializer> ub_essentials::block::boolean::log::get_arguments() const
{
	return {
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "log"	  },
		{espresso::mod::block::block::argument::type::BOOL,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}
