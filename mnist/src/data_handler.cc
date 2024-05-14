#include <vector>
#include <fstream>
#include <cstdint>
#include <string>
#include <cstdlib>
#include <ctime>
#include <set>
#include "data_handler.hpp"


data_handler::data_handler(){
    data_array = new std::vector<data *> ;
    training_data = new std::vector<data * >;
    testing_data = new std::vector<data *>;
    validation_data = new std::vector<data *>;

}

uint32_t data_handler::data_size(){
    return data_array->size();
}

void data_handler::read_features(std::string path){

    FILE * f = fopen(path.c_str(), "r");

    uint32_t headers[4]; // MAGIC|NUM|ROWS|COLS
    unsigned char bytes[4];

    if(f){

        for(int i = 0; i < 4; i++){
            if(fread(bytes, sizeof(bytes), 1, f)){

                headers[i] = convert_to_little_endian(bytes);
            }else{
                printf("error loading data.\n");
                exit(1);
            }
        }

        printf("Done reading features headers.\n");

        uint32_t image_size = headers[2] * headers[3];
        uint32_t num_of_images = headers[1];

        for(int i = 0; i < num_of_images; i++){

            uint8_t single_feature[1];
            data * datum = new data();

            for(int j = 0; j < image_size; j++){
                if(fread(single_feature, sizeof(single_feature), 1, f)){
                    datum->append_to_features(single_feature[0]);

                }else{
                    printf("error reading data\n");
                    exit(1);
                }
            }
            data_array->push_back(datum);
        }
        printf("Done reading features.\n");
    }else{
        printf("Failed to locate file.\n");
        exit(1);
    }

    fclose(f);
}

void data_handler::read_labels(std::string path){

    FILE * f = fopen(path.c_str(), "r");

    if(f){
        uint32_t headers[2];

        unsigned char bytes[4];

        for(int i = 0; i < 2; i++){

            if(fread(bytes, sizeof(bytes), 1, f)){

                headers[i] = convert_to_little_endian(bytes);
            }else{
                printf("problem reading data \n");
                exit(1);
            }

        }

        printf("Done reading labels headers.\n");


        uint32_t num_of_labels = headers[1];
        std::set<uint8_t> num_of_classes;

        for(int i = 0; i < num_of_labels; i++){
            uint8_t bytes[1];
            if(fread(bytes, sizeof(bytes), 1, f)){
                data_array->at(i)->set_label(bytes[0]);
                num_of_classes.insert(bytes[0]);
            }else{
                printf("error reading data.\n");
                exit(1);
            }
        }
        this->num_of_classes = num_of_classes.size();

        printf("Done reading labels.\n");

    }else{
        printf("Failed to open labels file!!!\n");
        exit(1);
    }
    fclose(f);
}

void data_handler::split_data(){
    uint32_t train_data_size = data_size() * data_handler::TRAIN_PERCENTAGE;
    uint32_t test_data_size = data_size() * data_handler::TEST_PERCENTAGE;
    uint32_t validation_data_size = data_size() * data_handler::VALIDATION_PERCENTAGE;

    srand(std::time(0));

    std::vector<int> perm(data_size());
    for(int i = 0; i < data_size(); i++){
        perm[i] = i;
    }

    int x = data_size();

    while(x > 0){
        int rand_num = std::rand() % x + 1;
        std::swap(perm[x - 1], perm[rand_num - 1]);
        x--;
    }

    for(int i = 0; i < data_size(); i++){
        if(i < train_data_size){
            training_data->push_back(data_array->at(perm[i]));
        }else if(i < (test_data_size + train_data_size)){
            testing_data->push_back(data_array->at(perm[i]));
        }else{
            validation_data->push_back(data_array->at(perm[i]));
        }

    }


}

uint32_t data_handler::convert_to_little_endian(const unsigned char * bytes){
    return (uint32_t)((bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3]);
}

std::vector<data *> *  data_handler::get_test_data(){
    return testing_data;
}
std::vector<data *> *  data_handler::get_train_data(){
    return training_data;
}
std::vector<data *> *  data_handler::get_validation_data(){
    return validation_data;
}

uint32_t data_handler::get_num_of_classes(){
    return num_of_classes;
}
