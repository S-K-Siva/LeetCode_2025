class Robot {
public:
    int i,j,n,m;
    char ch = 'E';
    Robot(int width, int height) {
        i = height-1;
        j = 0;
        n = height;
        m = width;
    }
    
    void step(int num) {
        if (m == 1 && n == 1) return;

        int cycle = 2 * (m + n) - 4;
        num %= cycle;

        // 🔥 Important fix for full cycle
        if (num == 0) {
            if (i == n-1 && j == 0) ch = 'S';
            else if (i == n-1 && j == m-1) ch = 'E';
            else if (i == 0 && j == m-1) ch = 'N';
            else if (i == 0 && j == 0) ch = 'W';
            return;
        }
        while(num){
            if(ch == 'E'){
                while(ch == 'E' && num && j<m-1){
                    j++;
                    num--;
                }
                if(num){
                    ch = 'N';
                }
            }
            else if(ch == 'N'){
                while(ch == 'N' && num && i>0){
                    i--;
                    num--;
                }
                if(num){
                    ch = 'W';
                }
            }else if(ch == 'W'){
                while(ch == 'W' && num && j>0){
                    j--;
                    num--;
                }
                if(num){
                    ch = 'S';
                }
            }else if(ch == 'S'){
                while(ch == 'S' && num && i < n-1){
                    i++;
                    num--;
                }
                if(num){
                    ch = 'E';
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {j,n-i-1};
    }
    
    string getDir() {
        string res = "";
        switch(ch){
            case 'E':
                res = "East";
                break;
            case 'N':
                res = "North";
                break;
            case 'W':
                res = "West";
                break;
            case 'S':
                res = "South";
                break;
            default:
                res = "East";
                break;

        }
        return res;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */