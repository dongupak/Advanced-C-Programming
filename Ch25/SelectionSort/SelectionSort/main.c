//
//  main.c
//  SelectionSort
//
//  Created by DongGyu Park on 2016. 12. 1..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_list(int list[], int n)
{
    int i;
    for (i = 0; i<n; i++)
        printf(" %d ", list[i]);
    printf("\n");
}

void selection_sort(int list[], int n)
{
    int i, j, pos_min;
    for (i = 0; i<n - 1; i++) {
        pos_min = i;
        for (j = i + 1; j<n; j++) 	// 최소값 탐색
            if (list[j]<list[pos_min])
                pos_min = j;
        // list의 i번째 원소와 최소값을 가지는 pos_min 위치의 원소값을 교환
        swap(&list[i], &list[pos_min]);
        print_list(list, n);
    }
}

//
int main()
{
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE];

//    for (i = 0; i<n; i++)      	// 난수 생성 및 출력
//        list[i] = rand() % 100 ; // 난수 발생 범위 0~99
    for (i = 0; i<n; i++)      	// 10,9,9,...,1의 값을 가진 배열
        list[i] = MAX_SIZE - i ;
    
    printf("선택 정렬 전 데이터 \n");
    print_list(list, MAX_SIZE);
    
    selection_sort(list, n); // 선택정렬함수 호출
    
    printf("선택 정렬 후 데이터 \n");
    print_list(list, MAX_SIZE);
    
    return 0;
}
