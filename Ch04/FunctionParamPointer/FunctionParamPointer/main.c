//
//  main.c
//  FunctionParamPointer
//
//  Created by DongGyu Park on 2016. 4. 25..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

void changeNum(int *ptr);

int main(int argc, const char * argv[]) {
    
    int num = 10;
    // 함수 호출
    printf("num = %d\n", num);
    changeNum(&num);
    printf("changeNum()의 결과 \n");
    printf("num = %d\n", num);
    return 0;
}

// changeNum 함수의 구현 - n을 20으로 수정
void changeNum(int *ptr)
{
    *ptr = 20;
}
