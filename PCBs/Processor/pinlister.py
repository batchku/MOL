#2017 Ali Momeni
#Made for Python 3.6
#   usage:
#   1.  export a pinlist from eagle board, here called inputfile
#   2.  execute:
#       python3 pinlister.py intputfile

import string
import sys
import re
import os

def process(filename):
    #define dictionary for storing pins and signals
    pinDict = dict()

    #open the input file
    theText = open(filename, "r").read()

    #make array of all lines of input filename
    theTextLines = open(filename, "r").readlines()

    #define important strings
    startText = 'TEENSY   0'                        #starting text
    endText = '         3V3(4)'                     #ending text
    skiptText = 'unconnected|3V3|AREF|AGND|GND'     #skip lines with these strings

    #find starting and ending lines
    with open(filename) as myFile:
            for num, line in enumerate(myFile,1):
                    if startText in line:
                        startLine = num - 1 #first line is off by 1 for some reason
                    if endText in line:
                        endLine = num
            lineRange = range(startLine,endLine)

    #populate dictionary
    for i in lineRange:
        #print('------')
        #print(theTextLines[i])
        thisline = re.split(" +", theTextLines[i])  #split text by spaces
        #print(thisline)
        pinNum = thisline[1]
        pinSig = re.sub('\n','',thisline[2])        #remove newline chars
        test = re.search(skiptText,theTextLines[i])
        #print(test)
        if test is None :
            pinDict[pinSig] = changeToInt(pinNum)
            #pinDict[pinSig] = pinNum

    output = open("output.h", "w")

    for key, value in pinDict.items():
        outputLine = "int " + key + "\t" + "= " + str(value) + ";\n"
        output.write(outputLine)

    output.close()

def changeToInt(s):
    try:
        int(s)
        return int(s)
    except ValueError:
        return s

def main():
    theFiles = sys.argv
    for eachFile in theFiles:
        process(eachFile)

if __name__ == '__main__':
    main()
