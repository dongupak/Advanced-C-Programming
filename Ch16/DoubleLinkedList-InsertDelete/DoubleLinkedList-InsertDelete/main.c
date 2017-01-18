//
//  main.c
//  DoubleLinkedList-InsertDelete
//
//  Created by DongGyu Park on 2016. 7. 8..
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
    new_node->prev = NULL;  // llink, rlink를 NULL로 초기화
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
        head = tail = new_node;  // head와 tail가 새노드를 참조
    else {
        head->prev = new_node; // 헤드의 선행노드가 새 노드가 됨
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

// 최초 노드를 삭제하는 함수
void delete_head()
{
    // 최초 노드를 참조하는 링크를 임시로 저장
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
void delete_by_key(int key)
{
    // 첫 노드에서부터 시작해서 검색
    DListNode* current = head;
    DListNode* previous = NULL;
    
    // 리스트가 비어있을 경우 NULL을 반환
    if(head == NULL)
        return ;
    
    // 리스트를 탐색함
    while(current->data != key){
        // 마지막까지 갔다면 삭제를 안하고 NULL을 반환
        if(current->next == NULL){
            return ;
        } else {
            // 현재 링크의 참조를 저장
            previous = current;
            // 다음 노드로 이동함
            current = current->next;
        }
    }
    
    // key값과 일치하는 data를 가진 노드를 발견하면
    if(current == head) {   // head 포인터를 변경한다
        head = head->next;
    }else {
        // current의 이전노드의 next가 current의 다음노드를 참조하도록 한다
        current->prev->next = current->next;
    }
    
    if(current == tail){    // tail 포인터를 변경한다
        tail = current->prev;
    }else {
        current->next->prev = current->prev;
    }
    
    free( current );
}

bool insert_after(int key,  int data){
    //start from the head link
    DListNode *current = head;
    
    //if list is empty
    if(head == NULL){
        return false;
    }
    
    //navigate through list
    while(current->data != key){
        //if it is tail node
        if(current->next == NULL){
            return false;
        }else {
            //move to next link
            current = current->next;
        }
    }
    
    //create a link
    DListNode *new_node = create_node(data);
    
    if(current == tail) {
        new_node->next = NULL;
        tail = new_node;
    }else {
        new_node->next = current->next;
        current->next->prev = new_node;
    }
    
    new_node->prev = current;
    current->next = new_node;
    return true;
}

int main() {
    insert_head(100);
    insert_head(200);
    insert_head(300);
    insert_head(400);
    insert_head(500);
    insert_head(600);
    
    printf("\n순방향출력 (처음부터 끝): ");
    display();
    
    delete_by_key(100);
    display();
    
    delete_by_key(600);
    display();
    
    delete_by_key(300);
    display();
    
    delete_tail();
    display();
    
    insert_after(400, 300);
    display();
    
    //    printf("\n");
    //    printf("\n역방향출력 (끝부터 처음) : ");
    //    reverse_display();
    //
    //    printf("\n첫 노드를 삭제: ");
    //    delete_head();
    //    display();
    //
    //    printf("\n마지막 노드를 삭제 : ");
    //    delete_tail();
    //    display();
    //
    //    printf("\n(400) 뒤에 450을 삽입 : ");
    //    insert_after(400, 450);
    //    display();
    //
    //    printf("\n(400)을 제거한 리스트 : ");
    //    delete(400);
    //    display();
    
    printf("\n");
    return 0;
}