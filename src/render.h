#pragma once
#include "polygon.h"

void render()
{
  setClearColor({0, 0, 0});
  clear();

  // Dibujar una línea diagonal
  std::vector<Vertex2> points;
  points.push_back(Vertex2{377, 249});
  points.push_back(Vertex2{411, 197});
  points.push_back(Vertex2{436, 249});

  setCurrentColor({255, 0, 0});

  fillPolygon(points);

  setCurrentColor({255, 255, 255});

  drawPolygon(points);

  renderBuffer();
}