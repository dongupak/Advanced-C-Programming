//
//  main.c
//  InsertionSort
//
//  Created by DongGyu Park on 2016. 11. 10..
//  Copyright © 2016년 ProfPark. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void print_list(int list[], int n)
{
    int i;
    for (i = 0; i<n; i++)
        printf(" %d ", list[i]);
    printf("\n");
}

// 삽입정렬 알고리즘, list는 정렬되기 전의 배열
void insertion_sort(int list[], int n)
{
    int i, j, key;
    
    for(i=1; i<n; i++){
        key = list[i];  // list[i] 값을 key값으로 두고 삽입
        // list의 j번째 원소값이 key보다 크면 한칸씩(j+1) 이동시킨다
        for(j=i-1; j>=0 && list[j]>key; j--)
            list[j+1] = list[j];
        // 삽입위치에 key값을 넣는다
        list[j+1] = key;
        print_list(list, n);
    }
}

//
int main()
{
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE];
    
    for (i = 0; i<n; i++)      	// 난수 생성 및 출력
        list[i] = rand() % 100 ; // 난수 발생 범위 0~99
//    for (i = 0; i<n; i++)      	// 10,9,9,...,1의 값을 가진 배열
//        list[i] = MAX_SIZE - i ;
    
    printf("삽입 정렬 전 데이터 \n");
    print_list(list, MAX_SIZE);
    
    insertion_sort(list, n); // 삽입정렬함수 호출
    
    printf("삽입 정렬 후 데이터 \n");
    print_list(list, MAX_SIZE);
    
    return 0;
}
