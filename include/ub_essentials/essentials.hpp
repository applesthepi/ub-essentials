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
ESSENTIALS_SINGLE U8 = "essentials_u8";
ESSENTIALS_SINGLE U16 = "essentials_u16";
ESSENTIALS_SINGLE U32 = "essentials_u32";
ESSENTIALS_SINGLE U64 = "essentials_u64";

ESSENTIALS_SINGLE I8 = "essentials_i8";
ESSENTIALS_SINGLE I16 = "essentials_i16";
ESSENTIALS_SINGLE I32 = "essentials_i32";
ESSENTIALS_SINGLE I64 = "essentials_i64";

ESSENTIALS_SINGLE F32 = "essentials_f32";
ESSENTIALS_SINGLE F64 = "essentials_f64";

ESSENTIALS_SINGLE BOOL = "essentials_bool";
ESSENTIALS_SINGLE STRING = "essentials_string";

/// Unsigned, signed, and floating point types.
ESSENTIALS_ARRAY(10) USF = { U8, U16, U32, U64, I8, I16, I32, I64, F32, F64 };
}

namespace essentials::argument
{
ESSENTIALS_SINGLE REAL = "essentials_real";
}

namespace essentials::block
{
ESSENTIALS_SINGLE REAL_LOG = "essentials_real_log";
}

namespace essentials::category
{
ESSENTIALS_SINGLE REALS = "essentials_reals";
}