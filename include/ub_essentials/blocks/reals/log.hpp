#pragma once
#include "config.h"

#include "ub_essentials/essentials.hpp"

namespace essentials::block::real
{
class log : public esp::block
{
public:
	std::string get_mod_unlocalized_name() override;
	const char* get_unlocalized_name() override;
	const char* get_category() override;
	bool is_topical() override;
	std::vector<esp::argument::initializer> get_arguments() override;
};
}
