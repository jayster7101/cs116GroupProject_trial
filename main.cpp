#include "include.h"

 int main()
 {  
    bool enter = greet();
    if(enter)
    {
    double gas;
    int capacity;
    std::string _file = get_file();
      while(enter && _file != "nofile")
      {
         int SIZE = get_size(_file);
         Node** matrix = new Node*[SIZE];
         read_line(_file, matrix);
         D_truck user = get_trucks();
         path(user,matrix,SIZE);
         print_map(matrix);
         enter = again();
      }
    }
 }