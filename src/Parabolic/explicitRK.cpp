#include "explicitRK.h"

// Implementation of the classic Runge-Kutta 4th order method for parabolic scalar
void classicRK4(uint64_t nStep, uint64_t nPoints, float *u, float dt, float h, float cfl_d)
{
    // Initialize the registers
    float *u_tmp;
    float *R;
    float *Rsum;

    float *u_tmp = new float[nPoints];
    float *R = new float[nPoints];
    float *Rsum = new float[nPoints];

    // Set the coefficients
    float a[4] = {0.0f, 0.5f, 0.5f, 1.0f};
    float b[4] = {1.0f / 6.0f, 1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 6.0f};

    // Compute the Runge-Kutta 4th order method
    for (uint64_t iStep = 0; iStep < nStep; iStep++)
    {
        // Zero the registers
        for (uint64_t index = 0; index < nPoints; index++)
        {
            u_tmp[index] = 0.0f;
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
            // TODO: Implement the computation of R(u_tmp)

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

        // Update dt
        // TODO: Implement the computation of the new dt
    }

    // Free the registers
    delete[] u_tmp;
    delete[] R;
    delete[] Rsum;
}