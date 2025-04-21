class StockSpanner {
public:
    stack<pair<int,int>> st;
    int counter = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int maxDays = 1;
      
        while(!st.empty() && st.top().first <= price){
            maxDays += st.top().second;
            st.pop();
        }
        st.push({price, maxDays});
        return maxDays;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */