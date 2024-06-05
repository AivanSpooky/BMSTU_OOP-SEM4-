#include "mainwindow.h"

#include <QApplication>
#include <QLocale>

#include <iostream>
#include <fstream>
#include <vector>
void createCubeBinFile(const std::string& fileName) {
    std::ofstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to create file: " << fileName << std::endl;
        return;
    }

    // Вершины куба
    std::vector<std::vector<double>> vertices = {
        {-100, 100, 100},
        {100, 100, 100},
        {100, -100, 100},
        {-100, -100, 100},
        {-100, 100, -100},
        {100, 100, -100},
        {100, -100, -100},
        {-100, -100, -100}
    };

    // Записываем количество вершин
    int numVertices = 8;
    file.write(reinterpret_cast<const char*>(&numVertices), sizeof(numVertices));

    // Записываем координаты каждой вершины
    for (const auto& vertex : vertices) {
        for (const auto& coordinate : vertex) {
            file.write(reinterpret_cast<const char*>(&coordinate), sizeof(coordinate));
        }
    }

    // Связи между вершинами куба
    std::vector<std::pair<int, int>> links = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1},
        {5, 6},
        {6, 7},
        {7, 8},
        {8, 5},
        {1, 5},
        {2, 6},
        {3, 7},
        {4, 8}
    };

    // Записываем количество связей
    int numLinks = 12;
    file.write(reinterpret_cast<const char*>(&numLinks), sizeof(numLinks));

    // Записываем каждую связь
    for (const auto& link : links) {
        file.write(reinterpret_cast<const char*>(&link.first), sizeof(link.first));
        file.write(reinterpret_cast<const char*>(&link.second), sizeof(link.second));
    }
}

int main(int argc, char *argv[])
{
    //createCubeBinFile("cube.bin");
    QApplication a(argc, argv);
    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
