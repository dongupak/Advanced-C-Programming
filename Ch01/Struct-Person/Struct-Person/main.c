#include <stdio.h>
#include <string.h>

// 구조체 정의
// Person은 struct 태그(식별하기 위한 이름)
struct Person {         // Person 구조체 선언
    char name[100];     // 구조체 멤버-이름
    int age;            // 구조체 멤버-나이
    int height;         // 구조체 멤버-키
    float weight;       // 구조체 멤버-몸무게
};

int main()
{
    struct Person personA, personB;
    
    personA.age = 24;
    strcpy(personA.name,"Hong GilDong");
    personA.height = 179;
    
    personB.age = 23;
    strcpy(personB.name,"Hong GilSun");
    personB.height = 170;
    
    struct Person personC = {"Park", 40, 174, 66};
    printf("personC의 이름 %s, 나이 = %d\n", personC.name, personC.age);
    
    return 0;
}