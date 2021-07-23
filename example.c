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

    darray(char *) test;
    darray_init(&test, 10);
    char *tmp = malloc(100);
    strcpy(tmp, "abc");
    int ret = darray_push_back(&test, &tmp);
    darray_push_back_val(&test, tmp);
    struct darray_header *header = DARRAY_HEADER(test);
    printf("cap: %li, size: %li\n", header->cap, darray_size(&test));
    printf("s: %li\n", sizeof(**(&test)));
    printf("s2: %i\n", ret);

    for(int i = 0;i < darray_size(&test);i++){
        printf("string: %s\n", test[i]);
    }

    darray_free(&test);


    darray(int) array;
    darray_init(&array, 0);
    array_print(array);

    int int_arr[] = {0,1,2,3,4,5};
    darray_push_back(&array, &int_arr[0]);
    darray_push_val(&array, 10, 0);
    darray_push_val(&array, 9, 0);
    array_print(array);
    int k = darray_size(&array);
    darray_push_val(&array, 5, k);
    darray_push_back_val(&array, 5);
    array_print(array);
    darray_pop_back(&array);
    array_print(array);

    darray_free(&array);

    darray(char) str;
    darray_init(&str,0);

    darray_append(&str, "test", strlen("test"));
    darray_push_back_val(&str, '1');
    darray_push_back(&str, "");

    printf("string: %s\n", str);

    darray_free(&str);
}
