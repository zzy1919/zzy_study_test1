#include<stdio.h>
#include<iostream>
using namespace std;

int func(int num);

int main()
{
    printf("个人学习cpp, main202311211-1108 \n");
    cout << "hello" << endl;
    int b = 2;
    for (int i=0; i < 5; i++){
	    cout << i * 11 << endl;
	    b += 5;
        func(b);
    }

    system("Pause");
    return 0;
}



int func(int num)
{
    if (num > 101) return num + 1000;
    else{
        num = num * 2;
        cout << num << endl;
        return num + 10000;
    }
}
