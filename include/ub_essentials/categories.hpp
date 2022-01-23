#pragma once
#include "config.h"

#include <espresso/mod/category.hpp>

#define CATEGORY_SYSTEM	  "essentials_system"
#define CATEGORY_BOOLEANS "essentials_booleans"
#define CATEGORY_REALS	  "essentials_reals"
#define CATEGORY_STRINGS  "essentials_strings"

namespace ub_essentials::category
{
class system : public esp::mod::category
{
public:
	system(const std::string& mod_unlocalized_name, const std::string& mod_display_name)
		: esp::mod::category(mod_unlocalized_name, mod_display_name)
	{}

	[[nodiscard]] cap::color get_color() const override;
	[[nodiscard]] std::string get_unlocalized_name() const override;
	[[nodiscard]] std::string get_display_name() const override;
};

class booleans : public esp::mod::category
{
public:
	booleans(const std::string& mod_unlocalized_name, const std::string& mod_display_name)
		: esp::mod::category(mod_unlocalized_name, mod_display_name)
	{}

	[[nodiscard]] cap::color get_color() const override;
	[[nodiscard]] std::string get_unlocalized_name() const override;
	[[nodiscard]] std::string get_display_name() const override;
};

class reals : public esp::mod::category
{
public:
	reals(const std::string& mod_unlocalized_name, const std::string& mod_display_name)
		: esp::mod::category(mod_unlocalized_name, mod_display_name)
	{}

	[[nodiscard]] cap::color get_color() const override;
	[[nodiscard]] std::string get_unlocalized_name() const override;
	[[nodiscard]] std::string get_display_name() const override;
};

class strings : public esp::mod::category
{
public:
	strings(const std::string& mod_unlocalized_name, const std::string& mod_display_name)
		: esp::mod::category(mod_unlocalized_name, mod_display_name)
	{}

	[[nodiscard]] cap::color get_color() const override;
	[[nodiscard]] std::string get_unlocalized_name() const override;
	[[nodiscard]] std::string get_display_name() const override;
};
} // namespace ub_essentials::category