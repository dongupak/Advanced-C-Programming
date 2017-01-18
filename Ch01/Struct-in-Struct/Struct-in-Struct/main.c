//
//  main.c
//  Struct-in-Struct
//
//  Created by DongGyu Park on 2016. 4. 19..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
};

int main(void)
{
    struct rect r;
    int w, h, area, peri;
    
    printf("왼쪽 상단의 좌표를 입력하시오: ");
    scanf("%d %d", &r.p1.x, &r.p1.y);
    
    printf("오른쪽 하단의 좌표를 입력하시오: ");
    scanf("%d %d", &r.p2.x, &r.p2.y);
    
    w = r.p2.x - r.p1.x;
    h = r.p2.y - r.p1.y;
    
    area = w * h;
    peri = 2 * w + 2 * h;
    printf("사각형의 면적은 %d이고 둘레는 %d입니다.\n", area, peri);
    
    struct rect new_r;
    new_r = r;   // OK
//    struct rect rx = r * new_r;
//    if( r < new_r )   // 비교연산은 지원하지 않는다
//    {
//        printf("new_r이 큽니다 \n");
//    }
//
    struct rect array_r[10];   // 구조체 배열은 가능함
    
    return 0;
}

