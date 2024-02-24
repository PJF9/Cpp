#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <map>

#define SHOW_MEMORY_ERROR_TEXT std::cout << "[ERROR] Failed to allocate memory..." << std::endl; exit(0);
#define EXTEND_SIZE 9



std::map<std::string, int> cmap = {
    {"Black", 0},
    {"Blue", 1},
    {"Green", 2},
    {"Aqua", 3},
    {"Red", 4},
    {"Purple", 5},
    {"Yellow", 6},
    {"White", 7},
    {"Gray", 8},
    {"Light_Blue", 9},
    {"Light_Green", 10},
    {"Light_Aqua", 11},
    {"Light_Red", 12},
    {"Light_Purple", 13},
    {"Light_Yellow", 14},
    {"Bright_White", 15}
};

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void colour(std::string s);



class Point {
    private:
        int *point_tuple;
        int dim;
        int point_id;
        static int _points;

    public:
        Point();
        Point(const std::initializer_list<int> &li);
        Point(const std::vector<int> v);
        Point(int dim, int value=0);
        Point(const Point &p);
        ~Point();

        void set_point(const std::initializer_list<int> &li);
        void set_point(const std::vector<int> v);
        void set_point(int dim, int value);
        std::vector<int> get_point() const;
        inline int get_dim() const;
        inline int get_point_id() const;
        static inline int get_npoints();

        void add_dim(int value);
        void remove_dim(int n=1);

        Point operator+(const Point &p);
        Point operator-(const Point &p);
        int operator*(const Point &p);
        Point operator++(int obj);
        Point operator++();
        Point &operator=(const Point &p);
        int &operator[](int i);
        bool operator==(const Point &p);

        friend std::ostream &operator<<(std::ostream &out, const Point &p);
        friend std::istream &operator>>(std::istream &in, Point &p);
};


class Display {
    private:
        Point *points;
        int extended_size;
        int total_points;
        int max[2];

        static Point __get_2d(const Point &p);
        void __update_max();

    public:
        Display();
        Display(const std::initializer_list<Point> &li);
        Display(const std::vector<Point> &v);
        Display(const Display &d);
        ~Display();

        inline int get_max_x() const;
        inline int get_max_y() const;
        std::vector<int> get_max() const;
        inline int get_total_points() const;
        inline int get_extended_size() const;
        std::vector<Point> get_points() const;

        int find(const Point &p);
        void add_point(const Point &p);
        void remove_last();
        void remove_point(const Point &p);

        Display &operator=(const Display &d);

        friend std::ostream &operator<<(std::ostream &out, const Display &d);
};


class App {
    private:
        int **grid;
        int size_x;
        int size_y;
        static int n_apps;

    public:
        App();
        App(const Display &d);
        App(const App &a);
        ~App();

        bool find(Point p) const;
        void locate(const Display &d) const;
        void add_point(Point p);
        void remove_point(Point p);
        void new_display(const Display &d);

        friend std::ostream &operator<<(std::ostream &out, const App &a);
};



int Point::_points = 0;
int App::n_apps = 0;



int main_menu(const Display &d, const Display &locate_d, const App &a, bool from_locate);



