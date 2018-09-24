#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "semaphore.h"

bool readyA = false;
bool readyB = false;

void tarefaA(Semaphore &s1, Semaphore &s2) {

    std::cout << "Faz trabalho A" << std::endl;
    s1.acquire();
    s2.release();
    
    
// DESEJO ESPERAR POR B AQUI!
    std::cout << "Fim trabalho A" << std::endl;
}

void tarefaB(Semaphore &s1, Semaphore &s2) {

    std::cout << "Faz trabalho B" << std::endl;
    s2.acquire();
    s1.release();
// DESEJO ESPERAR POR A AQUI!
    std::cout << "Fim trabalho B" << std::endl;
}

int main(int argc, char *argv[]) {
    Semaphore s1(1);
    Semaphore s2(1);
    std::thread t1(tarefaA, std::ref(s1), std::ref(s2));
    std::thread t2(tarefaB, std::ref(s1), std::ref(s2));
    
    
    t1.join();
    t2.join();
    return 0;
}
