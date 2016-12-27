#include <iostream>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Miner.h"
#include "Person.h"
#include "Game_Command.h"
#include "Model.h"
#include "View.h"
#include <string>

int main()
{   

    initial_output(); //This is what will be initially output (EC327:Introduction to software...etc)
    Model model; 
    View view;
    
    model.show_status();
    view.clear();
    model.display(view);
    view.draw();
    
    
    char command_code; // the command code the user will enter  (each code corresponds to a function that will run from command.cpp,.
    do
    {
    cout<<"Enter command: ";
    cin>>command_code; //only inputs the command code, the rest is taken care of in each fucntion when it is called from my command handling fucntion below, I did not endl so that the input can continue on the same line.
    command_handling(command_code,view, model);
    if (command_code!='q') // if the user hits q to quit the program there is no need to draw the grid at the end.
    {
        view.draw();
    }
   
    }while(command_code!='q'); // the program will keep asking the user for the next command until the user hits quit. 
   

    return 0;
}


