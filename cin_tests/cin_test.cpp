#include <iostream>
#include <vector>


using namespace std;

class consumer{
    public:
        vector<int> values;
    consumer():values(5)
    {
    }
    int get(void)
    {
        cin >> values[0] >> values[1];
        cout << values[0] << " : " << values[1] << endl;
    }
};




int main (void)
{
    consumer *c = new consumer();

    cout << "Element copied : " << c->get() << endl;
    return 0;
}
