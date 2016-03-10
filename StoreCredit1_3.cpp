//
// 
//  CISC3150proj1.2
//
//  Created by Anika Czander on 3/7/16.
//  Copyright (c) 2016 Anika Czander. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <utility>
using namespace std;

//pair<int,int> credit_pos(vector<int> v, int n, int credit);
pair<int, int> credit_pos(const vector<int>& prices, int n_items, int credit)
{
    pair<int, int> temp;
    for(int i = 0; i < n_items - 1; ++i)
    {
        for(int j = i + 1; j < n_items; ++j)
        {
            if(prices[i] + prices[j] == credit)
            {
                temp.first = i+1;
                temp.second = j+1;
            }
        }
    }
    return temp;
}

int main()
{
    int num_cases;
    int num_items;
    int credit;
    
    cout<<"Enter how many cases there are (N)"<<endl;
    cin >> num_cases;
    for(int i = 0; i < num_cases; i++)
    {
        cout<<"How much credit do you have? (C)"<<endl;
        cin >> credit;
        cout<<"How many items are in the store? (I)"<<endl;
        cin >> num_items;
        int price;
        vector<int> prices;
        cout<<"What are the prices of the items? (P)"<<endl;
        for(int j=0; j<num_items; j++)
        {
            cin >> price;
            prices.push_back(price);
        }
        pair<int,int> loc = credit_pos(prices, num_items, credit);
        cout <<"Case #"<< i+1 <<": " << loc.first <<" "<< loc.second<< std::endl;
    }
}