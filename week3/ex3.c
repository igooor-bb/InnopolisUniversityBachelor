#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void print_list(struct Node* head) {
    /*
    Function to print the linked list.
    */
    struct Node* current = head;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

struct Node* insert_node(struct Node* head, int value, int index) {
    /*
    Function to insert a node to the linked list.
    */
    struct Node* node;
    node = malloc(sizeof *node);
    
    node->value = value;

    struct Node** temp = &head;
    for (int i = 0; i < index && *temp != NULL; i += 1) {
        temp = &(*temp)->next;
    }

    node->next = *temp;
    *temp = node;
    return head;
}

struct Node* delete_node(struct Node* head, int index) {
    /*
    Function to delete a node from the linked list.
    */
    struct Node** curr = &head;
    struct Node** prev = NULL;

    if (*curr != NULL && index == 0) { 
        head = (*curr)->next;
        free(*curr);
        return head; 
    }

    int i = 0;
    while (*curr != NULL && i < index) { 
        prev = curr; 
        curr = &(*curr)->next;
    } 
 
    if (*curr == NULL) return head; 
  
    (*prev)->next = (*curr)->next;
  
    free(*curr);
    return head;
}

int main() {
    struct Node *head = NULL;
    head = insert_node(head, 1, 0);
    head = insert_node(head, 5, 1);
    head = insert_node(head, 0, 0);
    print_list(head); // Prints 0 1 5

    head = delete_node(head, 0);
    head = delete_node(head, 0);
    print_list(head); // Prints 5
    
    return 0;
}