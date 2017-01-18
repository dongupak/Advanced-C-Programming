//
//  main.c
//  QuickSort
//
//  Created by DongGyu Park on 2016. 12. 14..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

#define MAX_SIZE 9

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// list 배열의 원소를 출력하는 함수
void print_list(int list[], int n)
{
    int i;
    for (i = 0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

// list에는 정렬전 원소들이 있으며, left, right 값은 정렬할 데이터의 인덱스가 있다
int partition(int list[], int left, int right)
{
    int pivot;
    int low = left, high = right+1;
    
    pivot = list[left]; 	// 피벗은 list의 첫값으로 정한다
    do {
        do
            low++;    // 리스트의 왼편에서 피벗 값보다 큰 레코드1을 선택
        while (low <= right && list[low] < pivot);
        do
            high--;   // 리스트의 오른쪽에서 피벗보다 작은 레코드2를 선택
        while (high >= left && list[high] > pivot);
        if (low<high) // low값이 high보다 작으면 레코드1, 레코드2를 서로 교환
            swap(&list[low], &list[high]);
    } while (low < high);	  // 인덱스의 high 값이 low보다 크면 반복수행
    
    swap(&list[left], &list[high]); // 리스트의 제일 첫 값과 high 값을 교환
    
    return high;
}

// 퀵정렬은 재귀적인 기법을 사용하면 간결하게 구현할 수 있다
void quick_sort(int list[], int left, int right)
{
    if (left<right) {     // 분할가능한 상태이면
        // 피벗을 중심으로 작은 값은 왼쪽 부분리스트로 큰 값은 오른쪽 부분리스트로 보낸다
        int q = partition(list, left, right);
        printf("pivot = %d\n", q);
        print_list(list, MAX_SIZE);
        quick_sort(list, left, q - 1);      // 왼쪽 부분리스트를 퀵정렬
        quick_sort(list, q + 1, right);     // 오른쪽 부분리스트를 퀵정렬
    }
}

//
int main()
{
    int list[MAX_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //int list[MAX_SIZE] = { 18, 14, 17, 20, 25, 13, 16, 22, 40 };
    
    printf("퀵정렬 전 데이터 \n");
    print_list(list, MAX_SIZE);
    printf("\n");
    
    printf("퀵정렬 과정 \n");
    quick_sort(list, 0, MAX_SIZE-1);
    printf("\n");
    
    printf("퀵정렬 후 데이터 \n");
    print_list(list, MAX_SIZE);
    printf("\n");
}
