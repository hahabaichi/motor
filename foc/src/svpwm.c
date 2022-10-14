#include "svpwm.h"

static int SectorSelect(double alpha, double beta)
{
    double A, B, C;
    A = beta;
    B = alpha*sqrt(3/4) - 0.5*beta;
    C = -alpha*sqrt(3/4) - 0.5*beta;

    int intA, intB, intC;
    intA = (A>=0) ? 1 : 0;
    intB = (B>=0) ? 1 : 0;
    intC = (C>=0) ? 1 : 0;

    return (4*C + 2*B + A);
}

static void XYZCalculate(double in_alpha, double in_beta, double in_Ts, double in_Udc, double* out_X, double* out_Y, double* out_Z)
{
    double mid_var = in_Ts / in_Udc;
    *out_X = sqrt(3) * in_beta * mid_var;
    *out_Y = (1.5*in_alpha + sqrt(3)*in_beta/2) * mid_var;
    *out_Z = (-1.5*in_alpha + sqrt(3)*in_beta/2) * mid_var;
}

static void T1T2Calculate(int in_sectorN, double in_X, double in_Y, double in_Z, double in_Ts,
                          double* out_T1, double* out_T2)
{
    double tmp_T1, tmp_T2;
    switch(in_sectorN)
    {
    case 1:
    {
        tmp_T1 = in_Z;
        tmp_T2 = in_Y;
        break;
    }
    case 2:
    {
        tmp_T1 = in_Y;
        tmp_T2 = -in_X;
        break;
    }
    case 3:
    {
        tmp_T1 = -in_Z;
        tmp_T2 = in_X;
        break;
    }
    case 4:
    {
        tmp_T1 = -in_X;
        tmp_T2 = in_z;
        break;
    }
    case 5:
    {
        tmp_T1 = in_X;
        tmp_T2 = -in_Y;
        break;
    }
    case 6:
    {
        tmp_T1 = -in_Y;
        tmp_T2 = -in_Z;
        break;
    }
    default:
        break;
    }

    *T1 = ((in_Ts-tmp_T2-tmp_T1)>=0) ? tmp_T1 : (tmp_T1*in_Ts/(tmp_T1+tmp_T2));
    *T2
}

void Svpwm(double in_alpha, double in_beta, double* out_pwmA, double* out_pwmB, double* out_pwmC)
{

}
