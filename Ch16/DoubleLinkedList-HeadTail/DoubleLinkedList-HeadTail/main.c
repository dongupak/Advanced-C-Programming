//
//  main.c
//  DoubleLinkedList-HeadTail
//
//  Created by DongGyu Park on 2016. 7. 7..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
typedef struct DListNode {
    item data;
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

// head 변수는 항상 첫 노드를 참조한다
DListNode *head = NULL;

// tail 변수는 항상 마지막 노드를 참조한다
DListNode *tail = NULL;

// 이중 연결리스트를 위한 노드를 만들고 이 노드의 주소를 반환함
DListNode *create_node(int n)
{
    DListNode *new_node = (DListNode *)malloc(sizeof(DListNode));
    
    new_node->data = n;
    new_node->prev = NULL;  // prev, next를 NULL로 초기화
    new_node->next = NULL;
    
    return new_node;
}

// 첫 노드부터 마지막 노드까지 이동하며 노드의 data 항목을 출력함
void display(){
    // head 노드에서 시작
    DListNode *current = head;
    
    // 리스트의 마지막까지 탐색
    printf("\n(");
    while(current != NULL){
        printf(" %d",current->data);
        current = current->next; // next link를 따라감
        if( current != NULL ) printf(",");
    }
    printf(" )");
}

// 마지막 노드부터 첫 노드까지 이동하며 노드의 data 항목을 출력함
void reverse_display(){
    // tail 노드에서부터 출발
    DListNode *current = tail;
    
    // 리스트의 시작까지 탐색
    printf("\n(");
    while(current != NULL){
        // data 항목을 출력
        printf(" %d", current->data);
        current = current ->prev;
        if( current != NULL ) printf(",");
    }
    
    printf(" )");
}

// data 값을 가진 노드를 연결 리스트의 첫 노드로 삽입
void insert_head(int data){
    // 새로운 노드 생성
    DListNode *new_node = create_node(data);
    
    // 연결리스트가 비어있으면
    if( head == NULL )
        head = tail = new_node;  // tail, head가 새노드를 참조
    else {
        head->prev = new_node; // 헤드의 선행노드를 업데이트
        // 새 노드의 next가 head 노드를 참조함
        new_node->next = head;
        // 새 노드를 head가 참조
        head = new_node;
    }
}

//  data 값을 가진 노드를 연결 리스트의 마지막 노드로 삽입
void insert_tail(int data){
    // 새로운 노드 생성
    DListNode *new_node = create_node(data);
    
    // 연결리스트가 비어있다면
    if( head == NULL )
        head = tail = new_node;    // tail, head가 새노드를 참조
    else {
        // 마지막 노드의 후행노드를 업데이트
        tail->next = new_node;
        // 새 노드의 prev가 tail 노드를 참조함
        new_node->prev = tail;
        // 새 노드를 tail이 참조
        tail = new_node;
    }
}

int main() {
    insert_head(100);
    insert_tail(200);
    insert_tail(300);
    insert_tail(400);
    insert_tail(500);
    insert_tail(600);
    
    printf("\n순방향출력 (처음부터 끝): ");
    display();
    
    printf("\n");
    printf("\n역방향출력 (끝부터 처음) : ");
    reverse_display();
    printf("\n\n");
    
    return 0;
}
