#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int val;
} node;

typedef struct LinkedList {
    node *head;
} linked_list;

void insert_node(linked_list *list, int value) {
    node *new = malloc(sizeof(node));
    new->next = NULL;
    new->val = value;

    node *temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

void delete_node(linked_list *list, int value) {
    node *temp = list->head;

    while (temp->next != NULL && temp->next->val != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Error! No such element");
        exit(1);
    } else {
        node *temp2 = temp->next->next;
        free(temp->next);
        temp->next = temp2;
    }
}

void print_list(linked_list *list) {
    node *temp = list->head;
    char flag = 0;
    printf("{");
    while (temp->next != NULL) {
        temp = temp->next;
        if (flag == 0) {
            printf("%d", temp->val);
        } else {
            printf(", %d", temp->val);
        }
        flag = 1;
    }
    printf("}\n");
}

int main() {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = malloc(sizeof(node));
    list->head->next = NULL;
    //initialization of list

    print_list(list);
    insert_node(list, 1);
    insert_node(list, 2);
    insert_node(list, 3);
    print_list(list);

    delete_node(list, 2);
    print_list(list);
}
