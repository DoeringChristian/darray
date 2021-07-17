# darray
Generic dynamic array in C.

## Summary
Darray is a generic array written in C for C. It is compatible with C89/C90 and upwards as well as C++ without using "external C".
Similar to an allocator Darray handles the size and capacity management of the dynamic array in a header before the data.
Elements of Darray can be accessed using the builtin [] operator of C. 

## Rationale
There are already many libraries that provide some sort of generic dynamic array for C. But unfortunately they either rely on function like macros alone or they are not easy to use (for example: [c-vector](https://github.com/eteran/c-vector)).
My dynamic array implementation tries to mitigate these problems. All operations are handled in functions and only the casts from and to void * are handled using macros.
Darray uses the fact that one can get the size of an element from a c-style array with sizeof. This is used in the macros to supply the functions with the correct size of an element.
The "\_darray\_insert" and "\_darray\_remove" functions of Darray are as generic as possible and can be used for inserting and removing a number of bytes into an array with "struct darray\_header" prepending it. 

## Structure of a Darray

| size               | cap                    | data                                                                                         |
|--------------------|------------------------|----------------------------------------------------------------------------------------------|
| Size fo the array. | Capacity of the array. | Data stored in the array. This is the address where the pointer of the array is pointing to. |

## Funktions:

|                   | Functions that handle single elements      | Functions that handle arrays of elements            |
|-------------------|--------------------------------------------|-----------------------------------------------------|
| Insert at index   | darray\_push(\_arr\_p, \_elem\_p, \_index) | darray\_insert(\_arr\_p, \_elem\_p, \_num, \_index) |
| Insert at the end | darray\_push\_back(\_arr\_p, \_elem\_p)    | darray\_append(\_arr\_p, \_elem\_p, \_num)          |
| Remove at index   | darray_pop(\_arr\_p, \_elem\_p, \_index)   | darray_remove(\_arr\_p, \_num, \_index)             |
| Remove at the end | darray_pop_back(\_arr\_p)                  | ---                                                 |



