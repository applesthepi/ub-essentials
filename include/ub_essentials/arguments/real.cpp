#include "real.hpp"

#include "ub_essentials/essentials.hpp"

#include <espresso/registry.hpp>
#include <lungo/objects/object.hpp>
#include <lungo/objects/text.hpp>
#include <lungo/renderer.hpp>

struct custom
{
	std::shared_ptr<rhr::render::object::text> m_text;

	std::shared_ptr<rhr::render::object::object> m_decor_left_top;
	std::shared_ptr<rhr::render::object::object> m_decor_left_bottom;
	std::shared_ptr<rhr::render::object::object> m_decor_right_top;
	std::shared_ptr<rhr::render::object::object> m_decor_right_bottom;

	std::function<void(glm::vec<2, i32> position, f32 scroll, rhr::handler::input::mouse_operation operation, rhr::handler::input::mouse_button button)>
		m_mouse_button;
	std::function<void()> m_function_text_update;
};

struct custom_initializer
{
	std::string text;
};

esp::argument::initializer essentials::argument::real::get_initializer(esp::argument::mode mode, esp::argument::mode_restriction mode_restriction, double v0)
{
	auto init = new custom_initializer();
	init->text = std::to_string(v0);
	return {esp::registry::get()->get_argument(essentials::argument::REAL), mode, mode_restriction, reinterpret_cast<void*>(init) };
}

void essentials::argument::real::create(esp::argument::state* state, argument::initializer* initializer)
{
	auto initializer_custom = reinterpret_cast<custom_initializer*>(initializer->custom);
	auto state_custom = new custom{
		.m_text = std::make_shared<rhr::render::object::text>(
			rhr::registry::char_texture::texture_type::LIGHT_NORMAL,
			BLOCK_HEIGHT_CONTENT,
			false,
			true,
			state->plane_offset),
		.m_decor_left_top = std::make_shared<rhr::render::object::object>(true),
		.m_decor_left_bottom = std::make_shared<rhr::render::object::object>(true),
		.m_decor_right_top = std::make_shared<rhr::render::object::object>(true),
		.m_decor_right_bottom = std::make_shared<rhr::render::object::object>(true)
	};

	state_custom->m_mouse_button = [this, state](glm::vec<2, i32> position, f32 scroll, rhr::handler::input::mouse_operation operation, rhr::handler::input::mouse_button button)
	{
		if (button == rhr::handler::input::mouse_button::MIDDLE && operation == rhr::handler::input::mouse_operation::PRESS)
			toggle_mode(state);
	};

	state_custom->m_function_text_update = [state]()
	{
		(*state->function_collection_update)();
	};

	state_custom->m_decor_left_top->set_offset(state->plane_offset);
	state_custom->m_decor_left_bottom->set_offset(state->plane_offset);
	state_custom->m_decor_right_top->set_offset(state->plane_offset);
	state_custom->m_decor_right_bottom->set_offset(state->plane_offset);

	state_custom->m_text->initialize();
	state_custom->m_text->set_static_offset(state->plane_offset);
	state_custom->m_text->set_update_function(&state_custom->m_function_text_update);
	state_custom->m_text->set_weak_field(state_custom->m_text);
	state_custom->m_text->set_depth(rhr::render::renderer::depth_argument_text);
	state_custom->m_text->set_color_primary(espresso::color::text_primary_color);
	state_custom->m_text->set_color_secondary(state->block_color);
	state_custom->m_text->set_padding(esp::argument::padding);
	state_custom->m_text->set_mouse_button(state_custom->m_mouse_button);
	state_custom->m_text->set_text(initializer_custom->text);

	state->custom = reinterpret_cast<void*>(state_custom);
}

void essentials::argument::real::destroy(esp::argument::state* state)
{
	delete reinterpret_cast<custom*>(state->custom);
}

const char* essentials::argument::real::get_unlocalized_name()
{
	return essentials::argument::REAL;
}

