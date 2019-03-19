#ifndef _VEC3_H_
#define _VEC3_H_

#include <math.h>
#include <stdlib.h>
#include <iostream>

/**
 * @brief alias from vector's coordenates 
 */
#define x_axis 0
#define y_axis 1
#define z_axis 2

class Vec3 {
public:

    //<! The vector or point element
    float element[3];

    /**
     * @brief Construct a new Vector object
     */
    Vec3(){}

    /**
     * @brief Construct a new Vec3 object
     * 
     * @param element0 The value of x axis
     * @param element1 The value of y axis
     * @param element2 The value of z axis
     */
    Vec3(float element0, float element1, float element2)
    { element[x_axis] = element0; element[y_axis] = element1;  element[z_axis] = element2; }

    /**
     * @brief Get value of vector x axis 
     * @return float The x axis value
     */
    inline float x() const { return element[x_axis]; }
    
    /**
     * @brief Get value of vector y axis 
     * @return float The y axis value
     */
    inline float y() const { return element[y_axis]; }
    
    /**
     * @brief Get value of vector z axis 
     * @return float The z axis value
     */
    inline float z() const { return element[z_axis]; }
    
    /**
     * @brief Get value of vector x axis 
     * @return float The x axis value
     */
    inline float r() const { return element[x_axis]; }
    
    /**
     * @brief Get value of vector y axis 
     * @return float The y axis value
     */
    inline float g() const { return element[y_axis]; }
    
    /**
     * @brief Get value of vector z axis 
     * @return float The z axis value
     */
    inline float b() const { return element[z_axis]; }

    /**
     * @brief Define unary operator + (plus)
     * @return const Vec3& A new vec3 with the 
     * sum of this vec3 with other vec3
     */
    inline const Vec3& operator+() const { return *this; }

    /**
     * @brief Define operator - (subtraction)
     * @return Vec3 The vector with the subtraction of this
     * vec3 with other vec3 
     */
    inline Vec3 operator-() const 
    {return Vec3(-element[x_axis], -element[y_axis], -element[z_axis]);}

    /**
     * @brief Define operator [] const
     * @param i The position of vector
     * @return float the vector value in position i
     */
    inline float operator[] (int i) const { return element[i]; }

    /**
     * @brief Define operator [] not const
     * 
     * @param i The position of vector
     * @return float& The vector address in position i
     */
    inline float& operator[] (int i) { return element[i]; }

    /**
     * @brief Define operator +=
     * 
     * @param rhs The other vec3 to add a this vec3
     * @return Vec3& The new vec3 with the sum between this and rhs
     */
    inline Vec3& operator+=(const Vec3 &rhs);

    /**
     * @brief Define operator -=
     * 
     * @param rhs The other vec3 to sub a this vec3
     * @return Vec3& The new vec3 with the sub between this and rhs
     */
    inline Vec3& operator-=(const Vec3 &rhs);

    /**
     * @brief Define operator *= 
     * 
     * @param rhs The other vec3 to multiply a this vec3
     * @return Vec3& The new vec3 with the product between this and rhs
     */
    inline Vec3& operator*=(const Vec3 &rhs);

    /**
     * @brief Define operator /= 
     * 
     * @param rhs The other vec3 to divide a this vec3
     * @return Vec3& The new vec3 with the division between this and rhs
     */
    inline Vec3& operator/=(const Vec3 &rhs);

    /**
     * @brief Define scalar product
     * 
     * @param scalar the scalar 
     * @return Vec3& The scalar product between this vec3 and scalar element
     */
    inline Vec3& operator*=(const float scalar);

    /**
     * @brief Define scalar division
     * 
     * @param scalar the scalar 
     * @return Vec3& The division by a scalar between this vec3 and scalar element
     */
    inline Vec3& operator/=(const float scalar);

    /**
     * @brief the vector lenght - use pythagoras rule
     * @return float The value of vector lenght
     */
    inline float length() const {
        return sqrt(pow(element[x_axis],2) + pow(element[y_axis],2) + pow(element[z_axis],2));
    }

    /**
     * @brief the vector squared length
     * @return float the value of vector squared length
     */
    inline float squared_length() const {
        return pow(element[x_axis], 2) + pow(element[y_axis], 2) + pow(element[z_axis], 2);
    }

    /**
     * @brief make a unit vector
     */
    inline void make_unit_vector();
};

#endif