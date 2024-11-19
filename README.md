> Hola! 👋🏼 El trabajo aun no esta finalizado, seguimos en desarrollo! 💪🏼☕ - 19/11 

# Duck Game

### Integrantes
- Felipe D'alto (110000)
- Santiago Jorda (102924)
- Alexia Aroa (110014)


## Cómo compilar y ejecutar 

### Introducción
Este documento explica paso a paso cómo compilar y ejecutar el proyecto [Nombre del proyecto].

### Requisitos previos
#### Uso de bibliotecas

1. **Biblioteca de Sockets de la cátedra Veiga** | Autor: eldipa | Licencia: GPL v2
    - [https://github.com/eldipa/hands-on-sockets-in-cpp](https://github.com/eldipa/hands-on-sockets-in-cpp)

2. **Biblioteca de Threads y Queque de la cátedra Veiga** | Autor: eldipa | Licencia: GPL v2
    - [https://github.com/eldipa/hands-on-threads](https://github.com/eldipa/hands-on-threads)

3. **Blioteca SDL2** 
    - [https://github.com/libsdl-org/SDL](https://github.com/libsdl-org/SDL)

4. **Biblioteca  yaml-cpp**
    - [https://github.com/jbeder/yaml-cpp.git](https://github.com/jbeder/yaml-cpp.git)

## Instalar

Menos SDL2, Cmake se encarga de de instalar las dependencias necesarias 

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

Para el server en la primera:
```bash
 ./taller_server
````

Para el cliente en la segunda 
(por defecto se conecta en el peurto 8080)

```bash
 ./taller_client  <hostname> 8080
````

### Ejemplo
- Servidor: 
````bash  
./taller_server
````
- Cliente:
````bash  
/taller_client 127.0.0.1 8080
````
