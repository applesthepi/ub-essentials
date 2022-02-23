#include "from_string.hpp"

static void execute_release(espresso::mod::block::pass* pass)
{
	pass->get_real(0) = std::stod(pass->get_string(1));
}

static void execute_debug(espresso::mod::block::pass* pass)
{
	f64 nd = 0.0;

	try
	{
		nd = std::stod(pass->get_string(1));
	}
	catch (std::invalid_argument&)
	{
		pass->log_error(
			"failed to set real \"" + std::to_string(pass->get_real(0)) + "\" to string \"" + pass->get_string(1)
				+ "\"; the string could not be parsed into a real",
			espresso::mod::block::pass::logger_fatality::BREAK);
		return;
	}

	pass->get_real(0) = nd;
}

const char* ub_essentials::block::real::from_string::get_unlocalized_name() const
{
	return "essentials_real_from_string";
}

const char* ub_essentials::block::real::from_string::get_category() const
{
	return CATEGORY_REALS;
}

espresso::mod::block::block::execution ub_essentials::block::real::from_string::pull_execute_release() const
{
	return execute_release;
}

espresso::mod::block::block::execution ub_essentials::block::real::from_string::pull_execute_debug() const
{
	return execute_debug;
}

std::vector<espresso::mod::block::block::argument::initializer>
ub_essentials::block::real::from_string::get_arguments() const
{
	return {
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "set"	  },
		{espresso::mod::block::block::argument::type::REAL,
		 espresso::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"},
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "to"		 },
		{espresso::mod::block::block::argument::type::STRING,
		 espresso::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}