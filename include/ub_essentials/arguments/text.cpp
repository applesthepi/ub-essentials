#include "text.hpp"

#include "ub_essentials/essentials.hpp"

#include <lungo/renderer.hpp>
#include <mocha/stacking/plane.hpp>

esp::argument::initializer essentials::argument::text::get_initializer(esp::argument::mode mode, esp::argument::mode_restriction mode_restriction, const std::string& v0)
{
	auto init = new custom_initializer();
	init->text = v0;
	return {esp::registry::get()->get_argument(essentials::argument::TEXT), mode, mode_restriction, reinterpret_cast<void*>(init) };
}

void essentials::argument::text::create(esp::argument::state* state, argument::initializer* initializer)
{
	auto initializer_custom = reinterpret_cast<custom_initializer*>(initializer->custom);
	auto state_custom = new custom{
		.m_text = std::make_shared<rhr::render::object::text>(
			rhr::registry::char_texture::texture_type::LIGHT_NORMAL,
			BLOCK_HEIGHT_CONTENT,
			true,
			state->plane_offset)
	};

	state_custom->m_mouse_button = [this, state](rhr::handler::input::mouse_button_data mouse_button_data)
	{
		if (state->mode_restriction == esp::argument::mode_restriction::RESTRICTED)
			return;

		if (!check_bounds(state, mouse_button_data.position))
			return;

		if (mouse_button_data.button == rhr::handler::input::mouse_button::MIDDLE && mouse_button_data.operation == rhr::handler::input::mouse_operation::PRESS)
			toggle_mode(state);
	};

	state_custom->m_function_text_update = [state]()
	{
		(*state->function_collection_update)();
	};

	state_custom->m_text->initialize();
	state_custom->m_text->enable_background(false);
	state_custom->m_text->set_static_offset(state->plane_offset);
	state_custom->m_text->set_field_handler(&rhr::stack::plane::primary_plane->get_field());
	state_custom->m_text->set_update_function(&state_custom->m_function_text_update);
	state_custom->m_text->set_depth(rhr::render::renderer::depth_argument_text);
	state_custom->m_text->set_color_primary(espresso::color::black);
	state_custom->m_text->set_color_secondary(state->block_color.get_scaled(BLOCK_ARG_DIFF, false));
	state_custom->m_text->set_padding(esp::argument::padding);
	state_custom->m_text->set_text(initializer_custom->text); // before set_mouse_button
	state_custom->m_text->set_mouse_button(state_custom->m_mouse_button);

	state->custom = reinterpret_cast<void*>(state_custom);
}

void essentials::argument::text::destroy(esp::argument::state* state)
{
	delete reinterpret_cast<custom*>(state->custom);
}

const char* essentials::argument::text::get_unlocalized_name()
{
	return essentials::argument::TEXT;
}

std::string essentials::argument::text::get_ubbs_value(esp::argument::state* state)
{
	return "";
}

esp::reg::type* essentials::argument::text::get_type()
{
	return esp::registry::get()->get_type(essentials::type::F64);
}

void essentials::argument::text::get_valid_casts(std::vector<esp::reg::type*>& valid_types)
{
	esp::registry::get()->get_types(essentials::type::USF.data(), essentials::type::USF.size(), valid_types);
}

esp::argument::padding_style essentials::argument::text::get_padding_style()
{
	return esp::argument::padding_style::HARD;
}

esp::argument::mode essentials::argument::text::get_mode()
{
	return esp::argument::mode::RAW;// TODO: keep, but specify it CAN be used as an override
}

esp::argument::mode_restriction essentials::argument::text::get_mode_restriction()
{
	return esp::argument::mode_restriction::NONE;// TODO: keep, but specify it CAN be used as an override
}

u32 essentials::argument::text::get_width(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);
	return state_custom->m_text->get_size_local().x + (2 * ESSENTIALS_TEXT_DECOR_WIDTH);
}

bool essentials::argument::text::capture_mouse()
{
	return false;
}

void essentials::argument::text::ui_transform_update(
	esp::argument::state* state, rhr::render::interfaces::i_ui::transform_update_spec transform_update_spec
)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	state->parent->update_child_transform(state_custom->m_text, false);
	state_custom->m_text->set_position_local_physical({ ESSENTIALS_TEXT_DECOR_WIDTH, 0 }, true);

	glm::vec<2, f64> pos = state->parent->get_position_physical_absolute();

	state->parent->mark_dirty();
}

void essentials::argument::text::ui_frame_update(esp::argument::state* state, f64 delta_time)
{

}

void essentials::argument::text::ui_render(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);
	state_custom->m_text->render();
}

void essentials::argument::text::ui_reload_swap_chain(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);
	state_custom->m_text->reload_swap_chain();
}

void essentials::argument::text::ui_update_buffers(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);
	state_custom->m_text->update_buffers();
}

void essentials::argument::text::ui_chain_update_buffers(esp::argument::state* state)
{

}

void essentials::argument::text::ui_static_offset_update(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);
	state_custom->m_text->set_static_offset(state->plane_offset);
}

void essentials::argument::text::ui_serialize(esp::argument::state* state, latte::serializer::node& node)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	node.data_names.reserve(1);
	node.data_values.reserve(1);

	node.data_names.emplace_back("data");
	node.data_values.emplace_back(state_custom->m_text->get_text());
}

void essentials::argument::text::ui_deserialize(esp::argument::state* state, latte::serializer::node& node)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	if (!node.verify_data(ESSENTIALS_TEXT_SERIALIZE))
	{
		latte::logger::error(latte::logger::level::EDITOR, __FILE__, __LINE__, "failed to deserialize text argument; invalid data");
		return;
	}

	state_custom->m_text->set_text(node.data_values[0]);
}

void essentials::argument::text::on_set_mode(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	if (state->mode == esp::argument::mode::RAW)
		state_custom->m_text->set_color_secondary(state->block_color.get_scaled(BLOCK_ARG_DIFF, false));
	else if (state->mode == esp::argument::mode::VAR)
		state_custom->m_text->set_color_secondary(espresso::color().from_u8({ 100, 0, 40, 255 }));
}