int main() {
    Point p = {0, 0};
    Display d;
    Display locate_d;
    App a;

    int option;
    std::string points_str;
    bool from_locate = false;
    do {
        option = main_menu(d, locate_d, a, from_locate);
        from_locate = false;
    
        // Option 1: Add Points
        if (option == 1) {
            std::cout << "  *** Excellent! Give me the points you'd like to add - use the format (x1,y1)(x2,y2)...(xn,yn): ";
            std::cin >> points_str;

            int j = -1;
            for (int i=0; i<points_str.length(); i++) {
                if (i % 5 == 0 & i != 0) {
                    d.add_point(p);
                    j = -1;
                }
                if (j == 0) {
                    p[0] = points_str[i] - 48;
                }
                else if (j == 2) {
                    p[1] = points_str[i] - 48;
                }
                j++;
            }
            d.add_point(p);

            a.new_display(d);
        }

        // Option 2: Remove Points
        else if (option == 2) {
            std::cout << "  *** Alright! Give me the points you'd like to remove - use the format (x1,y1)(x2,y2)...(xn,yn): ";
            std::cin >> points_str;

            int j = -1;
            for (int i=0; i<points_str.length(); i++) {
                if (i % 5 == 0 & i != 0) {
                    d.remove_point(p);
                    j = -1;
                }
                if (j == 0) {
                    p[0] = points_str[i] - 48;
                }
                else if (j == 2) {
                    p[1] = points_str[i] - 48;
                }
                j++;
            }
            d.remove_point(p);

            a.new_display(d);
        }

        // Option 3: Find Points
        else if (option == 3) {
            locate_d = Display();
            from_locate = true;
            std::cout << "  *** Perfect! Give me the points you'd like to locate - use the format (x1,y1)(x2,y2)...(xn,yn): ";
            std::cin >> points_str;

            int j = -1;
            for (int i=0; i<points_str.length(); i++) {
                if (i % 5 == 0 & i != 0) {
                    locate_d.add_point(p);
                    j = -1;
                }
                if (j == 0) {
                    p[0] = points_str[i] - 48;
                }
                else if (j == 2) {
                    p[1] = points_str[i] - 48;
                }
                j++;
            }
            locate_d.add_point(p);
        }

    } while (option != 4);

    std::cout << std::endl;
    std::cout << "$ I hope you had a great adventure. Have a nice day!" << std::endl << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;

    return 0;
}



void colour(std::string s) {
   SetConsoleTextAttribute(h, cmap[s]);
}



int main_menu(const Display &d, const Display &locate_d, const App &a, bool from_locate) {
    int option;

    system("cls");
    std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
    colour ("Aqua"); std::cout << "                                                Welcome To PointoMania                                                " << std::endl; colour ("White");
    std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "--> Points: " << d << std::endl << std::endl;
    if (from_locate) {
        a.locate(locate_d);
    }
    else {
        std::cout << a << std::endl;
    }
    std::cout << "----------------------------------------------------------------------------------------------------------------------\n" << std::endl;

    std::cout << "$ What would you like to do?" << std::endl;
    std::cout << "   1. Add points" << std::endl;
    std::cout << "   2. Remove a point" << std::endl;
    std::cout << "   3. Find points" << std::endl;
    std::cout << "   4. Exit" << std::endl;

    std::cout << "\n$ Choose (1-4): ";
    std::cin >> option;

    while (option > 4 || option < 1) {
        std::cout << "$ You can only choose from 1-4. Try again: ";
        std::cin >> option;
        std::cout << std::endl;
    }

    return option;
}












Point::Point() {
    this->dim = 0;
    this->point_tuple = new(std::nothrow) int [0];
    if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    
    this->point_id = Point::_points++;
}


Point::Point(const std::initializer_list<int> &li) {
    this->dim = 0;
    this->point_tuple = new(std::nothrow) int [li.size()];
    if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (std::initializer_list<int>::iterator it=li.begin(); it!=li.end(); it++) {
        this->point_tuple[this->dim++] = *it;
    }

    this->point_id = Point::_points++;
}


Point::Point(const std::vector<int> v) {
    this->dim = 0;
    this->point_tuple = new(std::nothrow) int [v.size()];
    if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int el: v) {
        this->point_tuple[this->dim++] = el;
    }

    this->point_id = Point::_points++;
}


Point::Point(int dim, int value) {
    this->dim = 0;
    this->point_tuple = new(std::nothrow) int [dim];
    if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<dim; i++) {
        this->point_tuple[this->dim++] = value;
    }

    this->point_id = Point::_points++;
}


Point::Point(const Point &p) {
    this->dim = 0;
    this->point_tuple = new(std::nothrow) int [p.get_dim()];
    if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<p.get_dim(); i++) {
        this->point_tuple[this->dim++] = p.point_tuple[i];
    }

    this->point_id = Point::_points++;
}


Point::~Point() {
    delete [] this->point_tuple;

    Point::_points--;
}


