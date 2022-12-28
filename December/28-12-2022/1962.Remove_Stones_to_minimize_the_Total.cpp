/*
    You just need to greedily do the operation to largest piles
    in order to get the least total
    
    Heap is the best DS to access the largest value in O(1) time
    So use max-heap
	
	Time complexity : O((k+n)*log(n))
*/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = accumulate(begin(piles), end(piles), 0);
        
        priority_queue<int> pq(begin(piles), end(piles)); //O(nlog(n))
		//But note that there is a way to construct Heap from array in O(n)
        
        while(!pq.empty() && k--) { //O(klog(n))
            int curr = pq.top();
            pq.pop();
            
            sum     -= floor(curr/2);
            curr    -= floor(curr/2);
            
            pq.push(curr);
        }
        
        return sum;
    }
};