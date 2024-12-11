#!/bin/bash

# Paso 1: Instalar dependencias
sudo apt-get update
sudo apt-get install -y \
    libjpeg-dev libpng-dev libfreetype-dev libopusfile-dev libflac-dev libxmp-dev \
    libfluidsynth-dev libwavpack-dev cmake libmodplug-dev libsdl2-dev \
    qtcreator qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools \
    libqt5charts5-dev libqt5datavisualization5-dev libqt5gamepad5-dev \
    libqt5gstreamer-dev libqt5networkauth5-dev libqt5opengl5-dev \
    libqt5remoteobjects5-dev libqt5scxml5-dev libqt5sensors5-dev \
    libqt5serialbus5-dev libqt5serialport5-dev libqt5svg5-dev \
    libqt5texttospeech5-dev libqt5virtualkeyboard5-dev libqt5waylandclient5-dev \
    libqt5waylandcompositor5-dev libqt5webkit5-dev libqt5webchannel5-dev \
    libqt5websockets5-dev libqt5webview5-dev libqt5x11extras5-dev \
    libqt5xmlpatterns5-dev qtmultimedia5-dev

# Paso 2: Descargar los archivos ZIP
mkdir -p sdl_libs && cd sdl_libs
wget -q https://github.com/libsdl-org/SDL_image/releases/download/release-2.6.3/SDL2_image-2.6.3.zip
wget -q https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.6.3/SDL2_mixer-2.6.3.zip
wget -q https://github.com/libsdl-org/SDL_ttf/releases/download/release-2.20.2/SDL2_ttf-2.20.2.zip

# Descomprimir los archivos
for file in *.zip; do
    unzip -q "$file"
done

# Paso 3: Construir e instalar las bibliotecas SDL
for dir in SDL2_*; do
    cd "$dir"
    mkdir -p build
    cd build
    cmake ..
    make -j4
    sudo make install
    cd ../..
done

# Paso 4: Construir el proyecto FIUBA-duck-game-G4
cd .. # Volver al directorio base
if [ ! -d "FIUBA-duck-game-G4" ]; then
    echo "Error: No se encontró el directorio FIUBA-duck-game-G4. Por favor, clona el repositorio."
    exit 1
fi

mkdir -p build
cd build
cmake ..
sudo make install

echo "Instalación completada exitosamente."
