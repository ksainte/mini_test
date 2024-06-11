#include <stdio.h>

int main() {
    char *str;
    
    str = "abc";
    printf("Value: %s\n", str); // Output: 42
    printf("Pointer points to address: %p\n", str + 2); // Address of value
    printf("Pointer points to address: %p\n", str + 1); // Address of value
    printf("%p\n", str); // Address of value
    return 0;
}

// The address stored in the pointer (which it points to).
// The address of the pointer variable itself.