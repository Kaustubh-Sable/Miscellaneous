#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main()
{
    unsigned int i, t, n;
    cin>>t;
    do
    {
        cin>>n;
        int input;
        bool flag = true;
        vector<int> villainStrengths,playerEnergies;
        
        for(i=0;i<n;i++)
        {
            cin>>input;
            villainStrengths.push_back(input);
        }
        for(i=0;i<n;i++)
        {
            cin>>input;
            playerEnergies.push_back(input);
        }
        
        sort(villainStrengths.begin(), villainStrengths.end());
        sort(playerEnergies.begin(), playerEnergies.end());
        
                
        for(i=0;i<n;i++)
        {
            if(villainStrengths[i]>playerEnergies[i])
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            cout<<"WIN\n";
        else
            cout<<"LOSE\n";
        
    }while(--t);
}
