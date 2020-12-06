//
//  Day5.cpp
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

class Day5{
private:

    
public:
    
    std::vector<std::string> list;
    
    
    Day5(){
        std::string line;
        std::ifstream file("Day5/day5.txt");
        // std::ifstream file("Day4/day4_example.txt");
                
        while (std::getline(file, line)){
            list.push_back(line);
        }
    }
    
    int solveFirst(){
        
        int max = 0;
        
        for(int i = 0; i < list.size(); i++){
            
            std::pair<int, int> rangeRow = std::make_pair(0, 127);
            std::pair<int, int> rangeColumn = std::make_pair(0, 7);
                        
            int row = -1, column = -1;
            int lastRow = -1, lastColumn = -1;
                        
            for(int j = 0; j < list[i].length() - 3; j++){
                float middle = (rangeRow.second - rangeRow.first) / 2.0f;
                if(list[i][j] == 'F'){
                    rangeRow.second -= middle;
                }
                
                else if(list[i][j] == 'B'){
                    rangeRow.first += middle + 1;
                }
                                
                if(lastRow == rangeRow.first){
                    row = rangeRow.first;
                }
                lastRow = rangeRow.first;
            
            }
                        
            for(int j = (int)list[i].length() - 3; j < list[i].length(); j++){
                // std::cout << "str[i]: " << str[i] << std::endl;
                float middle = (rangeColumn.second - rangeColumn.first) / 2.0f;
                if(list[i][j] == 'L'){
                    rangeColumn.second -= middle;
                }
                
                else if(list[i][j] == 'R'){
                    rangeColumn.first += middle + 1;
                }
                                
                if(lastColumn == rangeColumn.second){
                    column = rangeColumn.second;
                }
                
                lastColumn = rangeColumn.second;
            }
            
            
                    
            int result = rangeRow.first * 8 + rangeColumn.second;
            if(result > max) max = result;
        }
                
        return max;
    }
    
    int solveSecond(){
        int max = 0, min = 0, sum = 0;
        
        std::vector<int> results;
        
        for(int i = 0; i < list.size(); i++){
            
            std::pair<int, int> rangeRow = std::make_pair(0, 127);
            std::pair<int, int> rangeColumn = std::make_pair(0, 7);
                        
            int row = -1, column = -1;
            int lastRow = -1, lastColumn = -1;
                        
            for(int j = 0; j < list[i].length() - 3; j++){
                float middle = (rangeRow.second - rangeRow.first) / 2.0f;
                if(list[i][j] == 'F'){
                    rangeRow.second -= middle;
                }
                
                else if(list[i][j] == 'B'){
                    rangeRow.first += middle + 1;
                }
                
                if(lastRow == rangeRow.first){
                    row = rangeRow.first;
                }
                
                lastRow = rangeRow.first;
            
            }
            
            for(int j = (int)list[i].length() - 3; j < list[i].length(); j++){
                float middle = (rangeColumn.second - rangeColumn.first) / 2.0f;
                if(list[i][j] == 'L'){
                    rangeColumn.second -= middle;
                }
                
                else if(list[i][j] == 'R'){
                    rangeColumn.first += middle + 1;
                }
                                                
                if(lastColumn == rangeColumn.second){
                    column = rangeColumn.second;
                }
                
                lastColumn = rangeColumn.second;
            }
            
            int result = rangeRow.first * 8 + rangeColumn.second;
            if(i == 0) min = result;
            
            if(result >= max) max = result;
            else if (result < min) min = result;
            
            results.push_back(result);
            sum += result;
        }
                
        int difference = 0;
        for(int i = min; i <= max; i++){
            difference += i;
        }
                        
        return difference - sum;
    }
};



