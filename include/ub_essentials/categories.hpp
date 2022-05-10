#pragma once
#include "config.h"

#include "ub_essentials/essentials.hpp"

namespace essentials::category
{
class system : public esp::category
{
public:
	std::string get_mod_unlocalized_name() override;
	std::string get_mod_display_name() override;
	espresso::color get_color() override;
	std::string get_unlocalized_name() override;
	std::string get_display_name() override;
};
class reals : public esp::category
{
public:
	std::string get_mod_unlocalized_name() override;
	std::string get_mod_display_name() override;
	espresso::color get_color() override;
	std::string get_unlocalized_name() override;
	std::string get_display_name() override;
};
} // namespace ub_essentials::category