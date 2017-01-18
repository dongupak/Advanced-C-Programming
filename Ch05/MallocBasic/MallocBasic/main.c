//
//  main.c
//  MallocBasic
//
//  Created by DongGyu Park on 2016. 4. 25..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *score;
    int i;
    
    // 100*sizeof(int) 바이트 만큼의 메모리를 동적으로 할당함
    score = (int *)malloc( 100*sizeof(int) );
    if( score == NULL )				// 반환값이 NULL인지 검사
    {
        printf("동적 메모리 할당 오류\n");
        exit(1);
    }
    // 동적으로 할당된 메모리에 값을 할당하는 for문
    for(i=0 ; i<100 ; i++){
        //score[i] = i;
        *(score+i) = i;
    }
    
    free(score);
    
    return 0;
}