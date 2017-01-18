//
//  main.c
//  DynamicArray
//
//  Created by DongGyu Park on 2016. 4. 28..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a;
    
    a = (int *)malloc(5*sizeof(int));
    if( a == NULL ) {
        printf("메모리 할당 에러 \n");
        return -1;
    }
    *(a+0) = 20;
    *(a+1) = 30;
    *(a+2) = 40;
    *(a+3) = 0;
    *(a+4) = 0;
    
    for(int i=0; i<5; i++)
        printf("a[%d] = %d, *(a+%d) = %d \n", i, a[i], i, *(a+i));
    free(a);
    
    return 0;
}
