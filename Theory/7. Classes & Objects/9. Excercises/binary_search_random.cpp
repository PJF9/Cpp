#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <math.h>


class Binary_Search {
    private:
        int *array;
        int *ready_array;
        int length;
        int normal_length;
        int max_number;
        int user_num;
        int max_searches;
    public:
        Binary_Search() {
            array = NULL;
            ready_array = NULL;
            length = 0;
        }
        ~Binary_Search() {
            delete [] array;
            delete [] ready_array;
        }

        void set_user_length() {
            std::cout << "Enter the length of the array: ";
            std::cin >> length;
        }

        void set_max_number() {
            std::cout << "Enter the max number in the array: ";
            std::cin >> max_number;
        }

        void set_user_num() {
            
            while (true) {
                std::cout << "Enter the number you want me to search: ";
                std::cin >> user_num;

                if (user_num > max_number) {
                    std::cout << "That number is heighter than the max number you inserted before" << std::endl;
                } else {
                    break;
                }
            }
        }
        
        int set_max_searches() {
            max_searches = log2(normal_length+1) + 1;
        }

        void fill_array() {
            array = new int [length];
            srand(time(NULL));

            for (int i=0; i<length; i++) {
                int num = rand() % max_number;
                array[i] = num;
            }

        }

        void sort_the_array() {
            for (int i=0; i<length; i++) {
                int j = i;

                for (int k=i+1; k<length; k++) {
                    if (array[k] < array[j]) {
                        j = k;
                    }
                }
                
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        void remove_same_elements() {
            int last = 0;
            for (int p=0; p<length; p++) {
                if (array[p] < array[p+1] && array[p] <= max_number) {
                    last ++;
                }
            }

            int first = 0;
            for (int i=0; i<last; i++) {
                if (array[0] == array[i]) {
                    first ++;
                }
            }   

            int start = -1 * ceil(first / 4.0);

            for (int i=start; i<length; i++) {
                for (int j=i; j<length; j++) {
                    if (array[j] == array[j+1]) {
                        for (int k=j; k<length; k++) {
                            array[k] = array[k+1];
                        }
                    }
                }
            }

            ready_array = new int [length];            

            for (int i=0; i<=last; i++) {
                ready_array[i] = array[i];
            }

            if (array[last] > max_number) {
                normal_length = last - 1;
            } else {
                normal_length = last;
            }
        }

        void print_array() {
            for (int i=0; i<=normal_length; i++) {
                std::cout << ready_array[i] << std::endl;
            }
        }

        void search_in_the_array() {
            int start = 0;
            int end = normal_length + 1;
            int count = 1; 
            
            std::cout << std::endl;

            while (true) {
                int middle = (start + end) / 2;

                if (ready_array[middle] == user_num) {
                    std::cout << "The number you are looking for is: " << ready_array[middle] << std::endl;
                    std::cout << "I have found it with " << count << " moves" << std::endl;
                    break;
                } else if (ready_array[middle] < user_num) {
                    start = middle + 1;
                } else {
                    end = middle - 1;
                }

                if (count == max_searches) {
                    std::cout << "The number you are looking for is not in the array" << std::endl;
                    break;
                }
                count ++;
            }
        }

        void go() {
            set_user_length();
            set_max_number();
            set_user_num();
            fill_array();
            sort_the_array(); 
            remove_same_elements();
            set_max_searches();
            print_array();
            search_in_the_array(); 
        }
};


int main() {
    Binary_Search b;
    b.go();
}
