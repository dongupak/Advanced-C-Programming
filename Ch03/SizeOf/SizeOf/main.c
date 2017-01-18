//
//  main.c
//  SizeOf
//
//  Created by DongGyu Park on 2016. 4. 20..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int i;
    char ch;
    short shrt;
    float flt;
    double dbl;
    
    printf("int형의 크기 = %lu \n", sizeof(int));
    printf("변수 i의 크기 = %lu \n", sizeof(i));
    
    printf("변수 ch의 크기 = %lu \n", sizeof(ch));
    printf("변수 shrt의 크기 = %lu \n", sizeof(shrt));
    printf("변수 flt의 크기 = %lu \n", sizeof(flt));
    printf("변수 dbl의 크기 = %lu \n", sizeof(dbl));
}
