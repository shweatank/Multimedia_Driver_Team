//Convert Endianess
#include <stdio.h>

unsigned int swap_endian(unsigned int num) {
    return ((num >> 24) & 0xFF) | // Move byte 3 to byte 0
           ((num >> 8) & 0xFF00) | // Move byte 2 to byte 1
           ((num << 8) & 0xFF0000) | // Move byte 1 to byte 2
           ((num << 24) & 0xFF000000); // Move byte 0 to byte 3
}

int main() {
    unsigned int num = 0x12345678;
    printf("Original: 0x%X\n", num);
    unsigned int converted = swap_endian(num);
    printf("Converted: 0x%X\n", converted);
    return 0;
}

