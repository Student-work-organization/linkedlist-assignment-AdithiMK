#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
void insert_at_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void delete_from_the_beginning() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void delete_the_end_node() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}
void delete_node_with_givenData(int data) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    if(head->data == data) {
        head = head->next;
        free(temp);
        return;
    }

    while(temp->next != NULL) {
        if(temp->next->data == data) {
            struct Node* del = temp->next;
            temp->next = del->next;
            free(del);
            return;
        }
        temp = temp->next;
    }

    printf("Data not found\n");
}
void traverse() {
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    printf("Original List:\n");
    traverse();

    delete_from_the_beginning();
    printf("after deleting from beginning:\n");
    traverse();

    delete_the_end_node();
    printf("after deleting from end:\n");
    traverse();

    delete_node_with_givenData(20);
    printf("after deleting node with value 20:\n");
    traverse();

    return 0;
}
