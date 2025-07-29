#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
 
float A,B,C;
float Cubewidth = 15;
int width=160, height = 44;
float zbuffer[160 * 44];
char buffer[160*44];
int backgroundASCIIcode = ' ';
int distancefromcam = 60;
float incrementspeed = 4;

float x,y,z;
float ooz;
int xp,yp;
int idx;
float k1 = 30;

float calculateX(int i, int j, int k){
    return j*sin(A)*sin(B)*cos(C) - k*cos(A)*sin(B)*cos(C)+j*cos(A)*sin(C)+k*sin(A)*sin(C)+i*cos(B)*cos(C);
};

float CalculateY(int i, int j, int k){
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) - j * sin(A) * sin(B) * sin(C) + k * cos(A) *sin(B) *sin(C) - i*cos(B) *sin(C);
};

float CalculateZ(int i, int j, int k){
    return k*cos(A)*cos(B)-j*sin(A)*cos(B)+i*sin(B);
};

void calculateforSurface(float cubeX,float cubeY, float cubeZ, int ch){
    x = calculateX(cubeY,cubeX,cubeZ);
    y = CalculateY(cubeY,cubeX,cubeZ);
    z = CalculateZ(cubeY,cubeX,cubeZ) + distancefromcam;

    ooz = 1/z;
    xp = (int)(width/2 + k1 * ooz * x * 2);
    yp = (int)(height/2 + k1 * ooz * y);

    idx = xp + yp * width;
    if(idx >= 0 && idx < width* height){
        if(ooz > zbuffer[idx]){
            zbuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}


int main(){
    printf("\x1b[2J");
    while(1){
        memset(buffer, backgroundASCIIcode, width*height);
        memset(zbuffer, 0, width*height*4);
        for(float cubeX = - Cubewidth; cubeX < Cubewidth; cubeX += incrementspeed){
            for(float cubeY = - Cubewidth; cubeY < Cubewidth; cubeY += incrementspeed){
            calculateforSurface(cubeX,cubeY,-Cubewidth, '*');
            calculateforSurface(Cubewidth, cubeY, cubeX, '$');
            calculateforSurface(-Cubewidth,cubeY,cubeX, '~');
            calculateforSurface(-cubeX,cubeY,Cubewidth, '?');
            calculateforSurface(cubeX,-Cubewidth,-cubeY, '#');
            calculateforSurface(cubeX, Cubewidth,cubeY, '+');
            }
        }
        printf("\x1b[H");
        for(int k = 0; k < width * height; k++){
            putchar(k % width ? buffer[k] : 10);
        }
        A+=0.005; 
        B+=0.005;
        usleep(1000);
    }
    return 0;
}