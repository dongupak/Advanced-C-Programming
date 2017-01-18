//
//  main.c
//  NodeGen
//
//  Created by DongGyu Park on 2016. 4. 29..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

//
//  main.c
//  List1
//
//  Created by DongGyu Park on 2016. 3. 31..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char item;
typedef struct ListNode {
    item data;
    struct ListNode *link;
} ListNode ;

int main()
{
    ListNode *head, *current, *new_node ;
    head =  current = new_node = NULL ;     // 초기화
    item n;
    
    printf("문자 데이터를 입력하시오 : ");
    // EOF 입력이 들어올때까지 값을 받아서 노드객체를 생성하여 연결리스트에 추가
    while (scanf("%c\n",&n) != EOF) {
        new_node = (ListNode *)malloc(sizeof(ListNode));
        new_node->data = n;
        new_node->link = NULL;
        
        if(head == NULL)
        {
            head = new_node;
            current = new_node;
        }
        else
        {
            current->link = new_node;
            current = new_node;
        }
    }
    
    // 연결리스트의 원소들을 출력함
    printf("연결리스트의 원소들은 다음과 같습니다 \n");
    current = head;
    while (current != NULL) {
        printf("%c \n", current->data);
        current = current->link;
    }
    return 0;
}
