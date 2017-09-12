
public class Program1 {

//attribute

private int R;
private int C;
private double [][] data;
private final int MAX = 100;

//constructor
public Program1(double [][] Markov){
    data = Markov;
    R = data.length;
    C = data[0].length;
}
public Program1(int Row, int Col){
R = Row;
C = Col;

data = new double[R][C];

/* for(int i=0; i&lt;R; i++){
for(int j=0; j&lt;C; j++){
data[i][j] = (int)(Math.random()+ MAX+1);
}//j
}//i*/
}//Matrix
public String toString(){

String output = "";
for(int i = 0; i < R; i++){
    for(int j=0; j < C; j++){
        output += data[i][j]+ "\t";
    }//j
    output += "\n";
}//i

return output;

}//toString
public Program1 copyMatrix(){

Program1 copyMatrix = new Program1(R,C);
for(int i=0; i < R; i++){
    System.arraycopy(this.data[i], 0, copyMatrix.data[i], 0, C);
    }//for i
    return copyMatrix;
}//copy

public boolean equals(Program1 M2){

if(this.R != M2.R || this.C != M2.C){
    return false;
    }//if
    else{
        for(int i=0; i < R; i++){
            for(int j=0; j < C; j++){
                if(this.data[i][j] != M2.data[i][j]) return false;

            }
        }
    }
    return true;
}//equals
public Program1 multiply(Program1 M2) throws Exception{

try{
    if(C != M2.R){
        System.out.println("Boo!");
        throw new RuntimeException();
    }//if

}//try
catch(Exception ex){
    System.out.println(ex);
}//catch

Program1 M3 = new Program1(this.R, this.C);//new Matrix
for(int i=0; i<this.R; i++){
    for(int j=0; j < M2.C; j++){
    //M3.data[i][j]=0;
        for(int K=0; K < M2.R; K++){
            M3.data[i][j] += this.data[i][K] * M2.data[K][j];
        }//k
    }//j
}//i
return M3;


}//mult


public Program1 multiplytwo(Program1 M1, Program1 M2, int n){
Program1 M3 = new Program1(this.R, M2.C);//new Matrix
if (n != 0) {    
    for(int i=0; i<this.R; i++){
        for(int j=0; j < M2.C; j++){
        //M3.data[i][j]=0;
            for(int K=0; K < M2.R; K++){
              M3.data[i][j] += this.data[i][K] * M2.data[K][j];
            }//k
        }//j
    }//i
   return multiplytwo(M2,M3,n-=1);
}else return M2;
}


}
