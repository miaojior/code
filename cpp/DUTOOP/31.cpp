#include <iostream>

using std::cout; using std::endl; using std::cin;

class Joseph {
public:
    Joseph(int n, int m, int k) : n(n), m(m), k(k) {
        people = new int[n];
        for (int i = 0; i < n; ++i)
            people[i] = i + 1;
    }

    ~Joseph() {
        delete[] people;
    }

    void simulate() {
        bool* eliminated = new bool[n]();
        int remaining = n;
        //int index = k - 1;
        int index = k - 2;

        while (remaining > 0) {
            int count = 0;
            /*while (count < m) {
                if (!eliminated[index])
                    count++;
                if (count == m) 
                    break;
                index = (index + 1) % n;
            }*/
           while (count < m) {
                index = (index + 1) % n;
                if (!eliminated[index])
                    count++;
            }
            cout << people[index] << (remaining > 1 ? " " : "\n");
            eliminated[index] = true;
            remaining--;
            //while (eliminated[index]&&remaining) 
            //    index = (index + 1) % n;
        }
        delete[] eliminated;
    }

private:
    int n, m, k;
    int* people;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    Joseph joseph(n, m, k);
    joseph.simulate();

    return 0;
}
