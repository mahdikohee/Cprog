//A simple code example of void and pointer ;
#include<stdio.h>
int main(void){
    int number = 120 ;
    void *ptr = &number ;
    printf("Your number is %d\n" , *(int *)ptr) ;
    return 0 ;
}
