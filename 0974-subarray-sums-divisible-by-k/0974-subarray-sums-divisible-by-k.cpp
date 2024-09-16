#define ll long long
class Solution {
public:
int subarraysDivByK(vector<int>& arr, int n) {
    map<ll, int> prefixSumCount;
    ll sum = 0;
    ll count = 0;

    // Initialize with 0 sum occurring once
    prefixSumCount[0] = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        // sum += arr[i];
        cout<<(sum + arr[i]) % n<<"\n";
        sum = (sum + arr[i]) % n;

        // Since sum can be negative, convert it to positive
        if (sum < 0)
            sum += n;
        
        count += prefixSumCount[sum];
       cout<<"c = " << count <<"\n";
        // Increment count of current sum
        prefixSumCount[sum]++;
    }
    return count;
}

};