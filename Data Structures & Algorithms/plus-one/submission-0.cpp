class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num = 0;
        int start = digits.size()-1;
        for(int i = start ; i >=0; i--  ){
            int mul = std::pow(10, start -i );
            cout<<mul<<endl;
            num+= mul* digits[i];
        }
        cout<<num;
        int numPlusOne = num +1;
        std::vector<int> res;
        while(numPlusOne != 0){
            res.push_back(numPlusOne % 10);
            numPlusOne /=10;
        }

        for(int i =0; i < res.size()/2; i++){
            std::swap(res[i], res[res.size()-1-i]);
        }
        return res;

    }
};
