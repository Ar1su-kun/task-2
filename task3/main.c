#include "list.h"
#include "input.h"

int main(){
    list lst;
    buffer buf;
    initList(&lst);
    initBuffer(&buf);

    while(input(&lst)){
        printSize(&lst);
        printList(&lst);

        sortList(&lst);
    
        printf("\nSorted: \n");
        printList(&lst);

        clearList(&lst);
    }

    return 0;
}
