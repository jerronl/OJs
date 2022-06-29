/*
 * 1809.double.cpp
 *
 *  Created on: Apr 5, 2021
 *      Author: jerron
 *      http://noi.openjudge.cn/ch0201/1809/
 *
 *      */

#include<iostream>
using namespace std;    //good job. see following for my suggestions
int main(){             //use proper indentation to improve readability.
int a[15],d=-1,e,c(0);  //use meaningful names for variables
                        //prefer vector over array
while(true){            //usually we use for(;;). maybe because of less typing.
d+=1;                   //++ is shorter and faster
cin>>a[d];
if(a[d]==0||d>=15)
break;
}

for(int i=0;i<d;i++){   //Prefer ++i over i++
e=a[i];                 //we can use a[i] directly
for(int j=0;j<d;j++){
if(a[j]==2*e)
c++;                    //Prefer ++c over c++
}
}
cout<<c;
}                       //return an int
#include <vector>
#include<iostream>
using namespace std;
int main(){
    int n,result=0,tmp;
    const int maxn=15;
    vector<int> nums;
    for(n=0;n<maxn;++n){
        cin>>tmp;
        if(!tmp)
            break;
        nums.push_back(tmp);
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(nums[i]*2==nums[j])
                ++result;
    cout<<result;
    return 0;
}
