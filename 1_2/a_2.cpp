#include<bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;

#define  size  1618 //1618
#define size_of_each_string 100

int matrix[size][size]={};
string s_arr[size+1];
string s_arr_reverse[size+1];
bool seen[size]={};

void input_strings(){
	// string s[10];
	for(int i=0;i<size;i++){
		cin>>s_arr[i];
	}
}


int find_common(int n,int m,int start,int end){
	int count=0;
	string a=s_arr[n];
	string b=s_arr[m];
	
	while(a[count]==b[end-count])
		count++;
	return count;

}

void make_matrix(){
	//matrix
	for (int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i==j)
				matrix[i][j]=-1;
			else 
				matrix[i][j]=find_common(j,i,0,size_of_each_string-1);		
		}
	}
}

string make_circular_genome(){
	
	string genome="";
	genome+=s_arr[0];
	seen[0]=true;
	int noise=-1;
	
	int point=0;
	for(int n=1;n<size;n++){
		int maximum=-1;
		int next=-1;
		for(int i=0;i<size;i++){
			int lm=matrix[point][i];
			if(lm>=maximum && seen[i]==false){
				if(noise==0){
					noise=matrix[point][i]+1;
					next=i;
					maximum=matrix[point][i]+1;
				}
				else
				{
					noise=0;
					next=i;
					maximum=matrix[point][i]+1;
				}	
			}
		}
		
		genome+=s_arr[next].substr(maximum,size_of_each_string-maximum);
		seen[next]=true;
		point=next;
	}
	return genome;
}

int main(){
	clock_t time_req;
	time_req = clock();
	cout<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl;
	input_strings();
	cout<<"sss "<<((float)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
	// cout<<CLOCKS_PER_SEC;
	make_matrix();
	cout<<"zzz "<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl;

	make_circular_genome();
	cout<<"eee "<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl;

}



