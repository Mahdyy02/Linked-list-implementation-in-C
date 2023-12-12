#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
}List;

typedef enum {
    LIST_EMPTY_ERROR,
}ListErrorCode;

void initialize(List* L){
    L->head = NULL;
}

Node* create_new_node(){
    Node* new_node = (Node*) malloc(sizeof(Node));
    return new_node;
}

void list_append(List* L, int value) {

    Node* new_node = create_new_node();
    new_node->value = value;
    new_node->next = NULL;

    if (L->head == NULL) {
        L->head = new_node;
        return;
    }

    Node* iter = L->head;
    while (iter->next != NULL) iter = iter->next;

    iter->next = new_node;
}

int list_pop(List* L) {
    if (L->head == NULL) return LIST_EMPTY_ERROR;

    int value;
    Node* iter = L->head;

    if (iter->next == NULL) {
        value = iter->value;
        free(iter);
        L->head = NULL;
        return value;
    }

    while (iter->next->next != NULL) iter = iter->next;

    value = iter->next->value;
    free(iter->next);
    iter->next = NULL;
    return value;

}

int list_len(List* L){

    if(L->head == NULL) return 0;

    unsigned int length = 0;
    Node* iter = L->head;
    while(iter != NULL){
        length++;
        iter = iter->next;
    }

    return length;
}

void destroy_list(List* L){
    while(L->head != NULL) list_pop(L);
}

int get_element_by_index(List* L, unsigned int index){

    if(index >= list_len(L)) {
        fprintf(stderr, "Error: Index out of range\n");
        exit(EXIT_FAILURE);
    }

    int item;
    Node *iter = L->head;
    for(int i = 0; i < index; i++) iter = iter->next;
    item = iter->value;

    return item;
}

void print_list(List* L){
    printf("[");
    Node *iter = L->head;
    while(iter != NULL){
        if(iter->next == NULL) printf("%d", iter->value);
        else printf("%d, ", iter->value);
        iter = iter->next;
    }
    printf("]\n");
}

void remove_element_by_index(List* L, unsigned int index){

    if(list_len(L) < index){
        printf("Element out of index.\n");
        return;
    }else if(index == list_len(L)-1){
        list_pop(L);
        return;
    }else if(index == 0){
        Node *Node_to_delete = L->head;
        L->head = L->head->next;
        free(Node_to_delete);
        return;
    }

    Node *iter = L->head;
    for(int i = 0; i < index - 1 && iter !=NULL; i++) iter = iter->next;
    Node *Node_to_delete = iter->next;
    iter->next = iter->next->next;
    free(Node_to_delete);

}

void delete_first_element(List* L){
    remove_element_by_index(L, 0);
}

int remove_element(List* L, unsigned int value){

    Node* iter = L->head;
    for(int i = 0; iter != NULL; i++){
        if(iter->value == value){
            remove_element_by_index(L, i);
            return i;
        }
        iter = iter->next;
    }
    return -1;
}

int main(){

    List L1;
    initialize(&L1);
    list_append(&L1, 1);
    list_append(&L1, 2);
    list_append(&L1, 3);
    list_append(&L1, 4);
    list_append(&L1, 5);
    list_append(&L1, 6);
    list_append(&L1, 7);
    list_append(&L1, 8);
    list_append(&L1, 9);
    // printf("%i\n", list_pop(&L1));

    remove_element_by_index(&L1, 0);
    print_list(&L1);
    remove_element_by_index(&L1, list_len(&L1)-1);
    print_list(&L1);
    remove_element_by_index(&L1, 1000);
    print_list(&L1);
    remove_element_by_index(&L1, 3);
    print_list(&L1);

    // print_list(&L1);
    // printf("%i\n", list_len(&L1));
    // printf("%i\n", get_element_by_index(&L1, 2));
    // printf("%i\n", get_element_by_index(&L1, 3));
    destroy_list(&L1);
    // print_list(&L1);

    return 0;
}