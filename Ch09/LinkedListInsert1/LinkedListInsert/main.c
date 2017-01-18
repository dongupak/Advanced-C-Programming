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

// phead : 리스트의 헤드 노드를 가리키는 포인터 변수의 포인터 변수
// new_node : 삽입될 노드를 참조하는 포인터
void insert_node(ListNode **phead, ListNode *new_node)
{
    new_node->link = *phead;    // 새로 삽입될 노드의 링크가 헤드노드를 참조
    *phead = new_node;          // new_node가 새 헤드노드가 된다
}

int main()
{
    ListNode *head = NULL;
    ListNode *node;
    
    // 노드를 만들고 노드의 data 필드에 100을 넣는다
    node = (ListNode *)malloc(sizeof(ListNode));
    node->data = 100;
    
    // node를 연결리스트에 삽입한다
    insert_node(&head, node);
    printf("node->data = %d\n", node->data);
    printf("head->data = %d\n", head->data);
    
    node = (ListNode *)malloc(sizeof(ListNode));
    node->data = 200;
    insert_node(&head, node);
    printf("node->data = %d\n", node->data);
    printf("head->data = %d\n", head->data);
    printf("head->link->data = %d\n", head->link->data);

    return 0;
}
