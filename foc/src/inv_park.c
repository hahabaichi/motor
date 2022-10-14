#include "inv_park.h"

void InvPark(double in_d, double in_q, double in_theta, double* out_alpha, double* out_beta)
{
    *out_alpha = in_d * cos(in_theta) - in_q * sin(in_theta);
    *out_beta = in_d * sin(in_theta) + in_q * cos(in_theta);
}
