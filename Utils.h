#include <stdlib.h>
#include <math.h>

typedef struct vector2 
{
    float x;
    float y;
}vector2_t;

vector2_t *PutPixel(int x, int y, int width, int heigth);

int InRange(float val, float equal, float error);