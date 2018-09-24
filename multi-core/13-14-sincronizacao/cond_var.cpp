#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <mutex>
#include <ctime>
#include <ratio>

typedef std::chrono::high_resolution_clock Time;


std::mutex A, B;
std::condition_variable cA, cB;
bool readyA = false;
bool readyB = false;

void thread0(int &resultado_para_thread1) {

    {
        std::unique_lock<std::mutex> lk (A);
        // faz trabalho longo

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        
        resultado_para_thread1 = 10;
        readyA = true;
        cA.notify_all();
    }
    // faz trabalho longo
    std::this_thread::sleep_for(std::chrono::milliseconds(1300));
    std::cout << "Fim thread0!" << std::endl;
}

void thread1(int const &resultado_da_thread0, int &resultado_para_thread2) {
    {    
        std::unique_lock<std::mutex> lk (A);
        cA.wait(lk, []{return readyA;});
   }
   {
        std::unique_lock<std::mutex> lk (B);
        // faz trabalho long com resultado de thread0
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        
        // finja que isto depende da thread0
        resultado_para_thread2 = 20; 

        readyB = true;
        cB.notify_one();
   }
    std::cout << "Fim thread1!" << std::endl;
}

void thread2(int const &resultado_thread_0, int const &resultado_thread_1) {
    {
        std::unique_lock<std::mutex> lk (A);
        cA.wait(lk, []{return readyA;});
    }
    // faz trabalho longo com resultado de thread0
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    
    {
        std::unique_lock<std::mutex> lk (B);
        cB.wait(lk, []{return readyB;});

        // faz trabalho longo com resultado de thread1
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
   
    std::cout << "thread2:" << resultado_thread_0 + resultado_thread_1 << "\n";
    std::cout << "Fim thread2!" << std::endl;
}

int main(int argc, char **argv) {
    int res_t0, res_t1;

    auto start = Time::now();

    std::thread t0 (thread0, std::ref (res_t0));
    std::thread t1 (thread1, std::ref (res_t0), std::ref (res_t1));
    std::thread t2 (thread2, std::ref (res_t0), std::ref (res_t1));

    auto end = Time::now();
    std::chrono::duration<double> diff = end-start;

    t0.join();
    t1.join();
    t2.join();

    std::cout << "Time: " << diff.count() << std::endl;
    return 0;
}
