#include <iostream>
#include <algorithm>
using std::cin; using std::cout; using std::endl;

class DataSet {
private:
    int size;
    int* data;
    int* count;

public:
    DataSet(int n);
    ~DataSet();
    void read();
    void compress();
    bool isEqual(DataSet& other);
    void print();
};

int main() {
    int size1, size2;
    std::cin >> size1;
    DataSet set1(size1);
    set1.read();

    std::cin >> size2;
    DataSet set2(size2);
    set2.read();

    if (set1.isEqual(set2))
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;
    set1.print();

    return 0;
}

DataSet::DataSet(int n) : size(n){
    data = new int[n];
    count = new int[n];
    std::fill(count, count + n, 1);
}

DataSet::~DataSet(){
    delete[] data;
    delete[] count;
}

void DataSet::read(){
    for (int i = 0; i < size; ++i)
        std::cin >> data[i];
    std::sort(data, data + size);
    compress();
}

void DataSet::compress(){
    int uniqueCount = 0;
    for (int i = 0; i < size; ++i){
        if (i == 0 || data[i] != data[i - 1]){
            data[uniqueCount] = data[i];
            count[uniqueCount] = 1;
            ++uniqueCount;
        }else 
            ++count[uniqueCount - 1];
    }
    size = uniqueCount;
}

bool DataSet::isEqual(DataSet& other){
    if (size != other.size)
        return false;
    for (int i = 0; i < size; ++i)
        if (data[i] != other.data[i] || count[i] != other.count[i])
            return false;
    return true;
}

void DataSet::print(){
    for (int i = 0; i < size; ++i)
        std::cout << data[i] << " " << count[i] << std::endl;
}