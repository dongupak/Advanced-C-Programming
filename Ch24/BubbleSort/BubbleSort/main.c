//
//  main.c
//  BubbleSort
//
//  Created by DongGyu Park on 2016. 5. 11..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10     // 데이터의 최대 크기

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_list(int list[], int n)
{
    for (int i = 0; i<n; i++)
        printf(" %d ", list[i]);
    printf("\n");
}

// list 배열과 그 배열의 크기 n을 받아서 정렬을 수행
void bubble_sort(int list[], int n)
{
    int i, j;
    
    printf("\n정렬과정\n");
    for (i = n - 1; i>0; i--)
        for (j = 0; j<i; j++) {
            if (list[j]>list[j+1]) {// 앞뒤의 레코드를 비교한 후 교환
                swap(&list[j], &list[j + 1]);
            }
        printf("j=%d : ",j);
        print_list(list,n);
    }
}

// 버블 정렬 기법
int main()
{
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE];
    
//    for (i = 0; i<n; i++)       // 난수 생성
//        list[i] = rand() % 100 ;// 난수 발생 범위 0~99로 함
    
    for (i = 0; i<n; i++)       // 내림차순으로 정렬된 데이터 생성
        list[i] = MAX_SIZE-i ;  // 10 9 8 .. 1을 가지는 배열
    
    printf("버블 정렬전 데이터 \n");
    print_list(list, n);
    
    bubble_sort(list, n);       // 버블정렬 함수 호출
    
    printf("버블 정렬후 데이터 \n");
    print_list(list, n);
    
    return 0;
}
