/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/


#include <vector>
#include <cmath>
#include <format>
#include <string>
#include <algorithm> //std::copy
#include <map>
#include <iterator>
#include <utility>
#include <ostream>
#include <iostream>
#include <sstream>

class Polynomial {
public: 
	//consturctor
	Polynomial(int a, int b);

	Polynomial(int d);

	Polynomial() = default; 

	//vector with vectors
	Polynomial(const std::vector<std::pair<int, int>> & V);

	//copiable
	Polynomial(const Polynomial& rhs) = default; 

	//assignable
	Polynomial& operator=(const Polynomial& rhs); 

	int degree();

	//tye conversion operator
	explicit operator std::string(); 

	//operators
	Polynomial& operator+=(const Polynomial& rhs);

	Polynomial& operator-=(const Polynomial& rhs);

	Polynomial& operator*=(const Polynomial& rhs);

	Polynomial& operator+(const Polynomial& rhs);

	Polynomial& operator-(const Polynomial& rhs);

	Polynomial& operator*(const Polynomial& rhs);

	bool operator==(const Polynomial& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, Polynomial& rhs) {
		os << std::string(rhs);
		return os;
	}


private: 

	//std::vector<std::pair<double, double>> coefficients_table; 
	std::map<int,int> coefficients_table; //key exponent, value coefficient
	//key är konstant
};