#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "common_functions.hpp"

#define DEFAULT_ENCODER 9


namespace _hid {
    class __Encoder_Decode_Key {
        private:
            int encoder_of_user_key;
            int encoder_of_time;

            int __get_encoder_based_of_user_key(std::string user_key);
            int __get_encoder_based_of_time();

        public:
            int create_encoder(std::string user_key);
            std::string create_decode_key();
    };
}





int _hid::__Encoder_Decode_Key::__get_encoder_based_of_user_key(const std::string user_key) {
    for (int i=0; i<user_key.size(); i++) {
        this->encoder_of_user_key += (int) user_key[i];
    }
    this->encoder_of_user_key %= 100;

    return this->encoder_of_user_key;
}



int _hid::__Encoder_Decode_Key::__get_encoder_based_of_time() {
    this->encoder_of_time = abs(std::time(nullptr) * std::time(nullptr)) % 100;

    return this->encoder_of_time;
}



int _hid::__Encoder_Decode_Key::create_encoder(const std::string user_key) {
    int encoder = this->__get_encoder_based_of_user_key(user_key) + this->__get_encoder_based_of_time();
    encoder = (((encoder * encoder) % 100) + ((encoder + encoder) % 10)) % 100;

    return (encoder == 0) ? DEFAULT_ENCODER : encoder;
}



std::string _hid::__Encoder_Decode_Key::create_decode_key() {
    int encoder = this->encoder_of_user_key + this->encoder_of_time;
    encoder = (((encoder * encoder) % 100) + ((encoder + encoder) % 10)) % 100;

    return Cryption_Functions().to_binary(encoder);
}
