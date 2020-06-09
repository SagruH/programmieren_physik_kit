import numpy as np
#import PhyPraKit as ppk #wurde von mir verändert
import matplotlib.pyplot as plt

#aus PhyPraKit:
def readCSV(file, nlhead=1):
  # open file for read (if necessary)
  if type(file)==type(' '): f = open(file, 'r') # file is a file name
  else: f=file     # assume input is file handle of an open file

  hlines=[]

  # read header
  for i in range (nlhead):
   hlines.append(f.readline()) # header line(s)

  # read data
  data = np.loadtxt(f, delimiter=',', unpack=True) # column-wise data
  return hlines, data


def loadCSV(name,hlines=0,split=2):
    hlines, data = readCSV(name,hlines)
    data = np.array(data)
    a,b=np.split(data,split)
    a = a[0] # anpassen nach split
    b = b[0]
    return a,b;

def create_plot():
    x,fx = loadCSV("a16-interpol-res.dat")
    f = open("a16-interpol.dat","r")
    data = np.loadtxt(f)
    data = np.array(data)

    for i in range(12):
        plt.plot(data[i][0],data[i][1],'or', label = "Gegebene Punkte")

    plt.plot(x,fx,'og', label = "Berechnete Punkte")
    plt.title("Polynom-Interpolation")
    plt.xlabel("x")
    plt.ylabel("fx")
    plt.legend()
    plt.grid(True)
    plt.show()

    return;
create_plot()
