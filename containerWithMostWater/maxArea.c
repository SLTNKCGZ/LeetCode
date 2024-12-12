#include <stdio.h>
#include <stdlib.h>

int maxArea(int *height, int heightSize)
{
    int max = 0;

    for (int i = 0; i < heightSize; i++)
    {
        int n1 = *(height + i);

        for (int j = i + 1; j < heightSize; j++)
        {
            int n2 = *(height + j);

            int product;
            if (n1 < n2)
            {
                product = n1 * (j - i);
            }
            else
            {
                product = n2 * (j - i);
            }
            if (max < product)
            {
                max = product;
            }
        }
    }
    return max;
}
int main()
{
    int heightArray[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int *height = (int *)malloc((sizeof(heightArray) / sizeof(int)) * sizeof(int));
    height = heightArray;
    int product = maxArea(height, sizeof(heightArray) / sizeof(int));
    printf("%d", product);
    return 0;
}