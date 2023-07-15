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


  renderBuffer();
}