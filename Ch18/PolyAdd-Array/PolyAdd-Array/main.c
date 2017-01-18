//
//  main.c
//  PolyAdd-Array
//
//  Created by DongGyu Park on 2016. 7. 13..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define MAX_DEGREE  101

// 다항식의 계수와 차수를 저장하는 구조체
typedef struct polynomial
{
    float coef;
    int expo;
} polynomial;

int main()
{
    int i;
    int deg1, deg2;      // 다항식의 최고차수를 저장
    int k=0, l=0, m=0;
    
    // 세 다항식의 선언
    polynomial p1[MAX_DEGREE], p2[MAX_DEGREE], p3[MAX_DEGREE];
    
    printf("다항식1의 최고차수를 입력하라 :");
    scanf("%d",&deg1);
    
    // 사용자로부터 x^0...x^n 항의 계수를 입력받는다
    for(i=0;i<=deg1;i++)
    {
        // x^i 항의 계수값을 입력하시오
        printf("x^%d 의 계수를 입력하시오 :",i);
        scanf("%f",&p1[i].coef);
        // 다항식의 차수값을 저장
        p1[k++].expo = i;
    }
    
    // 두번째 다항식을 입력받는다
    printf("\n다항식2의 최고차수를 입력하라 :");
    scanf("%d",&deg2);
    
    for(i=0;i<=deg2;i++)
    {
        printf("x^%d 의 계수를 입력하시오 :",i);
        scanf("%f",&p2[i].coef);
        p2[l++].expo = i;
    }
    
    // 첫번째 다항식을 출력함
    printf("\n다항식 1 = %.1f",p1[0].coef);
    for(i=1;i<=deg1;i++)
        printf("+ %.1fx^%d",p1[i].coef,p1[i].expo);
    
    // 두번째 다항식을 출력
    printf("\n다항식 2 = %.1f",p2[0].coef);
    for(i=1;i<=deg2;i++)
        printf("+ %.1fx^%d",p2[i].coef,p2[i].expo);
    
    // 두 다항식의 합을 계산
    // 첫 다항식의 최고차항의 차수가 클 경우
    if( deg1 > deg2 )
    {
        for(i=0;i<=deg2;i++) // 0차 항부터-두번째 항의 최고차항까지 계수를 더함
        {
            p3[m].coef = p1[i].coef + p2[i].coef;
            p3[m].expo = p1[i].expo;
            m++;
        }
        for(i=deg2+1;i<=deg1;i++)  // 첫번째 항의 최고차 항까지 복사
        {
            p3[m].coef = p1[i].coef;
            p3[m].expo = p1[i].expo;
            m++;
        }
    }
    else // 두번째 다항식의 최고차항이 더 크거나 같을 경우
    {
        for(i=0;i<=deg1;i++)
        {
            p3[m].coef = p1[i].coef + p2[i].coef;
            p3[m].expo = p1[i].expo;
            m++;
        }
        for(i=deg1+1;i<=deg2;i++)
        {
            p3[m].coef = p2[i].coef;
            p3[m].expo = p2[i].expo;
            m++;
        }
    }
    
    // 두 다항식의 합을 출력
    printf("\n두 수식의 합  = %.1f",p3[0].coef);
    for(i=1;i<m;i++)
            printf(" + %.1fx^%d",p3[i].coef,p3[i].expo);

    printf("\n");
    
    return 0;
}