#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex A, B;
condition_variable cA, cB;
bool readyA = false;
bool readyB = false;

void tarefaA() {

    std::cout << "Faz trabalho A" << std::endl;
    {
        std::unique_lock<std::mutex> lk(A);
        readyA = true;
        cA.notify_one();
    }
    {
        std::unique_lock<std::mutex> lk(B);
        cB.wait(lk, []{return readyB;});
    }
    
// DESEJO ESPERAR POR B AQUI!
    std::cout << "Fim trabalho A" << std::endl;
}

void tarefaB() {

    std::cout << "Faz trabalho B" << std::endl;
    {
        std::unique_lock<std::mutex> lk(B);
        readyB = true;
        cB.notify_one();
    }
    {
        std::unique_lock<std::mutex> lk(A);
        cA.wait(lk, []{return readyA;});
    }
// DESEJO ESPERAR POR A AQUI!
    std::cout << "Fim trabalho B" << std::endl;
}

int main(int argc, char *argv[]) {
    std::thread t1(tarefaA);
    std::thread t2(tarefaB);
    
    
    t1.join();
    t2.join();
    return 0;
}
