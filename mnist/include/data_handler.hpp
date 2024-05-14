#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include "data.hpp"

class data_handler{
    std::vector<data *> * data_array;
    std::vector<data *> *training_data;
    std::vector<data *> * testing_data;
    std::vector<data *> * validation_data;

    const double TRAIN_PERCENTAGE = 0.75;
    const double TEST_PERCENTAGE = 0.20;
    const double VALIDATION_PERCENTAGE = 0.05;
    uint32_t num_of_classes;

    public:
    data_handler();
    void read_features(std::string);
    void read_labels(std::string);
    void split_data();
    uint32_t data_size();
    uint32_t convert_to_little_endian(const unsigned char *);
    std::vector<data *> * get_train_data();
    std::vector<data *> * get_test_data();
    std::vector<data *> * get_validation_data();
    uint32_t get_num_of_classes();

};
