
import java.io.*;
import java.util.Vector;
import java.util.StringTokenizer;
import nn.Perceptron;

public class RunTestEpisode{

    public static int input_values = 256;
    public static int inputnodes = 10;    
    public static Vector<double[]> storage;
    public static Vector<Perceptron> nodes;
    public static Vector<Integer> actual;
    public static double[] weights;
   
   
    
	
    public RunTestEpisode(){
     storage = new Vector<double[]>();
     nodes = new Vector<Perceptron>();
     actual = new Vector<Integer>();
     weights = new double[inputnodes*input_values];     
    }
	
    public static void readFile(){
	int i=0;
      	String token;

  
	String line = new String();
	String fileName1 = "C:/DIGIT_RECOGNITION/src/test.txt";//ClassLoader.getSystemClassLoader().getResource("C:/DIGIT_RECOGNITION/src/test.txt").getPath(); 
        String fileName2 = "C:/DIGIT_RECOGNITION/src/best.txt";//ClassLoader.getSystemClassLoader().getResource("C:/DIGIT_RECOGNITION/src/best.txt").getPath();
	try {
	    BufferedReader infile = new BufferedReader( new FileReader(fileName1));	
            line = infile.readLine();
            while(infile.ready()){
                StringTokenizer st = new StringTokenizer(line);
		double []individual = new double[input_values];	
                while (st.hasMoreElements()) {  
                    token = st.nextToken();
                    if (i==256){                        
                        actual.add(Integer.parseInt(token));
                    }
                    else{                        
                        individual[i] = Double.parseDouble(token);
                    }
                    i++;
                }
                storage.add(individual);
                line = infile.readLine();
		i = 0; 
            }
	    infile.close();

	   BufferedReader bestInfile = new BufferedReader( new FileReader(fileName2));	
	   String newLine = new String();
           newLine = bestInfile.readLine();
           StringTokenizer st = new StringTokenizer(newLine);
	   i = 0;
           while (st.hasMoreElements()) {  
                token = st.nextToken();
                weights[i] = Double.parseDouble(token);
		i++;
           }
	   bestInfile.close();
	}
	catch(IOException e){
	    System.out.println("IOERROR : " + e.getMessage() + "\n");
	    e.printStackTrace();
      	}
    }
 
  
    public static int findMax(){
 	double max = -10000.0;
 	int maxindex = -1; 
 	double currMax = 0.0;
  
 	for (int i = 0; i < nodes.size(); i++){
 	    currMax = nodes.elementAt(i).get_output();
 	    if(currMax > max){
 	       max = currMax;
               maxindex = i;
            }
       }
       return maxindex;
    }

     public void executeTest(){
   
          
	    readFile();
	    int datacounter = 0;  
            double tempActivation[] = (double[])storage.elementAt(0);
            for (int k = 0; k< inputnodes; k++){
		nodes.add(new Perceptron(tempActivation)); // setup with first activation set set
             }    
    	     int accuracy = 0;
	     //double individual[] = weights;
             while (datacounter < (int)storage.size()-1){
		for (int k =0; k<inputnodes; k++){
                    nodes.elementAt(k).activate_perceptron(weights, k, input_values);
                }
	        int maxNode = findMax();
                int actNode = Integer.parseInt(actual.elementAt(datacounter).toString());
                if (actNode == maxNode){
                    accuracy++;
                }
                datacounter++; // move to the next activation set
                tempActivation = (double[])storage.elementAt(datacounter);
                for (int k = 0; k< nodes.size(); k++){					
                    nodes.elementAt(k).setActivation(tempActivation); // setup with first activation set set
                }
	     }
             System.out.println(storage.size());
             System.out.println(((double)accuracy/storage.size()) *100.0);
      
    	
   }
 


 public static void main(String args[]) {
	RunTestEpisode runTest = new RunTestEpisode();
	runTest.executeTest();
	
 }
    
 
}

   
