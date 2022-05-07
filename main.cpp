#include "helpers.h"

 int main()
 {  
    double gas;
    int capacity;
    std::string _file = get_file();
    int SIZE = get_size(_file);
    Node** matrix = new Node*[SIZE];
    read_line(_file, matrix);
    get_trucks(gas,capacity);
    Position<double> start(0);
    path_find_g(gas,capacity,matrix,start,SIZE);
    print_map( matrix);
 }