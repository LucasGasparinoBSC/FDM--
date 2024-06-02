#ifndef FLUX_DIFFU_H_
#define FLUX_DIFFU_H_

#pragma once

#include <cstdint>
#include <cstdlib>

void central2ndOrder(bool isPeriodic, uint64_t nPoints, uint64_t nx, uint64_t ***ijk2a, float h, float mu, float *u, float *R);

#endif // !FLUX_DIFFU_H_