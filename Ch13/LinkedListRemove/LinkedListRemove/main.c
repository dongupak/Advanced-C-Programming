//
//  main.c
//  LinkedListRemove
//
//  Created by DongGyu Park on 2016. 5. 30..
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

// 연결리스트의 헤드노드를 삭제하는 함수로 헤드노드가 NULL이 아니면
// 헤드노드 다음 노드가 헤드노드가 된다
void removeFirst(ListNode **phead)
{
    if( *phead == NULL )
        return;
    else {
        ListNode *removedNode;
        removedNode = *phead;
        *phead = (*phead)->link;
        free(removedNode);
    }
}

void removeLast(ListNode **phead)
{
    ListNode *prev = (*phead);
    ListNode *next ;
    
    // NULL 연결리스트이면 제거할 노드가 없음
    if( prev == NULL )
        return;
    else if( prev->link == NULL) { // 단일노드이면 노드하나만 제거
        free( prev );
        *phead = NULL;
        return;
    }
    
    // 연결리스트에 2개 이상의 노드가 있을 경우
    while (prev != NULL) {
        next = prev->link;
        // next 노드 다음에 노드가 없을때 next 노드를 제거
        if( next->link == NULL)
        {
            prev->link = NULL;
            free(next);
            return;
        }
        else {  // 그렇지 않으면 다음 노드 탐색
            prev = next;
        }
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

// 노드를 동적으로 생성하는 프로그램
ListNode *create_node(item data, ListNode *link)
{
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = link;
    return(new_node);
}

int main()
{
    ListNode *head = NULL;
    insert_node(&head, NULL, create_node(100, NULL));
    insert_node(&head, NULL, create_node(200, NULL));
    insert_node(&head, NULL, create_node(300, NULL));
    printf("100, 200, 300 데이터를 가진 노드 삽입 후 결과 \n");
    display_list(head);
    
    removeLast(&head);
    printf("마지막 노드 삭제 후 \n");
    display_list(head);

    removeLast(&head);
    printf("마지막 노드 삭제 후 \n");
    display_list(head);
    
    return 0;
}