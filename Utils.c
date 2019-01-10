#include "Utils.h"

vector2_t *PutPixel(int x, int y, int width, int heigth)
{
    vector2_t *vector2 = malloc(sizeof(vector2_t));

    vector2->x = width == 0 ? 0 : ((float)x / (float)width) * 2 - 1;
    vector2->y = heigth == 0 ? 0 : ((float)y / (float)heigth) * 2 - 1;

    return vector2;
}

int InRange(float val, float equal, float error)
{
    return fabs(val - equal) <= error;
}