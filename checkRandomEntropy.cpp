#include<iostream>
#include "monitor.hpp"
#include <thread>
#include <iomanip>
#include <chrono>

using namespace std;

int main(){
    cout << "Time\t\tEntropy" << endl;
    thread t1(useRandom, 128);
    thread t2(useRandom, 128);
    thread t3(useRandom, 128);
    thread t4(useRandom, 128);
    thread t5(useRandom, 128);
    try
    {
        while (true)
        {
            int entropyBefore = getEntropy();
            auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
            cout << put_time(localtime(&now), "%H:%M:%S") << "\t" << entropyBefore << endl;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}