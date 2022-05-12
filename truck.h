#ifndef TRUCK_H
#define TRUCK_H

class Truck
{
public:
  Truck();
  void set_gas(double);
  double get_gas();
  virtual void display();

private:
  double gas;
};
#endif