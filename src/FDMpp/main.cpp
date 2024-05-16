#include <iostream>
#include <cstdint>

#include "Grid.h"

// Define PI and 2*PI
#define PI 3.14159265358979323846
#define TWO_PI 6.28318530717958647692

int main(int argc, const char** argv)
{
    // Requires the value of nx as argument
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <nx>" << std::endl;
        return 1;
    }

    // Define the grid: for now is a cube equally spaced in x, y and z, beetween 0 and 2*PI
    const uint64_t nx = std::stoi(argv[1]);
    const uint64_t ny = nx;
    const uint64_t nz = nx;
    const double xmin = 0.0;
    const double xmax = TWO_PI;

    // Create the grid
    Grid g(nx, ny, nz, xmin, xmax);

    return 0;
}