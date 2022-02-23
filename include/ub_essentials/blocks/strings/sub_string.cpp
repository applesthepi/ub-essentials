#include "sub_string.hpp"

static void execute_release(espresso::mod::block::pass* pass)
{
	pass->get_string(3) = pass->get_string(0).substr((u64)pass->get_real(1), (u64)pass->get_real(2));
}

static void execute_debug(espresso::mod::block::pass* pass)
{
	std::string& str	   = pass->get_string(0);
	f64& offset			   = pass->get_real(1);
	f64& count			   = pass->get_real(2);
	std::string& final_str = pass->get_string(3);

	if (std::floor(offset) != offset)
	{
		pass->log_error(
			"failed to substring at \"" + std::to_string(offset) + "\" for count \"" + std::to_string(count)
				+ "\" from string \"" + str + "\" to replacing string \"" + final_str + "\"; offset is a decimal",
			espresso::mod::block::pass::logger_fatality::BREAK);
		return;
	}

	if (std::floor(count) != count)
	{
		pass->log_error(
			"failed to substring at \"" + std::to_string(offset) + "\" for count \"" + std::to_string(count)
				+ "\" from string \"" + str + "\" to replacing string \"" + final_str + "\"; count is a decimal",
			espresso::mod::block::pass::logger_fatality::BREAK);
		return;
	}

	i64 idx_at	  = offset;
	i64 idx_count = count;

	if (idx_at >= static_cast<i64>(str.length()) || idx_at < 0)
	{
		pass->log_error(
			"failed to substring at \"" + std::to_string(idx_at) + "\" for count \"" + std::to_string(idx_count)
				+ "\" from string \"" + str + "\" to replacing string \"" + final_str + "\"; offset index out of range",
			espresso::mod::block::pass::logger_fatality::BREAK);
		return;
	}

	if (idx_count + idx_at > static_cast<i64>(str.length()))
	{
		pass->log_error(
			"failed to substring at \"" + std::to_string(idx_at) + "\" for count \"" + std::to_string(idx_count)
				+ "\" from string \"" + str + "\" to replacing string \"" + final_str + "\"; count to high",
			espresso::mod::block::pass::logger_fatality::BREAK);
		return;
	}

	if (idx_count < 0)
	{
		pass->log_error(
			"failed to substring at \"" + std::to_string(idx_at) + "\" for count \"" + std::to_string(idx_count)
				+ "\" from string \"" + str + "\" to replacing string \"" + final_str + "\"; count index out of range",
			espresso::mod::block::pass::logger_fatality::BREAK);
		return;
	}

	final_str = str.substr(idx_at, idx_count);
}

const char* ub_essentials::block::string::sub_string::get_unlocalized_name() const
{
	return "essentials_string_sub_string";
}

const char* ub_essentials::block::string::sub_string::get_category() const
{
	return CATEGORY_STRINGS;
}

espresso::mod::block::block::execution ub_essentials::block::string::sub_string::pull_execute_release() const
{
	return execute_release;
}

espresso::mod::block::block::execution ub_essentials::block::string::sub_string::pull_execute_debug() const
{
	return execute_debug;
}

std::vector<espresso::mod::block::block::argument::initializer>
ub_essentials::block::string::sub_string::get_arguments() const
{
	return {
		{espresso::mod::block::block::argument::type::STRING,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"},
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "at"		 },
		{espresso::mod::block::block::argument::type::REAL,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "0"		},
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "count"	},
		{espresso::mod::block::block::argument::type::REAL,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "1"		},
		{espresso::mod::block::block::argument::type::TEXT,
		 espresso::mod::block::block::argument::variable_mode_restriction::NONE,
		 espresso::mod::block::block::argument::variable_mode::RAW,
		 "for"	  },
		{espresso::mod::block::block::argument::type::STRING,
		 espresso::mod::block::block::argument::variable_mode_restriction::RESTRICTED,
		 espresso::mod::block::block::argument::variable_mode::VAR,
		 "variable"}
	};
}
