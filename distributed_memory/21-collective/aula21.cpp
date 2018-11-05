#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <iostream>
#include <vector>
#include <random>
#include "math.h"
#include <climits>
#include <boost/serialization/vector.hpp>
#include <boost/mpi/collectives.hpp>

namespace mpi = boost::mpi;
using namespace std;


int compute_biggest(int *vec, int size){
    int biggest = INT_MIN;
    for (int i=0; i<size; i++){
        if (vec[i] > biggest){
            biggest = vec[i];
        }
    }
    return biggest;
}

int main(int argc, char* argv[]) {
    mpi::environment env(argc, argv);
    mpi::communicator world;
    vector<int> rand_vec;
    vector<int> sub_rand_vec;
    int elements_per_proc = 50;
    vector<int> sizes;
    vector<int> sizes2;
    vector<int> big_vec;
    
    if (world.rank() == 0){
        std::mt19937 rng(1);        
        std::uniform_int_distribution<int> uni(0,1000);

        for (int i=0; i<world.size()*elements_per_proc; i++){
            int temp = uni(rng);
            rand_vec.push_back(temp);
        }
    }
    for (int i=0; i<world.size();i++){
        sizes.push_back(elements_per_proc);
    }

    int *sub_rand = NULL;
    sub_rand = (int * ) malloc(sizeof(int) * elements_per_proc);

    mpi::scatterv(world, rand_vec, sizes, sub_rand, 0);

    int biggest = compute_biggest(sub_rand, elements_per_proc);
    cout << biggest << endl;
    mpi::gather(world, biggest, big_vec, 0);

    if (world.rank() == 0){
        int biggest = INT_MIN;
        for (int i=0;i<world.size();i++){
            if (big_vec[i]>biggest){
                biggest = big_vec[i];
            }
        }
        cout << biggest << endl;
    }
    return 0;
}
