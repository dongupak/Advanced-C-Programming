//
//  main.c
//  MergeSort
//
//  Created by DongGyu Park on 2016. 11. 11..
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

// list[]의 원소를 나누어서 임시 배열에 넣은 후, 이 원소들을 합병한다
void merge(int list[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // 빈 배열 만들기, 이 배열은 list 배열의 부분 배열임
    int left_list[n1], right_list[n2];
    
    // 임시 배열 left_list, right_list에 list 배열의 원소를 나누어 넣음
    for (i = 0; i < n1; i++)
        left_list[i] = list[l + i];
    for (j = 0; j < n2; j++)
        right_list[j] = list[m + 1 + j];
    
    // 임시 배열 left_list, right_list의 원소를 합병하며 list에 넣음
    // 이 때문에 합병 정렬은 임시 배열이 필요하다
    i = 0; // left 부분 배열의 초기 인덱스
    j = 0; // right 부분 배열의 초기 인덱스
    k = l; // 합병된 배열의 초기 인덱스
    while (i < n1 && j < n2)
    {
        if (left_list[i] <= right_list[j])
        {
            list[k] = left_list[i];
            i++;
        }
        else
        {
            list[k] = right_list[j];
            j++;
        }
        k++;
    }  // 합병이 완료될때까지 loop를 수행하며
    
    // 합병 후 left_list에 남아있는 원소가 있을 경우 이를 list에 넣기
    while (i < n1)
    {
        list[k] = left_list[i];
        i++;
        k++;
    }
    // 합병 후 right_list에 남아있는 원소가 있을 경우 이를 list에 넣기
    while (j < n2)
    {
        list[k] = right_list[j];
        j++;
        k++;
    }
}

// 합병 정렬 함수
void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left < right) {
        mid = (left + right) / 2;     // 배열의 중간 인덱스 값을 구한다
        merge_sort(list, left, mid);    // 앞의 절반을 정렬
        merge_sort(list, mid + 1, right); // 뒤의 절반을 정렬
        merge(list, left, mid, right);    // 두 개를 합병
    }
}

// 합병 정렬 프로그램
int main()
{
    int n = MAX_SIZE;
    int list[MAX_SIZE];
    
    for (int i = 0; i<n; i++)      	// 난수 생성 및 출력
        list[i] = rand() % 100 ; // 난수 발생 범위 0~100
    
    printf("합병 정렬 전 데이터 \n");
    print_list(list, MAX_SIZE);
    
    merge_sort(list, 0, MAX_SIZE-1); // 합병 정렬함수 호출
    
    printf("합병 정렬 후 데이터 \n");
    print_list(list, MAX_SIZE);
    
    return 0;
}
