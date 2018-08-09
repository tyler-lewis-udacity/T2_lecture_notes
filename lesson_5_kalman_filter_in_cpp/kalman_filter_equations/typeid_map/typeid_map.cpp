#include <iostream>
#include <string>
#include <map>
//#include <typeinfo>
using namespace std;

template <typename T>
const char* get_type(T var);

int main()
{
    // // int x;
    // // string x_id = typeid(x).name();
    // // x_id = typeid(x).name();
    // int x = 5;

    // cout << get_type(x) << endl;





    return 0;
}


// Function definitions
template <typename T>
const char* get_type(T var)
{
    return typeid(var).name();
}




// #include <iostream>
// #include <typeinfo>

// #define PRINT_NAME(x) std::cout << #x << " - " << typeid(x).name() << '\n'

// int main()
// {
//     PRINT_NAME(char);
//     PRINT_NAME(signed char);
//     PRINT_NAME(unsigned char);
//     PRINT_NAME(short);
//     PRINT_NAME(unsigned short);
//     PRINT_NAME(int);
//     PRINT_NAME(unsigned int);
//     PRINT_NAME(long);
//     PRINT_NAME(unsigned long);
//     PRINT_NAME(float);
//     PRINT_NAME(double);
//     PRINT_NAME(long double);
//     PRINT_NAME(char*);
//     PRINT_NAME(const char*);
//     //...
// }
