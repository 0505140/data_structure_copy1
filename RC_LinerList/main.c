#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct List {
    E *arr;
    int capacity;
    int size;
} * List;

_Bool initList(List list){
    list->arr = malloc(sizeof (E) * 10);
    if(!list->arr) return 0;
    list->size = 0;
    list->capacity = 10;
    return 1;
}

_Bool insertList(List list, E element, int index){
    if(index > list->size + 1 || index < 1) return 0;
    if(list->capacity == list->size){
        int newCapacity = list->capacity + (list->capacity >> 1);
        E * newArr = realloc(list->arr, newCapacity * sizeof (E));
        if(!newArr) return 0;
        list->arr = newArr;
        list->capacity = newCapacity;
    }

    for (int i = list->size; i > index - 1 ; --i) {
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[index - 1] = element;
    list->size++;
    return 1;
}

_Bool deleteList(List list, int index){
    if(index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; ++i) {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
    return 1;
}

void sizeList(List list){
    printf("%d ", list->size);
    putchar('\n');
}

void printList(List list){
    for (int i = 0; i < list->size; ++i) {
        printf("%d ", list->arr[i]);
    }
    putchar('\n');
}

// 获取指定位置的元素
E * getElement(List list, int index){
    if(index < 1 || index > list->size) return NULL;
    return  &list->arr[index - 1];
}

int getLocation(List list, E element){
    for (int i = 0; i < list->size + 1; ++i) {
        if(list->arr[i] == element) return i + 1;
    }
    return -1;
}

_Bool isEmpty(List list){
    if(list->size == 0) return 1;
    else return 0;
}

int main() {
    struct List list;
    if(initList(&list)){
        for (int i = 1; i < 11; ++i) {
            insertList(&list, i * 10, i);
        }
    }
    printList(&list);

    deleteList(&list, 1);
    printList(&list);

    sizeList(&list);

    printf("%d ", isEmpty(&list));
    putchar('\n');

    printf("%d ", *getElement(&list, 1));
    putchar('\n');

    printf("%d ", getLocation(&list, 50));

    putchar('\n');
    return 0;
}
