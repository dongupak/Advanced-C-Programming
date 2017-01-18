//
//  main.c
//  DoubleLinkedList-Simple
//
//  Created by DongGyu Park on 2016. 7. 7..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

// 단순한 이중 연결리스트의 구현 - 비교적 단순한 형태로 구현함
// tail 노드를 가리키는 별도의 포인터 변수가 없음

#include<stdio.h>
#include<stdlib.h>

typedef int item;
typedef struct DListNode  {
    item data;
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

// 이중 연결리스트를 위한 노드를 만들고 이 노드의 주소를 반환함
DListNode *create_node(int n)
{
    DListNode *new_node = (DListNode *)malloc(sizeof(DListNode));
    
    new_node->data = n;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    return new_node;
}

// 노드를 이중 연결리스트의 헤더에 삽입하는 함수
void insert_head(DListNode **phead, int n)
{
    DListNode *new_node = create_node(n);
    
    // 헤드노드를 가리키는 포인터 변수가 참조하는 객체가 없이 NULL이면
    // 새 노드를 참조하도록 한다
    if( *phead == NULL) {
        *phead = new_node;
        return;
    }
    (*phead)->prev = new_node;
    new_node->next = *phead;
    *phead = new_node;
}

// 노드를 이중 연결리스트의 꼬리에 삽입하는 함수
void insert_tail(DListNode **phead, int n)
{
    DListNode *current = *phead;
    DListNode *new_node = create_node(n);
    
    if(*phead == NULL) {
        *phead = new_node;
        return;
    }
    while(current->next != NULL)
        current = current->next; // 마지막 노드까지 이동
    
    // 마지막 노드의 다음 노드에 삽입함
    current->next = new_node;
    new_node->prev = current;
}

// 이중 연결리스트의 data를 순방향으로 탐색하며 출력함
void display(DListNode *head)
{
    DListNode *current = head;
    printf("순방향출력: ");
    while(current != NULL) {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

// 이중 연결리스트의 data를 역방향으로 탐색하며 출력함
void reverse_display(DListNode *head)
{
    DListNode *current = head;
    
    if(current == NULL) return; // 빈 리스트일 경우 중지
    // 마지막 노드까지 따라가서
    while(current->next != NULL) {
        current = current->next;
    }
    // 역방향출력- prev를 따라가며 출력함
    printf("역방향출력: ");
    while(current != NULL) {
        printf("%d ",current->data);
        current = current->prev;
    }
    printf("\n");
}

int main()
{
    // 헤드노드를 가리키는 포인터 변수. NULL로 초기화
    DListNode *head = NULL;
    
    // 삽입과 출력 함수
    insert_head(&head,200);
    display(head);
    insert_tail(&head,300);
    display(head);
    insert_tail(&head,400);
    display(head);
    insert_tail(&head,500);
    display(head);
    insert_head(&head,100);
    display(head);
    reverse_display(head);
    
    return 0;
}
