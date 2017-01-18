//
//  main.c
//  Swap1
//
//  Created by DongGyu Park on 2016. 4. 25..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
void swap(int x, int y);

int main(void)
{
    int a = 100, b = 200;
    
    printf("a=%d b=%d\n",a, b);
    swap(a, b);
    printf("a=%d b=%d\n",a, b);
    
    return 0;
}

void swap(int x, int y)
{
    int tmp;
    
    printf("swap() x=%d y=%d\n",x, y);
    tmp = x;
    x = y;
    y = tmp;
    printf("swap() x=%d y=%d\n",x, y);
}
