//
//  main.c
//  Typedef-Vector
//
//  Created by DongGyu Park on 2016. 4. 20..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

typedef float Vector[2];

#include <stdio.h>

int main(int argc, const char * argv[]) {
    Vector v1;
//    Vector v1, v2;
    v1[0] = 10.0f;
    v1[1] = 10.0f;
    
    printf("v1[0] = %4.2f, v1[1] = %4.2f \n", v1[0],v1[1]);
    
//    v2 = v1;
//    
//    printf("v2[0] = %4.2f, v2[1] = %4.2f \n", v2[0],v2[1]);
    return 0;
}
