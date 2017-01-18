//
//  main.c
//  QuickSortLib
//
//  Created by DongGyu Park on 2016. 12. 14..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE    9

// list 배열의 원소를 출력하는 함수
void print_list(int list[], int n)
{
    int i;
    for (i = 0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

// 퀵정렬을 위한 비교함수
// 이 프로그램은 정수값을 비교하므로 void형 포인터 변수의 형은 int형 포인터로
// 형을 변환하여 비교한다
int compare(const void *a, const void *b)
{
    // a가 b보다 크면 양수, 같으면 0, 작으면 음수를 반환
    //return ( *(int *)a - *(int *)b);
    return ( *(int *)b - *(int *)a );
}

//
int main()
{
    int list[MAX_SIZE] = { 18, 14, 17, 20, 25, 13, 16, 22, 40 };
    
    printf("퀵정렬 전 데이터 \n");
    print_list(list, MAX_SIZE);
    printf("\n");
    
    qsort((void *)list, (size_t)MAX_SIZE, sizeof(int), compare);
    
    printf("퀵정렬 후 데이터 \n");
    print_list(list, MAX_SIZE);
    printf("\n");
}
