#include <thread>
#include <iostream>
#include <vector>
#include <mutex>


void funcao_rodando_em_paralelo(int id_, std::mutex &mtx) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "id=" << id_ << std::endl;
}

int main() {
    std::mutex mtx;

    std::vector<std::thread> t;
    for (int i=0; i<4; i++){
        t.push_back(std::thread (funcao_rodando_em_paralelo, i, std::ref(mtx)));
    }

    for (int i=0; i<4; i++){
        t[i].join();
    }

}