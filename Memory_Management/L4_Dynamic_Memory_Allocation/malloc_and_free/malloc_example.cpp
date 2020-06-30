#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>

int main() 
{ 
    int *p = (int*)malloc(sizeof(int)+sizeof(char));
    return 0; 
}