#include <iostream>
#include <fstream>
#include <vector>
#include <omp.h>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>
#include <opencv2/opencv.hpp>

const int rows = 7121;
const int cols = 10681;

void leerArchivo(const std::string& nombreArchivo, std::vector<std::vector<int>>& matriz) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string contenido((std::istreambuf_iterator<char>(archivo)), std::istreambuf_iterator<char>());
        std::istringstream iss(contenido);
        std::string valor;
        for (int i = 0; i < matriz.size(); ++i) {
            for (int j = 0; j < matriz[i].size(); ++j) {
                iss >> valor;
                if (valor != "*") {
                    matriz[i][j] = atoi(valor.c_str());
                } else {
                    matriz[i][j] = -1;
                }
            }
        }
        archivo.close();
    }
    else {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        exit(EXIT_FAILURE);     
    }
}

int main() {
    std::vector<std::vector<int>> alpha(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> red(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> green(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> blue(rows, std::vector<int>(cols));

    leerArchivo("alfa.txt", alpha);
    leerArchivo("rojo.txt", red);
    leerArchivo("verde.txt", green);
    leerArchivo("azul.txt", blue);

    std::vector<std::vector<int>> promedio(rows, std::vector<int>(cols));
    leerArchivo("promedio.txt", promedio);
    
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (red[i][j] == -1) {
                int temp = (promedio[i][j] - blue[i][j] * 0.11 - green[i][j]* 0.59) / 0.3;
                red[i][j] = std::min(255, std::max(0, temp));
            }
            if (green[i][j] == -1) {
                int temp = (promedio[i][j] - blue[i][j] * 0.11 - red[i][j] * 0.3) / 0.59;
                green[i][j] = std::min(255, std::max(0, temp));
            }
            if (blue[i][j] == -1) {
                int temp = (promedio[i][j] - red[i][j] * 0.3 - green[i][j] * 0.59) / 0.11;
                blue[i][j] = std::min(255, std::max(0, temp));
            }
        }
    }

    // Crear imagen de OpenCV
    cv::Mat resultado(rows, cols, CV_8UC3);

    // Copiar valores a la imagen de OpenCV
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resultado.at<cv::Vec3b>(i, j) = cv::Vec3b(blue[i][j], green[i][j], red[i][j]);
        }
    }

    // Mostrar la imagen con OpenCV
    cv::imshow("Imagen Resultante", resultado);
    cv::waitKey(0);

    // Guardar la imagen si es necesario
    cv::imwrite("resultado.jpg", resultado);

    return 0;
}
