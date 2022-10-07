class MyCalendarThree {
    private:
    deque<int>startPoints;
    deque<int>endPoints;
public:
    MyCalendarThree() {
    
    }
    
    int book(int start, int end) {
      // Insert starting and ending points in deque
        startPoints.push_front(start);
        endPoints.push_front(end);
        
     // Sort After insertion new elements
        insertionSort(startPoints);
        insertionSort(endPoints);

    // Now find common intersection 
        int i=0;
        int j=0;
        int n=startPoints.size();
        int ans=INT_MIN;
        while(i<n)
        {
            while(startPoints[i]>=endPoints[j])
                j++;
            ans=max(ans,i+1-j);  
            i++;
        }
        return ans;
    }
    void insertionSort(deque<int>&v)
    {   int j=0;
        for(int i=1;i<v.size()&&v[j]>v[i];i++)
            swap(v[j++],v[i]);
        
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */