//
//  main.c
//  MallocBasic1
//
//  Created by DongGyu Park on 2016. 4. 25..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ip;        // int형 변수를 가리키는 포인터변수
    double *dp;     // double형 변수를 가리키는 포인터변수

    // 동적으로 int, double 자료형 크기의 메모리를 할당받음
    ip=(int *)malloc(sizeof(int));
    dp=(double *)malloc(sizeof(double));
    
    // 할당된 메모리 공간에 값을 넣는다
    *ip=10;
    *dp=3.4;
    
    printf("정수형 포인터 변수의 값 : %d\n", *ip);
    printf("실수형 포인터 변수의 값 : %lf\n", *dp);
    
    free(ip);
    free(dp);
    
    return 0;
}
