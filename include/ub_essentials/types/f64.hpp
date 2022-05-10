#pragma once
#include "config.h"

#include "ub_essentials/essentials.hpp"

#include <latte/utils.hpp>

namespace essentials::type
{
///
class f64 : public esp::type
{
public:
	const char* get_unlocalized_name() override;
	const char* get_ubbs_instance_r() override;
	const char* get_ubbs_instance_l() override;
	const char* get_ubbs_definition() override;
};
}
