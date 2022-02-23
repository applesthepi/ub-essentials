#include "ceil.hpp"

static void execute_release(espresso::mod::block::pass* pass)
{
	pass->get_real(0) = std::ceil(pass->get_real(0));
}

static void execute_debug(espresso::mod::block::pass* pass)
{
	execute_release(pass);
}

const char* ub_essentials::block::real::ceil::get_unlocalized_name() const
{
	return "essentials_real_ceil";
}

const char* ub_essentials::block::real::ceil::get_category() const
{
	return CATEGORY_REALS;
}

espresso::mod::block::block::execution ub_essentials::block::real::ceil::pull_execute_release() const
{
	return execute_release;
}

espresso::mod::block::block::execution ub_essentials::block::real::ceil::pull_execute_debug() const
{
	return execute_debug;
}

std::vector<espresso::mod::block::block::argument::initializer> ub_essentials::block::real::ceil::get_arguments() const
{
	return {
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "ceil"	   },
		{espresso::mod::block::block::argument::type::REAL,
		 espresso::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}