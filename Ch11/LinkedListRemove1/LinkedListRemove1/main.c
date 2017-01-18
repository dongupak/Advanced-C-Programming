//
//  main.c
//  LinkedListRemove1 - remove_node함수 추가
//
//  Created by DongGyu Park on 2016. 5. 4..
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
void insert_node(ListNode **phead, ListNode *prev, ListNode *new_node)
{
    if (prev == NULL) { // prev가 NULL이면 첫 번째 노드로 삽입
        new_node->link = *phead;
        *phead = new_node;
    }
    else {			 // prev 다음에 삽입
        new_node->link = prev->link;
        prev->link = new_node;
    }
}

// phead : 리스트의 헤드 노드를 참조하는 포인터 변수를 참조하는 변수
void remove_head(ListNode **phead)
{
    if( *phead != NULL ) {
        ListNode *tempHead ;    // 헤드노드를 임시로 참조하는 노드
        tempHead = *phead;
        *phead = (*phead)->link;    // 헤드노드를 헤드 노드 다음 노드로 변경
        free(tempHead);         // 원래 헤드노드를 삭제
    }
}

void display_list(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL) {
        printf(" %d ", current->data);
        current = current->link;
    }
    printf("\n");
}

int main()
{
    ListNode *head = NULL;
    ListNode *node1;
    ListNode *node2;
    
    node1 = (ListNode *)malloc(sizeof(ListNode));
    node1->data = 100;
    node1->link = NULL;
    node2 = (ListNode *)malloc(sizeof(ListNode));
    node2->data = 200;
    node2->link = NULL;
    
    insert_node(&head, NULL, node1);
    insert_node(&head, NULL, node2);
    printf("node1, node2 삽입 후 결과 \n");
    display_list(head);

    // 헤드노드를 삭제 함
    remove_head(&head);
    printf("헤드노드 삭제 후 \n");
    display_list(head);
    
    // 헤드노드를 삭제 함
    remove_head(&head);
    printf("헤드노드 삭제 후 \n");
    display_list(head);
    
    return 0;
}