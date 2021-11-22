#include <vector>
#include <math.h>

class Random
{
    private:
        std::vector<double> numberList;
        double max = RAND_MAX, min = 0;
        void fillVect();
        void shuffle();
        int count = 0;
        static Random *rInstance;
    public:

        // Constructors
        Random();
        Random(double min, double max);
        Random(int seed);

        // Functions
        int nextInt();
        double nextDbl();
        void setRange(double min, double max);

        // Extra Functions
        void printVect();
        static Random *Instance();
};