esp::reg::type* essentials::argument::real::get_type()
{
	return esp::registry::get()->get_type(essentials::type::F64);
}

void essentials::argument::real::get_valid_casts(std::vector<esp::reg::type*>& valid_types)
{
	esp::registry::get()->get_types(essentials::type::USF.data(), essentials::type::USF.size(), valid_types);
}

esp::argument::padding_style essentials::argument::real::get_padding_style()
{
	return esp::argument::padding_style::HARD;
}

esp::argument::mode essentials::argument::real::get_mode()
{
	return esp::argument::mode::RAW;// TODO: keep, but specify it CAN be used as an override
}

esp::argument::mode_restriction essentials::argument::real::get_mode_restriction()
{
	return esp::argument::mode_restriction::NONE;// TODO: keep, but specify it CAN be used as an override
}

u32 essentials::argument::real::get_width(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);
	return state_custom->m_text->get_size_local().x + (2 * ESSENTIALS_REAL_DECOR_WIDTH);
}

void essentials::argument::real::ui_transform_update(
	esp::argument::state* state, rhr::render::interfaces::i_ui::transform_update_spec transform_update_spec
)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	state->parent->update_child_transform(state_custom->m_text, false);
	state_custom->m_text->set_position_local_physical({ ESSENTIALS_REAL_DECOR_WIDTH, 0 }, true);

	glm::vec<2, f64> pos = state->parent->get_position_physical_absolute();
	state_custom->m_decor_left_top->set_super_position({pos.x, pos.y, rhr::render::renderer::depth_argument});
	state_custom->m_decor_left_bottom->set_super_position({pos.x, pos.y, rhr::render::renderer::depth_argument});
	state_custom->m_decor_right_top->set_super_position({pos.x, pos.y, rhr::render::renderer::depth_argument});
	state_custom->m_decor_right_bottom->set_super_position({pos.x, pos.y, rhr::render::renderer::depth_argument});

	state->parent->mark_dirty();
}

void essentials::argument::real::ui_frame_update(esp::argument::state* state, f64 delta_time)
{

}

void essentials::argument::real::ui_render(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	state_custom->m_text->render();

	state_custom->m_decor_left_top->render();
	state_custom->m_decor_left_bottom->render();
	state_custom->m_decor_right_top->render();
	state_custom->m_decor_right_bottom->render();
}

void essentials::argument::real::ui_reload_swap_chain(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	state_custom->m_text->reload_swap_chain();

	state_custom->m_decor_left_top->reload_swap_chain();
	state_custom->m_decor_left_bottom->reload_swap_chain();
	state_custom->m_decor_right_top->reload_swap_chain();
	state_custom->m_decor_right_bottom->reload_swap_chain();
}

