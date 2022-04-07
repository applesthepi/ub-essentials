#pragma once
#include "config.h"

#include "ub_essentials/essentials.hpp"

#include <espresso/argument.hpp>

#define ESSENTIALS_REAL_DECOR_WIDTH 6
#define ESSENTIALS_REAL_SERIALIZE { "data" }

namespace essentials::argument
{
class real : public esp::argument
{
public:
	static esp::argument::initializer get_initializer(esp::argument::mode mode, esp::argument::mode_restriction mode_restriction, double v0);
protected:
	void create(argument::state* state, argument::initializer* initializer) override;
	void destroy(argument::state* state) override;
	const char* get_unlocalized_name() override;
	esp::reg::type* get_type() override;
	void get_valid_casts(std::vector<esp::reg::type*>& valid_types) override;
	argument::padding_style get_padding_style() override;
	argument::mode get_mode() override;
	argument::mode_restriction get_mode_restriction() override;
	u32 get_width(argument::state* state) override;
	void ui_transform_update(argument::state* state, rhr::render::interfaces::i_ui::transform_update_spec transform_update_spec) override;
	void ui_frame_update(argument::state* state, f64 delta_time) override;
	void ui_render(argument::state* state) override;
	void ui_reload_swap_chain(argument::state* state) override;
	void ui_update_buffers(argument::state* state) override;
	void ui_chain_update_buffers(argument::state* state) override;
	void ui_static_offset_update(argument::state* state) override;
	void ui_serialize(argument::state* state, latte::serializer::node& node) override;
	void ui_deserialize(argument::state* state, latte::serializer::node& node) override;
	void on_set_mode(argument::state* state) override;
};
}