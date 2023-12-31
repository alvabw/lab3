/*******************************
 * Lab 3: exercise 1            *
 * Frequency table of words     *
 *******************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   //std::pair
#include <fstream>
#include <cassert>
#include <algorithm>
#include <cctype>


// A function to test the output of the program
void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n);

std::string toLowerCase(std::string& str);

std::string removePuncts(const std::string& s);

/***************************
 * Main function           *
 **************************/

int main() {  
    std::cout << "Text file: ";
	std::string file_name;
	std::cin >> file_name;

	std::ifstream in_File{"../code/" + file_name};  // modify path, if needed

	if (!in_File) {
		std::cout << "Could not open input file!!\n";
		return 0;
	}

    std::map<std::string, int> table;
    int counter{0};  // to count total number of words read from the input file

    //ADD CODE to build table
  
    std::string wordHolder; 
    while (in_File >> wordHolder){ //l�ser tills den kommer till ett mellanrum
        std::string S = toLowerCase(wordHolder); 
        table[removePuncts(S)] += 1; //If the word is not in the map, a new entry is created with a count of 1?

        counter++;
    }

    
    std::vector<std::pair<std::string, int>> freq;

    //ADD CODE to build vector freq
    std::transform(table.begin(), table.end(), std::back_inserter(freq),
        [](const std::pair<const std::string, int>& element) {
            return element;
        });


    std::sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second; //decending 10,9,8...
        }
        return a.first < b.first;  //alfabetiskt
        });


  

    //for (auto e : freq) {
    //    std::cout << e.first << " " << e.second << "\n";
    //}


    /* ************** Testing **************** */

    test(table, freq, file_name, counter); //�ndrade name ---> file_name 
}


/*******************************
 * Test implementation         *
 * Do not modify               *
 *******************************/

void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n) {

    std::ifstream file{"../code/out_" + file_name}; //modify path, if needed

    // Test if stream is in good state
    assert(bool(file) == true);

    std::map<std::string, int> result1;
    std::string word;
    int counter{0};
    int total{0};

    // load expected frequency table sorted alphabetically
    while (file >> word >> counter && counter > 0) {
        result1[word] = counter;
        total += counter;
    }

    /*
     * uppgift1_kort: 69 words
     * uppgift1.txt: 1063 words
     */

    assert(total == n);    // test if total number of words is correct
    assert(t == result1);  // test if map/table contents are correct

    std::vector<std::pair<std::string, int>> result2;

    // load expected frequency table sorted by frequence
    while (file >> word >> counter) {
        result2.push_back(std::pair{word, counter});
    }
    assert(v == result2);  // test if vector contents are correct

    std::cout << "\nPassed all tests successfully!!\n";
}


//egna:
std::string toLowerCase(std::string& str) {

    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) {return std::tolower(c); }
    );
    return str;
}

std::string removePuncts(const std::string& s) {
    //lambda
    //[capture](params) {body}
    std::string result;
    std::remove_copy_if(s.begin(), s.end(), std::back_inserter(result), 
        [](unsigned char c) { return std::ispunct(c) && c !='\'' && c !='\-'; }); // (true om det �r punct && INTE en ' eller -) 
    return result;

  

}