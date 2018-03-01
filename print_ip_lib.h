#pragma once

#include <string>
#include <type_traits>

template <typename T>
void print_ip(const std::enable_if_t<std::is_integral<T>::value, T> &);

template<typename T>
void print_ip(const std::enable_if_t<std::is_compound<T>::value, T> &);

template <>
void print_ip<std::string>(const std::string &);
