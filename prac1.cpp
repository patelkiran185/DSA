#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;
// // Longest SubString Length
// // #include<iostream>
// #include<unordered_map>
// using namespace std;
// int LongestSubstringLength(string s){
//     unordered_map<char,int> charIndexMap;
//     int maxlength=0;
//     int start=0;
//     for(int i=0;i<s.length();i++){
//         if(charIndexMap.find(s[i]) != charIndexMap.end()){
//             start=max(start,charIndexMap[s[i]]+1);
//         }
//         charIndexMap[s[i]]=i;
//         maxlength=max(maxlength,i-start+1);
//     }
//     return maxlength;  
// }
// int main(){
//     string s;
//     cin>>s;
//     int res=LongestSubstringLength(s);
//     cout<<"Longest Substring Length: "<<res<<"\n";
//     return 0;
// }

// // //Longest Palindromic Substring
// // #include<iostream>
// // #include<bits/stdc++.h>
// // #include<string.h>
// // using namespace std;
// // string LongestPalindromicString(string s){
// //     int n=s.size();
// //     vector<vector<bool>> dp(n,vector<bool>(n,false));
// //     int start=0;
// //     int maxLength=0;
// //     for(int i=0;i<n;i++){
// //         dp[i][i]=true;
// //         maxLength = 1;
// //     }
// //     for(int i=0;i<n-1;i++){
// //         if(s[i]==s[i+1]){
// //             dp[i][i+1]=true;
// //             start=i;
// //             maxLength=2;
// //         }
// //     }
// //     for(int len=3;len<=n;len++){
// //         for(int i=0;i<n-len+1;i++){
// //             int j=i+len-1;
// //             if(s[i]==s[j] && dp[i+1][j-1]){
// //             dp[i][j]=true;
// //             start=i;
// //             maxLength=len;
// //         }
// //         }
// //     }
// //     return s.substr(start,maxLength);
// // }
// // int main(){
// //     string s;
// //     cin>>s;
// //     string f=LongestPalindromicString(s);
// //     cout<<" "<<f;
// //     return 0;
// // }

// // // string to integer
// // #include<iostream>
// // #include<string.h>
// // #include<climits>
// // using namespace std;
// // int myatoi(string s){
// //     int i=0;
// //     while(i<s.length() && s[i]==' '){
// //         i++;
// //     }
// //     int sign=1;
// //     if(i<s.length() && s[i]=='-' || s[i] == '+'){
// //         sign =(s[i++]=='-') ? -1 :1;
// //     }
// //     long long result =0;
// //     while(i<s.length() && isdigit(s[i])){
// //         result=result*10 + (s[i++] - '0');
// //     if(result*sign > INT_MAX) return INT_MAX;
// //     else if (result*sign < INT_MIN) return INT_MIN;
// //     }
// //     return (result*sign);
// // }
// // int main(){
// //     string s;
// //     cin>>s;
// //     int st=myatoi(s);
// //     cout<<st;
// //     return 0;
// // }

// // //reverse string
#include<iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;
string  reverse(string s){
    int st=0;
    int e=s.length()-1;
    while(st<e){
        swap(s[st],s[e]);
        ++st;
        --e;
    }
    return s;
}
int main(){
    string s;
    cin>>s;
    cout<<reverse(s)<<endl;
    return 0;
}

// // //roman to integer 
// // #include<iostream>
// // #include<unordered_map>
// // using namespace std;
// // int romanToInt(string s){
// //     int total=0;
// //     int prev=0;
// //     unordered_map<char,int> roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
// //     for(char c: s){
// //         int current= roman[c];
// //         total += current;
// //         if(current > prev){
// //             total -= 2*prev;
// //         }
// //         prev=current;
// //     }
// //     return total;
// // }
// // int main(){
// //     string s;
// //     cin>>s;
// //     int n=romanToInt(s);
// //     cout<<n;
// //     return 0;
// // }

// // //integer to roman
// // #include<iostream>
// // #include<string.h>
// // #include<vector>
// // using namespace std;
// // string IntToRoman(int num){
// //     vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
// //     vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
// //     string roman;
// //     for(int i=0;i < values.size() && num >0;i++){
// //         while(values[i] <=  num){
// //             num -= values[i];
// //             roman += symbols[i];
// //         }
// //     }
// //     return roman;
// // }
// // int main(){
// //     int n;
// //     cin>>n;
// //     string s;
// //     s=IntToRoman(n);
// //     cout<<s<<endl;
// //     return 0;
// // }

