#ifndef POSITION_H
#define POSITION_H
/**
 * could use template class
 * would need to change the double of value to type T
 * this would be smart since we are looking at two different type
 * 
 * 
 *  @note 
 *  Instead of making 8 different functions
 *  you can make one and pass is the +1 or -1 to search positions 
 *  would be a template function because the type being modified -> value 
 *  would be of type int or double and wouldn't want to perform wrong opperation
 * 
 */

template <class T>
class Position
 {
  public:
    //Position<T> (T _value);
    // Position(T _value,int x,int y); *** working ***
    Position(T value);
    Position(int x, int y);
    T get_value(); // will be used to get the value wether it be int or double

    Position<T> next_s(int, int, int,  Node**);
    Position<T> next_g(int, int, int,  Node**);

    int get_x();
    int get_y();
    void set_value(T);
    int get_order();
    void set_order(int);

  private:
    int order;
    int x;
    int y;
    T value; // change to T if creating a template class
};
//WORKINNG
// template<class T>
// Position<T>::Position(T _value, int x, int y)
// {
//   x = 0;
//   y = 0;
//   value = _value;
// };
template<typename T>
void Position<T>::set_value(T _value)
{
    value = _value;
}

template<class T>
Position<T>::Position(T _value)
{
  //dynamically assign x and y later
  x = 0;
  y = 0;
  order = 1;
  value = _value;
};

template<class T>
Position<T>::Position(int _x, int _y)
{
  //dynamically assign x and y later
  x = _x;
  y = _y;
  order = 1;
  value = 0;
};

// /**
//  * @warning when calling this function, be sure to initialize 
//  * 
//  * @tparam T 
//  * @param x 
//  * @param y 
//  * @return Position<T> 
//  */
template <class T>
Position<T> Position<T>::next_s(int _x, int _y, int SIZE, Node** matrix) // when passing in x and y values,  call function like this Position<type>next( <current x position +- # >, <current y position +- #>, T)
{
    Position<T> temp(1000);
    if( ( _x >= 0 ) && ( _x < SIZE ) && ( _y >= 0 ) && (_y < SIZE ) ) // if in bounds of array continue 
    {
        temp.x = _x; // change 
        temp.y = _y;
        temp.value = matrix[_x][_y].get_served();
    }
    else
    {
        temp.value = -1;
    }
    return temp;
};

template<class T>
Position<T> Position<T>::next_g(int _x, int _y, int SIZE, Node** matrix) // when passing in x and y values,  call function like this Position<type>next( <current x position +- # >, <current y position +- #>, T)
{// lets try and get the constructor working first 
    Position<T> temp(10000);
    if( ( _x >= 0 ) && ( _x < SIZE ) && ( _y >= 0 ) && (_y < SIZE ) ) // if in bounds of array continue 
    {
        temp.x = _x; // change 
        temp.y = _y;
        temp.value = matrix[_x][_y].get_gallons();
    }
    else
    {
        temp.value = -1; // means that no spot exists , x and y coordinates will be the same from which parent node calls, each iteration of algo will have parent node, which is the previous selected node 
    }
    return temp; // returns a position type with new data or returns the parent node aka prevous iteration nodes x and y values, but will have value set to -1
};
template<class T>
int Position<T>::get_x()
{
    return x;
}
template<class T>
int Position<T>::get_y()
{
    return y;
}
template<class T>
T Position<T>::get_value()
{
    return value;
}


#endif

