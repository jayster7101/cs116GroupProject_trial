#include "include.h"

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
