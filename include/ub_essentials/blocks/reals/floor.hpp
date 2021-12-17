#pragma once
#include "ub_essentials/categories.hpp"
#include <espresso/mod/data.hpp>

namespace ub_essentials::block::real
{
class floor : public cap::mod::block::block
{
public:
	const char* get_unlocalized_name() const override;
	const char* get_category() const override;

	cap::mod::block::block::execution pull_execute_release() const override;
	cap::mod::block::block::execution pull_execute_debug() const override;

	std::vector<cap::mod::block::block::argument::initializer> get_arguments() const override;
};
}