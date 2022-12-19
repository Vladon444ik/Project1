#include <stdio.h>
#include <math.h>

double polynom(const char *expr, double x){
    double y = 0.0;
    int i = 0;
    //printf("1");
    while(expr[i] != '\0'){
        //printf("2");
        int znak = 1;
        int chislo = 0;
        while((expr[i] < '0') || (expr[i] > '9')){
            //printf("3");
            if(expr[i] == '-')
                znak = -1;
            i+=1;
        }
        //printf("4");
        while((expr[i] >= '0') && (expr[i] <= '9')){
            //printf("5");
            chislo = chislo*10 + (expr[i]-'0');
            i+=1;
        }
        //printf("6");
        if(expr[i] != '\0'){
            if(expr[i+1] == '^'){
                int step = expr[i+2]-'0';
                y += znak*chislo*pow(x,step);
            }
            else{
                if(expr[i] == 'x')
                    y += znak*chislo*x;
                }
        }
        else
            y += znak*chislo;

        //printf("%d ",'+');

        if(expr[i] == '\0')
            break;
        //i+=1;
        //printf("7");
    }
    //printf("8");
    printf("\n%f",y);
    return 0;
}

int main(){
    const char *expr = "-x^4 + 50";
    double x = 2.0;
    polynom(expr, x);
    return 0;
}