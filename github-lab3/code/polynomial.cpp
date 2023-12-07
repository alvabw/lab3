/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"
#include <vector>
#include <cmath>
#include <format>
#include <algorithm>

 //consturctor
Polynomial::Polynomial(double a, double b) {
	coefficients_table.push_back(std::pair(a, b));
}

Polynomial::Polynomial(double d) {
	coefficients_table.push_back(std::pair(0, d));
}

Polynomial::Polynomial() {
}

//vector with vectors KOLLA PÅ DENNA IGEN
Polynomial::Polynomial(const std::vector<std::vector<double>>& V) {
    std::transform(V.begin(), V.end(), std::back_inserter(coefficients_table),
        [](const std::vector<double>& pairVector) {
            return std::pair(pairVector[0], pairVector[1]);
        }
    );

}

//copiable
Polynomial::Polynomial(const Polynomial& rhs) {
   coefficients_table = rhs.coefficients_table;
}

//assignable
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
     coefficients_table = rhs.coefficients_table; 

     return *this; 
}

//degree
double Polynomial::degree() {
    double maxDegree = 0; 
    for (std::pair i : coefficients_table) {
        if (i.first > maxDegree) {
            maxDegree = i.first;
        }
   
    }
    return maxDegree;
  
}

//tye conversion operator
Polynomial::operator std::string() const {
    std::string S = ""; 

    for (std::pair i : coefficients_table) {
        if (i.first == 0) {
            S += std::format("{:.2f}", i.second);
        }
        else {
            if (i.second < 0) {
                S += std::format(" - {:.2f} * X^{}", abs(i.second), i.first);
            }
            else {
                S += std::format(" + {:.2f} * X^{}", i.second, i.first);
            }
        }
    }
    return S; 


}

//operators
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator-=(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator*=(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator+(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator-(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator*(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator==(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator<<(const Polynomial& rhs) {

}