
#include <cmath>
#include <memory>

#include "Point.h"

// getters
template <typename T>
const T& Point<T>::getX() const{
    return this->x;
}

template <typename T>
const T& Point<T>::getY() const{
    return this->y;
}

// affichage
template <typename T>
void Point<T>::print() const{
    std::cout << "x = " << this.x << ",y = " << this.y << std::endl;
}

// opérateurs
template <typename T>
Point<T> Point<T>::operator+(const Point<T>& other){
    Point res;
    res.x = this->x + other.x;
    res.y = this->y + other.y;
    return res;
}

template <typename T>
Point<T> Point<T>::operator-(const Point& other){
    Point res;
    res.x = this->x - other.x;
    res.y = this->y - other.y;
    return res;
}

template <typename T>
Point<T> Point<T>::operator*(const T a){
    Point res;
    res.x = (this->x)*a;
    res.y = (this->y)*a;
    return res;
}

template <typename T>
Point<T> Point<T>::operator/(const T a){
    Point res;
    res.x = (this->x)/a;
    res.y = (this->y)/a;
    return res;
}

template <typename T>
bool Point<T>::operator==(const Point& other){
    if ((this->x==other->x)&&(this->y==other->y))
        return true;
    else
        return false;
}

template <typename T>
bool Point<T>::operator>(const Point& other){
    if ((this->x>other->x)&&(this->y>other->y))
        return true;
    else
        return false;
}

template <typename T>
bool Point<T>::operator<(const Point& other){
    if(!(this>other||(this==other)))
        return true;
    else
        return false;
}

template <typename T>
std::unique_ptr<Point<double>> Point<T>::normalize(){
    double n = sqrt(pow(this->x, 2) + pow(this->y, 2));
    return std::make_unique<Point<double>>(x / n, y / n);
}