void Point::set_point(const std::initializer_list<int> &li) {
    if (this->dim != li.size()) {
        delete [] this->point_tuple;
        this->point_tuple = new(std::nothrow) int [li.size()];
        if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    this->dim = 0;
    for (std::initializer_list<int>::iterator it=li.begin(); it!=li.end(); it++) {
        this->point_tuple[this->dim++] = *it;
    }
}


void Point::set_point(const std::vector<int> v) {
    if (this->dim != v.size()) {
        delete [] this->point_tuple;
        this->point_tuple = new(std::nothrow) int [v.size()];
        if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    this->dim=0;
    for (int el: v) {
        this->point_tuple[this->dim++] = el;
    }
}


void Point::set_point(int dim, int value) {
    if (this->dim != dim) {
        delete [] this->point_tuple;
        this->point_tuple = new(std::nothrow) int [dim];
        if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    this->dim = 0;
    for (int i=0; i<dim; i++) {
        this->point_tuple[this->dim++] = value;
    }
}


std::vector<int> Point::get_point() const {
    std::vector<int> point;

    for (int i=0; i<this->dim; i++) {
        point.push_back(this->point_tuple[i]);
    }

    return point;
}


inline int Point::get_dim() const {
    return this->dim;
}


inline int Point::get_point_id() const {
    return this->point_id;
}


inline int Point::get_npoints() {
    return Point::_points;
}


void Point::add_dim(int value) {
    std::vector<int> v = this->get_point();
    v.push_back(value);

    delete [] this->point_tuple;
    
    this->dim ++;
    this->point_tuple = new(std::nothrow) int [this->dim];
    if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->dim; i++) {
        this->point_tuple[i] = v[i];
    }
}


void Point::remove_dim(int n) {
    if (n < 0) {
        std::cout << "[ERROR] `n` cannot be negative..." << std::endl;
        throw -3;
    }

    std::vector<int> v = this->get_point();

    delete [] this->point_tuple;

    if (n > this->dim) {
        this->dim = 0;
        v.clear();
    }
    else {
        this->dim -= n;
        v.erase(v.end()-n-1, v.end());
    }
    
    this->point_tuple = new(std::nothrow) int [this->dim];
    if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->dim; i++) {
        this->point_tuple[i] = v[i];
    }
}


Point Point::operator+(const Point &p) {
    if (this->dim != p.get_dim()) {
        std::cout << "[ERROR] Point dimensions doesn't match..." << std::endl;
        throw -2;
        return Point();
    }

    std::vector<int> v = p.get_point();
    for (int i=0; i<v.size(); i++) {
        v[i] += this->point_tuple[i];
    }

    return Point(v);
}


Point Point::operator-(const Point &p) {
    if (this->dim != p.get_dim()) {
        std::cout << "[ERROR] Point dimensions doesn't match..." << std::endl;
        throw -2;
        return Point();
    }

    std::vector<int> v = p.get_point();
    for (int i=0; i<v.size(); i++) {
        v[i] -= this->point_tuple[i];
    }

    return Point(v);
}


int Point::operator*(const Point &p) {
    if (this->dim != p.get_dim()) {
        std::cout << "[ERROR] Point dimensions doesn't match..." << std::endl;
        throw -2;
        return -1;
    }

    int dotp = 0;
    for (int i=0; i<this->dim; i++) {
        dotp += (this->point_tuple[i] * p.point_tuple[i]);
    }
    
    return dotp;
}


Point Point::operator++(int obj) {
    Point p = *this;

    this->add_dim(0);

    return p;
}


Point Point::operator++() {
    this->add_dim(0);

    return *this;
}


Point &Point::operator=(const Point &p) {
    if (this == &p) {
        return *this;
    }

    delete [] this->point_tuple;

    this->dim = p.get_dim();
    this->point_tuple = new(std::nothrow) int [this->dim];
    if (!this->point_tuple) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->dim; i++) {
        this->point_tuple[i] = p.point_tuple[i];
    }

    return *this;
}


int &Point::operator[](int i) {
    if (i >= this->dim || i < 0) {
        std::cout << "[ERROR] Index out of range..." << std::endl;
        throw -4;
    }
    return this->point_tuple[i];
}


bool Point::operator==(const Point &p) {
    if (this->dim != p.dim) {
        return false;
    }

    for (int i=0; i<this->dim; i++) {
        if (this->point_tuple[i] != p.point_tuple[i]) {
            return false;
        }
    }

    return true;
}


