#include "include.h"
#ifndef HELPER_H
#define HELPER_H


std::string get_file();
bool enter();
int path();
void read_line(std::string, Node**); // opens file, getsline, passes line to parse_line
void parse_line(std::string, int, int, Node**); // receives line and assigns data to new node, assigns node to spot in matrix
//template<class T>
void path_find_s(double &, int, Node**, Position<int> current, int); // finds the next best path for people served
void path_find_g(double &, int, Node**, Position<double> current, int);// finds the next best path for gas useage
void print_map(Node**); // prints simple map
//void populate_matrix(**);
int get_size(std::string);
void get_trucks(double &gas, int &capacity);
bool whichtruck();
void display_truck();
bool our_truck(double &gas, int &capacity);
void own_truck(double &gas, int &capacity);
double get_gas_price(); // gets the current gas price from user 
bool continue_delivery(double price, double used);
bool enter();
template<typename T>
Position<T> nearest_gas_station(Position<T> current_position, int size, Node** matrix);
template<typename T>
Position<T> find_g(Position<T>,int,int,Node**);
template<typename T>
Position<T> find_s(Position<T>,int,int,Node**);
std::ostream& operator<<(std::ostream& out,  Node& classObj);


#endif