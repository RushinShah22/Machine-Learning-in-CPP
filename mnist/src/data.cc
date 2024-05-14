#include "data.hpp"
#include <vector>
#include <cstdint>


data::data()
{
    features = new std::vector<uint8_t>;
}

std::vector<uint8_t> * data::get_features(){
    return features;
}

uint8_t data::get_label(){
    return label;
}

void data::append_to_features(uint8_t val){
    features->push_back(val);
}

void data::set_label(uint8_t lb){
    label = lb;
}

uint32_t data::features_size(){
    return features->size();
}
