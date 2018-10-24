#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
namespace mpi = boost::mpi;

int main(int argc, char *argv[]) {
    boost::mpi::environment env{argc, argv};
    boost::mpi::communicator world;
    
    if (world.rank() == 0) {
        mpi::request reqs[2];
        std::string s[2];
        reqs[0] = world.irecv(1, 10, s[0]);
        reqs[1] = world.irecv(2, 20, s[1]);
        
        for (int i=0; i<2; i++){
            int it = std::get<1>(boost::mpi::wait_any(reqs, reqs+1)-reqs);
            cout << s[it] << std::endl;
            reqs[it];
        }

    } else if (world.rank() == 1) {
        std::string s = "Hello, world!";
        sleep(2);
        world.send(0, 10, s);
        std::cout << "Fim rank 1 " << std::endl;
    } else if (world.rank() == 2) {
        std::string s = "Hello, moon!";
        sleep(1);
        world.send(0, 20, s); 
        std::cout << "Fim rank 2 " << std::endl;
    }
}
