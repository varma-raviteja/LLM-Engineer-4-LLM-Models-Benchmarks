
#include <iostream>
#include <iomanip>
#include <chrono>

double calculate(int iterations, int param1, int param2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        int j1 = i * param1 - param2;
        result -= (1.0 / j1);
        int j2 = i * param1 + param2;
        result += (1.0 / j2);
    }
    return result;
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    double result = calculate(100000000, 4, 1) * 4;
    auto end_time = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Result: " << result << std::endl;
    std::cout << "Execution Time: " << elapsed_seconds.count() << " seconds" << std::endl;

    return 0;
}
