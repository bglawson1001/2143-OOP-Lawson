# Brayden Lawson
# P04
# April 24, 2023
# This program is a conversion of a header file and main.cpp file from C++ it uses a dice class which will be used in the next program

import sys
from rich import print
import random



class Die(object):

  

    
  
  def __init__(self,sides = 0):
    if str(sides).isdigit():
      self.sides = sides
    else:
      if not isinstance(sides, int):
        print("error: sides is not an integer!")
        print("Default value used")
      
      self.sides = 6

  def roll(self):
    values = [x for x in range(self.sides)]
    
    random.shuffle(values)
    if values:
      return values[0] + 1
    
  def __str__(self):
    return f"[sides: {self.sides}]"
    

class Dice:
  def __init__(self,sides=None,num_dice=1):
    parts=[]
    sides2 = [sides]
    
    self.sides = sides
      
    if not sides:
      print("Need to pass in sides!!!")
      sys.exit()
    
    elif isinstance(sides,str):
      # 8.d.10
      parts = sides.split(".")
      # self.sides = parts[0]
      num_dice = int(parts[0])
      self.sides = int(parts[2])
      # print(sides, self.sides,self.num_dice)
    else: 
      self.sides = sides
      self.num_dice = num_dice
      
      def __str__(self):
        return f"{self.sides} , {self.num_dice}"
      #x = sides.split(".")
     #numberofdice, sides = int(x[0]), int(x[2])
      
    # create a container
    self.dice = []
    
    for die in range(num_dice):
      self.dice.append(Die(self.sides))

  def sum(self):
    total = 0
    for d in self.dice:
      total += d.roll()
      
    return total
  ## method to get the max of the amount of rolls passed from whatever sided die is passed into main.
  def max(self):
    results = []
    for d in self.dice:
      results.append(d.roll())
    # print(results)
    return max(results)
## method to get the min of the amount of rolls passed from whatever sided die is passed into main.
  def min(self):
    results = []
    for d in self.dice:
      results.append(d.roll())

    return min(results)
    
  ## method to get the average of the amount of rolls passed from whatever sided die is passed into main.
  def avg(self):
    """ this uses sum / len
    """
    results =[]
    for d in self.dice:
      results.append(d.roll())

    return sum(results) / len(results)
    

    
  def roll(self,rollType=None):
    if rollType =='max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()

  def __str__(self):
    s = "Dice:[\n    "
    for d in self.dice:
      s = s + str(d) # casting a class as a string, invokes the __str__ method!!
    s = s + "\n]\n"
    return s





  def __str__(self):
    return f"{self.name} , {self.number}"


if __name__=='__main__':
  # d1 = Die()
  # d2 = Die(10)

  # print(d1)
  # print(d2)
  # print()
  # d3 = Dice(10,5)


  
  #d5 = Dice(6,1)

  print(s1)
  print(s2)

  
