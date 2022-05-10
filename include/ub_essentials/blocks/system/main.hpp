#pragma once
#include "config.h"

#include "ub_essentials/essentials.hpp"

namespace essentials::block::system
{
class main : public esp::block
{
public:
	const char* get_unlocalized_name() override;
	const char* get_category() override;
	const char* get_ubbs_instance() override;
	bool is_topical() override;
	std::vector<esp::argument::initializer> get_arguments() override;
};
}
