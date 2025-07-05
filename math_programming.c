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

//another simple example of power and round method fucntion 
#include <stdio.h>
#include <math.h>

int main(void){
    int base = 2;
    int exponant = 3;

    double result = pow((double)base, (double)exponant);
    int rounded_result = (int)round(result);  // <-- safer casting using round()
//Use round method to auto avoid .9999999999 .....0.99999 this types of diffirence hell 
    printf("Result is %d\n", rounded_result);

    return 0;
}

------//did you know that ?
double num = 3.1415926535;

printf("|%4f|\n", num);   // width min 4, precision default 6
printf("|%.4f|\n", num);  // precision exactly 4

------//a simple example of squire     
#include<stdio.h>
#include<math.h>
int main(void){
    int number = 44 ;
    double  result = sqrt((double)number) ;
    printf("Result is :%4f\n" , result) ;
    return 0 ;
}
