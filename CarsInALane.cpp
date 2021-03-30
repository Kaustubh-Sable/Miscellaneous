/**
* Cars in the same lane are represented by numbers and car IDs. Positive numbers suggest cars behind and negative suggest the ones
* ahead. Car points within distance of 1 should be considered as the same car. Positive numbers should be collapsed into 1 before
* (like 1,1 1.5,2 2.25,3 -> should be considered as -> 1,1 2.25,3) while negative numbers should be collapsed into 1 later (like
* -5.4,1 -5.5,2 -5.1,3 -3,4 -> should be considered as -> -5.1,3 -3,4). Note that the car points in the input are not necessarily
* in the ascending order.
**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int,int>> cars_in_lane {{-5,1},{-6,2},{-7,3},{-5,4},{10,5},{-5,1}};
    // vector<pair<int,int>> cars_in_lane {{1,1},{1.01,2},{1.02,3},{1.04,4},{1.05,5},{-5,6},{-5.1,7},{-5.2,8},{-5.3,9},{-5.4,10}};
    // vector<pair<double,int>> cars_in_lane {{1,1},{1.5,2},{2.25,3}};
    vector<pair<double,int>> ans;
    
    sort(cars_in_lane.begin(), cars_in_lane.end());
    
    int index = 0;
    while(index < cars_in_lane.size() && cars_in_lane[index].first<0)
        index++;
        
    if(index < cars_in_lane.size())
        ans.push_back(cars_in_lane[index]);
    for(int i=index+1;i<cars_in_lane.size();i++) {
        if(cars_in_lane[i].first - ans[ans.size()-1].first >= 1.0)
            ans.push_back(cars_in_lane[i]);
    }
    
    if(index>0)
        ans.push_back(cars_in_lane[index-1]);
    for(int i=index-2;i>=0;i--) {
        if(cars_in_lane[i].first - ans[ans.size()-1].first == 0)
            ans[ans.size()-1].second = cars_in_lane[i].second;
        if(cars_in_lane[i].first - ans[ans.size()-1].first >= 1.0)
            ans.push_back(cars_in_lane[i]);
    }
    
    sort(ans.begin(), ans.end());
    
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    
    return 0;
}
