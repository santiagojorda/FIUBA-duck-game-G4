# Cómo compilar y ejecutar 

## Introducción
Este documento explica paso a paso cómo compilar y ejecutar el proyecto [Nombre del proyecto].

## Requisitos previos
* **Sistema operativo:** [Sistema operativo]
* **Dependencias:**
  * SDL2
  * [Dependencia 2]
  * ...

## Instalar
1 - En la terminal ejecutar 
```bash
sudo apt-get install libjpeg-dev libpng-dev libfreetype-dev libopusfile-dev libflac-dev libxmp-dev libfluidsynth-dev libwavpack-dev cmake libmodplug-dev libsdl2-dev
````
2 - se deben descargar los siguietes .zip


- libsdl2-image ( 2.6.3, https://github.com/libsdl-org/SDL_image/releases/tag/release-2.6.3)
- libsdl2-mixer (2.6.3, https://github.com/libsdl-org/SDL_mixer/releases/tag/release-2.6.3)
- libsdl2-ttf (2.20.2, https://github.com/libsdl-org/SDL_ttf/releases/tag/release-2.20.2)

3 - descompirmir y en cada una de las carpetas ejecutar 

```bash
cd nombre_de_la carpeta_descomprimida
mkdir build
cd build
cmake ..
make -j4
sudo make install
````

4 - Ahora dentro de la carpeta de del repo FIUBA-duck-game-G4

```bash
mkdir build
cd build
cmake ..
sudo make install
````

## Ejecutar
Se requieren dos terminales 

en la primera:

```bash
 ./taller_client  localhost 8080
````
en la segunda 
```bash
 ./taller_server
````