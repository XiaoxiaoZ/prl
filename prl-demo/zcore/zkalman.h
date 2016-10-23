#ifndef ZCORE_KALMAN_H
#define ZCORE_KALMAN_H

#include "Eigen/Eigen" 
#include <iostream>

class zkalman
{
private:
    Eigen::VectorXd mu;
    Eigen::MatrixXd sigma;
    Eigen::VectorXd upsilon;
    Eigen::VectorXd zeta;
    Eigen::MatrixXd A;
    Eigen::MatrixXd B;
    Eigen::MatrixXd C;
    Eigen::MatrixXd K;
    Eigen::MatrixXd R;
    Eigen::MatrixXd Q;
    Eigen::MatrixXd G;
    Eigen::MatrixXd H;
    Eigen::VectorXd _mu;
    Eigen::MatrixXd _sigma;
    Eigen::VectorXd(*g_func)(Eigen::VectorXd, Eigen::VectorXd);
    Eigen::VectorXd(*h_func)(Eigen::VectorXd);
    int kalman_type;

public:
    zkalman(Eigen::VectorXd mu0, Eigen::MatrixXd sigma0, Eigen::VectorXd upsilon0, Eigen::VectorXd zeta0, Eigen::MatrixXd A0, Eigen::MatrixXd B0, Eigen::MatrixXd C0, Eigen::MatrixXd K0, Eigen::MatrixXd R0, Eigen::MatrixXd Q0, int kalman);
    zkalman(Eigen::VectorXd mu0, Eigen::MatrixXd sigma0, Eigen::VectorXd upsilon0, Eigen::VectorXd zeta0, Eigen::MatrixXd G0, Eigen::MatrixXd H0, Eigen::MatrixXd K0, Eigen::MatrixXd R0, Eigen::MatrixXd Q0,Eigen::VectorXd(*g_func0)(Eigen::VectorXd, Eigen::VectorXd), Eigen::VectorXd(*h_func0)(Eigen::VectorXd), int kalman);
    Eigen::VectorXd g();
    Eigen::VectorXd h();
    void zkalman_filter();
    void zkalman_extended_filter();
    void updatemu(Eigen::VectorXd mut);
    void updatesigma(Eigen::MatrixXd sigmat);
    void updateupsilon(Eigen::VectorXd upsilont);
    void updatezeta(Eigen::VectorXd zetat);
    void updateA(Eigen::MatrixXd At);
    void updateB(Eigen::MatrixXd Bt);
    void updateC(Eigen::MatrixXd Ct);
    void updateK(Eigen::MatrixXd Kt);
    void updateR(Eigen::MatrixXd Rt);
    void updateQ(Eigen::MatrixXd Qt);
    void updateG(Eigen::MatrixXd Gt);
    void updateH(Eigen::MatrixXd Ht);
    Eigen::VectorXd getmu();
    Eigen::MatrixXd getsigma();
    Eigen::VectorXd getupsilon();
    Eigen::VectorXd getzeta();
    Eigen::MatrixXd getA();
    Eigen::MatrixXd getB();
    Eigen::MatrixXd getC();
    Eigen::MatrixXd getK();
    Eigen::MatrixXd getR();
    Eigen::MatrixXd getQ();
    Eigen::MatrixXd getG();
    Eigen::MatrixXd getH();
};
#endif