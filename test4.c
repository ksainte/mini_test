#include <stdio.h>

int main() {
    int value = 42;
    // int *p = &value;
    int *p; 
    
    p = &value;

    printf("Value: %d\n", value); // Output: 42
    printf("Pointer p points to address: %p\n", (void*)p); // Address of value
    printf("%p\n", &value); // Address of value
    printf("Value pointed by p: %d\n", *p); // Output: 42
    printf("Address of pointer p: %p\n", (void*)&p); // Address of pointer variable p

    return 0;
}

// The address stored in the pointer (which it points to).
// The address of the pointer variable itself.