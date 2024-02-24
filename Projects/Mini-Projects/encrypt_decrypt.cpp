#include <iostream>
#include <vector>
#include <string>


//! Alphabet
class Alphabet {
    public:
        std::string space = "000000";
        std::string comma = "000011";
        std::string ex_mark = "000101";
        std::string a = "000110";
        std::string b = "001001";
        std::string c = "001010";
        std::string d = "001100";
        std::string e = "001111";
        std::string f = "010001";
        std::string g = "010010";
        std::string h = "010100";
        std::string i = "010111";
        std::string j = "011000";
        std::string k = "011011";
        std::string l = "011101";
        std::string m = "011110";
        std::string n = "100001";
        std::string o = "100010";
        std::string p = "100100";
        std::string q = "100111";
        std::string r = "101000";
        std::string s = "101011";
        std::string t = "101101";
        std::string u = "101110";
        std::string v = "110000";
        std::string w = "110011";
        std::string x = "110101";
        std::string y = "110110";
        std::string z = "111001";
        std::string qu_mark = "111100";
        std::string full_stop = "111111";

        std::string zero = "000001";
        std::string eins = "000010";
        std::string zwei = "000100";
        std::string drei = "000111";
        std::string vier = "001000";
        std::string funf = "001011";
        std::string sechs = "001101";
        std::string sieben = "001110";
        std::string acht = "010000";
        std::string neun = "010011";

        std::string duck = "010101";
        std::string diesh = "010110";
        std::string dollar = "011001";
        std::string modulo = "011010";
        std::string to_the_pow = "011100";
        std::string and_char = "011111";
        std::string mult = "100000";
        std::string open_par = "100011";
        std::string close_par = "100101";
        std::string minus = "100110"; 
        std::string low_underscore = "101001";
        std::string plus = "101010";
        std::string equal = "101100";
        std::string for_slash = "101111";
        std::string semi_column = "110001";
        std::string opern_bracket = "110010";
        std::string close_bracket = "110100";
        std::string open_dict = "110111";
        std::string close_dict = "111000";
        std::string left_ear = "111101";
        std::string right_ear = "111110";
        std::string column = "111010";
        std::string single_quots = "111011";
};  

//! Ecnrypting Class
class Encrypt: public Alphabet {
    private:
        std::vector <std::string> letters_vector;
        std::string encrypted_message;
    public:

