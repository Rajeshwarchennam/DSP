#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
  float X[85] = {-8.31662009587695e-13, 0.634029328751641, -0.767445067471676, 1.21423064425930, -0.398089786809545, 0.577773754381422, 0.836673932101677, -0.308971047587158, 1.58778525229245, -0.182021563971272, 1.08979021355278, 0.955496287619025 ,0.101910213188460, 1.83342544475812, -0.0328730083226371, 1.47944976553274, 0.951056516297123, 0.416799687379008, 1.91156787310481, 0.0161320533298923, 1.70710678118365, 0.801827011717968, 0.605004908232005,1.80383953270139, -0.0489434837048209, 1.75534914481212, 0.508323091823254, 0.657549842333970, 1.51612377556215, -0.220379314802769, 1.63098631369702, 0.0938778153096871, 0.587785252289410,1.07806879773563, -0.469889032770565, 1.36346871276806, -0.398089786807767,0.428535685869768, 0.539117897404445, -0.753010516576522, 1.00000000000013,-0.909928708031988, 0.226248967323822, -0.0383550418345928, -1.01612377556313, 0.598101848038048, -1.37787003224955, 0.0330716683035159, -0.587785252288216, -1.20501828135071, 0.216772751324045, -1.74119124600282, -0.101910213187831, -1.04773048637417, -1.27368995655362, -0.0924099202063116, -1.95105651629510, -0.140900308094125, -1.37037177295808, -1.19200765574847, -0.292893218816216, -1.97770261413640, -0.0638088080855569, -1.52794015341620, -0.951056516293349, -0.368309299489775, -1.81488605669931, 0.128145116048447, -1.51612377556127, -0.565315643581117, -0.324423348820114, -1.48091766063180, 0.412214747707523, -1.35396817701884, -0.0713070673777790, -0.187593110348669, -1.01612377555957, 0.747339916547638, -1.08031399754952, 0.477111137289843, -6.64924840784914e-13, -0.477111137294668, 1.08031399755176, -0.747339916547943, 1.01612377556041};

int x[85];
int fractional_bits=14;
for(int i=0;i<85;i++){
x[i]=(X[i]*(1<<fractional_bits));
}
short int Y[85];
float y[85];
for(int j=0;j<85;j++){
    Y[j]=0;
    y[j]=0;
}
Y[0] = 0.5*x[0];
Y[1] = ((0.5)*(x[1]))+((0.167)*(x[0]));
Y[2] = ((0.5)*(x[2]))+((0.167)*(x[1]+x[0]));
Y[3] = ((0.5)*(x[3]))+((0.167)*(x[2]+x[1]))+((0.25)*(x[0]));

for(int i=4;i<85;i++){
    Y[i] = ((0.5)*(x[i]))+((0.167)*(x[i-1]+x[i-2]))+((0.25)*(x[i-3]+x[i-4]));
}

for(int k=0;k<85;k++){
    y[k]=Y[k]/(float)(1<<fractional_bits);
    printf("Y[%d]=%lf\n",k,y[k]);
}
return 0;
}
