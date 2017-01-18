//
//  main.c
//  PolyAdd-List 
//
//  Created by DongGyu Park on 2016. 7. 12..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 다항식의 차수와 계수값을 저장하는 항 노드
typedef struct DListNode {
    int coef;       // 다항식 항의 계수부
    int expon;      // 다항식 항의 차수부
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

// 다항식 연결리스트의 머리와 꼬리 포인터 노드와 길이를 저장하는 구조체
typedef struct PList {
    DListNode *head;
    DListNode *tail;
} PList;

// 초기화 함수
void init(PList *poly)
{
    poly->head = poly->tail = NULL;
}

// 이중 연결리스트를 위한 노드를 만들고 이 노드의 주소를 반환함
DListNode *create_node(int co, int ex)
{
    DListNode *new_node = (DListNode *)malloc(sizeof(DListNode));
    
    new_node->coef = co;
    new_node->expon = ex;
    new_node->prev = NULL;  // prev, next를 NULL로 초기화
    new_node->next = NULL;
    
    return new_node;
}

// coef는 계수, expon는 차수를 각각 매개변수로 전달하여 항을 생성하여
// 생성된 항을 다항식의 마지막 노드로 삽입함
void insert_last(PList *poly, int coef, int expon)
{
    DListNode *new_node = create_node(coef, expon);
    
    if( poly->tail == NULL ){
        poly->head = poly->tail = new_node;
    }
    else {
        poly->tail->next = new_node;
        new_node->prev = poly->tail;
        poly->tail = new_node;
    }
}

// coef는 계수, expon는 차수를 각각 매개변수로 전달하여 항을 생성하여
// 생성된 항을 다항식의 첫 노드로 삽입함
void insert_head(PList *poly, int coef, int expon)
{
    DListNode *new_node = create_node(coef, expon);
    
    if( poly->head == NULL ){
        poly->head = poly->tail = new_node;
    }
    else {
        poly->head->prev = new_node;
        new_node->next = poly->head;
        poly->head = new_node;
    }
}

// 두 다항식 poly1, poly2를 더하여 poly3에 넣는다
void poly_add(PList *poly1, PList *poly2, PList *poly3 )
{
    DListNode *poly_term1 = poly1->head;
    DListNode *poly_term2 = poly2->head;
    int sum;
    
    while(poly_term1 && poly_term2){  // poly1, poly2의 항 노드가 empty가 아니면
        if( poly_term1->expon == poly_term2->expon ){  // poly1, poly2 항의 다항식의 차수가 같으면
            sum = poly_term1->coef + poly_term2-> coef;   // 계수값을 더해서 노드에 추가
            if( sum != 0 )
                insert_last(poly3, sum, poly_term1->expon);
            poly_term1 = poly_term1->next;
            poly_term2 = poly_term2->next;
        }
        else if( poly_term1->expon > poly_term2->expon ){               // poly1항 다항식의 차수가 클 경우
            insert_last(poly3, poly_term1->coef, poly_term1->expon);
            poly_term1 = poly_term1->next;
        }
        else {   // poly2 항 다항식의 차수가 클 경우
            insert_last(poly3, poly_term2->coef, poly_term2->expon);
            poly_term2=poly_term2->next;
        }
    }
    
    // term1, term2중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두
    // 결과 다항식(poly_term3)으로 복사
    for( ; poly_term1 != NULL; poly_term1=poly_term1->next)
        insert_last(poly3, poly_term1->coef, poly_term1->expon);
    for( ; poly_term2 != NULL; poly_term2=poly_term2->next)
        insert_last(poly3, poly_term2->coef, poly_term2->expon);
}

// poly_nomial 다항식 출력함수
void poly_print(PList *poly)
{
    DListNode *current = poly->head;
    
    // 3x^3 형식으로 출력함
    for(;current != NULL ;current=current->next){
        if( current->expon != 0)
            printf("%dx^%d + ", current->coef, current->expon);
        else
            printf("%d ", current->coef);
    }
    printf("\n");
}

// 다항식의 첫 노드를 삭제하는 함수
void delete_head(PList *poly)
{
    // 첫 노드를 참조하는 링크를 임시로 저장
    DListNode *temp_node = poly->head;
    
    // 빈 리스트일 경우 - 아무것도 하지 않음
    if( poly->head == NULL )
        return;
    else if(poly->head->next == NULL)  // 노드가 하나뿐일 경우
        poly->tail = NULL;
    else
        poly->head->next->prev = NULL;
    
    poly->head = poly->head->next;
    free(temp_node);
}

// 다항식의 마지막 노드를 삭제하는 함수
void delete_tail(PList *poly)
{
    // 마지막 노드를 참조하는 링크를 임시로 저장
    DListNode *temp_node = poly->tail;
    
    // 빈 리스트일 경우 - 아무것도 안함
    if ( poly->tail == NULL )
        return;
    else if(poly->head->next == NULL)  // 노드가 하나뿐일 경우
        poly->head = NULL;
    else
        poly->tail->prev->next = NULL;
    
    poly->tail = poly->tail->prev;
    free(temp_node);
}

// 다항식 p1, p2, p3를 만들어서 p3 = p1 + p2 를 구함
int main() {
    PList p1, p2, p3;
    
    init(&p1);
    init(&p2);
    init(&p3);
    
    // 다항식 1을 생성
    insert_last(&p1, 3,12); // 3x^12
    insert_last(&p1, 2,8);  // 2x^8
    insert_last(&p1, 1,0);  // 1
    
    // 다항식 2를 생성
    insert_last(&p2, 8,12); // 8x^12
    insert_last(&p2, -3,10);// -3x^10
    insert_last(&p2, 10,6); // 10x^6
    
    // 다항식 3 = 다항식 1 + 다항식 2
    poly_add(&p1, &p2, &p3);
    printf("다항식 1 = ");
    poly_print(&p1);
    printf("다항식 2 = ");
    poly_print(&p2);
    printf("다항식 1 + 다항식 2 = ");
    poly_print(&p3);
    return 0;
}
