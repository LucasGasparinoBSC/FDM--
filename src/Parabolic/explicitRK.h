#ifndef PARABOLIC_EXPLICITRK_H
#define PARABOLIC_EXPLICITRK_H

#include <cstdint>
#include "fluxDiffu.h"

void computeDt(float mu, float h, float cfl_d, float dt);
void classicRK4(bool isPeriodic, uint64_t nStep, uint64_t nPoints, uint64_t nx, float *u, float dt, float h, float mu);

#endif //  PARABOLIC_EXPLICITRK_H