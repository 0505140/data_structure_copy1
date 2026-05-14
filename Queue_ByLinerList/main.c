#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct Queue{
    E * array;
    int capacity;
    int front, rear;
} * ArrayQueue;

_Bool initQueue(ArrayQueue queue){
    queue->array = malloc(sizeof(E) * 10);
    if(!queue->array) return 0;
    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return 1;
}

_Bool offerQueue(ArrayQueue queue, E element){
    int pos = (queue->rear + 1) % queue->capacity;
    if(pos == queue->front) return 0;
    queue->rear = pos;
    queue->array[queue->rear] = element;
    return 1;
}

int pollQueue(ArrayQueue queue){
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

_Bool isEmpty(ArrayQueue queue){
    return queue->front == queue->rear;
}

void printQueue(ArrayQueue queue){
    int i = queue->front;
    do{
        i = (i + 1) % queue->capacity;
        printf("%d ", queue->array[i]);
    } while (i != queue->rear);
    putchar('\n');
}


int main() {
    struct Queue queue;
    initQueue(&queue);
    for (int i = 1; i < 11; ++i) {
        offerQueue(&queue, i * 10);
    }
    printQueue(&queue);
    while(!isEmpty(&queue)){
        printf("%d ", pollQueue(&queue));
    }
    putchar('\n');
    return 0;
}


