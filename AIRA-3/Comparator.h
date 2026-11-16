#pragma once

#include "pch.h"

template <typename Compare, typename ArgType>
concept Comparator = (std::is_invocable_v<Compare, ArgType, ArgType>) && (std::is_same_v<bool, std::invoke_result_t<Compare, ArgType, ArgType>>);