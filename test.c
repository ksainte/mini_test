#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Create nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Using another pointer to iterate
    struct Node* current; 
    current = head;//le pointeur current pointe desormais sur la meme struct que head

    
    printf("Address of head: %p\n", (void*)&head);//address of the head pointer
    printf("Address stored in head: %p\n", (void*)head);//address of the first node
    printf("Address of current: %p\n", (void*)&current);//address of the current pointer
    printf("Address stored in current: %p\n", (void*)current);//address of the first node too

    //the structure address targeted by (current) pointer changes with each iteration, at first it points to head, after it points to head->next etc.
    //this means that the current pointer will at some moment point to the NULL structure, while the head pointer will still point at the start, ie struct of head
    //RULE : given a pointer created struct Node* current, one can address the pointed node/structure by simply writing "current"
    while (current != NULL) {
        printf("Current node data: %d\n", current->data);//equivalent de char[][] ou **ptr pour un double pointeur sur char
        printf("While : Address stored in current: %p, it's address it still %p\n", (void*)current, (void*)&current);
        current = current->next;  // Move to the next node, we access the address stored in next's pointer which is a structure, when you want to access the underlying address pointed by
        //a pointer(next*), use the pointer name only(next)
    }
    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
