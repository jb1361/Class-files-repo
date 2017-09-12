public class main{
    
public static void main(String[] args){
    double[][] temp = {{1,1,1},{1,1,1},{1,1,1}};
     double[][] temp2 = {{1,1,1},{1,1,1},{1,1,1}};
    Program1 m1 = new Program1(temp);
    Program1 m2 = new Program1(temp2);
    try{
    //for(int i=0; i&lt;50; i++){
    m2= m2.multiply(m1);
    //m2 = m2.multiplytwo(m1,m2,50);
    System.out.println(m2);
    }
    catch(Exception e){
    }

}

}