#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char* data;
    int size;
    int capacity;
} DynamicArray;

typedef struct node{
    DynamicArray* data;
    struct node* next;
} node;


/*===================Dynamic Array functions===================*/
void initDA(DynamicArray *arr, int capacity){
    arr->data =  (char*)malloc(capacity * sizeof(char));
    arr->capacity = capacity;
    arr->size = 0;
}

void appendDA(DynamicArray *arr, char value){
    if (arr->size >= arr->capacity){
        arr->capacity *= 2;
        char* temp = (char*)realloc(arr->data, arr->capacity * sizeof(char));

        arr->data = temp;
    }
    arr->data[arr->size] = value;
    arr->size ++;
}

void deleteDA(DynamicArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
void printDA(DynamicArray* arr){
    for (int i = 0; i < arr->size; i++){
        putchar(arr->data[i]);
    }
}
/*=======================List functions=========================*/
void addToEndL(node **lst, DynamicArray *value){
    node *current = *lst;
    DynamicArray *newArray = (DynamicArray*)malloc(sizeof(DynamicArray));

    newArray->size = value->size;
    newArray->capacity = value->capacity;
    newArray->data = value->data;

    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = newArray;
    newNode->next = NULL;
    if (current == NULL){
        *lst = newNode;
        return;
    }
    else{
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteL(node *lst){
    node *current = lst;
    node *next;
    while (current != NULL){
        next = current->next;
        free(current->data->data);
        free(current->data);
        free(current);
        current = next;
    }
}

void printL(node *lst){
    node *current = lst;
    printf("[");
    printDA(current->data);
    while (current->next != NULL){
        current = current->next;
        printf(", ");
        printDA(current->data);
    }
    printf("]\n");
}

void deleteSameAsLast(node **lst){
    node *last = *lst;
    while(last->next != NULL)
        last = last->next;

    node *current = *lst;
    node *prev = NULL;
    while ((current->next != NULL) && ((*current->data->data) == (*last->data->data)))
    {
        *lst = current->next;
        free(current->data->data); 
        free(current->data); 
        free(current);
        current = *lst;
    }
    while(current->next != NULL){
        while((current->next != NULL) && ((*current->data->data) != (*last->data->data))){
            prev = current;
            current = current->next;
        }
        if (current->next == NULL) return;
        prev->next = current->next; 
        free(current->data->data); 
        free(current->data); 
        free(current);
        current = prev->next;
     }
}

int main(){
    char c;
    node *lst;
    lst = NULL;
    DynamicArray arr;
    c = getchar();
    while (c != '\n'){
        if (c != ' '){
            initDA(&arr, 1);
            while(c!='\n'&&c!=' '){
                appendDA(&arr, c);
                c = getchar();
            } 
            addToEndL(&lst, &arr);
        }
        else{
            c = getchar();        
        }
    }
    printL(lst);
    deleteSameAsLast(&lst);
    printL(lst);    
    deleteL(lst);
    return 0;
}