        std::string encrypt_message(std::string aUser_message) {
            for (int index=0; index<aUser_message.length(); index++) {
                if (aUser_message[index] == '1') {
                    letters_vector.push_back(eins);
                } else if (aUser_message[index] == '2') {
                    letters_vector.push_back(zwei);
                } else if (aUser_message[index] == '3') {
                    letters_vector.push_back(drei);
                } else if (aUser_message[index] == '4') {
                    letters_vector.push_back(vier);
                } else if (aUser_message[index] == '5') {
                    letters_vector.push_back(funf);
                } else if (aUser_message[index] == '6') {
                    letters_vector.push_back(sechs);
                } else if (aUser_message[index] == '7') {
                    letters_vector.push_back(sieben);
                } else if (aUser_message[index] == '8') {
                    letters_vector.push_back(acht);
                } else if (aUser_message[index] == '9') {
                    letters_vector.push_back(neun);
                } else if (aUser_message[index] == '0') {
                    letters_vector.push_back(zero);
                } else if (aUser_message[index] == 'a' || aUser_message[index] == 'A') {
                    letters_vector.push_back(a);
                } else if (aUser_message[index] == 'b' || aUser_message[index] == 'B') {
                    letters_vector.push_back(b);
                } else if (aUser_message[index] == 'c' || aUser_message[index] == 'C') {
                    letters_vector.push_back(c);
                } else if (aUser_message[index] == 'd' || aUser_message[index] == 'D') {
                    letters_vector.push_back(d);
                } else if (aUser_message[index] == 'e' || aUser_message[index] == 'E') {
                    letters_vector.push_back(e);
                } else if (aUser_message[index] == 'f' || aUser_message[index] == 'F') {
                    letters_vector.push_back(f);
                } else if (aUser_message[index] == 'g' || aUser_message[index] == 'G') {
                    letters_vector.push_back(g);
                } else if (aUser_message[index] == 'h' || aUser_message[index] == 'H') {
                    letters_vector.push_back(h);
                } else if (aUser_message[index] == 'i' || aUser_message[index] == 'I') {
                    letters_vector.push_back(i);
                } else if (aUser_message[index] == 'j' || aUser_message[index] == 'J') {
                    letters_vector.push_back(j);
                } else if (aUser_message[index] == 'k' || aUser_message[index] == 'K') {
                    letters_vector.push_back(k);
                } else if (aUser_message[index] == 'l' || aUser_message[index] == 'L') {
                    letters_vector.push_back(l);
                } else if (aUser_message[index] == 'm' || aUser_message[index] == 'M') {
                    letters_vector.push_back(m);
                } else if (aUser_message[index] == 'n' || aUser_message[index] == 'N') {
                    letters_vector.push_back(n);
                } else if (aUser_message[index] == 'o' || aUser_message[index] == 'O') {
                    letters_vector.push_back(o);
                } else if (aUser_message[index] == 'p' || aUser_message[index] == 'P') {
                    letters_vector.push_back(p);
                } else if (aUser_message[index] == 'q' || aUser_message[index] == 'Q') {
                    letters_vector.push_back(q);
                } else if (aUser_message[index] == 'r' || aUser_message[index] == 'R') {
                    letters_vector.push_back(r);
                } else if (aUser_message[index] == 'x' || aUser_message[index] == 'S') {
                    letters_vector.push_back(s);
                } else if (aUser_message[index] == 't' || aUser_message[index] == 'T') {
                    letters_vector.push_back(t);
                } else if (aUser_message[index] == 'u' || aUser_message[index] == 'U') {
                    letters_vector.push_back(u);
                } else if (aUser_message[index] == 'v' || aUser_message[index] == 'V') {
                    letters_vector.push_back(v);
                } else if (aUser_message[index] == 'w' || aUser_message[index] == 'W') {
                    letters_vector.push_back(w);
                } else if (aUser_message[index] == 'x' || aUser_message[index] == 'X') {
                    letters_vector.push_back(x);
                } else if (aUser_message[index] == 'y' || aUser_message[index] == 'Y') {
                    letters_vector.push_back(y);
                } else if (aUser_message[index] == 'z' || aUser_message[index] == 'Z') {
                    letters_vector.push_back(z);
                } else if (aUser_message[index] == ',') {
                    letters_vector.push_back(comma);
                } else if (aUser_message[index] == '!') {
                    letters_vector.push_back(ex_mark);
                } else if (aUser_message[index] == '?') {
                    letters_vector.push_back(qu_mark);
                } else if (aUser_message[index] == '.') {
                    letters_vector.push_back(full_stop);
                } else if (aUser_message[index] == ' ') {
                    letters_vector.push_back(space);
                } else if (aUser_message[index] == '@') {
                    letters_vector.push_back(duck);
                } else if (aUser_message[index] == '#') {
                    letters_vector.push_back(diesh);
                } else if (aUser_message[index] == '$') {
                    letters_vector.push_back(dollar);
                } else if (aUser_message[index] == '%') {
                    letters_vector.push_back(modulo);
                } else if (aUser_message[index] == '^') {
                    letters_vector.push_back(to_the_pow);
                } else if (aUser_message[index] == '&') {
                    letters_vector.push_back(and_char);
                } else if (aUser_message[index] == '*') {
                    letters_vector.push_back(mult);
                } else if (aUser_message[index] == '(') {
                    letters_vector.push_back(open_par);
                } else if (aUser_message[index] == ')') {
                    letters_vector.push_back(close_par);
                } else if (aUser_message[index] == '-') {
                    letters_vector.push_back(minus);
                } else if (aUser_message[index] == '_') {
                    letters_vector.push_back(low_underscore);
                } else if (aUser_message[index] == '+') {
                    letters_vector.push_back(plus);
                } else if (aUser_message[index] == '=') {
                    letters_vector.push_back(equal);
                } else if (aUser_message[index] == '/') {
                    letters_vector.push_back(for_slash);
                } else if (aUser_message[index] == ';') {
                    letters_vector.push_back(semi_column);
                } else if (aUser_message[index] == '[') {
                    letters_vector.push_back(opern_bracket);
                } else if (aUser_message[index] == ']') {
                    letters_vector.push_back(close_bracket);
                } else if (aUser_message[index] == '{') {
                    letters_vector.push_back(open_dict);
                } else if (aUser_message[index] == '}') {
                    letters_vector.push_back(close_dict);
                } else if (aUser_message[index] == '<') {
                    letters_vector.push_back(left_ear);
                } else if (aUser_message[index] == '>') {
                    letters_vector.push_back(right_ear);
                } else if (aUser_message[index] == ':') {
                    letters_vector.push_back(column);
                } else if (aUser_message[index] == '\'') {
                    letters_vector.push_back(single_quots);
                } 
            }

            for (int index=0; index<letters_vector.size(); index++) {
                encrypted_message += letters_vector[index];
            }

            return encrypted_message;
        }
};

//! Decrypt Class
class Decrypt: public Alphabet {
    private:
        std::vector <std::string> from_binary_vector;
        std::string decrypted_message;
    public:

        std::string decrypt_message(std::string aUser_message) {
            for (int index=0; index<aUser_message.length(); index++) {
                if (index % 6 == 0) {
                    if (aUser_message.substr(index, 6) == eins) {
                        from_binary_vector.push_back("1");
                    } else if (aUser_message.substr(index, 6) == zwei) {
                        from_binary_vector.push_back("2");
                    } else if (aUser_message.substr(index, 6) == drei) {
                        from_binary_vector.push_back("3");
                    } else if (aUser_message.substr(index, 6) == drei) {
                        from_binary_vector.push_back("4");
                    } else if (aUser_message.substr(index, 6) == funf) {
                        from_binary_vector.push_back("5");
                    } else if (aUser_message.substr(index, 6) == sechs) {
                        from_binary_vector.push_back("6");
                    } else if (aUser_message.substr(index, 6) == sieben) {
                        from_binary_vector.push_back("7");
                    } else if (aUser_message.substr(index, 6) == acht) {
                        from_binary_vector.push_back("8");
                    } else if (aUser_message.substr(index, 6) == neun) {
                        from_binary_vector.push_back("9");
                    } else if (aUser_message.substr(index, 6) == zero) {
                        from_binary_vector.push_back("0");
                    } else if (aUser_message.substr(index, 6) == a) {
                        from_binary_vector.push_back("a");
                    } else if (aUser_message.substr(index, 6) == b) {
                        from_binary_vector.push_back("b");
                    } else if (aUser_message.substr(index, 6) == c) {
                        from_binary_vector.push_back("c");
                    } else if (aUser_message.substr(index, 6) == d) {
                        from_binary_vector.push_back("d");
                    } else if (aUser_message.substr(index, 6) == e) {
                        from_binary_vector.push_back("e");
                    } else if (aUser_message.substr(index, 6) == f) {
                        from_binary_vector.push_back("f");
                    } else if (aUser_message.substr(index, 6) == g) {
                        from_binary_vector.push_back("g");
                    } else if (aUser_message.substr(index, 6) == h) {
                        from_binary_vector.push_back("h");
                    } else if (aUser_message.substr(index, 6) == i) {
                        from_binary_vector.push_back("i");
                    } else if (aUser_message.substr(index, 6) == j) {
                        from_binary_vector.push_back("j");
                    } else if (aUser_message.substr(index, 6) == k) {
                        from_binary_vector.push_back("k");
                    } else if (aUser_message.substr(index, 6) == l) {
                        from_binary_vector.push_back("l");
                    } else if (aUser_message.substr(index, 6) == m) {
                        from_binary_vector.push_back("m");
                    } else if (aUser_message.substr(index, 6) == n) {
                        from_binary_vector.push_back("n");
                    } else if (aUser_message.substr(index, 6) == o) {
                        from_binary_vector.push_back("o");
                    } else if (aUser_message.substr(index, 6) == p) {
                        from_binary_vector.push_back("p");
                    } else if (aUser_message.substr(index, 6) == q) {
                        from_binary_vector.push_back("q");
                    } else if (aUser_message.substr(index, 6) == r) {
                        from_binary_vector.push_back("r");
                    } else if (aUser_message.substr(index, 6) == s) {
                        from_binary_vector.push_back("s");
                    } else if (aUser_message.substr(index, 6) == t) {
                        from_binary_vector.push_back("t");
                    } else if (aUser_message.substr(index, 6) == u) {
                        from_binary_vector.push_back("u");
                    } else if (aUser_message.substr(index, 6) == v) {
                        from_binary_vector.push_back("v");
                    } else if (aUser_message.substr(index, 6) == w) {
                        from_binary_vector.push_back("w");
                    } else if (aUser_message.substr(index, 6) == x) {
                        from_binary_vector.push_back("x");
                    } else if (aUser_message.substr(index, 6) == y) {
                        from_binary_vector.push_back("y");
                    } else if (aUser_message.substr(index, 6) == z) {
                        from_binary_vector.push_back("z");
                    } else if (aUser_message.substr(index, 6) == comma) {
                        from_binary_vector.push_back(",");
                    } else if (aUser_message.substr(index, 6) == ex_mark) {
                        from_binary_vector.push_back("!");
                    } else if (aUser_message.substr(index, 6) == qu_mark) {
                        from_binary_vector.push_back("?");
                    } else if (aUser_message.substr(index, 6) == full_stop) {
                        from_binary_vector.push_back(".");
                    } else if (aUser_message.substr(index, 6) == space) {
                        from_binary_vector.push_back(" ");
                    } else if (aUser_message.substr(index, 6) == diesh) {
                        from_binary_vector.push_back("#");
                    } else if (aUser_message.substr(index, 6) == duck) {
                        from_binary_vector.push_back("@");
                    } else if (aUser_message.substr(index, 6) == dollar) {
                        from_binary_vector.push_back("$");
                    } else if (aUser_message.substr(index, 6) == modulo) {
                        from_binary_vector.push_back("%");
                    } else if (aUser_message.substr(index, 6) == to_the_pow) {
                        from_binary_vector.push_back("^");
                    } else if (aUser_message.substr(index, 6) == and_char) {
                        from_binary_vector.push_back("&");
                    } else if (aUser_message.substr(index, 6) == mult) {
                        from_binary_vector.push_back("*");
                    } else if (aUser_message.substr(index, 6) == open_par) {
                        from_binary_vector.push_back("(");
                    } else if (aUser_message.substr(index, 6) == close_par) {
                        from_binary_vector.push_back(")");
                    } else if (aUser_message.substr(index, 6) == minus) {
                        from_binary_vector.push_back("-");
                    } else if (aUser_message.substr(index, 6) == low_underscore) {
                        from_binary_vector.push_back("_");
                    } else if (aUser_message.substr(index, 6) == plus) {
                        from_binary_vector.push_back("+");
                    } else if (aUser_message.substr(index, 6) == equal) {
                        from_binary_vector.push_back("=");
                    } else if (aUser_message.substr(index, 6) == for_slash) {
                        from_binary_vector.push_back("/");
                    } else if (aUser_message.substr(index, 6) == opern_bracket) {
                        from_binary_vector.push_back("[");
                    } else if (aUser_message.substr(index, 6) == close_bracket) {
                        from_binary_vector.push_back("]");
                    } else if (aUser_message.substr(index, 6) == open_dict) {
                        from_binary_vector.push_back("{");
                    } else if (aUser_message.substr(index, 6) == close_dict) {
                        from_binary_vector.push_back("}");
                    } else if (aUser_message.substr(index, 6) == left_ear) {
                        from_binary_vector.push_back("<");
                    } else if (aUser_message.substr(index, 6) == right_ear) {
                        from_binary_vector.push_back(">");
                    } else if (aUser_message.substr(index, 6) == semi_column) {
                        from_binary_vector.push_back(";");
                    } else if (aUser_message.substr(index, 6) == column) {
                        from_binary_vector.push_back(":");
                    } else if (aUser_message.substr(index, 6) == single_quots) {
                        from_binary_vector.push_back("\'");
                    }
                }
            }

            for (int index=0; index<from_binary_vector.size(); index++) {
                decrypted_message += from_binary_vector[index];
            }
            
            return decrypted_message;
        } 

};

