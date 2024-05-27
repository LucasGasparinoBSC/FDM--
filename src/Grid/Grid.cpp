#include "Grid.h"

void Grid::create_a2ijk()
{
    a2ijk = (uint64_t **)malloc(nPoints * sizeof(uint64_t *));
    for (uint64_t i = 0; i < nPoints; i++)
    {
        a2ijk[i] = (uint64_t *)malloc(nDime * sizeof(uint64_t));
    }

    uint64_t index = 0;
    for (uint64_t k = 0; k < nZ; k++)
    {
        for (uint64_t j = 0; j < nY; j++)
        {
            for (uint64_t i = 0; i < nX; i++)
            {
                a2ijk[index][0] = i;
                a2ijk[index][1] = j;
                a2ijk[index][2] = k;
                index++;
            }
        }
    }
}

void Grid::create_ijk2a()
{
    ijk2a = (uint64_t ***)malloc(nX * sizeof(uint64_t **));
    for (uint64_t i = 0; i < nX; i++)
    {
        ijk2a[i] = (uint64_t **)malloc(nY * sizeof(uint64_t *));
        for (uint64_t j = 0; j < nY; j++)
        {
            ijk2a[i][j] = (uint64_t *)malloc(nZ * sizeof(uint64_t));
        }
    }

    uint64_t index = 0;
    for (uint64_t k = 0; k < nZ; k++)
    {
        for (uint64_t j = 0; j < nY; j++)
        {
            for (uint64_t i = 0; i < nX; i++)
            {
                ijk2a[i][j][k] = index;
                index++;
            }
        }
    }
}

Grid::Grid() : nX(0), nY(0), nZ(0), xMin(0.0), xMax(0.0), yMin(0.0), yMax(0.0), zMin(0.0), zMax(0.0)
{
    nPoints = nX * nY * nZ;
}

Grid::Grid(uint64_t nX, uint64_t nY, uint64_t nZ, double xmin, double xmax) : nX(nX), nY(nY), nZ(nZ)
{
    nPoints = nX * nY * nZ;
    xMin = xmin;
    yMin = xmin;
    zMin = xmin;
    xMax = xmax;
    yMax = xmax;
    zMax = xmax;
    hx = (xMax - xMin) / (nX - 1);
    hy = (yMax - yMin) / (nY - 1);
    hz = (zMax - zMin) / (nZ - 1);
    xCoord = new double[nX];
    yCoord = new double[nY];
    zCoord = new double[nZ];

    for (uint64_t i = 0; i < nX; i++)
    {
        xCoord[i] = xMin + i * hx;
    }

    for (uint64_t i = 0; i < nY; i++)
    {
        yCoord[i] = yMin + i * hy;
    }

    for (uint64_t i = 0; i < nZ; i++)
    {
        zCoord[i] = zMin + i * hz;
    }

    create_a2ijk();
    create_ijk2a();
}

Grid::~Grid()
{
    delete[] xCoord;
    delete[] yCoord;
    delete[] zCoord;
}

uint64_t Grid::get_nPoints()
{
    return nPoints;
}

uint64_t Grid::get_nX()
{
    return nX;
}

uint64_t Grid::get_nY()
{
    return nY;
}

uint64_t Grid::get_nZ()
{
    return nZ;
}

uint64_t **Grid::get_a2ijk()
{
    return a2ijk;
}

uint64_t ***Grid::get_ijk2a()
{
    return ijk2a;
}

double Grid::get_hx()
{
    return hx;
}

double Grid::get_hy()
{
    return hy;
}

double Grid::get_hz()
{
    return hz;
}

double *Grid::get_xyz()
{
    double *xyz = new double[nPoints * 3];
    uint64_t index = 0;

    for (uint64_t i = 0; i < nX; i++)
    {
        for (uint64_t j = 0; j < nY; j++)
        {
            for (uint64_t k = 0; k < nZ; k++)
            {
                xyz[index] = xCoord[i];
                xyz[index + 1] = yCoord[j];
                xyz[index + 2] = zCoord[k];
                index += 3;
            }
        }
    }

    return xyz;
}