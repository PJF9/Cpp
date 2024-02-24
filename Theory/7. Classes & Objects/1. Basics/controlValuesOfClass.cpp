#include <iostream>

using namespace std;

class Movie {
    // Private means that we have access to this sector only inside the class
    private:
        string rating;
    public:
        string name;
        string director;
        Movie(string aName, string aDirectory, string aRating) {
            name = aName;
            director = aDirectory;
            rating = aRating;
        }
        // Create the limitation function
        void setRating(string Rating) {
            if (Rating == "G" || Rating == "PG" || Rating == "NR") {
                rating = Rating;
            } else {
                rating = "Invalid Rating";
            }
        }
        // Returning the rating
        string getRating() {
            return rating;
        }
};


int main() {
    Movie avengers("The Avengers", "Joss Whedon", "NR");

    // Printing the rating
    cout << avengers.getRating() << endl;

    // Setting new rating
    avengers.setRating("Cat");
    cout << avengers.getRating() << endl;
}