#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "boost/filesystem.hpp" 
#include <utility>

using namespace boost::filesystem;

int main(int argc, char **argv) {
    long counter;
    std::string dir;
    std::string substring;
    std::string diretorio;
    
    // std::cout << "diretorio: " << std::endl;
    // std::cin >> dir;
    std::cout << "palavra: " << std::endl;
    std::cin >> substring;
    std::cout << "diretorio: " << std::endl;
    std::cin >> diretorio;
    path p("./");

    #pragma omp parallel
    {
        #pragma omp master
        {
            for (auto &entry : directory_iterator(p)) {
                if (is_regular_file(entry.path())) {
                    #pragma omp task firstprivate (entry)
                    {
                        std::vector<std::pair <std::string, long>> task_list;
                        std::string str;

                        std::ifstream fs(entry.path().string());
                        counter = 0;
                        while (std::getline(fs, str)) {
                            if (str.find(substring) != std::string::npos) {
                                task_list.push_back(std::make_pair(entry.path().string(), counter));
                                // std::cout << entry.path().string() << ":" << counter << std::endl;
                            }   
                            counter += 1;
                        }

                        #pragma omp critical 
                        {
                            for (int i=0; i<task_list.size(); i++){
                                printf("%s : %lu\n", task_list[i].first.c_str(), task_list[i].second);
                            }
                        }
                        
                    }
                }                
            }
        }
    }
    
    return 0;
}
