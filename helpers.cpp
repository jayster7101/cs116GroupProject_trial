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


void path(D_truck user, Node** matrix, int SIZE)
{
    std::cout<< "With the data that has been provided, we can run three different test on the data \n";
    std::cout<< "Option one will find the most fuel efficient route but will not maximize people served \n";
    std::cout<< "Option two will find the route that serves the most people but will not maximize fuel \n";
    std::cout<< "Option three will cover the most area for however many gallons of gas that you specify \n";
    std::cout << "Please type in the interger 1,2,3 to choose the path you would like to choose \n";
    int decision;
    std::cin >> decision;
    while(std::cin.fail() || decision <= 0 || decision > 3) // only allows the user to enter a number of 1,2,3. acts as simple input validation 
    {
        std::cin.clear();// clears flag from cin.ignore() and ignores new data on each iteration 
        std::cin.ignore(250 , '\n');
        std::cout << "It Seems like you didn't provide a propper choice, please try again";
        std::cin >> decision;
    }
    std::cout<<"Before return ";
  if (decision == 1)
  {
    Position<double> start(0);
    path_find_g(user, matrix, start, SIZE);
  }
  else if (decision == 2)
  {
    Position<int> start(0);
    path_find_s(user, matrix, start, SIZE);
  }
  else if (decision == 3)
  {
    Position<double> start(0);
    path_find_g(user, matrix, start, SIZE);
  }

}

