from random import *
import math
desiredtemp = 105

#Simple agent that just keeps trying untill it gets the right temperature.
#A runtime error means that the python recursion stack limit of 997 has been reached (this is very rare with the set values)
def agentOne(n):
	x = randint(70,140)
	if(x == desiredtemp):
		print('Agent one found the right temperature after ' + str(n) + ' tries.')
		return
	if(n >= 900):
		print('Python max recursion stack, poor agent one.')
		return
	agentOne(n+1)

#Agent that store how hot/cold it was (difference) then reduces its random range of randint till it gets the right temperature
def agentTwo(randOne,randTwo,n):
	x = randint(randOne,randTwo)
	difference = abs(desiredtemp-x)
	if(difference == 0):
		print('Agent two found the right temperature after ' + str(n) + ' tries.')
		return
	newOne = randOne+math.floor(difference/2)
	newTwo = randTwo-math.floor(difference/2)
	agentTwo(newOne,newTwo,n+1)	
	
agentOne(1)
agentTwo(70,140,1)