#include <stdio.h>
#define kol 4
int main(int argc, char *argv[])
{
    int mas[kol][kol] = {0};
    int s = 1;

    for (int i = 0; i < kol;i++){
        for (int j = 0; j < kol;j++){
            mas[i][j] = s;
            s++;
        }
    }
//КОД НЕ РАБОТАЕТ, Я ТАК И НЕ ДОДУМАЛСЯ.
    int lin = 0;
    int diag = 0;
    int schet = 1;

   for (int i = 0; i < kol;i++){
        for (int j = 0; j < kol;j++){
            int nomer = 0;
            int stroka = 0;

            if (nomer != j && stroka != i){
                if (lin%2 == 0){
                    stroka += 1;
                    lin += 1;
                    schet += 1;

                }
                else{
                    nomer += 1;
                    lin += 1;
                    schet += 1;

                }


                if (diag%2 == 0){
                    diag += 1;
                    while(stroka != 0){
                        stroka -= 1;
                        nomer += 1;
                        schet += 1;
                    }
                }
                else{
                    diag += 1;
                    while(nomer != 0){
                        stroka += 1;
                        nomer -= 1;

                        schet += 1;
                    }
                }

            }
            printf("%2.0d",schet);
            schet = 1;

        }
        printf("\n");
    }
    return 0;
}
