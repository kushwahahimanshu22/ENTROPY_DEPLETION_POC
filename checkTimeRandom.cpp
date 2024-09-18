#include<iostream>
#include "monitor.hpp"

using namespace std;

int main(){
    while(true){
        measure_generation_time("/dev/random", 16);
    }
    return 0;
}