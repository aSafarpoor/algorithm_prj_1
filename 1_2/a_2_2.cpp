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

#define  number_of_reads  1618//1618
#define size_of_each_string 100
#define number_of_input_files 1
#define percent 10

vector< pair <int,int> >tree0[number_of_reads];
vector< pair <int,int> >tree1[number_of_reads];
vector< pair <int,int> >tree2[number_of_reads];

string s_arr[number_of_reads+1]={};
string s_arr_reverse[number_of_reads+1];
string genome="";
bool seen[number_of_reads]={};
bool error_used=false;
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


// int global_i=0;
void fill_tree(int n,int m){
    int i=0;
    string a=s_arr[n];
    string b=s_arr[m];

    pair<int,int> p;
    int error_counter=2;
    
    //tree2
    error_counter=2;
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
            if(error_counter>=0 && 200/percent>=j){
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
	error_counter=1;
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

        
        if(i+j==size_of_each_string && 100/percent>=j){
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
    error_counter=0;
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


int find_longest_common(){
	int m=0;
	for(int i=0;i<number_of_reads;i++){
		for(int j=0;j<tree0[i].size();j++){
			if(tree0[i][j].second>m){
				m=tree0[i][j].second;
			}
		}
		for(int j=0;j<tree1[i].size();j++){
			if(tree1[i][j].second>m){
				m=tree1[i][j].second;
			}
		}
		for(int j=0;j<tree2[i].size();j++){
			if(tree2[i][j].second>m){
				m=tree2[i][j].second;
			}
		}
	}
}


string generate_genome(){
    int old=0;
    int neww=-1;
    // return "ok";
    genome=s_arr[0];
    seen[0]=true;
    error_used=false;

    for(int n=1;n<number_of_reads;n++){

   	    int num_of_error=0;
        int m=-1;
        if(error_used==true){
        	// cout<<"A";
    		for(int i=0;i<tree1[old].size();i++){
        		if(seen[tree1[old][i].first]==false && tree1[old][i].second>m){
        			m=tree1[old][i].second;
        			neww=tree1[old][i].first;
        			num_of_error=1;
        			// cout<<"a\n";
        		}
        	}
        	
        	for(int i=0;i<tree0[old].size();i++){
        		if(seen[tree0[old][i].first]==false && tree0[old][i].second>=m){
        			m=tree0[old][i].second;
        			neww=tree0[old][i].first;
        			num_of_error=0;
        			// cout<<"b\n";
        		}
        	}
        }
        else{
        	// cout<<"B";
        	// find_with_legal_error();
        	for(int i=0;i<tree2[old].size();i++){
        		if(seen[tree2[old][i].first]==false && tree2[old][i].second>=m){
        			m=tree2[old][i].second;
        			neww=tree2[old][i].first;
        			num_of_error=2;
        			// cout<<"a\n";
        		}
        	}
        	
    		for(int i=0;i<tree1[old].size();i++){
        		if(seen[tree1[old][i].first]==false && tree1[old][i].second>=m){
        			m=tree1[old][i].second;
        			neww=tree1[old][i].first;
        			num_of_error=1;
        			// cout<<"b\n";
        		}
        	}
        	for(int i=0;i<tree0[old].size();i++){
	        		if(seen[tree0[old][i].first]==false && tree0[old][i].second>=m){
	        			m=tree0[old][i].second;
	        			neww=tree0[old][i].first;
						num_of_error=0;
						// cout<<"c\n";
	        		}
	        }
        	
        	
        }
        seen[neww]=true;
        old=neww;
        if(num_of_error==0){
        	genome+=s_arr[neww].substr(m,size_of_each_string-m+1);
        	error_used=false;

        }
        else if(num_of_error==1){
        	if(error_used){
        		error_used=true;
        		genome+=s_arr[neww].substr(m,size_of_each_string-m+1);
        	}
        	else{
        		error_used=false;
        		for(int t=0;t<=m;t++){
					genome[genome.length() - m + t]=s_arr[neww][t];
				}
				if(m<size_of_each_string)
					genome+=s_arr[neww].substr(m,size_of_each_string-(m));
        	}
        }
        else{
        	error_used=true;
        	bool flag=true;
        	for(int t=0;t<=m;t++){
        		if(genome[genome.length() - m + t]!=s_arr[neww][t]){
        			if(flag){
        				flag=false;
        			}
        			else{
        				genome[genome.length() - m + t]=s_arr[neww][t];
        			}
        		}
			}
			if(m<size_of_each_string)
				genome+=s_arr[neww].substr(m,size_of_each_string-(m));


        }
        // cout<<"kkkkkkkkkkkkkkkkk     "<<old<<endl;
        //add new to old genome'''''''''''''''''''
    }
    return genome;
}








int main(){
	
	for(int number=1;number<=10;number++){
        // cout<<"-----------------------------------------"<<number<<"------------------------------------------"<<endl;
    	clock_t time_req;
		time_req = clock();
		
		fill_n(seen, number_of_reads+1, 0);
		fill_n(s_arr, number_of_reads+1, 0);
		fill_n(s_arr_reverse, number_of_reads+1, 0);
		for(int i=0;i<number_of_reads;i++){
			tree0[i].clear();
			tree1[i].clear();
			tree2[i].clear();
		}


		input_strings(number);
        
        
		make_tree();
		cout<<"tree created\n";

		// o/ut=genome;
		generate_genome();
		cout<<"\n"<<genome.size()<<"\n\n";
		// cout<<genome<<endl;



		// cout<<"\nout is : "<<out<<endl;


		// cout<<number<<":"<<out.size()<<endl;



		string str =to_string(number);

		string name="output/Out_"+str+".txt";
		
		ofstream outfile;
		outfile.open(name);

		outfile << genome;
		outfile.close();


		cout<<number<<":"<<(float)(clock()-time_req)/CLOCKS_PER_SEC<<endl<<endl;
		
	}
	

}





/*
//print tree//
		//for(int i=0;i<number_of_reads;i++){
		// 	cout<<"--------------------------------";
		// 	for(int j=0;j<tree0[i].size();j++){
		// 		cout<<tree0[i][j].first<<" "<<tree0[i][j].second<<endl;
		// 	}
		// 	cout<<"\n";
		// 	for(int j=0;j<tree1[i].size();j++){
		// 		//if(tree1[i][j].second>m){
		// 		cout<<tree1[i][j].first<<" "<<tree1[i][j].second<<endl;
		// 	}
		// 	cout<<endl;
		// 	for(int j=0;j<tree2[i].size();j++){
		// 		cout<<tree2[i][j].first<<" "<<tree2[i][j].second<<endl;
		// 	}
		// 	cout<<endl;
		// }
*/