/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"
#include <vector>
#include <cmath>
#include <format>
#include <algorithm> //std::copy
#include <map>
#include <iterator>
#include <utility>

 //consturctor
Polynomial::Polynomial(int a, int b) {
    coefficients_table[a] = b; 
}

Polynomial::Polynomial(int d) {
    coefficients_table[0] = d;
}

Polynomial::Polynomial() {
}

//vector with vectors KOLLA PÅ DENNA IGEN
Polynomial::Polynomial(const std::vector<std::pair<int, int>> & V ) {

   std::copy(V.begin(), V.end(), std::inserter(coefficients_table, coefficients_table.begin())); 
   
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
int Polynomial::degree() {
    std::map<int, int>::iterator it = coefficients_table.begin()
;   int maxDegree =  it->first;
    int currentDegree; 

    for (it; it != coefficients_table.end(); ++it) {
        int currentDegree = it->first;

        if (currentDegree > maxDegree) {
           maxDegree = currentDegree;
        }

    }

    return maxDegree;
  
}

//tye conversion operator
Polynomial::operator std::string() const {
    //i.second är koefficienten och i.first är exponenten
    std::string S = "";

    std::map<int, int>::iterator it = coefficients_table.begin();  
    for (it; it != coefficients_table.end(); ++it) {
       
            if (it->second < 0) {
                S += std::format(" - {} * X^{}", abs(it->second), it->first);
            }
            else {
                S += std::format(" + {} * X^{}", it->second, it->first);
            }
        
    }
    return S; 


}

//operators
//EJ NESTED FOR LOOPS ENDAST I *= 
//PAPPRET!
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {

   for (const auto& i : rhs.coefficients_table) {
        coefficients_table[i.first] += i.second; 

        if (coefficients_table[i.second] == 0) {
            coefficients_table.erase(i.first);
        }
    }

    return *this; 
}


//vi är här typ
Polynomial& Polynomial::operator-=(const Polynomial& rhs) {

    for (auto i : coefficients_table) {
        for (auto j : rhs.coefficients_table) {
            if (i.first == j.first) {      
                if (i.second != j.second) { //coefficienterna är olika 
                    i.second -= j.second;
                }
                else {
                    coefficients_table.erase(i.first);
                }
            }
            else {
                coefficients_table.insert(j.first, -1*j.second);
            }
        }
    }

    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& rhs) {
    Polynomial P; 

    for (auto i : P.coefficients_table) {
        for (auto j : rhs.coefficients_table) {
            i.second *= j.second;
            i.first += j.first;


        }
    }
    //ifall ngra termer får samma exponent på olika platser ska d slås ihop
        return *this; 
}

Polynomial& Polynomial::operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial p(lhs);
    return P += rhs; 

}

Polynomial& Polynomial::operator-(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator*(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator==(const Polynomial& rhs) {

}

Polynomial& Polynomial::operator<<(const Polynomial& rhs) {

}