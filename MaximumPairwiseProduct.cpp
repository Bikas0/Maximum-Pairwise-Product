#include<bits/stdc++.h>
#include<vector>
#include<cstdlib>//it's used for taking random number in code;
using namespace std;

long long MaxPairwiseProduct(const vector<int> & numbers)
{
    long long result = 0;
    int n = numbers.size();
    for (int i = 0; i<n; ++i)
    {
        for (int j = i+1; j<n; ++j)
        {

            if(((long long) numbers[i]) * numbers[j] > result)
            {
                result = ((long long) numbers[i])* numbers[j];
            }
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers)
{
    long long result;
    int n = numbers.size();
    int max_index1 = -1;
    for(int i = 0; i<n; i++)
    {
        if((max_index1 == -1) || ((long long) numbers[i]>numbers[max_index1]))
        {
            max_index1 = i;
        }
    }

    int max_index2 = -1;
    for (int j = 0; j<n; j++)
    {
        if((j != max_index1) && ((long long)(numbers[j] > numbers[max_index2])|| (max_index2 == -1)))
        {
            max_index2 = j;
        }
    }
    //cout<< max_index1 << " "<<max_index2<<endl<<endl;
    return result = (long long) (numbers[max_index1] * (long long )numbers[max_index2]);
}
int main()
{
    //Stress Test................ Start............
    /*while(true)
    {
        int n = rand()%10 +2 ;
        cout<<n<<endl;
        vector<int> a;
        for (int i = 0; i<n; i++)
        {
            a.push_back(rand()%100);
        }
        for(int i = 0; i<n; i++)
        {
            cout<<a[i] <<" ";
        }
        cout<<endl;
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if(res1!= res2)
        {
            cout<<"Wrong Answer " << res1<< " "<<res2;
        }
        else
        {
            cout<<"OK\n";
        }
    }*/
    // Stress Test ...........close..............
    int n;
    cin>>n;
    vector<int> numbers(n);
    for (int i = 0; i<n; i++)
    {
        cin>>numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);
    cout<<result;
    return 0;
}
