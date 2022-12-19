#include <stdio.h>
int Calc(char *exp){
    if(exp[1] == '='){
        if(exp[2]=='x'){
            switch(exp[3]){
                case '*' : return ((exp[0]-48)/(exp[4]-48));//
                case '/' : return ((exp[0]-48)*(exp[4]-48));
                case '%' : return ((exp[0]-48)+(exp[4]-48));
                case '+' : return ((exp[0]-48)-(exp[4]-48));
                case '-' : return ((exp[0]-48)+(exp[4]-48));}
        }
        if(exp[4]=='x'){
            switch(exp[3]){
                case '*' : return ((exp[0]-48)/(exp[2]-48));
                case '/' : return ((exp[2]-48)/(exp[0]-48));
                case '%' : return ((exp[2]-48)-(exp[0]-48));
                case '+' : return ((exp[0]-48)-(exp[2]-48));
                case '-' : return ((exp[2]-48)-(exp[0]-48));}
        }
        if(exp[0]=='x'){
            switch(exp[3]){
                case '*' : return ((exp[2]-48)*(exp[4]-48));
                case '/' : return ((exp[2]-48)/(exp[4]-48));
                case '%' : return ((exp[2]-48)%(exp[4]-48));
                case '+' : return ((exp[4]-48)+(exp[4]-48));
                case '-' : return ((exp[2]-48)-(exp[4]-48));}
        }
    }
    if(exp[3]=='='){
        if(exp[2]=='x'){
            switch(exp[1]){
                case '*' : return ((exp[4]-48)/(exp[0]-48));
                case '/' : return ((exp[0]-48)/(exp[4]-48));
                case '%' : return ((exp[0]-48)-(exp[4]-48));
                case '+' : return ((exp[4]-48)-(exp[0]-48));
                case '-' : return ((exp[0]-48)-(exp[4]-48));}
        }
        if(exp[4]=='x'){
            switch(exp[1]){
                case '*' : return ((exp[0]-48)*(exp[2]-48));
                case '/' : return ((exp[0]-48)/(exp[2]-48));
                case '%' : return ((exp[0]-48)%(exp[2]-48));
                case '+' : return ((exp[0]-48)+(exp[2]-48));
                case '-' : return ((exp[0]-48)-(exp[2]-48));}
        }
        if(exp[0]=='x'){
            switch(exp[1]){
                case '*' : return ((exp[4]-48)/(exp[2]-48));
                case '/' : return ((exp[4]-48)*(exp[2]-48));
                case '%' : return ((exp[4]-48)+(exp[2]-48));
                case '+' : return ((exp[4]-48)-(exp[2]-48));
                case '-' : return ((exp[4]-48)+(exp[2]-48));}
        }
    }
    return 0;
}




int main(){
    char *expression[] = {"2+x=5","x+2=5","x-5=2","5-x=2","x=5*2","x*3=6","9*9=x","x=9/3","x/2=5","8/x=2","8=4*x","3=x+6","9=6-x"};
    int len = sizeof(expression)/sizeof(char *);
    for(int i=0;i<len;i++){
        printf(" %s x=%d\n",expression[i],Calc(expression[i]));
    }
    return 0;
}