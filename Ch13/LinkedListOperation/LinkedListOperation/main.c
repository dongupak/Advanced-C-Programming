#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

// phead: 리스트의 헤드 포인터의 포인터
// prev : 선행 노드
// new_node : 삽입될 노드
void insert_node(ListNode **phead, ListNode *prev, ListNode *new_node)
{
    if (*phead == NULL) {	// 공백리스트인 경우
        new_node->link = NULL;
        *phead = new_node;
    }
    else if (prev == NULL) { // prev가 NULL이면 첫번째 노드로 삽입
        new_node->link = *phead;
        *phead = new_node;
    }
    else {			 // prev 다음에 삽입
        new_node->link = prev->link;
        prev->link = new_node;
    }
}

// 연결리스트의 첫 노드를 삭제하는 함수
// head 노드가 NULL이 아니면 head 노드 다음 노드가 head노드가 되도록 함
void removeFirst(ListNode **phead)
{
    if( *phead == NULL )
        return;
    else {
        ListNode *removedNode;
        removedNode = *phead;
        *phead = (*phead)->link;
        free(removedNode);
    }
}

void removeLast(ListNode **phead)
{
    ListNode *prev = (*phead);
    ListNode *next ;
    
    // NULL 연결리스트이면 제거할 노드가 없음
    if( prev == NULL )
        return;
    else if( prev->link == NULL) { // 단일노드이면 노드하나만 제거
        free( prev );
        *phead = NULL;
        return;
    }
    
    // 연결리스트에 2개 이상의 노드가 있을 경우
    while (prev != NULL) {
        next = prev->link;
        // next 노드 다음에 노드가 없을때 next 노드를 제거
        if( next->link == NULL)
        {
            prev->link = NULL;
            free(next);
            return;
        }
        else {  // 그렇지 않으면 다음 노드 탐색
            prev = next;
        }
    }
}

// phead : 헤드 포인터에 대한 포인터
// prev : 삭제될 노드의 선행 노드
// removed: 삭제될 노드
void remove_node(ListNode **phead, ListNode *prev, ListNode *removed)
{
    if (prev == NULL)
        *phead = (*phead)->link;
    else
        prev->link = removed->link;
    free(removed);
}

void display(ListNode *head)
{
    ListNode *current = head;
    
    printf("(");
    while (current != NULL) {
        printf("%d", current->data);
        current = current->link;
        if( current != NULL )
            printf(", ");
    }
    
    printf(")\n");
}

// 연결리스트의 길이를 리턴받는 프로그램
int get_length(ListNode *head)
{
    int n = 0;
    
    ListNode *current = head;
    while (current != NULL) {
        current = current->link;
        n++;
    }
    return n;
}

// 연결리스트의 노드를 순회하며 data 필드의 합을 리턴받는 프로그램
int get_sum(ListNode *head)
{
    int sum = 0;
    
    ListNode *current = head;
    while (current != NULL) {
        // 원소의 값 current->data를 sum에 누적하여 더한다
        sum += current->data;
        current = current->link;
    }
    // 결과값 sum을 반환한다
    return sum;
}

// 연결리스트의 원소의 최댓값을 리턴받는 프로그램
int get_max(ListNode *head)
{
    int max = 0 ;
    
    ListNode *current = head;
    if( current != NULL )
        max = current->data;
    
    while (current != NULL) {
        // 원소의 값 current->data를 검사하여 max보다 크면 max를 변경
        if( current->data > max )
            max = current->data;
        current = current->link;
    }
    // 결과값 max을 반환한다
    return max;
}

// 연결리스트의 원소의 최솟값을 리턴받는 프로그램
int get_min(ListNode *head)
{
    int min = 0 ;
    
    ListNode *current = head;
    if( current != NULL )
        min = current->data;
    
    while (current != NULL) {
        // 원소의 값 current->data를 검사하여 min보다 작으면 min을 변경
        if( current->data < min )
            min = current->data;
        current = current->link;
    }
    // 결과값 min을 반환한다
    return min;
}

// 재귀함수를 이용한 연결리스트의 출력
void display_recur(ListNode *head)
{
    ListNode *current = head;
    if (current != NULL) {
        printf(" %d -> ", current->data);
        display_recur(current->link);
    }
}

// 연결리스트에 특정한 값이 있는가 검색함
ListNode *search(ListNode *head, int x)
{
    ListNode *current ;
    current = head;
    
    while (current != NULL) {
        if (current->data == x)
            return current;  // 탐색 성공
        current = current->link;
    }
    return current;  // 탐색 실패일 경우 제일마지막의 NULL 반환
}

