#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;

struct student {
    string surname, name;
    vector <double> hwm;
	double examm, sum=0, avg_hw, avg, med;
  int n,v;
	};

int main(){
    	vector<student> stud;
    	int f;
		char ans1 = 'y';
		while (ans1 != 'n')
        {stud.push_back(student());
		f = stud.size()-1;
		cout<<"Enter student's surname: "<<endl;
        cin>>stud[f].surname;
        cout<<"Enter student's name: "<<endl;
        cin>>stud[f].name;

		char ans= 'y';
        while (ans != 'n')
        {
           cout<<"Enter student's homework mark: "<<endl;
        cin>>stud[f].n;
        stud[f].hwm.push_back(stud[f].n);
        cout<<"Add a mark? (y/n)"<<endl;
        cin>>ans;
        }
        stud[f].v = stud[f].hwm.size();
         for(int i=0; i<stud[f].v; i++)
        	stud[f].sum += stud[f].hwm[i];
		stud[f].avg_hw = stud[f].sum/stud[f].v;
        cout<<"Enter student's exam mark: "<<endl;
        cin>>stud[f].examm;
        stud[f].avg =  0.4 * stud[f].avg_hw + 0.6 * stud[f].examm;

        for(int j = 1; j < stud[f].v; ++j)
	{
		for(int r = 0; r < stud[f].v-j; r++)
		{
			if(stud[f].hwm[r] >= stud[f].hwm[r+1])
			{
				int temp = stud[f].hwm[r];
				stud[f].hwm[r] = stud[f].hwm[r+1];
				stud[f].hwm[r+1] = temp;
			}
		}
	}
		if (stud[f].v%2!=0) stud[f].med = stud[f].hwm[stud[f].v/2];
		else stud[f].med = (stud[f].hwm[stud[f].v/2-1] + stud[f].hwm[stud[f].v/2])/2;
cout<<"Add students? (y/n)"<<endl;
cin>>ans1;
}
    cout<<"Surname"<<setw(5)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.)   /  Final points (Med.)"<<endl;
    for(int i=0; i<90; i++)
		cout<<"-";
	cout<<endl;

    for(int i=0; i<stud.size(); i++){
        cout<<stud[i].surname<<setw(15)<<cout.fill(' ')<<stud[i].name<<setw(15)<<cout.fill(' ')<<setprecision(3)<<setw(4)<<stud[i].avg<<setw(20)<<cout.fill(' ')<<setprecision(3)<<setw(4)<<stud[i].med<<endl;

    }


    return 0;
}

