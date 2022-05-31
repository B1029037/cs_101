#include <iostream>
#include <string>

using namespace std;

class Clock {
    private:
        int m_hr;
        int m_min;
        int m_sec;
        string m_AP;
    public:
        Clock(int hr, int min, int sec, string AP) {
            m_hr = hr;
            m_min = min;
            m_sec = sec;
            m_AP = AP;
        }
        void display() {
            cout << m_hr << ":" << m_min << ":";
            cout << m_sec << " " << m_AP << endl;
        }
        
};

class StandardClock : Clock {
};

class MilitaryClock : Clock {
};

int main() {
    Clock cc(10, 25, 43, "AM");
    cc.display();

    return 0;
}