// 두 연결리스트를 병함함
// 두 연결리스트의 head가 입력값
ListNode *concat(ListNode *head1, ListNode *head2)
{
    ListNode *p ;
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        p = head1;
        // 연결리스트의 마지막까지 순회하여
        while (p->link != NULL)
            p = p->link;
        // 마지막노드의 link가 head2를 참조하도록 함
        p->link = head2;
        
        return head1;
    }
}
// 연결리스트를 꺼꾸로 만듦
ListNode *reverse(ListNode *head)
{
    // 순회 포인터로 p, q, r을 사용
    ListNode *p, *q, *r;
    p = head;         // p는 역순으로 만들 리스트
    q = NULL;         // q는 역순으로 만들 노드
    while (p != NULL) {
        r = q;          // r은 역순으로 된 리스트. r은 q, q는 p를 차례로 따라간다.
        q = p;
        p = p->link;
        q->link = r;      // q의 링크 방향을 바꾼다.
    }
    return q; 	// q는 역순으로 된 리스트의 헤드 포인터
}

// 연결리스트의 최댓값을 제거함
void delete_max(ListNode **head)
{
    int max = 0;
    ListNode *current = *head;
    ListNode *prev = NULL, *next = NULL;
    
    if( current == NULL)  // NULL리스트이면 return;
        return;
    else if ( current->link == NULL ) // 단일노드 리스트이면
    {
        *head = NULL; // head를 NULL로 하고
        free(current);  // current를 제거함
    }
    
    max = get_max(*head);
    
    while ( current->link != NULL) {
        prev = current;
        next = current->link;
        
        if( current->data == max ) { // current 노드가 max 값을 가질때
            remove_node(head, NULL, current);
            current = next;
        }
        else if( next->data == max) { // next 노드가 max 값을 가질때
            remove_node(head, current, next);
            current = prev;
        }
        else
            current = current->link;
    }
}

// 연결리스트의 최솟값을 제거함
void delete_min(ListNode **head)
{
    int min = 0;
    ListNode *current = (*head);
    ListNode *prev = NULL, *next = NULL;
    
    if( current == NULL)  // NULL리스트이면 return;
        return;
    else if ( current->link == NULL ) // 단일노드 리스트이면
    {
        *head = NULL; // head를 NULL로 하고
        free(current);  // current를 제거함
    }
    
    min = get_min(*head);
    
    while ( current->link != NULL) {
        prev = current;
        next = current->link;
        
        if( current->data == min ) { // current 노드가 max 값을 가질때
            remove_node(head, NULL, current);
            current = next;
        }
        else if( next->data == min) { // next 노드가 max 값을 가질때
            remove_node(head, current, next);
            current = prev;
        }
        else
            current = current->link;
    }
}

// 노드를 동적으로 생성하는 프로그램
ListNode *create_node(element data, ListNode *link)
{
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = link;
    
    return(new_node);
}

// 테스트 프로그램
int main()
{
    ListNode *list1 = NULL, *list2 = NULL;
    ListNode *p;
    
    insert_node(&list1, NULL, create_node(90, NULL));
    insert_node(&list1, NULL, create_node(80, NULL));
    insert_node(&list1, NULL, create_node(70, NULL));
    insert_node(&list1, NULL, create_node(60, NULL));
    insert_node(&list1, NULL, create_node(50, NULL));
    insert_node(&list1, NULL, create_node(40, NULL));
    printf("연결리스트 출력 \n");
    printf("list1 = ");
    display(list1);
    
    printf("\n연결리스트의 길이를 알아봅니다\n");
    int n = get_length(list1);
    printf("list1의 노드는 %d 개 입니다 \n", n);
//
    int sum = get_sum(list1);
    printf("list1의 노드의 data 필드의 합은 %d 입니다 \n", sum);
//
    int max = get_max(list1);
    printf("list1의 최댓값은 %d 입니다 \n", max);
//
    printf("최댓값 %d를 삭제한 후의 연결리스트 \n", max);
    delete_max(&list1);
    display(list1);
//
    int min = get_min(list1);
    printf("list1의 최솟값은 %d 입니다 \n", min);
//
    printf("최솟값 %d를 삭제한 후의 연결리스트 \n", min);
    delete_min(&list1);
    display(list1);
    
//    // list1에서 20 탐색
//    int num = 20;
//    p = search(list1, num);
//    printf("\nlist1에서 %d를 찾습니다 \n", num);
//    if( p != NULL )
//        printf("탐색성공: %d\n", p->data);
//    else
//        printf("탐색실패 \n");
//    
    insert_node(&list2, NULL, create_node(9000, NULL));
    insert_node(&list2, NULL, create_node(9100, NULL));

    printf("list1 : ");
    display(list1);
    printf("list2 : ");
    display(list2);
//
    list1 = concat(list1, list2);
    printf("합병후의 list1 : ");
    display(list1);
    
    return 0;
}