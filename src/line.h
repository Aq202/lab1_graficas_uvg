#pragma once
#include <cmath>
#include "point.h"

void line(Vertex2 start, Vertex2 end)
{
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = (start.x < end.x) ? 1 : -1;
    int sy = (start.y < end.y) ? 1 : -1;

    int error = dx - dy;

    while (true)
    {
        point(Vertex2{start.x, start.y});

        if (start.x == end.x && start.y == end.y)
            break;

        int e2 = 2 * error;

        if (e2 > -dy)
        {
            error -= dy;
            start.x += sx;
        }

        if (e2 < dx)
        {
            error += dx;
            start.y += sy;
        }
    }
}