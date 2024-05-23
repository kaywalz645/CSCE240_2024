// Copyright 2024 Kaylee
#include <hw2/inc/parse_demographics.h>
#include <iostream>
#include <string>
#include <cstddef>

std::size_t ParseNumPatients(const std::string values[],
                            std::size_t size, ParseErrors* errors) {
    if (errors)
        *errors = ParseErrors::kNoErrors;

    std::size_t index = 1;
    std::size_t num_patients;
    if (index < size)
        num_patients = std::stoi(values[index]);

    if (errors && num_patients == 0) {
        *errors = ParseErrors::kNoPatients;
    }

    return num_patients;
}

std::size_t ParseNumEthnicities(const std::string& patient_id,
                                const std::string values[], std::size_t size,
                                ParseErrors* errors) {
    std::size_t index = 1;
    std::size_t num_patients;

    if (index < size)
        num_patients = std::stoi(values[index]);
    ++index;

    if (errors && num_patients == 0) {
        *errors = ParseErrors::kNoPatients;
        return 0;
    }

    for (std::size_t i = 0; i < num_patients; ++i) {
        std::size_t num_eth = 0;

        if (patient_id == values[index]) {
            num_eth = std::stoi(values[index]);
            ++index;
        } else {
            while (patient_id != values[index]) {
                ++index;
                if (index == size) {
                    *errors = ParseErrors::kMissingPatient;
                    return 0;
                }
            }
            ++index;
        }

        while (std::string("SEWB").find(values[index].front())
                                        != std::string::npos)
        switch (values[index].front()) {
            case 'S':
            case 'W':
            index += 2;
            continue;

            case 'B':
            index += 4;
            continue;

            case 'E':
            ++index;
            num_eth = stoi(values[index]);
            if (i == 0 && errors) {
                *errors = ParseErrors::kNoEthnicities;
                return 0;
            }
            index += num_eth;
            if (num_patients == i) {
                break;
            }
            ++index;
            break;
        }
        return num_eth;
    }
}


std::size_t ParseEthnicityValues(const std::string& patient_id,
                                const std::string values[],
                                std::size_t size, char ethnicity_values[],
                                ParseErrors* errors) {
    std::size_t index = 1;
    std::size_t num_patients;


    if (index < size)
        num_patients = std::stoi(values[index]);
    ++index;


    if (errors && num_patients == 0) {
        *errors = ParseErrors::kNoPatients;
        return 0;
    }

    std::size_t ethnicity_index = 0;

    for (std::size_t i = 0; i < num_patients; ++i) {
        std::size_t num_eth = 0;

        if (patient_id == values[index]) {
            num_eth = std::stoi(values[index]);
            ++index;
        } else {
            while (patient_id != values[index]) {
                ++index;
                if (index == size) {
                    *errors = ParseErrors::kMissingPatient;
                    return 0;
                }
            }
            ++index;
        }

        while (std::string("SEWB").find(values[index].front())
                != std::string::npos)
        switch (values[index].front()) {
            case 'S':
            case 'W':
            index += 2;
            continue;

            case 'B':
            index += 4;
            continue;

            case 'E':
            ++index;
            num_eth = stoi(values[index]);
            if (i == 0 && errors) {
                *errors = ParseErrors::kNoEthnicities;
                return 0;
            }

            if (num_eth > 0) {
            ++index;
            for (std::size_t ii = 0; ii < num_eth; ii++) {
                ethnicity_values[ethnicity_index] = values[index][i];
                ++ethnicity_index;
                ++index;
            }
            break;
            } else {
                break;
            }
            if (num_patients == i) {
                break;
            }
            ++index;
            break;
        }
        return num_eth;
    }
}


