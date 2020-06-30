#include <iostream>

int print(){
    int k = 20;
    std::cout << "k: " << &k << std::endl;
    return print();
}

int main()
{
    int m = 30;
    std::cout << "m: " << &m << std::endl;
    print();
    
    return 0;
}