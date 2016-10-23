#include "zkalman.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;

zkalman::zkalman(VectorXd mu0, MatrixXd sigma0, VectorXd upsilon0, VectorXd zeta0, MatrixXd A0, MatrixXd B0, MatrixXd C0, MatrixXd K0, MatrixXd R0, MatrixXd Q0, int kalman)
{
    mu = mu0;
    sigma = sigma0;
    upsilon = upsilon0;
    zeta = zeta0;
    A = A0;
    B = B0;
    C = C0;
    K = K0;
    R = R0;
    Q = Q0;
    kalman_type = kalman;
}

zkalman::zkalman(VectorXd mu0, MatrixXd sigma0, VectorXd upsilon0, VectorXd zeta0, MatrixXd G0, MatrixXd H0, MatrixXd K0, MatrixXd R0, MatrixXd Q0, Eigen::VectorXd(*g_func0)(Eigen::VectorXd, Eigen::VectorXd), Eigen::VectorXd(*h_func0)(Eigen::VectorXd), int kalman)
{
    mu = mu0;
    sigma = sigma0;
    upsilon = upsilon0;
    zeta = zeta0;
    G = G0;
    H = H0;
    K = K0;
    R = R0;
    Q = Q0;
    g_func = g_func0;
    h_func = h_func0;
    kalman_type = kalman;
}

Eigen::VectorXd zkalman::g()
{
    return this->g_func(this->upsilon,this->mu);
}

Eigen::VectorXd zkalman::h()
{
    return this->h_func(this->_mu);
}

void zkalman::zkalman_filter()
{
    this->_mu = this->A * this->mu + this->B * this->upsilon;
    this->_sigma = this->A * this->sigma * this->A.transpose() + R;
    this->K = this->_sigma * this->C.transpose() * (this->C * this->_sigma * this->C.transpose() + this->Q).inverse();
    this->mu = this->_mu + this->K * (this->zeta - this->C * this->_mu);
    MatrixXd temp = this->K * this->C;
    this->sigma = (MatrixXd::Identity(temp.rows(),temp.cols()) - temp) * this->_sigma;
}

void zkalman::zkalman_extended_filter()
{
    this->_mu=this->g();
    this->_sigma = this->G * this->sigma * this->G.transpose() + R;
    this->K = this->_sigma * this->H.transpose() * (this->H * this->_sigma * this->H.transpose() + this->Q).inverse();
    this->mu = this->_mu + this->K * (this->zeta - this->h());
    MatrixXd temp = this->K * this->H;
    this->sigma = (MatrixXd::Identity(temp.rows(),temp.cols()) - temp) * this->_sigma;
}

void zkalman::updatemu(VectorXd mut)
{
    this->mu = mut;
}

void zkalman::updatesigma(MatrixXd sigmat)
{
    this->sigma = sigmat;
}

void zkalman::updateupsilon(VectorXd upsilont)
{
    this->upsilon = upsilont;
}

void zkalman::updatezeta(VectorXd zetat)
{
    this->zeta = zetat;
}

void zkalman::updateA(MatrixXd At)
{
    this->A = At;
}

void zkalman::updateB(MatrixXd Bt)
{
    this->B = Bt;
}

void zkalman::updateC(MatrixXd Ct)
{
    this->C = Ct;
}

void zkalman::updateK(MatrixXd Kt)
{
    this->K = Kt;
}

void zkalman::updateR(MatrixXd Rt)
{
    this->R = Rt;
}

void zkalman::updateQ(MatrixXd Qt)
{
    this->Q = Qt;
}

void zkalman::updateG(Eigen::MatrixXd Gt)
{
    this->G = Gt;
}

void zkalman::updateH(Eigen::MatrixXd Ht)
{
    this->H = Ht;
}

VectorXd zkalman::getmu()
{
    return this->mu;
}

MatrixXd zkalman::getsigma()
{
    return this->sigma;
}

VectorXd zkalman::getupsilon()
{
    return this->upsilon;
}

VectorXd zkalman::getzeta()
{
    return this->zeta;
}

MatrixXd zkalman::getA()
{
    return this->A;
}

MatrixXd zkalman::getB()
{
    return this->B;
}

MatrixXd zkalman::getC()
{
    return this->C;
}

MatrixXd zkalman::getK()
{
    return this->K;
}

MatrixXd zkalman::getR()
{
    return this->R;
}

MatrixXd zkalman::getQ()
{
    return this->Q;
}

MatrixXd zkalman::getG()
{
    return this->G;
}

MatrixXd zkalman::getH()
{
    return this->H;
}