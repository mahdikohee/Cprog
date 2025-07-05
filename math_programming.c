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
 
//A example on absolute value 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void){
    double val[] = {-1.10101  , -0.322 , -0.323433 ,4.45343434 , -3.090} ;
    int n = sizeof(val) / sizeof(val[0]) ;
    for(int i = 0 ; i < n ; i++){
        printf("The main value is %4f \n" , val[i]) ;
        printf("The absolute value is :%4f \n" , fabs(val[i])) ;
    }
    return 0 ;
}
