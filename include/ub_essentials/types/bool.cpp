#include "bool.hpp"

const char* essentials::type::bool_::get_unlocalized_name()
{
	return essentials::type::BOOL;
}

const char* essentials::type::bool_::get_ubbs_instance_r()
{
	return "bool = <<<>>>";
}

const char* essentials::type::bool_::get_ubbs_instance_l()
{
	return "bool = false";
}

const char* essentials::type::bool_::get_ubbs_definition()
{
	return nullptr;
}