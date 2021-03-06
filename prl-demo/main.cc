#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Eigen/Eigen"
#include "zcore/zgaussian.h"
#include "zmapping/zmapping.h"
#include "zcore/zkalman.h"
/**
 * power - Calculate the power of number.
 * @param base: Base value.
 * @param exponent: Exponent value.
 *
 * @return base raised to the power exponent.
 */

Eigen::VectorXd fung(Eigen::VectorXd upsilon, Eigen::VectorXd mu)
{
    return upsilon+mu*10;
}
Eigen::VectorXd funh(Eigen::VectorXd mu)
{
    return mu*4;
}

int main(int argc, char *argv[])
{
    Eigen::MatrixXd sigma(3,3);
Eigen::VectorXd v(3,1);
    double x = 0;
    double mean = 0;
    //double v = 1.0;
v(0,0)=3;
    v(1,0)=1;
    v(2,0)=2;
sigma(0,0) = 3;
    sigma(1,0) = 0;
    sigma(2,0) =0;
    sigma(0,1) = 0;
    sigma(1,1) = 5.0;
sigma(2,1) = 0;
sigma(0,2) = 0;
    sigma(2,2) = 3;
sigma(1,2) = 0;
 double result = gaussianM(v*2,v,sigma);
    std::cout<<result<<std::endl;
    zmap a(1,100);
    std::cout<<a.getSum()<<std::endl;

    zkalman b(v,sigma,v,v,sigma,sigma,sigma,sigma,sigma,fung,funh,1);
    std::cout<<b.getK()<<std::endl;
    sigma(0,2) = 1000;
    b.updateK(sigma);
    std::cout<<b.g()<<std::endl;
    std::cout<<b.getmu()<<std::endl;
    b.zkalman_extended_filter();
    std::cout<<b.getmu()<<std::endl;
    return 0;
}

