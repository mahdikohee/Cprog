//A simple code example of void and pointer ;
#include<stdio.h>
int main(void){
    int number = 120 ;
    void *ptr = &number ;
    printf("Your number is %d\n" , *(int *)ptr) ;
    return 0 ;
}

//another c code example of void , ptr , struct and typedef 
#include<stdio.h>
typedef struct{
    char name[20] ;
    int age ;
}Person ;

int main(void){
    Person p1 = {"kohee" , 21} ;
    void *ptr = &p1 ;
    printf("The name is %s\n" , ((Person*)ptr)->name) ;
    printf("The age is :%d\n" , ((Person*)ptr)->age) ;

}
