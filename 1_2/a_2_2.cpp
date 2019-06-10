#include<bits/stdc++.h>
using namespace  std;

/*
vector< pair <int,int> > v[4];

int main () {  
    pair<int,int> p1,p2,p3;
    p1=make_pair(3,9);
    p2=make_pair(2,4);
    p3=make_pair(5,25);
    cout<<p3.first<<" "<<p3.second<<endl;
    v[2].push_back(p1);
    v[1].push_back(p2);
    v[1].push_back(p3);
    for(int i=0;i<4;i++){
        cout<<":"<<endl;
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j].first<<" "<<v[i][j].second<<"\n";
        }
    }
}*/

#define  number_of_reads  3//1618//1618
#define size_of_each_string 100
#define number_of_input_files 10

vector< pair <int,int> >tree0[number_of_reads];
vector< pair <int,int> >tree1[number_of_reads];
vector< pair <int,int> >tree2[number_of_reads];

string s_arr[number_of_reads+1];
string s_arr_reverse[number_of_reads+1];

bool seen[number_of_reads]={};
bool last_node_used_its_error=false;


void input_strings(int number){
   ifstream infile; 

	
	string str =to_string(number);

    string name="input/in"+str+".txt";
    infile.open(name); 

	for(int i=0;i<number_of_reads;i++)
		infile>>s_arr[i];
	infile.close();	
}
int max_j=0;
void fill_tree(int n,int m){
    string a=s_arr[n];
    string b=s_arr[m];
    
    pair<int,int> p;
    int error_counter=2;
  

    for(int i=0;i<size_of_each_string && error_counter>=0;i++){
        int j=0;
        
        while(error_counter>=0 && j+i<size_of_each_string){
            if(a[i+j]==b[j]){
                j+=1;
            }
            else{
                j+=1;
                error_counter-=1;
            } 
        }
        cout<<"nnnnnnnnnnnnnnnn";
        if(j>=max_j && error_counter>=0){
            max_j=j;
            
            // cout<<j<<" "<<error_counter<<" "<<n<<"   "<<m<<"\n"<<a<<"\n"<<b<<endl;
            // cout<<n<<endl<<a<<"\n"<<s_arr[n]<<endl;
            // cout<<m<<endl<<b<<"\n"<<s_arr[m]<<endl;
            cout<<max_j<<" "<<error_counter<<endl;
            
        }
        if(i+j==size_of_each_string){
            if(error_counter==2){
                error_counter=-1;
                p=make_pair(m,j);
                tree0[i].push_back(p);
                if(j>=10)tree1[i].push_back(p);
                if(j>=20)tree2[i].push_back(p);
                // p1=make_pair(3,9);
            }
            else if(error_counter==1){
                error_counter=0;
                p=make_pair(m,j);
                if(j>=10)tree1[i].push_back(p);
                if(j>=20)tree2[i].push_back(p);
            }
            else if(error_counter==0){
                error_counter=1;
                p=make_pair(m,j);
                if(j>=20)tree2[i].push_back(p);
            }
            else{
                error_counter=2;
            }
        }
    }
}
void make_tree(){
    for (int n=0;n<number_of_reads;n++){
        for(int m=0;m<number_of_reads;m++){
            if(n==m)continue;
            else fill_tree(n,m);
        }
    }
}
string make_circular_genome(){
    int first=0;
    return "ok";
    for(int n=0;n<size_of_each_string;n++){
        //we will use pure greedy algorithm
        ;;;;;;;;;;;;
    }
}
int main(){
	
	for(int number=0;number<=0;number++){
        cout<<"-----------------------------------------"<<number<<"------------------------------------------"<<endl;
    	clock_t time_req;
		time_req = clock();
	
		input_strings(number);
        cout<<"read file !";
        // for(int i=0;i<2;i++){
        //     cout<<s_arr[i]<<endl;
        // }
		make_tree();

		// string out=make_circular_genome();
	


		// string str =to_string(number);

		// string name="output/Out_"+str+".txt";
		
		// ofstream outfile;
		// outfile.open(name);

		// outfile << out;
		// outfile.close();


		// cout<<number<<":"<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl<<endl;


		
	}
	

}



