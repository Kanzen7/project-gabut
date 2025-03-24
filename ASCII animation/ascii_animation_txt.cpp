#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

void moveCursorTopLeft() {
    cout << "\033[H";
}

vector<string> loadFramesFromFile(const string &filename) {
    ifstream file(filename);
    vector<string> frames;
    if (!file.is_open()) {
        cerr << "Failed to open " << filename << endl;
        return frames;
    }

    string line, frame;
    while (getline(file, line)) {
        if (line == "---") {
            frames.push_back(frame);
            frame.clear();
        } else {
            frame += line + "\n";
        }
    }

    if (!frame.empty()) {
        frames.push_back(frame);
    }

    return frames;
}

int main() {
    vector<string> frames = loadFramesFromFile("ascii-animation-spt.txt");

    if (frames.empty()) {
        cout << "No frames found!" << endl;
        return 1;
    }

    while (true) {
        for (auto &frame : frames) {
            moveCursorTopLeft();
            cout << frame << flush;
            this_thread::sleep_for(chrono::milliseconds(80));
        }
    }

    return 0;
}
