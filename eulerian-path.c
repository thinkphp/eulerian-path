#include <stdio.h>
#include <malloc.h>
#define MAX 50

void readGraph(const char*);
void displayMatrix();
int connex();
int have_degree();
void dfs(int);

int mat[MAX][MAX], visited[ MAX ];

int num_vertices, num_edges;

FILE *fin, *fout;

int main() {

    readGraph("c:\\eulerian.in");
    printf("\n\n"); 

    if( connex() ) {

          if( have_degree() ) {

             printf("OK"); 

          } else {

           printf("The Graph does n respect the conditions for parity");

          }
        
    } else {

           printf("The Graph is not connex");
    }

    return(0);
};

void readGraph(const char *filename) {

     int i,j;

     fin = fopen( filename, "r" );
     
     fscanf(fin, "%d %d", &num_vertices, &num_edges);

     for(;num_edges; num_edges--) {
         
          fscanf(fin, "%d %d",&i,&j);
          mat[i][j] = mat[j][i] = 1;
     }
     
     fclose( fin );
}

void displayMatrix() {
     int i,j;

     for(i=1;i<=num_vertices;i++) {

         for(j=1;j<=num_vertices;j++) {
 
             printf("%d ", mat[i][j]);  
         }
             printf("\n");
     } 
}

int have_degree() {

    int sum,i,j,not = 1;
    
    for(i = 1; i <= num_vertices; i++) {

        sum = 0;

        for(j = 1; j <= num_vertices; j++) {

            sum += mat[i][j];
        }

        if(sum&1) not = 0;

        if(!not) return not;
    }
    return not;
}

int connex() {
    int i;

    dfs(1);

    for(i=1;i<=num_vertices;i++) 

        if(!visited[i]) 

            return 0;

    return 1;
}

void dfs(int node) {

     int j;

     visited[ node ] = 1;

     for(j = 1; j <= num_vertices; j++) {

         if(mat[ node ][ j ]) {
      
                if(!visited[ j ]) {

                    dfs( j ); 
                } 
         } 
     }  
}