#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//building the model

float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void)
{
    return (float) rand()/ (float) RAND_MAX;
}

//this is called "cost function"
//where y is the output of the neuron 
//and x1..xn the inputs
//y = x1*w1 + x2*w2 +, ... ,+ b
float cost(float w, float b){
   float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i){
        float x = train[i][0];
        float y = x*w + b;
        float d = y - train[i][1];
        result += d*d;
    } 
    result /= train_count;
    return result;
}

int main()
{
    srand(time(0));
    float w = rand_float()*10.0f;
    float b = rand_float()*5.0f;
    float eps = 1e-3;
     float rate = 1e-3;
    /*
    printf("%f\n", cost(w));

    here the model is getting worse

    printf("%f\n", cost(w + eps));

    let's try another direction

    printf("%f\n", cost(w - eps));

    here it's getting better and better!

    printf("%f\n", cost(w - eps*2));

    we need to differenciate the cost function */


    printf("%f\n", cost(w, b));
for (size_t i = 0; i < 500; ++i){
    float c = cost(w, b);
    float dw = (cost(w + eps, b) - c)/eps;
    float db = (cost(w, b + eps) - c)/eps;
    w -= rate*dw;
    b -= rate*db; 
    printf("cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
}
printf("---------------------------------\n");
printf("w = %f, b = %f\n", w, b);

    return 0;
}