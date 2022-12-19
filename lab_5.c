#define M_PI
#include <stdio.h>
#include <math.h>

float traverse_clockwise(float coord[], int n){
    float x_sr = 0;
    float y_sr = 0;
    for(int i = 0;i<n;i+=2){
        x_sr += coord[i];
        y_sr += coord[i+1];
    }
    //находим среднюю точку(равноудалённую от всех) 
    x_sr = x_sr/(n/2);
    y_sr = y_sr/(n/2);
    //относительно первой точки в массиве будем искать углы для каждой другой точки от неё
    float x_nach = coord[0];
    float y_nach = coord[1];
    double mas[100] = {};
    for(int i = 0; i < n;i+=2){
        //находим значение косинуса через формулу потом через аркосинус находим сам угол
        double ygol = (((x_nach-x_sr)*(coord[i]-x_sr)+(y_nach-y_sr)*(coord[i+1]-y_sr))/(sqrt((x_nach-x_sr)*(x_nach-x_sr) + (y_nach-y_sr)*(y_nach-y_sr))*sqrt((coord[i]-x_sr)*(coord[i]-x_sr) + (coord[i+1]-y_sr)*(coord[i+1]-y_sr))));
        if((ygol >= 0.0)|(ygol == 1.0))
            ygol = 180.0/M_PI * acos(ygol);
        else
            ygol = 360 - 180.0/M_PI * acos(ygol);
        //записываем найденные углы в массив 
        mas[i/2] = ygol;
    }
    //сортируем углы по возрастанию(первый угол всегда будет 0, так как мы так же находим угол точки между собой)
    for(int j = 1; j < n/2;j++){
        for(int i = 0; i < n/2 - 1;i++){
            if(mas[i] > mas[i+1]){double x = mas[i]; mas[i] = mas[i+1]; mas[i+1] = x;}
        }
    }
    float x_0 = coord[0];
    float y_0 = coord[1];
    float perimetr = 0.0;
    float ras = 0;
    //теперь опять относительно первой точки в массиве будем находить углы.
    for(int j = 0; j < n/2;j++){
        for(int i = 0; i < n;i+=2){
            double ygol = (((x_nach-x_sr)*(coord[i]-x_sr)+(y_nach-y_sr)*(coord[i+1]-y_sr))/(sqrt((x_nach-x_sr)*(x_nach-x_sr) + (y_nach-y_sr)*(y_nach-y_sr))*sqrt((coord[i]-x_sr)*(coord[i]-x_sr) + (coord[i+1]-y_sr)*(coord[i+1]-y_sr))));
            if((ygol >= 0.0)|(ygol == 1.0))
                ygol = 180.0/M_PI * acos(ygol);
            else
                ygol = 360 - 180.0/M_PI * acos(ygol);
            //если найденный угол совпадает с углом, из массива с углами
            if(ygol == mas[j]){
                //то находим расстояние между точками
                ras = sqrt( (coord[i] - x_0)*(coord[i] - x_0) + (coord[i+1] - y_0)*(coord[i+1] - y_0) );
                //дальше меняем координаты точки, на координаты точкки с которой совпал угол
                x_0 = coord[i];
                y_0 = coord[i+1];
                break;
            }
        }
        perimetr += ras;
    }
    //находим расстояние между начальной координатой в массиве и последней точки, у которой угол был наибольшим
    perimetr += sqrt( (coord[0] - x_0)*(coord[0] - x_0) + (coord[1] - y_0)*(coord[1] - y_0) );
    return perimetr;
}

int main(){
    float rect[] = {1,5,7,1,7,5,1,1};
    int n = sizeof(rect)/sizeof(float);
    printf("%f",traverse_clockwise(rect,n));
}