// Copyright 2024 Kaylee
#include <iostream>
#include <string>
#include <cstddef>
#include <hw2/inc/parse_demographics.h>

std::size_t ParseNumPatients(const std::string values[], std::size_t size, ParseErrors* errors) {
    if(errors) 
    *errors = ParseErrors::kNoErrors;

    std::size_t index = 1; //starting at the second index bc the first is unnecessary
    std::size_t num_patients; 
    if(index < size)
        num_patients = std::stoi(values[index]);
    
    if(errors && num_patients == 0) {
        *errors = ParseErrors::kNoPatients;
    }

    return num_patients;
}

std::size_t ParseNumEthnicities(const std::string& patient_id, const std::string values[], std::size_t size, ParseErrors* errors) {
    if(errors) 
    *errors = ParseErrors::kNoErrors;

    std::size_t index = 1; //starting at the second index bc the first is unnecessary
    std::size_t num_patients; 
    if(index < size)
        num_patients = std::stoi(values[index]);
    
    if(errors && num_patients == 0) {
        *errors = ParseErrors::kNoPatients;
    }
    for(std::size_t i = 0; i < num_patients; ++i){
        std::size_t num_eth = 0;
        if(patient_id == values[index])
            num_eth = std::stoi(values[index]);
        switch(values[index].front()){
            case 'S':
            case 'W':
            index += 2;
            break;

            case 'E':
            //put something here to parse ethnicities
            break;

            case 'B':
            index += 4;
            break;
        }

    }
    return 0;
}


std::size_t ParseEthnicityValues(const std::string& patient_id, const std::string values[], std::size_t size, char ethnicity_values[], ParseErrors* errors) {
if(errors) 
    *errors = ParseErrors::kNoErrors;

    std::size_t index = 1; //starting at the second index bc the first is unnecessary
    std::size_t num_patients; 
    if(index < size)
        num_patients = std::stoi(values[index]);
    
    if(errors && num_patients == 0) {
        *errors = ParseErrors::kNoPatients;
    }
    for(std::size_t i = 0; i < num_patients; ++i){
        std::size_t num_eth = 0;
        if(patient_id == values[index])
            num_eth = std::stoi(values[index]);
        switch(values[index].front()){
            case 'S':
            case 'W':
            index += 2;
            break;

            case 'E':
            //put something here to parse ethnicities
            break;

            case 'B':
            index += 4;
            break;
        }

    }
    return 0;
}