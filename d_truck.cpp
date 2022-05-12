//#include "include.h"
#include "truck.h"
#include "d_truck.h"
#include <iostream>
D_truck::D_truck()
{
  Truck::set_gas(0);
};
D_truck::D_truck(double gas,int _capacity)
{
  Truck::set_gas(gas);
  capacity = _capacity;
};



void D_truck::set_capacity(int _cap)
{
  capacity = _cap;
};
int D_truck::get_capacity()
{
  return capacity;
};

void D_truck::display()
{
  std::cout << "The tank capcity is " << get_gas() << " gallons total. Its able to serve a maximum of " << capacity<< " people\n";
}
