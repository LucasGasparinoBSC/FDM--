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

    // Case is periodic
    bool flag = true;

    // Create the grid
    Grid g(flag, nx, ny, nz, xmin, xmax);

    // Print the a2ijk info
    uint64_t **a2ijk = g.get_a2ijk();

    for (uint64_t i = 0; i < g.get_nPoints(); i++)
    {
        std::cout << "Point " << i << ": ";
        for (uint64_t j = 0; j < 3; j++)
        {
            std::cout << a2ijk[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Print the ijk2a info
    uint64_t ***ijk2a = g.get_ijk2a();

    for (uint64_t k = 0; k < nz; k++)
    {
        for (uint64_t j = 0; j < ny; j++)
        {
            for (uint64_t i = 0; i < nx; i++)
            {
                std::cout << "Point (" << i << ", " << j << ", " << k << "): " << ijk2a[i][j][k] << std::endl;
            }
        }
    }

    return 0;
}