/*
 * GANN.java
 *
 * Created on June 25, 2004, 8:14 PM
 * Last Modified Sept 29, 2004, 8.39AM
 * surveillance v1.0
 * Copyright (c) 2004 University of Wyoming
 */


package ga;



import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import java.io.*;



/**
 * Class GANN implements GA for surveillance using Lennard-Jones Potential.
 * Used for evolving population of interaction potentials
 * @version 	surveillance v1.0 22 July 2004
 * @author 	Suranga Hettiarachchi
 *
 */
public class GANN extends GABase{
    
    
    
    
    
    /** length of an individual, default is 11 */
  //  public static int lengthLj = 11;
    
    
    
    
    public GANN(int l) {
        super();
        length = l;
        if (gaSeed == -1)
            rnd = new Random();
        else
            rnd = new Random(gaSeed);
        
        population = new double[popSize][length];
        population1 = new double[popSize][length];
        population2 = new double[popSize][length];
        children = new int[popSize];
        sh = new int[popSize];
        best = new double[length];
        worst = new double[length];
        fitness = new double[popSize];
        population = population1;
        
        double value;
        
        for (int i = 0; i < popSize; ++i) {
            for (int j = 0; j < length; ++j) {
                value =  rand_data(rMax, rMin);
                population1[i][j] = value;
                population2[i][j] = value;
             }
            fitness[i] = 0.0;
            children[i] =  0;
         }
        // account for frozen bits
        mutationProbability = 1.0/(length);
    }
    
    
    
    /* mutate individuals, every individual may be mutated
     * uses Gaussian mutation with mean 0.0 and std 1.0
     * every allel is mutated with 1/L rate
     */
    public void gaussianMutation() {
        
        double new_individual[];
        int i, j;
        
        
        for (i = 0; i < popSize; ++i) {
            
            //int mutated = 0;
            new_individual = (double[])population[i].clone();
          //  new_individual[4] = population[i][4]; // save the non mutating param.
           // new_individual[5] = population[i][5];
          //  new_individual[6] = population[i][6];
            
            for (j=0; j<length; j++) {
                //if ( j!=4 && j!=5 && j!=6) // don't mutate frozen param.
                    if (rnd.nextDouble() <= mutationProbability){ // mutProb = 1/L, may use mutationRate
                        new_individual[j] += rnd.nextGaussian() * 0.01; // 0.001 reduces stepsize
                      //  mutated++;
                    }
                
            }
           // if (mutated > 0)
           //     if (legalBound(new_individual))
                    population[i] = new_individual;
            
            
        }
    }
    
    /* check the mutated individuals for their validity.
     * all values should be within original ranges as specified in conf file.
     
    public boolean legalBound(double individual[]) {
        
        boolean validBound = true;
        int j;
        
        if (individual[8] > individual[7])//minimum range should be less than maximum range
            validBound = false;
        
        for (j =0; j<length && validBound; j++) {
            
            if ( j == 0){
                if (individual[j]>eMax || individual[j]< eMin)
                    validBound = false;
            }
            
            if (j == 1){
                if (individual[j]>fMax || individual[j]<fMin)
                    validBound = false;
            }
            
            if ( j == 2){
                if (individual[j]>constMax || individual[j]<constMin)
                    validBound = false;
            }
            
            if (j == 3){
                if (individual[j]>constMax || individual[j]<constMin)
                    validBound = false;
            }
            
            if (j == 7){ // checking maximum range
                if (individual[j]>rMax  || individual[j]<rMin)
                    validBound = false;
            }
            
            if (j == 8){ // checking minimum range
                if (individual[j]>rMax  || individual[j]<rMin)
                    validBound = false;
            }
            
            if(j == 9){// checking power of range
                if (individual[j]>pMax || individual[j]<pMin)
                    validBound = false;
            }
            
            if (j == 10 ){ // friction
                if (individual[j]>fricMax || individual[j]< fricMin)
                    validBound = false;
                
            }
            
        }
        return validBound;
    }
    */
    
    
    
    
    
}// end class GALJ
