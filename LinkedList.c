#include <stdio.h>

typedef struct {
    int data;
    node* next;
} node;

node* head = NULL;
// 1. Insert at the end
void insertEnd(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
// 2. Insert at the beginning
void insertBeginning(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
// 3. Insert at a specific position
void insertAtPosition(int value, int position) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    
    if (position == 1) {
        insertBeginning(value);
        return;
    }
    
    node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}
// 4. Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    head = head->next;
    free(temp);
}

// 5. Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
// 6. Delete from a specific position
void deleteAtPosition(int position) {   
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 1) {
        deleteBeginning();
        return;
    }
    
    node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    
    node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
// 7. Display the list
void display() {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

