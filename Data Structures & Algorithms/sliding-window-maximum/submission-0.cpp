class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
    std::deque<int> dq; // Stores indices of elements

    for (int right = 0; right < nums.size(); right++) {
        // 1. MAINTAIN DECREASING ORDER:
        // Remove smaller elements from the back because they can never be the maximum
        while (!dq.empty() && nums[dq.back()] < nums[right]) {
            dq.pop_back();
        }

        // 2. Add current element's index to the back of the deque
        dq.push_back(right);

        // 3. FIXED-SIZE SHRINKING LOGIC:
        // If the element at the front of the deque has fallen out of the left boundary 
        // of our current window (size k), remove it.
        int left_boundary = right - k + 1;
        if (dq.front() < left_boundary) {
            dq.pop_front();
        }

        // 4. COLLECT RESULT:
        // Once our window reaches size k for the first time, start recording the maximum
        if (right >= k - 1) {
            result.push_back(nums[dq.front()]); // The front is always the max element
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> res = maxSlidingWindow(nums, k);
    
    // Output: 3 3 5 5 6 7
    for (int val : res) std::cout << val << " "; 
    return 0;
    }
};
