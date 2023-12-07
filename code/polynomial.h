/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/

#include <vector>

class Polynomial {
public: 
	//consturctor
	Polynomial(double a, double b);

	Polynomial(double d);

	Polynomial() = default; 

	//vector with vectors
	Polynomial(const std::vector<std::vector<double>>& V);

	//copiable
	Polynomial(const Polynomial& rhs) = default; 

	//assignable
	Polynomial& operator=(const Polynomial& rhs); 

	double degree();

	//tye conversion operator
	explicit operator std::string() const; 

	//operators
	Polynomial& operator+=(const Polynomial& rhs);

	Polynomial& operator-=(const Polynomial& rhs);

	Polynomial& operator*=(const Polynomial& rhs);

	Polynomial& operator+(const Polynomial& rhs);

	Polynomial& operator-(const Polynomial& rhs);

	Polynomial& operator*(const Polynomial& rhs);

	Polynomial& operator==(const Polynomial& rhs);

	Polynomial& operator<<(const Polynomial& rhs);


protected: 

private: 

	std::vector<std::pair<double, double>> coefficients_table; 
};