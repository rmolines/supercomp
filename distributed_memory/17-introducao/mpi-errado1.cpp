#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <iostream>
#include <vector>
#include <random>
#include "math.h"
#include <climits>
#include <boost/serialization/vector.hpp>

namespace mpi = boost::mpi;
using namespace std;

int main(int argc, char* argv[]) {
    mpi::environment env(argc, argv);
    mpi::communicator world;
    vector<int> rand_vec;
    
    if (world.rank() == 0){
        std::mt19937 rng(1);        
        std::uniform_int_distribution<int> uni(0,1000);
        vector<mpi::request> reqs;
        vector<mpi::request> reqs2;

        int big[world.size()-1];
        int biggest = INT_MIN;

        for (int i=0; i<world.size()*50; i++){
            int temp = uni(rng);
            rand_vec.push_back(temp);
        }
        vector<int>::const_iterator first = rand_vec.begin();

        for (int i=1; i<world.size(); i++){
            first = rand_vec.begin()+((i-1)*50);
            vector<int>::const_iterator last = rand_vec.begin()+(i*50);
            reqs.push_back(world.isend(i, 0, vector<int> (first, last)));
        }
        
        mpi::wait_all(reqs.begin(), reqs.end());

        for (int i=1; i<world.size(); i++){
            reqs2.push_back(world.irecv(i, 1, big[i-1]));
        }
        mpi::wait_all(reqs2.begin(), reqs2.end());
        for (int i=0; i<world.size()-1; i++){
            cout << big[i] << endl;
            if (big[i] > biggest){
                biggest = big[i];
            }
        }

        cout << biggest << endl;


    }
    else {
        vector<int> data;
        world.recv(0, 0, data);
        int biggest = data[0];

        for (int i=1; i<data.size(); i++){
            if (data[i] > biggest){
                biggest = data[i];
            }
        }
        world.send(0, 1, biggest);
    }   
    
    
    return 0;
}
