# darray
Generic dynamic array in C.

## Summary
darray is a generic array written in C for C. It is compatible with C89/C90 and upwards as well as C++ without using "external C".
Similar to an allocator Darray handles the size and capacity management of the dynamic array in a header before the data.
Elements of darray can be accessed using the builtin [] operator in C.
All macros are type save in the sense that the compiler will emit a warning when inserting the wrong type.


## Rationale
There already are many libraries that provide some sort of generic dynamic array for C. But unfortunately they either rely on function like macros alone or they are not easy to use (for example: [c-vector](https://github.com/eteran/c-vector)).
My dynamic array implementation tries to mitigate these problems. All operations are handled in functions and only the casts from and to void * are handled using macros.
darray uses the fact that one can get the size of an element from a c-style array with sizeof. This is used in the macros to supply the functions with the correct size of an element.
The "\_darray\_insert" and "\_darray\_remove" functions of darray are as generic as possible and can be used for inserting and removing a number of bytes into an array with "struct darray\_header" prepending it. 

## Structure of a darray

| darray(\_type) |
|----------------|
    |
    +------------------------------------------|
                                               v
| size               | cap                    | data                                                                                         |
|--------------------|------------------------|----------------------------------------------------------------------------------------------|
| Size fo the array. | Capacity of the array. | Data stored in the array. This is the address where the pointer of the array is pointing to. |

## Funktions:

|                         | Functions that handle single elements (by value) | Functions that handle arrays of elements            |
|-------------------------|--------------------------------------------------|-----------------------------------------------------|
| Insert at index         | darray\_push(\_arr\_p, \_elem, \_index)          | darray\_insert(\_arr\_p, \_elem\_p, \_num, \_index) |
| Insert at the end       | darray\_push\_back(\_arr\_p, \_elem)             | darray\_append(\_arr\_p, \_elem\_p, \_num)          |
| Insert at the beginning | darray\_push\_front(\_arr\_p, \_elem)            | darray\_prepend(\_arr\_p, \_elem\_p, \_num)         |
| Remove at index         | darray\_pop(\_arr\_p, \_index)                   | darray\_remove(\_arr\_p, \_num, \_index)            |
| Remove at the end       | darray\_pop\_back(\_arr\_p)                      | ---                                                 |

darray\_size(\_arr\_p) returns the size in bytes whereas darray\_len(\_arr\_p) returns the length in number of elements.

darray\_free(\_arr\_p) frees the array and sets it to NULL.



