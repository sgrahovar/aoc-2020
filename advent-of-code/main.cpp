//
//  main.cpp
//  advent-of-code
//
//  Created by Sanjin Grahovar Sadiković on 01.12.2020..
//

#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "Day1/Day1.cpp"
#include "Day2/Day2.cpp"
#include "Day3/Day3.cpp"
#include "Day4/Day4.cpp"
#include "Day5/Day5.cpp"
#include "Day6/Day6.cpp"


int main(int argc, const char * argv[]) {
    
    /*
    Day1 day1;
    std::cout << "Day 1, challenge 1: " << day1.solveFirst() << std::endl;
    std::cout << "Day 1, challenge 2: " << day1.solveSecond() << std::endl;
    
    Day2 day2;
    std::cout << "Day 2, challenge 1: " << day2.solveFirst() << std::endl;
    std::cout << "Day 2, challenge 2: " << day2.solveSecond() << std::endl;
    
    
    Day3 day3;
    std::cout << "Day 3, challenge 1: " << day3.solveFirst() << std::endl;
    std::cout << "Day 3, challenge 2: " << day3.solveSecond() << std::endl;
    */
    
    
    
    auto start = std::chrono::high_resolution_clock::now();
    
    Day4 day4;
    //std::cout << "Day 4, challenge 1: " << day4.solveFirst() << std::endl << std::endl;
    std::cout << "Day 4, challenge 2: " << day4.solveSecond() << std::endl << std::endl;
    
    //Day5 day5;
    // std::cout << "Day 5, challenge 1: " << day5.solveFirst() << std::endl << std::endl;
    //std::cout << "Day 5, challenge 1: " << day5.solveSecond() << std::endl << std::endl;
    
    //Day6 day6;
    //std::cout << "Day 6, challenge 1: " << day6.solveFirst() << std::endl << std::endl;
    
    auto stop = std::chrono::high_resolution_clock::now();
    
    
    // std::cout << "Answer: " << answer << std::endl;
    auto durationMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Function execution duration: " << durationMicroseconds.count() << " microseconds, " <<
    (float)durationMicroseconds.count()/1000000 << " seconds." << std::endl;

    
    return 0;
}


void random_calculateSumOfDigits(int n){
    // int n = 1721;
    int count = 0;
    
    for(int i = n; i > 0; i = i/10){
        std::cout << i%10 << std::endl << std::endl;
        count += i%10;
    }
    
    std::cout << "Sum: " << count << std::endl;
}

