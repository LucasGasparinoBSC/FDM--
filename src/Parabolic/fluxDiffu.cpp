#include "fluxDiffu.h"

void central2ndOrder(bool isPeriodic, uint64_t nPoints, uint64_t nx, uint64_t ***ijk2a, float h, float mu, float *u, float *R)
{
    // Vars for stencil
    uint64_t iPoint;
    uint64_t iLeft, iRight;
    uint64_t jLeft, jRight;
    uint64_t kLeft, kRight;

    // Factor
    float factor = mu/(h*h);

    // Compute the residual in the interior points
    for (uint64_t k = 0; k < nx - 1; k++)
    {
        for (uint64_t j = 0; j < nx - 1; j++)
        {
            for (uint64_t i = 0; i < nx - 1; i++)
            {
                if (isPeriodic)
                {
                    iPoint = ijk2a[i][j][k];
                    if (i == 0)
                    {
                        iLeft = ijk2a[nx - 2][j][k];
                        iRight = ijk2a[i + 1][j][k];
                    }
                    else if (i == nx-2)
                    {
                        iLeft = ijk2a[i - 1][j][k];
                        iRight = ijk2a[0][j][k];
                    }
                    else
                    {
                        iLeft = ijk2a[i - 1][j][k];
                        iRight = ijk2a[i + 1][j][k];
                    }

                    if (j == 0)
                    {
                        jLeft = ijk2a[i][nx - 2][k];
                        jRight = ijk2a[i][j + 1][k];
                    }
                    else if (j == nx-2)
                    {
                        jLeft = ijk2a[i][j - 1][k];
                        jRight = ijk2a[i][0][k];
                    }
                    else
                    {
                        jLeft = ijk2a[i][j - 1][k];
                        jRight = ijk2a[i][j + 1][k];
                    }

                    if (k == 0)
                    {
                        kLeft = ijk2a[i][j][nx - 2];
                        kRight = ijk2a[i][j][k + 1];
                    }
                    else if (k == nx-2)
                    {
                        kLeft = ijk2a[i][j][k - 1];
                        kRight = ijk2a[i][j][0];
                    }
                    else
                    {
                        kLeft = ijk2a[i][j][k - 1];
                        kRight = ijk2a[i][j][k + 1];
                    }
                    R[iPoint] = factor * 8.0f * u[iPoint];
                    R[iPoint] += factor * (u[iLeft] + u[iRight]);
                    R[iPoint] += factor * (u[jLeft] + u[jRight]);
                    R[iPoint] += factor * (u[kLeft] + u[kRight]);
                }
                else
                {
                    if ( i > 0 && j > 0 && k > 0 )
                    {
                        iPoint = ijk2a[i][j][k];
                        iLeft = ijk2a[i - 1][j][k];
                        iRight = ijk2a[i + 1][j][k];
                        jLeft = ijk2a[i][j - 1][k];
                        jRight = ijk2a[i][j + 1][k];
                        kLeft = ijk2a[i][j][k - 1];
                        kRight = ijk2a[i][j][k + 1];
                        R[iPoint] = factor * 8.0f * u[iPoint];
                        R[iPoint] += factor * (u[iLeft] + u[iRight]);
                        R[iPoint] += factor * (u[jLeft] + u[jRight]);
                        R[iPoint] += factor * (u[kLeft] + u[kRight]);
                    }
                }
            }
        }
    }
}