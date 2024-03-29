#include<bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;

#define  Size  1618//4//1618
#define size_of_each_string 100//3//100
// int max_overlapp=-1;
int matrix[Size][Size]={};
string s_arr[Size+1];
string s_arr_reverse[Size+1];
bool seen[Size]={};

void input_strings(int number){
   ifstream infile; 

	
	string str =to_string(number);

    string name="input/in"+str+".txt";
    infile.open(name); 

	for(int i=0;i<Size;i++)
		infile>>s_arr[i];
	infile.close();	
}


int find_common(int n,int m,int start,int end){
	int count=0;
	string b=s_arr[n];
	string a=s_arr[m];
	
	for(int i=0;i<size_of_each_string;i++){
		if(a[i]==b[0]){
			int j=0;
			while(j+i<size_of_each_string){
				if(a[i+j]==b[j]){j++;}
				else{
					break;
				}
			}
			if(i+j==size_of_each_string){
				return j;
			}
		}
	}

	/*
	for(int i=size_of_each_string;i>=0;i--){
		string sub_a;
		string sub_b;
		sub_a=a.substr(end-i+1,i);
		sub_b=b.substr(0,i);
		if(sub_b==sub_a)
			return i;
	}*/
	return 0;
	/*while(a[count]==b[end-count] && count<size_of_each_string)
		count++;
	// if(count>max_overlapp)max_overlapp=count;
	return count;*/
	/*
	for (int i=size_of_each_string;i>0;i--){
		if(str_a.substr(start,i)==str_b.substr(end-i+1,i))
			return i;
	}
	return 0;*/
}

void make_matrix(){
	//matrix
	for (int i=0;i<Size;i++){
		for(int j=0;j<Size;j++){
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
	
	int point=0;
	for(int n=1;n<Size;n++){
		int maximum=-1;
		int next=-1;
		for(int i=0;i<Size;i++){
			if(matrix[point][i]>maximum && seen[i]==false){
				next=i;
				maximum=matrix[point][i];
			}
		}
		// cout<<maximum<<endl;
		if(maximum<size_of_each_string)
			genome+=s_arr[next].substr(maximum,size_of_each_string-maximum);
		seen[next]=true;
		point=next;
	}
	return genome;
}

int main(){
	
	for(int number=1;number<=10;number++){
		for(int x=0;x<Size;x++)
			for(int z=0;z<Size;z++)
				matrix[x][z]=0;
		for(int z=0;z<Size+1;z++){
			s_arr_reverse[z]="";
			s_arr[z]="";
		}
		for(int z=0;z<Size+1;z++){
			seen[z]=false;
		}

		clock_t time_req;
		time_req = clock();
		//cout<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl;
		
		input_strings(number);
		// cout<<"sss "<<((float)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
		// cout<<CLOCKS_PER_SEC;
		make_matrix();
		// cout<<"zzz "<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl;
		string out=make_circular_genome();


		cout<<number<<" size is:"<<out.size()<<endl;
		// cout<<"out is:"<<out<<endl;


		string str =to_string(number);

		string name="output/out"+str+".txt";
		
		ofstream outfile;
		outfile.open(name);

		outfile << out;
		outfile.close();



		cout<<number<<":"<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl<<endl;

	}
	

}



