//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
    
        void merge(int arr[],int str,int mid,int end)
        {
            int i=str,j=mid+1;
            while(i<=mid && arr[i]<0)
            i++;
            while(j<=end && arr[j]<0)
            j++;
            int k=i,l=j-1,temp_mid=mid;
            while(i<temp_mid)
            swap(arr[i++],arr[temp_mid--]);
            temp_mid=mid+1,j--;
            while(temp_mid<j)
            swap(arr[temp_mid++],arr[j--]);
            while(k<l)
            swap(arr[k++],arr[l--]);
        }
        
        void mergesort(int arr[],int str,int end)
        {
            if(str<end)
            {
                int mid=(str+end)/2;
                mergesort(arr,str,mid);
                mergesort(arr,mid+1,end);
                merge(arr,str,mid,end);
            }
        }
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            mergesort(arr,0,n-1);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends