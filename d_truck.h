#include "truck.h"
#ifndef D_TRUCK_H
#define D_TRUCK_H

class D_truck : public Truck
{
public:
  D_truck();//default 
  D_truck(double,int);// overload to create a truck based on user input
  void set_capacity(int);
  int get_capacity();
private:
  int capacity;
};

#endif