#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    double x[2], y[2], r[2];
    int t, i;
    double distance;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &x[0], &y[0], &r[0], &x[1], &y[1], &r[1]);
        distance = sqrt(pow(x[0] - x[1], 2.0) + pow(y[0] - y[1], 2.0));
        if (x[0] == x[1] && y[0] == y[1])
        {
            if (r[0] == r[1] && r[0] != 0)
            {
                printf("-1\n");
            }
            else if (r[0] == r[1] && r[0] == 0)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            if (distance + r[0] == r[1] || distance + r[1] == r[0] || r[0] + r[1] == distance)
            {
                printf("1\n");
            }
            else
            {
                if (distance + r[0] < r[1] || distance + r[1] < r[0] || r[0] + r[1] < distance)
                {
                    printf("0\n");
                }
                else
                {
                    printf("2\n");
                }
            }
        }
    }
}