class RecentCounter {
public:
    int counter;
    queue<int> que;
    RecentCounter() {
        counter = 0;
    }
    
    int ping(int t) {
        que.push(t);
        while(!que.empty() && que.front() < t-3000){
            que.pop();
        }
        return que.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */