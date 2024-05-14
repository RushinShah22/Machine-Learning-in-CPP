#pragma once
#include <vector>
#include <string>
#include <cstdint>

#include "data.hpp"

class KNN{
    std::vector<data *> * X;
    uint8_t k;


    public:
    KNN(uint8_t);
    double calc_euclidean(data *, data *);
    uint8_t predict(data *);
    void fit(std::vector<data *> *);
    void set_k(uint8_t);
    double accuracy_score(std::vector<data *> *);

};
