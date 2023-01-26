bool isValid(string s) {
        stack<int> st;
        for(char x : s) {
            if(x == '(' || x == '[' || x == '{') {
                st.push(x);
            }
            else{
                if(st.empty()) return false;
                if(x==')' && st.top()!='(') return false;
                if(x==']' && st.top()!='[') return false;
                if(x=='}' && st.top()!='{') return false;
                st.pop();
            }
        }
        if(st.empty()==true){
            return true;
        }
        else {
            return false;
        }
    }



    //minimum number of swaps to make strings balanced

    int minSwaps(string str) {
        string unpurified = "";
        for(int i=0; i<str.size(); i++) {
            if(str[i] == '[') {
                unpurified.push_back('[');
            }
            else {
                if(!unpurified.empty() && unpurified.back() == '[') {
                    unpurified.pop_back();
                }
                else {
                    unpurified.push_back(str[i]);
                }
            }
        }
        cout<<unpurified << "\n";
        int open = unpurified.size()/2;
        return ((open+1)/2);
    }



    //Merge intervals

    bool doesIntervalsOverlap(vector<int>& a, vector<int>& b) {
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }

     vector<int> mergeIntervals(vector<int>& a, vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    vector<vector<int>> merge(vector<vector<int>>& inv) {
        int n=inv.size();
        vector<vector<int>>v;
        int i=0;
        sort(inv.begin(),inv.end());
        while(i<n){
            vector<int>curr=inv[i++];
            vector<int>merge=curr;
           while(i<n and doesIntervalsOverlap(curr,inv[i])){
               merge=mergeIntervals(curr,inv[i]);
               curr=merge;
               i++;
           }
           v.push_back(merge);
        }
        return v;
    }