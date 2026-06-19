class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> output(gain.size()+1,0);
        int answer =0;

        int maxAltitude =0;
        for (int i = 0 ;i < gain.size(); i++) {
            output[i+1] = output[i] + gain[i];
            
        }
            for(int i=1;i<output.size();i++){
                if(output[i]>answer){
                    answer = output[i];
                }
            }
            return answer;
        

    }
};