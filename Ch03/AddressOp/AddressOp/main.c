//
//  main.c
//  AddressOp
//
//  Created by DongGyu Park on 2016. 4. 20..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int i = 10;
    char c = 69;
    float f = 12.3;
    
    printf("i의 값: %d\n", i);	// 변수 i의 값 출력
    printf("i의 주소: %p\n", &i);	// 변수 i의 주소 출력
    printf("c의 값: %c\n", c);	// 변수 c의 주소 출력
    printf("c의 주소: %p\n", &c);	// 변수 c의 주소 출력
    printf("f의 값: %f\n", f);	// 변수 f의 주소 출력
    printf("f의 주소: %p\n", &f);	// 변수 f의 주소 출력
    return 0;
}