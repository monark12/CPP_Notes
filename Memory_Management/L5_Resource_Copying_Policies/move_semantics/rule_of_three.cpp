#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
public:
    int _size;
    int *_data;

    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    
    MyMovableClass(const MyMovableClass &source){
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    
    MyMovableClass &operator=(const MyMovableClass &source){
        
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this <<std::endl;
        if (this==&source)
            return *this;
        
        delete[] _data;
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        
        return *this;
    }
};

MyMovableClass createObject(int size){
    MyMovableClass obj(size);
    return obj;
}


int main(){
    MyMovableClass obj1(10);
    //call to copy constructor
//     MyMovableClass obj2(obj1);
//     MyMovableClass obj3 = obj1;
        
    MyMovableClass obj4 = createObject(10);
    std::cout << obj4._size << std::endl;
    return 0;
}