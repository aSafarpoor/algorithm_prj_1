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
		//scanf("%s",s_arr[i]);
		//cout<<s_arr[i]<<" ";
		// s_arr_reverse[i]=s_arr[i];
		// reverse(s_arr_reverse[i].begin(),s_arr_reverse[i].end());
		// reverse(name.begin(), name.end());
		// cout<<s_arr_reverse[i];
	}
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
	
	while(a[count]==b[end-count])
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
	
	int point=0;
	for(int n=1;n<size;n++){
		int maximum=-1;
		int next=-1;
		for(int i=0;i<size;i++){
			if(matrix[point][i]>maximum && seen[i]==false){
				next=i;
				maximum=matrix[point][i];
			}
		}
		// cout<<maximum<<endl;
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



