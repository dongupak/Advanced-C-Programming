//
//  main.c
//  BadReadability
//
//  Created by DongGyu Park on 2016. 4. 19..
//  Copyright © 2016년 ProfPark. All rights reserved.
//

#include <stdio.h>

void my_strcat(char *s, char *t);

void my_strcat(char *s, char *t) {
    while (*s++ != '\0');
    s--;
    while (*t != '\0')
        *s++ = *t++;
    
    *--t = '\0';
}

int main() {
    char str1[100] = "Hey, hello. ";
    char str2[100] = "How are you?";
    
    my_strcat(str1, str2);
    
    printf("%s\n", str1);
    return 0;
}