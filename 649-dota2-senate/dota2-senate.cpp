class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQue, direQue;
        int n = senate.size();
        for(int i = 0;i<n;i++){
            if(senate[i] == 'R'){
                radiantQue.push(i);
            }else{
                direQue.push(i);
            }
        }
        while(!radiantQue.empty() && !direQue.empty()){
            int rVal,dVal;
            rVal = radiantQue.front();
            dVal = direQue.front();
            radiantQue.pop();
            direQue.pop();
            if(rVal < dVal){
                radiantQue.push(rVal + n); //offset
            }else{
                direQue.push(dVal + n); //offset
            }
        }
        if(!radiantQue.empty()) return "Radiant";
        return "Dire";

    }
};