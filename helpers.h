#include "include.h"
#ifndef HELPER_H
#define HELPER_H


std::string get_file();
bool enter();
int path();
void read_line(std::string, Node**); // opens file, getsline, passes line to parse_line
void parse_line(std::string, int, int, Node**); // receives line and assigns data to new node, assigns node to spot in matrix
//template<class T>
void path_find_s(double &, int, Node**, Position<int> current);
void path_find_g(double &, int, Node**, Position<double> current);
void print_map(Node**);
//void populate_matrix(**);
void get_trucks(double &gas, int &capacity);
bool whichtruck();
void display_truck();
bool our_truck(double &gas, int &capacity);
void own_truck(double &gas, int &capacity);
 


#endif