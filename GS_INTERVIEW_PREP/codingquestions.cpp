#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
#include<stack>
using namespace std;
//1.Delete without head pointer 

    
class Solution
{
    public:
    struct Node {
    int data;
    struct Node *next;
    Node(int x) {
    data = x;
    next = NULL;
    }
    };
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       //copying current node's next value to curr    
       del->data=del->next->data;
       //linking curr to curr's next's next
       del->next=del->next->next;
       //setting curr's next's next's equal to null ptr
       //del->next->next=nullptr;
       
    }

};

//2.Mirror Tree 
class Solution{
    public:
    struct Node
    {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
    };
    //Function to convert a binary tree into its mirror tree.
    void mirror(Node* node)
    {
     // base class
     if(node==nullptr)
     return;
     
     Node*left=node->left;
     Node*right=node->right;
     
     node->left=right;
     node->right=left;
     
     mirror(node->left);
     mirror(node->right);
     return;
    }
};

//3.wave array
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int *arr, int n){
        
        // Your code here
        for(int i=0;i<n;i+=2)
        {
            int idx=i;
            int minn=arr[i];
            int minidx=i;
            for(int j=0;j<3&&(idx+j)<n;j++)
            {
                if(minn>arr[j+idx])
                {
                    minn=arr[j+idx];
                    minidx=j+idx;
                }
                
            }
            
            if(idx+1<n)
            {
                swap(arr[idx+1],arr[minidx]);
            }
            
            
        }
        
    }
};

// 4.To print anagrams in groups
void sortString(string&t)
{
    for(int i=0;i<t.length();i++)
    {
        for(int j=0;j<t.length()-i-1;j++)
        {
            if(t[j]>t[j+1])
            swap(t[j],t[j+1]);
        }
    }
}

vector<vector<string>> Anagrams(vector<string>& string_list) 
{

    unordered_map<string,vector<int>>m;
    //traverse the vector
    for(int i=0;i<string_list.size();i++)
    {
        //sort every string
        string t=string_list[i]; 
        //put it in another vector
        sortString(t);
        //insert tht index to that string's vector in hashmap
        m[t].push_back(i);
    }
    unordered_map<string,vector<int>>::iterator it=m.begin();
    vector<vector<string>> ans;
    for(;it!=m.end();it++)
    {
        vector<string>w;
        for(int i=0;i<it->second.size();i++)
        {
            w.push_back(string_list[it->second[i]]);
        }
       ans.push_back(w);
    }
    return ans;
}
// to safe sorting time, store frequency in the hashmap itself and use it as a key

//5. segregate 0 and 1

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        int start=0;
        int end=n-1;
        while(end>=0 && arr[end]==1)
        end--;
        
        while(start<end)
        {
            if(arr[start]==1)
            {
                swap(arr[start],arr[end]);
                end--;
            }
            else if(arr[start]==0)
            start++;
        }
    }
};

//Squares in N*N Chessboard 
class Solution {
  public:
    long long squaresInChessBoard(long long n) {
       //1*1: N*N
       //2*2: N-1*N-1
       //3*3: N-2*N-2 ans so on
       //so sum of squares of natural numbers= n(n+1)(2n+1)/6
       //but that can overflow
       //so using long long
       // and evaluate in parts, making sure it remains whole so 
       // divide n(n+1) by 2 first and 2n+1 by 3 then multiply both
       
       //return (n*(n+1)/2)*((2*n+1)/3);
       //issue with above is 2n+1 when divided by 3 can give non-int value
       return (n * (n + 1) / 2) * (2*n + 1) / 3;;
    }
};


//6.Search in a row-column sorted Matrix 
class Solution{
  public:
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        int start=0;
        int end=n*m-1;
        
        while(start<=end)
        {
            int mid=(start+end)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==x)
            {
                return 1;
            }
            else if(matrix[row][col]<x)
            {
               start=mid+1;
               
            }
            else if(matrix[row][col]>x)
            {
                end=mid-1;
            }
        }
        return 0;
    }
};

//7.egg dropping problem

