//
//  main.c
//  HeapSort
//
//  Created by DongGyu Park on 2016. 12. 14..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

#define MAX_ELEMENT 200 // 최대 힙 원소의 갯수

typedef struct {
    int data[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 초기화 함수
void init(HeapType *heap)
{
    heap->heap_size = 0;
}

// 힙 내용 출력 함수
void print_heap(HeapType *heap)
{
    int i;
    int level = 1;
    
    printf("\n===================");
    for (i = 1; i <= heap->heap_size; i++) {
        if (i == level) {
            printf("\n");
            level *= 2;
        }
        printf("\t%d", heap->data[i]);
    }
    printf("\n===================\n");
}

// max heap의 삽입 함수
void insert_max_heap(HeapType *heap, int item)
{
    int i;
    i = ++(heap->heap_size);
    
    // 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item > heap->data[i/2])) {
        heap->data[i] = heap->data[i/2];
        i /= 2;
    }
    heap->data[i] = item;     // 새로운 노드를 삽입
}

// 삭제 함수
int delete_max_heap(HeapType *heap)
{
    int parent, child;
    int item, temp;
    
    item = heap->data[1];
    temp = heap->data[(heap->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= heap->heap_size) {
        // 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
        if ((child < heap->heap_size) &&
            (heap->data[child]) < heap->data[child + 1])
            child++;
        if (temp >= heap->data[child]) break;
        // 한단계 아래로 이동
        heap->data[parent] = heap->data[child];
        parent = child;
        child *= 2;
    }
    heap->data[parent] = temp;
    return item;
}

// 힙를 이용한 정렬
void heap_sort(int *data, int n)
{
    int i;
    HeapType heap;
    
    init(&heap);
    for (i = 0; i<n; i++)
        insert_max_heap(&heap, data[i]);
    
    for (i = (n - 1); i >= 0; i--)
        data[i] = delete_max_heap(&heap);
}

#define ELEMENT_SIZE    6

// 주함수
int main(void)
{
    int data[] = {30, 10, 20, 55, 23, 11};
    
    printf("정렬 전 데이터 \n");
    for(int i=0; i<ELEMENT_SIZE; i++)
        printf("%d ", data[i]);
    printf("\n");
    
    heap_sort(data, ELEMENT_SIZE);
    
    printf("\nheap 정렬 후 데이터 \n");
    for(int i=0; i<ELEMENT_SIZE; i++)
        printf("%d ", data[i]);
    printf("\n");
    
    return 0;
}
