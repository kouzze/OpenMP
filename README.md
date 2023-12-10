<p align="center">
  <a href="https://cplusplus.com/" target="blank"><img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="200" alt="C++ Logo" /></a>
</p>

## OBJETIVOS

🠊 Aplicación Práctica de Algoritmos
</br>
🠊 Dominio de Lenguajes de Programación
</br>
🠊 Optimización y Eficiencia
</br>
🠊 Resolución de Problemas
</br>
🠊 Pruebas y Depuración
</br>
🠊 Documentación y Comunicación
</br>
🠊 Creatividad e Innovación
</br>
🠊 Pensamiento Lógico y Algorítmico

## Instalación
Al momento de realizar un cambio, se debe utilizar el comando:
```bash
make
```
Luego ejecutar el proyecto con el siguiente comando en la consola:
```bash
./proyecto
```
## Tecnología Utilizada

Para este proyecto utilicé el sistema operativo Ubuntu 22.04 LTS, las bibliotecas utilizadas fueron:

* g++
* cmake
* opencv

## Configuración OpenCV

### Instalar dependencias
```bash
sudo apt install build-essential cmake git pkg-config libgtk-3-dev

sudo apt install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev

sudo apt install libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev 

sudo apt install gfortran openexr libatlas-base-dev python3-dev python3-numpy

sudo apt install libtbb2 libtbb-dev libdc1394-dev
```
### Clonar repositorios OpenCV y contrib 
```bash
git clone https://github.com/opencv/opencv.git

git clone https://github.com/opencv/opencv_contrib
```
### Crear carpeta build 
```bash
cd opencv
mkdir build
cd build
```
### Configurar OpenCV
```bash
cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D INSTALL_C_EXAMPLES=ON \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D OPENCV_GENERATE_PKGCONFIG=ON \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules \
    -D BUILD_EXAMPLES=ON ..
```

### Proceso de Compilado
```bash
make -j{número de cores a utilizar, recomendado: 4}
por ejemplo: 
make -j4
```

### Instalación
```bash
make install
```

### Importar paquete de OpenCV
```bash
OPENCV = pkg-config opencv4 --cflags --libs
```

## Consideraciones a tomar
Los archivos .txt tienen que ir en la raíz del proyecto (promedio.txt, alpha.txt, azul.txt, rojo.txt y verde.txt)

## Autor

- Nicolas Jara Carvajal 