void read_line(std::string file, Node** matrix)
{
    std::ifstream in;
    in.open(file);
    std::string Ssize_of_matrix;
    getline(in,Ssize_of_matrix);
    int size_of_matrix = std::stoi(Ssize_of_matrix);
    //matrix = new Node*[size_of_matrix];

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

int get_size(std::string file)
{ 
  std::ifstream in;
  in.open(file);
  std::string Ssize_of_matrix;
  getline(in,Ssize_of_matrix);
  int size_of_matrix = std::stoi(Ssize_of_matrix);
  return size_of_matrix;
}


// void path_find_s(double &gas, int capacity, Node** matrix, Position <int> current, int SIZE)
// {
//   //gas = D_truck.get_gas();
  
//   matrix[0][0].set_order(1);
//   int count = 2;
//    matrix[current.get_x()][current.get_y()].set_visited(1); // sets initial to 1 to stop from going again
//     //PASS IN SIZE
  
//   int current_capacity = 0;
//   gas = gas - matrix[0][0].get_gallons();
//   Position<int> temp = current;
//   temp.set_value(100000);
//   while( gas > 0 && current_capacity < capacity) // D_truck.get_cap();
//   {
//         Position <int> picked(0);
//         Position <int> up = temp.next_s( temp.get_x(),  (temp.get_y() - 1),  SIZE,  matrix);
//         Position <int> up_right = temp.next_s( temp.get_x() + 1,  (temp.get_y() - 1),  SIZE,  matrix);
//         Position <int> right = temp.next_s( temp.get_x() + 1,  (temp.get_y()),  SIZE,  matrix);
//         Position <int> right_down = temp.next_s( temp.get_x() + 1 ,  (temp.get_y() + 1),  SIZE,  matrix);
//         Position <int> down = temp.next_s( temp.get_x(),  (temp.get_y() + 1),  SIZE,  matrix);
//         Position <int> left_down = temp.next_s( temp.get_x() - 1,  (temp.get_y() + 1),  SIZE,  matrix);
//         Position <int> left = temp.next_s( temp.get_x() -1 ,  (temp.get_y() ),  SIZE,  matrix);
//         Position <int> left_up = temp.next_s( temp.get_x() -1,  (temp.get_y() +1 ),  SIZE,  matrix);
//         Position<int> arr[] = {up, up_right,right,right_down,down,left_down,left,left_up};
//         for(int i = 0; i < 8; i++)
//         {   
            
//             std::cout << "\nvalues : "<< arr[i].get_value() ;
//             if(matrix[arr[i].get_x()][arr[i].get_y()].get_visited()!=0){std::cout <<" visited";} 
//             if(picked.get_value() < arr[i].get_value() &&  arr[i].get_value()!=-1 && matrix[arr[i].get_x()][arr[i].get_y()].get_visited()==0)  
//             {
//                 picked = arr[i]; // next position
//                 std::cout << " swap";
//             }
//         }
//         std::cout << "\n-------------------------------------\n";
//         gas -= matrix[picked.get_x()][picked.get_y()].get_gallons();
//         capacity -= matrix[picked.get_x()][picked.get_y()].get_served();
//         if(gas > 0 && capacity > 0)
//         {
//           matrix[picked.get_x()][picked.get_y()].set_order(count);
//           matrix[picked.get_x()][picked.get_y()].set_visited(1);
//           temp = picked;
//           count++;
//           std::cout << picked.get_value();
//           std::cout << "\n-------------------------------------\n";
//           std::cout << "\n current level of gas: " << gas << "\n";
//         }
//         else // car has ran out of gas 
//         {
//           std::cout << "gas has run out at [" << picked.get_x() << "," << picked.get_y() << "]\n";
//           matrix[0][0].set_order(1);gas = -1;
//           return;
//         }
//   }
// }

void path_find_s(D_truck truck, Node** matrix, Position <int> current, int SIZE)
{
  double gas_price = get_gas_price();
  double total_gas_used;
  double depth_gas = 0;
  int depth_capacity = 0;
  double trip_gas = truck.get_gas();
  bool keep_going = true;
  matrix[0][0].set_order(1); // sets first node to visited 
  int count = 2; // this is incremented and sets node.order to which order it is picked 
  matrix[current.get_x()][current.get_y()].set_visited(1); // sets initial to 1 to stop from going again
  int depth = 1; // depth is the search depth, its only incremented when the algo cant find a position at a depth of 1  
  int current_capacity = 0;
  trip_gas = trip_gas - matrix[0][0].get_gallons(); // takes away the cost at going to [0,0]
  Position<int> temp = current; // temp variable set to the postion thats passed in 
  temp.set_value(100000); // sets a very high value so that its value is never picked 
  while( trip_gas > 0 && current_capacity < truck.get_capacity() && keep_going)
  {     
    Position<int> picked = find_s(temp,depth,SIZE,matrix); // finds the best decision / position to go to
        if(picked.get_value() != 1000) // checks for algo being stuck in a corner 
        {
          if(depth != 1)
          {
            std::cout << "we are past the first depth and are at a depth of:" << depth << " is where a valid node was found\n";
            //depth_gas += matrix[picked.get_x()][picked.get_y()].get_gallons();
            //depth_gas = 0;
            // needs to store the depths from previous iterations that are
            // ex, lets say we find a good node to go to at a depth of 3, 
            // well then we need to subtract the gas at node of 1,2, and 3 depth away
            // so storing each depth until finding a working one or deleting it after none are found 
          } 
          depth = 1; // sets depth back to 1 because a valid postion was found 
          std::cout << "\n-------------------------------------\n";
          trip_gas -= matrix[picked.get_x()][picked.get_y()].get_gallons(); // subtracts gas at that position that was found 
          total_gas_used += matrix[picked.get_x()][picked.get_y()].get_gallons();
          current_capacity += matrix[picked.get_x()][picked.get_y()].get_served();// adds the amount served at the position that was found 
          if(trip_gas > 0 && current_capacity < truck.get_capacity()) // if gas or current capacity was excceded, then we dont actually visit it beacause it not possible 
          {
            matrix[picked.get_x()][picked.get_y()].set_order(count);
            matrix[picked.get_x()][picked.get_y()].set_visited(1);
            temp = picked;
            count++;
            std::cout << picked.get_value();
            std::cout << "\n-------------------------------------\n";
            std::cout << "\ncurrent level of trip_gas: " << trip_gas << "\n";
          }
          else // go back 
          {
            keep_going = continue_delivery(gas_price,total_gas_used);
            Position<int> back_to_start(1000);
            temp = back_to_start;

            std::cout << "trip_gas has run out at [" << picked.get_x() << "," << picked.get_y() << "]\n";
            //matrix[0][0].set_order(1);
            trip_gas = truck.get_gas();
            current_capacity = 0;
            //return;
          }
        } 
        else // if stuck in a corner, search at a deeper depth 
        {
          std::cout << "\nchecking depth " << depth << "\n";
          if(depth == SIZE) return; // return if no more possible depths are possible
          depth++; // add depth 
        }
  }
  std::cout << "leaving now\n"; return;
}
















/**
 * @brief main algorthim function 
 * this function gets the surrounding data at one depth from any particular node 
 * once the algo finds that smallest node, it subtracst the has used at that node 
 * 
 * @param gas 
 * @param capacity 
 * @param matrix 
 * @param current 
 */

void path_find_g(D_truck truck, Node** matrix, Position <double> current, int SIZE)
{
  double gas_price = get_gas_price();
  double total_gas_used;
  double depth_gas = 0;
  int depth_capacity = 0;
  double trip_gas = truck.get_gas();
  bool keep_going = true;
  matrix[0][0].set_order(1); // sets first node to visited 
  int count = 2; // this is incremented and sets node.order to which order it is picked 
  matrix[current.get_x()][current.get_y()].set_visited(1); // sets initial to 1 to stop from going again
  int depth = 1; // depth is the search depth, its only incremented when the algo cant find a position at a depth of 1  
  int current_capacity = 0;
  trip_gas = trip_gas - matrix[0][0].get_gallons(); // takes away the cost at going to [0,0]
  Position<double> temp = current; // temp variable set to the postion thats passed in 
  temp.set_value(100000); // sets a very high value so that its value is never picked 
  while( trip_gas > 0 && current_capacity < truck.get_capacity() && keep_going)
  {     
    Position<double> picked = find_g(temp,depth,SIZE,matrix); // finds the best decision / position to go to
        if(picked.get_value() != 1000) // checks for algo being stuck in a corner 
        {
          if(depth != 1)
          {
            std::cout << "we are past the first depth and are at a depth of:" << depth << " is where a valid node was found\n";
            depth_gas += matrix[picked.get_x()][picked.get_y()].get_gallons();
            depth_gas = 0;
            // needs to store the depths from previous iterations that are
            // ex, lets say we find a good node to go to at a depth of 3, 
            // well then we need to subtract the gas at node of 1,2, and 3 depth away
            // so storing each depth until finding a working one or deleting it after none are found 
          } 
          depth = 1; // sets depth back to 1 because a valid postion was found 
          std::cout << "\n-------------------------------------\n";
          trip_gas -= matrix[picked.get_x()][picked.get_y()].get_gallons(); // subtracts gas at that position that was found 
          total_gas_used += matrix[picked.get_x()][picked.get_y()].get_gallons();
          current_capacity += matrix[picked.get_x()][picked.get_y()].get_served();// adds the amount served at the position that was found 
          if(trip_gas > 0 && current_capacity < truck.get_capacity()) // if gas or current capacity was excceded, then we dont actually visit it beacause it not possible 
          {
            matrix[picked.get_x()][picked.get_y()].set_order(count);
            matrix[picked.get_x()][picked.get_y()].set_visited(1);
            temp = picked;
            count++;
            std::cout << picked.get_value();
            std::cout << "\n-------------------------------------\n";
            std::cout << "\ncurrent level of trip_gas: " << trip_gas << "\n";
          }
          else // go back 
          {
            keep_going = continue_delivery(gas_price,total_gas_used);
            Position<double> back_to_start(1000);
            temp = back_to_start;

            std::cout << "trip_gas has run out at [" << picked.get_x() << "," << picked.get_y() << "]\n";
            //matrix[0][0].set_order(1);
            trip_gas = truck.get_gas();
            current_capacity = 0;
            //return;
          }
        } 
        else // if stuck in a corner, search at a deeper depth 
        {
          std::cout << "\nchecking depth " << depth << "\n";
          if(depth == SIZE) return; // return if no more possible depths are possible
          depth++; // add depth 
        }
  }
  std::cout << "leaving now\n"; return;
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
        std::cout << matrix[i][j];
      }
      
    std::cout << "\n";
  }
}


