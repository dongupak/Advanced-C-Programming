//
//  main.c
//  LinkedListInsert2 - 수정 버전(이중 포인터사용으로 문제해결)
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

//void display_list(ListNode *head)
//{
//    ListNode *p = head;
//    printf("(");
//    while (p != NULL) {
//        printf(" %d", p->data);
//        p = p->link;
//        if( p != NULL )
//            printf(",");
//    }
//    printf(" )\n");
//}

// phead : 리스트의 헤드 노드의 포인터
// prev : 선행노드
// new_node : 삽입될 노드
void insert_node(ListNode **phead, ListNode *prev, ListNode *new_node)
{
    printf("before insert : new_node = %p\n", new_node);
    printf("before insert : phead = %p\n", *phead);
    
    if (prev == NULL) { // prev 가 NULL이면 첫번째 노드로 new_node 삽입
        new_node->link = *phead;
        *phead = new_node;
    }
    else {			 // prev 다음에 new_node를 삽입
        new_node->link = prev->link;
        prev->link = new_node;
    }
    
    printf("after insert: new_node = %p\n", new_node);
    printf("after insert: phead = %p\n", *phead);
}


int main()
{
    ListNode *head = NULL;
    ListNode *node;
    
    node = (ListNode *)malloc(sizeof(ListNode));
    node->data = 100;
    
    // head 노드에 node를 삽입한다
    insert_node(&head, NULL, node);
    
//    node = (ListNode *)malloc(sizeof(ListNode));
//    node->data = 200;
//    
//    // head 노드에 node를 삽입한다
//    insert_node(&head, NULL, node);
//    
//    node = (ListNode *)malloc(sizeof(ListNode));
//    node->data = 300;
//    
//    // head 노드에 node를 삽입한다
//    insert_node(&head, NULL, node);
    
    printf("node->data = %d\n", node->data);
    printf("node = %p\n", node);
    printf("head = %p\n", head);
    printf("head->data = %d\n", head->data);
    
    // 노드 삽입 후 결과 살펴보기
//    display_list(head);
    
    return 0;
}
