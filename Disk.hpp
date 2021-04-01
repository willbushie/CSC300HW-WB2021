#include <string>

class Disk
{
    private:
        int size;
        Disk* nextDisk;

    public:
        Disk(int size);
        int getSize();
        Disk* getNextDisk();
        void setNextDisk(Disk* n);
        std::string toString();
};