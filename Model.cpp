#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "Model.h"
#include "View.h"

using namespace std;

Model::Model() // deafult constructor, creating new objects as speceficed in the assignmenment, each with their own id and initial location. Pointers to these objecrs are stored in their respective arrays. 
{
    time=0;
    Miner* Miner1= new Miner(1,Cart_Point(5,1));
    object_ptrs[0]=Miner1;
    person_ptrs[0]=Miner1;
    Miner* Miner2= new Miner(2,Cart_Point(10,1));
    object_ptrs[1]=Miner2;
    person_ptrs[1]=Miner2;
    Gold_Mine* GoldMine1=new Gold_Mine (1,Cart_Point(1,20));
    object_ptrs[2]=GoldMine1;
    mine_ptrs[0]=GoldMine1;
    Gold_Mine* GoldMine2=new Gold_Mine (2,Cart_Point(10,20));
    object_ptrs[3]=GoldMine2;
    mine_ptrs[1]=GoldMine2;
    Town_Hall* TownHall1=new Town_Hall(1,Cart_Point(0,0));
    object_ptrs[4]=TownHall1;
    hall_ptrs[0]=TownHall1;
    num_objects=5;
    num_persons=2;
    num_mines=2;
    num_halls=1;
    cout<<"Model constructed."<<endl;
    
}



Person* Model::get_Person_ptr(int id) // returns a pointer to the person with id. 
{
  for(int i=0;i<(num_persons);i++) // iterating through the array. 
  {
        if((*person_ptrs[i]).get_id()==id) //checking if any object has the same id. 
           {
               return person_ptrs[i];
    
           }
   }
    return 0;
}
           

Gold_Mine* Model::get_Gold_Mine_ptr(int id) //returns a pointer to the goldmine with id
{
  for(int i=0;i<(num_mines);i++)
   {
       if((*mine_ptrs[i]).get_id()==id)
        {
            return mine_ptrs[i];
        }
   }
    return 0;
}
           

           
Town_Hall* Model::get_Town_Hall_ptr(int id) // returns a pointer to townhall with id
{
  for(int i=0;i<(num_halls);i++)
   {
     if((*hall_ptrs[i]).get_id()==id)
        {
            return hall_ptrs[i];
        }
  
   }
    return 0;
}
           
void Model::show_status()
{
   
  cout<<"Time: "<<time<<endl; //I put this one here because I want the time to appear before the grid display.
  for(int i=0;i<(num_objects);i++)
    {
        (*object_ptrs[i]).show_status();
    }
return ;
}
            

           
bool Model::update() // increments the time and updates each object. 
{
    time=time+1;
    bool obj_updated;
    obj_updated=false;
    for(int i=0;i<(num_objects);i++)
    {
        if ((*object_ptrs[i]).update())
            obj_updated=true;
    }
    
return obj_updated;
    
}




Model::~Model() // The destructor, I delete all the objects I used. 
{
    delete object_ptrs[0];
    delete object_ptrs[1];
    delete object_ptrs[2];
    delete object_ptrs[3];
    delete object_ptrs[4];
    cout<<"Model destructed"<<endl;
}



void Model::display(View &view) // this is the function that generates the display for the game_objects
{
    view.clear();
    for (int i=0;i<num_objects;i++)
    {
        view.plot(object_ptrs[i]);
    }
}


    

