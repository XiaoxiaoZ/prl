/*
 * Function: gaussian
 *----------------------------------------
 * Calculate the gaussian based on function 
 * p(x) = (2*pi*sigma^2)^(-1/2)*exp{-1/2*(x-mu)^2/sigma^2}.
 * mu: mean
 * sigma: variance
 *========================================
 * Function: gaussianM
 *----------------------------------------
 * Calculate the gaussian based on function 
 * p(x) = det(2*pi*SIGMA)^(-0.5)*exp{-0.5*(x-mu)'*SIGMA^-1*(x-mu)}.
 * mu: mean vector
 * sigma: covariance matrix
 */
#include "zgaussian.h"
using Eigen::VectorXd;
using Eigen::MatrixXd;
#define ZPI 3.14159265358979323846

double gaussian(double x, double mu, double sigma)
{
    double p = pow(2.0*ZPI*pow(sigma,2.0),-1.0/2.0)*exp(-1.0/2.0*pow(x-mu,2.0)/pow(sigma,2.0));
    return p;
}

double gaussianM(VectorXd x, VectorXd mu, MatrixXd sigma)
{   
    double p = pow(2.0*ZPI*sigma.determinant(),-0.5)*exp(-0.5*(x-mu).transpose()*sigma.inverse()*(x-mu));
    return p;
}




