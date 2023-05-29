#include <iostream>

// & = adress of
// * = value of pointer


int main(){
    int n = 5;
    std::cout << "n: " << n << std::endl;
    std::cout << "&n: " << &n << std::endl;

    int* ptr = &n;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;

    *ptr = 10;
    std::cout << "*ptr = 10: " << *ptr << std::endl;
    std::cout << "n: " << n << std::endl;

    int v;
    int* ptr2 = &v;
    *ptr2 = 7;
    std::cout << "v = " << v << std::endl;
    std::cout << "*ptr2 = " << *ptr2 << std::endl;
    return 0;
}