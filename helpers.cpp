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
  
  int current_capacity = 0;
  gas = gas - matrix[0][0].get_gallons();
  Position<int> temp = current;
  temp.set_value(100000);
  while( gas > 0 && current_capacity < capacity)
  {
        bool swap = false;
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
            if(matrix[arr[i].get_x()][arr[i].get_y()].get_visited()!=0){std::cout <<" visited";} 
            if(picked.get_value() < arr[i].get_value() &&  arr[i].get_value()!=-1 && matrix[arr[i].get_x()][arr[i].get_y()].get_visited()==0)  
            {
                picked = arr[i]; // next position
                std::cout << " swap";
                swap = true;
            }
        }
        matrix[picked.get_x()][picked.get_y()].set_order(count);
        count++;
        std::cout << "\n-------------------------------------\n";
        gas -= matrix[picked.get_x()][picked.get_y()].get_gallons();
        capacity -= matrix[picked.get_x()][picked.get_y()].get_served();
        matrix[picked.get_x()][picked.get_y()].set_visited(1);
        std::cout << picked.get_value();
        std::cout << "\n-------------------------------------\n";
        
        if(swap){temp = picked;}else {matrix[0][0].set_order(1);gas = -1;} //current to next swap if we find a square to swap to

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

void path_find_g(double &gas, int capacity, Node** matrix, Position <double> current)
{
  matrix[0][0].set_order(1);
  int count = 2;
  matrix[current.get_x()][current.get_y()].set_visited(1); // sets initial to 1 to stop from going again
    //PASS IN SIZE
  int SIZE = 5;
  int current_capacity = 0;
  gas = gas - matrix[0][0].get_gallons();
  Position<double> temp = current;
  temp.set_value(100000);
  while( gas > 0 && current_capacity < capacity)
  {     
        bool swap = false;
        Position <double> picked(1000);
        Position <double> up = temp.next_g( temp.get_x(),  (temp.get_y() - 1),  SIZE,  matrix);
        Position <double> up_right = temp.next_g( temp.get_x() + 1,  (temp.get_y() - 1),  SIZE,  matrix);
        Position <double> right = temp.next_g( temp.get_x() + 1,  (temp.get_y()),  SIZE,  matrix);
        Position <double> right_down = temp.next_g( temp.get_x() + 1 ,  (temp.get_y() + 1),  SIZE,  matrix);
        Position <double> down = temp.next_g( temp.get_x(),  (temp.get_y() + 1),  SIZE,  matrix);
        Position <double> left_down = temp.next_g( temp.get_x() - 1,  (temp.get_y() + 1),  SIZE,  matrix);
        Position <double> left = temp.next_g( temp.get_x() -1 ,  (temp.get_y() ),  SIZE,  matrix);
        Position <double> left_up = temp.next_g( temp.get_x() -1,  (temp.get_y() +1 ),  SIZE,  matrix);
        Position<double> arr[] = {up, up_right,right,right_down,down,left_down,left,left_up};
        for(int i = 0; i < 8; i++)
        {   
            
            std::cout << "\nvalues : "<< arr[i].get_value() ;
            if(matrix[arr[i].get_x()][arr[i].get_y()].get_visited()!=0){std::cout <<" visited";} 
            if(picked.get_value() > arr[i].get_value() &&  arr[i].get_value()!=-1 && matrix[arr[i].get_x()][arr[i].get_y()].get_visited()==0)  
            {
                picked = arr[i];
                std::cout << "swap";
                swap = true;
            }
        }
        matrix[picked.get_x()][picked.get_y()].set_order(count);
        count++;
        std::cout << "\n-------------------------------------\n";
        gas -= matrix[picked.get_x()][picked.get_y()].get_gallons();
        capacity -= matrix[picked.get_x()][picked.get_y()].get_served();
        matrix[picked.get_x()][picked.get_y()].set_visited(1);
        if(swap){temp = picked;}
        std::cout << picked.get_value();
        std::cout << "\n-------------------------------------\n";
        if(swap){temp = picked;}else { matrix[0][0].set_order(1);gas = -1;}
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


void get_trucks(double &gas, int &capacity)
{
  bool truckchoice = whichtruck();
  if (truckchoice)
  {
    display_truck();
    our_truck(gas, capacity);
  }
  else
  {
    own_truck(gas, capacity);
  }
}

bool whichtruck()
{
  std::string input;
  std::cout<<"Would you like to:\n";
  std::cout<<"1. Use one of our trucks\n";
  std::cout<<"2. Use your own truck\n";
  while (true)
    {
      std::cout<<"(please choose '1' or '2')\n";
      std::cin>>input;
      if (input=="1")
      {
        return true;
      }
      else if (input == "2")
      {
        return false;
      }
      else 
      {
        std::cout<<"Error. ";
      }
    }
}

void display_truck()
{
  std::cout << "\nWhich truck would you like to select?\n";
  std::cout<<"\n-Truck 1-\nFuel Tank Capacity: 7 gallons\nAmount Of People That Can Be Served: 250\n";
  std::cout<<"\n-Truck 2-\nFuel Tank Capacity: 10 gallons\nAmount Of People That Can Be Served: 480\n";
  std::cout<<"\n-Truck 3-\nFuel Tank Capacity: 15 gallons\nAmount Of People That Can Be Served: 650\n";
}

bool our_truck(double &gas, int &capacity)
{
  std::string input;
  while (true)
    {
      std::cout << "(Please enter '1','2' or '3')\n\n";
      std::cin >> input;
      if (input == "1")
      {
        gas = 7;
        capacity = 250;
        return true;
      }
      else if (input == "2")
      {
        gas = 10;
        capacity = 480;
        return true;
      }
      else if (input == "3")
      {
        gas = 15;
        capacity = 650;
        return true;
      }
      else
      {
        std::cout << "Error. \n";
      }
    }
}

void own_truck(double &gas, int &capacity)
{
  double input1;
  int input2;
  std::cout << " - For Your Truck -\n";
  std::cout <<"Enter fuel tank capacity (in gallons): ";
  std::cin>>input1;
  std::cout << "Enter amount of people that can be served: ";
  std::cin>>input2;
  gas = input1;
  capacity = input2;
}