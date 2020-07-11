#include <iostream>
#include <string>
int main(){

    std::string str;
#ifdef IS_WINDOWS
    str = "Hello Windows";
#elif IS_MACOS
    str = "Hello macOS";
#elif IS_LINUX
    str = "Hello Linux";
#else
    str = "Hello Windows";
#endif

    std::cout<<"Hello "<<str<<std::endl;
    return 0;
}