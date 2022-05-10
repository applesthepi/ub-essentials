#include "i32.hpp"

const char* essentials::type::i32::get_unlocalized_name()
{
	return essentials::type::I32;
}

const char* essentials::type::i32::get_ubbs_instance_r()
{
	return "i32 = <<<>>>";
}

const char* essentials::type::i32::get_ubbs_instance_l()
{
	return "i32 = 0";
}

const char* essentials::type::i32::get_ubbs_definition()
{
	return nullptr;
}