/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"


 //consturctor
//Polynomial::Polynomial(int a, int b) {
//    coefficients_table[a] = b; 
//}
//
//Polynomial::Polynomial(int d) {
//    coefficients_table[0] = d;
//}

 Polynomial::Polynomial(int a, int b) {
     if (a != 0) {
        coefficients_table[a] = b; 
     }
     else {
         coefficients_table[0] = 0; //denna else ska kanske inte vara med, får ej stora Noll värden i map table
     }
  }


//vector with vectors KOLLA PÅ DENNA IGEN
Polynomial::Polynomial(const std::vector<std::pair<int, int>> & V ) {

   std::copy(V.begin(), V.end(), std::inserter(coefficients_table, coefficients_table.begin())); 
   
}

//copiable är default, man behöver inte omdefieniera det  här

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
           currentDegree = it->first;

        if (currentDegree > maxDegree) {
           maxDegree = currentDegree;
        }

    }

    return maxDegree;
  
}

//tye conversion operator
Polynomial::operator std::string() const{
    //i.second är koefficienten och i.first är exponenten
    std::string S = "";
    int counter = 0; 

    /*if (coefficients_table.empty()) {
        return std::string("0");
    }*/

    /*std::map<int, int>::iterator it = coefficients_table.begin();*/
    for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
        if (it->first == 0 && it->second == 0) {
        std::cout << "hej :3    ";
            S = "0";
         }

            if (it->second < 0) {
                S += std::format(" - {} * X^{}", abs(it->second), it->first);
            }
            else {
               
                if (counter == 0) {
                     S = std::format("{} * X^{}", it->second, it->first);
                } 
                else {
                    S += std::format(" + {} * X^{}", it->second, it->first);
                }
            }
            counter++;
        
    }
    std::cout << "  S = " << S << "     ";
    return S; 


}

//operators
//EJ NESTED FOR LOOPS ENDAST I *= 
//PAPPRET!
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {

   for (const auto& i : rhs.coefficients_table) {
        coefficients_table[i.first] += i.second; //For each term in rhs, add the coefficient (i.second) to the corresponding term in the current polynomial 

        if (coefficients_table[i.second] == 0) {
            coefficients_table.erase(i.first);
        }
    }

    return *this; 
}


//vi är här typ
Polynomial& Polynomial::operator-=(const Polynomial& rhs) {

    for (const auto& i : rhs.coefficients_table) {
        coefficients_table[i.first] -= i.second; //For each term in rhs, subtract the coefficient (i.second) to the corresponding term in the current polynomial 

        if (coefficients_table[i.second] == 0) {
            coefficients_table.erase(i.first);
        }
     }
    

    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& rhs) {
    Polynomial P; 

    for (const auto& i : coefficients_table) {
        for (const auto& j : rhs.coefficients_table) {
            int newCoeff = i.second * j.second;
            int newExponent = i.first + j.first;

            P.coefficients_table[newExponent] += newCoeff; //man lägger in coeff vid graden exponent
        }
    }
    //ifall ngra termer får samma exponent på olika platser ska d slås ihop
        return P; 
}

Polynomial& operator+(Polynomial lhs, const Polynomial& rhs) {
    return lhs += rhs; 

}

Polynomial& operator-(Polynomial lhs, const Polynomial& rhs) {
    return lhs -= rhs;
}

Polynomial& operator*(Polynomial lhs,const Polynomial& rhs) {
    return lhs *= rhs;
}

bool Polynomial::operator==(const Polynomial& rhs) const {
   /* if (coefficients_table.empty() && rhs.coefficients_table.empty()) {
        return true;
    }*/
    return coefficients_table == rhs.coefficients_table;
}

//std::ostream& operator<<(std::ostream& os, const Polynomial& rhs) {
//    os << std::string(rhs);
//    return os; 
//}