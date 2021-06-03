#include <stdio.h>

typedef struct node {
    int val;
    struct node *next;
} node;

typedef struct list {
    node *head;
} list;

void print(list l){
    node *current = l.head;
    while(current) {
        printf("%d ", current->val);
        current = current->next;
    }
}

int main(){
    list l;
    node *n1, *n2;
    int i = 0, x;
    scanf("%d", &x);
    n1 = new node;
    n1->val = x;
    l.head = n1;
    while(i < 3){
        scanf("%d", &x);
        n2 = new node;
        n2->val = x;
        n1->next = n2;
        n1 = n2;
        i++;
    }
    n2->next = NULL;
    
    print(l);
}
