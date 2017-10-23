/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
Credits:
Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        
        if (nums1.empty() || nums2.empty() || k <= 0) return result;
        
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> heap(comp);
        
        heap.emplace(0,0);
        while (k-- && !heap.empty()) {
            auto p = heap.top(); heap.pop();
            result.emplace_back(nums1[p.first], nums2[p.second]);
            if (p.first+1 < nums1.size())
                heap.emplace(p.first+1, p.second);
            
            // both (i,j) and (i-1,j+1) can generate (i,j+1), so we just choose x or y to add, 
            // when i = 0, there is no j+1
            if (p.first == 0 && p.second+1 < nums2.size())
                heap.emplace(p.first, p.second+1);
        }
        return result;
    }
};
