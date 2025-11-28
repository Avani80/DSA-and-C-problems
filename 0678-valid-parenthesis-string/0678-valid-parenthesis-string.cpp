class Solution {
public:
    bool checkValidString(string s) {
        
        int low = 0;
        int high = 0;
        for (char c : s){
            if(c == '('){
                low ++;
                high++;
            }else if(c==')'){
                low -- ;
                high--;
            }else{
                low --; // * as )
                high++;// * as (
            }
            //if even the max posibility opening count is -ve we say invalid false
            if(high <0) return false;
            // low cannot be -ve,0
            if(low < 0) low = 0;
        }
        // min possible open count = zero, balance all
        return low == 0;
    }
};