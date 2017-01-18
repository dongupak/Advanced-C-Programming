//
//  main.c
//  ScoreArray
//
//  Created by DongGyu Park on 2016. 4. 25..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, size = 3;
    double value, total=0.0;
    double *scores;
    scores = (double *)malloc(size*sizeof(double));
    
    for(i=0;i<size;i++) {
        printf("성적을 입력하시오 : ");
        scanf("%lf", &value);
        *(scores+i) = value;
        {
        }
    }
   
    for(i=0;i<size;i++){
       total += scores[i];
    }

    printf("평균: %f\n", total/size);
    free(scores);
    return 0;
}
