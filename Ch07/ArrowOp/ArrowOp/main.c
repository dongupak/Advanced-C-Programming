//
//  main.c
//  ArrowOp
//
//  Created by DongGyu Park on 2016. 5. 18..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

typedef int item;
typedef struct ListNode {
    item data;
    struct ListNode *link;
} ListNode ;

int main()
{
    ListNode node = {100, NULL};
    ListNode *list = &node;
 
    printf("node.data = %d\n", node.data);
    printf("(*list).data = %d\n", (*list).data);
    printf("list->data = %d\n", list->data);
    
    return 0;
}
