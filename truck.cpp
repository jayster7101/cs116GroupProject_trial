#include "include.h"
Truck::Truck()
{
  gas = 12;
}

void Truck::set_gas(double _gas)
{
  gas = _gas;
}

double Truck::get_gas()
{
  return gas;
}
void Truck::display()
{
  std::cout << "BASE \n";
  //std::cout << "This is a basic pickup truck with 0 extra functionality, the tank capcity is " << gas << " gallons total.\n";
}
