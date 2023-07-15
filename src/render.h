#pragma once
#include "polygon.h"

void render()
{

  setClearColor({0, 0, 0});
  clear();

  std::vector<Vertex2> points;
  points.push_back(Vertex2{321, 335});
  points.push_back(Vertex2{288, 286});
  points.push_back(Vertex2{339, 251});
  points.push_back(Vertex2{374, 302});

  setCurrentColor({35, 29, 226});

  fillPolygon(points);

  setCurrentColor({255, 255, 255});

  drawPolygon(points);

  renderBuffer();
}