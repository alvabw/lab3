/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"


 //consturctor
Polynomial::Polynomial(int coef, int exp) {
    if (coef != 0) {
        coefficients_table[exp] = coef;
    }
}

Polynomial::Polynomial(int coef) {
    if (coef != 0) {
        coefficients_table[0] = coef;
    }
}

//vector with vectors KOLLA PÅ DENNA IGEN
Polynomial::Polynomial(const std::vector<std::pair<int, int>> & V ) {

   /*std::copy(V.begin(), V.end(), std::inserter(coefficients_table, coefficients_table.begin())); */
   std::copy(V.begin(), V.end(), std::inserter(coefficients_table, end(coefficients_table)));
}

//copiable är default, man behöver inte omdefieniera det  här
//assignable dedfault


//degree
int Polynomial::degree() {
    int currentDegree = 0; 

    for (const auto& i : coefficients_table) {
        currentDegree = std::max(currentDegree, i.first);
    }

    return currentDegree;
  
}

//tye conversion operator
Polynomial::operator std::string() const{
    //i.second är koefficienten och i.first är exponenten
    std::string S = "";
    int counter = 0; 

    if (coefficients_table.empty()) {
        S = "0";
    }

    for (const auto& it : coefficients_table) {
        if ( it.first == 0 || it.second !=0) { //ifall coeff = 0 så ska den ju inte skrivas ut xD 
          
            if (counter == 0) {
                    S = std::format("{}X^{}", it.second, it.first); //föasta värdet (om den är posiiv) 
            }
         
            
            if (it.second < 0 && counter != 0) {
             
                S += std::format(" - {}X^{}", abs(it.second), it.first);
            }
            else if(counter != 0) {
                S += std::format(" + {}X^{}", it.second, it.first);
            }
            
        }counter++;
    }
   
    return S; 
}

//operators
//EJ NESTED FOR LOOPS ENDAST I *= 
//PAPPRET!
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {

   for (const auto& i : rhs.coefficients_table) {
        coefficients_table[i.first] += i.second; //For each term in rhs, add the coefficient (i.second) to the corresponding term in the current polynomial 

        if (coefficients_table[i.first] == 0) {
            coefficients_table.erase(i.first);
        }
    }

    return *this; 
}


//vi är här typ
Polynomial& Polynomial::operator-=(const Polynomial& rhs) {

    for (const auto& i : rhs.coefficients_table) {
        coefficients_table[i.first] -= i.second; //For each term in rhs, subtract the coefficient (i.second) to the corresponding term in the current polynomial 

        if (coefficients_table[i.first] == 0) {//det är value aka second=coefficient
            coefficients_table.erase(i.first);
        }
     }
    

    return *this;
}

Polynomial Polynomial::operator*=(const Polynomial& rhs) {
    Polynomial returnPol;

    if (this->coefficients_table.empty() || rhs.coefficients_table.empty()) {
        this->coefficients_table.clear();
        return *this; //om någon 0 blir allt 0
    }

    Polynomial P = rhs; 

    for (auto i : coefficients_table) {
        returnPol += P.mult(i);
    }
    
    //ifall ngra termer får samma exponent på olika platser ska d slås ihop
    *this = returnPol; 
    return *this; 
}


//+ operator 2 olika
Polynomial operator+(Polynomial lhs, const Polynomial& rhs) {
    return lhs += rhs; 
}
Polynomial operator+(Polynomial& lhs, const int rhs) {
    return lhs += Polynomial(rhs);
}


//- operator 2 olika
Polynomial operator-(Polynomial lhs, const Polynomial& rhs) {
    return lhs -= rhs;
}
Polynomial operator-(Polynomial& lhs, const int rhs) {
    return lhs -= Polynomial(rhs); 
}

//* operator 2 olika
Polynomial operator*(Polynomial& lhs, const Polynomial& rhs) {
    Polynomial result = 1; // multiplicerar lhs med 1 för att int ändra lhs
    result *= lhs; //sätter till en annan variabel. Annars ändrades p1 i test.cpp :( 
    result *= rhs;
    return result;
}
Polynomial operator*(int i, const Polynomial& rhs) {
   return Polynomial(i) *= rhs;
}




bool operator==(const Polynomial& lhs, const Polynomial& rhs){
   /* if (coefficients_table.empty() && rhs.coefficients_table.empty()) {
        return true;
    }*/
    return lhs.coefficients_table == rhs.coefficients_table;
}

std::ostream& operator<<(std::ostream& os, Polynomial& rhs) {
    os << std::string(rhs);
    return os;
}

//Egna funktioner
Polynomial Polynomial::mult(std::pair<int, int> i){
    Polynomial result;
    for (std::pair<int, int> it : coefficients_table) {
        int coef = it.second * i.second;
        int exp = it.first + i.first;

        if (result.coefficients_table.find(exp) != result.coefficients_table.end()) {
            result.coefficients_table[exp] += coef;
        }
        else {
            result.coefficients_table[exp] = coef;
        }
        
    }
    return result;
}