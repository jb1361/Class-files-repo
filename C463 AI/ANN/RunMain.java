
import java.io.*;
import java.util.Vector;
import java.util.StringTokenizer;
import ga.GANN;
import nn.Perceptron;

public class RunMain{

    public static int input_values = 256;
    public static int inputnodes = 10;
    public static int generations  = 1000;    
    public static int indiviLength = 0;
    public static Vector<double[]> storage;
    public static Vector<Perceptron> nodes;
    public static Vector<Integer> actual;
    //public static Vector resultcounter;
    public static GANN ga;
    
	
    public RunMain(){
     ga = new GANN(input_values*inputnodes);
     storage = new Vector<double[]>();
     nodes = new Vector<Perceptron>();
     actual = new Vector<Integer>();
   //  resultcounter = new Vector();
     indiviLength = ga.getLength();
    }
	
    public static void readFile(){
	int i=0;
      	String token;

  
	String line = new String();
	String fileName = "C:/DIGIT_RECOGNITION/src/train.txt";//ClassLoader.getSystemClassLoader().getResource("test.txt").getPath(); 
	try {
	    BufferedReader infile = new BufferedReader( new FileReader(fileName));	
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

     public void executeGA(){
   
      try 
      {
            
            //PrintWriter outfile = new PrintWriter(new BufferedWriter(new FileWriter("C:/DIGIT_RECOGNITION/src/results.txt")));
            PrintWriter bestworstoutfile = new PrintWriter(new BufferedWriter(new FileWriter("C:/DIGIT_RECOGNITION/src/best_worst.txt")));
            PrintWriter history = new PrintWriter(new BufferedWriter(new FileWriter("C:/DIGIT_RECOGNITION/src/history.txt")));
            
           // history.write(Forest.randSeed + " " + Target.targetSeed + "\n");
	    readFile();
	    
            double tempActivation[] = (double[])storage.elementAt(0);
            for (int k = 0; k< inputnodes; k++){
		nodes.add(new Perceptron(tempActivation)); // setup with first activation set set
             }
		for (int i = 0; i<generations ; i++)
		{
			//outfile.write("Generation: " + i +"\n");
			double[] individual = new double[indiviLength];
			
			for (int j=0; j < ga.getPopulationSize(); j++)
			{
				individual = ga.population[j];
				double fitnessValue = 0;
                                
                                int datacounter = 0;      

                                tempActivation = (double[])storage.elementAt(datacounter);
                                for (int k = 0; k< nodes.size(); k++){
                                    nodes.elementAt(k).setActivation(tempActivation); // setup with first activation set set
                                }
      
                                 while (datacounter < (int)storage.size()-1){
	
                                    for (int k =0; k<inputnodes; k++){
                                         nodes.elementAt(k).activate_perceptron(individual, k, input_values);
                                    }
	
                                    int maxNode = findMax();
                                   
                                    int actNode = Integer.parseInt(actual.elementAt(datacounter).toString());
                                    if (actNode == maxNode){
                                        //resultcounter.elementAt(maxNode)++;
                                        fitnessValue++;
                                    }
                                    
				    datacounter++; // move to the next activation set
                                    
				    tempActivation = (double[])storage.elementAt(datacounter);
                                    for (int k = 0; k< nodes.size(); k++){					
                                        nodes.elementAt(k).setActivation(tempActivation); // setup with first activation set set
                                    }
	
                                }
      
                                ga.setFitness(j, fitnessValue);// set fitness of individual j	
                                //System.out.println("ind-->"+j+" fitness-->"+fitnessValue);
                        }
                       //  System.out.println();       
         	    	//ga.outputPopulation(outfile);
			ga.computeTotalFitness();
			ga.showBest(bestworstoutfile, i);
			ga.showWorst(bestworstoutfile, i);
			ga.findAvgFitness();
			ga.offspring();
			ga.createNewPopulation();
			ga.recombination();
			ga.gaussianMutation();
			ga.reinitData();
			
			//outfile.flush();
			bestworstoutfile.flush();
			history.flush();
		}
		//outfile.close();
		bestworstoutfile.close();
		history.close();
    
	}
	catch(IOException e)
	    {
		System.out.println("IOERROR : " + e.getMessage() + "\n");
		e.printStackTrace();
	    }
	System.exit(0);
     
   }
 


 public static void main(String args[]) {
	RunMain rm = new RunMain();
	rm.executeGA();
 }
    
 
}

   