std::ostream &operator<<(std::ostream &out, const Point &p) {
    out << p.dim << ": (";
    for (int i=0; i<p.dim; i++) {
        if (i == p.dim - 1) {
            out << p.point_tuple[i];
        }
        else {
            out << p.point_tuple[i] << ", ";
        }
    }
    out << ")";

    return out;
}


std::istream &operator>>(std::istream &in, Point &p) {
    int value;

    in >> value;

    p.add_dim(value);

    return in;
}












Point Display::__get_2d(const Point &p) {
    Point ret_p = p;

    if (p.get_dim() <= 2) {
        for (int i=0; i<2 - p.get_dim(); i++) {
            ret_p.add_dim(0);
        }
    }
    else {
        ret_p.remove_dim(p.get_dim() - 2);
    }

    return ret_p;
}


void Display::__update_max() {
    if (this->total_points == 0) {
        this->max[0] = 0;
        this->max[1] = 0;
    }
    else {
        int max_x = this->points[0][0];
        int max_y = this->points[0][1];

        for (int i=1; i<this->total_points; i++) {
            if (this->points[i][0] > max_x) {
                max_x = this->points[i][0];
            }
            if (this->points[i][1] > max_y) {
                max_y = this->points[i][1];
            }
        }
        this->max[0] = max_x;
        this->max[1] = max_y;
    }
}


Display::Display() {
    this->extended_size = EXTEND_SIZE;
    this->total_points = 0;
    Point max = {0, 0};

    this->points = new(std::nothrow) Point [EXTEND_SIZE];
    if (!this->points) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
}


Display::Display(const std::initializer_list<Point> &li) {
    this->total_points = 0;
    this->extended_size = li.size() + EXTEND_SIZE;
    this->points = new(std::nothrow) Point [this->extended_size];
    if (!this->points) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (std::initializer_list<Point>::iterator it=li.begin(); it!=li.end(); it++) {
        if (this->find(this->__get_2d(*it)) == -1) {
            this->points[this->total_points++] = this->__get_2d(*it);
        }
    }

    this->__update_max();
}


Display::Display(const std::vector<Point> &v) {
    this->total_points = 0;
    this->extended_size = v.size() + EXTEND_SIZE;
    this->points = new(std::nothrow) Point [this->extended_size];
    if (!this->points) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (Point p: v) {
        if (this->find(this->__get_2d(p)) == -1) {
            this->points[this->total_points++] = this->__get_2d(p);
        }
    }

    this->__update_max();
}


Display::Display(const Display &d) {
    this->total_points = 0;
    this->extended_size = d.get_total_points() + EXTEND_SIZE;
    this->points = new(std::nothrow) Point [this->extended_size];
    if (!this->points) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<d.get_total_points(); i++) {
        this->points[total_points++] = d.points[i];
    }

    this->__update_max();
}


Display::~Display() {
    delete [] this->points;
}


inline int Display::get_max_x() const {
    return this->max[0];
}


inline int Display::get_max_y() const {
    return this->max[1];
}


std::vector<int> Display::get_max() const {
    std::vector<int> v = {this->max[0], this->max[1]};

    return v;
}


inline int Display::get_total_points() const {
    return this->total_points;
}


inline int Display::get_extended_size() const {
    return this->extended_size;
}


std::vector<Point> Display::get_points() const {
    std::vector<Point> v;
    for (int i=0; i<this->total_points; i++) {
        v.push_back(this->points[i]);
    }

    return v;
}


int Display::find(const Point &p) {
    for (int i=0; i<this->total_points; i++) {
        if (this->points[i] == this->__get_2d(p)) {
            return i;
        }
    }

    return -1;
}


void Display::add_point(const Point &p) {
    if (this->find(p) != -1) {
        return;
    }

    if (this->total_points == this->extended_size) {
        this->total_points ++;
        this->extended_size = this->total_points + EXTEND_SIZE;

        Point *temp = new(std::nothrow) Point [this->total_points];
        if (!temp) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

        for (int i=0; i<this->total_points-1; i++) {
            temp[i] = this->points[i];
        }
        temp[total_points-1] = p;

        delete [] this->points;

        this->points = new(std::nothrow) Point [this->extended_size];
        if (!this->points) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

        for (int i=0; i<this->total_points; i++) {
            this->points[i] = temp[i];
        }

        delete [] temp;
    }
    else {
        this->total_points++;
        this->points[this->total_points-1] = p;
    }

    this->__update_max();
}


