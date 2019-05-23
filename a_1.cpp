// #include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

#define  size  3 //1618
#define size_of_each_string 4

int matrix[size][size]={};
string s_arr[size+1];
string s_arr_reverse[size+1];
bool seen[size]={};

void input_strings(){
	for(int i=0;i<size;i++){
		cin>>s_arr[i];
	}		
}
 
bool check(int n,int m,int start,int end ) { 
	string str_a=s_arr[n];
	string str_b=s_arr_reverse[m];
	int length=end-start+1;
	str_a=str_a.substr(start,length);//az start be andaze end :)
	str_b=str_b.substr(size_of_each_string-length-start, length);

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

void make_matrix(){
	//matrix
	for (int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			matrix[i][j]=find_common(i,j,0,size_of_each_string-1);		
		}
	}
}

string make_circular_genome(){
	string genome="";
	genome+=s_arr[0];
	seen[0]=true;
	int point=0;
	int maximum=-1;
	int next=-1;
	for(int i=0;i<size;i++){
		if(matrix[point][i]>maximum && seen[i]==false){
			next=i;
			maximum=matrix[point][i];
		}
	}
	// genome///////////////////////////////////should be complete
	// //////////////////////should to use backpropagate
	point=next;
}

int main(){
	input_strings();
	make_matrix();
	make_circular_genome();
}



