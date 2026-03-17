#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct stack{
    E * array;
    int capacity;
    int top;
} * ArrayStack;

_Bool initStack(ArrayStack stack){
    stack->array = malloc(sizeof (E) * 10);
    if(!stack->array) return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}

_Bool pushStack(ArrayStack stack, E element){
    if(stack->top + 1 == stack->capacity){
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        E * newArray = realloc(stack->array, sizeof (E) * newCapacity);
        if(!newArray) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[++stack->top] = element;
    return 1;
}

E popStack(ArrayStack stack){
    return stack->array[stack->top--];
}

_Bool isEmpty(ArrayStack stack){
    return stack->top == -1;
}

void printStack(ArrayStack stack){
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d ", stack->array[i]);
    }
    putchar('\n');
}

int main() {
    struct stack stack;
    initStack(&stack);
    for (int i = 0; i < 21; ++i) {
        pushStack(&stack, i * 10);
    }
    printStack(&stack);
    putchar('\n');

    while(!isEmpty(&stack)){
        printf("%d ", popStack(&stack));
    }
    return 0;
}
