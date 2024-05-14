#pragma once

#include <vector>
#include <cstdint>

class data
{
    std::vector<uint8_t> * features;
    uint8_t label;

public:
    data();
    std::vector<uint8_t>* get_features();
    uint8_t get_label();
    void append_to_features(uint8_t val);
    void set_label(uint8_t);
    uint32_t features_size();
};
