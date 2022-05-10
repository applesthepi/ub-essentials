#pragma once
#include "config.h"

#include <espresso/type.hpp>
#include <espresso/argument.hpp>
#include <espresso/block.hpp>
#include <espresso/category.hpp>
#include <espresso/registry.hpp>

#define ESSENTIALS_UNLOCALIZED "essentials"
#define ESSENTIALS_DISPLAY "essentials"

#define ESSENTIALS_SINGLE [[maybe_unused]] static const char*
#define ESSENTIALS_ARRAY(n) [[maybe_unused]] static std::array<const char*, n>

namespace essentials::type
{
ESSENTIALS_SINGLE U8 = "t_essentials_u8";
ESSENTIALS_SINGLE U16 = "t_essentials_u16";
ESSENTIALS_SINGLE U32 = "t_essentials_u32";
ESSENTIALS_SINGLE U64 = "t_essentials_u64";

ESSENTIALS_SINGLE I8 = "t_essentials_i8";
ESSENTIALS_SINGLE I16 = "t_essentials_i16";
ESSENTIALS_SINGLE I32 = "t_essentials_i32";
ESSENTIALS_SINGLE I64 = "t_essentials_i64";

ESSENTIALS_SINGLE F32 = "t_essentials_f32";
ESSENTIALS_SINGLE F64 = "t_essentials_f64";

ESSENTIALS_SINGLE BOOL = "t_essentials_bool";
ESSENTIALS_SINGLE STRING = "t_essentials_string";

/// Unsigned, signed, and floating point types.
ESSENTIALS_ARRAY(10) USF = { U8, U16, U32, U64, I8, I16, I32, I64, F32, F64 };
}

namespace essentials::argument
{
ESSENTIALS_SINGLE TEXT = "a_essentials_text";
ESSENTIALS_SINGLE REAL = "a_essentials_real";
}

namespace essentials::block
{
ESSENTIALS_SINGLE REAL_LOG = "b_essentials_real_log";
ESSENTIALS_SINGLE SYSTEM_MAIN = "b_essentials_system_main";
}

namespace essentials::category
{
ESSENTIALS_SINGLE SYSTEM = "c_essentials_system";
ESSENTIALS_SINGLE REALS = "c_essentials_reals";
}