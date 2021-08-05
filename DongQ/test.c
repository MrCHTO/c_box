#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,d,e,sum;
    float g,f;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    sum=a+b+c+d+e;
    g=sum/5;
    f=(powf((a-g),2.0)+powf((b-g),2.0)+powf((c-g),2.0)+powf((d-g),2.0)+powf((e-g),2.0))/5.0;
    printf("%f%f",g,f);
}