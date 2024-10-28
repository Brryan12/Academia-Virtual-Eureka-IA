#include <iostream>
#if defined(_WIN64) || defined(_WIN32)
#define cls "cls"
#define pause "pause"
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define cls "clear"
#define pause "read -n1 -r -p \"Press any key to continue...\""
#endif

int main()
{
    std::cout << "Hello World!\n";
}