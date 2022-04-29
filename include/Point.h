#ifndef POINT
#define POINT

#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class Point{
    private :
        T x, y;

    public :
        Point(const T& a, const T& b) :x{a}, y{b} {

        };
        Point() :x{0}, y{0}{

        };
        Point(const Point<T> &p) :x{ p.x}, y{ p.y }{

        };
        const T& getX() const;
        const T& getY() const;
        void print() const;
        Point<T> operator+(const Point<T>& other);
        Point<T> operator-(const Point<T>& other);
        Point<T> operator*(const T a);
        Point<T> operator/(const T a);
        bool operator==(const Point& other);
        bool operator>(const Point& other);
        bool operator<(const Point& other);
        std::unique_ptr<Point<double>> normalize();
};

#include "Point.hpp"

#endif