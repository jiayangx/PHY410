from studentrecord import studentrecord


def main() :

    f = open("records.txt")
    a = f.read()
    l = []
    j = a.replace(',', ' ')
    for t in j.split():
        try:
            l.append(float(t))
        except ValueError:
            pass
    print 'The scores are: ',l

    averagescore = 0.
    averagescore = studentrecord()
    averagescore.input(l)
    final=averagescore.average(l)
    print 'The average score is: ', final





if __name__ == "__main__" :
    main()
