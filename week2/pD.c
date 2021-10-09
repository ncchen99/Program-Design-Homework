#include<stdio.h>
#include<math.h>
#define PI 3.14f

int main(void){
    float a;
    scanf("%f", &a);
    printf("%.2f %.2f", a*a*PI, 2*a*PI);
}
