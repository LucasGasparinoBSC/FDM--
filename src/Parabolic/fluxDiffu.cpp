#include "fluxDiffu.h"

void central2ndOrder(uint64_t nPoints, uint64_t nx, uint64_t ***ijk2a, float cfl_d, float *u, float *R)
{
    // Zero the residual
    for (uint64_t iPoint = 0; iPoint < nPoints; iPoint++)
    {
        R[iPoint] = 0.0;
    }

    // Compute the residual
    for (uint64_t k = 1; k < nx - 1; k++)
    {
        for (uint64_t j = 1; j < nx - 1; j++)
        {
            for (uint64_t i = 1; i < nx - 1; i++)
            {
            }
        }
    }
}