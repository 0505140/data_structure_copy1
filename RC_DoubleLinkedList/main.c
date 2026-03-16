#include <stdio.h>
#include <stdlib.h>
typedef int E;
typedef struct ListNode{
    E element;
    struct ListNode * prev;
    struct ListNode * next;
} * Node;

void initList(Node head){
    head->next = head->prev = NULL;
}

_Bool insertList(Node head, E element, int index){
    if(index < 1) return 0;
    while(--index){
        head = head->next;
        if(!head) return 0;
    }
    Node node = malloc(sizeof (struct ListNode));
    if(!node) return 0;
    node->element = element;
    // 这里要格外注意，判断head的下一个是否为空
    if(head->next){
        node->next = head->next;
        head->next->prev = node;
    }else{
       node->next = NULL;
    }
    head->next = node;
    node->prev = head;
    return 1;
}

// 头尾双向打印
void PRT(Node head){
    printf("从头打印的链表如下：\n");
    while(head->next){
        head = head->next;
        printf("%d ", head->element);
    }
    putchar('\n');
    printf("从尾打印的链表如下：\n");
    while(head->prev){
        printf("%d ", head->element);
        head = head->prev;
    }
    putchar('\n');
}

// 删除
_Bool deleteList(Node head, int index){
    if(index < 1) return 0;
    while (--index){
        head = head->next;
        if(!head || !head->next) return 0;
    }
    Node node = head->next;
    // 在链表的插入和删除中几乎都要判断index位置是不是空
    if(!node->next){
        head->next = NULL;
        free(node);
    }else{
        head->next = node->next;
        node->next->prev = head;
        free(node);
    }
    return 1;
}

int main() {
    struct ListNode head;
    initList(&head);
    // 依旧头结点不存放元素
    for (int i = 1; i < 11; ++i) {
        insertList(&head, i * 10, i);
    }
    PRT(&head);
    putchar('\n');
    deleteList(&head, 3);
    PRT(&head);
    return 0;
}
