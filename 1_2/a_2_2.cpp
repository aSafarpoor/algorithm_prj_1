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
#define number_of_input_files 1

vector< pair <int,int> >tree0[number_of_reads];
vector< pair <int,int> >tree1[number_of_reads];
vector< pair <int,int> >tree2[number_of_reads];

string s_arr[number_of_reads+1]={};
string s_arr_reverse[number_of_reads+1];

bool seen[number_of_reads]={};
bool last_node_used_its_error=false;

int max_j=-1;

void input_strings(int number){
   ifstream infile; 

	string str =to_string(number);

    string name="input/in"+str+".txt";
    infile.open(name); 

	for(int i=0;i<number_of_reads;i++)
		infile>>s_arr[i];
	infile.close();	
}


// int global_i=0;
void fill_tree(int n,int m){
    int i=0;
    string a=s_arr[n];
    string b=s_arr[m];

    pair<int,int> p;
    int error_counter=2;
    
    //tree2
    for(i=0;i<size_of_each_string;i++){
        
        if(error_counter<0){break;}
        int j=0;
        // int seen_tree=0;
        while(error_counter>=0 && ((j+i)<size_of_each_string)){

            if(a[i+j]==b[j]){
                j+=1;
            }
            else{
                j+=1;
                error_counter-=1;
            } 
        }

        
        if(i+j==size_of_each_string){
            if(error_counter>=0){
                error_counter=1;
                p=make_pair(m,j);
                i--;
                tree2[n].push_back(p);
                break;
            }
            else{
                error_counter=2;
            }
        }
        else{
        	error_counter=2;
        }
    }
	//tree1
	for(;i<size_of_each_string;i++){
        
        if(error_counter<0){break;}
        int j=0;
        // int seen_tree=0;
        while(error_counter>=0 && ((j+i)<size_of_each_string)){

            if(a[i+j]==b[j]){
                j+=1;
            }
            else{
                j+=1;
                error_counter-=1;
            } 
        }

        
        if(i+j==size_of_each_string){
            if(error_counter>=0){
                error_counter=0;
                p=make_pair(m,j);
                i--;
                tree1[n].push_back(p);
                break;
            }
            else{
                error_counter=1;
            }
        }
        else{
        	error_counter=1;
        }
    }
    //tree0
    for(;i<size_of_each_string;i++){
        
        if(error_counter<0){break;}
        int j=0;
        // int seen_tree=0;
        while(error_counter>=0 && ((j+i)<size_of_each_string)){

            if(a[i+j]==b[j]){
                j+=1;
            }
            else{
                j+=1;
                error_counter-=1;
            } 
        }

        
        if(i+j==size_of_each_string){
            if(error_counter>=0){
                error_counter=0;
                p=make_pair(m,j);
                i--;
                tree0[n].push_back(p);
                break;
            }
            else{
                error_counter=0;
            }
        }
        else{
        	error_counter=0;
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
        
        
		make_tree();
		cout<<"\n\n";
		for(int i=0;i<number_of_reads;i++){
			cout<<"000000000000\n";
			for(int j=0;j<tree0[i].size();j++){
				cout<<tree0[i][j].first<<" "<<tree0[i][j].second<<'\n';
			}
			cout<<"111111111111111\n";
			for(int j=0;j<tree1[i].size();j++){
				cout<<tree1[i][j].first<<" "<<tree1[i][j].second<<'\n';
			}
			cout<<"22222222222222\n";
			for(int j=0;j<tree2[i].size();j++){
				cout<<tree2[i][j].first<<" "<<tree2[i][j].second<<'\n';
			}
			cout<<"\n\n";
		}
		cout<<endl;
		


		
	}
	

}



