//
//  Day6.cpp
//  advent-of-code
//
//  Created by Sanjin Grahovar Sadiković on 06.12.2020..
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>

#define MAX_SIZE 1000

class Day6{
private:

    
public:
    std::vector<std::vector<std::string>> list2;
    
    
    Day6(){
        std::string line;
        //std::ifstream file("Day5/day6.txt");
        std::ifstream file("Day6/day6_example.txt");
        
        int i = 0;
        while (std::getline(file, line)){
            // if(!line.empty()) list2[i].push_back(line);
            // else i++;
            
            if(!line.empty()){
                list2.push_back(std::vector<std::string>());
                std::cout << "i: " << i << ", line: " << line << std::endl;
                list2[i].push_back(line);
            }
            else{
                i++;
                std::cout << std::endl;
            }
            
        }

    }
    
    int solveFirst(){
        
        for(int i = 0; i < list2.size(); i++){
            for(int j = 0; j < list2[i].size(); j++){
                std::cout << list2[i][j] << std::endl;
            }
        }

        
        return 0;
    }
    
    int solveSecond(){
        
        return 0;
    }
};
