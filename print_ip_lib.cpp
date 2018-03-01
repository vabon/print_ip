#include "print_ip_lib.h"
#include "version.h"
#include <iostream>
#include <numeric>

template <typename T>
void print_ip(const std::enable_if<std::is_integral<T>::value, T> & ip)
{
    auto bytes = sizeof(ip);
    unsigned char chunk;
    
    for (auto i = 1; i <= bytes; ++i)
    {
        chunk = static_cast<unsigned char>(ip >> (8 * (bytes - i)) & 0xFF );
        std::cout << +chunk;
        
        if (i < bytes)
            std::cout << ".";
    }
    
    std::cout << std::endl;
}

template<typename T>
void print_ip(const std::enable_if<std::is_compound<T>::value, T> & ip)
{
    std::cout << std::accumulate(std::next(ip.begin()), ip.end(),
                                    std::to_string(ip.front()),
                                    [](std::string a, int b){ return a + '.' + std::to_string(b);
                                    })
              << std::endl;
}

template <>
void print_ip<std::string>(const std::string & ip)
{
    std::cout << ip << std::endl;
}
