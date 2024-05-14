#include <cstdint>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

#include "data_handler.hpp"

int main(){
    data_handler * dt = new data_handler();
    std::string path = std::filesystem::current_path();
    dt->read_features(path + "/mnist/train-images.idx3-ubyte");
    dt->read_labels(path + "/mnist/train-labels.idx1-ubyte");
    dt->split_data();
    // printf("%u", dt->get_num_of_classes());
    printf("%lu %lu %lu", dt->get_train_data()->size(), dt->get_test_data()->size(), dt->get_validation_data()->size());
    return 0;
}
