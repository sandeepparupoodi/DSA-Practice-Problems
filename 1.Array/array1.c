#include <stdio.h>
#include <string.h>

void toMartian(int n){
    char buf[64];
    int i=0;
    
    while(n>=1000){
        buf[i++] = 'R';
        n-=1000;
    }
    if(n>=900){
        buf[i++] = 'B';
        buf[i++] = 'R';
        n-=900;
    }
    if(n>=500){
        buf[i++] = 'G';
        n-=500;
    }
    if(n>=400){
        buf[i++] = 'B';
        buf[i++] = 'G';
        n-=400;
    }

    while(n>=100){
        buf[i++] = 'B';
        n-=100;
    }
    if(n>=90){
        buf[i++] = 'Z';
        buf[i++] = 'B';
        n-=90;
    }
    if(n>=50){
        buf[i++] = 'P';
        n-=50;
    }
    if(n>=40){
        buf[i++] = 'Z';
        buf[i++] = 'P';
        n-=40;
    }

    while(n>=10){
        buf[i++] = 'Z';
        n-=10;
    }
    if(n>=9){
        buf[i++] = 'B';
        buf[i++] = 'Z';
        n-=9;
    }
    if(n>=5){
        buf[i++] = 'W';
        n-=5;
    }
    if(n>=4){
        buf[i++] = 'B';
        buf[i++] = 'W';
        n-=4;
    }
    
    while(n>=1){
        buf[i++] = 'B';
        n-=1;
    }

    buf[i] = '\0';
    printf("%s\n", buf);

}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        toMartian(n);
    }
    return 0;
}