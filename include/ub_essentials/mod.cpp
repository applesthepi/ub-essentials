#include "mod.hpp"

#include "ub_essentials/categories.hpp"

//
// TYPES
//

#include "ub_essentials/types/u8.hpp"
#include "ub_essentials/types/u16.hpp"
#include "ub_essentials/types/u32.hpp"
#include "ub_essentials/types/u64.hpp"

#include "ub_essentials/types/i8.hpp"
#include "ub_essentials/types/i16.hpp"
#include "ub_essentials/types/i32.hpp"
#include "ub_essentials/types/i64.hpp"

#include "ub_essentials/types/f32.hpp"
#include "ub_essentials/types/f64.hpp"

#include "ub_essentials/types/bool.hpp"
#include "ub_essentials/types/string.hpp"

//
// ARGUMENTS
//

#include "ub_essentials/arguments/text.hpp"
#include "ub_essentials/arguments/real.hpp"

//
// BLOCKS
//

#include "ub_essentials/blocks/reals/log.hpp"
#include "ub_essentials/blocks/system/main.hpp"

#define MOD_UNLOCALIZED ESSENTIALS_UNLOCALIZED

UB_EXPORT void initialization(esp::mod_data* mod_data)
{
	//
	// MOD SETUP
	//

	// TODO: you shouldn't have to do any of this yourself

	latte::logger::initialize();
	rhr::handler::input::initialize();

	latte::logger::set_stream_system(mod_data->get_stream_system());
	latte::logger::set_stream_editor(mod_data->get_stream_editor());
	latte::logger::set_stream_runtime(mod_data->get_stream_runtime());

	esp::registry::set(mod_data->get_registry_esp());
	rhr::registry::char_texture::set(mod_data->get_registry_char_texture());
	rhr::render::renderer::set(mod_data->get_renderer());
	rhr::stack::plane::primary_plane = *mod_data->get_primary_plane();
	rhr::stack::plane::toolbar_plane = *mod_data->get_toolbar_plane();

	mod_data->set_input_stream(rhr::handler::input::get_stream());

	mod_data->set_mod_display_name(ESSENTIALS_DISPLAY);
	mod_data->set_mod_unlocalized_name(ESSENTIALS_UNLOCALIZED);
	mod_data->set_version("NULL"); // TODO: version

	esp::registry* registry = esp::registry::get();

	//
	// TYPES
	//

	REGISTER_TYPE(new essentials::type::u8());
	REGISTER_TYPE(new essentials::type::u16());
	REGISTER_TYPE(new essentials::type::u32());
	REGISTER_TYPE(new essentials::type::u64());

	REGISTER_TYPE(new essentials::type::i8());
	REGISTER_TYPE(new essentials::type::i16());
	REGISTER_TYPE(new essentials::type::i32());
	REGISTER_TYPE(new essentials::type::i64());

	REGISTER_TYPE(new essentials::type::f32());
	REGISTER_TYPE(new essentials::type::f64());

	REGISTER_TYPE(new essentials::type::bool_());
	REGISTER_TYPE(new essentials::type::string());

	//
	// ARGUMENTS
	//

	REGISTER_ARGUMENT(new essentials::argument::text());
	REGISTER_ARGUMENT(new essentials::argument::real());

	//
	// BLOCKS
	//

	//REGISTER_BLOCK();

	//REGISTER_BLOCK(new essentials::block::real::log());
	//REGISTER_BLOCK(new essentials::block::system::main());

	//
	// CATEGORIES
	//

	REGISTER_CATEGORY(new essentials::category::system());
	REGISTER_CATEGORY(new essentials::category::reals());

	//
	// DEFINITIONS
	//

	REGISTER_DEFINITION("struct MainPrint {\n"
						"\tvalue: String,\n"
						"}");

	//
	// INITIALIZATION
	//

	REGISTER_INITIALIZATION("\tlet mut essentials_main_print: MainPrint = MainPrint {\n"
							"\t\tvalue: String::from(\"hello there\"),\n"
							"\t};");

	//
	// PARAMETERS
	//

	REGISTER_PARAMETER("&mut essentials_main_print", "essentials_main_print: &mut MainPrint");

	//
	// LIBRARIES
	//

	REGISTER_LIBRARY("serde = \"1.0.137\"");
}
