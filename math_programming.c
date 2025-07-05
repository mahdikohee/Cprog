//A basic math programming example 
#include<stdio.h>
#include<math.h>
int main(void){
    double value[] = {12.0323 , 3.332233 , 83493.34323 , -3423.3423 , -3.322334} ;
    int n = sizeof(value) / sizeof(value[0]) ;
    for(int i = 0 ; i < n ; i++){
        printf("Main value is %4f\n" , value[i]) ;
        printf("Floor of val is :%4f\n" ,floor(value[i])) ;
        printf("Floor of val is :%4f\n" , ceil(value[i])) ;
    }
    return 0 ;
}
 
