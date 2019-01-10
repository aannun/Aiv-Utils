#include "aiv_unit_test.h"
#include "Utils.h"

TEST(in_range)
{
    float value = 5.001;
    float equal = 5;

    ASSERT_THAT(InRange(value, equal, 0.01) == 1);
    ASSERT_THAT(InRange(value, equal, 0.0001) == 0);
}

TEST(in_range_negative)
{
    float value = -4.999;
    float equal = -5;

    ASSERT_THAT(InRange(value, equal, 0.01) == 1);
    ASSERT_THAT(InRange(value, equal, 0.0001) == 0);
}

TEST(put_pixels_half)
{
    vector2_t *vector2 = PutPixel(300, 300, 600, 600);

    ASSERT_THAT(InRange(vector2->x, 0, 0.0001));
    ASSERT_THAT(InRange(vector2->y, 0, 0.0001));

    free(vector2);
}

TEST(put_pixels_min)
{
    vector2_t *vector2 = PutPixel(0, 0, 600, 600);

    ASSERT_THAT(InRange(vector2->x, -1, 0.0001));
    ASSERT_THAT(InRange(vector2->y, -1, 0.0001));

    free(vector2);
}

TEST(put_pixels_max)
{
    vector2_t *vector2 = PutPixel(600, 600, 600, 600);

    ASSERT_THAT(InRange(vector2->x, 1, 0.0001));
    ASSERT_THAT(InRange(vector2->y, 1, 0.0001));

    free(vector2);
}

TEST(put_pixels_zero)
{
    vector2_t *vector2 = PutPixel(600, 600, 0, 0);

    ASSERT_THAT(InRange(vector2->x, 0, 0.0001));
    ASSERT_THAT(InRange(vector2->y, 0, 0.0001));

    free(vector2);
}

int main(int argc, char const *argv[])
{
    RUN_TEST(in_range);
    RUN_TEST(in_range_negative);
    RUN_TEST(put_pixels_half);
    RUN_TEST(put_pixels_min);
    RUN_TEST(put_pixels_max);
    RUN_TEST(put_pixels_zero);

    PRINT_TEST_RESULTS();
    return 0;
}
