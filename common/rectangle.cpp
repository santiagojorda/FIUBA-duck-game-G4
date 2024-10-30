#include "rectangle.h"


int length_x(const Coordinate& c) { return c.get_h() - c.get_x(); }
int length_y(const Coordinate& c) { return c.get_w() - c.get_y(); }

Rectangle::Rectangle() {}

Rectangle::Rectangle(Coordinate coordinate):
        points(coordinate.get_x(), coordinate.get_y(), coordinate.get_x() + coordinate.get_w(),
               coordinate.get_y() + coordinate.get_h()) {}

Rectangle::Rectangle(int x_min, int y_min, int x_max, int y_max):
        points(x_min, y_min, x_max, y_max) {}


bool Rectangle::operator==(const Rectangle& other) const {
    int this_area = length_x(this->points) * length_y(this->points);
    int other_area = length_x(other.points) * length_y(other.points);

    return this_area == other_area;
}


bool Rectangle::operator<(const Rectangle& other) const {
    int this_area = length_x(this->points) * length_y(this->points);
    int other_area = length_x(other.points) * length_y(other.points);

    return this_area < other_area;
}


bool Rectangle::operator>(const Rectangle& other) const {
    int this_area = length_x(this->points) * length_y(this->points);
    int other_area = length_x(other.points) * length_y(other.points);

    return this_area > other_area;
}

bool Rectangle::operator<=(const Rectangle& other) const {
    return this->operator==(other) || this->operator<(other);
}

bool Rectangle::operator>=(const Rectangle& other) const {
    return this->operator==(other) || this->operator>(other);
}

Rectangle Rectangle::operator*(int escale) const {
    return Rectangle(this->points.get_x(), this->points.get_y(),
                     this->points.get_h() + (escale / 2), this->points.get_w() + (escale / 2));
}

Rectangle Rectangle::operator/(int escale) const {
    return Rectangle(this->points.get_x(), this->points.get_y(),
                     this->points.get_h() - (escale / 2), this->points.get_w() - (escale / 2));
}

Coordinate Rectangle::get_points() const { return this->points; }

Coordinate Rectangle::get_coordinates() const {
    int x = this->points.get_x();
    int y = this->points.get_y();
    int h = this->points.get_w() - this->points.get_y();
    int w = this->points.get_h() - this->points.get_x();
    return Coordinate(x, y, h, w);
}

int Rectangle::get_x_min() const { return this->points.get_x(); }

int Rectangle::get_x_max() const { return this->points.get_h(); }

int Rectangle::get_y_min() const { return this->points.get_y(); }

int Rectangle::get_y_max() const { return this->points.get_w(); }

Rectangle::~Rectangle() {}
