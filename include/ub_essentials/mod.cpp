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

#include "ub_essentials/arguments/real.hpp"

//
// BLOCKS
//

//#include "ub_essentials/blocks/system/main.hpp"
//
//#include "ub_essentials/blocks/booleans/and.hpp"
//#include "ub_essentials/blocks/booleans/flip.hpp"
//#include "ub_essentials/blocks/booleans/log.hpp"
//#include "ub_essentials/blocks/booleans/not.hpp"
//#include "ub_essentials/blocks/booleans/or.hpp"
//#include "ub_essentials/blocks/booleans/set.hpp"
//
//#include "ub_essentials/blocks/reals/abs.hpp"
//#include "ub_essentials/blocks/reals/ceil.hpp"
//#include "ub_essentials/blocks/reals/comp_eq.hpp"
//#include "ub_essentials/blocks/reals/comp_gr.hpp"
//#include "ub_essentials/blocks/reals/comp_gr_eq.hpp"
//#include "ub_essentials/blocks/reals/comp_ls.hpp"
//#include "ub_essentials/blocks/reals/comp_ls_eq.hpp"
//#include "ub_essentials/blocks/reals/cos.hpp"
//#include "ub_essentials/blocks/reals/divide.hpp"
//#include "ub_essentials/blocks/reals/eulers.hpp"
//#include "ub_essentials/blocks/reals/floor.hpp"
//#include "ub_essentials/blocks/reals/from_bool.hpp"
//#include "ub_essentials/blocks/reals/from_string.hpp"
#include "ub_essentials/blocks/reals/log.hpp"
//#include "ub_essentials/blocks/reals/logarithmic.hpp"
//#include "ub_essentials/blocks/reals/minus.hpp"
//#include "ub_essentials/blocks/reals/mod.hpp"
//#include "ub_essentials/blocks/reals/multiply.hpp"
//#include "ub_essentials/blocks/reals/pi.hpp"
//#include "ub_essentials/blocks/reals/plus.hpp"
//#include "ub_essentials/blocks/reals/pow.hpp"
//#include "ub_essentials/blocks/reals/random.hpp"
//#include "ub_essentials/blocks/reals/round.hpp"
//#include "ub_essentials/blocks/reals/set.hpp"
//#include "ub_essentials/blocks/reals/sin.hpp"
//#include "ub_essentials/blocks/reals/tan.hpp"
//
//#include "ub_essentials/blocks/strings/cat_from.hpp"
//#include "ub_essentials/blocks/strings/char_at.hpp"
//#include "ub_essentials/blocks/strings/comp_eq.hpp"
//#include "ub_essentials/blocks/strings/find.hpp"
//#include "ub_essentials/blocks/strings/from_bool.hpp"
//#include "ub_essentials/blocks/strings/from_real.hpp"
//#include "ub_essentials/blocks/strings/from_real_int.hpp"
//#include "ub_essentials/blocks/strings/length.hpp"
//#include "ub_essentials/blocks/strings/log.hpp"
//#include "ub_essentials/blocks/strings/set.hpp"
//#include "ub_essentials/blocks/strings/sub_string.hpp"

UB_EXPORT void initialization(esp::mod_data* mod_data)
{
	//
	// MOD SETUP
	//

	latte::logger::initialize();
	latte::logger::set_stream_system(mod_data->get_stream_system());
	latte::logger::set_stream_editor(mod_data->get_stream_editor());
	latte::logger::set_stream_runtime(mod_data->get_stream_runtime());

	esp::registry::set(mod_data->get_registry_esp());
	rhr::registry::char_texture::set(mod_data->get_registry_char_texture());
	rhr::render::renderer::set(mod_data->get_renderer());

	mod_data->set_mod_display_name("essentials");
	mod_data->set_mod_unlocalized_name("essentials");
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

	REGISTER_ARGUMENT(new essentials::argument::real());

	//
	// BLOCKS
	//

	//data->register_block(new essentials::block::system::main());
	//
	//data->register_block(new essentials::block::boolean::and_());
	//data->register_block(new essentials::block::boolean::flip());
	//data->register_block(new essentials::block::boolean::log());
	//data->register_block(new essentials::block::boolean::not_());
	//data->register_block(new essentials::block::boolean::or_());
	//data->register_block(new essentials::block::boolean::set());
	//
	//data->register_block(new essentials::block::real::abs());
	//data->register_block(new essentials::block::real::ceil());
	//data->register_block(new essentials::block::real::comp_eq());
	//data->register_block(new essentials::block::real::comp_gr());
	//data->register_block(new essentials::block::real::comp_gr_eq());
	//data->register_block(new essentials::block::real::comp_ls());
	//data->register_block(new essentials::block::real::comp_ls_eq());
	//data->register_block(new essentials::block::real::cos());
	//data->register_block(new essentials::block::real::divide());
	//data->register_block(new essentials::block::real::eulers());
	//data->register_block(new essentials::block::real::floor());
	//data->register_block(new essentials::block::real::from_bool());
	//data->register_block(new essentials::block::real::from_string());
	REGISTER_BLOCK(new essentials::block::real::log());
	//data->register_block(new essentials::block::real::logarithmic());
	//data->register_block(new essentials::block::real::minus());
	//data->register_block(new essentials::block::real::mod());
	//data->register_block(new essentials::block::real::multiply());
	//data->register_block(new essentials::block::real::pi());
	//data->register_block(new essentials::block::real::plus());
	//data->register_block(new essentials::block::real::pow());
	//data->register_block(new essentials::block::real::random());
	//data->register_block(new essentials::block::real::round());
	//data->register_block(new essentials::block::real::set());
	//data->register_block(new essentials::block::real::sin());
	//data->register_block(new essentials::block::real::tan());
	//
	//data->register_block(new essentials::block::string::cat_from());
	//data->register_block(new essentials::block::string::char_at());
	//data->register_block(new essentials::block::string::comp_eq());
	//data->register_block(new essentials::block::string::find());
	//data->register_block(new essentials::block::string::from_bool());
	//data->register_block(new essentials::block::string::from_real());
	//data->register_block(new essentials::block::string::from_real_int());
	//data->register_block(new essentials::block::string::length());
	//data->register_block(new essentials::block::string::log());
	//data->register_block(new essentials::block::string::set());
	//data->register_block(new essentials::block::string::sub_string());

	//
	// CATEGORIES
	//

	//data->register_category(
	//	new essentials::category::system(data->get_mod_unlocalized_name(), data->get_mod_display_name()));
	REGISTER_CATEGORY(new essentials::category::reals());
	//data->register_category(
	//	new essentials::category::strings(data->get_mod_unlocalized_name(), data->get_mod_display_name()));
	//data->register_category(
	//	new essentials::category::booleans(data->get_mod_unlocalized_name(), data->get_mod_display_name()));
}
