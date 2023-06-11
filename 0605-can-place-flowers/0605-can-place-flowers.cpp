class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(i<flowerbed.size() && n)
        {   if(flowerbed[i]==0)
            { int ne= (i==flowerbed.size()-1)?0:flowerbed[i+1];
            int p=(i==0)?0:flowerbed[i-1];
            if(p==0 && ne==0)
            {flowerbed[i]=1;
            n--;}
            }
            i++;
        }
        for(int i=0;i<flowerbed.size();i++)
        cout<<flowerbed[i]<<" ";
        cout<<"/n"<<n;
        if(n==0)
        return true;
        return false;
    }
};