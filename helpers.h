#include "include.h"
#ifndef HELPER_H
#define HELPER_H


std::string get_file();
bool enter();
bool greet();
bool again();

void path(D_truck, Node** matrix, int SIZE);

void read_line(std::string, Node**); // opens file, getsline, passes line to parse_line
void parse_line(std::string, int, int, Node**); // receives line and assigns data to new node, assigns node to spot in matrix
//template<class T>
void path_find_s(D_truck, Node**, Position<int> current, int); // finds the next best path for people served
void path_find_g(D_truck, Node**, Position<double> current, int);// finds the next best path for gas useage
void print_map(Node**); // prints simple map
//void populate_matrix(**);
int get_size(std::string);

// Trucks *Needs changing for classes*
D_truck get_trucks();

bool whichtruck();
void display_truck();
D_truck our_truck(); // returns one of the three predefined trucks
D_truck own_truck();
double get_gas_price(); // gets the current gas price from user 
bool continue_delivery(double price, double used, int);
bool enter();// gets the answer to yes and no questions

// Template functions
template<typename T>
Position<T> nearest_gas_station(Position<T> current_position, int size, Node** matrix);
template<typename T>
Position<T> find_g(Position<T>,int,int,Node**);
template<typename T>
Position<T> find_s(Position<T>,int,int,Node**);
std::ostream& operator<<(std::ostream& out,  Node& classObj);


#endif