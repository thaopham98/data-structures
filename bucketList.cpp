//
//  main.cpp
//  bucketList
//
//  Created by Thao Pham on 11/24/21.
//

#include <iostream>
using namespace std;


int main()
{
    int arr[] = {1985, 1988, 1990, 1992, 1993, 1997, 1999, 2006, 2007, 2009, 2010 };
    
    for (int i =0; i < 11 ; i++)
    {
        int index = (arr[i])%9 ;
        cout << "Result of " << arr[i] << " : " << index << endl;
        
    }
    return 0;
}
