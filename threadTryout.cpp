#include<iostream>
#include<mutex>
#include<thread>
#include<vector>
using namespace std;

mutex a;

void printDummy(int i)
{
    unique_lock<mutex> lockThisSection(a);
    cout<<"Hello printDummy ";
    cout<<i<<endl;
}

int main()
{
    int size = 10;
    vector<thread> threadsVec(size);
    for(int i = 0; i < size; i++)
        threadsVec[i] = thread(printDummy, i);
    
    for(int i = 0; i < size; i++){
        threadsVec[i].join();
        cout<<"joining : "<<i<<endl;
    }

    vector<thread> threadsVec2;
    for(int i = 0; i < size; i++)
        threadsVec2.push_back(thread(printDummy, i));
    
    for(int i = 0; i < size; i++){
        threadsVec2[i].join();
        cout<<"joining : "<<i<<endl;
    }

    thread t1 (printDummy, 1), t2(printDummy, 2), t3(printDummy, 3);
    t1.join();
    t2.join();
    t3.join();
    
    cout<<"ended"<<endl;
    return 0;
}