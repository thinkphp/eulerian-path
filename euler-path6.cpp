#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#define FIN "ciclueuler.in"
#define FOUT "ciclueuler.out"
#define NMAX 100005
#define MMAX 700005

using namespace std;

vector<int> G[ NMAX ];
stack<int> STACK;

int degree[ NMAX ],

    sol[ MMAX ],

    num_nodes, 

    num_edges,

    i,

    x,

    y,

    a,

    b;

void read() {

    freopen(FIN, "r", stdin);

    scanf("%d %d", &num_nodes, &num_edges);

    for(i = 1; i <= num_edges; i++) {

          scanf("%d %d", &x, &y);

          G[ x ].push_back( y );  
          G[ y ].push_back( x );
 
          degree[ x ]++;
          degree[ y ]++;
    }     

    fclose( stdin ); 
};

int euler() {

    for(i = 1; i <= num_nodes; i++) {

        if(degree[ i ] & 1) {

           return 0; 
        }
    }

    return 1;
}

int solve() {

    freopen(FOUT, "w", stdout);

    if( !euler() ) {

           printf("-1");

           return 0;
    }

    STACK.push( 1 );

    while(!STACK.empty()) {

           a = STACK.top();

           if(!degree[ a ]) {

               sol[++sol[0]] = a;

               STACK.pop();

               continue;  
           }

           b = G[ a ].back();

           G[ a ].pop_back();           

           degree[ a ]--;

           degree[ b ]--;

           STACK.push( b ); 

           for(vector<int>::iterator it = G[ b ].begin(); it != G[ b ].end(); ++it) {

               if(*it == a) {

                   G[ b ].erase( it );

                   break;
               }   
           } 
    }

    for(i = 1; i <= num_edges; i++) printf("%d ", sol[ i ]); 

    fclose( stdout );
  
    return 1;
};
 
int main() {

    read(); 

    solve();        

    return(0);
};
