#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "Model.h"
#include "Game_Command.h"
#include <iostream>

char command_code;
using namespace std;

void command_handling(char command_code, View &view, Model &model) // This my own command handling function that analyses the user input of each command, I use a switch statment to do so 
{
    switch (command_code)
    {
        case 'm':
            do_move_command(model,view);
            break;
        case 'l':
            list_command(model,view);
            break;
        case 's':
            stop_command(model,view);
            break;
        case 'q':
            cout<<"Terminating program"<<endl; // This case ends the prgoram (ie. when the user hits q)
            break;
        case 'g':
            do_go_command(model,view);
            list_command(model, view);// outputs the status after the go command (g)
            break;
        case 'w':
            do_work_command(model,view);
            break;
        case 'r':
            do_run_command(model,view);
            list_command(model,view); // outputs the status after the go command (g)
            break;
            
    }
}

void  do_move_command(Model &model, View &view) // Command the miner ID to move to destination_loc whihc is a cart_point
{
    int ID;
    double xcord;
    double ycord;
    cin>>ID>>xcord>>ycord;
    Cart_Point destination_loc;
    destination_loc.x=xcord;
    destination_loc.y=ycord;
    Person* person_move;
    person_move=model.get_Person_ptr(ID); // I use this to get the Miner with the supplied ID.
    person_move->start_moving(destination_loc); // This is telling the person to start moving (start moving is a function in person)
    view.clear();
    model.display(view);
    return;
}

void do_work_command(Model &model, View &view) // Comand the miner id1 to start mining at gold_mine id2 and deposit at town_hall id3
{
    int id1;
    int id2;
    int id3;
  cin>>id1>>id2>>id3;
  Person* person_work;
  Town_Hall* townhall3;
  Gold_Mine* goldmine2;
  townhall3=model.get_Town_Hall_ptr(id3);
  goldmine2=model.get_Gold_Mine_ptr(id2);
  person_work= model.get_Person_ptr(id1);
  person_work->start_mining(goldmine2,townhall3); // start mining is a function in Miner class
    view.clear();
    model.display(view);
  return;
}
  
    



void stop_command(Model &model, View &view)// stop the miner ID 
{
    int id;
    cin>>id;
    Person* minerstop; 
    minerstop=model.get_Person_ptr(id);
    minerstop->stop(); // this is a function in miner. 
    view.clear();
    model.display(view);
}


void do_go_command(Model &model,View &view)
{
    cout<<"Advancing one tick."<<endl;
    model.update(); // Updates all objects.
    view.clear();
    model.display(view);
}


void list_command(Model &model, View &view) // ouputs the status (I call this in my command_handling function at the top)
{
    model.show_status();
}

void do_run_command(Model &model, View &view) // this command updates each object until one returns false or 5 steps are taken. I use a while loop 
{
    int c;//counter for the number of steps (should be less than 5)
    c=0;
    cout<<"Advancing to next event."<<endl;
    while (!(model.update()) && c<5)
    {
        c++;
    }
view.clear();
model.display(view);
return ;
    
}

void initial_output() // This is the first thing that will output when the program runs
{
    cout<<"EC327: Introduction to Software Engineering"<<endl;
    cout<<"Fall 2016"<<endl;
    cout<<"Programming Assignment 3"<<endl;
}








