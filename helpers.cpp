#include "include.h"

std::string get_file()
   {
       int count = 0;
       std::string _file;
       std::cout << "Please enter the file name.\n-> ";
       std::cin >> _file;
       std::ifstream file;
       file.open(_file);
       while(file.fail())
       {
          count++;
          std::cout<< "It seems that that file does not exist please try again\n-> ";
          std::cin >> _file;
          file.open(_file);
          if(!file.fail())
          {
              file.clear();
          }
          if(count == 4)
           {
               std::cout << "It seems that you are having trouble opening a file, would you like to exit the program?\nPlease enter yes or no\n-> ";
               bool _enter = enter();
               if(_enter)
               {
                   _file = "nofile";
                   return _file;
               }
               count = 0;
           }
       }
       return _file;
   };

   bool enter()
    {
   bool return_value;
   std::string yes_no;
   bool reprompt = false;
       while(!reprompt) // this is the first instance of input validation which only accepts yes or Yes or No or no and will keep prompting until valid
       {
           if(std::cin.fail()) std::cin.ignore(100,'\n'); // ignores the flag on the error
           std::cin >> yes_no;
           if(yes_no =="yes" || yes_no =="Yes")// the logic below compares the string to the 4 possible values, and then returns true or false to either enter the if statement or skip to the else statement in the main function
           {
               reprompt = true;
               return_value = true;
           }
           else if (yes_no =="no" || yes_no =="No")
           {
               reprompt = true;
               return_value = false;
           }
           else
           {
               std::cout<<"Please enter yes or no only\n-> ";
           }
       }
   return return_value;
} 

int path()
{
    std::cout<< "With the data that has been provided, we can run three different test on the data \n";
    std::cout<< "Option one will find the most fuel efficient route but will not maximize people served \n";
    std::cout<< "Option two will find the route that serves the most people but will not maximize fuel \n";
    std::cout<< "Option three will cover the most area for 12 gallons of gas \n";
    std::cout << "Please type in the interger 1,2,3 to choose the path you would like to choose \n";
    int decision;
    std::cin >> decision;
    while(std::cin.fail()) // only allows the user to enter a number of 1,2,3. acts as simple input validation 
    {
        std::cin.clear();// clears flag from cin.ignore() and ignores new data on each iteration 
        std::cin.ignore(250 , '\n');
        std::cout << "It Seems like you didn't provide a propper choice, please try again";
        std::cin >> decision;
    }
    std::cout<<"Before return ";
    return decision;

}

void read_line(std::string file, Node** matrix)
{
    std::ifstream in;
    in.open(file);
    std::string Ssize_of_matrix;
    getline(in,Ssize_of_matrix);
    int size_of_matrix = std::stoi(Ssize_of_matrix);

    for(int i = 0; i < size_of_matrix; i++)
    {
        matrix[i] = new Node[size_of_matrix];
    }
    std::string line;
    for (int i = 0; i < size_of_matrix; i++)
    {
        getline(in,line);
        parse_line(line, i, size_of_matrix, matrix);
    }
}
/**
 * @brief 
 * 
 * @param line 
 * @param position 
 * @param size 
 * @param matrix 
 */
void parse_line(std::string line, int position, int size, Node** matrix)
{
    std::stringstream ss(line);

    for(int i = 0; i < size; i++)
    {
       
        double gallons;
        int served;
        ss >> gallons >> served;
        matrix[position][i] = Node(gallons,served);
    }
    
}

void path_find_s(double &gas, int capacity, Node** matrix, Position <int> current)
{
  matrix[0][0].set_order(1);
  int count = 2;
   matrix[current.get_x()][current.get_y()].set_visited(1); // sets initial to 1 to stop from going again
    //PASS IN SIZE
  int SIZE = 5;
  int current_capacity;
  gas = gas - matrix[0][0].get_gallons();
  Position<int> temp = current;
  temp.set_value(100000);
  while( gas > 0 )//|| current_capacity < capacity)
  {
        Position <int> picked(0);
        Position <int> up = temp.next_s( temp.get_x(),  (temp.get_y() - 1),  SIZE,  matrix);
        Position <int> up_right = temp.next_s( temp.get_x() + 1,  (temp.get_y() - 1),  SIZE,  matrix);
        Position <int> right = temp.next_s( temp.get_x() + 1,  (temp.get_y()),  SIZE,  matrix);
        Position <int> right_down = temp.next_s( temp.get_x() + 1 ,  (temp.get_y() + 1),  SIZE,  matrix);
        Position <int> down = temp.next_s( temp.get_x(),  (temp.get_y() + 1),  SIZE,  matrix);
        Position <int> left_down = temp.next_s( temp.get_x() - 1,  (temp.get_y() + 1),  SIZE,  matrix);
        Position <int> left = temp.next_s( temp.get_x() -1 ,  (temp.get_y() ),  SIZE,  matrix);
        Position <int> left_up = temp.next_s( temp.get_x() -1,  (temp.get_y() +1 ),  SIZE,  matrix);
        Position<int> arr[] = {up, up_right,right,right_down,down,left_down,left,left_up};
        for(int i = 0; i < 8; i++)
        {   
            
            std::cout << "\nvalues : "<< arr[i].get_value() ;
            if(picked.get_value() < arr[i].get_value() &&  arr[i].get_value()!=-1 && matrix[arr[i].get_x()][arr[i].get_y()].get_visited()==0)  
            {
                picked = arr[i];
                std::cout << "swap";
            }
        }
        matrix[picked.get_x()][picked.get_y()].set_order(count);
        count++;
        std::cout << "\n-------------------------------------\n";
        gas -= matrix[picked.get_x()][picked.get_y()].get_gallons();
        capacity -= matrix[picked.get_x()][picked.get_y()].get_served();
        matrix[picked.get_x()][picked.get_y()].set_visited(1);
        temp = picked;
        std::cout << temp.get_value();
        std::cout << "\n-------------------------------------\n";

    /**
     * @brief 
     * compare all data and find biggest 
     * subtract gas at that node
     * subtract people served at that node from capacity 
     * change the temp node, to the new nodes position
     * run algo again while still in loop
     * 
     */
    //std::cout << right.get_x() << ", " << right.get_y() << "\n";
  }
    

}

// basic map
// void print_map(Node** matrix)
// {
//   for(int i = 0; i < 5; i++)
//   {
//     for(int j = 0; j < 5; j++)
//       {
//         if(matrix[i][j].get_visited() == 0)
//         {
//           std::cout << "[" << std::setfill('0') << std::setw(2) << 0 << "]";
//         }
//         else std::cout << "[" << std::setfill('0') << std::setw(2) << 1 << "]";
//       }
//     std::cout << "\n";
//   }
// }


void print_map(Node** matrix)
{
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
      {
        std::cout << "[" << std::setfill('0') << std::setw(2) << matrix[i][j].get_order() << "]";
      //   if(matrix[i][j].get_visited() == 0)
      //   {
      //     std::cout << "[" << std::setfill('0') << std::setw(2) << 0 << "]";
      //   }
      //   else std::cout << "[" << std::setfill('0') << std::setw(2) << matrix[i][j].get_order() << "]";
       }
      
    std::cout << "\n";
  }
}
 