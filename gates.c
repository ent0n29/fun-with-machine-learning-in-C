#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//definining sigmoid function
float sigmoidf(float x)
{
    return 1.f / (1.f + expf(-x));
}

// implementing an OR-gate
float train[][3] = {
    {0,0,0},
    {1,0,1},
    {0,1,1},
    {1,1,1},
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void)
{
    return (float) rand()/ (float) RAND_MAX;
}

//cost function
float cost(float w1, float w2){
   float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i){
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = sigmoidf(x1*w1 + x2*w2);
        float d = y - train[i][2];
        result += d*d;
    } 
    result /= train_count;
    return result;
}

int main(void)
{
    srand(time(0));
    float eps = 1e-2;
    float rate = 1e-2;
    float w1 = rand_float()*10 - 5;
    float w2 = rand_float()*10 - 5;
for (size_t i = 0; i < 1 ; ++i){
    float c = cost(w1, w2);
    printf("w1 = %f, w2 = %f, c = %f\n", w1, w2, c);
    float dw1 = (cost(w1+ eps, w2) - c)/eps;
    float dw2 = (cost(w1, w2 + eps) - c)/eps;
    w1 -= rate*dw1;
    w2 -= rate*dw2;
}
printf("w1 = %f, w2 = %f, c = %f\n", w1, w2, cost(w1, w2));

for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            printf("%zu | %zu = %f\n", i, j, sigmoidf(i*w1 + j*w2));
        }
    }

return 0;


}