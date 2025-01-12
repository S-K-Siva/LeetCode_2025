// 200/258 Testcases Passed

// import java.util.*;

// class Solution {
//     public boolean canBeValid(String s, String locked) {
//         Stack<Map.Entry<Character,Integer>> st = new Stack<>();
//         int n = locked.length();
//         if(n <= 1) return false;
//         for(int i = 0;i<n;i++){
//             Map.Entry<Character,Integer> pair = Map.entry(s.charAt(i),i);
//             char currentLock = locked.charAt(pair.getValue());
//             char currentKey = pair.getKey();
//             if(st.empty()){
//                 if(currentLock == '1' && currentKey == ')') return false;
//                 st.push(pair);
//             }else{
//                 Map.Entry<Character,Integer> top = st.peek();
//                 char peekLock = locked.charAt(top.getValue());
//                 char peekKey = top.getKey();
                
//                 if(currentKey == '('){
//                     if(peekKey == ')'){
//                         st.pop();
//                     }else{
//                         if(peekKey == ')' && peekLock == '0'){
//                             st.pop();
//                         }else{
//                             st.push(pair);
//                         }
//                     }
//                 }else if(currentKey == ')'){
//                     if(peekKey == '('){
//                         st.pop();
//                     }else{
//                         if(peekKey == ')' && peekLock == '0'){
//                             st.pop();
//                         }else{
//                             st.push(pair);
//                         }
//                     }
//                 }
//             }
//         }

//         return st.empty();
//     }
// }

import java.util.*;

class Solution {
    public boolean solve(String s, String locked, boolean isFromBack) {
        
        int unlockedCount = 0;
        int n = s.length();
        int i = isFromBack ? n - 1 : 0;
        
        while (isFromBack ? i >= 0 : i < n) {
            if(locked.charAt(i) == '0' || ((!isFromBack && s.charAt(i) == '(') || (isFromBack && s.charAt(i) == ')'))){
                unlockedCount++;
            }else{
                unlockedCount--;
            }
            if(unlockedCount < 0){
                return false;
            }
            i += isFromBack ? -1 : 1;
        }
        
        return true;
    }
    
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if (n % 2 == 1) return false; 
        return solve(s, locked, false) && solve(s, locked, true);
    }
}