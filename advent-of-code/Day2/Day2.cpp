//
//  Day1.cpp
//  advent-of-code
//
//  Created by Sanjin Grahovar Sadiković on 02.12.2020..
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

class Day2{
private:
    std::vector<std::string> list;
    
public:
    
    
    Day2(){
        //list = new std::vector<int>();
        std::ifstream file("Day2/day2.txt");
        std::string str;
        while (std::getline(file, str))
        {
            list.push_back(str);
        }
    }
        
    int solveFirst(){
        int result = 0;
        
        for(int j = 0; j < list.size(); j++) {
            std::string containsRange, password, letter;
            
            std::stringstream ss(list[j]);
            
            // Get range
            std::getline(ss, containsRange, ' ');
            
            // Get letter we're searching
            std::getline(ss, letter, ':');
            
            // Get password
            password = list[j].substr(list[j].find(": ") + 2);
            
            // Split range from string to int
            std::stringstream ss2(containsRange);
            
            std::pair<int, int> range;
            range.first = std::stoi(containsRange.substr(0, containsRange.find("-")));
            range.second = std::stoi(containsRange.substr(containsRange.find("-") + 1));
            
            int count = 0;
            
            for(int i = 0; i < password.length(); i++){
                if(password[i] == letter[0]){
                    count++;
                }
            }
            
            if(count >= range.first && count <= range.second){
                result++;
            }
        
        }

        return result;
    }
    
    int solveSecond(){
        int result = 0;
        
        for(int j = 0; j < list.size(); j++) {
            std::string containsRange, password, letter;
            
            std::stringstream ss(list[j]);
            
            // Get range
            std::getline(ss, containsRange, ' ');
            
            // Get letter we're searching
            std::getline(ss, letter, ':');
            
            // Get password
            password = list[j].substr(list[j].find(": ") + 2);
            
            // Split range from string to int
            std::stringstream ss2(containsRange);
            
            std::pair<int, int> range;
            range.first = std::stoi(containsRange.substr(0, containsRange.find("-")));
            range.second = std::stoi(containsRange.substr(containsRange.find("-") + 1));
                    
            if(letter[0] == password[range.first - 1] || letter[0] == password[range.second - 1]){
                if(password[range.first - 1] != password[range.second - 1]){
                    result++;
                }
            }
        }

        return result;
    }
};
