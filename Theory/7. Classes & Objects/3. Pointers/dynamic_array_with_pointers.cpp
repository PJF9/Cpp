#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#define memory_condition std::cout << "Error Allocating Memory" << std::endl; exit(0);


class array {
    private:
        int *arr = nullptr;
        int size = 0;

    public:
        array() {
            this->arr = new int [0];
            if (!this->arr) {memory_condition;}
        }
        array(std::initializer_list<int> list) {
            this->arr = new int [list.size()];

            if (!arr) {memory_condition;}

            for (auto i = list.begin(); i<list.end(); i++) {
                this->arr[this->size] = *i; 
                this->size ++;
            }
        }
        array(const array &obj) {
            this->size = obj.get_size();
            this->arr = new int [this->size];

            if (!this->arr) {memory_condition;}

            for (int i=0; i<this->size; i++ ) {
                this->arr[i] = obj.get_elem(i);
            }
        }
        ~array() {
            delete [] this->arr;
        }

        inline int get_size() const {
            return this->size;
        }

        inline int get_elem(int index) const {
            return this->arr[index];
        }

        void append(int value) {
            int *temp = new int [this->size];
            
            if (!temp) {memory_condition;}
            
            for (int i=0; i<this->size; i++) {
                temp[i] = this->arr[i];
            }

            delete [] this->arr;

            this->size ++;
            this->arr = new int [this->size];

            if (!this->arr) {memory_condition;}

            for (int i=0; i<this->size - 1; i++) {
                this->arr[i] = temp[i];
            }
            this->arr[this->size - 1] = value;

            delete [] temp;
        }

        void pop() {
            this->size --;

            int *temp = new int [this->size];

            if (!temp) {memory_condition;}

            for (int i=0; i<this->size; i++) {
                temp[i] = this->arr[i];
            }

            delete [] this->arr;

            this->arr = new int [this->size];
            if (!this->arr) {memory_condition;}

            for (int i=0; i<this->size; i++) {
                this->arr[i] = temp[i];
            }

            delete [] temp;
        }
};


class array_2d {
    private:
        int **arr = nullptr;
        int rows = 0;
        int columns = 0;

    public:
        array_2d(std::initializer_list<std::initializer_list<int>> list) {
            this->arr = new int *[list.size()];

            for (int i=0; i<list.size(); i++) {
                this->arr[i] = new int [list.begin()->size()];
                this->columns = 0;

                for (auto j=(list.begin() + i)->begin(); j<(list.begin() + i)->end(); j++) {
                    this->arr[this->rows][this->columns] = *j;
                    this->columns ++;
                }
                this->rows ++;
            } 
        }
        ~array_2d() {
            for (int i=0; i<this->rows; i++) {
                delete [] this->arr[i];
            }
            delete [] this->arr;
        }

        inline int get_elem(int row, int column) const {
            return this->arr[row][column];
        }

        inline int get_rows() const {
            return this->rows;
        }

        inline int get_columns() const {
            return this->columns;
        }
};


int main() {
    array a = {10, 11, 12};

    a.append(13);
    a.append(14);
    a.append(15);

    a.pop();
    a.pop();
    a.pop();
    a.pop();

    array another_a = a;

    for (int i=0; i<another_a.get_size(); i++) {
        std::cout << another_a.get_elem(i) << " ";
    }
    std::cout << std::endl;

    array_2d aa = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i=0; i<aa.get_rows(); i++) {
        for (int j=0; j<aa.get_columns(); j++) {
            std::cout << aa.get_elem(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
