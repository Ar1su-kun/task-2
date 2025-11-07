#include "list.h"
#include "input.h"

void findMostPopular(list *lst){
    int c = 0;
    for (int i = 0; lst->data[i] != NULL; i++){
        
    
    }
}

int main(){
    list lst;
    buffer buf;
    initList(&lst);
    initBuffer(&buf);

    while(input(&lst)){
        printSize(&lst);
        printList(&lst);

        sortList(&lst);

        if(lst.data != NULL)
            printf("Sorted: \n");

        printList(&lst);

        clearList(&lst);
        printf("\n");
    }

    return 0;
}
