#include "string.hpp"

const char* essentials::type::string::get_unlocalized_name()
{
	return essentials::type::STRING;
}

const char* essentials::type::string::get_ubbs_instance_r()
{
	return "String = <<<>>>";
}

const char* essentials::type::string::get_ubbs_instance_l()
{
	return "String = \"\"";
}

const char* essentials::type::string::get_ubbs_definition()
{
	return nullptr;
}