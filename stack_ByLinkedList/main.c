#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct Stack{
    E element;
    struct Stack * next;
} * LStack;

void initStack(LStack stack){
    stack->next = NULL;
}

_Bool pushStack(LStack head, E element){
    LStack node = malloc(sizeof (struct Stack));
    if(!node) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

E popStack(LStack head){
    LStack tmp = head->next;
    E e = tmp->element;
    head->next = tmp->next;
    free(tmp);
    return e;
}

_Bool isEmpty(LStack head){
    return head->next == NULL;
}

void printStack(LStack head){
    head = head->next;
    while (head){
        printf("%d ", head->element);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Stack head;
    initStack(&head);
    for (int i = 0; i < 21; ++i) {
        pushStack(&head, i * 10);
    }
    printStack(&head);
    while (!isEmpty(&head))
        printf("%d ", popStack(&head));
    return 0;
}
