#include<bits/stdc++.h>
using namespace std;
class Fanvick{
    public:
    void updateValue(int index,int val,vector<int>&tree){
        int i = index;
        int n = tree.size(); 
        while(i < n){
           tree[i] += val;
           i = findNext(i);
        }
    }

    int sum(int ind , vector<int>&tree){
        int i = ind;
        int sum = 0;
        while(i > 0){
            sum += tree[i];
            i = findParent(i);
        }
        return sum;
    }

    vector<int>createTree(vector<int>&arr){
        int n = arr.size();
      vector<int>tree(n+1,0);
      for(int i =0 ;i < n;i++){
         updateValue(i+1,arr[i],tree);
      }
      return tree;
    }
    
    private:
    int findNext(int i){
        return i + (i & (-i));
    }
    int findParent(int i){
        return i - (i & (-i));
    }
};


int main(){
    vector<int>arr = {2,-1,5,3,-2,5,9,8,7,};
    Fanvick fn;
    vector<int>tree = fn.createTree(arr);
    int sm = fn.sum(2,tree); //1
    cout<<sm<<endl;
    sm = fn.sum(3,tree); //6
    cout<<sm<<endl;
    sm = fn.sum(4,tree); //9
    cout<<sm<<endl;
    sm = fn.sum(5,tree); //7
    cout<<sm<<endl;
    sm = fn.sum(6,tree); //12
    cout<<sm<<endl;

  return 0;
}