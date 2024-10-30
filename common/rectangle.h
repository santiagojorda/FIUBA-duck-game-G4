#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "coordinate.h"

class Rectangle {
private:
    Coordinate points;

public:
    Rectangle();

    /*
    / Inicia con el siguiente formato (x, y , x+w, y+h )
    */
    Rectangle(Coordinate _points);


    Rectangle(int x_min, int y_min, int x_max, int y_max);

    /*
    /  compara  tamaño de los rectangulos
    */
    bool operator==(const Rectangle& other) const;

    /*
    /  compara  tamaño de los rectangulos
    */
    bool operator<(const Rectangle& other) const;

    /*
    /  compara  tamaño de los rectangulos
    */
    bool operator>(const Rectangle& other) const;

    /*
    /  compara  tamaño de los rectangulos
    */
    bool operator<=(const Rectangle& other) const;

    /*
    /  compara  tamaño de los rectangulos
    */
    bool operator>=(const Rectangle& other) const;

    /*
    /  escala el tamaño del rectangulo
    */
    Rectangle operator*(int escale) const;

    /*
    /  decrece el tamaño del rectangulo
    */
    Rectangle operator/(int decrease) const;

    /*
    /  coordenada en formato (x, y, x+w, y+h)
    */
    Coordinate get_points() const;

    /*
    /  coordenada en formato (x, y, h, w)
    */
    Coordinate get_coordinates() const;

    int get_x_min() const;

    int get_x_max() const;

    int get_y_min() const;

    int get_y_max() const;

    ~Rectangle();
};


#endif  // RECTANGLE_H
