#ifndef DRAWER_H
#define DRAWER_H

class Drawer {
private:
public:
    /*
     * Constructor.
     */
    Drawer();

    /*
     *
     */
    void run();

    /*
     * Deshabilitar copias.
     */
    Drawer(const Drawer&) = delete;
    Drawer& operator=(const Drawer&) = delete;
};

#endif  // DRAWER_H