//! App Class
class App: Decrypt, Encrypt {
    private:
        // All the class members we nedd
        int choice; //* The user choices
        char char_choice; //*
        std::string decrypted_text; //* To store the decrypted message
        std::string encrypted_text; //* To store the encrypted message
        std::string user_text; //* To store the message that the user is passing
        std::string personal_key = "petros"; //* With this key we can decrypt the message
    public:

    //? First Function
    void set_user_text() {
        // Get the message that the user want to work with
        std::cout << "Insert the text you want to encrypt or decrypt: ";
        std::getline(std::cin, user_text);
        std::cout << "--------------------------------------------------------------" << std::endl;
    }

    //? Second Function
    void menu_image() {
        // Creating the menu picture
        system("cls");
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "         Welcome to the best encryption app    " << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "         ~ Menu ~                   ^_^_^_^    " << std::endl; 
        std::cout << "                                   /  O O  \\  " << std::endl;
        std::cout << "         1. Encrypt the message   /| . | . |\\ " << std::endl;
        std::cout << "         2. Decrypt the message  /  \\_-_-_/  \\" << std::endl;
        std::cout << "         3. Exit                      | |      " << std::endl;
        std::cout << "                                      - -      " << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
    }

    //? Third Function
    std::string ask_personal_key() {
        std::string user_input;

        std::cout << "Enter key: ";
        getline(std::cin, user_input);

        return user_input;
    }

