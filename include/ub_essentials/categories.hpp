#pragma once
#include "config.h"

#include "ub_essentials/essentials.hpp"

namespace essentials::category
{
//class system : public esp::mod::category
//{
//public:
//	system(const std::string& mod_unlocalized_name, const std::string& mod_display_name)
//		: esp::mod::category(mod_unlocalized_name, mod_display_name)
//	{}
//
//	[[nodiscard]] espresso::color get_color() const override;
//	[[nodiscard]] std::string get_unlocalized_name() const override;
//	[[nodiscard]] std::string get_display_name() const override;
//};
//
//class booleans : public esp::mod::category
//{
//public:
//	booleans(const std::string& mod_unlocalized_name, const std::string& mod_display_name)
//		: esp::mod::category(mod_unlocalized_name, mod_display_name)
//	{}
//
//	[[nodiscard]] espresso::color get_color() const override;
//	[[nodiscard]] std::string get_unlocalized_name() const override;
//	[[nodiscard]] std::string get_display_name() const override;
//};

class reals : public esp::category
{
public:
	std::string get_mod_unlocalized_name() override;
	std::string get_mod_display_name() override;
	espresso::color get_color() override;
	std::string get_unlocalized_name() override;
	std::string get_display_name() override;
};

//class strings : public esp::mod::category
//{
//public:
//	strings(const std::string& mod_unlocalized_name, const std::string& mod_display_name)
//		: esp::mod::category(mod_unlocalized_name, mod_display_name)
//	{}
//
//	[[nodiscard]] espresso::color get_color() const override;
//	[[nodiscard]] std::string get_unlocalized_name() const override;
//	[[nodiscard]] std::string get_display_name() const override;
//};
} // namespace ub_essentials::category