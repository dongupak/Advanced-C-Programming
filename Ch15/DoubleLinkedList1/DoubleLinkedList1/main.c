//
//  main.c
//  DoubleLinkedList1
//
//  Created by DongGyu Park on 2016. 6. 29..
//  CopyNext © 2016년 ProfPark. All Nexts reserved.
//

// 이중 연결리스트를 구현
// 헤더노드는 아이템이 없는 노드로 이 노드의 prev link가 마지막 노드를 가리키도록 함

#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct DListNode {
    item data;
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

// 이중 연결 리스트의 초기화, 헤드노드의 prev, next가 자기자신을 참조함
void init(DListNode *phead)
{
    phead->prev = phead;
    phead->next = phead;
}

// 이중 연결리스트의 data를 순방향으로 탐색하며 출력함
void display(DListNode *phead)
{
    DListNode *current = phead->next;
    
    // 순방향출력- next를 따라가며 출력함
    printf("순방향출력: (");
    while(current != phead) {
        printf(" %d",current->data);
        current = current->next;
        if( current != phead ) printf(",");
    }
    printf(" )\n");
}

// 이중 연결리스트의 data를 역방향으로 탐색하며 출력함
void reverse_display(DListNode *phead)
{
    DListNode *current = phead->prev;
    
    // 역방향출력- prev를 따라가며 출력함
    printf("역방향출력: (");
    while(current != phead) {
        printf(" %d",current->data);
        current = current->prev;
        if( current != phead ) printf(",");
    }
    printf(" )\n");
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

// 이중 연결 리스트의 노드를 출력
void detail_reverse_display(DListNode *phead)
{
    DListNode *current;
    
    printf("   |%15s |%16s  |%15p |  \n", "Prev Node", "current","Next Node");
    for (current = phead->prev; current != phead; current = current->prev) {
        printf("<--|%15p |%2d(%14p)|%15p |-->\n",current->prev,current->data,current,current->next);
    }
    printf("\n");
}

// new_node를 before 노드의 다음에 위치하도록 삽입한다.
void insert_node(DListNode *before, DListNode *new_node)
{
    new_node->prev = before;
    new_node->next = before->next;
    before->next->prev = new_node;
    before->next = new_node;
}

// 이중 연결리스트를 위한 노드를 만들고 이 노드의 주소를 반환함
DListNode *create_node(int n)
{
    DListNode *new_node = (DListNode *)malloc(sizeof(DListNode));
    
    new_node->data = n;
    new_node->prev = NULL;  // prev, next를 NULL로 초기화
    new_node->next = NULL;
    
    return new_node;
}

// 이중 연결 리스트 테스트 프로그램
int main()
{
    // 헤드노드는 포인터 변수가 아닌 일반변수로 만들어 둔다
    DListNode head_node;
    DListNode *p[10];
    int i;
    
    init(&head_node);       // 헤드노드를 초기화한다
    printf("head_node의 주소 = %14p\n\n", &head_node);
    for (i = 0; i<4; i++) { // 4개의 노드를 동적으로 생성함
        p[i] = create_node(i);
        // 헤드 노드의 다음에 새로 생성된 노드를 삽입
        insert_node(&head_node, p[i]);
        printf("p[%d] 노드를 이중연결리스트에 삽입한 결과\n", i);
        detail_display(&head_node);
        detail_reverse_display(&head_node);
    }
    printf("\n4개의 노드를 이중연결리스트에 삽입한 결과\n");
    detail_display(&head_node);
//
//    printf("\n4개의 노드를 역방향으로 출력한 결과\n");
//    detail_reverse_display(&head_node);
//    
//    printf("연결리스트 노드를 출력함 \n");
//    display(&head_node);
    
    return 0;
}
