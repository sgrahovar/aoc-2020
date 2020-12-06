//
//  Day3.cpp
//  advent-of-code
//
//  Created by Sanjin Grahovar Sadiković on 03.12.2020..
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#define MAX_SIZE 1000

class Day3{
private:
    const static int m = 5, n = 5;
    char list[MAX_SIZE][MAX_SIZE];
    int lineCount = 0;
    int columnCount = 0;
    
    std::pair<int, int> pattern = {3, 1};
    
    std::vector<std::pair<int, int>> patterns = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };
    
public:
    
    
    Day3(){
        //std::ifstream file("Day3/day3.txt");
        std::ifstream file("Day3/day3.txt");
        std::string str;
        
        while (std::getline(file, str))
        {
            str.resize(str.size());
            if(columnCount == 0){
                columnCount = (int)str.size();
            }
                        
            for(int i = 0; i < str.length(); ++i){
                list[lineCount][i] = str[i];
                std::cout << str[i] << " ";
            }
            std::cout << std::endl;
            ++lineCount;
        }
        // std::cout << "Line count: " << line_count << std::endl;
        
    }
    
    int solveFirst(){
        int pointX = 1, pointY = 0;
        int result = 0;
        
        while(pointY <= lineCount){
            int possibleX = pointX + pattern.first;
            
            if(possibleX <= columnCount){
                pointX = possibleX;
            }
            
            else{
                pointX = abs(pointX  + pattern.first - columnCount);
            }
            
            pointY += pattern.second;
            if(list[pointY][pointX - 1] == '#') result++;
        }
        
        return result;
    }
    
    int solveSecond(){
        std::vector<int> results;
        
        for(int i = 0; i < patterns.size(); i++){
            int pointX = 1, pointY = 0;
            int result = 0;
            
            while(pointY <= lineCount){
                int possibleX = pointX + patterns[i].first;
                
                if(possibleX <= columnCount){
                    pointX = possibleX;
                }
                
                else{
                    pointX = abs(pointX  + patterns[i].first - columnCount);
                }
                
                pointY += patterns[i].second;
                if(list[pointY][pointX - 1] == '#') result++;
            }
                        
            results.push_back(result);
        }
        
        int result = 1;
        for(int i = 0; i < results.size(); i++){
            result *= results[i];
        }
        
        return result;
    }
};

