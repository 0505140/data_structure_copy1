#include <stdio.h>
#include <stdlib.h>
typedef int E;

typedef struct LinkedNode{
    E element;
    struct LinkedNode * next;
} * Node;

// 初始化
void initList(Node node){
    node->next = NULL;
}

// 插入
_Bool insertList(Node head, E element, int index){
    if(index < 1) return 0;
    while(--index){
        head = head->next;
        if(!head) return 0;
    }
    Node node = malloc(sizeof (struct LinkedNode));
    if(node == NULL) return 0;
    node->next = head->next;
    head->next = node;
    node->element = element;
    return 1;
}

//打印结点
void printList(Node head){
    while (head->next){
        head = head->next;
        printf("%d->", head->element);
    }
    putchar('\n');
}

// 删除
_Bool deleteNode(Node head, int index){
    if(index < 1) return 0;
    while (--index){
        head = head->next;
        if(!head || !head->next) return 0;
    }
    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return 1;
}

// 获取对应元素的位置
int getLocation(Node head, E element){
    int i = 0;
    while(head->next){
        if(head->element == element){
            return i;
        }
        i++;
        head = head->next;
    }
    return -1;
}

// 获取对应位置的元素
E * getElement(Node head, int index){
    if(index < 1) return NULL;
    while(--index){
        head = head->next;
        if(head == NULL) return NULL;
    }
    return &head->next->element;
}

int sizeList(Node head){
    int i = 0;
    if(head->next == NULL) return i;
    while(head->next){
        i++;
        head = head->next;
    }
    return i;
}

int main() {
    struct LinkedNode head;
    initList(&head);
    for (int i = 1; i < 11; ++i) {
        insertList(&head, i * 10, i);
    }
    printList(&head);

    deleteNode(&head, 3);
    printList(&head);

    printf("%d \n", getLocation(&head, 90));

    printf("%d \n", *getElement(&head, 3));

    printf("%d \n", sizeList(&head));

    return 0;
}
