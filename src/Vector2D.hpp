#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
/**
 * @brief The Vector2D class
 * @details The Vector2D class is a template class that represents a 2D vector.
 * @tparam T The type of the vector.
 */
template<typename T>
class Vector2D{

    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef unsigned long int size_type;

private:
    value_type _x;
    value_type _y;

public:

    Vector2D(value_type x, value_type y) : _x(x), _y(y){}

    Vector2D(const Vector2D& v) : _x(v._x), _y(v._y){}
    
    Vector2D operator+(Vector2D &v) const{
        return Vector2D(_x + v._x, _y + v._y);
    }

    Vector2D operator-(Vector2D &v) const{
        return Vector2D(_x - v._x, _y - v._y);
    }

    Vector2D operator*(value_type alpha) const{
        return Vector2D(_x * alpha, _y * alpha);
    }

    Vector2D operator/(value_type alpha) const{
        return Vector2D(_x / alpha, _y / alpha);
    }

    Vector2D& operator+=(const Vector2D &v){
        _x += v._x;
        _y += v._y;
        return *this;
    }

    Vector2D& operator-=(const Vector2D &v){
        _x -= v._x;
        _y -= v._y;
        return *this;
    }

    value_type dot(Vector2D &v) const{
        return _x * v._x + _y * v._y;
    }

    value_type cross(Vector2D &v) const{
        return _x * v._y - _y * v._x;
    }

    value_type norm() const{
        return sqrt(_x * _x + _y * _y);
    }

    Vector2D& normalize(){
        return *this / norm();
    }

    value_type x() const{
        return _x;
    }

    value_type y() const{
        return _y;
    }

    void x(value_type x) const{
        _x = x;
    }

    void y(value_type y) const{
        _y = y;
    }

    void set(value_type x, value_type y){
        _x = x;
        _y = y;
    }

};

#endif // VECTOR2D_H