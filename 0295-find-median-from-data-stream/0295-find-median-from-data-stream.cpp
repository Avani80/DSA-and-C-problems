class MedianFinder {
public:
priority_queue<int>left_maxheap;
priority_queue<int, vector<int>, greater<int>> right_minheap;
   // MedianFinder() {
        
    //}
    
    void addNum(int num) {
      if(left_maxheap .empty() || num < left_maxheap.top()){
        left_maxheap.push(num);
      }else{
        right_minheap.push(num);
      }
      // 2no ka size equal ho vrna left ma 1 jada hoga right sa
      if(abs((int)left_maxheap.size() - (int)right_minheap.size()) > 1)
      //2no ma size ka - 1 ho y 0 use jada toh glt ha 
      {
      right_minheap.push(left_maxheap.top());
      left_maxheap.pop();
    } 
    else if(left_maxheap.size() < right_minheap.size()){
        left_maxheap.push(right_minheap.top());
        right_minheap.pop();

    }
    }
    double findMedian() {
        //even no honge
        if(left_maxheap.size() == right_minheap.size()){
        return (double)(left_maxheap.top()+ right_minheap.top())/2;
    
    }
    
        //odd num honge
        return left_maxheap.top();
}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */