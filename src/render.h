#pragma once
#include "polygon.h"

void render()
{
  setClearColor({0, 0, 0});
  clear();

  // Dibujar una línea diagonal
  std::vector<Vertex2> points;
  points.push_back(Vertex2{413, 177});
  points.push_back(Vertex2{448, 159});
  points.push_back(Vertex2{502, 88});
  points.push_back(Vertex2{553, 53});
  points.push_back(Vertex2{535, 36});
  points.push_back(Vertex2{676, 37});
  points.push_back(Vertex2{660, 52});
  points.push_back(Vertex2{750, 145});
  points.push_back(Vertex2{761, 179});
  points.push_back(Vertex2{672, 192});
  points.push_back(Vertex2{659, 214});
  points.push_back(Vertex2{615, 214});
  points.push_back(Vertex2{632, 230});
  points.push_back(Vertex2{580, 230});
  points.push_back(Vertex2{597, 215});
  points.push_back(Vertex2{552, 214});
  points.push_back(Vertex2{517, 144});
  points.push_back(Vertex2{466, 180});

  std::vector<Vertex2> points2;
  points2.push_back(Vertex2{682, 175});
  points2.push_back(Vertex2{708, 120});
  points2.push_back(Vertex2{735, 148});
  points2.push_back(Vertex2{739, 170});

  setCurrentColor({128, 255, 0});

  fillPolygon(points);

  setCurrentColor({255, 255, 255});

  drawPolygon(points);

  setCurrentColor({0, 0, 0});

  fillPolygon(points2);

  setCurrentColor({255, 255, 255});

  drawPolygon(points2);

  renderBuffer();
}