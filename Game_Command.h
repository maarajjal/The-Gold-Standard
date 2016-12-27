#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "Model.h"
#include <iostream>

void command_handling(char command_code, View &view, Model &model);
void do_move_command(Model &model, View &view);
void do_go_command(Model &model, View &view);
void do_work_command(Model &model,View &view);
void do_run_command(Model &model,View &view);
void stop_command(Model &model,View &view);
void list_command(Model &model, View &view);
void initial_output();











#endif /* Game_Command_h */
