#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int f;
    vector<int> result;
    map<int, int> hash;

    for (int i = 0; i < nums.size(); i++) {
        f = target - nums[i];
        if (hash.count(f) > 0) {
            result.push_back(hash[f]);
            result.push_back(i);
        }
        hash[nums[i]] = i;
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), res;
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }

    res = twoSum(a, 10);

    for(int i = 0; i< 2; i++){
        cout << res[i] << "\t";
    }

    return 0;
}
