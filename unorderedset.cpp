//Unordered sets
//T.C. of unordered set is O(1) < than sets T.C. O(log(n))
//when ordering does not bother always use Unordered set
//because it is faster than the normal set
//it is internally implemnted with the help of Hash table

/*
Impotant Note: on valid datatype in Unordered sets
is that we can not use the complex data structure like vector, set, pair etc.
because Unordered sets is based on hash table & it contain all the hash value
for the each datatype like int, char, float, long but not for these complex data structure

we can not use " Unorderd_set<pair<int,int> string> m; "
but in case of normal set we can use all these complex data structure
*/

#include<bits/stdc++.h>
using namespace std;

void print(unordered_set<string> &s)
{
    //this is just to print the size of the set
    cout<<s.size()<<endl;

    //1st method for printing the set (range based loop)
    for(string value:s)
    {
        cout<<value<<endl;
    }
    cout<<endl;

    //2nd method is the (auto iterator)
    for(auto it=s.begin(); it!=s.end(); it++)
    {
        cout<<(*it)<<endl;
    }
}
int main()
{
    unordered_set<string> s;
    s.insert("abc");  // T.C. is O(1)
    s.insert("def");
    s.insert("ghi");
    s.insert("jkl");

    auto it=s.find("abc");   //T.C. O(1)
    if(it!=s.end())          // Check for the availabilty of key
    {
        //cout<<(*it);
        //s.erase(it); //it can be passed using itearator
    }
    //we can also use it directly like this 
    s.erase("abc");
    print(s);
}

