#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <iostream>
#include <cmath> // for std::sqrt

// Classes bundle data and behaviour into one type.

class Vector3D {
    public: // Accessible from outside the class
        double x, y, z; // data / member variables



        // member function (method) - this is a behaviour of the class

        double magnitudeSquared() const{ // trailing const means this method doesn't modify the object.
            return x*x + y*y + z*z;
        } 

        double magnitude() const {
            return std::sqrt(x*x + y*y + z*z);
        }

        // constructor - special member function that is called when an object of the class is created
        // Option A: initializer list (preferred)

        Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {} // constructor call to create an object of the class

        /* 
        Option B: assignment in body (works, slightly less idiomatic)

        Vector3D(double x_, double y_, double z_) {
            x = x_; y = y_; z = z_;
        }

        */

        // operator overloading - allows us to define how operators work with our class

        Vector3D operator+(const Vector3D& other) const {

        /*
            C++ calls a.operator+(b) — so a is the object (its members are x, y, z) and b is other.
            It takes the right-hand operand by const& (no copy, read-only — same habit).
            It's marked const because adding doesn't modify a.
            It returns a new Vector3D (by value) — the sum. It doesn't mutate either operand. This is how + should behave: a + b produces a third vector, leaving a and b alone.
        */

            return Vector3D(x + other.x, y + other.y, z + other.z);
        }
        


};

int main() {

    
    Vector3D vec1(1.0, 2.0, 3.0); // create a Vector3D object using the constructor
    Vector3D vec2(4.0,5.0,8.0);

    Vector3D vec3 = vec1 + vec2; // use the overloaded + operator to add two Vector3D objects

    std::cout << "Sum: " << vec3.x << ", " << vec3.y << ", " << vec3.z << "\n";
    std::cout << "Magnitude squared of vec3: " << vec3.magnitudeSquared() << "\n"; 
    std::cout << "Magnitude of vec3: " << vec3.magnitude() << "\n";

    return 0;

}