D_truck get_trucks()
{
  bool truckchoice = whichtruck();
  if (truckchoice)
  {
    display_truck();
    return our_truck();
  }
  else
  {
   return own_truck();
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

D_truck our_truck()
{
  double gas = 0;
  int capacity = 0;
  std::string input;
  while (true)
    {
      std::cout << "(Please enter '1','2' or '3')\n\n";
      std::cin >> input;
      if (input == "1")
      {
        gas = 7;
        capacity = 250;
        return D_truck(7,250);
      }
      else if (input == "2")
      {
        gas = 10;
        capacity = 480;
        return D_truck(10,480);
      }
      else if (input == "3")
      {
        gas = 15;
        capacity = 650;
       return D_truck(15,650);
      }
      else
      {
        std::cout << "Error. \n";
      }
    }
}

D_truck own_truck()
{
  double input1;
  int input2;
  std::cout << " - For Your Truck -\n";
  std::cout <<"Enter fuel tank capacity (in gallons): ";
  std::cin>>input1;
  std::cout << "Enter amount of people that can be served: ";
  std::cin>>input2;
  while(std::cin.fail() || ( input1 < 0 ) || ( input2 < 0 ) )
    {
      std::cin.clear();
      std::cin.ignore(100,'\n');
      std::cout << "Sorry it seems like you havent entered a correct value, please try again\n> ";
      std::cout <<"Enter fuel tank capacity (in gallons): ";
      std::cin >> input1;
      std::cout << "Enter amount of people that can be served: ";
      std::cin>>input2;
    }
  return D_truck(input1,input2);
}




template<typename T>
 Position<T> find_g(Position<T> temp, int depth, int SIZE, Node** matrix)
{ 
  Position <double> picked(1000);//sets a very high value so that its value is never picked 
  //These lines fetch the data from all of the nodes surrounding the position of temp  
  Position <double> up = temp.next_g( temp.get_x(),  (temp.get_y() - depth),  SIZE,  matrix);
  Position <double> up_right = temp.next_g( temp.get_x() + depth,  (temp.get_y() - depth),  SIZE,  matrix);
  Position <double> right = temp.next_g( temp.get_x() + depth,  (temp.get_y()),  SIZE,  matrix);
  Position <double> right_down = temp.next_g( temp.get_x() + depth ,  (temp.get_y() + depth),  SIZE,  matrix);
  Position <double> down = temp.next_g( temp.get_x(),  (temp.get_y() + depth),  SIZE,  matrix);
  Position <double> left_down = temp.next_g( temp.get_x() - depth,  (temp.get_y() + depth),  SIZE,  matrix);
  Position <double> left = temp.next_g( temp.get_x() -depth ,  (temp.get_y() ),  SIZE,  matrix);
  Position <double> left_up = temp.next_g( temp.get_x() -depth,  (temp.get_y() +depth ),  SIZE,  matrix);
  Position<double> arr[] = {up, up_right,right,right_down,down,left_down,left,left_up};
  for(int i = 0; i < 8; i++) // finding the lowest amount of gas used
  {   
    std::cout << "values : "<< arr[i].get_value() ;
    if(matrix[arr[i].get_x()][arr[i].get_y()].get_visited()!=0){std::cout <<" visited";} 
    if( ( picked.get_value() > arr[i].get_value() ) && ( arr[i].get_value()!=-1 ) && ( matrix[arr[i].get_x()][arr[i].get_y()].get_visited()==0 ) )  
    {
      picked = arr[i];
      std::cout << " swap";
    }
    std::cout<<"\n";
  }
  return picked;
}
/*
Changes I made:
Switched some of the numbers to make it find the highest amount of people served instead of lowest.
**/
template<typename T>
 Position<T> find_s(Position<T> temp, int depth, int SIZE, Node** matrix)
{ 
  Position <int> picked(0);//sets a very high value so that its value is never picked 
  //These lines fetch the data from all of the nodes surrounding the position of temp  
  Position <int> up = temp.next_s( temp.get_x(),  (temp.get_y() - depth),  SIZE,  matrix);
  Position <int> up_right = temp.next_s( temp.get_x() + depth,  (temp.get_y() - depth),  SIZE,  matrix);
  Position <int> right = temp.next_s( temp.get_x() + depth,  (temp.get_y()),  SIZE,  matrix);
  Position <int> right_down = temp.next_s( temp.get_x() + depth ,  (temp.get_y() + depth),  SIZE,  matrix);
  Position <int> down = temp.next_s( temp.get_x(),  (temp.get_y() + depth),  SIZE,  matrix);
  Position <int> left_down = temp.next_s( temp.get_x() - depth,  (temp.get_y() + depth),  SIZE,  matrix);
  Position <int> left = temp.next_s( temp.get_x() -depth ,  (temp.get_y() ),  SIZE,  matrix);
  Position <int> left_up = temp.next_s( temp.get_x() -depth,  (temp.get_y() +depth ),  SIZE,  matrix);
  Position<int> arr[] = {up, up_right,right,right_down,down,left_down,left,left_up};
  for(int i = 0; i < 8; i++) // finding the lowest amount of gas used
  {   
    std::cout << "values : "<< arr[i].get_value() ;
    if(matrix[arr[i].get_x()][arr[i].get_y()].get_visited()!=0){std::cout <<" visited";} 
    if( ( picked.get_value() < arr[i].get_value() ) && ( arr[i].get_value()!=-1 ) && ( matrix[arr[i].get_x()][arr[i].get_y()].get_visited()==0 ) )  
    {
      picked = arr[i];
      std::cout << " swap";
    }
  std::cout<<"\n";
  }
  return picked;
}


double get_gas_price()
{
  double gas;
  std::cout << "Whats the current gas price in your area?\n> ";
  std::cin >> gas;
  while(std::cin.fail() || gas < 0 )
    {
      std::cin.ignore(100,'\n');
      std::cout << "Sorry, that is not a valid price\nPlease enter the current price of gas in us dollars\n> ";
      std::cin.clear();
      std::cin >> gas;
    }
  return gas;
}
bool continue_delivery(double price, double used)
{
  std::cout << "You have gone back to refill, the current amount of gas used in todays trip is " << used << " gallons. This has costed you " << price*used   << "$\nWould you like to go back out and try and serve more people? Yes or No\n>";
  return enter();
}


// supposed to find nearest gas station 
template<typename T>
Position<T> nearest_gas_station(Position<T> current_position, int size, Node** matrix)
{
  Position<T> optimal(0);
  Position<T> top_left(0,0);
  Position<T> top_right(size,0);
  Position<T> bottom_left(0,size);
  Position<T> bottom_right(size,size);
  Position<T> arr[] = {top_left, top_right, bottom_left, bottom_right};
  for(int i = 0; i < size; i++)
  {
    if(current_position.get_x() < size/2 && current_position.get_y() < size/2)
    {
     // return Position<T> re(0,0,0);
    }
  }
  
  //top left
  //top right
  //bottom left
  //bottom right
  // if current position is in impacted spot, generate random num from 0-10 and then 2%random number and then go to one 
}


std::ostream& operator<<(std::ostream& out,  Node& classObj)
{
  out << "[" << std::setfill('0') << std::setw(2) << classObj.get_order() << "]";
  return out;
};
