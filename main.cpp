#include "print_ip.h"

#include <list>
#include <string>
#include <vector>

int main(int argc, const char * argv[])
{
    print_ip<char>(-1);
    print_ip<short>(0);
    print_ip<int>(2130706433);
    print_ip<long>(8875824491850138409);
    
    // std::string str("192.168.0.1");
    // print_ip<std::string>(str);
    
    std::vector<int> v(4, 255);
    print_ip<std::vector<int> >(v);
    
    std::list<int> l(4, 0);
    print_ip<std::list<int> >(l);

    return 0;
}
