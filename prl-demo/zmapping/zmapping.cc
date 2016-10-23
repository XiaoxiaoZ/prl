#include "zmapping.h"

zmap::zmap(int x, int y)
{
    gx = x;
    gy = y;
    gz = 2;
}

int zmap::getSum()
{
    return gx+gy+gz;
}
