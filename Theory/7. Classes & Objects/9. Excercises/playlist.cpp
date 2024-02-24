#include <iostream>
#include <string>

// Create the video class
class Video {
    private:
        // All the class members we need
        std::string atrist_name;
        std::string track_name;
        int duration; 

    public:
        // Get the duration
        int get_duration() {
            return duration;
        }

        // Set all the class members
        void set_video(std::string artist_name, std::string track_name, int duration) {
            this->atrist_name = artist_name;
            this->track_name = track_name;
            this->duration = duration;
        }
        
        // Overload the << operator
        friend std::ostream &operator<<(std::ostream &left, Video &v) {
            left << "Artist Name: " << v.atrist_name << std::endl;
            left << "Track Name: " << v.track_name << std::endl;
            left << "Track duration (sec): " << v.duration << std::endl;
            left << "------------------------------------------------------" << std::endl;
            
            return left;
        }
};

// Create the playlist class
class Playlist {
    protected:
        // All the class members we need
        std::string name;
        std::string details;
        int total_time;
        Video videos[100];
        int total_videos;

    public:
        // Creating the cunstructor
        Playlist(std::string name, std::string details) {
            this->name = name;
            this->details = details;
            this->total_time = 0;
            this->total_videos = 0;
        }

        // Add video method
        void add_video(Video in_video) {
            videos[total_videos] = in_video;
            total_videos ++;
            total_time += in_video.get_duration();
        }   

        // Overload the << operator
        friend std::ostream &operator<<(std::ostream &left, Playlist &p) {
            left << "Playlist Name: " << p.name << std::endl;
            left << "Playlist Details: " << p.details << std::endl;
            left << "Playlist Total Secs: " << p.total_time << "\n" << std::endl;
            
            for (int i=0; i<p.total_videos; i++) {
                left << p.videos[i];
            }

            return left;
        }
};

// Create the classical playlist class
class Classical_Playlist: public Playlist {
    private:
        // All the class members we want
        std::string period;

    public:
        // Create the cosntructor
        Classical_Playlist(std::string aName, std::string aDetails, std::string period): Playlist(aName, aDetails) {
            this->period = period;
        }

        // Overloading the << operator
        friend std::ostream &operator<<(std::ostream &left, Classical_Playlist &ob) {
            left << "Playlist Name: " << ob.name << std::endl;
            left << "Playlist Details: " << ob.details << std::endl;
            left << "Playlist Total Secs: " << ob.total_time << std::endl;
            left << "Playlist Period: " << ob.period << "\n" << std::endl;
            
            for (int i=0; i<ob.total_videos; i++) {
                left << ob.videos[i];
            }

            return left;
        }
};

int main() {
    Playlist playlist("Name", "No Name Only Details");
    Classical_Playlist classical_playlist("Classical Name", "No Classical Name Only Details", "Period");
    Video video_1, video_2;
    Video video_3, video_4;

    video_1.set_video("Artist Name", "Artist Song", 203);
    video_2.set_video("2", "2", 5);
    
    playlist.add_video(video_1);
    playlist.add_video(video_2);
    
    std::cout << playlist << std::endl;

    video_3.set_video("Name", "song", 200);
    video_4.set_video("N", "S", 200);

    classical_playlist.add_video(video_3);
    classical_playlist.add_video(video_4);

    std::cout << classical_playlist;
}