void Display::remove_last() {
    if (this->total_points == 0) {
        std::cout << "[ERROR] No points exists..." << std::endl;
        throw -4;
    }

    if (this->extended_size - this->total_points > EXTEND_SIZE) {
        this->total_points--;
        this->extended_size = this->total_points;

        Point *temp = new(std::nothrow) Point [this->total_points];
        if (!temp) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

        for (int i=0; i<this->total_points; i++) {
            temp[i] = this->points[i];
        }

        this->points[this->total_points].~Point();

        delete [] this->points;

        this->points = new(std::nothrow) Point [this->extended_size];
        if (!this->points) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

        for (int i=0; i<this->total_points; i++) {
            this->points[i] = temp[i];
        }

        delete [] temp;
    }
    else {
        this->total_points--;
        this->points[this->total_points].~Point();
    }

    this->__update_max();
}


void Display::remove_point(const Point &p) {
    int pos = this->find(p);

    if (pos != -1) {
        if (this->extended_size - this->total_points > EXTEND_SIZE) {
            this->total_points --;
            this->extended_size = this->total_points;

            Point *temp = new(std::nothrow) Point [this->total_points];
            if (!temp) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

            int j = 0;
            for (int i=0; i<this->total_points+1; i++) {
                if (i != pos) {
                    temp[j++] = this->points[i];
                }
            }

            this->points[pos].~Point();

            delete [] this->points;

            this->points = new(std::nothrow) Point [this->extended_size];
            if (!this->points) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

            for (int i=0; i<this->total_points; i++) {
                this->points[i] = temp[i];
            }

            delete [] temp;
        }
        else {
            this->total_points--;

            Point temp = this->points[pos];

            for (int i=pos; i<this->total_points; i++) {
                this->points[i] = this->points[i+1];
            }
            temp.~Point();
        }

        this->__update_max();
    }
}


Display &Display::operator=(const Display &d) {
    if (this == &d) {
        return *this;
    }

    for (int i=0; i<this->total_points; i++) {
        this->points[i].~Point();
    }
    delete [] this->points;

    this->total_points = d.get_total_points();
    this->extended_size = d.get_extended_size();
    this->points = new(std::nothrow) Point [this->extended_size];
    if (!this->points) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->total_points; i++) {
        this->points[i] = d.points[i];
    }

    return *this;
}


std::ostream &operator<<(std::ostream &out, const Display &d) {
    std::vector<Point> points = d.get_points();
    out << "{";
    for (int i=0; i<d.get_total_points(); i++) {
        if (i == d.get_total_points() - 1) {
            out << "(" << d.points[i][0] << ", " << d.points[i][1] << ")";
        }
        else {
            out << "(" << d.points[i][0] << ", " << d.points[i][1] << "), ";
        }
    }
    out << "}";

    return out;
}












App::App() {
    if (this->n_apps == 1) {
        std::cout << "[ERROR] Only one instance of `App` can be created..." << std::endl;
        throw -5;
    }

    this->size_x = 0;
    this->size_y = 0;

    this->grid = new(std::nothrow) int* [this->size_y];
    if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->size_y; i++) {
        this->grid[i] = new(std::nothrow) int [this->size_x];
        if (!this->grid[i]) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    this->n_apps ++;
}


App::App(const Display &d) {
    if (this->n_apps == 1) {
        std::cout << "[ERROR] Only one instance of `App` can be created..." << std::endl;
        throw -5;
    }

    this->size_x = d.get_max_x() + 1;
    this->size_y = d.get_max_y() + 1;

    this->grid = new(std::nothrow) int* [this->size_y];
    if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->size_y; i++) {
        this->grid[i] = new(std::nothrow) int [this->size_x];
        if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    for (int i=0; i<this->size_y; i++) {
        for (int j=0; j<this->size_x; j++) {
            this->grid[i][j] = 0;
        }
    }

    for (Point p: d.get_points()) {
        this->grid[this->size_y - p[1] - 1][p[0]] = 1;
    }

    this->n_apps ++;
}


