#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
} tree;

void insertToTree(tree** root, int key){ 
    tree *newTree = (tree*)malloc(sizeof(tree));
    newTree->data = key;
    newTree->right = NULL;
    newTree->left = NULL;

    if (*root == NULL){
        *root = newTree;
    }
    else{
        tree *tmp = *root;
        while(true){
            if(tmp->data > key){
                if (tmp->left != NULL){
                    tmp = tmp->left;
                }
                else{
                    tmp->left = newTree;
                    break;
                }
            }
            else if(tmp->data < key){
                if (tmp->right != NULL){
                    tmp = tmp->right;
                }
                else{
                    tmp->right = newTree;
                    break;
                }
            }
            else{
                fprintf(stderr, "Error: this value %d already exists\n", key);
                free(newTree);
                break;
            }
        }
    }
}

tree* prevMinInTree(tree* root){
    if (root->left->left == NULL) return root;
    else return prevMinInTree(root->left);
}

void deleteFromTree(tree** root, int key){
    if (*root != NULL){
        tree *tmp = *root;
        tree *prev = tmp;
        while(true){
            if(tmp == NULL){
                fprintf(stderr, "Error: there isn't %d in tree\n", key);
                return;
            }
            else if(tmp->data > key){
                prev = tmp;
                tmp = tmp->left;
            }
            else if(tmp->data < key){
                prev = tmp;
                tmp = tmp->right;
            }
            else
                break;
        }

        if (tmp->left == NULL && tmp->right == NULL){
            free(tmp);
            if (prev->left == tmp)
                prev->left = NULL;
            else
                prev->right = NULL;

         }
        else if (tmp->left == NULL && tmp->right != NULL){
            tmp->data = tmp->right->data;
            free(tmp->right);
            tmp->right = NULL;
        }
        else if (tmp->left != NULL && tmp->right == NULL){
            tmp->data = tmp->left->data;
            free(tmp->left);
            tmp->left = NULL;
        }
        else{
            if (tmp->right->left == NULL){
                tmp->data = tmp->right->data;
                tree *tmp2 = (tmp->right->right); 
                free(tmp->right);
                tmp->right = tmp2;
            }
            else{
                tree *tmp2 = prevMinInTree(tmp->right);
                tmp->data = tmp2->left->data;
                free(tmp2->left);
                tmp2->left = NULL;
            }
        }
    }
}

void printTree(tree* root){
    if(root == NULL) return;
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

void freeTree(tree* root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int searchInTree(tree* root, int key){
    if(root == NULL) return -1;
    if(root->data == key) return key;
    return (key < root->data)?searchInTree(root->left, key): searchInTree(root->right, key);
}

int main(){
    tree *bst = NULL;
    char c;
    int value;
    while((c = getchar()) != EOF){
        switch (c){
            case '+':
                scanf("%d", &value); 
                insertToTree(&bst, value);
                getchar();
                break;
            case '-':
                scanf("%d", &value);  
                deleteFromTree(&bst, value);
                getchar();
                break;
            case '?':
                scanf("%d", &value);
                getchar();
                printf("%d\n", value); 
                printf((searchInTree(bst, value) == -1)?"no\n":"yes\n");
                break;
            case 'p':
                printTree(bst);
                printf("\n");
                getchar();
                break;
            default:
                fprintf(stderr, "Error: invalid input\n");
                break;
        }
    }
    freeTree(bst);
    
    return 0;
}
