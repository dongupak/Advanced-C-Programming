//
//  main.c
//  SkipList
//

/* Skip Lists: A Probabilistic Alternative to Balanced Trees */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>  // getpid()

// 스킵리스트의 최대 레벨을 지정하여 제한함
#define SKIPLIST_MAX_LEVEL 6

// 스킵 리스트의 노드 구조체 - 키 값과 밸류 값 그리고 forward 값을 가짐
typedef struct snode {
    int key;
    int value;
    struct snode **forward;
} snode;

// 스킵 리스트 구조체
typedef struct skiplist {
    int level;              // 스킵리스트의 최대 레벨
    struct snode *header;   // 스킵리스트 헤더 노드
} skiplist;

// 스킵 리스트 초기화 함수
skiplist *skiplist_init(skiplist *list)
{
    int i;
    
    // 헤드 노드를 동적으로 만들어서 list->header가 참조하도록 하고 key는 INT_MAX로 두자
    snode *header = (snode *)malloc(sizeof(struct snode));
    list->header = header;
    header->key = INT_MAX;
    header->value = INT_MAX;
    
    // 헤드 노드의 forward는 노드를 참조하는 포인터 변수를 참조함
    header->forward = (snode **)malloc(sizeof(snode*)*(SKIPLIST_MAX_LEVEL+1));
    
    // header의 forward[i] 배열값이 스킵리스트의 헤드노드를 참조하도록 초기화
    for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {
        header->forward[i] = list->header;
    }
    // 리스트의 기본 레벨은 1로 초기화
    list->level = 1;
    
    return list;
}

// 난수가 RAND_MAX/2보다 작을 확률은 1/2이다
// 이 함수는 1/2의 확률로 참(1)또는 거짓(0)을 반환한다
int flip()
{
    return rand() < RAND_MAX/2;
}

// 스킵 리스트의 레벨을 생성함
static int rand_level()
{
    int level = 1;
    
    // 레벨값은 랜덤하게 생성하되 매 레벨이 1 증가할 확률은 1/2씩 감소함
    // level 값이 2가 될 확률은 1/2, level이 3이 될 확률은 (1/2)*(1/2), ...
    // 단 최대 레벨은 SKIPLIST_MAX_LEVEL 미만임
    while ( flip() == 0 && level < SKIPLIST_MAX_LEVEL)
        level++;
    return level;
}

int gl_level[SKIPLIST_MAX_LEVEL+1] = {0};

void skplist_levelprint()
{
    for (int i=1; i<SKIPLIST_MAX_LEVEL; i++) {
        printf("level %d : number of element %d \n", i, gl_level[i]);
    }
}

// 스킵 리스트에 key와 value를 가진 노드를 삽입
int skiplist_insert(skiplist *list, int key, int value)
{
    snode *update[SKIPLIST_MAX_LEVEL+1];
    snode *x = list->header;
    int i, level;
    
    // 리스트의 레벨을 감소시키며 forward를 업데이트합다.
    // 이때 update[i]에는 삽입될 key 값의 위치
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key) {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[1];
    
    if (key == x->key) {
        x->value = value;
        return 0;
    }
    else {
        level = rand_level();
        if (level > list->level) {
            for (i = list->level+1; i <= level; i++) {
                update[i] = list->header;
            }
            list->level = level;
        }
        
        x = (snode *)malloc(sizeof(snode));
        x->key = key;
        x->value = value;
        x->forward = (snode **)malloc(sizeof(snode*) * (level + 1));
        
        for (i = 1; i <= level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
    
    // 새로운 노드 삽입후의 결과 출력
    printf("\n** After insert key = %d, ", key);
    printf("(level = %d, x = %p)\n", level, x);
    for (i=1; i<level; i++) {
        printf("forward[%d] = %p\tx->forward[%d]->key = %d\n",
               i, x->forward[i],i,x->forward[i]->key);
    }
    
    return 0;
}

// 스킵 리스트 검색 알고리즘
snode *skiplist_search(skiplist *list, int key)
{
    snode *x = list->header;
    int i;
    
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
    }
    if (x->forward[1]->key == key)
        return x->forward[1];
    
    return NULL;
}

// 스킵 리스트의 전체 노드를 힙 메모리에서 소거함
void skiplist_free(skiplist *list)
{
    snode *current_node = list->header->forward[1];
    while(current_node != list->header) {
        snode *next_node = current_node->forward[1];
        free(current_node->forward);
        free(current_node);
        current_node = next_node;
    }
    free(list->header->forward);
    free(list->header);
}

// 스킵 리스트 노드를 힙 메모리에서 해지
static void skiplist_node_free(snode *x)
{
    if (x) {
        free(x->forward);
        free(x);
    }
}

// 스킵 리스트 노드의 삭제 - 주어진 키 값을 가지는 노드를 삭제함
int skiplist_delete(skiplist *list, int key)
{
    int i;
    snode *update[SKIPLIST_MAX_LEVEL + 1];
    snode *x = list->header;
    
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }
    
    x = x->forward[1];
    if (x->key == key) {
        for (i = 1; i <= list->level; i++) {
            if (update[i]->forward[i] != x)
                break;
            update[i]->forward[i] = x->forward[i];
        }
        skiplist_node_free(x);
        
        while (list->level > 1 && list->header->forward[list->level] == list->header)
            list->level--;
        return 0;
    }
    return 1;
}

// 스킵 리스트의 내용을 살펴보자
static void skiplist_dump(skiplist *list)
{
    snode *x = list->header;
    while (x != NULL && x->forward[1] != list->header) {
        x = x->forward[1];
        printf("[key = %10d]\n", x->key);
    }
}

int main()
{
    int arr[] = {3, 91, 88, 72, 9, 14, 20, 77, 71, 16}, i;
    skiplist list;
    
    srand((unsigned)time(NULL)+(unsigned)getpid());
    
    skiplist_init(&list);
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        skiplist_insert(&list, arr[i], arr[i]);
    }
    skiplist_dump(&list);
    
    skiplist_free(&list);
    
    return 0;
}
