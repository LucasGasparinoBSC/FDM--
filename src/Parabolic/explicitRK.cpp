#include "explicitRK.h"

void computeDt(float mu, float h, float cfl_d, float dt)
{
    // Compute the time step
    dt = cfl_d * (h*h) / mu;
}

// Implementation of the classic Runge-Kutta 4th order method for parabolic scalar
void classicRK4(bool isPeriodic, uint64_t nStep, uint64_t nPoints, uint64_t nx, uint64_t ***ijk2a, float *u, float cfl_d, float h, float mu)
{
    // Initialize the registers
    float *u_tmp = new float[nPoints];
    float *R = new float[nPoints];
    float *Rsum = new float[nPoints];

    // Set the coefficients
    float a[4] = {0.0f, 0.5f, 0.5f, 1.0f};
    float b[4] = {1.0f / 6.0f, 1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 6.0f};

    // Initialize dt
    float dt;
    computeDt(mu, h, cfl_d, dt);

    // Compute the Runge-Kutta 4th order method
    for (uint64_t iStep = 0; iStep < nStep; iStep++)
    {
        // Zero the registers
        for (uint64_t index = 0; index < nPoints; index++)
        {
            R[index] = 0.0f;
            Rsum[index] = 0.0f;
        }

        // Compute the intermediate steps
        for (int iStage = 0; iStage < 4; iStage++)
        {
            float as = a[iStage];
            float bs = b[iStage];

            // Compute u_tmp
            for (uint64_t index = 0; index < nPoints; index++)
            {
                u_tmp[index] = u[index] + dt * as * R[index];
            }

            // Compute R(u_tmp)
            central2ndOrder(isPeriodic, nPoints, nx, ijk2a, h, mu, u_tmp, R);

            // Accumulate the new residual
            for (uint64_t index = 0; index < nPoints; index++)
            {
                Rsum[index] += bs * R[index];
            }
        }

        // Final update
        for (uint64_t index = 0; index < nPoints; index++)
        {
            u[index] += dt * Rsum[index];
        }
    }

    // Free the registers
    delete[] u_tmp;
    delete[] R;
    delete[] Rsum;
}