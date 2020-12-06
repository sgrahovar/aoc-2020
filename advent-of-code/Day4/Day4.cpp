//
//  Day4.cpp
//  advent-of-code
//
//  Created by Sanjin Grahovar Sadiković on 04.12.2020..
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

class Day4{
private:

    
public:
    std::string byr, iyr, eyr, hgt, hcl, ecl, pid, cid;
    
    std::vector<std::string> list;
        
    std::map<std::string, int> map;
    
    /*
    std::map< std::string,
        std::pair<
            std::pair<
                int,
                int
            >,
            int
        >
    > map2;
    */
    
    std::map< std::string,
        std::vector<
            std::pair<std::string, std::string>
            //int
        >
    > map2;
    
    std::map<std::string,
        std::map<
            std::string, std::string>
    > map3;
    
    
    Day4(){
        
        map3["byr"] = {
            {"required", "1"},
            {"rangeLower", "1920"},
            {"rangeHigher", "2002"},
        };
        
        map3["iyr"] = {
            {"required", "1"},
            {"rangeLower", "2010"},
            {"rangeHigher", "2020"}
        };
        
        map3["eyr"] = {
            {"required", "1"},
            {"rangeLower", "2020"},
            {"rangeHigher", "2030"}
        };
        
        map3["hgt"] = {
            {"required", "1"},
            {"rangeLowerCm", "150"},
            {"rangeHigherCm", "193"},
            {"rangeLowerIn", "59"},
            {"rangeHigherIn", "76"}
        };
        
        map3["hcl"] = {
            {"required", "1"},
            {"rangeLower", "0"},
            {"rangeHigher", "15"}
        };
        
        map3["ecl"] = {
            {"required", "1"},
            {"0", "amb"},
            {"1", "blu"},
            {"2", "brn"},
            {"3", "gry"},
            {"4", "grn"},
            {"5", "hzl"},
            {"6", "oth"}
        };
        
        map3["pid"] = {
            {"required", "1"},
            {"rangeHigher", "9"}
        };
        
        map3["cid"] = {
            {"required", "0"}
        };

        map = {
            std::make_pair("byr", 1),
            std::make_pair("iyr", 1),
            std::make_pair("eyr", 1),
            std::make_pair("hgt", 1),
            std::make_pair("hcl", 1),
            std::make_pair("ecl", 1),
            std::make_pair("pid", 1),
            std::make_pair("cid", 0)
        };
    }
    
    int solveFirst(){
        std::string line;
        std::ifstream file("Day4/day4.txt");
        // std::ifstream file("Day4/day4_example.txt");
        
        std::string tmpString2 = "";
        
        while (std::getline(file, line)){
            if(!line.empty()){
                tmpString2.append(line + " ");
            }
            else{
                list.push_back(tmpString2);
                tmpString2 = "";
            }
        }
        list.push_back(tmpString2);
        
        int valid = 0;
        
        for(int i = 0; i < list.size(); i++)
        {
            std::string key, value;
            int beginIndex = 0;
            std::vector<std::pair<std::string, std::string>> pairs;
            std::string tmpString;
            
            // Create pairs from string -> pairs.first = key; pairs.second = value;
            for(int j = 0; j < list[i].length(); j++){
                
                if(list[i][j] == ':'){
                    tmpString = list[i].substr(beginIndex, j - beginIndex);
                    beginIndex = j + 1;
                }
                
                if(list[i][j] == ' ' && list[i][j + 1]){
                    pairs.push_back(std::make_pair(tmpString, list[i].substr(beginIndex, j - beginIndex)));
                    beginIndex = j + 1;
                }
                
                if(j == list[i].length() - 1){
                    pairs.push_back(std::make_pair(tmpString, list[i].substr(beginIndex, j - beginIndex)));
                }
            }
                        
            int ignoredCount = 0;
            int count = 0;
            
            for(int j = 0; j < pairs.size(); j++){
                if(map.count(pairs[j].first) == 1 && map[pairs[j].first] == 1){
                    count++;
                }
            }
            
            ignoredCount = (int)std::count_if(std::begin(map),
                          std::end  (map),
                          [value](std::pair<std::string, int> const &p) {
                            return p.second == 0;
                          });

            if(count == map.size() - ignoredCount){
                // std::cout << "Passport valid" << std::endl;
                valid++;
            }
            
            else{
                // std::cout << "Passport invalid" << std::endl;
            }
                        
            count = 0;
        }

        return valid;
    }
    
