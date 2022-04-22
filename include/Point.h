#ifndef POINT
#define POINT

#include <iostream>
#include <vector>

template<typename T>
class Point{
    private :
        T x, y;

    public :
        Point(T a, T b) :x{a}, y{b} {

        };
        Point() :x{0}, y{0}{

        };
        const T& getX() const;
        const T& getY() const;
        void print() const;
        Point<T> operator+(const Point& other);
        Point<T> operator-(const Point& other);
        Point<T> operator*(const T a);
        Point<T> operator/(const T a);
        bool operator==(const Point& other);
        bool operator>(const Point& other);
        bool operator<(const Point& other);
        void normalize();
};

#include "Point.hpp"

#endif