void essentials::argument::real::ui_update_buffers(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	state_custom->m_text->update_buffers();

	rhr::render::vertex vertices[12];
	f32 other_side = ESSENTIALS_REAL_DECOR_WIDTH + state_custom->m_text->get_size_local().x;

	espresso::color use_color = state->block_color;
	if (state->mode == esp::argument::mode::VAR)
		use_color = espresso::color().from_u8({ 100, 0, 40, 255 });

	vertices[0] =
		rhr::render::vertex({ static_cast<f32>(ESSENTIALS_REAL_DECOR_WIDTH), 0, 0 }, use_color.get_normalized(), { 0.0f, 0.0f });
	vertices[1] = rhr::render::vertex({0, 0, 0}, use_color.get_normalized(), { 0.0f, 0.0f });
	vertices[2] = rhr::render::vertex(
		{ static_cast<f32>(ESSENTIALS_REAL_DECOR_WIDTH), static_cast<f32>(BLOCK_HEIGHT_CONTENT / 2), 0 },
		use_color.get_normalized(),
		{0.0f, 0.0f});

	vertices[3] = rhr::render::vertex(
		{ static_cast<f32>(ESSENTIALS_REAL_DECOR_WIDTH), static_cast<f32>(BLOCK_HEIGHT_CONTENT / 2), 0 },
		use_color.get_normalized(),
		{0.0f, 0.0f});
	vertices[4] = rhr::render::vertex(
		{ 0, static_cast<f32>(BLOCK_HEIGHT_CONTENT), 0}, use_color.get_normalized(), { 0.0f, 0.0f });
	vertices[5] = rhr::render::vertex(
		{ static_cast<f32>(ESSENTIALS_REAL_DECOR_WIDTH), static_cast<f32>(BLOCK_HEIGHT_CONTENT), 0},
		use_color.get_normalized(),
		{0.0f, 0.0f});

	vertices[6] = rhr::render::vertex({ other_side, 0, 0 }, use_color.get_normalized(), { 0.0f, 0.0f });
	vertices[7] = rhr::render::vertex(
		{ other_side + static_cast<f32>(ESSENTIALS_REAL_DECOR_WIDTH), 0, 0}, use_color.get_normalized(), { 0.0f, 0.0f });
	vertices[8] = rhr::render::vertex(
		{ other_side, static_cast<f32>(BLOCK_HEIGHT_CONTENT / 2), 0 },
		use_color.get_normalized(),
		{ 0.0f, 0.0f });

	vertices[9] = rhr::render::vertex(
		{ other_side, static_cast<f32>(BLOCK_HEIGHT_CONTENT / 2), 0 },
		use_color.get_normalized(),
		{ 0.0f, 0.0f });
	vertices[10] = rhr::render::vertex(
		{ other_side + static_cast<f32>(ESSENTIALS_REAL_DECOR_WIDTH), static_cast<f32>(BLOCK_HEIGHT_CONTENT), 0 },
		use_color.get_normalized(),
		{ 0.0f, 0.0f });
	vertices[11] = rhr::render::vertex(
		{ other_side, static_cast<f32>(BLOCK_HEIGHT_CONTENT), 0 }, use_color.get_normalized(), { 0.0f, 0.0f });

	state_custom->m_decor_left_top->update_vertices(vertices + 0, 3, true);
	state_custom->m_decor_left_bottom->update_vertices(vertices + 3, 3, true);
	state_custom->m_decor_right_top->update_vertices(vertices + 6, 3, true);
	state_custom->m_decor_right_bottom->update_vertices(vertices + 9, 3, true);
}

void essentials::argument::real::ui_chain_update_buffers(esp::argument::state* state)
{

}

void essentials::argument::real::ui_static_offset_update(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	state_custom->m_decor_left_top->set_offset(state->plane_offset);
	state_custom->m_decor_left_bottom->set_offset(state->plane_offset);
	state_custom->m_decor_right_top->set_offset(state->plane_offset);
	state_custom->m_decor_right_bottom->set_offset(state->plane_offset);

	state_custom->m_text->set_static_offset(state->plane_offset);
}

void essentials::argument::real::ui_serialize(esp::argument::state* state, latte::serializer::node& node)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	node.data_names.reserve(1);
	node.data_values.reserve(1);

	node.data_names.emplace_back("data");
	node.data_values.emplace_back(state_custom->m_text->get_text());
}

void essentials::argument::real::ui_deserialize(esp::argument::state* state, latte::serializer::node& node)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	if (!node.verify_data(ESSENTIALS_REAL_SERIALIZE))
	{
		latte::logger::error(latte::logger::level::EDITOR, __FILE__, __LINE__, "failed to deserialize real argument; invalid data");
		return;
	}

	state_custom->m_text->set_text(node.data_values[0]);
}

void essentials::argument::real::on_set_mode(esp::argument::state* state)
{
	auto state_custom = reinterpret_cast<custom*>(state->custom);

	if (state->mode == esp::argument::mode::RAW)
		state_custom->m_text->set_color_secondary(state->block_color);
	else if (state->mode == esp::argument::mode::VAR)
		state_custom->m_text->set_color_secondary(espresso::color().from_u8({ 100, 0, 40, 255 }));
}
