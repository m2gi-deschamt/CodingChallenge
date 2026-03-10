# Fun implementation

## Inspiration

I was listening a youtube video called "the C iceberg"

[![Watch the video](https://img.youtube.com/vi/63zGtiv89bA/maxresdefault.jpg)](https://www.youtube.com/watch?v=63zGtiv89bA)

## First exercice : implement Array object 1D

### Observation

- an array have a constant size
- should reserve a fixed memory size : NumberOfElement \* sizeof(int)
- \*(array+idx) <==> arr[idx] with idx [0...(NumberOfElement-1)]

## Second exercice : implement Vector object

### Observation

- a vector have a dynamic size
- it can be access by index
- push & pop, on the last element
- copy data in a bigger space if needed

### Interesting

a[b] == _(a + b) == _(b + a)

So if you want to get value, you can do :

- vector->data[i]
- \*(vector->data + i)
- i[vector->data]
