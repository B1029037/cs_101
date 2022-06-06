#include <iostream>
#include <string>

using namespace std;

class Clock {
    private:
        
    public:
        int m_hr;
        int m_min;
        int m_sec;
        string m_AP;
        Clock(int hr, int min, int sec, string AP) {
            m_hr = hr;
            m_min = min;
            m_sec = sec;
            string m_AP = AP;
        }
        void display() {
            cout << m_hr << ":" << m_min << ":";
            cout << m_sec << " ";
            if (m_AP == "AM") {
                cout << "AM" << endl;
            } else {
                cout << "PM" << endl;
            }
        }      
};

class StandardClock : Clock {
    private:

    public:
        StandardClock(int hr, int min, int sec, string AP)
            : Clock(hr, min, sec, AP) {
        }
        void display() {
            if (m_AP == "AM") {
                cout << "上午 ";
            } else {
                cout << "下午 ";
            }
            cout << m_hr << ":" << m_min << ":";
            cout << m_sec << endl;
        }    
};

class MilitaryClock : Clock {
    private:

    public:
        MilitaryClock(int hr, int min, int sec, string AP)
            : Clock(hr, min, sec, AP) {
        }
        void display() {
            if (m_AP == "AM") {
                cout << m_hr;
            } else {
                cout << m_hr+12;
            }
            cout << ":" << m_min << ":";
            cout << m_sec << endl;
        }
};

int main() {
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "AM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
