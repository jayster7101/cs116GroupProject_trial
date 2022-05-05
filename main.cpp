#include "helpers.h"

 int main()
 {  
    double gas = 12;
    int SIZE = 5;
    int capacity = 250;
    Node** matrix = new Node*[SIZE];
    std::string _file = get_file();
    read_line(_file, matrix);
     Position<int> start(0);
     path_find_s(gas,capacity,matrix,start);
    print_map( matrix);

 }