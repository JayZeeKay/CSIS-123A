#ifndef FRACTION
#define FRACTION

using std::istream;
using std::ostream;

class Fraction
{
    private:
        int *num;
        int *den;
    public:
        void create();
        void setFraction(int n, int d);
        Fraction add(const Fraction &f);
        Fraction sub(const Fraction &f);
        Fraction mul(const Fraction &f);
        Fraction div(const Fraction &f);

        int getNum() const;
        int getDen() const;

        void printFraction();
        std::string getFraction();

        // Constructors

        Fraction();
        Fraction(int num, int den); 
        Fraction(std::string fraction);
        Fraction(const Fraction &f);

        ~Fraction();

        // Operator Overloads

        Fraction operator +(const Fraction &f);
        Fraction operator -(const Fraction &f);
        Fraction operator /(const Fraction &f);
        Fraction operator *(const Fraction &f);
        Fraction &operator =(const Fraction &f);

        // Friend Functions

        friend istream &operator >>(istream &input, Fraction &f);
        friend ostream &operator <<(ostream &output, Fraction &f);

        static int count;
        static void printCount();
};

#endif