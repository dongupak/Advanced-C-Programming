//
//  main.c
//  NodeAndLink
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

typedef int item;
typedef struct ListNode {
    item data;
    struct ListNode *link;
} ListNode ;

int main()
{
    ListNode *p1;
    ListNode *p2;
    
    p1 = (ListNode *)malloc(sizeof(ListNode));
    p1->data = 20;
    
    p2 = (ListNode *)malloc(sizeof(ListNode));
    p2->data = 30;
    p2->link = NULL;
    p1->link = p2;
    
    printf("p1->data = %d\n", p1->data);
    printf("p1->link->data = %d\n", p1->link->data);
    printf("p2->data = %d\n", p2->data);
    
    return 0;
}