class Solution{
    public:
    /* Function to get minimum number of trials needed in worst 
      case with n eggs and k floors */
    
    int eggDrop(int n, int f) 
    {
        vector<int>v(f+1,0);
       vector<vector<int>>dp(n+1,v);
       
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=f;j++)
           {
               if(j==1)
               {
                   dp[i][j]=1;
               }
               else if(i==1)
               {
                   dp[i][j]=j;
               }
               else
               {
                   int minn=(int)1e9;
                   for(int mj=j-1,pj=0;mj>=0;mj--,pj++)
                   {
                       int v1=dp[i][mj];
                       int v2=dp[i-1][pj];
                       int maxx=max(v1,v2);
                       minn=min(maxx,minn);
                   }
                   dp[i][j]=minn+1;
               }
           }
       }
       return dp[n][f];
    }
};

//8.sort the stack using recursion i.e top should point to greatest element 
// no use of while or for allowed
// variant of reverse stack using recursion
class SortedStack{
public:
	stack<int> s;
	void sort();
};
void sortinsert(stack<int>&s,int x)
{
    // here if stack empty or top elemnt is less than x then simply push x in stack
    if(s.empty() || x>=s.top())
    {
        s.push(x);
        return;
    }
    // else
    //store top element
    int temp=s.top();
    s.pop();
    // call insert again till you find smaller element
    sortinsert(s,x);
    //on return insert the popped top element
    s.push(temp);
}

void SortedStack :: sort()
{
   if(!s.empty())
   {
// taking out top element
   int x=s.top();
   s.pop();
// calling func again to repeat it   
   sort();
   // on return, insertion would be in sorted order
   sortinsert(s,x);
   }
}

//9.implement stack using array
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

 

/* The method push to push element into the stack */
void MyStack :: push(int x)
{
        // Your Code
        top++;
        arr[top]=x;
        
}

/*The method pop which return the element 
  poped out of the stack*/
int MyStack :: pop()
{
        // Your Code
       if(top==-1)
       return top;
       int t=arr[top];
       top--;
       return t;
        
}

//10. counting sort
//11.quick sort
//12. SPECIAL STACK: getmin in O(1) & O(n) in stack
//13. array equal or not
bool areEqual(int arr1[], int arr2[], int n, int m)
{
    // If lengths of arrays are not equal
    if (n != m)
        return false;
 
    // Store arr1[] elements and their counts in
    // hash map
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr1[i]]++;
 
    // Traverse arr2[] elements and check if all
    // elements of arr2[] are present same number
    // of times or not.
    for (int i = 0; i < n; i++) {
        // If there is an element in arr2[], but
        // not in arr1[]
        if (mp.find(arr2[i]) == mp.end())
            return false;
 
        // If an element of arr2[] appears more
        // times than it appears in arr1[]
        if (mp[arr2[i]] == 0)
            return false;
 
        mp[arr2[i]]--;
    }
 
    return true;
}

//if all elements occur only once
//An Alternate Solution without comparing each element of the arrays and without using unordered_map (by using XOR). 
//This approach will work only if each  element exist only once in an array. For example :  array a  : { 3 , 3 } and array b : { 5 , 5 },  
//xor_of_array_a(say b1) = 0 and xor_of_array_b = 0 (say b2) and b1^b2 = 0, but array a and array b are not equal.

bool areEqual(int arr1[], int arr2[], int n, int m)
{
    // If lengths of array are not equal means
    // array are not equal
    if (n != m)
        return false;
     
    // to store xor of both arrays
    int b1 = arr1[0];
    int b2 = arr2[0];
     
    // find xor of each elements in array
    for (int i = 1; i < n; i++) {
        b1 ^= arr1[i];
    }
 
    for (int i = 1; i < m; i++) {
        b2 ^= arr2[i];
    }
    int all_xor = b1 ^ b2;
     
    // if xor is zero means they are equal (5^5=0)
    if (all_xor == 0)
        return true;
     
    // If all elements were not same, then xor will not be
    // zero
    return false;
}
