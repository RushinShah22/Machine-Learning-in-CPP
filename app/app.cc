#pragma GCC optimize("O3")


#include <cstdint>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

#include "data_handler.hpp"
#include "knn.hpp"

int main(){
    data_handler * dt = new data_handler();
    std::string path = std::filesystem::current_path();
    dt->read_features(path + "/mnist/train-images.idx3-ubyte");
    dt->read_labels(path + "/mnist/train-labels.idx1-ubyte");
    dt->split_data();
    printf("size of validation data is %ld\n", dt->get_validation_data()->size());

    KNN knn = KNN(0);
    knn.fit(dt->get_train_data());
    printf("Model fitted.\n");

    for(int i = 3; i < 6; i++){
        knn.set_k(i);
        double score = knn.accuracy_score(dt->get_validation_data());
        printf("accuary with K = %d is:  %.3f\n", i, score);
    }

    return 0;
}
