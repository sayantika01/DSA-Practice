#include<bits/stdc++.h>
using namespace std;
void tower(int n,char source,char auxiliary, char destination){//#SAD
    if(n==1){
        cout<<"Move disk 1 from "<<source<<"to "<<destination<<endl;
        return;
    }
    tower(n-1,source,destination,auxiliary);//#SDA
    cout<<"Move disk  from "<<source<<"to "<<destination<<endl;
    tower(n-1,auxiliary,source,destination);//#ASD
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    char source='A';
    char auxiliary='B';
    char destination='C';
    tower(n,source,auxiliary,destination);
    return 0;
}