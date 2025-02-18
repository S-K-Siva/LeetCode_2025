class ProductOfNumbers {
public:
    vector<int> res;
    
    ProductOfNumbers() { 
    }
    
    void add(int num) {
        res.push_back(num);
    }
    
    int getProduct(int k) {
        if (k > res.size()) return 0;

        int result = 1;
        for (int i = res.size() - 1; i >= (int)(res.size() - k); i--) {
            result *= res[i];
        }
        return result;
    }
};