App::App(const App &a) {
    if (this->n_apps == 1) {
        std::cout << "[ERROR] Only one instance of `App` can be created..." << std::endl;
        throw -5;
    }

    this->size_x = a.size_x;
    this->size_y = a.size_y;

    this->grid = new(std::nothrow) int* [this->size_y];
    if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->size_y; i++) {
        this->grid[i] = new(std::nothrow) int [this->size_x];
        if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    for (int i=0; i<this->size_y; i++) {
        for (int j=0; j<this->size_x; j++) {
            this->grid[i][j] = a.grid[i][j];
        }
    }
}


App::~App() {
    this->n_apps --;

    for (int i=0; i<this->size_y; i++) {
        delete [] this->grid[i];
    }

    delete [] this->grid;
}


bool App::find(Point p) const {
    if (p[0] < this->size_x && p[1] < this->size_y) {
        if (this->grid[this->size_y - 1 - p[1]][p[0]] == 1) {
            return true;
        }
    }

    return false;
}


void App::locate(const Display &d) const {
    std::string extra_space = "    ";

    if (this->size_x == 0 && this->size_y == 0) {
        std::cout << "  " << extra_space << " --- " << std::endl;
        std::cout << extra_space << "0 |   |" << std::endl;
        std::cout << "  " << extra_space << " --- " << std::endl;
        std::cout << " " << extra_space << "   0" << std::endl;

        return;
    }

    bool coloured_point = false;
    std::vector<Point> points = d.get_points();

    for (int i=0; i<this->size_y; i++) {
        std::cout << "  " << extra_space;
        for (int j=0; j<this->size_x; j++) {
            std::cout << " " << "---" << " ";
        }
        std::cout << std::endl;

        std::cout << extra_space << this->size_y-i-1 << " ";
        
        for (int j=0; j<this->size_x; j++) {
            coloured_point = false;
            if (this->grid[i][j] == 1) {
                for (Point p: points) {
                    if (p[0] == j && this->size_y - 1 - p[1] == i) {
                        coloured_point = true;
                        break;
                    }
                }
                if (coloured_point) {
                    std::cout << "|";
                    colour("Green");
                    std::cout << " * ";
                    colour("White");
                    std::cout << "|";
                }
                else {
                    std::cout << "|" << " * " << "|";
                }
            }
            else {
                std::cout << "|" << "   " << "|";
            }
        }
        std::cout << std::endl;
        std::cout << "  " << extra_space;
        for (int j=0; j<this->size_x; j++) {
            std::cout << " " << "---" << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "  " << extra_space;
    for (int i=0; i<this->size_x; i++) {
        std::cout << "  " << i << "  ";
    }
    std::cout << std::endl;
}


void App::add_point(Point p) {
    if (p[0] < this->size_x && p[1] < this->size_y) {
        this->grid[this->size_y -1 -p[1]][p[0]] = 1;
        return;
    }

    int old_x = this->size_x;
    int old_y = this->size_y;
    if (p[0] >= this->size_x) {
        this->size_x = p[0] + 1;
    }
    if (p[1] >= this->size_y) {
        this->size_y = p[1] + 1;
    }

    int **temp = new(std::nothrow) int* [this->size_y];
    if (!temp) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->size_y; i++) {
        temp[i] = new(std::nothrow) int [this->size_x];
        if (!temp) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    for (int i=0; i<this->size_y; i++) {
        for (int j=0; j<this->size_x; j++) {
            if (i < old_y && j < old_x) {
                temp[i][j] = this->grid[i][j];
            }
            else {
                temp[i][j] = 0;
            }
        }
    }
    temp[this->size_y - 1 - p[1]][p[0]] = 1;

    for (int i=0; i<old_y; i++) {
        delete [] this->grid[i];
    }
    delete [] this->grid;

    this->grid = new(std::nothrow) int* [this->size_y];
    if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->size_y; i++) {
        this->grid[i] = new(std::nothrow) int [this->size_x];
        if (!this->grid[i]) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    for (int i=0; i<this->size_y; i++) {
        for (int j=0; j<this->size_x; j++) {
            this->grid[i][j] = temp[i][j];
        }
    }

    for (int i=0; i<this->size_y; i++) {
        delete [] temp[i];
    }
    delete [] temp;
}


void App::remove_point(Point p) {
    if (!this->find(p)) {
        return;
    }

    if ((p[0] < this->size_x - 1) && (p[1] < this->size_y - 1)) {
        this->grid[this->size_y - 1 - p[1]][p[0]] = 0;
        return;
    }

    bool with_others_y = true;
    bool with_others_x = true;
    if (p[1] == this->size_y - 1) {
        for (int i=0; i<this->size_x; i++) {
            if ((i != p[0]) && (this->grid[this->size_y - 1 - p[1]][i] == 1)) {
                with_others_y = true;
                break;
            }
            with_others_y = false;
        }
    }
    if (p[0] == this->size_x - 1) {
        for (int i=0; i<this->size_y; i++) {
            if ((i != p[1]) && (this->grid[this->size_y - 1 - i][p[0]] == 1)) {
                with_others_x = true;
                break;
            }
            with_others_x = false;
        }
    }
    if (with_others_x && with_others_y) {
        this->grid[this->size_y - 1 - p[1]][p[0]] = 0;
            return;
    }

    int old_y = this->size_y;
    if (!with_others_y) {
        this->size_y --;
    }
    if (!with_others_x) {
        this->size_x --;
    }
    
    int **temp = new(std::nothrow) int* [this->size_y];
    if (!temp) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->size_y; i++) {
        temp[i] = new(std::nothrow) int [this->size_x];
        if (!temp) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    for (int i=0; i<this->size_y; i++) {
        for (int j=0; j<this->size_x; j++) {
            temp[this->size_y - 1 - i][j] = this->grid[old_y - 1 - i][j];
        }
    }

    for (int i=0; i<old_y; i++) {
        delete [] this->grid[i];
    }
    delete [] this->grid;

    this->grid = new(std::nothrow) int* [this->size_y];
    if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->size_y; i++) {
        this->grid[i] = new(std::nothrow) int [this->size_x];
        if (!this->grid[i]) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    for (int i=0; i<this->size_y; i++) {
        for (int j=0; j<this->size_x; j++) {
            this->grid[this->size_y - 1 - i][j] = temp[this->size_y - 1 - i][j];
        }
    }

    for (int i=0; i<this->size_y; i++) {
        delete [] temp[i];
    }
    delete [] temp;
}


void App::new_display(const Display &d) {
    for (int i=0; i<this->size_y; i++) {
        delete [] this->grid[i];
    }
    delete [] this->grid;

    this->size_x = d.get_max_x() + 1;
    this->size_y = d.get_max_y() + 1;

    this->grid = new(std::nothrow) int* [this->size_y];
    if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}

    for (int i=0; i<this->size_y; i++) {
        this->grid[i] = new(std::nothrow) int [this->size_x];
        if (!this->grid) {SHOW_MEMORY_ERROR_TEXT; throw -1;}
    }

    for (int i=0; i<this->size_y; i++) {
        for (int j=0; j<this->size_x; j++) {
            this->grid[i][j] = 0;
        }
    }

    for (Point p: d.get_points()) {
        this->grid[this->size_y - p[1] - 1][p[0]] = 1;
    }
}


std::ostream &operator<<(std::ostream &out, const App &a) {
    std::string extra_space = "    ";

    if (a.size_x == 0 && a.size_y == 0) {
        out << "  " << extra_space << " --- " << std::endl;
        out << extra_space << "0 |   |" << std::endl;
        out << "  " << extra_space << " --- " << std::endl;
        out << " " << extra_space << "   0" << std::endl;
    }
    else {
        for (int i=0; i<a.size_y; i++) {
            out << "  " << extra_space;
            for (int j=0; j<a.size_x; j++) {
                out << " " << "---" << " ";
            }
            out << std::endl;

            out << extra_space << a.size_y-i-1 << " ";
            
            for (int j=0; j<a.size_x; j++) {
                if (a.grid[i][j] == 1) {
                    out << "|" << " * " << "|";
                }
                else {
                    out << "|" << "   " << "|";
                }
            }
            out << std::endl;
            out << "  " << extra_space;
            for (int j=0; j<a.size_x; j++) {
                out << " " << "---" << " ";
            }
            out << std::endl;
        }
        out << "  " << extra_space;
        for (int i=0; i<a.size_x; i++) {
            out << "  " << i << "  ";
        }
        out << std::endl;
    }

    return out;
}
