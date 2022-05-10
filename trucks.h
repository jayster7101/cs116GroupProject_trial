#ifndef TRUCK_H
#define TRUCK_H

class Truck
{
public:
  void set_gas(double);
  double get_gas();
  
  void set_capacity(int);
  int get_capacity();



private:
  int capacity;
  double gas;
};
#endif