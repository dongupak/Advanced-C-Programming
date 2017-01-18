//
//  main.c
//  LinkedListRemove2
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


// 특정한 value 값을 가지는 노드를 연결리스트에서 삭제한다
void removeData(ListNode **phead, int value)
{
    ListNode *curr, *prev = NULL;
    
    curr = *phead;
    while( curr != NULL ) {
        if( curr->data == value ){
            // 시작 노드가 value값을 가지므로 head를 변경시킨다
            if( prev == NULL ) {
                *phead = curr->link;
            }
            else {
                prev->link = curr->link;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->link;
    }
}

void display_list(ListNode *head)
{
    ListNode *current = head;
    printf("(");
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->link;
        if( current != NULL )
            printf(",");
    }
    printf(" )\n");
}

int main()
{
    ListNode *head = NULL;
    ListNode *node1, *node2, *node3;
    
    node1 = (ListNode *)malloc(sizeof(ListNode));
    node1->data = 100;
    node1->link = NULL;
    node2 = (ListNode *)malloc(sizeof(ListNode));
    node2->data = 200;
    node2->link = NULL;
    node3 = (ListNode *)malloc(sizeof(ListNode));
    node3->data = 300;
    node3->link = NULL;
    
    insert_node(&head, NULL, node1);
    insert_node(&head, NULL, node2);
    insert_node(&head, NULL, node3);
    
    printf("100, 200, 300 데이터를 가진 노드 삽입 후 결과 \n");
    display_list(head);
    
    removeData(&head, 500);
    printf("500 노드 삭제 후 \n");
    display_list(head);
//    removeData(&head, 100);
//    printf("100 노드 삭제 후 \n");
//    display_list(head);
//    removeData(&head, 300);
//    printf("300 노드 삭제 후 \n");
//    display_list(head);
 
    return 0;
}