    //? Finall Function
    void start() {
        std::string user_key = ask_personal_key();

        if (personal_key != user_key) {
            std::cout << "\nThe key you enter is not the wanted key..." << std::endl;
            std::cout << "Exitting program..." << std::endl;
            exit(0);
        }
        // Call all the important methods of all these classes and produce the finall output
        menu_image();
        set_user_text();

        do {
            std::cout << "Enter Action: ";
            std::cin >> choice;
            std::cout << "--------------------------------------------------------------" << std::endl;

            if (choice > 3 || choice < 1) {
                std::cout << "Only options are 1,2 and 3" << std::endl;
                std::cout << std::endl;
            }

        } while (choice > 3 || choice < 1);

        if (choice == 1) {
            if (user_text[0] == '0' || user_text[0] == '1') {
                std::cout << "This program is encrypting normal text to binary..." << std::endl;
            } else {
                encrypted_text = encrypt_message(user_text);
                std::cout << "Your message has been encrypted succesfully..." << std::endl;
                std::cout << "--------------------------------------------------------------" << std::endl;
                
                do {
                    std::cout << "Want to see the encrypted message? ( y=yes/n=no ): ";
                    std::cin >> char_choice;
                    std::cout << std::endl;

                    if (char_choice != 'y' && char_choice != 'n') {
                        std::cout << "Only options are ( y=yes/ n=no )" << std::endl;
                        std::cout <<  "--------------------------------------------------------------" << std::endl;
                    }

                } while (char_choice != 'y' && char_choice != 'n');

                if (char_choice == 'n') {
                    std::cout << "Ok, exiting program..." << std::endl; 
                } else {
                    std::cout << "Encrypted message: " << encrypted_text << std::endl;
                }
            }

        } else if (choice == 2) {
            if (user_text[0] == '0' || user_text[0] == '1') {
                decrypted_text = decrypt_message(user_text);
                std::cout << "Your message has been decrypted succesffully..." << std::endl;
                std::cout << "--------------------------------------------------------------" << std::endl;

                do {
                    std::cout << "Want to see the decrypted message? ( y=yes/n=no ): ";
                    std::cin >> char_choice;
                    std::cout << std::endl;

                    if (char_choice != 'y' && char_choice != 'n') {
                        std::cout << "Only options are ( y=yes/ n=no )" << std::endl;
                        std::cout <<  "--------------------------------------------------------------" << std::endl;
                    }

                } while (char_choice != 'y' && char_choice != 'n');

                if (char_choice == 'n') {
                    std::cout << "Ok, exiting program..." << std::endl; 
                } else {
                    std::cout << "Decrypted message: " << decrypted_text << std::endl;
                }

            } else {
                std::cout << "This program is decrypting binary text to normal..." << std::endl;
            }

        } else {
            std::cout << "\nOk, exiting program..." << std::endl;
        }
    }
};


int main() {
    system("cls");

    App a;
    a.start();
}
