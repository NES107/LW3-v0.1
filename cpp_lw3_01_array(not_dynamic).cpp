#include <iostream>
#include <stdio.h>
#include <iomanip>


using namespace std;


struct results
{
    char surname[20];
    char name[20];
    int hwm[100];
    float examm;
    float averagem;
    float medianm;
    float fpoints;
    float fpointsm;
};

int main(){

    int studn;
    cout<<"\nWhat is the number of students?"<<endl;
    cin>>studn;

    results students [studn];

    for(int i=0; i<studn; i++){
        float average = 0;

        cout<<"Enter "<<i+1<<" student's surname: "<<endl;
        cin>>students[i].surname;
        cout<<"Enter "<<i+1<<" student's name: "<<endl;
        cin>>students[i].name;


        cout<<"How many homework marks does "<<i+1<<" student has: "<<endl;
        int hwsize;
        cin>>hwsize;
        for(int k=0;k<hwsize;k++){
           cout<<"Enter "<<i+1<<" student's "<<k+1<<" homework mark: "<<endl;
            cin>>students[i].hwm[k];
            if (students[i].hwm[k]>10){
                cout<<"Invalid input"<<endl;
                k--;
            }
        average+=students[i].hwm[k];

        }
        cout<<"Enter "<<i+1<<" student's exam mark: "<<endl;
        cin>>students[i].examm;

        students[i].averagem = average/hwsize;
        students[i].fpoints = 0.4*students[i].averagem+0.6*students[i].examm;
        int k=0;

        for(int j = 1; j < hwsize; ++j){
		for(int r = 0; r < hwsize-j; r++){
			if(students[i].hwm[r] >= students[i].hwm[r+1]){
				int temp = students[i].hwm[r];
				students[i].hwm[r] = students[i].hwm[r+1];
				students[i].hwm[r+1] = temp;
			}
		}
	}
		if (hwsize%2!=0) students[i].medianm = students[i].hwm[hwsize/2+1];
		else students[i].medianm = (students[i].hwm[hwsize/2] + students[i].hwm[hwsize/2-1])/2;

        students[i].fpointsm = 0.4*students[i].medianm+0.6*students[i].examm;
    }


    cout<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.)  /Final points (Med.)"<<endl;
    for(int i=0; i<72; i++)
		cout<<"-";
	cout<<endl;


    for(int i=0; i<studn; i++){
        cout<<students[i].surname<<setw(15)<<cout.fill(' ')<<right<<students[i].name<<setw(15)<<cout.fill(' ')<<right;
        printf("%.2f",students[i].fpoints);
        cout<<setw(15)<<cout.fill(' ')<<right;
        printf("%.2f\n",students[i].fpointsm);
    }

    return 0;
}


