#include <vector>
#include "line.h"
#include <queue>
#include <algorithm>

void drawPolygon(const std::vector<Vertex2>& points)
{
    if (points.size() < 2)
    {
        std::cout << "Cannot draw a polygon with less than 2 points." << std::endl;
        return;
    }

    for (size_t i = 0; i < points.size() - 1; ++i)
    {
        line(points[i], points[i + 1]);
    }

    // Connect the last point with the first point to close the polygon
    line(points[points.size() - 1], points[0]);
}

void fillPolygon(const std::vector<Vertex2>& vertices)
{
    if (vertices.size() < 3)
    {
        std::cout << "Cannot fill a polygon with less than 3 vertices." << std::endl;
        return;
    }

    // Encontrar los límites del polígono
    int minX = vertices[0].x;
    int maxX = vertices[0].x;
    int minY = vertices[0].y;
    int maxY = vertices[0].y;

    for (const Vertex2& vertex : vertices)
    {
        if (vertex.x < minX)
            minX = vertex.x;
        if (vertex.x > maxX)
            maxX = vertex.x;
        if (vertex.y < minY)
            minY = vertex.y;
        if (vertex.y > maxY)
            maxY = vertex.y;
    }

    // Crear una matriz de visitados para controlar los píxeles ya rellenados
    std::vector<std::vector<bool>> visited(maxY - minY + 1, std::vector<bool>(maxX - minX + 1, false));

    // Obtener el color de relleno
    Color fillColor = currentColor;

    // Rellenar el polígono línea por línea utilizando el enfoque de "bucket fill" y "scanline"
    for (int y = minY; y <= maxY; ++y)
    {
        std::vector<int> intersectPoints;

        // Encontrar los puntos de intersección con cada línea del polígono
        for (size_t i = 0; i < vertices.size(); ++i)
        {
            const Vertex2& currentVertex = vertices[i];
            const Vertex2& nextVertex = vertices[(i + 1) % vertices.size()];

            if ((currentVertex.y <= y && nextVertex.y > y) || (nextVertex.y <= y && currentVertex.y > y))
            {
                int x = currentVertex.x + (static_cast<float>(y - currentVertex.y) / (nextVertex.y - currentVertex.y)) * (nextVertex.x - currentVertex.x);
                intersectPoints.push_back(x);
            }
        }

        // Ordenar los puntos de intersección por coordenada X
        std::sort(intersectPoints.begin(), intersectPoints.end());

        // Rellenar el espacio entre los puntos de intersección
        for (size_t i = 0; i < intersectPoints.size(); i += 2)
        {
            int startX = intersectPoints[i];
            int endX = intersectPoints[i + 1];

            for (int x = startX; x <= endX; ++x)
            {
                if (!visited[y - minY][x - minX])
                {
                    point(Vertex2{ x, y });
                    visited[y - minY][x - minX] = true;
                }
            }
        }
    }
}
