#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {
    int* data;
    int length;
    int capacity;
} Vector;

void append(Vector* vector, int value) {
    if(vector->length >= vector->capacity) {
        if(vector->capacity == 0) 
            vector->capacity +=4;
        else 
            vector->capacity *=2;
        vector->data = (int*) realloc(vector->data, vector->capacity * sizeof(*vector->data));
    };
    *(vector->data + vector->length) = value;
    vector->length += 1;
};

int main(int argc, char const *argv[]) {
    Vector vec = {0};
    for (size_t i = 0; i < 10; i++) {
        append(&vec,i);
    };

    for (size_t i = 0; i < 10; i++) {
        std::cout << " " << vec.data[i] << " ";
    };
}