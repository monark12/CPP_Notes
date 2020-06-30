#include <iostream>
#include <stdlib.h>

class MyClass
{

public:
    int _mymember;

    MyClass()
    {
        std::cout << "Constructor is called\n";
        _mymember = 20;
    }

    ~MyClass()
    {
        std::cout << "Destructor is called\n";
    }

    void *operator new[](size_t size)
    {
        std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
        void *p = malloc(size);

        return p;
    }

    void operator delete[](void *p)
    {
        std::cout << "delete: Memory is freed again " << std::endl;
        free(p);
    }
};

int main()
{
    MyClass *p = new MyClass[3]();
    std::cout << p[0]._mymember << ", " << p[1]._mymember << std::endl;
    delete[] p;
}