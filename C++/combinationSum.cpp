/**
 * Given an array of integers and a sum B,
 *  find all unique combinations in the array
 *  where the sum is equal to B. 
 * The same number may be chosen from the array any number of times to make B.
 * N = 4
    arr[] = {7,2,6,5}
    B = 16
    Output:
    (2 2 2 2 2 2 2 2)
    (2 2 2 2 2 6)
    (2 2 2 5 5)
    (2 2 5 7)
    (2 2 6 6)
    (2 7 7)
    (5 5 6)
 * */



#include <bits/stdc++.h>
using namespace std;
vector<int>res;
vector<vector<int> >ans;
void util(int b,vector<int> &a,int ind,int n)
{
    if(ind>=n)
    return;
    if(b==0)
    {
        //sort(res.begin(),res.end());
        //if(find(ans.begin(),ans.end(),res)==ans.end())
        ans.push_back(res);
        return;
    }
   
       if(a[ind]<=b)
       {
           res.push_back(a[ind]);
           
           util(b-a[ind],a,ind,n);
           
           res.pop_back();
       }
   util(b,a,ind+1,n);
   return;
   
}
vector<vector<int> > combinationSum(vector<int> &a, int b) {
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    util(b,a,0,a.size());
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    vector<int> A;
    cout<<"Enter elements of array\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }   
    int sum;
    cin>>sum;
    vector<vector<int>> result =combinationSum(A, sum);
   	if(result.size()==0){
   		cout<<"No solution exists";
   	}
    for(int i=0;i<result.size();i++){
        cout<<'(';
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j];
            if(j<result[i].size()-1)
                cout<<" ";
        }
        cout<<")";
    }
    cout<<"\n";
    return 0;
}
