//
//  main.c
//  PointerOp1
//
//  Created by DongGyu Park on 2016. 4. 20..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int *myPointer;
    int myVar = 10;
    
    printf("myVar = %d\n", myVar);
    myPointer = &myVar;
    
    *myPointer = 20;
    printf("\n*myPointer = 20으로 변경 \n");
    printf("myVar = %d\n", myVar);
    
    return 0;
}
