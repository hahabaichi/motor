#include "PI.h"


void PI(double input, double in_target, double in_P, double in_I, double* in_out_last_err, double* output)
{
    double err = input - in_target;
    *output = in_P * (err - *in_out_last_err) + in_I * err;
    *in_out_last_err = err;
}
