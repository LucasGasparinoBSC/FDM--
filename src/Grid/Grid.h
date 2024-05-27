#ifndef GRID_H
#define GRID_H

#pragma once

#include <cstdint>
#include <cstdlib>

class Grid
{
    private:
        const uint64_t nDime = 3;
        uint64_t nPoints;
        uint64_t nX;
        uint64_t nY;
        uint64_t nZ;
        uint64_t **a2ijk;
        uint64_t ***ijk2a;
        double xMin;
        double xMax;
        double yMin;
        double yMax;
        double zMin;
        double zMax;
        double hx;
        double hy;
        double hz;
        double *xCoord;
        double *yCoord;
        double *zCoord;
        void create_a2ijk();
        void create_ijk2a();
    public:
        // Constructor
        Grid();                                                                // Default constructor
        Grid(uint64_t nX, uint64_t nY, uint64_t nZ, double xmin, double xmax); // Parameterized constructor
        // Destructor
        ~Grid();
        // Getters
        uint64_t get_nPoints();
        uint64_t get_nX();
        uint64_t get_nY();
        uint64_t get_nZ();
        uint64_t **get_a2ijk();
        uint64_t ***get_ijk2a();
        double get_hx();
        double get_hy();
        double get_hz();
        double *get_xyz();
};

#endif