class MyCalendarTwo {
public:
    map<int,int> mt;
    MyCalendarTwo() {
        mt.clear();
    }
    
    bool book(int start, int end) {
        mt[start]++;
        mt[end]--;

        int bookings = 0;
        for(auto [time, count]: mt){
            bookings+=count;
            
            if(bookings > 2){
                mt[start]--;
                mt[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */