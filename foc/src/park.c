#include "park.h"

void Park(double in_alpha, double in_beta, double in_theta, double * out_d, double * out_q)
{
    *out_d = in_alpha * cos(in_theta) + in_beta * sin(in_theta);
    *out_q = -in_alpha * sin(in_theta) + in_beta * cos(in_theta);
}
