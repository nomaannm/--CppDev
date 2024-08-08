#include <algorithm>
#include <iostream>
#include <vector>

class CompareDescending {
public:
    bool operator()(int a, int b) const {
        return a>b;
    }
};


int main() {
    std::vector<int> nums = {1,2,3,4,5,6};

    std::sort(nums.begin(), nums.end(), CompareDescending());

    for(auto num : nums) {
        std::cout << num << ",";
    }
}