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

float cost(float w){
   float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i){
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
    } 
    result /= train_count;
    return result;
}

int main()
{
    //srand(time(0));
    srand(69);
    float w = rand_float()*10.0f;
    float eps = 1e-3;
    /*
    printf("%f\n", cost(w));

    here the model is getting worse

    printf("%f\n", cost(w + eps));

    let's try another direction

    printf("%f\n", cost(w - eps));

    here it's getting better and better!

    printf("%f\n", cost(w - eps*2));

    we need to differenciate the cost function */

    float dcost = (cost(w + eps) - cost(w))/eps;
    float rate = 1e-3;
    printf("%f\n", cost(w));
    w -= rate*dcost;
    printf("%f\n", cost(w));


    return 0;
}