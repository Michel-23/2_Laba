#include <iostream>
#include <cmath>
using namespace std;

int cif(float a){ // функция для подсчета количества чисел после запятой
    float eps = 0.00001;
    int c = 0;
    while (fabs(a - static_cast<int>(a)) > eps && fabs(a) > eps){
        a*=10;
        c++;
    }
    return c;
}

int main(){
    float a=5.23;
    int deltal = cif(a);
    //cout << deltal << endl;

    int ten;
    if (deltal!=0){
        ten = pow (10, deltal);
    }
    else{
        ten = 1;
    }
    a=a*ten;
    cout << a << "/" << ten << endl;
    return 0;
}