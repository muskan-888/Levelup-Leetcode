#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& v) {
        // zeroes     ones       unexplored        two
        //[0,zero] (zero,itr)   [itr,two]         (two,n-1]
        if(v.size()==0)
        {
            return;
        }
        int zero=-1;
        int itr=0;
        int two=v.size()-1;
        
        while(itr <= two)
        {
            if(v[itr]==0)
            {
                zero++;
                swap(v[itr],v[zero]);
                itr++;
            }
            else if(v[itr]==1)
            {
                itr++;
            }
            
            else if(v[itr]==2)
            {
                swap(v[itr],v[two]);
                two--;
            }
            
        }
    }
};