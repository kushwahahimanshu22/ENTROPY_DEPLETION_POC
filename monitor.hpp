#ifndef MONITOR
#define MONITOR

#include <vector>
#include <fstream>
#include <chrono>

int getEntropy(){
    std::ifstream entFile("/proc/sys/kernel/random/entropy_avail");
    int entropy = 0;
    if(entFile.is_open()){
        entFile >> entropy;
        entFile.close();
    }
    return entropy;
}

void useRandom(int bytes){
    std::ifstream randFile("/dev/random", std::ios::binary);
    if(randFile.is_open()){
        std::vector<char> buffer(bytes);
        randFile.read(buffer.data(), bytes);
        randFile.close();
    }
}

void useURandom(int bytes){
    std::ifstream randFile("/dev/urandom", std::ios::binary);
    if(randFile.is_open()){
        std::vector<char> buffer(bytes);
        randFile.read(buffer.data(), bytes);
        randFile.close();
    }
}

void measure_generation_time(const std::string& source, size_t num_bytes) {
    std::ifstream file(source, std::ios::binary);
    if (!file) {
        return;
    }
    std::vector<char> buffer(num_bytes);
    auto start = std::chrono::high_resolution_clock::now();
    file.read(buffer.data(), num_bytes);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time to generate " << num_bytes * 8 << "-bit random number from " << source 
              << ": " << elapsed.count() << " seconds" << std::endl;
}

#endif