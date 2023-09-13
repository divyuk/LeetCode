//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool cmp(Item i1 , Item i2){
        return i1.value*1.0/i1.weight > i2.value*1.0/i2.weight;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr , arr+n , cmp);
        double maxCarry=0;
        for(int i =0;i<n;i++){
            if(arr[i].weight >= W){
                maxCarry += ( (arr[i].value*1.0) / (arr[i].weight)  ) * W;
                break;
            }
            maxCarry += arr[i].value;
            W -= arr[i].weight;
        }
        return maxCarry;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends