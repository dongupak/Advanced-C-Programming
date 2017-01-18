//
//  main.c
//  LinkedListInsert1 - Error 버전(단순 포인터사용시 문제점)
//
//  Created by DongGyu Park on 2016. 4. 30..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct ListNode {
    item data;
    struct ListNode *link;
} ListNode ;

// phead : 리스트의 헤드 노드의 포인터
// prev : 선행노드
// new_node : 삽입될 노드
void insert_node(ListNode *phead, ListNode *prev, ListNode *new_node)
{
    printf("before insert : new_node = %p\n", new_node);
    printf("before insert : phead = %p\n", phead);

    if (prev == NULL) { // prev가 NULL이면 첫번째 노드로 new_node 삽입
        new_node->link = phead;
        phead = new_node;
    }
    else {			 // prev 다음에 new_node를 삽입
        new_node->link = prev->link;
        prev->link = new_node;
    }
    
    printf("after insert: new_node = %p\n", new_node);
    printf("after insert: phead = %p\n", phead);
}

int main()
{
    ListNode *head = NULL;
    ListNode *node;
    
    node = (ListNode *)malloc(sizeof(ListNode));
    node->data = 100;
    
    // head 노드에 node를 삽입한다
    insert_node(head, NULL, node);
    
    printf("node->data = %d\n", node->data);
    printf("node = %p\n", node);
    printf("head = %p\n", head);
    printf("head->data = %d\n", head->data);
    
    return 0;
}
