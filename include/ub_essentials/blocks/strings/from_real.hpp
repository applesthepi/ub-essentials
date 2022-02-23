#pragma once
#include "ub_essentials/categories.hpp"
#include <espresso/mod/data.hpp>

namespace ub_essentials::block::string
{
class from_real : public espresso::mod::block::block
{
public:
	const char* get_unlocalized_name() const override;
	const char* get_category() const override;

	espresso::mod::block::block::execution pull_execute_release() const override;
	espresso::mod::block::block::execution pull_execute_debug() const override;

	std::vector<espresso::mod::block::block::argument::initializer> get_arguments() const override;
};
} // namespace ub_essentials::block::string