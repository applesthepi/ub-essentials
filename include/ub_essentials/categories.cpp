#include "categories.hpp"

cap::color ub_essentials::category::system::get_color() const { return cap::color().from_u8({88, 95, 179, 255}); }

std::string ub_essentials::category::system::get_unlocalized_name() const { return CATEGORY_SYSTEM; }

std::string ub_essentials::category::system::get_display_name() const { return "system"; }

cap::color ub_essentials::category::booleans::get_color() const { return cap::color().from_u8({230, 103, 67, 255}); }

std::string ub_essentials::category::booleans::get_unlocalized_name() const { return CATEGORY_BOOLEANS; }

std::string ub_essentials::category::booleans::get_display_name() const { return "booleans"; }

cap::color ub_essentials::category::reals::get_color() const { return cap::color().from_u8({79, 154, 62, 255}); }

std::string ub_essentials::category::reals::get_unlocalized_name() const { return CATEGORY_REALS; }

std::string ub_essentials::category::reals::get_display_name() const { return "reals"; }

cap::color ub_essentials::category::strings::get_color() const { return cap::color().from_u8({16, 167, 167, 255}); }

std::string ub_essentials::category::strings::get_unlocalized_name() const { return CATEGORY_STRINGS; }

std::string ub_essentials::category::strings::get_display_name() const { return "strings"; }
