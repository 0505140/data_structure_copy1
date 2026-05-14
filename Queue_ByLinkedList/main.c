#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct LNode{
    E element;
    struct LNode * next;
} * Node;

// 通过两个指针维护一个链表，这个链表的出入结构就是队列的出入结构
typedef struct Queue{
    Node front, rear;
} * Lqueue;

_Bool initLint(Lqueue queue){
    Node node = malloc(sizeof (struct LNode));
    if(!node) return 0;
    queue->rear = queue->front = node;
    return 1;
}

_Bool offerQueue(Lqueue queue, E element){
    Node node = malloc(sizeof(struct LNode));
    if(!node) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    node->next = NULL;
    return 1;
}

_Bool isEmpty(Lqueue queue){
    return queue->rear == queue->front;
}

E pollQueue(Lqueue queue){
    Node tmp = queue->front->next;
    E e = tmp->element;
    queue->front->next = tmp->next;
    if(queue->rear == tmp){
        queue->rear = queue->front;
    }
    free(tmp);
    return e;
}

void printQueue(Lqueue queue){
    Node node = queue->front->next;
    while(node){
        printf("%d ", node->element);
        node = node->next;
    }
    printf("\n");
}



int main() {
    struct Queue queue;
    initLint(&queue);
    for (int i = 0; i < 11; ++i) {
        offerQueue(&queue, i * 10);
    }
    printQueue(&queue);
    while(!isEmpty(&queue)){
        printf("%d ", pollQueue(&queue));
    }
    return 0;
}
