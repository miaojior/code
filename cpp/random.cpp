#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(70, 20);

    bool valid = false;
    std::vector<int> nums;
    while (!valid) {
        nums.clear();
        for (int i = 0; i < 20; i++) {
            int num;
            do {
                num = static_cast<int>(dist(gen));
            } while (num < 0 || num >= 100);
            nums.push_back(num);
        }
        bool has_below_60 = false;
        bool has_above_85 = false;
        for (int num : nums) {
            if (num < 60) has_below_60 = true;
            if (num >= 85) has_above_85 = true;
        }
        valid = has_below_60&&has_above_85;
    }

    std::cout << "Random numbers:" << std::endl;
    std::vector<int> idx(20);
    std::iota(idx.begin(), idx.end(), 1);
    std::shuffle(idx.begin(), idx.end(), gen);
    for (int i = 0; i < 20; i++) {
        std::cout << idx[i] << " " << nums[i] << std::endl;
    }

    return 0;
}