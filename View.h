#ifndef VIEW_H
#define VIEW_H

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "Model.h"
#include <iostream>

const int view_maxsize=20;

class View
{
    
private:
    int size;
    double scale;
    Cart_Point origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int &ix, int &iy, Cart_Point location);

public:
    View();
    void clear();
    void plot(Game_Object * ptr);
    void draw();
};
    



#endif /* View_h */