// // letter combination
// // #include<iostream>
// // #include<vector>
// // #include<string.h>
// // #include<bits/stdc++.h>
// // using namespace std;
void helper(int idx,int n, string &digits,vector<string> &dict,string &temp,vector<string> &res){
    if(idx==n){
        res.push_back(temp);
    }
    string k= dict[digits[idx]-'0'];
    for(int i=0;i< k.size();i++){
        temp += k[i];
        helper(idx+1,n,digits,dict,temp,res);
        temp.pop_back();
    }
}
vector<string> letterCombinations(string digits){
    int n= digits.length();
    vector<string> res;
    vector<string> dict={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string temp="";
    helper(0,n,digits,dict,temp,res);
    return res;
}
int main(){
    string s;
    cin>> s;
    vector<string> st;
    st = letterCombinations(s);
    for(const string& str : st){
        cout<<str<<" ";
    }
    cout<<endl;
    return 0;
}

// // //generate parenthesis
void backtrack(vector<string> &result,string current,int left,int right,int n){
    if(current.size()==2*n){
        result.push_back(current);
        return;
    }
    if(left<n){
        backtrack(result,current+'(',left+1,right,n);
    }
    if(right<left){
        backtrack(result,current+')',left,right+1,n);
    }
}
vector<string> generatePArenthesis(int n){
    vector<string> result;
    backtrack(result,"",0,0,n);
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<string> str;
    str=generatePArenthesis(n);
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// // //regular expression matching
// // bool isValid(string s,string p){
// //     int m=s.length();
// //     int n=s.length();
// //     vector<vector<bool> dp(m+1,vector<bool>(n+1,false));
// //     for(int j=1;j<=n;j++){
// //         if(p[j-1]=='*'){
// //             dp[0][j]==dp[i][j-2];
// //         }
// //     }
// //     for(int i=1;i<=m;++i){
// //         for(int j=1;j<=n;++j){
// //             if(s[i-1]==p[j-1] || p[j-1]=='.'){
// //                 dp[i][j]=dp[i-1][j-1];
// //             } else if(p[j-1]=='*'){
// //                 dp[i][j] = dp[i][j-2] || (dp[i-1][j] && s[i-1]==p[j-2] || p[j-2]=='.');
// //             }
// //         }
// //     }
// //     return dp[m][n];
// // }

// // //longest common prefix
string longestcommonprefix(vector<string> &strs){
    if(strs.empty()){
        return "";
    }
    for(int i=0;i<strs[0].size();++i){
        for(int j=1;j<strs.size();++j){
            if( i>= strs[j].size() || strs[j][i] != strs[0][i]){
                return strs[0].substr(0,i);
            }
        }
    }
    return strs[0];
}
int main(){
    vector<string> s;
    s={"flower","flow","float"};
    cout<<longestcommonprefix(s)<<endl;
    return 0;
}

// // //valid palindrome
bool isPalindrome(string s){
    int st=0;
    int e=s.length();
    while(st<=e){
        if(!isalnum(s[st])){
            st++;
            continue;
        }
        if(!isalnum(s[e])){
            e--;
            continue;
        }
        if(tolower(s[st]) != tolower(s[e])){
            return false;
        }
        else{
            st++;
            e--;
        }
    }
    return true;
}
int main(){
    string s="a man in a canal";
    cout<<isPalindrome(s)<<endl;
    return 0;
}

// // //first unique character in a string
int uni(string s){
    unordered_map<char,int> freq;
    for(auto ch: s){
        freq[ch]++;
    }
    for(int i=0;i<s.size();i++){
        if(freq[s[i]]==1){
            return i;
        }
    }
    return -1;
}
int main(){
    string s="dsferddfg";
    cout<<uni(s)<<endl;
    return 0;
}

// // // //anagrams grouping
vector<vector<string>> anagrams(vector<string> & strs){
    unordered_map<string,vector<string>> mp;
    for(auto x : strs){
        string word=x;
        sort(strs.begin(),strs.end());
        mp[word].push_back(x);
    }
    vector<vector<string>> ans;
    for(auto x : mp){
        ans.push_back(x.second);
    }
    return ans;
}
int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res=anagrams(strs);
    for (auto &v : res){
        for(string &s : v){
            cout<< s<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// // //longest palindrome
int longestpalindrome(string s){
    unordered_map<char,int> mp;
    int oddCount=0;
    for(auto ch: s){
        mp[ch]++;
        if(mp[ch]%2==0){
            oddCount-=1;
        }
        else{
            oddCount+=1;
        }
    }
    return s.length()-max(0,oddCount-1);
}
int main(){
    string s;
    cin>>s;
    int x=longestpalindrome(s);
    cout<<x<<endl;
    return 0;
}

// // // sort an array
// vector<int> sortA(vector<int> &nums){
//     sort(nums.begin(),nums.end());
//     return nums;
// }
// int main(){
//     vector<int> nums={1,5,6,8,9,2,3};
//     vector<int> result=sortA(nums);
//     for(int i=0;i<result.size();i++){
//         cout<<result[i]<<" ";
//     }
//     // cout<<sortA(nums)<<endl;
//     return 0;
// }

// // //merge two sorted arrays and calculate median
double findMedianOfTwoMergedArrays(vector<int> &nums1,vector<int> &nums2){
    nums1.insert(nums1.end(),nums2.begin(),nums2.end());
    sort(nums1.begin(),nums1.end());
    int n = nums1.size();
    if(n%2==0){
        return (nums1[n/2 -1]+ nums1[n/2]) / 2.0;
    }
    else{
        return nums1[n/2];
    }
}
int main(){
    vector<int> nums1={1,5,8,6};
    vector<int> nums2={5,7,8,9};
    double y=findMedianOfTwoMergedArrays(nums1,nums2);
    cout<<y<<endl;
    return 0;
}

// //input vector<int>
// int main(){
//     vector<int> numbers;
//     int n;
//     cout<<"Enter number: "<<endl;
//     cin>>n;
//     cout<<"Enter numbers: ";
//     for(int i=0;i<n;i++){
//         int num;
//         cin>>num;
//         numbers.push_back(num);
//     }
//     for(int num:numbers){
//         cout<<num<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// //best time to sell and buy stock
// int maxProf(vector<int> &price){
//     int min_price=price[0];
//     int maxprof=0;
//     for(int i=0;i<price.size();i++){
//         maxprof=max(maxprof,price[i]-min_price);
//         min_price=min(price[i],min_price);
//     }
//     return maxprof;
// }
// int main(){
//     vector<int> numbers;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int num;
//         cin>>num;
//         numbers.push_back(num);
//     }
//    int x= maxProf(numbers);
//    cout<<x<<endl;
//    return 0;
// }

// //minimum common value
int getCommon(const vector<int> &nums1, const vector<int> &nums2){
    int i=0,j=0;
    while(i< nums1.size() && j<nums2.size()){
        if(nums1[i]==nums2[j]){
            return nums1[i];
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return -1;
}
int main(){
    vector<int> nums1={1,2,5,6};
    vector<int> nums2={5,2,6,7,8};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int x=getCommon(nums1,nums2);
    cout<<x<<endl;
    return 0;
}

// //concatenation of array
// class Solution {
// public:
//     vector<int> getConcatenation(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             nums.push_back(nums[i]);
//         }
//         return nums;   
//     }
// };
// int main(){
//     Solution s;
//     vector<int> nums={1,2,5,9};
//     vector<int> res=s.getConcatenation(nums);
//     for(int num: res){
//         cout<<num<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// // //minimum operations to make array increasing
// // int MinimumOp(vector<int> &nums){
// //     int opera=0;
// //     for(int i=1;i<nums.size();++i){
// //         if(nums[i]<=nums[i-1]){
// //             opera += (nums[i-1]-nums[i]+1);
// //             nums[i]=nums[i-1]+1;
// //         }
// //     }
// //     return opera;
// // }
// // int main(){
// //     vector<int> nums={1,2,2};
// //     int x=MinimumOp(nums);
// //     cout<<x<<endl;
// //     return 0;
// // }

// // //buddy strings
bool buddyStrings(string s, string goal){
    if(s.size() != goal.size()){ //size of bot strings not equal
        return false;
    }
    if(s==goal && unordered_set<char>(s.begin(),s.end()).size() < s.size()){
        return true;
    } // equal haitoh set 
    vector<int> dif;
    for(int i=0;i<s.size();i++){
        if(s[i] != goal[i]){
            dif.push_back(i);
        } // diff
    }
    return dif.size()==2 && s[dif[0]]== goal[dif[1]] && s[dif[1]]==goal[dif[0]];
}
int main(){
    string s="ab";
    string goal="ba";
    cout<<buddyStrings(s,goal)<<endl;
    return 0;
}

// // //remove duplicates from an sorted array
// // int RemoveDuplicates(vector<int> &nums){
// //     int j=1;
// //     for(int i=1;i<nums.size();i++){
// //         if(nums[i] != nums[i-1]){
// //             nums[j]=nums[i];
// //             j++;
// //         }
// //     }
// //     return j;
// // }
// // int main(){
// //     vector<int> nums={1,1,2};
// //     int c=RemoveDuplicates(nums);
// //     cout<<c<<endl;
// //     return 0;
// // }
// // class Solution {
// // public:
// //     int removeDuplicates(int nums[], int n) {
// //         if (n == 0) return 0;
// //         int j = 1;
// //         for (int i = 1; i < n; i++) {
// //             if (nums[i] != nums[i - 1]) {
// //                 nums[j] = nums[i];
// //                 j++;
// //             }
// //         }
// //         return j;
// //     }
// // };
// // int main() {
// //     Solution solution;
// //     int nums[] = {1, 1, 2};
// //     int n = sizeof(nums) / sizeof(nums[0]);
// //     int newLength = solution.removeDuplicates(nums, n);
// //     std::cout << newLength << std::endl;
// //     return 0;
// // }

// // //subarray with given sum
void SubArraySum(int arr[],int n,int sum){
    for(int i=0;i<n;i++){
        int currentsum = arr[i];
        if(currentsum==sum){
            cout<<"Sum found at index: "<<i<<endl;
            return;
        }
        else{
            for(int j=i+1;j<n;j++){
                currentsum += arr[j];
                if(currentsum==sum){
                    cout<<"sum found between indices "<< i<<" and "<<j<<endl;
                    return;
                }
            }
        }     
    }
    cout<<"No subarray found"<<endl;
    return;
}
int main(){
    int arr[]={1,5,6,9,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=100;
    SubArraySum(arr,n,sum);
    return 0;
}

// // // //spiral matrix using vectors
// vector<int> spiralorder(vector<vector<int>> &matrix){
//     vector<int> result;
//     int left=0,bottom=matrix.size()-1,top=0,right=matrix[0].size()-1;
//     while(left<= right && top<= bottom){
//         for(int j=left;j<=right;j++) result.push_back(matrix[top][j]);
//         for(int i=top+1;i<=bottom;i++) result.push_back(matrix[i][right]);
//         if(top<bottom && left<right){
//             for(int j=right-1;j>left;j--) result.push_back(matrix[bottom][j]);
//             for(int i=bottom;i>top;i--) result.push_back(matrix[i][left]);
//         }
//         top++,bottom--,left++,right--;
//     }
//     return result;
// }
// int main(){
//     vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
//     vector<int> result=spiralorder(matrix);
//     for(int i:result){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// int main(){
//     int rows,colums;
//     cin>> rows>>colums;
//     vector<vector<int>> matrix(rows,vector<int>(colums));
//     for(int i=0;i<rows;i++){
//         for(int j=0;j<colums;j++){
//             cin>>matrix[i][j];
//         }
//         cout<<endl;
//     }
//     for(int i=0;i<rows;i++){
//         for(int j=0;j<colums;j++){
//             cout<<matrix[i][j]<<" ";
//         }
//     }
//     return 0;
// }

// // //spiral using arrays
// void SpiralOrder(int matrix[3][3],int m,int n,int result[]){
//     int top=0,left=0,bottom=m-1,right=n-1;
//     int index=0;
//     while(top<=bottom && left<=right){
//         for(int j=left;j<=right;j++) result[index++]=matrix[top][j];
//         for(int i=top+1;i<=bottom;i++) result[index++]=matrix[i][right];
//         if(top<bottom && left<right){
//             for(int j=right-1;j>left;j--) result[index++]=matrix[bottom][j];
//             for(int i=bottom;i>top;i--) result[index++]=matrix[i][left];
//         }
//         top++,bottom--,left++,right--;
//     }
// }
// int main(){
//     int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//     int result[9];
//     SpiralOrder(matrix,3,3,result);
//     for(int i=0 ;i<9;i++){
//         cout<<result[i]<<" ";
//     }
//     return 0;
// }

// // //rotate an array
// // #include <iostream>
// void rotate(int nums[], int n, int k) {
//     int temp[n];
//     for (int i = 0; i < n; i++) {
//         temp[(i + k) % n] = nums[i];
//     }
//     for (int i = 0; i < n; i++) {
//         nums[i] = temp[i];
//     }
// }
// int main() {
//     int nums[] = {1, 2, 3, 4, 5, 6, 7};
//     int n = sizeof(nums) / sizeof(nums[0]);
//     int k = 3;
//     rotate(nums, n, k);
//     for (int i = 0; i < n; i++) {
//         std::cout << nums[i] << " ";
//     }
//     return 0;
// }

// // //rotate an image
// void RotateAnImage(vector<vector<int>> &matrix){
//     int row=matrix.size();
//     for(int i=0;i<row;i++){
//         for(int j=0;j<=i;j++){
//             swap(matrix[i][j],matrix[j][i]);
//         }
//     }
//     for(int i=0;i<row;i++){
//         reverse(matrix[i].begin(),matrix[i].end());
//     }
// }
// int main(){
//     vector<vector<int>> matrix={{1,2,3},{5,8,9},{5,8,9}};
//     RotateAnImage(matrix);
//     for(const auto &row:matrix){
//         for(int num:row){
//             cout<<num<< " ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// #include <string>
// #include <unordered_set>

// using namespace std;

// class Solution {
// public:
//     string reverseVowels(string s) {
//         unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
//         int i = 0, j = s.size() - 1;
//         while (i < j) {
//             if (vowels.count(s[i]) && vowels.count(s[j])) {
//                 swap(s[i++], s[j--]);
//             } else if (vowels.count(s[i])) {
//                 j--;
//             } else {
//                 i++;
//             }
//         }
//         return s;
//     }
// };
// int main(){
   
//     Solution sol;
//     string s;
//     s="efewrgrgv";
//     sol.reverseVowels(s);
//     cout<<s<<endl;
//     return 0;
// }



// int * finla(int arr[],int size,int target){
//     int * resukt=new int[2];
//     resukt[0]=-1;
//     resukt[1]=-1;
//     for(int i=0;i<size;i++){
//         if(arr[i] != target){
//             continue;
//             if(resukt[0]==-1){
//                 resukt[0]=i;
//             }
//             resukt[1]=i;
//         }
//     }
//     return resukt;
// }


// long long maxProduct(vector<int> arr,int n){
//     long long int maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//          long long int prod=1;
//         for(int j=i;j<n;j++){
           
//             prod*=arr[j];
//             maxi=max(maxi,prod);
//         }
//     }
//     return maxi;
// }
// int main(){
//     vector<int> arr={1,2,6,5,3};
//     int n=arr.size();
//     cout<<maxProduct(arr,n)<<endl;
//     return 0;
// }



// int main(){
//     int n=6;
//     int arr[n]={0,-9,1,3,-4,5};
//     int maxN=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]>maxN){
//             maxN=arr[i];
//         }
//         cout<<maxN<<endl;
//     }
//     return 0;
// }


// int factorial(int a);
// int main(){
//     int n=5;
//     int s=0;
//     int i=0;
//     while(i<n){
//         s+=factorial(i+1);
//         i++;
//     }
//     cout<<s<<endl;
//     return 0;
// }
// int factorial(int a){
//     if(a==0 || a==1){
//         return 1;
//     }
//     else{
//         return a*factorial(a-1);
//     }
// }

// bool prime(int num){
//     if(num>=2){
//         for(int i=2;i<=sqrt(num);i++){
//             if(num%i==0){
//                 return false;
//             }
//         }
//     }
//     else{
//         return false;
//     }
//     return true;
// }


// bool palindrome(int num){
//     int temp=num;
//     int rem=0;
//     int newNum=0;
//     while(temp!=0){
//         rem=temp%10;
//         newNum=newNum*10+rem;
//         temp=temp/10;
//     }
//     if(newNum==num){
//         return true;
//     }
//     return false;
// }
// int main(){
//     int num=563;
//     if(prime(num) && palindrome(num)){
//         cout<<num<<endl;
//     }else{
//         cout<<"no";
//     }

//     return 0;
// }




void replace(string s){
    if(s.size() == 0){
        return;
    }
    if(s[0] == 'o' && s[1] == 'o'){
        cout << "kmit";
        replace(s.substr(2));
    }
    else{
        cout << s[0];
        replace(s.substr(1));
    }
    return;
}

int main()
{
    string s = "goozeldoopsoococoofl";
    replace(s);
    return 0 ;
}

// void reverseArray(int arr[],int n){
//     int s=0,e=n-1;
//     while(s<e){
//         swap(arr[s],arr[e]);
//         s++;
//         e--;
//     }
// }
// int main()
// {
//     int n=4;
//     int arr[n]={1,2,3,6};
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
    
//     reverseArray(arr,n);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr) {
//         int n = arr.size();
//         int count_zeros = 0;
//         for (int num : arr) {
//             if (num == 0)
//                 count_zeros++;
//         }
//         int i = n - 1, j = n + count_zeros - 1;
//         // Add logic to duplicate zeros here
//         while (i >= 0 && j >= 0) {
//             // Shift elements and duplicate zeros
//             if (arr[i] == 0) {
//                 if (j < n) // Ensure j doesn't go beyond the original array size
//                     arr[j] = 0;
//                 j--;
//             }
//             if (j < n) // Ensure j doesn't go beyond the original array size
//                 arr[j] = arr[i];
//             i--;
//             j--;
//         }
//     }
// };

// int main() {
//     Solution solution;
    
//     // Test case
//     vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
//     solution.duplicateZeros(arr);
    
//     cout << "Modified array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
    
//     return 0;
// }





// #include<iostream>
// #include<algorithm>

// using namespace std;

// int minimumBoxes(int appl[],int n,int cap[],int m){
   
//     sort(cap,cap+m,greater<int>());
//     int counter=0;
//     int j=0;
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=appl[i];
//     } //sum 

//     while(sum>0){
      
//         if(sum > cap[j]){
//             sum -= cap[j];
//             counter+=1;
            
//         }
//         else{
//             counter++;
//             sum-=cap[j];
//         }
//         j++;

//     }
//     return counter;
// }
// int main(){
//     int arr[3]={1,3,2};
//     int cap[5]={4,3,1,5,2};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int m=sizeof(cap)/sizeof(cap[0]);

//     cout<<minimumBoxes(arr,n,cap,m);
//     return 0;
// }





// #include<iostream>
// #include<algorithm>

// using namespace std;

// int minimumBoxes(int appl[],int n,int cap[],int m){
   
//     sort(cap,cap+m,greater<int>());
//     int counter=0;
//     int j=0;
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=appl[i];
//     } //sum 
//     while(sum>0){
//         if(sum > cap[j]){
//             sum -= cap[j];
//             counter+=1;
            
//         }
//         else{
//             counter++;
//             sum-=cap[j];
//         }
//         j++;
//     }
//     return counter;
// }
// int main(){
//     int arr[3]={1,3,2};
//     int cap[5]={4,3,1,5,2};
//     int n=sizeof(arr)/sizeof(arr[0]);
// //     int m=sizeof(cap)/sizeof(cap[0]);

// //     cout<<minimumBoxes(arr,n,cap,m);
// //     return 0;
// // }



#include<iostream>
#include<algorithm>
using namespace std;
vector<int> FairWsap(vector<int> &A,vector<int> &B){
    int n=A.size();
    int m=B.size();
    int sum_n=0;
    int sum_m=0;
    for(int i=0;i<n;i++){
        sum_n+=A[i];
    }
    for(int i=0;i<m;i++){
        sum_m+=B[i];
    }
    int diff = (sum_n-sum_m)/2;
    cout<<diff;
    cout<<endl;
    sort(begin(B),end(B));
    for (int i:A)
    {
        /* code */
        if(binary_search(begin(B),end(B),i-diff)){
            // cout<<i;
            // cout<<i-diff;
            return {i,i-diff};
        }
    }

    return {-1,-1};
    

}
int main(){
    vector<int> A={2};
    vector<int> B = {1,3};

    FairWsap(A,B);

    return 0;
}



// bank open u two current and saving accounts offer karre 
// 20 people open, how many of you have opened in which account how much balance



// int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
