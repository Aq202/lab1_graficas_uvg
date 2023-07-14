#pragma once
#include <iostream>
#include "color.h"
#include "framebuffer.h"
#include "vertex2.h"

Color currentColor = {0, 0, 0};

void setCurrentColor(const Color color)
{
    currentColor = color;
}

void point(const Vertex2 &vertex)
{
    // Calcular el índice en el framebuffer correspondiente a la coordenada (x, y)
    int index = vertex.y * screenWidth + vertex.x;

    // Verificar si el índice está dentro del rango válido
    if (index >= 0 && index < framebuffer.size())
    {
        // Actualizar el color en la posición index del framebuffer con currentColor
        framebuffer[index] = currentColor;
    }
}