#include "f64.hpp"

const char* essentials::type::f64::get_unlocalized_name()
{
	return essentials::type::F64;
}

const char* essentials::type::f64::get_ubbs_instance_r()
{
	return "f64 = <<<>>>";
}

const char* essentials::type::f64::get_ubbs_instance_l()
{
	return "f64 = 0.0";
}

const char* essentials::type::f64::get_ubbs_definition()
{
	return nullptr;
}