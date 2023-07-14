#pragma once
#include <vector>
#include <fstream>
#include <cstdint>
#include "color.h"

void writeBmp(std::vector<Color> framebuffer, uint32_t screenWidth, uint32_t screenHeight, std::string fileName) {
    // Abrir el archivo en modo binario para escritura
    std::ofstream file(fileName, std::ios::binary);

    // Encabezado del archivo BMP
    uint16_t fileType = 0x4D42;  // "BM" en little-endian
    uint32_t fileSize = 54 + framebuffer.size() * 3;  // Tamaño total del archivo
    uint32_t reserved = 0;  // Reservado, debe ser 0
    uint32_t dataOffset = 54;  // Desplazamiento hasta los datos de la imagen
    uint32_t headerSize = 40;  // Tamaño del encabezado de información
    uint32_t imageWidth = screenWidth;
    uint32_t imageHeight = screenHeight;
    uint16_t planes = 1;  // Número de planos, debe ser 1
    uint16_t bitsPerPixel = 24;  // Bits por píxel (RGB), 24 para 8 bits por componente
    uint32_t compression = 0;  // Sin compresión
    uint32_t imageSize = framebuffer.size() * 3;  // Tamaño de los datos de la imagen
    uint32_t horizontalResolution = 2835;  // Resolución horizontal en píxeles por metro (72 dpi)
    uint32_t verticalResolution = 2835;  // Resolución vertical en píxeles por metro (72 dpi)
    uint32_t colorsUsed = 0;  // Número de colores utilizados, 0 para todos los colores
    uint32_t importantColors = 0;  // Número de colores importantes, 0 para todos los colores

    // Escribir el encabezado del archivo BMP
    file.write(reinterpret_cast<char*>(&fileType), sizeof(fileType));
    file.write(reinterpret_cast<char*>(&fileSize), sizeof(fileSize));
    file.write(reinterpret_cast<char*>(&reserved), sizeof(reserved));
    file.write(reinterpret_cast<char*>(&dataOffset), sizeof(dataOffset));
    file.write(reinterpret_cast<char*>(&headerSize), sizeof(headerSize));
    file.write(reinterpret_cast<char*>(&imageWidth), sizeof(imageWidth));
    file.write(reinterpret_cast<char*>(&imageHeight), sizeof(imageHeight));
    file.write(reinterpret_cast<char*>(&planes), sizeof(planes));
    file.write(reinterpret_cast<char*>(&bitsPerPixel), sizeof(bitsPerPixel));
    file.write(reinterpret_cast<char*>(&compression), sizeof(compression));
    file.write(reinterpret_cast<char*>(&imageSize), sizeof(imageSize));
    file.write(reinterpret_cast<char*>(&horizontalResolution), sizeof(horizontalResolution));
    file.write(reinterpret_cast<char*>(&verticalResolution), sizeof(verticalResolution));
    file.write(reinterpret_cast<char*>(&colorsUsed), sizeof(colorsUsed));
    file.write(reinterpret_cast<char*>(&importantColors), sizeof(importantColors));

    // Escribir los datos de la imagen
    for (const Color& color : framebuffer) {
        uint8_t red = color.getRed();
        uint8_t green = color.getGreen();
        uint8_t blue = color.getBlue();

        // Escribir los componentes de color en orden inverso (BGR)
        file.write(reinterpret_cast<char*>(&blue), sizeof(blue));
        file.write(reinterpret_cast<char*>(&green), sizeof(green));
        file.write(reinterpret_cast<char*>(&red), sizeof(red));
    }

    // Cerrar el archivo
    file.close();
}