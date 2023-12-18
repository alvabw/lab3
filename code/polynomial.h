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
	Polynomial() = default; 

	Polynomial(int coef, int exp);

	Polynomial(int coef);

	/*~Polynomial() = default;*/

	//vector with vectors
	Polynomial(const std::vector<std::pair<int, int>> & V);

	//copiable
	/*Polynomial(const Polynomial& rhs) = default; */

	//assignable
	/*Polynomial& operator=(const Polynomial& rhs) = default; */

	int degree();

	//tye conversion operator
	explicit operator std::string() const; 

	//operators
	Polynomial& operator+=(const Polynomial& rhs);

	Polynomial& operator-=(const Polynomial& rhs);

	Polynomial operator*=(const Polynomial& rhs);

	Polynomial mult(std::pair<int, int> rhs);
	
	friend Polynomial& operator+(Polynomial lhs, const Polynomial& rhs);
	friend Polynomial& operator+(int lhs, const Polynomial& rhs);
	friend Polynomial& operator+(Polynomial lhs, const int rhs);

	friend Polynomial operator-(Polynomial lhs, const Polynomial& rhs);

	friend Polynomial& operator*(Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial& operator*(int i, const Polynomial& rhs); 

	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);

	friend std::ostream& operator<<(std::ostream& os, Polynomial& rhs) {
		os << std::string(rhs);
		return os;
	}


private: 

	//std::vector<std::pair<double, double>> coefficients_table; 
	std::map<int,int> coefficients_table; //key exponent, value coefficient
	//key är konstant

	
};