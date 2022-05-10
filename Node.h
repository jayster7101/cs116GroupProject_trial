
#include <iomanip>
#ifndef Node_H
#define Node_H
class Node
{
    public:
    Node();
    Node(double, int);
    void set_gallons(double);
    double get_gallons() ;
    void set_served(int);
    int get_served() ;
    void set_visited(int);
    int get_visited();
    int get_order();
    void set_order(int);

    private:
    double gallons;
    int served;
    int visited;
    int order;
};




#endif