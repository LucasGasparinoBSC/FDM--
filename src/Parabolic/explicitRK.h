#ifndef PARABOLIC_EXPLICITRK_H
#define PARABOLIC_EXPLICITRK_H

#include <cstdint>

void classicRK4(uint64_t nStep, uint64_t nPoints, float *u, float dt, float h, float cfl_d);
void lsrk();

#endif //  PARABOLIC_EXPLICITRK_H