/*********************************************
 * Lab 3: exercise 3                         *
 * Program to compute an approximation of pi *
 * STL-algorithms should be used             *
 *********************************************/

#include <iostream>
#include <cmath>
#include <format>
#include <vector>
#include <algorithm>
#include <numeric>


 double calculate(double k) {
        double const factor{ 8.0 * k };
        double const init{ 4.0 / (factor + 1.0) - 1.0 / (factor + 4.0) };

        std::vector<double> other_factors{ 4.0, 5.0, 6.0 };

        //räknar lite?
        std::transform(other_factors.begin(), other_factors.end(), other_factors.begin(),
            [factor](double& value) {return -1.0 / (factor + value); }); 

        //Summera ihop
        double result{ init };

       result = std::accumulate(other_factors.begin(), other_factors.end(), init); 

        return result;
    }





int main() {
    std::cout << "Enter number of terms: ";
    int n;
    std::cin >> n;

    // ADD CODE

    //Iota för varje element för den ++
    std::vector<double> terms(n);
    std::iota(terms.begin(), terms.end(), 0.0);

    std::vector<double> power_terms{ terms };

    //ändrar nu terms 
    //skicka till calculte
    std::transform(terms.begin(), terms.end(), terms.begin(),
        [](double& term) {return calculate(term); });

    //Fixar lilla perentesen
    std::transform(power_terms.begin(), power_terms.end(), power_terms.begin(),
        [](double& term) {return std::pow(16.0, term * (-1)); });

    double result{ 0.0 };

    //inner product av terms(stora parentesen) och powwer_terms(lilla perentesen)
    result += std::inner_product(std::begin(terms), std::end(terms), std::begin(power_terms), 0.0);

    std::cout << std::format("{:.15f}\n", result);
    
}