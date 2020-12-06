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

class Day1{
private:
    std::vector<int> list;
    
public:
    
    
    Day1(){
        //list = new std::vector<int>();
        std::ifstream file("Day1/day1.txt");
        std::string str;
        while (std::getline(file, str))
        {
            list.push_back(std::stoi(str));
        }
    }
        
    int solveFirst(){
        for(int i = 0; i < list.size() - 1; i++){
            for(int j = (int)list.size() - 1; j > i; j--){
                // std::cout << "Sum: " << list.at(i) + list.at(j) << std::endl;
                if(list.at(i) + list.at(j) == 2020)
                    return list.at(i) * list.at(j);
            }
        }
        return NULL;
    }
    
    int solveSecond(){
        for(int i = 0; i < list.size() - 1; i++){
            for(int j = (int)list.size() - 1; j > i; j-- ){
                for(int k = j - 1; k > i; k--){
                    if(list.at(i) + list.at(j) + list.at(k) == 2020){
                        return list.at(i) * list.at(j) * list.at(k);
                    }
                }
            }
        }
        return 0;
    }
};
