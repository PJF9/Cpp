#include <iostream>


void print_array(std::string array[5][11]) {
    for (int i=0; i<5; i++) {
        for (int j=0; j<11; j++) {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string layout[5][11] = {
        {" ", "1", " ", "|", " ", "2", " ", "|", " " ,"3", " "},
        {"-", "-", "-", "|", "-", "-", "-", "|", "-", "-", "-"},
        {" ", "4", " ", "|", " ", "5", " ", "|", " ", "6", " "},
        {"-", "-", "-", "|", "-", "-", "-", "|", "-", "-", "-"},
        {" ", "7", " ", "|", " ", "8", " ", "|", " ", "9", " "}
    };  
    
    int col_size = sizeof(layout) / sizeof(std::string) / 5;
    int row_size = sizeof(layout) / sizeof(std::string) / 11;

    bool game = true;
    bool is_x = true;
    bool has_1 = false;
    bool has_2 = false;
    bool has_3 = false;
    bool has_4 = false;
    bool has_5 = false;
    bool has_6 = false;
    bool has_7 = false;
    bool has_8 = false;
    bool has_9 = false;

    int moves = 1;

    while (game) {
        system("cls");
        int choice;

        print_array(layout);

        std::cout << "Play: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (!has_1) {
                    if (is_x) {
                        layout[0][1] = "x";
                        is_x = false;
                        has_1 = true;
                    } else {
                        layout[0][1] = "o";
                        is_x = true;
                        has_1 = true;
                    }
                    break;
                } else {
                    break;
                }
            
            case 2:
                if (!has_2) {
                    if (is_x) {
                        layout[0][5] = "x";
                        is_x = false;
                        has_2 = true;
                    } else {
                        layout[0][5] = "o";
                        is_x = true;
                        has_2 = true;
                    }
                    break;
                } else {
                    break;
                }
            
            case 3:
                if (!has_3) {
                    if (is_x) {
                        layout[0][9] = "x";
                        is_x = false;
                        has_3 = true;
                    } else {
                        layout[0][9] = "o";
                        is_x = true;
                        has_3 = true;
                    }
                    break;
                } else {
                    break;
                }

            case 4:
                if (!has_4) {
                    if (is_x) {
                        layout[2][1] = "x";
                        is_x = false;
                        has_4 = true;
                    } else {
                        layout[2][1] = "o";
                        is_x = true;
                        has_4 = true;
                    }
                    break;
                } else {
                    break;
                }
            
            case 5:
                if (!has_5) {
                    if (is_x) {
                        layout[2][5] = "x";
                        is_x = false;
                        has_5 = true;
                    } else {
                        layout[2][5] = "o";
                        is_x = true;
                        has_5 = true;
                    }
                    break;
                } else {
                    break;
                }

            case 6:
                if (!has_6) {
                    if (is_x) {
                        layout[2][9] = "x";
                        is_x = false;
                        has_6 = true;
                    } else {
                        layout[2][9] = "o";
                        is_x = true;
                        has_6 = true;
                    }
                    break;
                } else {
                    break;
                }

            case 7:
                if (!has_7) {
                    if (is_x) {
                        layout[4][1] = "x";
                        is_x = false;
                        has_7 = true;
                    } else {
                        layout[4][1] = "o";
                        is_x = true;
                        has_7 = true;
                    }
                    break;
                } else {
                    break;
                }
            
            case 8:
                if (!has_8) {
                    if (is_x) {
                        layout[4][5] = "x";
                        is_x = false;
                        has_8 = true;
                    } else {
                        layout[4][5] = "o";
                        is_x = true;
                        has_8 = true;
                    }
                    break;
                } else {
                    break;
                }
            
            case 9:
                if (!has_9) {
                    if (is_x) {
                        layout[4][9] = "x";
                        is_x = false;
                        has_9 = true;
                    } else {
                        layout[4][9] = "o";
                        is_x = true;
                        has_9 = true;
                    }
                    break;
                } else {
                    break;
                }
        }   

        if (layout[0][1] == "x" && layout[0][5] == "x" && layout[0][9] == "x") {
            system("cls");
            std::cout << "Player1 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][1] == "o" && layout[0][5] == "o" && layout[0][9] == "o") {
            system("cls");
            std::cout << "Player2 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }

        if (layout[2][1] == "x" && layout[2][5] == "x" && layout[2][9] == "x") {
            system("cls");
            std::cout << "Player1 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[2][1] == "o" && layout[2][5] == "o" && layout[2][9] == "o") {
            system("cls");
            std::cout << "Player2 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }

        if (layout[4][1] == "x" && layout[4][5] == "x" && layout[4][9] == "x") {
            system("cls");
            std::cout << "Player1 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[4][1] == "o" && layout[4][5] == "o" && layout[4][9] == "o") {
            system("cls");
            std::cout << "Player2 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][1] == "x" && layout[2][1] == "x" && layout[4][1] == "x") {
            system("cls");
            std::cout << "Player1 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][1] == "o" && layout[2][1] == "o" && layout[4][1] == "o") {
            system("cls");
            std::cout << "Player2 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }

        if (layout[0][5] == "x" && layout[2][5] == "x" && layout[4][5] == "x") {
            system("cls");
            std::cout << "Player1 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][5] == "o" && layout[2][5] == "o" && layout[4][5] == "o") {
            system("cls");
            std::cout << "Player2 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }

        if (layout[0][9] == "x" && layout[2][9] == "x" && layout[4][9] == "x") {
            system("cls");
            std::cout << "Player1 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][9] == "o" && layout[2][9] == "o" && layout[4][9] == "o") {
            system("cls");
            std::cout << "Player2 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][1] == "x" && layout[2][5] == "x" && layout[4][9] == "x") {
            system("cls");
            std::cout << "Player1 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][1] == "o" && layout[2][5] == "o" && layout[4][9] == "o") {
            system("cls");
            std::cout << "Player2 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][9] == "x" && layout[2][5] == "x" && layout[4][1] == "x") {
            system("cls");
            std::cout << "Player1 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }
        if (layout[0][9] == "o" && layout[2][5] == "o" && layout[4][1] == "o") {
            system("cls");
            std::cout << "Player2 Won\n" << std::endl;
            
            game = false;

            print_array(layout);
        }

        if (moves == 9) {
            system("cls");
            std::cout << "Equal Game\n" << std::endl;

            game = false;

            print_array(layout);
        }

        moves++;
    }
}
