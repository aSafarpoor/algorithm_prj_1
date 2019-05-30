#include<bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;

#define  Size  1618
#define size_of_each_string 100
// int max_overlapp=-1;

int last_overlapp;//it is to handle overlapp off overlapps

int matrix[Size][Size]={};
int error_prone_matrix[Size][Size]={};
int index_of_dif[Size][Size]={};
bool has_error[Size][Size]={};
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
	string a=s_arr[n];
	string b=s_arr[m];
	if(a==b)return size_of_each_string;
	while(a[count]==b[end-count] && count<size_of_each_string)
		count++;
	// if(max_overlapp<count)max_overlapp=count;
	return count;/*
	for (int i=size_of_each_string;i>0;i--){
		if(str_a.substr(start,i)==str_b.substr(end-i+1,i))
			return i;
	}
	return 0;*/

}
int find_common_with_error(int n,int m,int start,int end){
	int count=0;
	string a=s_arr[n];
	string b=s_arr[m];
	
	if(a==b)return size_of_each_string;

	while(a[count]==b[end-count] && count<size_of_each_string)
		count++;

	index_of_dif[n][m]=count+1;

	count+=1;
	while(a[count]==b[end-count] && count<size_of_each_string)
		count++;	

	if(count>size_of_each_string)count--;
	
	// if(max_overlapp<count)max_overlapp=count;

	return count;/*
	for (int i=size_of_each_string;i>0;i--){
		if(str_a.substr(start,i)==str_b.substr(end-i+1,i))
			return i;
	}
	return 0;*/

}

void make_matrix(){
	//matrix
	int error_free_part=19;
	/*compute error_common_rate
	1/ecr<=5/100 => ecr>=20 => error_free_part>=19
	*/
	for (int i=0;i<Size;i++){
		for(int j=0;j<Size;j++){
			if(i==j)
				matrix[i][j]=-1;
			else {
				matrix[i][j]=find_common(j,i,0,size_of_each_string-1);
				error_prone_matrix[i][j]=find_common_with_error(j,i,0,size_of_each_string-1);
				if(error_prone_matrix[i][j]>=error_free_part && matrix[i][j]<100)has_error[i][j]=true;
			}
						
		}
	}
}

string make_circular_genome(){
	
	bool is_error_used_in_last_iteration=false;
	bool first_error=false;
	bool next_error=false;
	bool temp_error_will_use=false;
	bool error_will_use=false;

	string genome="";
	genome+=s_arr[0];
	seen[0]=true;
	is_error_used_in_last_iteration=false;
	
	int point=0;
	int temp_val=0;


	for(int n=1;n<Size;n++){
		int maximum=-1;
		int next=-1;
		int index_of_error;
		error_will_use=false;
		for(int i=0;i<Size;i++){
			temp_val=matrix[point][i];
			if(has_error[point][i]==true){
				temp_val=error_prone_matrix[point][i];
				temp_error_will_use=true;
				index_of_error=index_of_dif[point][i];
			}

			if(temp_val>maximum && seen[i]==false){
				error_will_use=temp_error_will_use;
				next=i;
				maximum=temp_val;
			}
		}
		/*
		##########################OO##########################
		there is a bug if 2 overlaps has overlap on each other

		we checked inputs, there are no situation we this potantiality,,mx  overlapp was just 23 in error prone and 20 in error free

		but we prefer to handle it
		######################################################
		*/
		if(error_will_use){
			if(is_error_used_in_last_iteration){
				first_error=false;
				next_error=true;
			}
			else{
				first_error=true;		
				next_error=false;	
			}
			
		}


		is_error_used_in_last_iteration=error_will_use;
		
		if(error_will_use==false){
			if(maximum<size_of_each_string)
				genome+=s_arr[next].substr(maximum,size_of_each_string-maximum);
			last_overlapp=-1;
		}
		else{//means error will use :)
			if(first_error){
				if(last_overlapp>size_of_each_string-maximum){
					next_error=true;
					first_error=false;
				}
				else{
					for(int t=0;t<=maximum;t++){
						genome[genome.length() - maximum + t]=s_arr[next][t];
					}
					if(maximum<size_of_each_string)
						genome+=s_arr[next].substr(maximum,size_of_each_string-(maximum));
					last_overlapp=maximum;
				}
				
			}
			if(next_error){//it means if(next_error)
				last_overlapp=maximum;
				if(maximum<size_of_each_string)
					genome+=s_arr[next].substr(maximum,size_of_each_string-(maximum));/**/			
			}
		}
		seen[next]=true;
		point=next;
	}
	return genome;
}

int main(){
	
	for(int number=1;number<11;number++){
		for(int x=0;x<Size;x++)
			for(int z=0;z<Size;z++){
				matrix[x][z]=0;
				index_of_dif[x][z]=0;
				error_prone_matrix[x][z]=0;
			}
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


		cout<<number<<":"<<out.size()<<endl;



		string str =to_string(number);

		string name="output/out"+str+".txt";
		
		ofstream outfile;
		outfile.open(name);

		outfile << out;
		outfile.close();


		// cout<<(float)time_req<<endl;
		cout<<number<<":"<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl<<endl;


		
	}
	

}



