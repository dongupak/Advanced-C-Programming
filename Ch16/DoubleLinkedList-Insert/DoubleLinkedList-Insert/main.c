//
//  main.c
//  DoubleLinkedList-Insert
//
//  Created by DongGyu Park on 2016. 7. 4..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct DListNode {
    item data;
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

// 이중 연결 리스트의 초기화, 헤드노드의 prev, rnext가 자기자신을 참조
void init(DListNode *phead)
{
    phead->prev = phead;
    phead->next = phead;
}

// 이중 연결 리스트의 노드를 출력
void detail_display(DListNode *phead)
{
    DListNode *current;
    
    printf("   |%15s |%16s  |%15p |  \n", "Prev Node", "current","Next Node");
    for (current = phead->next; current != phead; current = current->next) {
        printf("<--|%15p |%2d(%14p)|%15p |-->\n",current->prev,current->data,current,current->next);
    }
    printf("\n");
}

// new_node를 before 노드의 다음에 위치하도록 삽입한다.
void dinsert_node(DListNode *before, DListNode *new_node)
{
    new_node->prev = before;
    new_node->next = before->next;
    before->next->prev = new_node;
    before->next = new_node;
}

// 연결리스트의 제일 앞에 new_node를 삽입함
void insert_first(DListNode *phead, DListNode *new_node)
{
    new_node->prev = phead;
    new_node->next = phead->next;
    phead->next = new_node;
    new_node->next->prev = new_node;
}

// 연결리스트의 제일 뒤에 new_node를 삽입함
void insert_last(DListNode *phead, DListNode *new_node)
{
    new_node->prev = phead->prev;
    new_node->next = phead;
    phead->prev = new_node;
    new_node->prev->next = new_node;
}

// 이중 연결 리스트 테스트 프로그램
int main()
{
    DListNode head_node;
    DListNode *p[10];
    int i;
    
    init(&head_node);       // 헤드노드 초기화
    printf("head_node의 주소 = %14p\n\n", &head_node);
    for (i = 0; i<4; i++) { // 4개의 노드를 동적으로 생성함
        p[i] = (DListNode *)malloc(sizeof(DListNode));
        p[i]->data = i;
        // 연결 리스트의 마지막에 새로 생성된 노드를 삽입
        insert_first(&head_node, p[i]);
        printf("p[%d] 노드를 이중연결리스트에 삽입한 결과\n", i);
        detail_display(&head_node);
    }
    
    return 0;
}
