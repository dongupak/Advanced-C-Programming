//
//  main.c
//  FunctionBasic
//
//  Created by DongGyu Park on 2016. 4. 25..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

// 함수 선언
//int sum(int a, int b);
// 다음과 같은 형태도 가능함
int sum(int, int);

int main(int argc, const char * argv[]) {

    int n = 10, m = 20;
    // 함수 호출
    printf("%d과 %d의 합은 %d \n",n,m,sum(n,m));
    int res = sum(100, 200);
    printf("res = %d\n", res);
    return 0;
}

// 함수의 구현 - a,b를 매개변수로 받아서 그 합을 반환함
int sum(int a, int b)
{
    int result = a + b;
    return result;
}

