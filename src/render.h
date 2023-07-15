#pragma once
#include "polygon.h"

void render()
{
  setClearColor({0, 0, 0});
  clear();

  // Dibujar una línea diagonal
  std::vector<Vertex2> points;
  points.push_back(Vertex2{165, 380});
  points.push_back(Vertex2{185, 360});
  points.push_back(Vertex2{180, 330});
  points.push_back(Vertex2{207, 345});
  points.push_back(Vertex2{233, 330});
  points.push_back(Vertex2{230, 360});
  points.push_back(Vertex2{250, 380});
  points.push_back(Vertex2{220, 385});
  points.push_back(Vertex2{205, 410});
  points.push_back(Vertex2{193, 383});

  setCurrentColor({241, 201, 59});

  fillPolygon(points);

  setCurrentColor({255, 255, 255});

  drawPolygon(points);

  /*Poligono 2*/
  points.clear();

  points.push_back(Vertex2{321, 335});
  points.push_back(Vertex2{288, 286});
  points.push_back(Vertex2{339, 251});
  points.push_back(Vertex2{374, 302});

  setCurrentColor({35, 29, 226});

  fillPolygon(points);

  setCurrentColor({255, 255, 255});

  drawPolygon(points);

  /*Poligono 3*/
  points.clear();

  points.push_back(Vertex2{377, 249});
  points.push_back(Vertex2{411, 197});
  points.push_back(Vertex2{436, 249});

  setCurrentColor({255, 0, 0});
  fillPolygon(points);
  setCurrentColor({255, 255, 255});
  drawPolygon(points);

  /*Poligono 4 y 5*/

  points.clear();
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

  renderBuffer();
}