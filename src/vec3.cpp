#include "vec3.h"


/**
 * @brief Define operator + (plus) between two vectors
 * 
 * @param  v1 the lhs vector
 * @param  v2 the rhs vector
 * 
 * @return const a new vec3 with the sum of v1 and v2
 */
inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2){ 
    return Vec3(v1.element[x_axis] + v2.element[x_axis],
                v1.element[y_axis] + v2.element[y_axis],
                v1.element[z_axis] + v2.element[z_axis]);    
}

/**
 * @brief Define operator - (subtraction) between two vectors
 * 
 * @param v1   the lhs vector
 * @param v2   the rhs vector
 * 
 * @return Vec3 The vector with result v1-v2
 */
inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.element[x_axis] - v2.element[x_axis],
                v1.element[y_axis] - v2.element[y_axis],
                v1.element[z_axis] - v2.element[z_axis]); 
}

/**
 * @brief Define operator * between two vectors
 * 
 * @param v1     The lhs vector
 * @param v2     The rhs vector
 * @return Vec3  the product between v1 and v2
 */
inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2){
    return Vec3(v1.element[x_axis] * v2.element[x_axis],
                v1.element[y_axis] * v2.element[y_axis],
                v1.element[z_axis] * v2.element[z_axis]); 
}

/**
 * @brief Define operator / between two vectors
 * 
 * @param v1  The lhs vector
 * @param v2  The rhs vector
 * @return Vec3  the result of v1/v2
 */
inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2){
   
    int x = v2.element[x_axis], y = v2.element[y_axis], z = v2.element[z_axis];
    
    /**
     * @brief check if division by 0;
     */
    if ( x == 0) x = 1;
    if ( y == 0) y = 1;
    if ( z == 0) z = 1;

    return Vec3(v1.element[x_axis] / v2.element[x_axis],
                v1.element[y_axis] / v2.element[y_axis],
                v1.element[z_axis] / v2.element[z_axis]); 
}

/**
 * @brief make a unit vector
 */
inline void make_unit_vector();