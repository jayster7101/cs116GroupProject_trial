#include "include.h"
    Node::Node()
    {
        gallons = 0;
        served = 0;
        visited = 0;
        order = 0;
    }
    Node::Node(double _gallons, int _served)
    {
        gallons = _gallons;
        served = _served;
        visited = 0;
        order = 0;
    }
    void Node::set_gallons(double _gallons)
    {
        gallons = _gallons;
    }
    double Node::get_gallons() 
    {
        return gallons;
    }
    void Node::set_served(int _served)
    {
        served = _served;
    }
    int Node::get_served()
    {
        return served;
    }
    void Node::set_visited(int _visited)
    {
        visited = _visited;
    }
    int Node::get_visited()
    {
        return visited;
    } 

void Node:: set_order(int o)
{
  order = o;
}


int Node::get_order()
{return order;}