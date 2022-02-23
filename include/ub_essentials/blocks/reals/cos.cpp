#include "cos.hpp"

static void execute_release(espresso::mod::block::pass* pass)
{
	pass->get_real(0) = std::cos(pass->get_real(0) * (3.141592653589793 / 180.0));
}

static void execute_debug(espresso::mod::block::pass* pass)
{
	execute_release(pass);
}

const char* ub_essentials::block::real::cos::get_unlocalized_name() const
{
	return "essentials_real_cos";
}

const char* ub_essentials::block::real::cos::get_category() const
{
	return CATEGORY_REALS;
}

espresso::mod::block::block::execution ub_essentials::block::real::cos::pull_execute_release() const
{
	return execute_release;
}

espresso::mod::block::block::execution ub_essentials::block::real::cos::pull_execute_debug() const
{
	return execute_debug;
}

std::vector<espresso::mod::block::block::argument::initializer> ub_essentials::block::real::cos::get_arguments() const
{
	return {
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "cos"	  },
		{espresso::mod::block::block::argument::type::REAL,
		 espresso::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}