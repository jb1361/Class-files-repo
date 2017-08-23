package nn;

import java.util.Vector;

public class Perceptron{
    
  private int num_inputs;
  private double activation[];
  private double output;
  private double threshold;
  
    
  public Perceptron(double act[]){
      
      num_inputs = act.length;
      activation = new double[num_inputs];
      
      for (int i=0; i< num_inputs; i++)
         activation[i] = act[i];
      
      output     = 0.0;
      threshold  = 0.0;  
      
  }
    
public  double get_output(){
   return output;
}
 
public void setActivation(double act[]){
  for (int i=0; i < act.length; i++)
    activation[i] = act[i];
  output = 0.0;
}
  
public double sigmoid(double sum){
  return (1.0/(1.0+Math.exp(sum*-1)));
}

public void activate_perceptron(double weights[], int k, int num_inputs){
  
  double sum = 0.0; int j =0;
  //System.out.println(weights.length);
  //System.out.println((k*num_inputs)+" "+(((k+1)*num_inputs)));
  for (int i=(k*num_inputs); i<((k+1)*num_inputs);i++) {
   // System.out.println(i);
    sum += weights[i] * activation[j]; j++;
    
  }
  
  output = sigmoid(sum);
}

}
