import binascii
with open("out", "r") as f:
    line = f.read()
    l = line.replace(' ', '1')
    l = l.replace('\t', '0')
    t = ""
    i = 0
    while i < len(l):
        t += l[i:i+8] + " "
        i+=8
    print(t)
