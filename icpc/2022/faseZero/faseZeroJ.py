n = int(input())
o = []

for i in range(n):
	o.append(input())

def conversao(n, o):
    if(n >= 0 and n <= 100 and len(o) > 0 and len(o) <= n):
        for valor in o:
            oValue = valor
            if " 1T" in oValue:
                oTrimmed = oValue[0:2]
                oNumber = int(oTrimmed)
                if (oNumber > 60):
                  None
                if (oNumber > 45):
                    print("45+%s" % (oNumber % 45))
                else:
                    print(oNumber)
            else:
                oTrimmed = oValue[0:2]
                oNumber = int(oTrimmed)
                if (oNumber > 60):
                  None

                if (oNumber > 45):
                    print("90+%s" % (oNumber % 45))
                else:
                    print(45 + oNumber)
conversao(n, o)

