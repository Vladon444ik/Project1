#include <stdio.h>


void main1(){
    int mas[8] = {-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    long int mas16[14][14]={0};
    for(int i = 3;i<11;i++){
        int ch = mas[i-3];
        int j = 0;
        while (ch!=0){
            int chis = 0;
            if (ch<0){
                chis = ((ch%16)+15)%16;
                ch = ch/16;
            }
            else{
                chis = ch%16;
                ch = ch/16;
            }
            mas16[i][10-j]= chis;
            j+=1;
            
        }
    }
    int kol = 0;
    for(int i = 3;i<11;i++){
        for(int j = 3;j<11;j++){
            if(mas16[i][j] == 10){
                if((mas16[i][j+1]==11)&&(mas16[i+1][j+1]==11)&&(mas16[i+1][j+2]==10)) {kol +=1;printf("1%d %d\n",i,j);}//1
                if((mas16[i][j+1]==11)&&(mas16[i-1][j+1]==11)&&(mas16[i-1][j+2]==10)) {kol +=1;printf("2%d %d\n",i,j);}//2
                if((mas16[i+1][j]==11)&&(mas16[i+1][j+1]==11)&&(mas16[i+2][j+1]==10)) {kol +=1;printf("3%d %d\n",i,j);}//3
                if((mas16[i+1][j]==11)&&(mas16[i+1][j-1]==11)&&(mas16[i+2][j-1]==10)) {kol +=1;printf("4%d %d\n",i,j);}//4
                if((mas16[i][j+1]==11)&&(mas16[i][j+2]==11)&&(mas16[i][j+3]==10)) {kol +=1;printf("5%d %d\n",i,j);}//5
                if((mas16[i+1][j]==11)&&(mas16[i+2][j]==11)&&(mas16[i+3][j]==10)) {kol +=1;printf("6%d %d\n",i,j);}//6
                if((mas16[i][j+1]==11)&&(mas16[i+1][j+1]==11)&&(mas16[i+2][j+1]==10)) {kol +=1;printf("7%d %d\n",i,j);}//7
                if((mas16[i][j-1]==11)&&(mas16[i+1][j-1]==11)&&(mas16[i+2][j-1]==10)) {kol +=1;printf("8%d %d\n",i,j);}//8
                if((mas16[i+1][j]==11)&&(mas16[i+2][j]==11)&&(mas16[i+2][j-1]==10)) {kol +=1;printf("9%d %d\n",i,j);}//9
                if((mas16[i+1][j]==11)&&(mas16[i+2][j]==11)&&(mas16[i+2][j+1]==10)) {kol +=1;printf("10%d %d\n",i,j);}//10
                if((mas16[i][j+1]==11)&&(mas16[i][j+2]==11)&&(mas16[i+1][j+2]==10)) {kol +=1;printf("11%d %d\n",i,j);}//11
                if((mas16[i][j+1]==11)&&(mas16[i][j+2]==11)&&(mas16[i-1][j+2]==10)) {kol +=1;printf("12%d %d\n",i,j);}//12
                if((mas16[i-1][j]==11)&&(mas16[i-1][j+1]==11)&&(mas16[i-1][j+2]==10)) {kol +=1;printf("13%d %d\n",i,j);}//13
                if((mas16[i+1][j]==11)&&(mas16[i+1][j+1]==11)&&(mas16[i+1][j+2]==10)) {kol +=1;printf("14%d %d\n",i,j);}//14
            }
            //printf("%%d %d\n1,i,jd ",mas16[i][j]);
        }//printf("\%d %d\n),i,j;
    }
    printf("%d",kol);
}
int main(){
    main1();
    return 0;
}



/*
            char isxod;
            if(chis < 10){
                isxod = chis+48;
                //printf("%%d %d\n",i,j,isxod);
                mas16[i][8-j]= isxod;
                //printf("%%d %d\n,,i,jmas16[i][8-j]);
                j+=1;
            }
            else {isxod = chis+55;
                //printf("%%d %d\n",i,j,isxod);
                mas16[i][8-j]= isxod;
                //printf("%%d %d\n,,i,jmas16[i][8-j]);
                j+=1;
            } 
            */