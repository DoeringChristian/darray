#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "darray.h"

void array_print(darray(int) arr){
    struct darray_header *header = DARRAY_HEADER(arr);
    printf("cap: %li, size: %li\n", header->cap, header->size);
    for(int i = 0;i < darray_size(&arr);i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
}

int main(){
    darray(int) array;
    darray_init(&array, 0);
    array_print(array);

    int int_arr[] = {0,1,2,3,4,5};
    darray_push_back(&array, &int_arr[0]);
    array_print(array);
    darray_pop_back(&array);
    array_print(array);

    darray_free(&array);
}
