#include<bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;

#define  Size  1618 //1618
#define size_of_each_string 100

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
/*
bool check(int n,int m,int start,int end ) { 
	string str_a=s_arr[n];
	// string str_b=s_arr_reverse[m];
	string str_b=s_arr[m];
	int length=end-start+1;
	str_a=str_a.substr(start,length);//az start be andaze end :)
	// str_b=str_b.substr(start,length);//
	str_b=str_b.substr(size_of_each_string-length-start, length);
	cout<<str_a<<" "<<str_b<<endl;;
	// cout<<start<<" "<<end<<" "<<(str_a==str_b)<<endl;
	if(str_a==str_b)return true;
	return false;
} 

int find_common(int n,int m,int start,int end){
	if(start>end) return end ;
	
	if (end==start){
		bool c=check(n,m,start,end);
		if(c)
			return end;
		else 
			return end-1;
	} 
	int mid=(start+end+1)/2;
	
	int length=mid-start;
	int is_end=0;

	if(check(n,m,start,mid-1)){
		is_end=find_common(n,m,mid,end);
	}
	else{
		is_end=find_common(n,m,start,mid-1);
	}
	return is_end;
}
*/

int find_common(int n,int m,int start,int end){
	int count=0;
	string a=s_arr[n];
	string b=s_arr[m];
	
	while(a[count]==b[end-count] && count<size_of_each_string)
		count++;
	return count;/*
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
		if(maximum+1>=size_of_each_string)
			genome+=s_arr[next].substr(maximum,size_of_each_string-maximum);
		seen[next]=true;
		point=next;
	}
	return genome;
}

int main(){
	
	for(int number=1;number<11;number++){
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
		// time_req = clock();
		//cout<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl;
		
		input_strings(number);
		// cout<<"sss "<<((float)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
		// cout<<CLOCKS_PER_SEC;
		make_matrix();
		// cout<<"zzz "<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl;
		string out=make_circular_genome();


		cout<<number<<":"<<out.size()<<endl;



		string str =to_string(number);

		string name="output/out"+str+".txt";
		
		ofstream outfile;
		outfile.open(name);

		outfile << out;
		outfile.close();



		cout<<number<<":"<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl<<endl;
	}
	

}



