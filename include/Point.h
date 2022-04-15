#ifndef POINT
#define POINT

#include <iostream>
#include <vector>

template<typename T>
class Point{
    private :
        T x, y;

    public :
        const T& getX() const;
        const T& getY() const;
        void print() const;
        Point& operator+(const Point& other);
        Point& operator-(const Point& other);
        Point& operator*(const Point& other);
        Point& operator==(const Point& other);
        bool operator>(const Point& other);
        bool operator<(const Point& other);
        void normalize();
};

#endif