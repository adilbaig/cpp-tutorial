#include <memory>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <string>
#include <iostream>

inline static const std::string SHM_NAME = "/tmp1234";

class SharedMemoryDetacher
{
    public:
        void operator () (int* p) {
            std::cout << "unlink " << SHM_NAME << std::endl;
            if (shm_unlink(SHM_NAME.c_str()) != 0) {
                std::cerr << "unlink failed!" << std::endl;
            }
        }
};

std::shared_ptr<int> getSharedIntMemory(int num) {
    void* mem;
    int shmfd = shm_open(SHM_NAME.c_str(), O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
    if(shmfd < 0) {
        throw std::string(strerror(errno));
    }

    if (ftruncate(shmfd, num * sizeof(int)) == -1) {
        throw std::string(strerror(errno));
    }

    mem = mmap(nullptr, num*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (mem == MAP_FAILED) {
        throw std::string(strerror(errno));
    }

    return std::shared_ptr<int>(static_cast<int*>(mem), SharedMemoryDetacher());
}

int main()
{
    // attach 100 ints
    std::shared_ptr<int> smp(getSharedIntMemory(100));

    //init the shared mem
    for (int i=0; i<100; ++i) {
        smp.get()[i] = i*42;
    }

    std::cout << "<return>" << std::endl;
    std::cin.get();

    smp.reset();
}