#include "from_real.hpp"

static void execute_release(cap::mod::block::pass* pass) { pass->get_string(0) = std::to_string(pass->get_real(1)); }

static void execute_debug(cap::mod::block::pass* pass) { execute_release(pass); }

const char* ub_essentials::block::string::from_real::get_unlocalized_name() const { return "essentials_string_from_real"; }

const char* ub_essentials::block::string::from_real::get_category() const { return CATEGORY_STRINGS; }

cap::mod::block::block::execution ub_essentials::block::string::from_real::pull_execute_release() const { return execute_release; }

cap::mod::block::block::execution ub_essentials::block::string::from_real::pull_execute_debug() const { return execute_debug; }

std::vector<cap::mod::block::block::argument::initializer> ub_essentials::block::string::from_real::get_arguments() const
{
	return {
		{cap::mod::block::block::argument::type::TEXT,
		 cap::mod::block::block::argument::variable_mode_restriction::NONE,
		 cap::mod::block::block::argument::variable_mode::RAW,
		 "set"	  },
		{cap::mod::block::block::argument::type::STRING,
		 cap::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 cap::mod::block::block::argument::variable_mode::VAR,
		 "variable"},
		{cap::mod::block::block::argument::type::TEXT,
		 cap::mod::block::block::argument::variable_mode_restriction::NONE,
		 cap::mod::block::block::argument::variable_mode::RAW,
		 "to"		 },
		{cap::mod::block::block::argument::type::REAL,
		 cap::mod::block::block::argument::variable_mode_restriction::NONE,
		 cap::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}
