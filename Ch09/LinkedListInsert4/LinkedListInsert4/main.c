//
//  main.c
//  LinkedListInsert
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
void insert_node(ListNode **phead, ListNode *prev, ListNode *new_node)
{
    if (prev == NULL) { // prev가 NULL이면 첫번째 노드로 new_node 삽입
        new_node->link = *phead;
        *phead = new_node;
    }
    else {			 // prev 다음에 new_node를 삽입
        new_node->link = prev->link;
        prev->link = new_node;
    }
}

int main()
{
    ListNode *head = NULL, *prev_node = NULL;
    ListNode *node, *current_node;
    
    // 5개의 노드를 생성하여 data 값에 0..4를 넣는다
    for(int i=0; i<5; i++)
    {
        node = (ListNode *)malloc(sizeof(ListNode));
        node->data = i;
        insert_node(&head, prev_node, node);
        prev_node = node;
    }
    
    current_node = head ;
    while (current_node != NULL){
        printf("current_node->data = %d\n", current_node->data);
        current_node = current_node->link;
    }
    
    return 0;
}
