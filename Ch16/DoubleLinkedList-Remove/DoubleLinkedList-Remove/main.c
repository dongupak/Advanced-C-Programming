//
//  main.c
//  DoubleLinkedList-Remove
//
//  Created by DongGyu Park on 2016. 7. 4..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

//
//  main.c
//  DoubleLinkedList1
//
//  Created by DongGyu Park on 2016. 6. 29..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct DlistNode {
    item data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

// 이중 연결 리스트의 초기화, 헤드노드의 llink, rrlink가 자기자신을 참조
void init(DlistNode *phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void display(DlistNode *phead)
{
    DlistNode *p;
    printf("     | %14s |item| %14s |  \n", "Left Node", "Right Node");
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<--- | %14p | %2d | %14p | ---->\n", p->llink, p->data, p->rlink);
    }
    printf("\n");
}

// new_node를 before노드의 오른쪽에 위치하도록 삽입한다.
void dinsert_node(DlistNode *before, DlistNode *new_node)
{
    new_node->llink = before;
    new_node->rlink = before->rlink;
    before->rlink->llink = new_node;
    before->rlink = new_node;
}

// 노드 removed를 삭제한다.
void dremove_node(DlistNode *phead_node,
                  DlistNode *removed)
{
    if (removed == phead_node) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

// 이중 연결 리스트 테스트 프로그램
int main()
{
    DlistNode head_node;
    DlistNode *p[10];
    int i;
    
    init(&head_node);       // 헤드노드 초기화
    for (i = 0; i<4; i++) { // 5개의 노드를 동적으로 생성함
        p[i] = (DlistNode *)malloc(sizeof(DlistNode));
        p[i]->data = i;
        // 헤드 노드의 오른쪽에 새로 생성된 노드를 삽입
        dinsert_node(&head_node, p[i]);
    }
    printf("5개의 노드를 이중연결리스트에 삽입한 결과\n");
    display(&head_node);
    
    printf("1개의 노드를 이중연결리스트에서 삭제\n");
    dremove_node(&head_node, p[4]);
    display(&head_node);
    
    return 0;
}
