#pragma once
#include <vector>
#include <fstream>
#include <cstdint>
#include "writeBmp.h"

// Tamaño de la pantalla en píxeles
const int screenWidth = 800;
const int screenHeight = 600;

// Variable global para almacenar el framebuffer
std::vector<Color> framebuffer(screenWidth *screenHeight);

// Variable global para representar el color base del framebuffer
Color clearColor = {0, 0, 0}; // Negro

// Función para limpiar el framebuffer con el color clearColor
void clear()
{
    for (int i = 0; i < framebuffer.size(); i++)
    {
        framebuffer[i] = clearColor;
    }
}

void setClearColor(Color color)
{
    clearColor = color;
}

void renderBuffer()
{
    writeBmp(framebuffer, screenWidth, screenHeight, "out.bmp");
}
