#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "Model.h"
#include "View.h"
#include <iomanip>
#include <iostream>

using namespace std;

View::View() // the deafult constructor that insitilises the member variables 
{
    size=11;
    origin.x=0;
    origin.y=0;
    scale=2;
    
}

bool View::get_subscripts (int &ix,int &iy,Cart_Point location) // caluclates the x and y values for a specified locaation. 
{
    ix=(location.x-origin.x)/(2);
    iy=(location.y-origin.y)/(2);
    if ((ix<=11) && (iy<=11))
    {
        return true;
    }
    else // if the location is beyond the size of the grid which is 11
    {
        cout<<"An object is outside the display"<<endl;
        return false;
    }
    
}


void View::plot(Game_Object * ptr) //plots the character in the grid. 
{
    int x_cord=0;
    int y_cord=0;
    if(get_subscripts(x_cord,y_cord,(*ptr).get_location())) // checking to see if get_subscripts is valid. 
    {
        {
            (ptr)->drawself(grid[x_cord][y_cord]); // calls drawself if valid.
        }
       
     
    }
    return;
}
    





void View::draw() //producing the display
{
    for (int j=10;j>=0;j--)
    {
        if (j%2==0)
        {
            cout<<setw(2)<<left<<2*(j); // setting the width of the field to 2. 
        }
        else
        {
            cout<<"  ";
        }
        for (int i=0; i<11;i++)
        {
        cout<<grid[i][j][0]<<grid[i][j][1]; 
        }
        cout<<endl;
    }
    cout<<"  "; // space between scale on y-axis
    for (int c=0;c<=10;c=c+2)
        {
            cout<<c*2<<"   "; // space between the scale on the x-axis. 
        }
    cout<<endl; // end the line at the end of the grid. 

}



void View::clear() // creates the speficied backgorund of dots and spaces. 
{
    for (int X=0;X<11;X++) // for the x axis 
    {
        for (int Y=0;Y<11;Y++) // for the y axis
        {
            grid[X][Y][0]='.'; // outputs . first
            grid[X][Y][1]=' '; //then outputs space between each dot. 
        }
    }
}


