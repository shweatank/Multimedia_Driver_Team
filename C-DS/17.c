//Size of structure
#include <stdio.h>

struct MyStruct {
    int a;
    char b;
    float c;
};

int main() {
    struct MyStruct *ptr1 = (struct MyStruct *)0; 
    struct MyStruct *ptr2 = ptr1 + 1;            

    // Difference in addresses gives the size of the structure
    printf("Size of the structure: %ld bytes\n", (char *)ptr2 - (char *)ptr1);

    return 0;
}


