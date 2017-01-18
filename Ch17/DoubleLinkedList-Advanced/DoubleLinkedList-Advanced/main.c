//
//  main.c
//  DoubleLinkedList-Advanced
//
//  Created by DongGyu Park on 2016. 7. 10..
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

// 연결리스트가 empty인가 검사하는 함수
bool isEmpty()
{
    return head == NULL;
}

// 연결리스트의 길이를 구하는 함수
int length()
{
    int length = 0;     // 초기화
    DListNode *current;
    
    for(current = head; current != NULL; current = current->next){
        length++;
    }
    
    return length;
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

// 첫 노드부터 마지막 노드까지 이동하며 노드의 data 항목을 출력함
void display(){
    // head 노드에서 시작
    DListNode *current = head;
    
    // 리스트의 마지막까지 탐색
    printf("\n(");
    while(current != NULL){
        printf(" %d",current->data);
        current = current->next; // right link
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

// data 값을 가진 노드를 첫 노드로 삽입
void insert_head(int data){
    // 노드를 생성
    DListNode *new_node = create_node(data);
    
    // 연결리스트가 비어있으면
    if(isEmpty())
        head = tail = new_node;  // head와 tail이 새노드를 참조
    else {
        // 헤드의 선행노드가 새 노드가 됨
        head->prev = new_node;
        // 새노드의 next가 head 노드를 참조함
        new_node->next = head;
        // 새 노드가 head 노드가 됨
        head = new_node;
    }
}

// 새로운 노드를 생성하여 연결리스트의 마지막에 삽입
void insert_tail(int data){
    // 새로운 노드 생성
    DListNode *new_node = create_node(data);
    
    if(isEmpty())
        head = tail = new_node;    // 새 노드를 마지막 노드로 지정함
    else {
        // 마지막 노드의 next가 새 노드를 참조하고
        tail->next = new_node;
        // 새 노드의 prev가 tail 노드를 참조함
        new_node->prev = tail;
        // 새 노드가 tail 노드가 참조함
        tail = new_node;
    }
}

// 첫 노드를 삭제하는 함수
void delete_head()
{
    // 첫 노드를 참조하는 링크를 임시로 저장
    DListNode *temp_node = head;
    
    // 빈 리스트일 경우 - 아무것도 하지 않음
    if( head == NULL )
        return;
    else if(head->next == NULL)  // 노드가 하나뿐일 경우
        tail = NULL;
    else
        head->next->prev = NULL;
    
    head = head->next;
    free(temp_node);
}

// 마지막 노드를 삭제하는 함수
void delete_tail()
{
    // 마지막 노드를 참조하는 링크를 임시로 저장
    DListNode *temp_node = tail;
    
    // 빈 리스트일 경우 - 아무것도 안함
    if ( tail == NULL )
        return;
    else if(head->next == NULL)  // 노드가 하나뿐일 경우
        head = NULL;
    else
        tail->prev->next = NULL;
    
    tail = tail->prev;
    free(temp_node);
}

// 주어진 키를 가진 노드를 삭제함
bool delete(int key)
{
    // 첫 노드에서부터 시작해서 검색
    DListNode* current = head;
    
    // 리스트가 비어있을 경우 false을 반환
    if( head == NULL )
        return false ;
    
    // 리스트를 탐색함
    while(current->data != key){
        // 마지막까지 갔다면 삭제를 안하고 false를 반환
        if(current->next == NULL)
            return false ;
        else
            current = current->next;
    }
    
    if( current == head )
        delete_head();
    else if( current == tail )
        delete_tail();
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    
    return true;
}

// key값을 가진 노드를 발견하면 이 노드 앞에 data 값을 가진
// 새로운 노드를 생성하여 삽입함
bool insert_before(int key,  int data){
    DListNode *current = head;
    
    // 리스트가 비어있다면 false를 반환
    if(head == NULL)
        return false;
    
    // 리스트를 탐색함
    while(current->data != key){
        // 마지막까지 갔다면 삭제를 안하고 false를 반환
        if( current->next == NULL )
            return false;
        else
            current = current->next;
    }
    
    if(current == head) {
        insert_head(data);
    } else {
        // 새 노드를 만든다
        DListNode *new_node = create_node(data);
        
        new_node->prev = current->prev;
        current->prev->next = new_node;
        new_node->next = current;
        current->prev = new_node;
    }
    return true;
}

// key값을 가진 노드를 발견하면 이 노드 뒤에 data 값을 가진
// 새로운 노드를 생성하여 삽입함
bool insert_after(int key,  int data){
    DListNode *current = head;
    
    // 리스트가 비어있다면 false를 반환
    if(head == NULL)
        return false;
    
    // 리스트를 탐색함
    while(current->data != key){
        // 마지막까지 갔다면 삭제를 안하고 false를 반환
        if( current->next == NULL )
            return false;
        else
            current = current->next;
    }
    
    if(current == tail) {
        insert_tail(data);
    }else {
        // 새 노드를 만든다
        DListNode *new_node = create_node(data);
        
        new_node->next = current->next;
        current->next->prev = new_node;
        new_node->prev = current;
        current->next = new_node;
    }
    return true;
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
    delete(100);
    display();
    delete(600);
    display();
    delete(300);
    display();
    delete_tail();
    display();
    insert_before(400, 300);
    display();
    insert_after(400, 500);
    display();
    printf("\n");
    return 0;
}
