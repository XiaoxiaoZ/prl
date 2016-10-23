#ifndef ZMAPPING_H
#define ZMAPPING__H

#include "Eigen/Eigen" 

class zmap
{
    int gx;
    int gy;
    int gz;

public:
    zmap(int x, int y);
    int getSum();
};

#endif

