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
#define SKIPLIST_MAX_LEVEL  6
#define BASE_LEVEL          0

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

// 스킵 리스트 초기화 ** After insert함수
skiplist *skiplist_init(skiplist *list)
{
    int i;
    
    // 헤드 노드를 동적으로 만들어서 list->header가 참조하도록 하고 key는 INT_MAX로 두자
    snode *header = (snode *)malloc(sizeof(struct snode));
    list->header = header;
    header->key = INT_MAX;
    header->value = INT_MAX;
    
    // 헤드 노드의 forward 포인터는 노드 * (최대 레벨 개수+1) 만큼의 메모리를 참조
    header->forward = (snode **)malloc(sizeof(snode*)*(SKIPLIST_MAX_LEVEL));
    
    // header의 forward[i] 배열값이 스킵리스트의 헤드노드를 참조하도록 초기화
    for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {
        header->forward[i] = list->header;
    }
    // 리스트의 기본 레벨은 1로 초기화
    list->level = 1;
    
    return list;
}

// 난수가 RAND_MAX/2 보다 작을 확률은 1/2이다
// 이 함수는 1/2의 확률로 참(1값)을 반환한다
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
    return level ;
}

// 스킵 리스트에 key와 value를 가진 노드를 삽입
int skiplist_insert(skiplist *list, int key, int value)
{
    snode *update[SKIPLIST_MAX_LEVEL];
    snode *x = list->header;
    int i, level;
    
    // update[0,...,SKIPLIST_MAX_LEVEL-1] 배열에 새로 삽입할 객체를 참조할 포인터 변수의
    // 정보를 넣어둔다
    for (i = list->level-1; i >= BASE_LEVEL; i--) {
        while (x->forward[i]->key < key) {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[BASE_LEVEL];
    
    if (key == x->key) {
        x->value = value;
        return 0;
    }
    else {
        level = rand_level();
        if (level > list->level) {
            for (i = list->level; i <= level-1; i++) {
                update[i] = list->header;
            }
            list->level = level;
        }
        
        // x는 새로 삽입되는 노드로 update[] 배열에 기록된 정보를 바탕으로
        // level을 갱신하는 방식을 사용한다
        x = (snode *)malloc(sizeof(snode));
        x->key = key;
        x->value = value;
        x->forward = (snode **)malloc(sizeof(snode*) * (level));
        
        for (i = 0; i <= level-1; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
    
    printf("\n** After insert key = %d, ", key);
    printf("(level = %d, x = %p)\n", level, x);
    for (i=BASE_LEVEL; i<=level-1; i++) {
        printf("forward[%d] = %p\tx->forward[%d]->key = %d\n",
               i, x->forward[i],i,x->forward[i]->key);
    }
    
    return 0;
}

// 스킵 리스트의 내용을 살펴보자
static void skiplist_dump(skiplist *list)
{
    snode *x = list->header;
    printf("header = %p\n", x);
    while (x != NULL && x->forward[BASE_LEVEL] != list->header) {
                x = x->forward[BASE_LEVEL];
        printf("[key = %10d], x = %p, x->forward[0] = %p\n",
               x->key, x, x->forward[BASE_LEVEL]);
    }
}

int main()
{
    int arr[] = {3, 91, 88, 72, 9, 14, 20, 72, 16}, i;
    skiplist list;
    
    srand((unsigned)time(NULL)+(unsigned)getpid());
    
    skiplist_init(&list);
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        skiplist_insert(&list, arr[i], arr[i]);
    }
    skiplist_dump(&list);
    
//    for (i = 0; i < 100000; i++) {
//        int randKey = rand() % INT_MAX ;
//        int rankValue = rand() % INT_MAX ;
//        
//        skiplist_insert(&list, randKey, rankValue);
//    }
    
    // 스킵 리스트의 내부에 keys[] 배열값의 노드가 있는가 찾아보자
//    printf("Search:--------------------\n");
//    int keys[] = {3, 4, 7, 16, 111};
//    for (i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
//        snode *x = skiplist_search(&list, keys[i]);
//        if (x) {
//            printf("key = %d, value = %d\n", keys[i], x->value);
//        } else {
//            printf("key = %d, not found\n", keys[i]);
//        }
//    }
//    
//    // 스킵 리스트의 노드중 3,9 키 값을 가지는 노드가 있으면 삭제하자
//    printf("Delete 3 and 9 node : \n");
//    skiplist_delete(&list, 3);
//    skiplist_delete(&list, 9);
//    skiplist_dump(&list);
//    skplist_levelprint();
    
//    skiplist_free(&list);
//    printf("Skip List is freed\n");
    
    return 0;
}
