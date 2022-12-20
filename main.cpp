#include <iostream>
#include <math.h>
using namespace std;

void print (float x){
    cout << int (x*10000)/10000.0;
}

float f(float a){
    return (a*a*cos(a))+1;
}

bool verifica(float a, float b){
    if(f(a)*f(b)>=0) {
        return true;
    }
    else {
        return false;
    }
}

int main(){
    float a,b;
    do{
        cout<<"inserire estremi"<<endl;
        cin>>a>>b;
    }while(verifica(a,b));
    float x;
    float err;
    do{
        x=(a+b)/2;
        if(f(x)==0){
            break;
        } else if (!verifica(a, x)){
            b = x;
        }else{
            a = x;
        }
        err = abs((b - a) / 2);
    }while(err>=1e-6);
    print (x);
    return 0;
}
