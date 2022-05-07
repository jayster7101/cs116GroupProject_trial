#include "helpers.h"

 int main()
 {  
    double gas;
    int SIZE = 5;
    int capacity;
    Node** matrix = new Node*[SIZE];
    std::string _file = get_file();
    read_line(_file, matrix);
    get_trucks(gas,capacity);
    Position<double> start(0);
    path_find_g(gas,capacity,matrix,start);
    print_map( matrix);
 }