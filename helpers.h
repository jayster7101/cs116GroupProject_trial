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
void print_map(Node**);
//void populate_matrix(**);
 


#endif