    int solveSecond(){
        std::string line;
        std::ifstream file("Day4/day4.txt");
        //std::ifstream file("Day4/day4_example.txt");
        
        std::string tmpString2 = "";
        
        while (std::getline(file, line)){
            if(!line.empty()){
                tmpString2.append(line + " ");
            }
            else{
                list.push_back(tmpString2);
                tmpString2 = "";
            }
        }
        list.push_back(tmpString2);
        
        int valid = 0;
        
        for(int i = 0; i < list.size(); i++)
        {
            std::string key, value;
            int beginIndex = 0;
            std::vector<std::pair<std::string, std::string>> pairs;
            std::string tmpString;
            
            // Create pairs from string -> pairs.first = key; pairs.second = value;
            for(int j = 0; j < list[i].length(); j++){
                
                if(list[i][j] == ':'){
                    tmpString = list[i].substr(beginIndex, j - beginIndex);
                    beginIndex = j + 1;
                }
                
                if(list[i][j] == ' ' && list[i][j + 1]){
                    pairs.push_back(std::make_pair(tmpString, list[i].substr(beginIndex, j - beginIndex)));
                    beginIndex = j + 1;
                    
                }
                
                if(j == list[i].length() - 1){
                    pairs.push_back(std::make_pair(tmpString, list[i].substr(beginIndex, j - beginIndex)));
                }
            }
                        
            int ignoredCount = 0;
            
            for (auto it=map3.begin(); it!=map3.end(); ++it){
                if(it->second["required"] == "0") ignoredCount++;
            }
            
            
            
            int count = 0;
            
            for(int j = 0; j < pairs.size(); j++){
                if(map3.count(pairs[j].first) == 1 && map3[pairs[j].first]["required"] == "1"){
                    
                    // check birth year - byr
                    if(pairs[j].first == "byr" &&
                       (std::stoi(pairs[j].second) >= std::stoi(map3[pairs[j].first]["rangeLower"]) && std::stoi(pairs[j].second) <= std::stoi(map3[pairs[j].first]["rangeHigher"]))
                       ) {
                        count++;
                        // std::cout <<  "byr found" << std::endl;
                    }
                    
                    // check issue year - iyr
                    if(pairs[j].first == "iyr" &&
                       (std::stoi(pairs[j].second) >= std::stoi(map3[pairs[j].first]["rangeLower"]) && std::stoi(pairs[j].second) <= std::stoi(map3[pairs[j].first]["rangeHigher"]))
                       ) {
                        count++;
                        // std::cout <<  "iyr found" << std::endl;
                    }
                                        
                    // check expiration year - eyr
                    if(pairs[j].first == "eyr" &&
                       (std::stoi(pairs[j].second) >= std::stoi(map3[pairs[j].first]["rangeLower"]) && std::stoi(pairs[j].second) <= std::stoi(map3[pairs[j].first]["rangeHigher"]))
                       ) {
                        count++;
                        // std::cout <<  "eyr found" << std::endl;
                    }
                    
                    // check height - hgt
                    if(pairs[j].first == "hgt"){
                        if(pairs[j].second.substr(pairs[j].second.length() - 2) == "cm"){
                            if(std::stoi(pairs[j].second.substr(0, pairs[j].second.length() - 2)) >= std::stoi(map3[pairs[j].first]["rangeLowerCm"]) &&
                                std::stoi(pairs[j].second.substr(0, pairs[j].second.length() - 2)) <= std::stoi(map3[pairs[j].first]["rangeHigherCm"])
                               ) {
                                count++;
                                // std::cout <<  "cm hgt found" << std::endl;
                            }
                            
                        }
                        
                        else if(pairs[j].second.substr(pairs[j].second.length() - 2) == "in"){
                            if(std::stoi(pairs[j].second.substr(0, pairs[j].second.length() - 2)) >= std::stoi(map3[pairs[j].first]["rangeLowerIn"]) &&
                                std::stoi(pairs[j].second.substr(0, pairs[j].second.length() - 2)) <= std::stoi(map3[pairs[j].first]["rangeHigherIn"])
                               ) {
                                count++;
                                // std::cout <<  "in hgt found" << std::endl;
                            }
                        }
                    }
                    
                    if(pairs[j].first == "hcl"){
                        int passed = 0;
                        
                        if(pairs[j].second[0] == '#'){
                            for(int k = 1; k < pairs[j].second.length(); k++){
                                if( (pairs[j].second[k] >= 'a' || pairs[j].second[k] >= '0') &&
                                    (pairs[j].second[k] <= 'f' || pairs[j].second[k] <= '9')
                                   ) passed++;
                            }
                        }
                                                
                        if(passed == 6) {
                            count++;
                            // std::cout << "hcl found" << std::endl;
                        }
                    }
                    
                    if(pairs[j].first == "ecl"){
                        if(pairs[j].second == "amb" ||
                           pairs[j].second == "blu" ||
                           pairs[j].second == "brn" ||
                           pairs[j].second == "gry" ||
                           pairs[j].second == "grn" ||
                           pairs[j].second == "hzl" ||
                           pairs[j].second == "oth"
                        ){
                            count++;
                            // std::cout <<  "ecl found" << std::endl;
                        }
                    }
                    
                    
                    if(pairs[j].first == "pid") {
                        if(pairs[j].second.length() == 9 && std::stoi(pairs[j].second)){
                            // std::cout << "Pid found" << std::endl;
                            count++;
                        }
                    }
                }
                
            }

            if(count >= map3.size() - ignoredCount){
                // std::cout << "Passport valid" << std::endl;
                valid++;
            }
            
            else{
                // std::cout << "Passport invalid" << std::endl;
            }
                        
            count = 0;
        }
        
        return valid;
    }
};


