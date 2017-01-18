//
//  main.c
//  Typedef-delta
//
//  Created by DongGyu Park on 2016. 4. 19..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

typedef struct point {
    int x;
    int y;
} POINT;

POINT translate(POINT p, POINT delta);

int main(void)
{
    POINT p = { 2, 3 };
    POINT delta = { 10, 10 };
    POINT result;
    
    result = translate(p, delta);
    printf("새로운 점의 좌표는(%d, %d)입니다.\n", result.x, result.y);
    
    return 0;
}

POINT translate(POINT p, POINT delta)
{
    POINT new_p;
    
    new_p.x = p.x + delta.x;
    new_p.y = p.y + delta.y;
    
    return new_p;
}

