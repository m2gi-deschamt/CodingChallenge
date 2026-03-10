/*
My mind... 
- Cantor pairing function
- bit packing, looks interesting  

The idea is to implement array object to understand better prog
My first ideas;
- an array have a constant size
- should reserve a fixed memory size : NumberOfElement * sizeof(int)
- *(array+idx) <==> arr[idx] with idx [0...(NumberOfElement-1)] 
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int* arr;
    arr = new int[5]{12, 2, 3, 4, 5};
    int idx0 = *arr;
    int idx2 = *(arr+2); // *(arr+2) vs *arr+2

    int size = 5 * sizeof(int);
    cout << "block size reserved : " << size << "\n";
    cout << "index 0 = " << idx0 << "\n";
    cout << "index 2 = " << idx2 << "\n";
    cout << "size of int* = " << sizeof(int*) << "\n";
    cout << "size of int = " << sizeof(int) << "\n";
    return 0;
}