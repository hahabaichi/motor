#include "clark.h"

void Clark(double in_curA, double in_curB, double in_curC, double * out_alpha, double * out_beta)
{
    *out_alpha = in_curA;
    *out_beta = sqrt(in_curC) / 3 * (in_curB - in_curC);
}
