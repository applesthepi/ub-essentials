#pragma once
#include "config.h"

#include <espresso/mod_data.hpp>

#if LINUX
#define UB_EXPORT extern "C"
#else
#define UB_EXPORT extern "C" __declspec(dllexport)
#endif

UB_EXPORT void initialization(esp::mod_data* mod_data);
