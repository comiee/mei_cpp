#pragma once

// 防止检查：Pass by value and use std::move
#define IGNORE_MOVE_CHECK(__arg_name__) [[maybe_unused]] const auto &_##__arg_name__ = __arg_name__;
