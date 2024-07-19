#include<iostream>
using namespace std;

class Vector
{
    public:
        Vector(int s): elem{new double[s]}, sz{s}{}
        int size() { return sz; }
        double& operator[](int i) { return elem[i]; }
    private:
        double* elem;
        int sz;


};
int main()
{
    Vector v(7);
    cout << v[0] << endl;

}