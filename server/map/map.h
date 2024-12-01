#ifndef MAP
#define MAP

#include <memory>
#include <vector>
#include <cmath>
#include "../attributes/positionable.h"
#include "../game/list_items_map.h"
#include "list_floor.h"

#define MAX_HEIGHT 500
#define MAX_WIDTH 800
#define CELL_SIZE 16

class Cell{
private:
    std::shared_ptr<Ground> item;
    int col;
    int row;
public:
    Cell() : col(0), row(0) {}
    Cell(int _col, int _row)
        : col(_col), row(_row) {}

    int get_row() const { return row; }
    int get_col() const { return col; }

    int get_pos_x() const { return col * 16; }
    int get_pos_y() const { return row * 16; }
    std::shared_ptr<Ground> get_item() { return item; }
    void set_item(Ground newItem) { item = std::make_shared<Ground>(newItem); }
    void clear() { item.reset(); }
    bool is_ocuppied() { return item != nullptr; }
};

class Map {
private:
    std::vector<std::vector<Cell>> grid;
    ListFloors floors;

public:
    Map() {
        int num_cells_x = std::ceil(static_cast<double>(MAX_WIDTH) / CELL_SIZE);
        int num_cells_y = std::ceil(static_cast<double>(MAX_HEIGHT) / CELL_SIZE);
        grid.resize(num_cells_x);
        for (int x = 0; x < num_cells_x; x++) {
            grid[x].resize(num_cells_y);
            for (int y = 0; y < num_cells_y; y++) {
                grid[x][y] = Cell(x, y);
            }
        }
    }

    bool is_valid_cell(int col, int row) { return (row >= 0 && row < (int)grid[0].size()) && (col >= 0 && col < (int)grid.size()); }
    Cell& get_cell(int pixel_x, int pixel_y) {
        int row = pixel_y / CELL_SIZE;
        int col = pixel_x / CELL_SIZE;
        if (!is_valid_cell(col, row)) {
            throw std::out_of_range("La posición está fuera del rango del mapa.");
        }
        return grid[col][row];
    }

    void add(int pixel_x, int pixel_y, Ground new_floor){
        get_cell(pixel_x, pixel_y).set_item(new_floor);
        floors.add(get_cell(pixel_x, pixel_y).get_item());
    }

    ListFloors& get_floors() { return floors;}
    uint8_t size() {
        return floors.size();
    }
    ~Map() { 
        // grid.clear(); 
    }
};

#endif
