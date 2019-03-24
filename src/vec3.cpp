#include "vec3.h"


inline std::istream& operator>> (std::istream &is, Vec3 &t){
    is >> t.element[x_axis] >> t.element[y_axis] >> t.element[z_axis];
    return is;
}

inline std::ostream& operator<< (std::ostream &os, const Vec3 &t){
    os << t.element[x_axis] << t.element[y_axis] << t.element[z_axis];
    return os;
}

/**
 * @brief make a unit vector
 */
inline void Vec3::make_unit_vector(){
    float k = 1.0 / sqrt(pow(element[x_axis],2) + 
                         pow(element[y_axis],2) + 
                         pow(element[z_axis],2));
    element[x_axis] *= k; 
    element[y_axis] *= k;
    element[z_axis] *= k;
}

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
 * @brief scalar product
 * 
 * @param t the scalar
 * @param v the vector
 * @return Vec3  the result vector of product between a scalar and a vector
 */
inline Vec3 operator* (float t, const Vec3 &v){
    return Vec3(t*v.element[x_axis], t*v.element[y_axis], t*v.element[z_axis]);
}

/**
 * @brief division by scalar
 * 
 * @param v the vector
 * @param t the scalar
 * @return Vec3 the division result between vector and scalar 
 */
inline Vec3 operator/ (Vec3 v, float t){
    if (t == 0) return v;
    return Vec3(v.element[x_axis]/t, v.element[y_axis]/t, v.element[z_axis]/t);
}

/**
 * @brief The right product between vector and a scalar 
 * 
 * @param v the vector
 * @param t the scalar
 * @return Vec3  the result
 */
inline Vec3 operator* (const Vec3 &v, float t){
    return Vec3(t*v.element[x_axis], t*v.element[y_axis], t*v.element[z_axis]);
}

/**
 * @brief The product between tow vectors
 * 
 * @param v1 the first vector
 * @param v2 the second vector
 * @return float the product between v1 and v2
 */
inline float dot(const Vec3 &v1, const Vec3 &v2){
    return v1.element[x_axis] * v2.element[y_axis] +
           v1.element[y_axis] * v2.element[y_axis] +
           v1.element[z_axis] * v2.element[z_axis];
}

/**
 * @brief The vectorial product between two vector
 * 
 * @param v1 the first vector
 * @param v2 the second vector
 * @return Vec3 the result of product
 */
inline Vec3 cross(const Vec3 &v1, const Vec3 &v2){
    return Vec3( (v1.element[z_axis]*v2.element[y_axis] 
                - v1.element[z_axis]*v2.element[y_axis]),
                -(v1.element[x_axis]*v2.element[z_axis]
                - v1.element[z_axis]*v2.element[x_axis]),
                 (v1.element[x_axis]*v2.element[y_axis]
                - v1.element[y_axis]*v2.element[x_axis]));
}

inline Vec3& Vec3::operator+= (const Vec3 &v){
    element[x_axis] += v.element[x_axis];
    element[y_axis] += v.element[y_axis];
    element[z_axis] += v.element[z_axis];

    return *this;
}

inline Vec3& Vec3::operator*= (const Vec3 &v){
    element[x_axis] *= v.element[x_axis];
    element[y_axis] *= v.element[y_axis];
    element[z_axis] *= v.element[z_axis];

    return *this;
}

inline Vec3& Vec3::operator/= (const Vec3 &v){
    element[x_axis] /= v.element[x_axis];
    element[y_axis] /= v.element[y_axis];
    element[z_axis] /= v.element[z_axis];

    return *this;
}

inline Vec3& Vec3::operator-= (const Vec3 &v){
    element[x_axis] -= v.element[x_axis];
    element[y_axis] -= v.element[y_axis];
    element[z_axis] -= v.element[z_axis];

    return *this;
}

inline Vec3& Vec3::operator*= (const float t){
    element[x_axis] *= t;
    element[y_axis] *= t;
    element[z_axis] *= t;

    return *this;
}

inline Vec3& Vec3::operator/= (const float t){
    if (t == 0) return *this;
    
    float k = 1.0/t;
    
    element[x_axis] *= k;
    element[y_axis] *= k;
    element[z_axis] *= k;

    return *this;
}

inline Vec3 unit_vector(Vec3 v){
    return v / v.length();
}
