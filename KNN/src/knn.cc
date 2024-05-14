#pragma GCC optimize("O3")

#include <cstdint>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cmath>
#include <map>
#include "data.hpp"
#include "knn.hpp"


KNN::KNN(uint8_t val){
    k = val;
}

uint8_t KNN::predict(data * input){
    std::vector<std::pair<double, uint8_t>> neighbours;

    for(int i = 0; i < X->size(); i++){
        double metric = calc_euclidean(input, X->at(i));
        neighbours.push_back(std::make_pair(metric, X->at(i)->get_label()));
    }
    std::sort(neighbours.begin(), neighbours.end());

    uint8_t ans = 0;
    std::map<uint8_t, uint32_t> label_count;

    for(int i = 0; i < k; i++){
        label_count[neighbours[i].second]++;
    }
    uint32_t max_count = 0;
    for(auto x: label_count){
        if(x.second > max_count){
            max_count = x.second;
            ans = x.first;
        }
    }

    return ans;

}

void KNN::fit(std::vector<data *> * inputs){
    X = inputs;
}

double KNN::calc_euclidean(data * x1, data * x2){
    double ans = 0;

    for(int i = 0; i < x1->features_size(); i++){
        double x11 = x1->get_features()->at(i);
        double x22 = x2->get_features()->at(i);
        ans += ((x11 - x22) * (x11 - x22));
    }
    return sqrtl(ans);
}


double KNN::accuracy_score(std::vector<data *> * test_data){
    uint32_t right = 0, wrong = 0;
    double count = 0;
    std::vector<bool> done(4);
    for(auto input: *test_data){
        count++;
        double percentage_done = count / test_data->size();
        if(percentage_done > 0.2 && percentage_done <= 0.3 && !done[0]){
            done[0] = true;
            printf("%f%c validation done.\n", percentage_done, '%');
        }
        if(percentage_done > 0.4 && percentage_done <= 0.5 && !done[1]){
            done[1] = true;
            printf("%f%c validation done.\n", percentage_done, '%');
        }
        if(percentage_done > 0.6 && percentage_done <= 0.7 && !done[2]){
            done[2] = true;
            printf("%f%c validation done.\n", percentage_done, '%');
        }
        if(percentage_done > 0.9 && percentage_done <= 1 && !done[3]){
            done[3] = true;
            printf("%f%c validation done.\n", percentage_done, '%');
        }
        uint8_t output = predict(input);

        if(output == input->get_label())right++;
        else wrong++;
    }
    return ((double)right / (right + wrong));
}

void KNN::set_k(uint8_t val){
    k = val;
}
